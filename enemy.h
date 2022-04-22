#ifndef TEST1_ENEMY_H
#define TEST1_ENEMY_H
#include "entity.h"

class Enemy: public Entity{
public:
    float time_dx = 0;
    bool is_stay = false;
    Enemy(int X, int Y, int W, int H, String Name): Entity(X,Y,W,H,Name){
        if (Name == "enemy\\Skeleton.png"){
            health = 100;
            damage = 10;
            speed = SPEED_SKELETON;
            dx = speed;
            speed_animation = SPEED_SKELETON_ANIMATION;
            dir = true;
        }
    }

    void InteractWorldEnemy(int dir) {
        for (int i = ((y) / SIZE_OF_BLOCK); i < ((y + height) / SIZE_OF_BLOCK); i++) {
            for (int j = (x / SIZE_OF_BLOCK); j < ((x+ width) / SIZE_OF_BLOCK) ; j++) {
                if (TileMap[i][j] == '1') {
                    if (dy > 0 && dir == 1) {
                        y = ((i) * SIZE_OF_BLOCK) - height ;
                        dy = 0;
                        is_ground = true;
                    }
                    if (dy < 0 && dir == 1) {
                        y = (i * SIZE_OF_BLOCK) + SIZE_OF_BLOCK;
                        dy = 0;
                    }
                    if (dx > 0 && dir == 0) {
                        x = (j * SIZE_OF_BLOCK) - width;
                        dx = -speed;
                        sprite.scale(-1,1);
                    }
                    if (dx < 0 && dir == 0) {
                        x = (j * SIZE_OF_BLOCK) + SIZE_OF_BLOCK;
                        dx = speed;
                        sprite.scale(-1,1);
                    }
                } else if (TileMap[i][j] != '1' && dir == 1){
                    is_ground = false;
                }
            }
        }
    }

    void update(float time){
        if (name == "enemy\\Skeleton.png"){
           move_timer+= time;
            if(move_timer > 5000 && !is_stay){
                is_stay = true;
                move_timer = 0;
                time_dx = dx;
                dx = 0;
                dir = !dir;
            } else if(move_timer > 5000 && is_stay){
                dx = -time_dx;
                is_stay = false;
                move_timer = 0;

            }

            x += dx*time;
           InteractWorldEnemy(0);
            if (!is_ground) {
                dy += 0.0005 * time;
            }
            y += dy * time;
            InteractWorldEnemy(1);

            frame += speed_animation*time;
            //cout<<frame<<endl;

            if (frame > 13)
                frame -= 13;
            if (dx == 0){
                if (dir)
                    sprite.setTextureRect(IntRect(width * int(frame + 1) , height * 0 , -width, height));
                else
                    sprite.setTextureRect(IntRect(width * int(frame ) , height * 0 , width, height));
            }
            else if (dx > 0)
                sprite.setTextureRect(IntRect(width * int(frame ) , height * 1 , width, height));
            else
                sprite.setTextureRect(IntRect(width * int(frame+1) , height * 1 , -width, height));

            sprite.setPosition(x,y);
            if(health<=0)
                life=false;
        }
    }
};
#endif //TEST1_ENEMY_H
