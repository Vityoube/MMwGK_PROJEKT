#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QMouseEvent>
#include <QGLWidget>
#include <GL/glu.h>
#include "fish.h"

class OpenGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget *parent = 0);
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
private:
    bool leftMousePressed=false;
    GLfloat camera_x_rotation=0.0f;
    GLfloat camera_y_rotation=0.0f;
    GLfloat left_mouse_press_position_x=0.0f;
    GLfloat left_mouse_press_position_y=0.0f;
};

#endif // OPENGLWIDGET_H
