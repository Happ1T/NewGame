#ifndef TEST1_ENTITY_H
#define TEST1_ENTITY_H


class Entity {
private:
public:
    float dx, dy, frame, speed, x, y, speed_animation, move_timer = 0;
    int  width, width_attack, height, height_attack, health, height_simple, damage = 0;
    bool dir, is_attack = false, is_ground = false,life=true;

    String name;
    Texture texture;
    Sprite sprite;
    Entity(float X, float Y, int W,int H, String Name){
        width = W;
        height = H;
        x = X;
        y = Y;
        name = Name;
        texture.loadFromFile("C:\\Users\\Honor MagicBook Pro\\CLionProjects\\test1\\texture\\" + Name);
        sprite.setTexture(texture);

    }
};


#endif //TEST1_ENTITY_H
