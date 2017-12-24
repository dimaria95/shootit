#ifndef BALL_H
#define BALL_H
#define PI 3.141592653589793
#include <math.h>

float x_curr;
float y_curr;
float ball_rotation;
float v_x;
float v_y;
int backboardFlag;

void initBallPosition(float x, float y);
void draw_ball(float x_curr,float y_curr, float ball_rotation);
void updateBallPosition(float time);
void setBackboardFlag(int b);


#endif

