#ifndef BRICK_H
#define BRICK_H



typedef struct Brick
{
	double x;
	double y;
	double z;
} Brick;

void set_brick_size(Brick* brick, double x, double y, double z);

/*Calculating the volume of the brick*/
double calculate_brick_volume(const Brick*brick);


/*Calculating the volume of the brick*/
double calculate_brick_surface(const Brick*brick);

int has_square_sides(Brick*brick);


int isValid(Brick* brick);

#endif
