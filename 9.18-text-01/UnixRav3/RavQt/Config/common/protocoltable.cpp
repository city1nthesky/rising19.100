#include <QHeaderView>
#include <QScrollBar>
#include <QLabel>
#include <QVariant>
#include <QColor>
#include <QModelIndex>
#include <QTableWidgetItem>
#include <QToolTip>
#include <QEvent>
#include <QDebug>

#include "protocoltable.h"
#include "common/pubdef.h"

ProtocolItemModel::ProtocolItemModel(QObject * parent)
    :QStandardItemModel(parent)
{
    QPixmap oripixmap = QPixmap(":/resource/delete_btn");
    m_pImageDel = new QPixmap;
    *m_pImageDel = oripixmap.copy(0,0,oripixmap.width()/3,oripixmap.height());
}

QVariant ProtocolItemModel::data(const QModelIndex & index, int role) const
{
    if (!index.isValid())
            return QVariant();

    int column=index.column();
    int rows = m_pItems->size();
    int cur_row = index.row();

    //qDebug("ProtocolItemModel::data() column=%d row=%d", column, cur_row);
    if(role == Qt::BackgroundRole  && cur_row == m_nHoverRow)
    {
        return QColor(247,243,251);
    }
    if(role == Qt::TextAlignmentRole && column == 0 && cur_row < rows){
        return QVariant(Qt::AlignVCenter|Qt::AlignHCenter);
    }
    if(role==Qt::DisplayRole && cur_row < rows){
        switch(column){
        case 0:{
//                ExtDisplayItem* pdata = (*m_pItems)[cur_row];
//                return pdata->m_sName;
                break;
            }
        case 1:{      //2021.9.26  by zhangdong
    //qDebug("I am second");
    //qDebug() << "index" << index << "role" << role;
                return *m_pImageDel;
                break;
            }
        default:
            break;
        }
    }
    return QStandardItemModel::data(index,role);
}

void ProtocolDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex & index ) const
{
    int cur_column = index.column();
    switch(cur_column){
    case 0:{
//            QString sname = index.model()->data(index, Qt::DisplayRole).toString();
//            QStyleOptionViewItem myOption = option;
//            myOption.displayAlignment = Qt::AlignLeft| Qt::AlignVCenter;
//            drawDisplay(painter, myOption, myOption.rect, sname);
        }
        break;
    case 1:{     //2021.9.26   by zhangdong
            if(index.data().canConvert<QPixmap>()){
    //qDebug("I am first");
                QItemDelegate::paint(painter, option, index);

                QPixmap imgDel = qvariant_cast<QPixmap>(index.data());
                int x = option.rect.x() + option.rect.width()/2 - imgDel.width()/2;
                int y = option.rect.y() + option.rect.height()/2 - imgDel.height()/2;

                painter->drawPixmap(x,y,imgDel);
                return;
            }
        }
        break;
    default:
        break;
    }
    QItemDelegate::paint(painter, option, index);
}


ProtocolNameTable::ProtocolNameTable(QWidget *parent)
    :QTableView(parent)
{
    verticalHeader()->setVisible(false);
    verticalHeader()->setDefaultSectionSize(24);
    horizontalScrollBar()->setVisible(false);

#ifdef QT_NEW_HEADER_54
    QFont font("Arial", 10, QFont::Thin, false);
#else
    QFont font("Arial", 10, QFont::Light, false);
#endif
    setFont(font);
    setStyleSheet("QTableView {\
                  selection-background-color: rgb(236,229,243);\
                  selection-color: black;\
              }");
    setFrameShape(QFrame::NoFrame);
    setSortingEnabled(false);
    setEditTriggers(QAbstractItemView::DoubleClicked);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setMouseTracking(true);

    m_pModel= new ProtocolItemModel;
    m_pModel->setColumnCount(2);
    m_pModel->setRowCount(6);
    m_pModel->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("protocol"));
    m_pModel->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("操作"));
    m_pModel->SetData(&m_AllItems);

    m_pDelegate = new ProtocolDelegate;
    m_pDelegate->SetView(this);

    setModel(m_pModel);
    setItemDelegate(m_pDelegate);

    setColumnWidth(0, 240);
    setColumnWidth(1, 40);

    m_nCurrentRow = -1;


//    QString *pitem = new QString("test dir and child type");
//    m_AllItems.push_back(pitem);
//    QString *pitem1 = new QString("test xxxx");
//    m_AllItems.push_back(pitem1);

//    m_pModel->setItem(0, 0, new QStandardItem("test dir and child type"));
//    m_pModel->setItem(1, 0, new QStandardItem("test xxxx"));

}

void ProtocolNameTable::AddExtNameStart()
{
    qDebug("I come start");
    int row_count = m_pModel->rowCount();
    int rows = m_AllItems.size();
    //int rows = m_AllItems.size()/3;    //2021.9.26 by zhangdong
    //qDebug("ProtocolNameTable::AddExtName event row_count=%d recores=%d", row_count, rows);
    if((row_count-1) == rows ){
        m_pModel->setRowCount(row_count + 1);
    }

    //QModelIndex index = m_pModel->index(rows, 0);
    QModelIndex index = m_pModel->index(rows, 0);
	//m_nCurrentCloumn = (m_nCurrentCloumn + 1) % 3;    //2021.9.26 by zhangdong
    if(index.isValid()){
        openPersistentEditor(index);
        setFocus();
        QWidget* editWidget = indexWidget(index);
        if(editWidget != NULL){
            m_pWidget = editWidget;
            editWidget->setFocus();
            m_Index = index;
            QString *pitem = new QString("");
            m_AllItems.push_back(pitem);
            connect(editWidget,SIGNAL(editingFinished()), this, SLOT(AddExtNameEnd()));
        }
    }
}

QString ProtocolNameTable::ExtName_sub(QString text)
{
    if(text.size() == 0)
        return text;

    if(text[0] == QChar('.'))
    {
        return QString("*") + text;
    }

    return text;
}

void ProtocolNameTable::AddExtNameEnd()
{
    closePersistentEditor(m_Index);
    qDebug() << "I come end!";
    int row = m_Index.row();
    qDebug() << "ProtocolNameTable::AddExtNameEnd row=" << m_Index.row() ;
    QString text = m_pModel->itemFromIndex(m_Index)->text();

    text = ExtName_sub(text);

    QVector<QString*>::iterator it = m_AllItems.begin();
    int i = 0;
    while(it != m_AllItems.end()){
        if(i++ == row){
            QString *pdata = *it;
            if(text.isEmpty()){
                delete pdata;
                pdata = NULL;
                it = m_AllItems.erase(it);
                continue;
                //this->repaint();
            }else{
                *pdata = text;
            }
        }
        it++;
    }

    QVector<QString*>::iterator it1 = m_AllItems.begin();
    int j = 0;
    while(it1 != m_AllItems.end()){
        QString *pdata = *it1;
        qDebug() << j++ << "  " << *pdata ;
        qDebug() << "look at me  ";
        it1++;
    }

}

int ProtocolNameTable::AddItem(QString sName)
{
    int row_count = m_pModel->rowCount();
    int rows = m_AllItems.size();
    //qDebug("ProtocolNameTable::AddItem row_count=%d rows=%d", row_count, rows);
    //qDebug("I get in AddItem");
    if((row_count-1) == rows ){
        m_pModel->setRowCount(row_count + 1);
    }
    QString *pitem = new QString(sName);
    m_AllItems.push_back(pitem);
    m_pModel->setItem(rows, 0, new QStandardItem(sName));
    return 0;
}

void ProtocolNameTable::DelItem(int row)
{
    int i = 0;
    int row_count = m_pModel->rowCount();
    qDebug("I come DelItem");
    QVector<QString*>::iterator it = m_AllItems.begin();
    while(it != m_AllItems.end()){
        if(i++ == row){
            //qDebug("ProtocolNameTable::DelItem i=%d  row=%d row_count=%d", i, row, row_count);
            QString *pitem = *it;
            delete pitem;
            pitem = NULL;
            m_AllItems.erase(it);
            m_pModel->removeRow(row);
            if(row_count == 6)
                m_pModel->setRowCount(6);

            QVector<QString*>::iterator it1 = m_AllItems.begin();
            int j = 0;
            while(it1 != m_AllItems.end()){
                QString *sdata = *it1;
                qDebug() << j++ << "  " << *sdata ;
                it1++;
            }
            return;
        }
        it++;
    }
}

void ProtocolNameTable::ClearAllItem()
{
    int i = 0;
    //int row_count = m_pModel->rowCount();
    QVector<QString*>::iterator it = m_AllItems.begin();
    while(it != m_AllItems.end()){
        QString *pitem = *it;
        delete pitem;
        pitem = NULL;
        m_pModel->removeRow(i++);
        it = m_AllItems.erase(it);
    }
}

void ProtocolNameTable::UpdateRow(int row)
{
    if (row == m_nCurrentRow)
        return;

    m_pModel->SetHoverRow(row);
    //qDebug("ProtocolNameTable::UpdateRow row=%d  m_nCurrentRow=%d", row, m_nCurrentRow);
    for (int i = 1; i >= 0; i--)
    {
        update(model()->index(m_nCurrentRow, i));
        update(model()->index(row, i));
    }
    QStandardItem *item = m_pModel->item(row, 0);
    if (item) {
        item->setForeground(QBrush(QColor(0, 0, 0)));
        m_nCurrentRow = row;
    }
}


int ProtocolNameTable::GetAllItem(vector<string> * vData)
{
    int ncount = 0;
    QVector<QString*>::iterator it = m_AllItems.begin();
    while(it != m_AllItems.end()){
        QString *pitem = *it;
        vData->push_back(pitem->toStdString());
        ncount++;
        it++;
    }
    return ncount;
}


bool ProtocolNameTable::event(QEvent *pEvent)
{
    if(pEvent->type() == QEvent::ToolTip){
        QPoint pt =  mapFromGlobal(QCursor::pos());
        int rows = m_AllItems.size();
        int row = this->rowAt(pt.y());
        int col = this->columnAt(pt.x());
        //qDebug("ProtocolNameTable::event ToolTip col=%d row=%d rows=%d", col, row, rows);
        if(col == 0 && row <= rows){
            ShowToolTip(row);
        }
    }
    return QTableView::event(pEvent);
}

void ProtocolNameTable::ShowToolTip(int )
{
//    ExtDisplayItem *pdt = m_AllItems[row-1];
//    QString stip = u8"类型：";
//    stip += APP_MENU_WHITELIST_TYPE[pdt->m_nType];
//    stip += "\n";
//    stip += u8"路径：";
//    stip += pdt->m_sName;

//    QToolTip::showText(QCursor::pos(), stip);
}

void ProtocolNameTable::mousePressEvent(QMouseEvent *event)
{
    int rows = m_AllItems.size();
    int row = this->rowAt(event->y());
    if(row >= rows){
        qDebug("I do nothing");
        return;
    }else{
        qDebug("I am closed?");
        setCurrentIndex(QModelIndex());
        QTableView::mousePressEvent(event);
        QModelIndex index = currentIndex();
        if(event->button() == Qt::LeftButton){
        qDebug("I come from mousePressEvent");
            CellClicked(index);
        }
        //qDebug("ProtocolNameTable::mousePressEvent col:%d row:%d", index.column(), index.row());
    }
}

void ProtocolNameTable::mouseMoveEvent(QMouseEvent *event)
{
    int rows = m_AllItems.size();
    int column=this->columnAt(event->x());
    int row=this->rowAt(event->y());

    if(column == 1 && row < rows){
        this->setCursor(Qt::PointingHandCursor);
    }else{
        this->setCursor(Qt::ArrowCursor);
    }
    if(row < rows)
        UpdateRow(row);
}

void ProtocolNameTable::leaveEvent (QEvent * )
{
    m_pModel->SetHoverRow(-1);
    int column_count= model()->columnCount();
    for (int i = column_count- 1; i >= 0; i--)
    {
        update(model()->index(m_nCurrentRow, i));
    }
    m_nCurrentRow = -1;
}


void ProtocolNameTable::CellClicked(const QModelIndex &index)
{
    //qDebug("ProtocolNameTable::cellClicked %d %d", index.column(), index.row());
    qDebug("I get in cellClicked");
    int col = index.column();
    int row = index.row();

    if(col != 1 || row < 0)   //2021.9.26 by zhangdong
        return;
    DelItem(row);
}
