#include "FardinSceneWindow.h"

// constructor / destructor
FardinSceneWindow::FardinSceneWindow(QWidget *parent)
	: QWidget(parent)
	{ // constructor

    /*
    // create menu bar
    menuBar = new QMenuBar(this);

	// create the action
	actionQuit = new QAction("&Quit", this);

	// leave signals & slots to the controller
	
	// add the item to the menu
	fileMenu->addAction(actionQuit);
    */

	// create the window layout
	windowLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

	// create main widget
    fardiWidget = new FardinSceneWidget(this);
    windowLayout->addWidget(fardiWidget);

	// create slider
	nVerticesSlider = new QSlider(Qt::Horizontal);
	windowLayout->addWidget(nVerticesSlider);
	} // constructor

FardinSceneWindow::~FardinSceneWindow()
	{ // destructor
	delete nVerticesSlider;
    delete fardiWidget;
	delete windowLayout;
    /*
    delete actionQuit;
	delete fileMenu;
	delete menuBar;
    */
	} // destructor

// resets all the interface elements
void FardinSceneWindow::ResetInterface()
	{ // ResetInterface()
	nVerticesSlider->setMinimum(3);
	nVerticesSlider->setMaximum(30);

	//don't use the slider for now

    //nVerticesSlider->setValue(thePolygon->nVertices);
	
	// now force refresh
    fardiWidget->update();
	update();
	} // ResetInterface()
