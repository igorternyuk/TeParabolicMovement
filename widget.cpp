#include "widget.h"
#include "ui_widget.h"
#include "tescene.h"

#ifdef DEBUG
#include <QDebug>
#endif

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("ParabolicMovement");
    this->setFixedSize(WIDTH, HEIGHT);
    m_scene = new TeScene(this);
    ui->graphicsView->setScene(m_scene);
    connect(ui->btnAnimation, SIGNAL(clicked(bool)), m_scene, SLOT(toggleAnimation()));
    connect(m_scene, &TeScene::animationStarted, [&](){
        ui->btnAnimation->setText("Stop animation");
    });
    connect(m_scene, &TeScene::animationStopped, [&](){
        ui->btnAnimation->setText("Start animation");
    });
}

Widget::~Widget()
{
    /*if(m_scene->isAnimation())
    {
        m_scene->toggleAnimation();
    }*/
    delete ui;
}

#ifdef DEBUG
void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << event->size();
    QWidget::resizeEvent(event);
}
#endif

/*void Widget::closeEvent(QCloseEvent *event)
{
    if(m_scene->isAnimation())
    {
        m_scene->toggleAnimation();
    }
    Widget::closeEvent(event);
}*/


