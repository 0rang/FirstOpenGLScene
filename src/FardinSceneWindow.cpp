#include "FardinSceneWindow.h"

// constructor / destructor
FardinSceneWindow::FardinSceneWindow(QWidget *parent)
    : QWidget(parent) {

    // create menu bar
    menuBar = new QMenuBar(this);

	// create the action
	actionQuit = new QAction("&Quit", this);

	// leave signals & slots to the controller
	
	// add the item to the menu
	fileMenu->addAction(actionQuit);

	// create the window layout
    windowLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);

    // create main widget
    fardiWidget = new FardinSceneWidget(this);
    windowLayout->addWidget(fardiWidget);

    toolbar = new QBoxLayout(QBoxLayout::TopToBottom);
    windowLayout->addLayout(toolbar);

    // create slider
    cameraAngleHoriSlider = new QSlider(Qt::Horizontal);
    toolbar->addWidget(cameraAngleHoriSlider);
    connect(cameraAngleHoriSlider, SIGNAL(valueChanged(int)), fardiWidget, SLOT(SetCameraAngleHori(int)));
}

FardinSceneWindow::~FardinSceneWindow() {
    delete cameraAngleHoriSlider;
    delete fardiWidget;
	delete windowLayout;
    delete toolbar;

    delete actionQuit;
	delete fileMenu;
	delete menuBar;

}

