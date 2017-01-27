#include "openglwidget.h"

double scene_left=-10.0, scene_right=10.0,scene_top=10.0,scene_bottom=-10.0,scene_near=1.0,scene_far=15.0;
double width_height_ratio=1.0;

OpenGLWidget::OpenGLWidget(QWidget* parent):
QGLWidget(parent){
    QTimer * timer=new QTimer;
    connect(timer,SIGNAL(timeout()),SLOT(animation()));
    timer->start(30);
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
    glLoadIdentity();
    glPushMatrix();

    glTranslatef(fish.center_x,fish.center_y,fish.center_z);
    glRotatef(camera_x_rotation/64,1.0f,0.0f,0.0f);
    glRotatef(camera_y_rotation/64,0.0f,1.0f,0.0f);
    glTranslatef(-fish.center_x,-fish.center_y,-fish.center_z);
    fish.draw();
    glPopMatrix();
}

void OpenGLWidget::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        leftMousePressed=true;
        left_mouse_press_position_x=event->x();
        left_mouse_press_position_y=event->y();
    }
}

void OpenGLWidget::mouseReleaseEvent(QMouseEvent *event){
    if (event->button()==Qt::LeftButton)
        leftMousePressed=false;

}

void OpenGLWidget::mouseMoveEvent(QMouseEvent *event){
    GLfloat delta_y=event->x()-left_mouse_press_position_x;
    GLfloat delta_x=event->y()-left_mouse_press_position_y;
//    if (delta_x<0) delta_x=-delta_x;
//    if (delta_y<0) delta_y=-delta_y;
    GLfloat rotation_x=camera_x_rotation+delta_x, rotation_y=camera_y_rotation+delta_y;
    if (leftMousePressed){
        if (camera_x_rotation!=rotation_x)
            camera_x_rotation=rotation_x;
        if (camera_y_rotation!=rotation_y)
            camera_y_rotation=rotation_y;
        updateGL();
    }
}

void OpenGLWidget::animation(){
    if (fish.back_fin_z_move>0.5)
        fish.back_fin_z_move_direction=-1;
    else if (fish.back_fin_z_move<-0.5)
        fish.back_fin_z_move_direction=1;
    fish.back_fin_z_move+=fish.back_fin_z_move_direction*0.05;
    updateGL();
}
