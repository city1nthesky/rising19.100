#ifndef __iextmail_h__2007_5_16__18H04M13S
#define __iextmail_h__2007_5_16__18H04M13S

//------------------------------------------------------------------------------------
//�ʼ��ӿ�

//�������ʼ����ͣ�
//������λ���ʼ��������IREStream�У�PIDΪ PID_MAILFILE_SUBTYPE
enum MAILFILE_SUBTYPE
{
	MAILFILE_ST_TEXT_HTML = 0, 
	MAILFILE_ST_TEXT_PLAIN,
	MAILFILE_ST_ATTACHMENT,
};

//������ܱ�
//������λ��IREExtmail��SetProperty\GetProperty
enum MAILFILE_PROPERTY
{
	//��д
	MAILFILE_SUBJECTMARK,		//���⸽�Ӵ�				
	MAILFILE_HTMLMARK,			//���ı����Ӵ�			
	MAILFILE_PLAINMARK,			//�ı����Ӵ�	
	MAILFILE_APPCHASET,			//Ӧ�ó����ַ�����������д�ʼ��ı��롣�������������͸���������

	MAILFILE_SUBJECT,			//����					
	MAILFILE_SENDER, 			//������				
	MAILFILE_RECEIVER,			//������			
	MAILFILE_CC, 				//cc					
	MAILFILE_BCC,				//bcc		

	//ֻ�����̶�������
	MAILFILE_PLAINCHARSET,	 	//�����ַ���		    
	MAILFILE_HTMLCHARSET, 		//���ı������ַ��� 
	MAILFILE_ATTCOUNT, 			//������Ŀ			����
	MAILFILE_SUBITEMCOUNT,		//���ĵ�����Ŀ			

	//����
	MAILFILE_BUILDALLSIZE,		//�ʼ���д��Ĺ����С	 

};


//���� �� ����
struct REAttInfo
{
	CHAR pszAttName[MAX_PATH*2];
	DWORD dwAttSize;
};

class IREMailFile : public IUnknown
{
public:
	RE_DECLARE_IID;

	//�����ʼ������͹̶���һЩ�����Ĵ�ȡ�ӿ�
	STDMETHOD(SetProperty)(const MAILFILE_PROPERTY rpid, const PROPVARIANT *pv) PURE;
	STDMETHOD(GetProperty)(const MAILFILE_PROPERTY rpid, const PROPVARIANT **ppv) PURE;

	//����
	STDMETHOD( GetAttInfo )			(INT iIndex,	OUT REAttInfo *pInfo) PURE;
	STDMETHOD( GetAttData )			(INT iIndex,	OUT const IREStream **ppStream) PURE;
	STDMETHOD( AddAtt)				(IREStream* lpszAttName) PURE;

	//����
	STDMETHOD( GetHTML )			(OUT IREStream** ppStream) PURE;
	STDMETHOD( GetPlain	)			(OUT IREStream** ppStream) PURE;
};

RE_DEFINE_IID(IREMailFile, "{4ACF628E-8F96-4bfb-BF67-A16CEB84FC99}",
			0x4acf628e, 0x8f96, 0x4bfb, 0xbf, 0x67, 0xa1, 0x6c, 0xeb, 0x84, 0xfc, 0x99);


//------------------------------------------------------------------------------------
//�ʼ�
//treat as compound file OR mail file


//------------------------------------------------------------------------------------
//����
//treat as compound file





//------------------------------------------------------------------------------------
//��������ļ�
//treat as compound file









#endif // __iextmail_h__
