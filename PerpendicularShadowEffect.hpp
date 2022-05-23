#ifndef MOVIESSCROLLER_PERPENDICULARSHADOWEFFECT_HPP
#define MOVIESSCROLLER_PERPENDICULARSHADOWEFFECT_HPP

#include <QGraphicsEffect>

class PerpendicularShadowEffect : public QGraphicsEffect
{
Q_OBJECT
public:
	explicit PerpendicularShadowEffect(QObject *parent = nullptr);

	void draw(QPainter* painter) override;
	[[nodiscard]] QRectF boundingRectFor(const QRectF& rect) const override;

	inline void setDistance(qreal distance) { _distance = distance; updateBoundingRect(); }
	[[nodiscard]] inline qreal distance() const { return _distance; }

	inline void setBlurRadius(qreal blurRadius) { _blurRadius = blurRadius; updateBoundingRect(); }
	[[nodiscard]] inline qreal blurRadius() const { return _blurRadius; }

	inline void setColor(const QColor& color) { _color = color; }
	[[nodiscard]] inline QColor color() const { return _color; }

private:
	qreal  _distance;
	qreal  _blurRadius;
	QColor _color;
};


#endif //MOVIESSCROLLER_PERPENDICULARSHADOWEFFECT_HPP
