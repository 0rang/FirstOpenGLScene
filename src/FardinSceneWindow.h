#ifndef __GL_POLYGON_WINDOW_H__
#define __GL_POLYGON_WINDOW_H__ 1

#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QBoxLayout>
#include "SceneWidget.h"

class FardinSceneWindow: public QWidget
	{ 
	public:
    FardinSceneWindow(QWidget *parent);
    ~FardinSceneWindow();

    // Signals to connect to Scene logic
    QSlider* cameraZoomSlider;
    QSlider* cameraAngleHoriSlider;
    QSlider* cameraAngleVertSlider;

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
