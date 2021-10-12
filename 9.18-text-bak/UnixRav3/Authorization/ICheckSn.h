#ifndef __ICHECKSN_H__
#define __ICHECKSN_H__

#include "RSCFGDEF.H"

/*******************************************************************************
<���к���֤���ýӿ�>
*******************************************************************************/
class ICheckSn
{
public:
	/**********************************************************
	<���кż�麯��CheckSn>
	����ֵ˵����
		��֤��ȷ��ERR_SN_VAL_SUCCESS
		��֤����ERR_SN_VAL_INVALID��
				  ȡ���������Ϣ����GetFirstError��GetLastError
	**********************************************************/
	virtual RS_LONG		CheckSn(					//��֤���к�
						RS_CHAR *pstSn, RS_INT nSnSize, RS_DWORD dwSnKey) = 0;	
	/**********************************************************
	<���º���Ϊȡ�������к���Ϣ����>������CheckSn���ú����
	����ֵ˵����
		��ȷ�����ؾ���ֵ
		����ERR_SN_VAL_INVALID��
			  ȡ���������Ϣ����GetFirstError��GetLastError
	**********************************************************/
	virtual	RS_LONG		GetProductBigType() = 0;	//ȡ��Ʒ����
	virtual RS_LONG		GetProductType() = 0;		//ȡ��Ʒ����
	virtual RS_LONG		GetProductSubtype() = 0;	//ȡ��Ʒ������ 
	virtual RS_LONG		GetTrialType() = 0;			//ȡ��������
	virtual RS_LONG		GetBatchNo() = 0;			//ȡ����
	virtual RS_LONG		GetFlowNo() = 0;			//ȡ��ˮ��
	virtual RS_LONG		GetRegionNo() = 0;			//ȡ������
	virtual RS_LONG		GetOEMID() = 0;				//ȡOEM����ID
	virtual RS_LONG		GetHardwareType() = 0;		//ȡӲ��ƽ̨
	virtual RS_LONG		GetOSType() = 0;			//ȡOSϵͳ����
	virtual RS_LONG		GetOSVersion() = 0;			//ȡOSϵͳ�汾
	virtual RS_LONG		GetNumCenters() = 0;		//ȡϵͳ������
	virtual RS_LONG		GetNumServers() = 0;		//ȡ����������
	virtual RS_LONG		GetNumClients() = 0;		//ȡ�ͻ�������
	virtual RS_LONG		GetDecodeVer() = 0;			//ȡ���ܰ汾
	/**********************************************************
	<���º���Ϊ��������>
	����ֵ˵����
		���ش����
	**********************************************************/
	virtual RS_LONG		GetFirstError() = 0;		//ȡ��һ�������
	virtual RS_LONG		GetLastError() = 0;			//ȡ���һ�������
};

#endif
