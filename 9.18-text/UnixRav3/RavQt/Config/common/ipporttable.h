#ifndef IPPORTTABLE_H
#define IPPORTTABLE_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QPixmap>
#include <QVector>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QPainter>
#include <QMouseEvent>
#include <string>
#include <vector>
#include <QMenu>

#include "pubdef.h"

using namespace std;


class IpPortItemModel;
class IpPortIconDelegate;
class IpPortNameTable;


class IpPortItemModel:public QStandardItemModel
{
    Q_OBJECT
public:
    IpPortItemModel(QObject * parent=0);
    virtual ~ IpPortItemModel(){}

signals:


public:
    int m_nHoverRow;

    QVector<QString*> *m_pItems;
    QPixmap * m_pImageDel;
};

class IpPortIconDelegate : public QItemDelegate
{
    Q_OBJECT
public:
		IpPortIconDelegate(QObject *parent = NULL): QItemDelegate  (parent) {}
    void SetView(IpPortNameTable *pView){m_pView=pView;}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex & index ) const;
	bool eventFilter(QObject *obj, QEvent *event);

public:
    IpPortNameTable    *m_pView;
};

class IpPortNameTable : public QTableView
{
    Q_OBJECT
public:
    IpPortNameTable(QWidget *parent = Q_NULLPTR);


public slots:
	void PressedHandle(QModelIndex index);
	void ItemChangedHandle(QStandardItem*);
	void mouseMoveEvent(QMouseEvent *event);
	void AddRowEdit();

signals:

protected:

public:

    int m_nCurrentRow;
    QModelIndex m_Index;
    QModelIndex previouseindex;
    QWidget *m_pWidget;
	IpPortItemModel *m_pModel;
	IpPortIconDelegate *m_pDelegate;
    QPixmap *m_pImageDel;
    QVector<QString> m_Stringdata;
	bool ischanged;
	//Menu *m_protocol;
	//Menu *m_direction;
};

#endif // EXTNAMETABLE_H
