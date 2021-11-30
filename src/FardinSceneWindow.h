#ifndef __GL_POLYGON_WINDOW_H__
#define __GL_POLYGON_WINDOW_H__ 1

#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QBoxLayout>
#include "FardinSceneWidget.h"

class FardinSceneWindow: public QWidget
	{ 
	public:
       
	
	// constructor / destructor
    FardinSceneWindow(QWidget *parent);
    ~FardinSceneWindow();

	// visual hierarchy
	// menu bar
	QMenuBar *menuBar;
		// file menu
		QMenu *fileMenu;
			// quit action
			QAction *actionQuit;

	// window layout
	QBoxLayout *windowLayout;

	// beneath that, the main widget
    FardinSceneWidget *fardiWidget;
	// and a slider for the number of vertices
	QSlider *nVerticesSlider;

	// resets all the interface elements
	void ResetInterface();
	}; 
	
#endif
