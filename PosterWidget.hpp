#ifndef MOVIESSCROLLER_POSTERWIDGET_HPP
#define MOVIESSCROLLER_POSTERWIDGET_HPP

#include <QGraphicsView>

class PosterWidget : public QGraphicsView {
Q_OBJECT
public:
	explicit PosterWidget(QGraphicsScene *scene, QWidget *parent = nullptr);

	void mouseMoveEvent(QMouseEvent *) override;

	void select();
	void unselect();

signals:
	void mouseEntered();
};

#endif //MOVIESSCROLLER_POSTERWIDGET_HPP
