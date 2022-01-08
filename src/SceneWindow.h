#ifndef __GL_POLYGON_WINDOW_H__
#define __GL_POLYGON_WINDOW_H__ 1

#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QBoxLayout>
#include <QPushButton>
#include "SceneWidget.h"

class SceneWindow: public QWidget{ 
public:
    SceneWindow(QWidget *parent);
    ~SceneWindow() {
        delete cameraAngleHoriSlider;
        delete sceneWidget;
        delete windowLayout;
        delete toolbar;
        delete qTimer;
    }

    // Signals to connect to Scene logic
    QSlider* cameraZoomSlider;
    QSlider* cameraAngleHoriSlider;
    QSlider* cameraAngleVertSlider;

    QPushButton* specularButton;

    QTimer* qTimer; // set base tick rate for animation

private:
    void resetInterface();

    // Top level layout
    QBoxLayout* windowLayout;

    // OpenGL Scene on the left hand side
    SceneWidget* sceneWidget;

    // Interactive UI elements on the right hand side
    QGridLayout* toolbar;
};
	
#endif
