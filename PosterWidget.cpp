#include "PosterWidget.hpp"

#include "PerpendicularShadowEffect.hpp"

#include <QMouseEvent>

PosterWidget::PosterWidget(QGraphicsScene *scene, QWidget *parent) : QGraphicsView(scene, parent) {
	unselect();

	setMouseTracking(true);
}

void PosterWidget::mouseMoveEvent(QMouseEvent * event) {
	if (event->type() == QMouseEvent::MouseMove) {
		emit mouseEntered();
		select();
		event->accept();
		return;
	}
	event->ignore();
}

void PosterWidget::select() {
	auto bodyShadow = new PerpendicularShadowEffect();
	bodyShadow->setBlurRadius(20.0);
	bodyShadow->setDistance(6.0);
	bodyShadow->setColor(QColor(0, 0, 255, 80));
	setAutoFillBackground(true);
	setGraphicsEffect(bodyShadow);
}

void PosterWidget::unselect() {
	auto bodyShadow = new PerpendicularShadowEffect();
	bodyShadow->setBlurRadius(20.0);
	bodyShadow->setDistance(6.0);
	bodyShadow->setColor(QColor(0, 0, 0, 80));
	setAutoFillBackground(true);
	setGraphicsEffect(bodyShadow);
}