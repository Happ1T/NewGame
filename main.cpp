#include "hero.h"
#include "consts.h"
#include "map.h"
#include "view.h"
#include "entity.h"
#include "enemy.h"

int main() {

    RenderWindow window(VideoMode(WIDTH_SCREEN, HEIGHT_SCREEN), "Fil gay", Style::Close);
    view.reset(FloatRect(0,CENTER, WIDTH_CAMERA, HEIGHT_CAMERA));
    Hero adventurer(456.05, CENTER, WIDTH_OF_ADVENURER, HEIGHT_OF_ADVENTURER, "player\\adventurer.png");
    Enemy skeleton(475.05, 367, WIDTH_OF_SKELETON,HEIGHT_OF_SKELETON,"enemy\\Skeleton.png");
    Texture map;
    map.loadFromFile("C:\\Users\\Honor MagicBook Pro\\CLionProjects\\test1\\texture\\map\\map.png");
    Sprite s_map;
    s_map.setTexture(map);
    Clock clock;
    float fps, fps_time = 0;
    float time_of_jump;
    while (window.isOpen()) {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 1000;
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        skeleton.update(time);
        adventurer.update(time);
        window.setView(view);
        window.clear();
        for (int i = 0; i < HEIGHT_MAP; i++)
            for (int j = 0; j < WIDTH_MAP; j++)
            {
                if (TileMap[i][j] == '1')  s_map.setTextureRect(IntRect(SIZE_OF_BLOCK*0, 0, SIZE_OF_BLOCK, SIZE_OF_BLOCK));
                if (TileMap[i][j] == '0')  s_map.setTextureRect(IntRect(SIZE_OF_BLOCK, 0, SIZE_OF_BLOCK, SIZE_OF_BLOCK));
                if ((TileMap[i][j] == ' ')) s_map.setTextureRect(IntRect(SIZE_OF_BLOCK*2, 0, SIZE_OF_BLOCK, SIZE_OF_BLOCK));
                if ((TileMap[i][j] == '3')) s_map.setTextureRect(IntRect(SIZE_OF_BLOCK*3, 0, SIZE_OF_BLOCK, SIZE_OF_BLOCK));

                s_map.setPosition(j * SIZE_OF_BLOCK, i * SIZE_OF_BLOCK);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

                window.draw(s_map);//рисуем квадратики на экран
            }
        window.draw(adventurer.sprite);
        window.draw(skeleton.sprite);
        window.display();
       // cout << herosprite.GetPlayerCordInX() << " " << herosprite.GetPlayerCordInY() << endl;
        fps++;
        fps_time += time;
        if (fps_time > 1000)
        {
            cout << fps << endl;
            fps = 0;
            fps_time =0;
        }
        sleep(milliseconds(12));
    }
}