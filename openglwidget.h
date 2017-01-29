#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QMouseEvent>
#include <QGLWidget>
#include <GL/glu.h>
#include "fish.h"
#include "bottom.h"

class OpenGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget *parent = 0);
    FIBITMAP * load_bitmap(char const* file_name);
    void initializeGL();
    void resizeGL(int width,int height);
    void paintGL();
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private slots:
    void animation();
public:
    Fish fish;
    Bottom bottom;
    double scene_left=-10.0, scene_right=10.0,scene_top=10.0,scene_bottom=-10.0,scene_near=1.0,scene_far=21.0;
    double width_height_ratio=1.0;
    GLuint fish_texture, bottom_texture;
    FIBITMAP * fish_texture_bitmap;
    FIBITMAP * bottom_texture_bitmap;

private:
    bool leftMousePressed=false;
    GLfloat camera_x_rotation=0.0f;
    GLfloat camera_y_rotation=0.0f;
    GLfloat left_mouse_press_position_x=0.0f;
    GLfloat left_mouse_press_position_y=0.0f;
};

#endif // OPENGLWIDGET_H
