#include <QApplication>
#include <QPushButton>

#include "Window.hpp"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	Window window;
	window.show();
	return app.exec();
}
