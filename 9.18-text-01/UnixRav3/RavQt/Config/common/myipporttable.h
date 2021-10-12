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

    void SetData(QVector<QString*> *pData){
        m_pItems = pData;
    }

    void SetHoverRow(int row){
        m_nHoverRow = row;
    }

    QVariant data(const QModelIndex & index, int role=Qt::DisplayRole) const;


public:
    int m_nHoverRow;

    QVector<QString*> *m_pItems;
    QPixmap * m_pImageDel;
};

class IpPortIconDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    IpPortIconDelegate(QObject *parent = NULL): QItemDelegate  (parent) { }
    void SetView(IpPortNameTable *pView){m_pView=pView;}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex & index ) const;
public:
    IpPortNameTable    *m_pView;
};


class IpPortNameTable : public QTableView
{
    Q_OBJECT
public:
    IpPortNameTable(QWidget *parent = Q_NULLPTR);

    void AddExtNameStart();

    int AddItem(QString sName);
    void DelItem(int row);
    void ClearAllItem();

    void UpdateRow(int row);
    int GetAllItem(vector<string> * vData);

public slots:
    void AddExtNameEnd();
    void ShowToolTip(int row);
    void mytext();

protected:
    bool event(QEvent *pEvent);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void leaveEvent (QEvent * event);
//    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);


    void CellClicked(const QModelIndex &index);

    QString ExtName_sub(QString text);


public:
    QVector<QString*>  m_AllItems;

    IpPortItemModel *m_pModel;
    IpPortIconDelegate    *m_pDelegate;

    int m_nCurrentRow;
    int m_nCurrentCloumn;
    QModelIndex m_Index;
    QWidget *m_pWidget;
};

#endif // EXTNAMETABLE_H
