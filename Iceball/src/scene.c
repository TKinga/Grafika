#include "scene.h"
#include "iceball.h"
#include "utils.h"
#include "app.h"
#include "camera.h"
#include "fire.h"
//#include cup.h

#include <stdio.h>
#include <obj/load.h>
#include <obj/draw.h>



void init_scene(Scene* scene)

{
    scene->guide_id = load_texture("assets/textures/gui.jpg");
    scene->lose_id = load_texture("assets/textures/lose.jpg");
    scene->win_id = load_texture("assets/textures/win.jpg");
    //scene->iceball=load_texture("assets/textures/ice texture.png");

    scene->lighting_changer=0.45f;
    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;
    scene->material.shininess = 0.0;


   init_skybox(&(scene->skybox));
   init_map(&(scene->map));
   init_ice_element(&(scene->ice_element1), 4.5, 0.1); ///például, ez msot rnadom, majd ha látom beillesztem őket
   init_ice_element(&(scene->ice_element2), 6.5, 0.1);
   init_ice_element(&(scene->ice_element3), 8.5, 0.1); //7.5?
   //init_ice_element(&(scene->ice_element1), 12.5, 0.1);
   init_iceball(&(scene->iceball));
   // init_cup or award later
   init_fire(&(scene->fire1), 0.4, 3.5);
   init_fire(&(scene->fire2), 0.4, 5.5);
   init_fire(&(scene->fire3), 0.4, 7.5);

}


void set_lighting(float light)
{

    float ambient_light[] = { light, light, light, 1.0f };
    float diffuse_light[] = { light, light, light, 1.0f };
    float specular_light[] = { light, light, light, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);


}

void set_lighting_changer(float light) //siman volt float light
{

    scene.lighting_changer +=light;
}


void set_material(Material* material) //const Material

{
    float ambient_material_color[] = 
    {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue

    };

    float diffuse_material_color[] = 
    {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue

    };

    float specular_material_color[] = 
    {
        material->specular.red,
        material->specular.green,
        material->specular.blue

    };


    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}



void draw_scene(Scene* scene)  //const Scene

{

    set_lighting(scene->lighting_changer);
    set_material(&(scene->material));
    //draw_origin();

    //draw_kupa/zászló is lehet 
    
    draw_iceball(&(scene->iceball));
    draw_skybox(&(scene->skybox));
    draw_map(&(scene->map));

    draw_ice_element(&(scene->ice_element1));
    draw_ice_element(&(scene->ice_element2));
    draw_ice_element(&(scene->ice_element3));
    
    draw_fire(&(scene->fire1));
    draw_fire(&(scene->fire2));
    draw_fire(&(scene->fire3));
   

    update_iceball(&(scene->iceball), &(scene->map), &(scene->ice_element1), &(scene->fire1)); // ne felejtsem el ide is beírni a fire stb dolgokat!! &(scene->fire1)
    update_iceball(&(scene->iceball), &(scene->map), &(scene->ice_element2), &(scene->fire2)); //mind3 sorba kell
    update_iceball(&(scene->iceball), &(scene->map), &(scene->ice_element3), &(scene->fire3));
}


void update_scene(Scene* scene)
{
    set_lighting(scene->lighting_changer);
    //update_iceball(scene->iceball);  //szerepel a scene.c  draw sceneben
}



void reset_lights()
{
scene.lighting_changer = 0.40f; //40.f
}


void draw_origin()
{

    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

