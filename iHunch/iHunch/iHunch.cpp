#include "iHunch.h"

iHunch::iHunch(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::iHunchClass)
{
    ui->setupUi(this);
    this->setWindowTitle("Turtle Neck");

    m_trayicon = new QSystemTrayIcon(this);
    m_trayicon->setIcon(QIcon("gb.png"));
    m_trayicon->setToolTip("Turtle Neck");

    QMenu* menu = new QMenu(this);
    QAction* viewWindow = new QAction(QString::fromLocal8Bit("����"), this);
    QAction* quitAction = new QAction(QString::fromLocal8Bit("����"), this);
    QAction* event1 = new QAction(QString::fromLocal8Bit("�̺�Ʈ1"), this);

    connect(viewWindow, SIGNAL(triggered()), this, SLOT(showNormal()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(event1, SIGNAL(triggered()), this, SLOT(popupslot()));

    menu->addAction(event1);
    menu->addAction(viewWindow);
    menu->addAction(quitAction);

    m_trayicon->setContextMenu(menu);
    m_trayicon->show();

    connect(m_trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
        this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    ui->mainToolBar->hide();
    QStatusBar* myStatusBar = ui->statusBar;
    myStatusBar->showMessage("Developed by asd", 0);
}

iHunch::~iHunch()
{
    delete ui;
}

void iHunch::closeEvent(QCloseEvent* event)
{
    if (this->isVisible())
    {
        event->ignore();
        this->hide();

        m_trayicon->showMessage(
            QString::fromLocal8Bit("���α׷� ������"), QString::fromLocal8Bit("���α׷��� ��׶��忡�� ������"),
            QIcon("gb.png"),
            2000);
    }
}

void iHunch::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick)
        this->show();
}

void iHunch::popupslot()
{
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
    m_trayicon->showMessage(
        QString::fromLocal8Bit("Turtle Neck"), QString::fromLocal8Bit("������ �ڼ��� �����ǰ� �־��."),
        QIcon("gb.png"),
        2000);
}