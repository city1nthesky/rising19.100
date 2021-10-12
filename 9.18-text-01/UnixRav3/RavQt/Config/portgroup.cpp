#include "portgroup.h"
#include "common/pubdef.h"

#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QStringList>
#include <QFileDialog>

#include <QDebug>

//#define WHITELIST_GROUP_WIDTH   620
#define PORT_GROUP_HEIGHT  280

PortGroup::PortGroup(int flag, QWidget *parent)
    :QGroupBox(parent),m_bFocus(false)
{
    setTitle(u8"白名单");
	if(flag)
		setTitle(u8"黑名单");
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

    InitAllWidget();
	
    SetFocus(m_bFocus);
}

void PortGroup::InitAllWidget()
{
#ifdef QT_NEW_HEADER_54
    QFont font("Arial", 10, QFont::Thin, false);
#else
    QFont font("Arial", 10, QFont::Light, false);
#endif

    QGridLayout *glayout = new QGridLayout;

    QHBoxLayout *fdlayout = new QHBoxLayout;
    QLabel *pDFLabel = new QLabel(u8"ip&端口：", this);
    pDFLabel->setFont(font);
    m_ppbDirFile = new PushButton(this);
    m_ppbDirFile->loadPixmap(":/resource/plus_btn");
    fdlayout->addWidget(pDFLabel, 0, Qt::AlignRight);
    fdlayout->addWidget(m_ppbDirFile, 0, Qt::AlignRight);
    glayout->addLayout(fdlayout, 0, 0, Qt::AlignRight);

    QVBoxLayout *all_layout = new QVBoxLayout;
    QHBoxLayout *extlayout = new QHBoxLayout;
    QLabel *pExtLabel = new QLabel(u8"协议：", this);
    pExtLabel->setFont(font);
    m_pbExtName = new PushButton(this);
    m_pbExtName->loadPixmap(":/resource/plus_btn");
    extlayout->addWidget(pExtLabel, 0, Qt::AlignRight);
    extlayout->addWidget(m_pbExtName, 0, Qt::AlignRight);
    glayout->addLayout(extlayout, 0, 1, Qt::AlignRight);

    //m_pdfDirFile = new DirFileTable(this);   
    //glayout->addWidget(m_pdfDirFile, 1, 0);

    //m_IpPortName = new ExtNameTable(this);
    m_IpPortName = new IpPortNameTable(this);
    glayout->addWidget(m_IpPortName, 1, 0);
    m_ProtocolName = new ProtocolNameTable(this);
    //m_ProtocolName = new IpPortNameTable(this);
    glayout->addWidget(m_ProtocolName, 1, 1);

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
    connect(m_pbExtName, SIGNAL(clicked()), this, SLOT(AddProtocolClicked()));

}


void PortGroup::AddIpPortClicked()
{
    //m_IpPortName->setEditTriggers(QAbstractItemView::DoubleClicked);
    m_IpPortName->AddExtNameStart();
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
