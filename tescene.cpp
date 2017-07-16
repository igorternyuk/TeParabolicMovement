#include "tescene.h"
#include "teball.h"
#include "tethread.h"
#ifdef DEBUG
#include <QDebug>
#endif

TeScene::TeScene(QObject *parent) :
    QGraphicsScene(SCENE_LEFT, SCENE_TOP, SCENE_WIDTH, SCENE_HEIGHT, parent),
    m_index(0), m_a(DEFAULT_A), m_b(DEFAULT_B), m_c(DEFAULT_C)
{

    m_thread = new TeThread(DELAY, this);
    m_ball = new TeBall(SCENE_LEFT, SCENE_HEIGHT, 10.0, 10.0);
    calcPath();
    this->addRect(SCENE_LEFT, SCENE_TOP, SCENE_WIDTH, SCENE_HEIGHT);
    this->addPolygon(QPolygonF(m_path));

    //Aquí agregamos nuestra pelotita a la escena
    this->addItem(m_ball);
    //Conectamos los señales con las ranuras
    connect(m_thread, &TeThread::timeOut, [&](){
        if(m_index > m_path.size() - 1)
        {
            m_index = 0;
        }
        const double x = m_path.at(m_index).x();
        const double y = m_path.at(m_index).y();
        m_ball->setPosX(x);
        m_ball->setPosY(y);
#ifdef DEBUG
        qDebug() << "point " << m_index << "x = " << x << "y = " << y;
#endif
        update();
        ++m_index;
    });
}

TeScene::~TeScene()
{
    m_thread->quit();
    if(!m_thread->wait(3000)) //Wait until it actually has terminated (max. 3 sec)
    {
        m_thread->terminate(); //Thread didn't exit in time, probably deadlocked, terminate it!
        m_thread->wait(); //We have to wait again here!
    }
}

bool TeScene::isAnimation()
{
    return m_thread->isRunning();
}

void TeScene::toggleAnimation()
{
    if(m_thread->isRunning())
    {
        m_thread->terminate();
        emit animationStopped();
    }
    else
    {
        m_thread->start();
        emit animationStarted();
    }
}

void TeScene::calcPath()
{
    m_path.clear();
    //int k = 0;
    for(double x = SCENE_LEFT; x <= SCENE_WIDTH; x += 1)
    {
        const double y = m_a * x * x + m_b * x + m_c;
        //const double y = 1.0 / 150 * (x - 300) * (x - 300);
        //qDebug() << "point " << ++k << "x = " << x << " y = " << y;
        m_path << QPointF(x, y);
    }
}

void TeScene::resetBall()
{
    m_ball->setX(m_path.at(0).x());
    m_ball->setY(m_path.at(0).y());
}

