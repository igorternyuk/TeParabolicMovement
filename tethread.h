#ifndef TETHREAD_H
#define TETHREAD_H

#include <QThread>

class TeThread : public QThread
{
    Q_OBJECT

public:
    explicit TeThread(int msec, QObject *parent = nullptr);
signals:
    void timeOut();
protected:
    void run() override;
private:
    int m_miliseconds;
};

#endif // TETHREAD_H

