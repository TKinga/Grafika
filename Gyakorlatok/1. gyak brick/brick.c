
#include "brick.h"
#include <math.h>


int has_square_sides(Brick* brick){
    int ret = 0;
    if(brick->x==brick->y ||brick->y==brick->z || brick->x==brick->z){
        ret = 1;
    }
    return ret;
}

int isValid(Brick* brick){
    if(brick->x!=brick->x ||brick->y!=brick->y|| brick->z!=brick->z){
        return 0;
    }
    return 1;
}


void set_brick_data(Brick* brick, double x, double y, double z)
{
    if(x>0){
        brick->x=x;
    }
    else{
        brick->x=NAN;
    }
    if(y>0){
        brick->y=y;
    }
    else{
        brick->y=NAN;
    }
    if(z>0){
        brick->z=z;
    }
    else{
        brick->z=NAN;
    }
}

double calculate_brick_volume(const Brick* brick)
{
	double volume = brick->x*brick->y*brick->z;
	return volume;
}
double calculate_brick_surface(const Brick* brick){
    double surface = 2*(brick->x*brick->y+brick->x*brick->z+brick->z*brick->y);
    return surface;
}