#ifndef __GL_POLYGON_WIDGET_H__
#define __GL_POLYGON_WIDGET_H__ 1

#include <QGLWidget>
#include <QTimer>
#include <GL/glu.h>
#include <string>

#define NUM_TEXTURES 3

/* cpp files that implement this class
 * SceneWidget.cpp
 * object/DrawSpider.cpp
 * object/DrawSpiderWeb.cpp
 */

class SceneWidget: public QGLWidget{
    Q_OBJECT
public:
    SceneWidget(QWidget *parent) {
        quadric = gluNewQuadric();
        marcQimg = new QImage(QString("Marc_Dekamps.ppm"));
        markusQimg = new QImage(QString("markus.ppm"));
        earthQimg = new QImage(QString("Mercator-projection.ppm"));
    }
    ~SceneWidget(){
        gluDeleteQuadric(quadric);
        delete marcQimg;
        delete markusQimg;
        delete earthQimg;
    }
    int getCameraAngleHori() { return cameraAngleHori; }

public slots:
    void SetCameraAngleHori(int angle);
    void SetCameraAngleVert(int angle);
    void SetCameraZoom(int distance);

    void IncrementCircMotionAngle();
		
protected:
	// called when OpenGL context is set up
	void initializeGL();
	// called every time the widget is resized
	void resizeGL(int w, int h);
	// called every time the widget needs painting
	void paintGL();

private:
    // vars that are controlled with UI
    int cameraAngleHori;
    int cameraAngleVert;
    int cameraZoom;

    int spiderCircularPos;


    GLUquadric* quadric;


    QImage* marcQimg;
    QImage* markusQimg;
    QImage* earthQimg;
    GLuint bindCount;
    GLuint textureIDs[3]; // 0: Marc; 1:Markus; 2: Earth; (fingers crossed)

    void scene_objects(); // show the whole scene
    void test_things();

    // convex objects with manually defined vertices and normals
	void cube();
    void textured_cube(QImage* texture_qimg); // call glBindTexture with a new number before you call this
    void pyramid();

    // MAYBE: encapsulate spider code in it's own class?
    // modularised code for rendering the spider
    void spider(); //calls all the other spider components
    void earth_textured_sphere(); // squashed sphere using earth texture
    void spider_leg(float base_length=2, float base_angle=30, float tip_length=2, float tip_angle=30); // simple leg with one joint
    void spider_circular_motion();
    void spider_animation();

    //fly

    // render the spider's web
    void spider_web();
    void polygon_from_cylinders(GLfloat radius_scale_compensation); //applied at different scales as part of the spider web


    // test functions
    void test_pyramid();
    void test_earth_textured_sphere();
    void test_textured_cube();
};
	
#endif
