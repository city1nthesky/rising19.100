#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <time.h>
#include "common/pubdef.h"


#include "iprulegroup.h"



IPRuleGroup::IPRuleGroup(QWidget *parent):QWidget(parent)
{
#ifdef QT_NEW_HEADER_54
    QFont font("Arial", 10, QFont::Thin, false);
#else
    QFont font("Arial", 10, QFont::Light, false);
#endif
    setFont(font);
    //setFixedSize(APP_SCREEN_WIDTH-APP_SCREEN_LEFT_WIDTH, APP_SCREEN_HEIGHT-36); //size 36 is the height of sysclose_btn.png

    m_plTitle = new QLabel(u8"IP规则", this);
    m_plTitle->adjustSize();
    m_plLine = new QLabel(this);
    m_plLine->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(57, 23, 92);");
    m_plLine->setFixedSize(535, 2);

//    m_plTime = new QLabel(u8"时间:", this);
//    m_plTime->adjustSize();
//    m_plProtectType = new QLabel(u8"防护类型:", this);
//    m_plProtectType->adjustSize();

//    QPalette pa;
//    pa.setColor(QPalette::WindowText,Qt::blue);
//    m_plExportLog = new QLabel(u8"导出日志", this);
//    m_plExportLog->adjustSize();
//    m_plExportLog->setPalette(pa);

//    m_pcTime = new QComboBox(this);
//    m_pcProtectType = new QComboBox(this);
    m_pTable = new QTableWidget(this);
    QStringList lheader;
    lheader << u8"序号" << u8"时间" << u8"原始IP" << u8"目的IP" << u8"审计结果";
    m_pTable->setColumnCount(5);
    m_pTable->setHorizontalHeaderLabels(lheader);
    m_pTable->verticalHeader()->setDefaultSectionSize(25);
    m_pTable->verticalHeader()->hide();
    m_pTable->horizontalHeader()->setFixedHeight(25);
    m_pTable->setFrameShape(QFrame::NoFrame);
    m_pTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTable->horizontalHeader()->resizeSection(0,50);
    m_pTable->horizontalHeader()->resizeSection(1,130);
    m_pTable->horizontalHeader()->resizeSection(2,130);
    m_pTable->horizontalHeader()->resizeSection(3,130);
    m_pTable->horizontalHeader()->resizeSection(4,150);
//    m_pTable->horizontalHeader()->resizeSection(5,150);
//    m_pTable->horizontalHeader()->resizeSection(6,60);
//    m_pTable->horizontalHeader()->resizeSection(7,60);
//    m_pTable->horizontalHeader()->resizeSection(8,60);

    m_pTable->setFixedSize(610, 410);
    m_pTable->setRowCount(0);

    InitControls();
}
//QHBoxLayout *hflayout = new QHBoxLayout;
//hflayout->setMargin(10);
//hflayout->setSpacing(10);
//hflayout->addWidget(m_plTitle, 0 , Qt::AlignLeft | Qt::AlignVCenter);
//hflayout->addWidget(m_plLine, 0 , Qt::AlignLeft | Qt::AlignVCenter);

//QHBoxLayout *hslayout = new QHBoxLayout;
//hslayout->setMargin(10);
//hslayout->addWidget(m_plComment, 0 , Qt::AlignLeft | Qt::AlignVCenter);
//QHBoxLayout *hdlayout = new QHBoxLayout;
//hdlayout->setMargin(10);
//hdlayout->addStretch();
//hdlayout->addWidget(m_pbtnRestoreToSource, 0, Qt::AlignRight | Qt::AlignVCenter);
//hdlayout->addWidget(m_pDeleteSelected, 0, Qt::AlignRight | Qt::AlignVCenter);

//QVBoxLayout *vlayout = new QVBoxLayout;
//vlayout->setContentsMargins(10,0,10,10);
//vlayout->addLayout(hflayout);
//vlayout->addLayout(hslayout);
//vlayout->addWidget(m_pTable, 0, Qt::AlignHCenter);
//vlayout->addLayout(hdlayout);
//setLayout(vlayout);
void IPRuleGroup::InitControls()
{
//    QStringList tlist;
//    tlist << u8"全部" << u8"今天"<< u8"最近三天" << u8"最近一周" << u8"最近一月";
//    m_pcTime->addItems(tlist);
//    m_pcTime->setCurrentIndex(1);
//    QStringList clist;
    //clist << u8"全部" << u8"文件防护" << u8"注册表防护" << u8"进程防护" << u8"系统防护";
//    m_pcProtectType->addItems(clist);

    QHBoxLayout *hflayout = new QHBoxLayout;
    hflayout->setSpacing(10);
    hflayout->setMargin(10);
    //hflayout->setContentsMargins(10,0,0,10);
    hflayout->addWidget(m_plTitle, 0 , Qt::AlignLeft | Qt::AlignVCenter);
    hflayout->addWidget(m_plLine, 0 , Qt::AlignLeft | Qt::AlignVCenter);

//    QHBoxLayout *hslayout = new QHBoxLayout;
//    hslayout->setMargin(10);
//    //hslayout->setContentsMargins(0,0,0,0);
//    hslayout->addWidget(m_plTime, 0 , Qt::AlignLeft | Qt::AlignVCenter);
//    hslayout->addWidget(m_pcTime, 0 , Qt::AlignLeft | Qt::AlignVCenter);
//    hslayout->addSpacing(5);
//    hslayout->addWidget(m_plProtectType, 0 , Qt::AlignLeft | Qt::AlignVCenter);
//    hslayout->addWidget(m_pcProtectType, 0 , Qt::AlignLeft | Qt::AlignVCenter);
//    hslayout->addStretch();
//    hslayout->addWidget(m_plExportLog, 0 , Qt::AlignRight | Qt::AlignVCenter);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->setContentsMargins(10,0,10,10);
    vlayout->addLayout(hflayout);
    //vlayout->addLayout(hslayout);
    vlayout->addWidget(m_pTable, 0, Qt::AlignHCenter);
    setLayout(vlayout);
}
//int  GetNetAccessLog(std::list<NetAccessEntry>& logs);
//            long    mTime;
//                std::string mUrl;
//                std::string mProcess;
//                typedef enum {
//                    URL,
//                    IP
//                }MatchType;
//                MatchType   mType;
//                typedef enum {
//                    REJECT = 1
//                }MatchResult;
//                MatchResult mState;
//                typedef enum {
//                    BROWSER,
//                    DOWNLOAD,
//                    PROCESS
//                }NetSource;
//                NetSource   mSource;

//序号 时间 原始IP 目的IP 审计结果
void IPRuleGroup::AddItem(NetAccessEntry &info)
{
    int rowCount = m_pTable->rowCount();
    m_pTable->insertRow(rowCount);
    //m_logs[rowCount] = info;
    char buf[128]= {0};

    QTableWidgetItem  *itemID = new QTableWidgetItem(QString("%1").arg(++m_nMaxIndex,0,10));
    m_pTable->setItem(rowCount, 0, itemID);

    struct tm *tmi = localtime((time_t*)&(info.mTime));
    QTableWidgetItem *itemTime = new QTableWidgetItem(QString("%04d-%02d-%02d %02d:%02d:%02d").arg(tmi->tm_year+1900,0,10).arg(tmi->tm_mon+1,0,10).arg(tmi->tm_mday,0,10)
                                                      .arg(tmi->tm_hour,0,10).arg(tmi->tm_min,0,10).arg(tmi->tm_sec,0,10));
    m_pTable->setItem(rowCount, 1, itemTime);

    QTableWidgetItem *itemSIP = new QTableWidgetItem(QString(u8""));
    m_pTable->setItem(rowCount, 2, itemSIP);

    QTableWidgetItem *itemDIP = new QTableWidgetItem(info.mUrl.c_str());
    m_pTable->setItem(rowCount, 3, itemDIP);

    QTableWidgetItem  *itemResult = new QTableWidgetItem(u8"拦截");
    m_pTable->setItem(rowCount, 4, itemResult);
}

void IPRuleGroup::ResetTable()
{
    m_pTable->clearContents();
    m_pTable->setRowCount(0);
   // m_logs.clear();
    m_nMaxIndex = 0;
    m_bInitedScreenData = false;
}

void IPRuleGroup::InitData()
{
    if(m_bInitedScreenData){
        ResetTable();
    }
    m_bInitedScreenData = true;

    std::list<NetAccessEntry> logs;
    int count = m_pMain->GetNetAccessLog(logs);
    if(count > 0){
        list<NetAccessEntry>::iterator it = logs.begin();
        while(it != logs.end()){
            //printf("IPRuleGroup::InitData before AddItem\n");
            NetAccessEntry log = *it;
            if(log.mType == NetAccessEntry::IP)
                AddItem(log);
            it++;
        }
    }
}

void IPRuleGroup::resizeEvent(QResizeEvent *event)
{
    m_plLine->setFixedWidth(event->size().width() - 100);
    m_pTable->setFixedSize(event->size().width()-50, event->size().height()-100);
}

