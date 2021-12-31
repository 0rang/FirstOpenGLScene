#ifndef __GL_POLYGON_WIDGET_H__
#define __GL_POLYGON_WIDGET_H__ 1

#include <QGLWidget>


class FardinSceneWidget: public QGLWidget
    {
    Q_OBJECT
public:
    FardinSceneWidget(QWidget *parent);
    ~FardinSceneWidget(){};
    int getCameraAngleHori() { return cameraAngleHori; }

public slots:
    void SetCameraAngleHori(int angle);
		
protected:
	// called when OpenGL context is set up
	void initializeGL();
	// called every time the widget is resized
	void resizeGL(int w, int h);
	// called every time the widget needs painting
	void paintGL();

private:
    void scene();
    void pyramid();
	void cube();
    void spider();
    void spider_leg();

    int cameraAngleHori;
    };
	
#endif
