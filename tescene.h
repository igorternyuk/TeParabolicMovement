#ifndef TESCENE_H
#define TESCENE_H

#include <QGraphicsScene>

#define SCENE_LEFT 0.0
#define SCENE_TOP 0.0
#define SCENE_WIDTH 600.0
#define SCENE_HEIGHT 600.0
#define DEFAULT_A 1.0/150.0
#define DEFAULT_B -4.0
#define DEFAULT_C 600.0
#define DELAY 10

class TeBall;
class TeThread;

class TeScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit TeScene(QObject *parent = nullptr);
    ~TeScene();
    bool isAnimation();
signals:
    void animationStarted();
    void animationStopped();
public slots:
    void toggleAnimation();
protected:
    //virtual void update(const QRectF &rect = QRectF()) override;
private:
    int m_index;
    double m_a, m_b, m_c; //Coefficients of parabola
    TeBall *m_ball;
    TeThread *m_thread;
    QVector<QPointF> m_path;
    void calcPath();
    void resetBall();
};

#endif // TESCENE_H
