#include "portgroup.h"
#include "common/pubdef.h"

#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QStringList>
#include <QFileDialog>
#include <QModelIndex>

#include <QDebug>

//#define WHITELIST_GROUP_WIDTH   620
#define PORT_GROUP_HEIGHT  280

PortGroup::PortGroup(int flag, QWidget *parent)
    :QGroupBox(parent),m_bFocus(false)
{
	switch(flag)
	{
		case 0:
			setTitle(u8"白名单");
			break;

		case 1:
			setTitle(u8"黑名单");
			break;

		case 2:
			setTitle(u8"端口");
			break;

		default :
			setTitle(u8"白名单");
			break;
	}


    QFont font;
#ifdef QT_NEW_HEADER_54
    font.setWeight(QFont::Thin);
#else
    font.setWeight(QFont::Light);
#endif
    font.setPointSize(10);
    setFont(font);

    setFixedWidth(APP_SCREEN_WIDTH-APP_SCREEN_LEFT_WIDTH-30);
    setMaximumHeight(PORT_GROUP_HEIGHT);

    setFlat(true);

    setStyleSheet("QGroupBox {\
                  font-size:13px; \
                  border: 2px solid #7B599F;\
                  margin-top: 1ex; \
                  }\
                  QGroupBox::title {\
                  top: 1px;\
                  left: 20px;\
                  subcontrol-origin: margin;\
                  subcontrol-position: top left;}");

	switch(flag)
	{
		case 0:
			InitWhiteListWidget();
			break;

		case 1:
			InitBlackListWidget();
			break;

		case 2:
			InitPortWidget();
			break;

		default :
			InitWhiteListWidget();
			break;
	}

    SetFocus(m_bFocus);
}

void PortGroup::InitPortWidget()
{

#ifdef QT_NEW_HEADER_54
    QFont font("Arial", 10, QFont::Thin, false);
#else
    QFont font("Arial", 10, QFont::Light, false);
#endif

    QGridLayout *glayout = new QGridLayout;

    QHBoxLayout *fdlayout = new QHBoxLayout;
    QLabel *pDFLabel = new QLabel(u8"端口&协议&方向：", this);
    pDFLabel->setFont(font);
    m_ppbDirFile = new PushButton(this);
    m_ppbDirFile->loadPixmap(":/resource/plus_btn");
    fdlayout->addWidget(pDFLabel, 0, Qt::AlignRight);
    fdlayout->addWidget(m_ppbDirFile, 0, Qt::AlignRight);
    glayout->addLayout(fdlayout, 0, 0, Qt::AlignRight);

    QVBoxLayout *all_layout = new QVBoxLayout;
    //QHBoxLayout *extlayout = new QHBoxLayout;
    //QLabel *pExtLabel = new QLabel(u8"协议：", this);
    //pExtLabel->setFont(font);
    //m_pbExtName = new PushButton(this);
    //m_pbExtName->loadPixmap(":/resource/plus_btn");
    //extlayout->addWidget(pExtLabel, 0, Qt::AlignRight);
    //extlayout->addWidget(m_pbExtName, 0, Qt::AlignRight);
    //glayout->addLayout(extlayout, 0, 1, Qt::AlignRight);


    m_PortName = new PortNameTable(this);
    glayout->addWidget(m_PortName, 1, 0);
    //m_ProtocolName = new ProtocolNameTable(this);
    //m_ProtocolName = new IpPortNameTable(this);
    //glayout->addWidget(m_ProtocolName, 1, 1);

    all_layout->addLayout(glayout);

    QLabel *pinfo = new QLabel;

    QHBoxLayout * pinfolayout = new QHBoxLayout;
    pinfolayout->addWidget(pinfo);
    pinfolayout->setAlignment(Qt::AlignLeft);

    all_layout->addLayout(pinfolayout);

    setLayout(all_layout);

    connect(m_ppbDirFile, SIGNAL(clicked()), this, SLOT(AddPortClicked()));
    connect(m_PortName, SIGNAL(clicked(QModelIndex)), m_PortName, SLOT(PressedHandle(QModelIndex)));
}

void PortGroup::InitBlackListWidget()
{

#ifdef QT_NEW_HEADER_54
    QFont font("Arial", 10, QFont::Thin, false);
#else
    QFont font("Arial", 10, QFont::Light, false);
#endif

    QGridLayout *glayout = new QGridLayout;

    QHBoxLayout *fdlayout = new QHBoxLayout;
    QLabel *pDFLabel = new QLabel(u8"ip/ip段：", this);
    pDFLabel->setFont(font);
    m_ppbDirFile = new PushButton(this);
    m_ppbDirFile->loadPixmap(":/resource/plus_btn");
    fdlayout->addWidget(pDFLabel, 0, Qt::AlignRight);
    fdlayout->addWidget(m_ppbDirFile, 0, Qt::AlignRight);
    glayout->addLayout(fdlayout, 0, 0, Qt::AlignRight);

    QVBoxLayout *all_layout = new QVBoxLayout;
    //QHBoxLayout *extlayout = new QHBoxLayout;
    //QLabel *pExtLabel = new QLabel(u8"协议：", this);
    //pExtLabel->setFont(font);
    //m_pbExtName = new PushButton(this);
    //m_pbExtName->loadPixmap(":/resource/plus_btn");
    //extlayout->addWidget(pExtLabel, 0, Qt::AlignRight);
    //extlayout->addWidget(m_pbExtName, 0, Qt::AlignRight);
    //glayout->addLayout(extlayout, 0, 1, Qt::AlignRight);


    m_IpPortName = new IpPortNameTable(this);
    glayout->addWidget(m_IpPortName, 1, 0);
    //m_ProtocolName = new ProtocolNameTable(this);
    //m_ProtocolName = new IpPortNameTable(this);
    //glayout->addWidget(m_ProtocolName, 1, 1);

    all_layout->addLayout(glayout);

    QLabel *pinfo = new QLabel;

    QHBoxLayout * pinfolayout = new QHBoxLayout;
    pinfolayout->addWidget(pinfo);
    pinfolayout->setAlignment(Qt::AlignLeft);

    all_layout->addLayout(pinfolayout);

    setLayout(all_layout);

    connect(m_ppbDirFile, SIGNAL(clicked()), this, SLOT(AddIpPortClicked()));
    //connect(m_IpPortName, SIGNAL(clicked(QModelIndex)), m_IpPortName, SLOT(OpenEdit(QModelIndex)));
    connect(m_IpPortName, SIGNAL(clicked(QModelIndex)), m_IpPortName, SLOT(PressedHandle(QModelIndex)));
    //connect(m_IpPortName, SIGNAL(pressed(QModelIndex)), this, SLOT(OpenEdit(QModelIndex)));
}

void PortGroup::InitWhiteListWidget()
{
#ifdef QT_NEW_HEADER_54
    QFont font("Arial", 10, QFont::Thin, false);
#else
    QFont font("Arial", 10, QFont::Light, false);
#endif

    QGridLayout *glayout = new QGridLayout;

    QHBoxLayout *fdlayout = new QHBoxLayout;
    QLabel *pDFLabel = new QLabel(u8"ip/ip段：", this);
    pDFLabel->setFont(font);
    m_ppbDirFile = new PushButton(this);
    m_ppbDirFile->loadPixmap(":/resource/plus_btn");
    fdlayout->addWidget(pDFLabel, 0, Qt::AlignRight);
    fdlayout->addWidget(m_ppbDirFile, 0, Qt::AlignRight);
    glayout->addLayout(fdlayout, 0, 0, Qt::AlignRight);

    QVBoxLayout *all_layout = new QVBoxLayout;
    //QHBoxLayout *extlayout = new QHBoxLayout;
    //QLabel *pExtLabel = new QLabel(u8"协议：", this);
    //pExtLabel->setFont(font);
    //m_pbExtName = new PushButton(this);
    //m_pbExtName->loadPixmap(":/resource/plus_btn");
    //extlayout->addWidget(pExtLabel, 0, Qt::AlignRight);
    //extlayout->addWidget(m_pbExtName, 0, Qt::AlignRight);
    //glayout->addLayout(extlayout, 0, 1, Qt::AlignRight);


    m_IpPortName = new IpPortNameTable(this);
    glayout->addWidget(m_IpPortName, 1, 0);
    //m_ProtocolName = new ProtocolNameTable(this);
    //m_ProtocolName = new IpPortNameTable(this);
    //glayout->addWidget(m_ProtocolName, 1, 1);

    all_layout->addLayout(glayout);

    QLabel *pinfo = new QLabel;
    QPixmap *pxinfo = new QPixmap(":/resource/whitelist_info");
    pinfo->setPixmap(*pxinfo);
    pinfo->setFixedSize(pxinfo->width(), pxinfo->height());
    QHBoxLayout * pinfolayout = new QHBoxLayout;
    pinfolayout->addWidget(pinfo);
    pinfolayout->setAlignment(Qt::AlignLeft);

    all_layout->addLayout(pinfolayout);

    setLayout(all_layout);

    connect(m_ppbDirFile, SIGNAL(clicked()), this, SLOT(AddIpPortClicked()));
    //connect(m_IpPortName, SIGNAL(clicked(QModelIndex)), m_IpPortName, SLOT(OpenEdit(QModelIndex)));
    connect(m_IpPortName, SIGNAL(clicked(QModelIndex)), m_IpPortName, SLOT(PressedHandle(QModelIndex)));
    //connect(m_IpPortName, SIGNAL(pressed(QModelIndex)), this, SLOT(OpenEdit(QModelIndex)));

}

void PortGroup::AddPortClicked()
{
    //m_IpPortName->setEditTriggers(QAbstractItemView::DoubleClicked);
    //m_IpPortName->AddExtNameStart();
	if(!m_PortName->ischanged)
		m_PortName->AddRowEdit();
    //for(int i=0; i)
}

void PortGroup::AddIpPortClicked()
{
    //m_IpPortName->setEditTriggers(QAbstractItemView::DoubleClicked);
    //m_IpPortName->AddExtNameStart();
	if(!m_IpPortName->ischanged)
		m_IpPortName->AddRowEdit();
    //for(int i=0; i)
}

void PortGroup::AddProtocolClicked()
{
    //m_IpPortName->setEditTriggers(QAbstractItemView::DoubleClicked);
    m_ProtocolName->AddExtNameStart();
    //for(int i=0; i)
}

void PortGroup::SetFocus(bool bFocus)
{
    m_bFocus = bFocus;
    if(m_bFocus){
        setStyleSheet("QGroupBox {\
              font-size:13px; \
              border: 2px solid #7B599F;\
              margin-top: 1ex; \
              }\
              QGroupBox::title {\
              top: 1px;\
              left: 20px;\
              subcontrol-origin: margin;\
              subcontrol-position: top left;}");

    }else{
        setStyleSheet("QGroupBox {\
              font-size:13px; \
              border: 2px solid #EFEBE7;\
              margin-top: 1ex; \
              }\
              QGroupBox::title {\
              top: 1px;\
              left: 20px;\
              subcontrol-origin: margin;\
              subcontrol-position: top left;}");
    }
    update();
}
