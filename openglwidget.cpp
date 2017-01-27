#include "openglwidget.h"

double scene_left=-10.0, scene_right=10.0,scene_top=10.0,scene_bottom=-10.0,scene_near=1.0,scene_far=10.0;
double width_height_ratio=1.0;

OpenGLWidget::OpenGLWidget(QWidget* parent):
QGLWidget(parent)
{
}

void OpenGLWidget::initializeGL(){
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,500,500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(scene_left,scene_right,scene_bottom,scene_top,scene_near,scene_far);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenGLWidget::resizeGL(int width, int height){
    width_height_ratio=(double)width/(double)height;
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat resized_scene_left=scene_left*width_height_ratio, resized_scene_right=scene_right*width_height_ratio,
            resized_scene_top=scene_top*width_height_ratio, resized_scene_bottom=scene_bottom*width_height_ratio;
    glOrtho(resized_scene_left,resized_scene_right,resized_scene_bottom,resized_scene_top,scene_near,scene_far);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenGLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor4d(1.0,0.2,0.5,1.0);
    glVertex3d(1.0*width_height_ratio,5.0*width_height_ratio,-9.0);
    glVertex3d(6.0*width_height_ratio,-5.0*width_height_ratio,-9.0);
    glVertex3d(-5.0*width_height_ratio,-5.0*width_height_ratio,-9.0);
    glEnd();
}
