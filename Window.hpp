#ifndef MOVIESSCROLLER_WINDOW_HPP
#define MOVIESSCROLLER_WINDOW_HPP

#include <QScrollArea>

class PosterWidget;
class QPixmap;

class Window : public QScrollArea {
Q_OBJECT

public:
	Window();

private:
	[[nodiscard]] static PosterWidget *setUpPosterView();
	[[nodiscard]] static QPixmap setUpPoster();
	[[nodiscard]] static QPalette setUpPalette();
};


#endif //MOVIESSCROLLER_WINDOW_HPP
