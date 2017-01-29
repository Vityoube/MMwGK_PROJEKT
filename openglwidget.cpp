#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent):
QGLWidget(parent){
    QTimer * timer=new QTimer;
    connect(timer,SIGNAL(timeout()),SLOT(animation()));
    timer->start(60);
}

FIBITMAP * OpenGLWidget::load_bitmap(char const* file_name){
    FIBITMAP * bitmap;
    FREE_IMAGE_FORMAT fif=FreeImage_GetFIFFromFilename(file_name);
    bitmap=FreeImage_Load(fif,file_name,JPEG_DEFAULT);
    if (!bitmap){
        std::cerr<<"Could not load texture image "<<file_name<<std::endl;
        exit(0);
    }
    return bitmap;
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
    glEnable(GL_TEXTURE_2D);
    fish_texture_bitmap=load_bitmap("fish_texture.jpg");
    bottom_texture_bitmap=load_bitmap("bottom_texture.png");
    fish_texture=fish.load_fish_texture(fish_texture_bitmap);
    bottom_texture=bottom.load_texture(bottom_texture_bitmap);
}

void OpenGLWidget::resizeGL(int width, int height){
    width_height_ratio=(double)width/(double)height;
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(scene_left,scene_right,scene_bottom,scene_top,scene_near,scene_far);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    fish_texture_bitmap=load_bitmap("fish_texture.jpg");
    bottom_texture_bitmap=load_bitmap("bottom_texture.png");
    fish_texture=fish.load_fish_texture(fish_texture_bitmap);
    bottom_texture=bottom.load_texture(bottom_texture_bitmap);
}

void OpenGLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(fish.center_x,fish.center_y,fish.center_z);
    glRotatef(-20.0f,1.0f,0.0f,0.0f);
    glRotatef(camera_y_rotation/32,0.0f,1.0f,0.0f);
    glTranslatef(-fish.center_x,-fish.center_y,-fish.center_z);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexGenf(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
    glTexGenf(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
    glBindTexture(GL_TEXTURE_2D,fish_texture);
    fish.draw();

    glPopMatrix();
    glPushMatrix();
//    glTranslatef(bottom.center_x,bottom.center_y,bottom.center_z);
    glTranslated(0,0,bottom.center_z);

    glRotatef(-20.0f,1.0f,0.0f,0.0f);
    glRotatef(camera_y_rotation/32,0.0f,1.0f,0.0f);
    glTranslated(0,0,-bottom.center_z);
//    glTranslatef(-bottom.center_x,-bottom.center_y,-bottom.center_z);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexGenf(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
    glTexGenf(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
    glBindTexture(GL_TEXTURE_2D,bottom_texture);
    bottom.draw();

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
    if (fish.back_fin_z_move>0.2)
        fish.back_fin_z_move_direction=-1;
    else if (fish.back_fin_z_move<-0.2)
        fish.back_fin_z_move_direction=1;
    fish.back_fin_z_move+=fish.back_fin_z_move_direction*0.05;
    updateGL();
}

