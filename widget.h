#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#ifdef DEBUG
#include <QResizeEvent>
#endif

namespace Ui {
class Widget;
}

class TeScene;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
#ifdef DEBUG
    void resizeEvent(QResizeEvent *event);
    //void closeEvent(QCloseEvent *event) override;
#endif
private:
    Ui::Widget *ui;
    TeScene * m_scene;
    enum screen_geom{WIDTH = 880, HEIGHT = 650};
};

#endif // WIDGET_H
