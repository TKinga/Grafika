#ifndef ICEBALL_H
#define ICEBALL_H

#include "utils.h"
#include "camera.h"
#include "map.h"
#include "ice_element.h"
#include "fire.h"
#include <stdbool.h>
#include <obj/model.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


//#include <cup.h> vagy flag.h
/*
# minden olyan elem ami szerepelhet benne kupa/zászló , fire stb
PUSH POP egyszerre hajtja végre a dolgokat benne
*/
typedef struct Iceball
{
    GLuint iceball_texture_id; 
    Model model;
    float radius;
    float moving_speed;
    float rotation_speed;
    float gravity;
    float upward_speed;
    float bouncing;
    bool in_the_air;
    vec3 position;
    vec3 rotation;
    Material iceball_material;

} Iceball;


//jéggömb inincializálása
void init_iceball(Iceball* iceball);

//jéggömb megrajzolása
void draw_iceball(Iceball* iceball);

//jéggömb mozgatása
void setting_iceball_moving_speed(Iceball* iceball, float speed);

//jéggömb forgatása
void setting_iceball_rotation(Iceball* iceball, float angle);

//jéggömb pattogása
void setting_upward_speed(Iceball* iceball, float jumping_power);

//jéggömb helyzetének visszaállítása
void reset_iceball(Iceball* iceball);

//jéggömb helyzetének frissítése
void update_iceball(Iceball* iceball, Map* map, Ice_element* ice_element, Fire* fire  );  //KIEGÉSZÍTÉS MINDEN OLYAN ELEMMEL AMI SZEREPEL


/* ICEBALL_H*/
#endif 