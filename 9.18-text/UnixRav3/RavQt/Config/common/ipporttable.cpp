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

#include "ipporttable.h"
#include "common/pubdef.h"

#define COLUMN_NUMBER 2
#define ROW_NUMBER 6
#define HORIZONTAL_DEVIATION 400
#define VERTICAL_DEVIATION 400


//load close icon
IpPortItemModel::IpPortItemModel(QObject * parent) 
    :QStandardItemModel(parent)
{
    QPixmap oripixmap = QPixmap(":/resource/delete_btn");
    m_pImageDel = new QPixmap;
    *m_pImageDel = oripixmap.copy(0,0,oripixmap.width()/3,oripixmap.height());
}

//init table
IpPortNameTable::IpPortNameTable(QWidget *parent)
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
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSelectionBehavior(QAbstractItemView::SelectItems);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setMouseTracking(true);


    QPixmap oripixmap = QPixmap(":/resource/delete_btn");
    m_pImageDel = new QPixmap;
    *m_pImageDel = oripixmap.copy(0,0,oripixmap.width()/3,oripixmap.height());

    m_pModel= new IpPortItemModel;
    m_pModel->setColumnCount(COLUMN_NUMBER);
    m_pModel->setRowCount(ROW_NUMBER);
    m_pModel->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("ip"));
    m_pModel->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("操作"));
	

    m_pDelegate = new IpPortIconDelegate;
    m_pDelegate->SetView(this);
	m_pModel->installEventFilter(m_pDelegate);

    setModel(m_pModel);
	setItemDelegate(m_pDelegate);

    setColumnWidth(0, 500);
    setColumnWidth(1, 40);

    m_nCurrentRow = -1;
	previouseindex = m_pModel->index(0,0);
	ischanged = false;

	connect(this, SIGNAL(pressed(QModelIndex)), this, SLOT(PressedHandle(QModelIndex)));
	connect(m_pModel, SIGNAL(itemChanged(QStandardItem*)), this ,SLOT(ItemChangedHandle(QStandardItem*)));
}


//disable tab key
bool IpPortIconDelegate::eventFilter(QObject *obj, QEvent *event) {
	if (event->type() == QEvent::KeyPress) {
		QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
		//qDebug() << "Ate key press" << keyEvent->key();
		switch(keyEvent->key())
		{
			case Qt::Key::Key_Tab:
			qDebug() << "tab key press" << keyEvent->key();
			return true;
				break;

			default :
			return QItemDelegate::eventFilter(obj, event);
				break;
		}
	}
	// pass the event on to the parent class
	return QItemDelegate::eventFilter(obj, event);
}

//paint close key
void IpPortIconDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex & index ) const
{
    int cur_column = index.column();
		if(cur_column == COLUMN_NUMBER - 1 && index.row() <= m_pView->m_nCurrentRow)
		{
                QItemDelegate::paint(painter, option, index);

                QPixmap imgDel = *(m_pView->m_pImageDel);
                int x = option.rect.x() + option.rect.width()/2 - imgDel.width()/2;
                int y = option.rect.y() + option.rect.height()/2 - imgDel.height()/2;

                painter->drawPixmap(x,y,imgDel);
                return;
		}
    QItemDelegate::paint(painter, option, index);
}

void IpPortNameTable::ItemChangedHandle(QStandardItem *item) 
{
	QString str = item->text();
	int row = item->row();
	int size = m_Stringdata.size()-1;
	//qDebug() << item->text() << item->row() << item->column();
	qDebug() << "ItemChanged sad";

	if(row > size && str == "")
	{
		return;
	}

	//insert ending
	if(row > size && str != "")
	{
		m_Stringdata.push_back(str);
		ischanged = false;
	}

	//change  middle
	if(row < size)
	{
		m_Stringdata.erase(m_Stringdata.begin() + row);
		m_Stringdata.insert(m_Stringdata.begin() + row, str);
		ischanged = false;
	}

	//change ending
	if(row == size)
	{
		m_Stringdata.erase(m_Stringdata.begin() + row);
		m_Stringdata.push_back(str);
		ischanged = false;
	}

	for (int i = 0; i < m_Stringdata.size(); i++) {
		qDebug() << m_Stringdata[i];
	}
}

//add a new row with editable
void IpPortNameTable::AddRowEdit()
{
	m_nCurrentRow++;
	if(m_nCurrentRow > ROW_NUMBER-1)
		m_pModel->insertRow(m_nCurrentRow);
	//closePersistentEditor(previouseindex);
	//openPersistentEditor(m_pModel->index(m_nCurrentRow,0));
	//previouseindex = m_pModel->index(m_nCurrentRow,0);
	ischanged = true;
	update(m_pModel->index(m_nCurrentRow, COLUMN_NUMBER-1));
}

void IpPortNameTable::mouseMoveEvent(QMouseEvent *event)
{
	//if(event->pos().x() < 5 || event->pos().y() >140 || event->pos().x() > 530 || event->pos().y() <5)
	//{
	//qDebug()<< "zobiao" << event->pos();
	//}

}

//when mouse is pressed, we need to do something
void IpPortNameTable::PressedHandle(QModelIndex index)
{
	m_Index = index;
	if(index.row() <= m_nCurrentRow)
	{
		switch(index.column())
		{
			case COLUMN_NUMBER-1:
				closePersistentEditor(previouseindex);
				m_pModel->removeRow(index.row());
				if( index.row() <= m_Stringdata.size() -1)
					m_Stringdata.erase(m_Stringdata.begin() + index.row());
				//ItemChangedHandle(m_pModel->item(index.row(),index.column())) ;
				if(m_nCurrentRow < ROW_NUMBER)
					m_pModel->insertRow(ROW_NUMBER - 1);

				m_nCurrentRow--;
				ischanged = false;
				return;
				break;

			default :
				break;
		}
		
		//openPersistentEditor(index);
		//if(index != previouseindex)
		//{
		//	closePersistentEditor(previouseindex);
		//	previouseindex = index;
		//}
		
		closePersistentEditor(previouseindex);
		openPersistentEditor(index);

	}
	else
	{
		qDebug() << "no way";
		closePersistentEditor(previouseindex);
	}
		previouseindex = index;
		//qDebug() << "I am clicked";
}
