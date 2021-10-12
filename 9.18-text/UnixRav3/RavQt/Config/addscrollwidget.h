#ifndef ADDSCROLLWIDGET_H
#define ADDSCROLLWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>

#include "pubdef.h"
#include "traygroup.h"
//#include "upgradegroup.h"
#include "portgroup.h"
#include "whitelistgroup.h"
#include "mainwindow.h"


//class UpgradeGroup;
class PortGroup;
//class WhiteListGroup;


class AddScrollWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AddScrollWidget(QWidget *parent, MainWindow *pMainWindow);

signals:

public slots:

public:
    MainWindow  *m_pMainWindow;

    QVBoxLayout *m_pLayout;

    //UpgradeGroup            *m_pUpgrade;
	PortGroup *m_pIpWhiteList;
	PortGroup *m_pIpBlackList;
	PortGroup *m_pIpPort;
	//WhiteListGroup *m_pWhiteList;
};

#endif // ENDSCROLLWIDGET_H
