#include "Window.hpp"

#include "PosterWidget.hpp"

#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBitmap>
#include <QGraphicsDropShadowEffect>

Window::Window() {
	setWindowTitle(tr("Basic Drawing"));
	setPalette(setUpPalette());
	setMinimumSize(1200, 600);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setWidgetResizable(true);

	auto layout = new QGridLayout;

	std::vector<PosterWidget*> children;

	for (int column = 0; column < 7; ++column) {
		for (int row = 0; row < 4; ++row) {
			PosterWidget *view = setUpPosterView();
			const auto alignment = Qt::AlignmentFlag::AlignHCenter | Qt::AlignmentFlag::AlignTop;
			layout->addWidget(view, row, column, alignment);
			children.push_back(view);
		}
	}

	for (const auto & childA : children) {
		for(auto & childB : children) {
			QObject::connect(childA, &PosterWidget::mouseEntered, childB, &PosterWidget::unselect);
		}
	}

	auto widget = new QWidget;
	widget->setLayout(layout);
	setWidget(widget);
}

PosterWidget * Window::setUpPosterView() {
	const QPixmap poster = setUpPoster();

	auto scene = new QGraphicsScene();
	scene->addPixmap(poster);

	auto view = new PosterWidget(scene);
	view->setFixedSize(poster.width()+2, poster.height()+2);


	return view;
}

QPixmap Window::setUpPoster() {
	static QPixmap pixmap("assets/raw/test.jpg");
	auto scaled = pixmap.scaledToWidth(135);

	QBitmap bitmap(scaled.size());
	bitmap.clear();
	QPainter pixmapPainter(&bitmap);
	pixmapPainter.setRenderHint(QPainter::Antialiasing, true);
	QPainterPath path;
	path.addRoundedRect(0, 0, scaled.width(), scaled.height(), 10, 10);
	pixmapPainter.fillPath(path, Qt::color1);

	scaled.setMask(bitmap);

	return scaled;
}

QPalette Window::setUpPalette() {
	const QColor darkGray(53, 53, 53);
	const QColor gray(128, 128, 128);
	const QColor blue(42, 130, 218);

	QPalette darkPalette;
	darkPalette.setColor(QPalette::Window, darkGray);
	darkPalette.setColor(QPalette::WindowText, Qt::white);
	darkPalette.setColor(QPalette::Base, darkGray);
	darkPalette.setColor(QPalette::AlternateBase, darkGray);
	darkPalette.setColor(QPalette::ToolTipBase, blue);
	darkPalette.setColor(QPalette::ToolTipText, Qt::white);
	darkPalette.setColor(QPalette::Text, Qt::white);
	darkPalette.setColor(QPalette::Button, darkGray);
	darkPalette.setColor(QPalette::ButtonText, Qt::white);
	darkPalette.setColor(QPalette::Link, blue);
	darkPalette.setColor(QPalette::Highlight, blue);
	darkPalette.setColor(QPalette::HighlightedText, Qt::black);

	darkPalette.setColor(QPalette::Active, QPalette::Button, gray.darker());
	darkPalette.setColor(QPalette::Disabled, QPalette::ButtonText, gray);
	darkPalette.setColor(QPalette::Disabled, QPalette::WindowText, gray);
	darkPalette.setColor(QPalette::Disabled, QPalette::Text, gray);
	darkPalette.setColor(QPalette::Disabled, QPalette::Light, darkGray);

	return darkPalette;
}