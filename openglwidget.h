#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QGLWidget>
#include <GL/glu.h>

class OpenGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width,int height);
    void paintGL();
};

#endif // OPENGLWIDGET_H
