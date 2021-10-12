#ifndef PORTGROUP_H
#define PORTGROUP_H

#include "common/pushbutton.h"
#include "common/dirfiletable.h"
#include "common/extnametable.h"
#include "common/dirselectdialog.h"
#include "common/ipporttable.h"
#include "common/protocoltable.h"

#include <QObject>
#include <QWidget>
#include <QGroupBox>
#include <QMenu>
#include <QAction>

class PushButton;
class DirFileTable;
class ExtNameTable;
class DirSelectDialog;


class PortGroup : public QGroupBox
{
    Q_OBJECT
public:
    PortGroup(int flag = 0, QWidget *parent = Q_NULLPTR);

    void InitAllWidget();

    void SetFocus(bool bFocus);

public slots:
    void AddIpPortClicked();
    void AddProtocolClicked();

public:
    bool m_bFocus;

    PushButton  *m_pbExtName;
    PushButton  *m_ppbDirFile;

    //ExtNameTable    *m_penExtName;
    IpPortNameTable    *m_IpPortName;
    ProtocolNameTable    *m_ProtocolName;
    //IpPortNameTable    *m_ProtocolName;

};

#endif // PORTGROUP_H
