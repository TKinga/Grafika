#include <stdio.h>
#include "brick.h"

void brick(Brick*brick);


int main(int argc, char* argv[])
{
	Brick brick;
	printf("Brick number 1:\n");
    set_brick_data(&brick, 10, -1, 16);
    examineBrick(&brick);
    printf("\nBrick number 2:\n");
    set_brick_data(&brick, 10, 5, 16);
    examineBrick(&brick);
    printf("\nBrick number 3:\n");
    set_brick_data(&brick, 10, 100, 16);
    examineBrick(&brick);
}


void brick(Brick*brick)
{

if (!ok(brick))
{
    printf("You gave something incorrectly. Try again!");
}
else
{
double volume= calculate_brick_volume(brick);
double surface= calculate_brick_surface(brick);

printf("Brick volume: %lf", volume);
printf("Brick surface: %lf", surface);

if (it_has_square_sides(brick))
{
    printf("Has square sides.");
}
else
{
    printf("Has no square sides.");
}


}

}