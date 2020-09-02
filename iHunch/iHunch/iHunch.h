#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_iHunch.h"
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QAction>
#include <QWidget>
#include <QMenu>
#include <QStyle>

QT_BEGIN_NAMESPACE
namespace Ui { class iHunchClass; }
QT_END_NAMESPACE

class iHunch : public QMainWindow
{
    Q_OBJECT

public:
    iHunch(QWidget *parent = Q_NULLPTR);
    ~iHunch();

protected:
    //�ּ�ȭ �Ǿ��� �� �Ǵ� ���� â�� ������ �� ȣ��
    void closeEvent(QCloseEvent* event);

private:
    Ui::iHunchClass* ui;
    //Ʈ���̾����� Ŭ���� �ν��Ͻ�
    QSystemTrayIcon* m_trayicon;

public slots:
    //�ý��� Ʈ���� ������ Ŭ�� �̺�Ʈ�κ��� �ñ׳��� ó���ϴ� slot�Լ�
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void popupslot();
};
