#include "SceneWindow.h"
#include <QDebug>
#include <QSizePolicy>
#include <QLabel>

// constructor / destructor
SceneWindow::SceneWindow(QWidget *parent)
    : QWidget(parent) {

	// create the window layout
    windowLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);


    // create main widget
    sceneWidget = new SceneWidget(this);
    sceneWidget->setMinimumSize(300, 300);
    sceneWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    toolbar = new QGridLayout(this);

    windowLayout->addWidget(sceneWidget);
    windowLayout->addLayout(toolbar);

    // Start timer
    qTimer = new QTimer();
    qTimer->start(30); // set animation tick period (msec)
    connect(qTimer, SIGNAL(timeout()), sceneWidget, SLOT(IncrementCircMotionAngle()));

    //
    // Configure, label and connect the interactive UI elements
    //

    // this incremented row count makes it easier to insert a new row
    // and guarantees that UI is in the same order as the code
    int row = 0;

    // horizontal camera angle
    cameraAngleHoriSlider = new QSlider(Qt::Horizontal);
    cameraAngleHoriSlider->setMinimum(-90);
    cameraAngleHoriSlider->setMaximum(90);
    row++;
    toolbar->addWidget(new QLabel("Angle Horizontal"), row, 0);
    toolbar->addWidget(cameraAngleHoriSlider, row, 1);
    connect(cameraAngleHoriSlider, SIGNAL(valueChanged(int)), sceneWidget, SLOT(SetCameraAngleHori(int)));
    cameraAngleHoriSlider->setValue(0);

    // vertical camera angle
    cameraAngleVertSlider = new QSlider(Qt::Horizontal);
    cameraAngleVertSlider->setMinimum(0);
    cameraAngleVertSlider->setMaximum(90);
    row++;
    toolbar->addWidget(new QLabel("Angle Vertical"), row, 0);
    toolbar->addWidget(cameraAngleVertSlider, row, 1);
    connect(cameraAngleVertSlider, SIGNAL(valueChanged(int)), sceneWidget, SLOT(SetCameraAngleVert(int)));
    cameraAngleVertSlider->setValue(45);

    // camera zoom
    cameraZoomSlider = new QSlider(Qt::Horizontal);
    cameraZoomSlider->setMinimum(2);
    cameraZoomSlider->setMaximum(10);
    row++;
    toolbar->addWidget(new QLabel("Zoom"), row, 0);
    toolbar->addWidget(cameraZoomSlider, row, 1);
    connect(cameraZoomSlider, SIGNAL(valueChanged(int)), sceneWidget, SLOT(SetCameraZoom(int)));
    cameraZoomSlider->setValue(3);

}

