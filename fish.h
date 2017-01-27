#ifndef FISH_H
#define FISH_H

#include <GL/gl.h>
#include <QTimer>
#include <FreeImage.h>
#include <iostream>
#include <GL/glu.h>

class Fish
{
public:
    Fish();
    void draw();
    GLuint load_fish_texture();

public:
    double center_x=0, center_y=-5, center_z=-5;
    double back_fin_z_move=0;
    double side_fins_y_move=0,side_fins_z_move=0;
    int back_fin_z_move_direction=1;
    int side_fins_move_direction=1;
};

#endif // FISH_H
