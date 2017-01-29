#ifndef BOTTOM_H
#define BOTTOM_H

#include <GL/gl.h>
#include <FreeImage.h>
#include <iostream>

class Bottom
{
public:
    Bottom();
    void draw();
    GLuint load_texture(FIBITMAP *);

public:
    double center_x=0.0, center_y=-8.0, center_z=-11;
};

#endif // BOTTOM_H
