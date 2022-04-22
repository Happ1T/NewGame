#ifndef TEST1_CONST_H
#define TEST1_CONST_H


// dir
const int left_dir= 1;
const int right_dir= 0;
const int up_dir = 2;

//ADVENTURE
const int WIDTH_OF_ADVENURER = 26;
const int HEIGHT_OF_ADVENTURER = 30; // make always +7
const int WIDTH_ATTACK_ADVENTURE=48;
const int HEIGTH_ATTACK_ADVENTURE=30;
const float ATTACK_ANIMATION=0.01;

//SKELETON
const int HEIGHT_OF_SKELETON = 32;
const int WIDTH_OF_SKELETON = 24;
const float SPEED_SKELETON_ANIMATION=0.01;
const float SPEED_SKELETON = 0.02;

//map
const int HEIGHT_MAP = 34;
const int WIDTH_MAP = 80;
const int CENTER = 400;

//size block
const int SIZE_OF_BLOCK = 16;

//screen
int WIDTH_SCREEN = 1920;
int HEIGHT_SCREEN = 960;
const float LEFT_LINE  = 180;
const float RIGHT_LINE = 781;
const int GROUND = HEIGHT_MAP*SIZE_OF_BLOCK;

//camera
int WIDTH_CAMERA= WIDTH_SCREEN / 3;
int HEIGHT_CAMERA=HEIGHT_SCREEN / 3;

//speed
const float SPEED = 0.15;
const float JUMP_RANGE = -0.2;


//animation
const float SPEED_ANIMATION = 0.005;
const float JUMP_ANIMATION = 0.01;


#endif//TEST1_CONST_H
