#ifndef	BASE64_H__
#define	BASE64_H__

#define IN
#define OUT

//����
long Base64Decode(IN const char* lpszDecoding, OUT unsigned char* pbytDecoded);

//����
long Base64Encode(IN unsigned char* lpbytEncoding, IN long lInputLength, OUT char* pszEncoded);

#endif	//BASE64_H__