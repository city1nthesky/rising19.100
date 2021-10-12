#ifndef __RX_INTERNAL_FUNCTIONAL__
#define __RX_INTERNAL_FUNCTIONAL__

#include "recfmt.h"
#include "2010/ivm.h"
#include "tc/tcpe.h"

namespace dbg
{
	class ITCEPoorDebugger : public IUnknown
	{
	public:

		enum RecEvent
		{
			OnRecSet,			// ������ʼ��������¼
			OnRecStep,			// �����ĵ����¼�
			OnRecOver,			// ��¼������
			OnRecBadOp,			// �����˲���ʶ��OPCODE
			OnRecError,			// ������ָ�����ָ�������
			OnRecBreak,			// ������ָ��������ָ��ִ�У�
			OnRecLimitSteps,	// �ܵ������Ʋ���
		};

	public:

		STDMETHOD_( SIZE_T, GetCustomRecordNum)() PURE;

		STDMETHOD_(tcr::LPTCREC, GetCustomRecord)( SIZE_T uIndex ) PURE;

		STDMETHOD(OnRecEvent)( IUnknown* lpImpl, RecEvent uIdEvent, LPEMUX lpEmuCtx, BOOL& bContinueDebug ) PURE;

		RE_DECLARE_IID;
	};

	// {BA5C487E-06E0-4799-A912-08D4A41C487F}
	RE_DEFINE_IID( ITCEPoorDebugger, "{BA5C487E-06E0-4799-A912-08D4A41C487F}",
		0xba5c487e, 0x6e0, 0x4799, 0xa9, 0x12, 0x8, 0xd4, 0xa4, 0x1c, 0x48, 0x7f);

	// {7D5D250C-069B-4ECF-9B71-C779547F7BEE}
	DEFINE_GUID(PID_ROT_TCE_Poor_Debugger, 0x7d5d250c, 0x69b, 0x4ecf, 0x9b, 0x71, 0xc7, 0x79, 0x54, 0x7f, 0x7b, 0xee);


};

#endif