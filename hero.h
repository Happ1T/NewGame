#ifndef TEST1_HERO_H
#define TEST1_HERO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "consts.h"
#include "view.h"
#include "map.h"
#include "entity.h"

using namespace sf;
using namespace std;

class Hero:public Entity {
public:
    int count_jump, stamina, line = 0;
    bool is_shift = true;

    Hero(int X, int Y, int W, int H,String Name): Entity(X,Y,W,H,Name) {
       if (name == "player\\adventurer.png"){
            health = 100;
            width_attack = WIDTH_ATTACK_ADVENTURE;
            height_attack = HEIGTH_ATTACK_ADVENTURE;
        }
       height_simple = height;
    }
    void control() {
        if ((Keyboard::isKeyPressed(Keyboard::LShift))) {
                is_shift = true;
            }
            if (!is_shift) {
                speed = SPEED;
                speed_animation = SPEED_ANIMATION;
            } else {
                speed = SPEED * 1.5;
                speed_animation = SPEED_ANIMATION * 2;
            }
            is_shift = false;
            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                if (count_jump == 0) {
                    dy = JUMP_RANGE;
                } else if (count_jump == 15) {
                    dy = JUMP_RANGE;
                }
                count_jump++;
                is_ground = false;
            } else if (Keyboard::isKeyPressed(Keyboard::A) || (Keyboard::isKeyPressed(Keyboard::Left))) {
                is_attack = false;
                dx = -speed;
            } else if (Keyboard::isKeyPressed(Keyboard::D) || (Keyboard::isKeyPressed(Keyboard::Right))) {
                is_attack = false;
                dx = speed;
            }
            else if(Keyboard::isKeyPressed(Keyboard::F)){
                is_attack= true;
                height = height_attack;

            }
            else {
                dx = 0;
            }
    }
    void update(float time) {
        control();
        x += dx * time;
        InteractWorld(0);
        if (!is_ground) {
            dy += 0.0005 * time;
        }

        y += dy * time;
        InteractWorld(1);
        if (y > GROUND){
            y = GROUND;
            dy = 0;
            is_ground = true;
        }
        if (count_jump > 1)
        {
            if (count_jump == 15)
                frame = 0.1;
            if (frame < 7)
                frame += JUMP_ANIMATION * time;
            else {
                frame = 7;
            }
            if (dir) {
                sprite.setTextureRect(IntRect(width * int(frame + 1) , height * 2 , -width, height));
            }
            else {
                sprite.setTextureRect(IntRect(width *int(frame), height * 2 , width, height));
            }
        }

        else if (dx >0)
        {
            dir = false;
            frame += SPEED_ANIMATION * time;
            if (frame > 6)
                frame -= 6;
            sprite.setTextureRect(IntRect((width) * (int(frame)),height*1 ,  width, height));
        }
        else if(dx < 0){
            dir = true;
            frame+=SPEED_ANIMATION * time;
            if(frame > 6)
                frame -= 6;
            sprite.setTextureRect(IntRect((width) * (int(frame)+1) ,height*1,  -width, height));
        }
        else if(is_attack) {
            frame += ATTACK_ANIMATION * time;
            if (frame > 8) {
                frame -= 8;
                line += 1;
            }
            if (line == 1 && frame > 2) {
                is_attack = false;
                line = 0;
            }

            if (dir) {
                sprite.setTextureRect(IntRect(width_attack * (int(frame) + 1), 90 + height_attack * line, -width_attack,
                                              height_attack));
            } else {
                sprite.setTextureRect(
                        IntRect((width_attack * int(frame)), 90 + height_attack * line, width_attack, height_attack));
            }
        }
        else{
            frame += SPEED_ANIMATION * time;
            if (frame > 4)
                frame -= 4;
            if (dir)
                sprite.setTextureRect(IntRect(width * (int(frame) + 1), 0, -width,height));
            else
                sprite.setTextureRect(IntRect((width * int(frame)), 0, width, height));
        }
        sprite.setPosition(x, y);
        SetPlayerCoordForView(GetPlayerCordInX(), GetPlayerCordInY());
    }

    float GetPlayerCordInX() {
        return x;
    }
    float GetPlayerCordInY() {
        return y;
    }



    void InteractWorld(int dir) {
        for (int i = ((y) / SIZE_OF_BLOCK); i < ((y + height) / SIZE_OF_BLOCK); i++) {
            for (int j = (x / SIZE_OF_BLOCK); j < ((x+ width) / SIZE_OF_BLOCK) ; j++) {
                if (TileMap[i][j] == '1') {
                    if (dy > 0 && dir == 1) {
                        y = ((i) * SIZE_OF_BLOCK) - height ;
                        dy = 0;
                        is_ground = true;
                        count_jump = 0;
                    }
                    if (dy < 0 && dir == 1) {
                        y = (i * SIZE_OF_BLOCK) + SIZE_OF_BLOCK;
                        dy = 0;
                    }
                    if (dx > 0 && dir == 0) {
                        x = (j * SIZE_OF_BLOCK) - width;
                        dx = 0;
                    }
                    if (dx < 0 && dir == 0) {
                        x = (j * SIZE_OF_BLOCK) + SIZE_OF_BLOCK;
                        dx = 0;
                    }
                } else if (TileMap[i][j] != '1' && dir == 1){
                    is_ground = false;
                }
            }
        }
    }
};

#endif//TEST1_HERO_H

