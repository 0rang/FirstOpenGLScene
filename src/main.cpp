#include <QApplication>
#include <QVBoxLayout>
#include "FardinSceneWindow.h"

int main(int argc, char *argv[])
	{ // main()
	// create the application
	QApplication app(argc, argv);

	// create a master widget
    FardinSceneWindow *window = new FardinSceneWindow(NULL);



	// resize the window
    window->resize(720, 720);

	// show the label
	window->show();

	// start it running
	app.exec();

	// clean up
	//	delete controller;
	delete window;
	
	// return to caller
	return 0; 
	} // main()
