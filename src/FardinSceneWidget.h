#ifndef __GL_POLYGON_WIDGET_H__
#define __GL_POLYGON_WIDGET_H__ 1

#include <QGLWidget>


class FardinSceneWidget: public QGLWidget
	{ // 
	public:
    FardinSceneWidget(QWidget *parent);

		
	protected:
	// called when OpenGL context is set up
	void initializeGL();
	// called every time the widget is resized
	void resizeGL(int w, int h);
	// called every time the widget needs painting
	void paintGL();

	private:

	void cube();
	void polygon(int, int, int, int);

	}; // class GLPolygonWidget
	
#endif
