#ifndef TEST1_VIEW_H
#define TEST1_VIEW_H
#include <SFML/Graphics.hpp>
#include "consts.h"
using namespace sf;

View view;

View SetPlayerCoordForView(float x, float y) {
    float tempX=x;
    if (x < LEFT_LINE)
        tempX = LEFT_LINE;
    else if (x > RIGHT_LINE)
        tempX = RIGHT_LINE;

    view.setCenter(tempX+(10*16),y);
    return view;
}



#endif //TEST1_VIEW_H