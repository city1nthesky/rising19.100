#ifndef __R4_EXPORTED_CLASS__
#define __R4_EXPORTED_CLASS__

#if 0
#if (CPP_COMPILER==CC_MSVC)

	#pragma message("include: rxclsid.h")

#elif (CPP_COMPILER==CC_GCC)

	#warning ("include: rxclsid.h")

#endif
#endif  
 
struct STRPTR
{
	LPCSTR	ClassName;
	bool operator < ( const STRPTR& r ) const
	{
		return strcmp( ClassName?ClassName:"", r.ClassName?r.ClassName:"" )<0;
	}
	bool operator == ( const STRPTR& r ) const
	{
		return strcmp( ClassName?ClassName:"", r.ClassName?r.ClassName:"" )==0;
	}
	bool operator == ( LPCSTR lp ) const
	{
		return strcmp( ClassName?ClassName:"", lp?lp:"" )==0;
	}
	bool operator != ( LPCSTR lp ) const
	{
		return strcmp( ClassName?ClassName:"", lp?lp:"" )!=0;
	}
	bool operator != ( const STRPTR& r ) const
	{
		return strcmp( ClassName?ClassName:"", r.ClassName?r.ClassName:"" )!=0;
	}
	STRPTR() : ClassName(""){}
	STRPTR( LPCSTR cap ) : ClassName(cap) {};
	STRPTR& operator = ( LPCSTR lp )
	{
		ClassName = lp;
		return *this;
	}
	STRPTR& operator = ( const STRPTR& ro )
	{
		ClassName = ro.ClassName;
		return *this;
	}
	operator LPCSTR () const {
		return ClassName;
	}
};

static STRPTR							TNULL;
#define TCLSID_NULL						TNULL
#define CIDOF(X)						CLSID_##X
#define TCLSIDREF						STRPTR
#define TCLSID							STRPTR

#define	PROGID(progid)					#progid
#define	PROGID2(mod,cls)				#mod"."#cls

#define DEF_CLASSID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)	static LPCSTR CIDOF(name)	= (LPCSTR)#name;

// {3AD64A7B-5F73-4123-8B08-5ABA8AD453D7}
DEF_CLASSID(FrontEnd,					0x3ad64a7b, 0x5f73, 0x4123, 0x8b, 0x8, 0x5a, 0xba, 0x8a, 0xd4, 0x53, 0xd7);

// {25C2C344-E06B-4dbd-B0A7-AC15E4BD1FD0}
DEF_CLASSID(MssLibFile,					0x25c2c344, 0xe06b, 0x4dbd, 0xb0, 0xa7, 0xac, 0x15, 0xe4, 0xbd, 0x1f, 0xd0);
// {F3492083-DDB5-4338-B400-F2D03612E67A}
DEF_CLASSID(MssLibPatcher,				0xf3492083, 0xddb5, 0x4338, 0xb4, 0x0, 0xf2, 0xd0, 0x36, 0x12, 0xe6, 0x7a);
// {F36B89BA-F14A-42C5-A421-B518AAD62784}
DEF_CLASSID(MssLibUpdater,				0xf36b89ba, 0xf14a, 0x42c5, 0xa4, 0x21, 0xb5, 0x18, 0xaa, 0xd6, 0x27, 0x84);
// {75D851B7-E19A-4ADB-BDD4-457C8AADD226}
DEF_CLASSID(MssLibUpdaterW,				0x75d851b7, 0xe19a, 0x4adb, 0xbd, 0xd4, 0x45, 0x7c, 0x8a, 0xad, 0xd2, 0x26);
// {F524CE7B-6B2A-499D-BEB7-BD4F5713ACC1}
DEF_CLASSID(MssToolkit,					0xf524ce7b, 0x6b2a, 0x499d, 0xbe, 0xb7, 0xbd, 0x4f, 0x57, 0x13, 0xac, 0xc1);
// {5A5087C0-0389-4A8C-B7B0-EC908DAAEDC3}
DEF_CLASSID(MssHomeFileList,			0x5a5087c0, 0x389, 0x4a8c, 0xb7, 0xb0, 0xec, 0x90, 0x8d, 0xaa, 0xed, 0xc3);

// {82B4A7CE-D98F-4122-9E96-79F01C0B9EDB}
DEF_CLASSID(PropertyX,					0x82b4a7ce, 0xd98f, 0x4122, 0x9e, 0x96, 0x79, 0xf0, 0x1c, 0xb, 0x9e, 0xdb);
// {E74702C4-8F67-4edd-AE44-B1CDC6F3E91E}
DEF_CLASSID(ObjectTable,				0xe74702c4, 0x8f67, 0x4edd, 0xae, 0x44, 0xb1, 0xcd, 0xc6, 0xf3, 0xe9, 0x1e);
//////////////////////////////////////////////////////////////////////////
// {ED20E0E5-2357-4825-B3FA-198AEC674E81}
DEF_CLASSID(Property,					0xed20e0e5, 0x2357, 0x4825, 0xb3, 0xfa, 0x19, 0x8a, 0xec, 0x67, 0x4e, 0x81);
// {2100E98D-B13E-4306-8081-50F325B10586}
DEF_CLASSID(Property2,					0x2100e98d, 0xb13e, 0x4306, 0x80, 0x81, 0x50, 0xf3, 0x25, 0xb1, 0x5, 0x86);
// {545654F7-3B62-49ec-A965-E7E2FAEE9AFD}
DEF_CLASSID(ARCHIVE_CLASS_CATELOG,		0x545654f7, 0x3b62, 0x49ec, 0xa9, 0x65, 0xe7, 0xe2, 0xfa, 0xee, 0x9a, 0xfd);
// {B7D94971-ECCC-442f-AE99-9EE7FF6391C7}
DEF_CLASSID(MDUNIT_CLASS_CATELOG,		0xb7d94971, 0xeccc, 0x442f, 0xae, 0x99, 0x9e, 0xe7, 0xff, 0x63, 0x91, 0xc7);
//////////////////////////////////////////////////////////////////////////
// {3FEE7DBA-AA84-45a1-A083-BB08FCE14C00}
DEF_CLASSID(HandleFile,					0x3fee7dba, 0xaa84, 0x45a1, 0xa0, 0x83, 0xbb, 0x8, 0xfc, 0xe1, 0x4c, 0x0);
// {EABA3E91-E22F-4999-A457-66F563B35C78}
DEF_CLASSID(WinHandleMapFile,			0xeaba3e91, 0xe22f, 0x4999, 0xa4, 0x57, 0x66, 0xf5, 0x63, 0xb3, 0x5c, 0x78);
// {6AB22B24-40B6-480e-8590-52B22CD3ADD3}
DEF_CLASSID(VirtualFile,				0x6ab22b24, 0x40b6, 0x480e, 0x85, 0x90, 0x52, 0xb2, 0x2c, 0xd3, 0xad, 0xd3);
// {25DF75F4-3808-47c0-9CF1-7F5EF488B5C4}
DEF_CLASSID(FormatList,					0x25df75f4, 0x3808, 0x47c0, 0x9c, 0xf1, 0x7f, 0x5e, 0xf4, 0x88, 0xb5, 0xc4);
// {4CD12783-9983-4F38-9392-892B127DDA57}
DEF_CLASSID(PKCS7Verify,				0x4cd12783, 0x9983, 0x4f38, 0x93, 0x92, 0x89, 0x2b, 0x12, 0x7d, 0xda, 0x57);
// {71F5AAD6-71B2-4291-B6BC-4A0C8ADB2087}
DEF_CLASSID(Sig64List,					0x71f5aad6, 0x71b2, 0x4291, 0xb6, 0xbc, 0x4a, 0xc, 0x8a, 0xdb, 0x20, 0x87);
// {AC225D4E-8ADD-473f-BC2E-4B9750D644F1}
DEF_CLASSID(NormalArchive,				0xac225d4e, 0x8add, 0x473f, 0xbc, 0x2e, 0x4b, 0x97, 0x50, 0xd6, 0x44, 0xf1);
//////////////////////////////////////////////////////////////////////////
// {D3160CB4-AC7E-475c-A169-4949E262A0F9}
DEF_CLASSID(LocalFileSystem,			0xd3160cb4, 0xac7e, 0x475c, 0xa1, 0x69, 0x49, 0x49, 0xe2, 0x62, 0xa0, 0xf9);
//////////////////////////////////////////////////////////////////////////
// RArchive
DEF_CLASSID(VolumeHistory,				0xe1d3dde3, 0x4d76, 0x44f6, 0x80, 0xfe, 0x6d, 0xb1, 0x87, 0x92, 0x80, 0x00);
DEF_CLASSID(7zArchive,					0x9e994924, 0x079e, 0x4056, 0x83, 0xa8, 0xdb, 0xa0, 0x17, 0x9b, 0x80, 0x01);
DEF_CLASSID(7zExeArchive,				0x893f80a9, 0x7ba4, 0x46a1, 0xa5, 0x21, 0xc2, 0xa5, 0x43, 0x94, 0x80, 0x02);
DEF_CLASSID(AceArchive,					0x4b9b281a, 0xa454, 0x4650, 0xb2, 0x44, 0x23, 0x60, 0x82, 0x9e, 0x80, 0x03);
DEF_CLASSID(AceExeArchive,				0x173e15b9, 0xe6bf, 0x4b7b, 0x83, 0xc3, 0xd9, 0x76, 0xcf, 0xaa, 0x8e, 0x6b);
DEF_CLASSID(ArcArchive,					0xedecf793, 0x1830, 0x412c, 0xb4, 0x42, 0x36, 0x9a, 0x52, 0xed, 0x80, 0x04);
DEF_CLASSID(ArcExeArchive,				0x19d22abf, 0x8865, 0x4a60, 0xad, 0xb3, 0xd8, 0x48, 0x66, 0xc5, 0x80, 0x05);
DEF_CLASSID(ArjArchive,					0xfb8b31eb, 0x24c9, 0x4f8c, 0xa6, 0x95, 0xde, 0x24, 0xb5, 0xee, 0x80, 0x06);
DEF_CLASSID(ArjExeArchive,				0x7e63fcfa, 0xcc69, 0x455f, 0xbb, 0xa8, 0x2e, 0xe7, 0xc0, 0xc7, 0x80, 0x07);
DEF_CLASSID(Bz2Archive,					0x30e76b46, 0x0f5d, 0x45ce, 0xad, 0x6b, 0xe1, 0x23, 0x21, 0xdb, 0x80, 0x08);
DEF_CLASSID(CabArchive,					0x5282b811, 0x4bd1, 0x4a04, 0x9f, 0x94, 0xc0, 0xa9, 0xef, 0x90, 0x80, 0x09);
DEF_CLASSID(CabExeArchive,				0x5bd0f16b, 0x14f1, 0x4fb2, 0x8a, 0x46, 0x59, 0x8f, 0x8b, 0xe0, 0x80, 0x0a);
DEF_CLASSID(CabSetExeArchive,			0xafee1363, 0x2b6f, 0x4b2f, 0x88, 0x15, 0xef, 0xb3, 0x8e, 0x38, 0x80, 0x0b);
DEF_CLASSID(ChmArchive,					0x9bc3c87c, 0x7324, 0x4877, 0x8c, 0x29, 0xdd, 0xa7, 0x12, 0x13, 0x80, 0x0c);
DEF_CLASSID(GZipArchive,				0xd4ba0996, 0x3106, 0x40a5, 0xac, 0xb2, 0x79, 0x7d, 0xcc, 0xa6, 0x80, 0x0d);
DEF_CLASSID(LhaArchive,					0xc19e8e04, 0xffcb, 0x4d4a, 0x9d, 0x98, 0x26, 0x66, 0xc8, 0x85, 0x80, 0x0e);
DEF_CLASSID(LhaExeArchive,				0xb4509455, 0x02d7, 0x4a7f, 0xb6, 0x48, 0xb7, 0x58, 0xa8, 0x2c, 0x80, 0x0f);
DEF_CLASSID(NsisArchive,				0xcefd62ef, 0xe870, 0x4764, 0xb3, 0x93, 0xb2, 0x52, 0x20, 0xf0, 0x80, 0x10);
DEF_CLASSID(RarArchive,					0xe100b759, 0x0ed2, 0x4086, 0x85, 0x69, 0x7c, 0x00, 0x98, 0x5b, 0x80, 0x11);
DEF_CLASSID(RarExeArchive,				0x1905d5b3, 0x3502, 0x4bf0, 0x89, 0xe3, 0x01, 0x88, 0xde, 0x5d, 0x80, 0x12);
DEF_CLASSID(SisArchive,					0x55cdbaec, 0xa6d2, 0x44c5, 0xbf, 0xe2, 0xe0, 0xa3, 0x62, 0xb6, 0x80, 0x13);
DEF_CLASSID(TarArchive,					0xdb6d0032, 0x7b13, 0x498b, 0x9b, 0x94, 0xa9, 0x72, 0x9e, 0x91, 0x80, 0x14);
DEF_CLASSID(UueArchive,					0xe3225b05, 0x212a, 0x41f6, 0xbd, 0xff, 0x9f, 0x44, 0x81, 0x5a, 0x80, 0x15);
DEF_CLASSID(ZipArchive,					0xc4ec4581, 0x2a1e, 0x494e, 0x80, 0xe1, 0x64, 0xfd, 0x29, 0x01, 0x80, 0x16);
DEF_CLASSID(ZipExeArchive,				0x6f57caf6, 0x43a8, 0x4923, 0x81, 0xfd, 0x65, 0xdc, 0x5f, 0x1e, 0x80, 0x17);
DEF_CLASSID(ZooArchive,					0xa099a829, 0x60e2, 0x44b5, 0x8a, 0x77, 0xfb, 0xb4, 0x5a, 0x1a, 0x80, 0x18);
DEF_CLASSID(InnoArchive,				0x8bcd8bae, 0x302f, 0x4ee4, 0xac, 0x86, 0x28, 0xb6, 0x21, 0xb3, 0x80, 0x19);
DEF_CLASSID(AstrumArchive,				0xa577f510, 0xcf30, 0x4b8e, 0x88, 0x79, 0x03, 0x1e, 0x1b, 0x75, 0x80, 0x1a);
DEF_CLASSID(SeaArchive,					0x105073c0, 0x797f, 0x4b4d, 0x8f, 0x30, 0xde, 0x5d, 0x95, 0x18, 0x80, 0x1b);
DEF_CLASSID(WiseArchive,				0x97ead3b9, 0x2b46, 0x48c7, 0x97, 0xc3, 0xfa, 0xd8, 0x62, 0x8c, 0x80, 0x1c);
DEF_CLASSID(WiseAdvArchive,				0x5b9036c9, 0x4d28, 0x440e, 0xbf, 0x06, 0x02, 0x68, 0x90, 0x6d, 0x80, 0x1d);
DEF_CLASSID(AutoItArchive,				0xc8f26d38, 0xa69c, 0x4086, 0xab, 0x04, 0x70, 0x44, 0x5e, 0xc8, 0x8f, 0x0b);
DEF_CLASSID(ElangArchive,				0xacdd70ee, 0x220b, 0x4a0a, 0xa1, 0x65, 0xaa, 0x85, 0xf0, 0xb9, 0x4a, 0xf2);
DEF_CLASSID(GenteeArchive,				0x0c0161eb, 0xf04d, 0x4150, 0xa8, 0x54, 0x8e, 0x04, 0x4d, 0x34, 0x96, 0xd4);
DEF_CLASSID(PaquetArchive,				0x6b3c2d5b, 0x0aa5, 0x4242, 0x93, 0x1b, 0x7f, 0x04, 0x28, 0xe2, 0x3d, 0xdf);
DEF_CLASSID(InstylerArchive,			0xc51e3c15, 0x6435, 0x41e7, 0xad, 0x72, 0x6d, 0xfd, 0x2d, 0xf6, 0x57, 0x8b);
DEF_CLASSID(QuickBatchArchive,			0x3ae3f533, 0xc8f8, 0x4c61, 0x99, 0x81, 0x41, 0xd0, 0xa1, 0x06, 0xe8, 0x5e);
DEF_CLASSID(SfactoryArchive,			0x93a88fff, 0x5e36, 0x498d, 0x89, 0x23, 0x19, 0x7d, 0x21, 0x0a, 0x65, 0x41);
DEF_CLASSID(PdfArchive,					0x842454cc, 0xfbb4, 0x4143, 0xbc, 0x1f, 0x69, 0x16, 0x63, 0xf0, 0xf2, 0x9e);
DEF_CLASSID(SwcArchive,					0x424881bd, 0xa50a, 0x4f4b, 0xa1, 0x63, 0x9e, 0xd6, 0x6c, 0x7d, 0x45, 0x5a);
DEF_CLASSID(DexArchive,					0x48a6a03e, 0xb2aa, 0x45b8, 0xae, 0x9d, 0x55, 0x6b, 0x12, 0xd3, 0x60, 0xef);
DEF_CLASSID(CmpressBlockArchive,		0x279b0078, 0x5c9b, 0x4236, 0xa9, 0xe0, 0xfc, 0x17, 0x71, 0xe7, 0xbb, 0x9d);
DEF_CLASSID(ApkArchive,					0x4fc1c7fc, 0xd709, 0x4d10, 0x8a, 0xbf, 0xa, 0xd2, 0x1, 0x4, 0x25, 0x95);
DEF_CLASSID(Rar5Archive,				0x72f655e9, 0x11de, 0x45d9, 0xb0, 0xd4, 0x6b, 0x9f, 0x30, 0xd7, 0xa7, 0x19);
DEF_CLASSID(Rar5ExeArchive,				0x3676be9c, 0x62d8, 0x40ee, 0xad, 0x74, 0x55, 0xdd, 0x56, 0xb7, 0xce, 0x2d);

// RCompress
DEF_CLASSID(CopyCoder,					0x78794cd0, 0x4e83, 0x425d, 0x95, 0x0e, 0x95, 0xc9, 0x6e, 0xba, 0xf1, 0x00);
DEF_CLASSID(CipherCoder,				0xaa549a4c, 0x38f2, 0x4814, 0x8e, 0x39, 0xe4, 0xfd, 0xf0, 0x21, 0xf1, 0x01);
DEF_CLASSID(ACEV1Decoder,				0x35aae783, 0x7329, 0x4366, 0xba, 0xba, 0x0f, 0xcc, 0x1c, 0xe9, 0x5b, 0x7b);
DEF_CLASSID(ACEV2Decoder,				0x25b42588, 0x0af5, 0x4677, 0x8d, 0xde, 0x2d, 0xaf, 0xe8, 0x7e, 0xca, 0x9f);
DEF_CLASSID(UUDecoder,					0x70298484, 0xbde5, 0x46dc, 0xb6, 0x5f, 0x24, 0x9d, 0x52, 0x37, 0xf1, 0x02);
DEF_CLASSID(UUEncoder,					0xdc51a58c, 0x16d0, 0x49f0, 0x97, 0xa6, 0x56, 0x21, 0x11, 0x80, 0xf1, 0x03);
DEF_CLASSID(Bz2Decoder,					0xe4a6e031, 0x6296, 0x48e0, 0xaf, 0x2f, 0x82, 0xa1, 0xf1, 0x97, 0xf1, 0x04);
DEF_CLASSID(Bz2Encoder,					0x9f63e862, 0x4ded, 0x4407, 0x9c, 0x03,  0x8e, 0xb, 0x37, 0x79, 0xf1, 0x05);
DEF_CLASSID(Rar29Decoder,				0x0e9ad3c8, 0x08db, 0x411f, 0x85, 0xa3, 0x2a, 0xbf, 0x61, 0xcd, 0xf1, 0x06);
DEF_CLASSID(Rar20Decoder,				0x48423a55, 0xc46d, 0x4898, 0xb6, 0x74, 0xeb, 0xad, 0xc7, 0xbf, 0xf1, 0x07);
DEF_CLASSID(Rar15Decoder, 				0xf19ca6a3, 0xef55, 0x4c8a, 0xaf, 0xf8, 0xf8, 0xdf, 0x42, 0x8a, 0xf1, 0x08);
DEF_CLASSID(Rar5Decoder,				0x8999d489, 0xdd72, 0x4b05, 0xa9, 0x96, 0x48, 0xe8, 0xea, 0xe2, 0x85, 0x87);
DEF_CLASSID(DeflateDecoder,				0x726c8325, 0x4d78, 0x4d71, 0xa2, 0x34, 0x43, 0xd3, 0xe1, 0x7d, 0xf1, 0x09);
DEF_CLASSID(DeflateEncoder,				0xa53bb83c, 0x824b, 0x4ddc, 0x86, 0x68, 0x25, 0xeb, 0x42, 0x13, 0xf1, 0x0a);
DEF_CLASSID(ZooLzwDecoder,				0xcf27143f, 0xc78a, 0x49cf, 0x83, 0x51, 0x9c, 0xbe, 0x3b, 0x63, 0xf1, 0x0b);
DEF_CLASSID(ZooLzhDecoder,				0x4102c32f, 0x0e62, 0x42bf, 0xb2, 0x3e, 0xa9, 0xd9, 0x08, 0x29, 0xf1, 0x0c);
DEF_CLASSID(ArjDecoder	,				0xfb26f2ac, 0x4d16, 0x410b, 0x91, 0x04, 0x55, 0x02, 0x18, 0x36, 0xf1, 0x0d);
DEF_CLASSID(ArjLzhDecoder,				0x1a1aafea, 0xda1c, 0x413a, 0xaa, 0x57, 0xec, 0x64, 0x88, 0x96, 0xf1, 0x0e);
DEF_CLASSID(LzxDecoder,					0x2b0710df, 0x663d, 0x4ab8, 0x8d, 0x93, 0xcf, 0x71, 0x6b, 0xe8, 0xf1, 0x0f);
DEF_CLASSID(LzxEncoder,					0x22189b75, 0x5c80, 0x4430, 0xae, 0xe3, 0x3a, 0x04, 0x8c, 0x42, 0xf1, 0x10);
DEF_CLASSID(QtmDecoder,					0x5091dec5, 0xccef, 0x469f, 0x85, 0x8a, 0x18, 0xee, 0x7c, 0x5e, 0xf1, 0x11);
DEF_CLASSID(Lh1Decoder,					0x011f9ecd, 0x5f4b, 0x495e, 0xa4, 0x4e, 0x5b, 0x84, 0x60, 0xac, 0xf1, 0x12);
DEF_CLASSID(Lh2Decoder,					0x9daa74c5, 0xf97b, 0x40fa, 0xb0, 0xb0, 0xc5, 0xf9, 0x68, 0x8f, 0xf1, 0x13);
DEF_CLASSID(Lh3Decoder,					0x23d40366, 0x39f4, 0x4f64, 0xb9, 0x32, 0x7c, 0x28, 0xec, 0x34, 0xf1, 0x14);
DEF_CLASSID(Lh4Decoder,					0x661dd712, 0x6e3b, 0x442c, 0x92, 0xd9, 0x63, 0x9a, 0x30, 0x98, 0xf1, 0x15);
DEF_CLASSID(Lh5Decoder,					0xdefa619f, 0x4afd, 0x4e0b, 0xb0, 0x2f, 0xd2, 0xb7, 0x61, 0xde, 0xf1, 0x16);
DEF_CLASSID(Lh6Decoder,					0x6a3c0493, 0x8fe4, 0x4c02, 0x90, 0xda, 0xd8, 0xfe, 0x31, 0x0b, 0xf1, 0x17);
DEF_CLASSID(Lh7Decoder,					0x4cb99bf5, 0x16ad, 0x4f30, 0x87, 0xda, 0x98, 0x74, 0xb8, 0x0e, 0xf1, 0x18);
DEF_CLASSID(Lz5Decoder,					0xf587c1f7, 0x0a46, 0x4077, 0x85, 0x7a, 0xfb, 0xc5, 0x4a, 0x8d, 0xf1, 0x19);
DEF_CLASSID(LzsDecoder,					0x32a8dae6, 0xf340, 0x4897, 0x86, 0xf0, 0x1e, 0xaf, 0x57, 0x15, 0xf1, 0x1a);
DEF_CLASSID(ArcDecoder,					0xaf4042cf, 0x0e5f, 0x409d, 0xbd, 0x94, 0x60, 0x29, 0x6a, 0xfd, 0xf1, 0x1b);
DEF_CLASSID(LzmaDecoder,				0xec3116b1, 0x9d6c, 0x4bc4, 0x93, 0x56, 0xe5, 0xda, 0xdf, 0xc6, 0xf1, 0x1c);
DEF_CLASSID(LzmaEncoder,				0xbf2b203f, 0xfdcd, 0x4443, 0xaa, 0xc4, 0xbf, 0xa7, 0x89, 0xf2, 0xf1, 0x1d);
DEF_CLASSID(Lzma2Decoder,				0xa9b914ab, 0xaff1, 0x460e, 0xad, 0x9f, 0xe3, 0xd7, 0x4c, 0x51, 0x75, 0x90);
DEF_CLASSID(Lzma2Encoder,				0x22d27d24, 0x5735, 0x4f74, 0xa3, 0x21, 0xdf, 0x66, 0x83, 0xb1, 0x80, 0xc7);
DEF_CLASSID(BcjDecoder,					0x027edb1b, 0x164e, 0x47f7, 0x99, 0xec, 0x51, 0x8d, 0x2e, 0xb9, 0xf1, 0x1e);
DEF_CLASSID(BcjEncoder,					0x94d5ab3a, 0x1801, 0x4688, 0x93, 0xb6, 0xbb, 0x14, 0x31, 0x14, 0xf1, 0x1f);
DEF_CLASSID(Bcj2Decoder,				0x4542794a, 0x31e5, 0x464d, 0x80, 0x40, 0x61, 0x05, 0x73, 0x93, 0xf1, 0x20);
DEF_CLASSID(Bcj2Encoder,				0xff7957fb, 0x237a, 0x4697, 0x87, 0x33, 0x1f, 0x97, 0x20, 0xeb, 0xf1, 0x21);
DEF_CLASSID(BcPpcDecoder,				0xd6971030, 0x802d, 0x4d14, 0xac, 0xec, 0x7f, 0xa9, 0x17, 0x9b, 0xf1, 0x22);
DEF_CLASSID(BcPpcEncoder,				0x3f0c2e44, 0x3c5d, 0x491e, 0xb7, 0x79, 0x77, 0xc1, 0x3c, 0x5d, 0xf1, 0x23);
DEF_CLASSID(BcIa64Decoder,				0x1071cefe, 0xc512, 0x4bdf, 0x97, 0x6b, 0x39, 0x58, 0xef, 0x8a, 0xf1, 0x24);
DEF_CLASSID(BcIa64Encoder,				0x32f6d1a9, 0x4819, 0x4ced, 0x96, 0x50, 0xd2, 0x1a, 0x13, 0x28, 0xf1, 0x25);
DEF_CLASSID(BcArmDecoder,				0x5a19f4aa, 0x729f, 0x4322, 0xa8, 0x59, 0x54, 0x96, 0x1d, 0xe3, 0xf1, 0x26);
DEF_CLASSID(BcArmEncoder,				0x85bbfa41, 0xc47a, 0x4f2d, 0xb7, 0x41, 0xa4, 0xa5, 0xc0, 0xeb, 0xf1, 0x27);
DEF_CLASSID(BcArmThumbDecoder,			0x04c53710, 0x03e0, 0x41d8, 0xb2, 0x46, 0x24, 0xe0, 0xf7, 0xe4, 0xf1, 0x28);
DEF_CLASSID(BcArmThumbEncoder,			0x0bc80b6d, 0x61dd, 0x47bd, 0xba, 0x18, 0xb7, 0x78, 0x1c, 0xb7, 0xf1, 0x29);
DEF_CLASSID(BcSparcDecoder,				0xb6b2e47a, 0xf303, 0x4cba, 0x99, 0x11, 0xf5, 0x8f, 0x47, 0x0a, 0xf1, 0x2a);
DEF_CLASSID(BcSparcEncoder,				0xb39b7c93, 0x0d69, 0x4233, 0xa2, 0x69, 0xfd, 0x0f, 0xb2, 0x5a, 0xf1, 0x2b);
DEF_CLASSID(PpmdDecoder,				0xd9742425, 0xdd22, 0x4cc6, 0x9a, 0xdb, 0xc3, 0xdd, 0x1f, 0x27, 0xf1, 0x2c);
DEF_CLASSID(PpmdEncoder,				0x714fb119, 0xe78f, 0x4f35, 0x9c, 0xf9, 0x5e, 0xeb, 0x58, 0xab, 0xf1, 0x2d);
DEF_CLASSID(ArcRleDecoder,				0xc174daea, 0x6d55, 0x4779, 0xa6, 0x03, 0x30, 0x21, 0xa4, 0x25, 0xf1, 0x2e);
DEF_CLASSID(ArcHuffmanDecoder,			0xf7ae497b, 0xb0e5, 0x40c7, 0x85, 0xd2, 0x94, 0xca, 0xc9, 0x69, 0xf1, 0x2f);
DEF_CLASSID(ArcLzDecoder,				0x3b2a7025, 0x1847, 0x48c0, 0xbf, 0x80, 0x3f, 0x47, 0xb0, 0xcf, 0xf1, 0x30);
DEF_CLASSID(ArcLzRleDecoder,			0x418b070f, 0x4b9a, 0x4628, 0xba, 0xda, 0x13, 0x1b, 0xcc, 0x94, 0xf1, 0x31);
DEF_CLASSID(ArcLz2RleDecoder,			0xdf642af4, 0x058b, 0x4b03, 0xb7, 0x0f, 0x09, 0x70, 0xd2, 0xec, 0xf1, 0x32);
DEF_CLASSID(ArcDlzRleDecoder,			0xfff55f8a, 0xbe99, 0x461d, 0xa4, 0x26, 0xb0, 0xc1, 0x94, 0x8e, 0xf1, 0x33);
DEF_CLASSID(ArcDlzDecoder,				0x459666d8, 0xc4ff, 0x4d04, 0xa2, 0x50, 0x71, 0xb2, 0x03, 0x69, 0xf1, 0x34);
DEF_CLASSID(CabDeflateDecoder,			0x55f5c6cb, 0x27ef, 0x479e, 0xa4, 0x89, 0xac, 0x24, 0x56, 0xa9, 0xf1, 0x35);
DEF_CLASSID(CabQuantumDecoder,			0x19187912, 0x9c2e, 0x4a89, 0xb4, 0x90, 0xaf, 0x1f, 0x7a, 0x1a, 0xf1, 0x36);
DEF_CLASSID(CabLzxDecoder,				0x1f4d2dec, 0x1eaf, 0x44c9, 0x95, 0x1a, 0xc2, 0xe0, 0xf8, 0xba, 0xf1, 0x37);
DEF_CLASSID(ChmLzxDecoder,				0xe1d38a6d, 0x7af8, 0x43b1, 0x86, 0x1c, 0x14, 0xf2, 0x7e, 0x4d, 0xf1, 0x38);
DEF_CLASSID(ChmLzxEncoder,				0x6b9345e8, 0x488d, 0x41e6, 0xa8, 0x4d, 0x9c, 0x2f, 0x2b, 0x51, 0xf1, 0x39);
DEF_CLASSID(ImplodeDecoder,				0xc03a43b6, 0xfef6, 0x4ca4, 0xb3, 0x30, 0x79, 0x82, 0x97, 0x60, 0xf1, 0x3a);
DEF_CLASSID(ShrinkDecoder,				0x5998c70a, 0x0d77, 0x4a72, 0x9d, 0x89, 0xff, 0xfc, 0x46, 0xed, 0xf1, 0x3b);
DEF_CLASSID(GenteeDecoder,				0xe729bb40, 0xa34b, 0x4b17, 0xa0, 0x6d, 0x65, 0xd5, 0x5f, 0x3a, 0xdb, 0x9a);
DEF_CLASSID(AutoItDecoder,				0x70e0e6af, 0xc938, 0x4fda, 0x84, 0x4b, 0xac, 0x95, 0xf9, 0x8c, 0xcb, 0x6b);
DEF_CLASSID(SFactoryDecoder,			0x22dab0ff, 0xa71b, 0x4bbe, 0x81, 0x3f, 0xba, 0x90, 0xf4, 0xdf, 0x78, 0x06);
DEF_CLASSID(ASCIIHexDecoder,			0xac77b201, 0xeba6, 0x403e, 0x96, 0x62, 0x72, 0x05, 0x5e, 0x8e, 0x47, 0x3f);
DEF_CLASSID(ASCII85Decoder,				0x904811fd, 0x54b6, 0x428f, 0xa0, 0x38, 0x76, 0xa1, 0x58, 0x95, 0xfa, 0xb5);
// RCrypto
DEF_CLASSID(HashSha1,					0xd14d91a2, 0x615c, 0x414f, 0x89, 0x70, 0x3a, 0x4a, 0xad, 0x48, 0x45, 0x00);
DEF_CLASSID(HashSha256,					0xf2765709, 0xdd45, 0x4d04, 0x98, 0x12, 0x4f, 0x1e, 0x59, 0x2a, 0x45, 0x01);
DEF_CLASSID(HashCRC16,					0xba45e713, 0xddb6, 0x4bc7, 0xa7, 0x9c, 0x8c, 0xc5, 0xe7, 0x05, 0x45, 0x02);
DEF_CLASSID(HashCRC32,					0xa5f5e33e, 0x87f4, 0x4c7d, 0xab, 0x0d, 0x3a, 0x16, 0xf4, 0x25, 0x45, 0x03);
DEF_CLASSID(HashMD4,					0xc9b04586, 0x1a22, 0x4729, 0xa4, 0x87, 0xc7, 0x3f, 0x7f, 0xd9, 0x45, 0x04);
DEF_CLASSID(HashMD5,					0x37a3ac99, 0xe1e8, 0x4a2a, 0xb1, 0x99, 0xbe, 0xcf, 0xa5, 0xc4, 0x45, 0x05);
DEF_CLASSID(HashADLER32,				0x918177ee, 0xc1c4, 0x4604, 0x83, 0x80, 0xc0, 0x81, 0xe1, 0x7f, 0x45, 0x06);
DEF_CLASSID(HashHmacSha1,				0x67599a3c, 0x8c5c, 0x4aca, 0xb5, 0x48, 0x33, 0xf8, 0x0d, 0x16, 0x45, 0x07);
DEF_CLASSID(PKCSPBKDF1,					0x984bd5f9, 0x4591, 0x42fe, 0xae, 0x97, 0x16, 0x89, 0xca, 0x98, 0x45, 0x08);
DEF_CLASSID(PKCSPBKDFHmacSha1,			0xc5563ecf, 0x79dc, 0x4fb1, 0xb4, 0x86, 0x8b, 0x3e, 0x7a, 0x39, 0x45, 0x09);
DEF_CLASSID(AesCbcDecoder,				0x0ab25db2, 0x128c, 0x4380, 0xa6, 0x8e, 0x5f, 0xc4, 0x19, 0xb9, 0x45, 0x0a);
DEF_CLASSID(AesCbcEncoder,				0x8dfa8ba9, 0x1a6c, 0x4fb0, 0x81, 0x7f, 0x6c, 0x08, 0x6f, 0x68, 0x45, 0x0b);
DEF_CLASSID(AesEcbDecoder,				0x9f9725c7, 0x319b, 0x4a9c, 0xa7, 0x0b, 0xc3, 0x25, 0xfe, 0xc2, 0x45, 0x0c);
DEF_CLASSID(AesEcbEncoder,				0xd7b666dc, 0x9453, 0x45fd, 0x97, 0xc9, 0x6f, 0xb5, 0x4b, 0xdf, 0x45, 0x0d);
DEF_CLASSID(AesCfbDecoder,				0xae550585, 0xf0d4, 0x4999, 0x93, 0x74, 0x1a, 0x88, 0x31, 0x28, 0x45, 0x0e);
DEF_CLASSID(AesCfbEncoder,				0xbd9f9548, 0x8907, 0x4fbc, 0xb5, 0xa4, 0xc1, 0x25, 0xe8, 0x75, 0x45, 0x0f);
DEF_CLASSID(AesOfbCoder,				0x9cb831a2, 0x424e, 0x4097, 0x9a, 0x27, 0x1b, 0xdc, 0x9a, 0x48, 0x45, 0x10);
DEF_CLASSID(AesCtrSimpleCoder,			0xf5320750, 0xa4b8, 0x4d56, 0x9a, 0x04, 0x47, 0x58, 0x85, 0xe3, 0x45, 0x11);
DEF_CLASSID(Rar20CipherDecoder,			0x632eeb07, 0x4159, 0x4c7b, 0x9a, 0xb6, 0x83, 0xed, 0x5f, 0x0d, 0x45, 0x12);
DEF_CLASSID(Rar20CipherEncoder,			0x6b5b0538, 0x3e24, 0x425d, 0x8b, 0x04, 0xbb, 0x43, 0x12, 0x47, 0x45, 0x13);
DEF_CLASSID(RC4,						0x03162920, 0xf034, 0x45f3, 0xa1, 0x1a, 0xd7, 0xb4, 0x58, 0xcc, 0x45, 0x14);
DEF_CLASSID(BlowFishEcbDecoder,			0xe8a734f7, 0x6c94, 0x4944, 0xba, 0x45, 0x2e, 0xcb, 0x25, 0x62, 0x52, 0x34);
// RAlgorithm
DEF_CLASSID(NaiveSearch,				0x0e7deaea, 0x90cb, 0x4a43, 0x8e, 0x0a, 0x24, 0xf0, 0x3f, 0xa2, 0xab, 0x00);
DEF_CLASSID(RNaiveSearch,				0x1b2ae87e, 0x0efc, 0x4cc2, 0x8c, 0x1c, 0x41, 0x41, 0xa3, 0xd8, 0xab, 0x01);
DEF_CLASSID(MultiNaiveSearch,			0xf6f71a9b, 0x54f1, 0x4a6e, 0x96, 0x31, 0x8f, 0x79, 0xc1, 0x21, 0xab, 0x02);
//////////////////////////////////////////////////////////////////////////
// {AE68FC69-B8D6-4132-9BE7-9E8648258D52}
DEF_CLASSID(PEArchive,				0xae68fc69, 0xb8d6, 0x4132, 0x9b, 0xe7, 0x9e, 0x86, 0x48, 0x25, 0x8d, 0x52);
// {61B8F6DE-0C5B-4c4c-B2D3-7287936CEB24}
DEF_CLASSID(PEArchive2012,			0x61b8f6de, 0xc5b, 0x4c4c, 0xb2, 0xd3, 0x72, 0x87, 0x93, 0x6c, 0xeb, 0x24);
// {8CD4BC83-0CB5-4863-8E03-AE5FFE922296}
DEF_CLASSID(PEArchive64,			0x8cd4bc83, 0xcb5, 0x4863, 0x8e, 0x3, 0xae, 0x5f, 0xfe, 0x92, 0x22, 0x96);

// {E49D1172-8E06-43E9-AB56-0B00F4B8CC85}
DEF_CLASSID(PEDotNetArchive,		0xe49d1172, 0x8e06, 0x43e9, 0xab, 0x56, 0xb, 0x0, 0xf4, 0xb8, 0xcc, 0x85);

//////////////////////////////////////////////////////////////////////////

// {DAAD1266-EB8A-4bba-B6D8-0F8F7D0C19E5}
DEF_CLASSID(InitLegacy10,			0xdaad1266, 0xeb8a, 0x4bba, 0xb6, 0xd8, 0xf, 0x8f, 0x7d, 0xc, 0x19, 0xe5);


//////////////////////////////////////////////////////////////////////////
// Offcice + OLE
// {7B3373EE-5507-4d93-8BDA-C27310FCFBEB}
DEF_CLASSID(OLEArchive,				0x7b3373ee, 0x5507, 0x4d93, 0x8b, 0xda, 0xc2, 0x73, 0x10, 0xfc, 0xfb, 0xeb);
// {4C87FF45-333E-4f21-94D0-204AF2B5E510}
DEF_CLASSID(XMLOfficeArchive,		0x4c87ff45, 0x333e, 0x4f21, 0x94, 0xd0, 0x20, 0x4a, 0xf2, 0xb5, 0xe5, 0x10);

// {3A9FCC4C-ECF6-4128-B875-CBF2E26251B9}
DEF_CLASSID(OpenOfficeArchive,		0x3a9fcc4c, 0xecf6, 0x4128, 0xb8, 0x75, 0xcb, 0xf2, 0xe2, 0x62, 0x51, 0xb9);

// {521FD7F4-9A86-4DC3-9831-E58158A34E49}
DEF_CLASSID(OpenOfficeXML03Archive,	0x521fd7f4, 0x9a86, 0x4dc3, 0x98, 0x31, 0xe5, 0x81, 0x58, 0xa3, 0x4e, 0x49);

// {3EF7B235-1D98-4396-A5B1-657CA36115ED}
DEF_CLASSID(OdfArchive,					0x3ef7b235, 0x1d98, 0x4396, 0xa5, 0xb1, 0x65, 0x7c, 0xa3, 0x61, 0x15, 0xed);

// {167A59DA-0FBB-4096-A125-58803B91E812}
DEF_CLASSID(Enc_PowerShell,				0x167a59da, 0xfbb, 0x4096, 0xa1, 0x25, 0x58, 0x80, 0x3b, 0x91, 0xe8, 0x12);

// {2D202D53-977E-4587-A682-D5B5D4177363}
DEF_CLASSID(CFBArchive, 0x2d202d53, 0x977e, 0x4587, 0xa6, 0x82, 0xd5, 0xb5, 0xd4, 0x17, 0x73, 0x63);
//////////////////////////////////////////////////////////////////////////
// {2C8FD015-5CD5-47bc-971D-EB797E54B8DE}
DEF_CLASSID(ObjectDB,				0x2c8fd015, 0x5cd5, 0x47bc, 0x97, 0x1d, 0xeb, 0x79, 0x7e, 0x54, 0xb8, 0xde);
// {23311803-AA8F-4c23-B62E-DA74E8E6E6E7}
DEF_CLASSID(StoneProp,				0x23311803, 0xaa8f, 0x4c23, 0xb6, 0x2e, 0xda, 0x74, 0xe8, 0xe6, 0xe6, 0xe7);
// {9604CE98-5EE5-4e61-80EA-75C636199199}
DEF_CLASSID(ODBServer,				0x9604ce98, 0x5ee5, 0x4e61, 0x80, 0xea, 0x75, 0xc6, 0x36, 0x19, 0x91, 0x99);
// {601E7047-3A4D-4c88-AE6F-1808FDBD0E02}
DEF_CLASSID(ODBClient,				0x601e7047, 0x3a4d, 0x4c88, 0xae, 0x6f, 0x18, 0x8, 0xfd, 0xbd, 0xe, 0x2);

// {453F0D7C-CF1E-49E6-BA1B-22792009C8A8}
DEF_CLASSID(MemBlock,				0x453f0d7c, 0xcf1e, 0x49e6, 0xba, 0x1b, 0x22, 0x79, 0x20, 0x9, 0xc8, 0xa8);


// {31FFA1BC-C99B-4A30-B6AD-E03D8BFF2C72}
DEF_CLASSID(MD5DB,  0x31ffa1bc, 0xc99b, 0x4a30, 0xb6, 0xad, 0xe0, 0x3d, 0x8b, 0xff, 0x2c, 0x72);

//////////////////////////////////////////////////////////////////////////
//
//	ALL MDU
//

DEF_CLASSID(MduLegacy,				0xb7e45776, 0xea17, 0x4ad4, 0xad, 0x73, 0x3c, 0x0, 0x32, 0x38, 0x1e, 0x76);
DEF_CLASSID(MduSig64,				0x878e9101, 0x30a9, 0x4c53, 0xa8, 0xc2, 0x3f, 0x7f, 0xb2, 0xb9, 0x36, 0x82);
DEF_CLASSID(WduTrust,				0xc80700d2, 0xe490, 0x4659, 0xa3, 0x66, 0x5d, 0xe0, 0xf4, 0x14, 0x8d, 0x94);
DEF_CLASSID(MduExtPre,				0xc80700d2, 0xe490, 0x4659, 0xa3, 0x66, 0x5d, 0xe0, 0xf4, 0x14, 0x8d, 0x94);
DEF_CLASSID(MduExtPost,				0xdd603c2d, 0x8656, 0x44e2, 0xbd, 0x1, 0x7e, 0xa4, 0x5f, 0x72, 0x1b, 0x9f);
DEF_CLASSID(MduMalSpot,				0xe31f6ea7, 0x6c2b, 0x4be4, 0x9f, 0xd3, 0x8a, 0xa9, 0x78, 0x17, 0xbd, 0xb6);
DEF_CLASSID(MduFSM13,				0x1c837f2e, 0x2172, 0x4d58, 0x96, 0xc6, 0xd7, 0x4e, 0x85, 0x68, 0x3b, 0xf5);
DEF_CLASSID(MduMD5,					0xa351a90, 0x16a5, 0x49ca, 0x9a, 0x28, 0x4, 0xb6, 0x40, 0xe3, 0x8a, 0xcf);
DEF_CLASSID(WduTrustJar,			0x97a1f88d, 0x6f51, 0x4eed, 0x9e, 0xb7, 0x3a, 0xab, 0x7, 0x44, 0xba, 0xfe);

/// RXMAIL
DEF_CLASSID(EMLFile, 				0xfc77f137, 0xf556, 0x4318, 0x89, 0x50, 0x80, 0x17, 0xe8, 0xa8, 0x3e, 0xab);
DEF_CLASSID(FoxMail3, 				0x8322d4fe, 0xf957, 0x4719, 0x81, 0x62, 0x96, 0xeb, 0x42, 0x58, 0x84, 0x73);
DEF_CLASSID(Netscape, 				0xbbf91e95, 0x43af, 0x41c4, 0xa0, 0x50, 0x6a, 0xfb, 0xfb, 0xe4, 0xa1, 0xd);
DEF_CLASSID(OutlookExp4, 			0xbfaf3f26, 0x298c, 0x4933, 0x8c, 0xb6, 0xa8, 0x68, 0xcc, 0x87, 0x75, 0xbe);
DEF_CLASSID(OutlookExp5,			0x4ca6b88d, 0xc876, 0x4a2e, 0x90, 0x5c, 0x9b, 0x37, 0x4c, 0x46, 0xa2, 0x6f);
DEF_CLASSID(Base64File, 			0xfe8dc9ac, 0x51f1, 0x499a, 0x99, 0x7, 0x59, 0x95, 0x9f, 0x2b, 0xca, 0xb0);
DEF_CLASSID(UnicodeFile, 			0x18405b48, 0x8f86, 0x4b05, 0xae, 0x2a, 0x63, 0x49, 0xbd, 0xc5, 0x38, 0x2a);
DEF_CLASSID(OutlookPst, 			0xc08648b2, 0x6a21, 0x435c, 0xbc, 0x1d, 0x81, 0x35, 0x1f, 0xea, 0xef, 0x48);
DEF_CLASSID(XDPFile,				0x6acefe0f, 0x2493, 0x403f, 0x92, 0x28, 0x84, 0x2e, 0xf4, 0xc0, 0x42, 0x86);
DEF_CLASSID(RTFArchive,				0x3f2d41fe, 0x9874, 0x47b6, 0x96, 0x86, 0x2b, 0xd8, 0xcd, 0x43, 0x7d, 0x50);

//////////////////////////////////////////////////////////////////////////
//
//

DEF_CLASSID(Parameter,				0x5ded5f8e, 0x2540, 0x4a95, 0x85, 0xc5, 0x45, 0x83, 0x25, 0x9b, 0x56, 0xcb);
DEF_CLASSID(Condition,				0xd2ce41b6, 0xa934, 0x4642, 0xaf, 0x52, 0xff, 0x1c, 0xd4, 0xdc, 0x4d, 0xc5);
DEF_CLASSID(NameDB,					0x68741441, 0x396a, 0x4d24, 0x91, 0x5f, 0xce, 0xd9, 0x7c, 0x27, 0xa1, 0x65);
DEF_CLASSID(Thd3NameDB,				0xbf015182, 0x3bb8, 0x46d6, 0x96, 0x52, 0x3b, 0xe8, 0xfd, 0x37, 0x22, 0x9c);



// {C52381B4-E43A-4532-8833-336352CE8634}
DEF_CLASSID(CondFilter,				0xc52381b4, 0xe43a, 0x4532, 0x88, 0x33, 0x33, 0x63, 0x52, 0xce, 0x86, 0x34);

//////////////////////////////////////////////////////////////////////////
//
// MachineLearn
//
// {0C88B3E9-79D5-44d7-A464-7756D193BC51}
DEF_CLASSID(SupportVectorMachine,	0xc88b3e9, 0x79d5, 0x44d7, 0xa4, 0x64, 0x77, 0x56, 0xd1, 0x93, 0xbc, 0x51);

//////////////////////////////////////////////////////////////////////////
//
// ScanIcon
//
// {EA108057-9C00-4429-AFD1-0B78B6344C25}
DEF_CLASSID(MduVision,				0xea108057, 0x9c00, 0x4429, 0xaf, 0xd1, 0xb, 0x78, 0xb6, 0x34, 0x4c, 0x25);


// {C392EC5B-615F-4398-9FEF-777128ABC247}
DEF_CLASSID(CloudEngine17,			0xc392ec5b, 0x615f, 0x4398, 0x9f, 0xef, 0x77, 0x71, 0x28, 0xab, 0xc2, 0x47);

// {2286FA5F-6299-4A83-992F-23518C0C5D83}
DEF_CLASSID(ZDRClient,				0x2286fa5f, 0x6299, 0x4a83, 0x99, 0x2f, 0x23, 0x51, 0x8c, 0xc, 0x5d, 0x83);

// {95E8C43E-7569-41BE-A375-7A7AABEE4CC5}
DEF_CLASSID(ZDRHttpClient,			0x95e8c43e, 0x7569, 0x41be, 0xa3, 0x75, 0x7a, 0x7a, 0xab, 0xee, 0x4c, 0xc5);

// {D9FDE754-A745-45BE-B2E7-AD0E40CB414D}
DEF_CLASSID(ZDRHashs,				0xd9fde754, 0xa745, 0x45be, 0xb2, 0xe7, 0xad, 0xe, 0x40, 0xcb, 0x41, 0x4d);

// {49435255-AB67-4B48-B283-6E7B3FAA0E7B}
DEF_CLASSID(CloudRxudx,				0x49435255, 0xab67, 0x4b48, 0xb2, 0x83, 0x6e, 0x7b, 0x3f, 0xaa, 0xe, 0x7b);

// {22624DFB-F442-41CA-9ABE-16857BF3D463}
DEF_CLASSID(UDXHttpClient,			0x22624dfb, 0xf442, 0x41ca, 0x9a, 0xbe, 0x16, 0x85, 0x7b, 0xf3, 0xd4, 0x63);

// {A2AFAC50-9E58-423E-B695-388278E96DE7}
DEF_CLASSID(ZDRBatchClient,			0xa2afac50, 0x9e58, 0x423e, 0xb6, 0x95, 0x38, 0x82, 0x78, 0xe9, 0x6d, 0xe7);


//////////////////////////////////////////////////////////////////////////
//
// ExtDU
//

// {EFC201FC-3D7D-4DEC-B585-1111364EB204}
DEF_CLASSID(MduSVM00,				0xefc201fc, 0x3d7d, 0x4dec, 0xb5, 0x85, 0x11, 0x11, 0x36, 0x4e, 0xb2, 0x4);

// {5B0D0493-07CE-4D14-AF6E-F5A89E2022F6}
DEF_CLASSID(MSO,					0x5b0d0493, 0x7ce, 0x4d14, 0xaf, 0x6e, 0xf5, 0xa8, 0x9e, 0x20, 0x22, 0xf6);


// {8B3A7A3E-2A92-4958-A982-B9AE8A37983F}
DEF_CLASSID(MemoryFile1,			0x8b3a7a3e, 0x2a92, 0x4958, 0xa9, 0x82, 0xb9, 0xae, 0x8a, 0x37, 0x98, 0x3f);

DEF_CLASSID(SmartInstallerArchive,		0xfa9826cd, 0x8234, 0x47dd, 0xb7, 0xf8, 0x0f, 0x1b, 0x71, 0x23, 0x37, 0xca);

// {A8110D2B-8636-4300-94AC-BD491AC6B753}
DEF_CLASSID(FasArchive,					0xa8110d2b, 0x8636, 0x4300, 0x94, 0xac, 0xbd, 0x49, 0x1a, 0xc6, 0xb7, 0x53);
// {7EBEA267-614B-445E-BD34-EEB70FB7208C}
DEF_CLASSID(CSwfArchive2,	0x7ebea267, 0x614b, 0x445e, 0xbd, 0x34, 0xee, 0xb7, 0xf, 0xb7, 0x20, 0x8c);


// {6F6E00BC-119C-4512-9D1A-80AF59877594}
DEF_CLASSID(CVbeArchive,	0x6f6e00bc, 0x119c, 0x4512, 0x9d, 0x1a, 0x80, 0xaf, 0x59, 0x87, 0x75, 0x94);


// {4105F800-C0D9-45BA-B116-7A3C286A1094}
DEF_CLASSID(JsArchive,			0x4105f800, 0xc0d9, 0x45ba, 0xb1, 0x16, 0x7a, 0x3c, 0x28, 0x6a, 0x10, 0x94);

// {DF43CD8C-2709-493C-854D-9C00A76CE4B8}
DEF_CLASSID(WSFArchive,	0xdf43cd8c, 0x2709, 0x493c, 0x85, 0x4d, 0x9c, 0x0, 0xa7, 0x6c, 0xe4, 0xb8);

// {878D119A-228A-4054-94AA-A9EB580326ED}
DEF_CLASSID(TsnClient,	0x878d119a, 0x228a, 0x4054, 0x94, 0xaa, 0xa9, 0xeb, 0x58, 0x3, 0x26, 0xed);			
			
// {0EFBC0DD-F8C6-4373-A506-3951349A62AC}
DEF_CLASSID(CertVerify, 0xefbc0dd, 0xf8c6, 0x4373, 0xa5, 0x6, 0x39, 0x51, 0x34, 0x9a, 0x62, 0xac);


// {45C8F6E4-50EB-47F1-A4EE-61D42A687E2E}
DEF_CLASSID(CertVerifyW, 0x45c8f6e4, 0x50eb, 0x47f1, 0xa4, 0xee, 0x61, 0xd4, 0x2a, 0x68, 0x7e, 0x2e);

// {C97CB19D-6CA1-48DB-8095-2BD74178E087}
DEF_CLASSID(ZlibArchive, 0xc97cb19d, 0x6ca1, 0x48db, 0x80, 0x95, 0x2b, 0xd7, 0x41, 0x78, 0xe0, 0x87);

// {E6252F42-8EE6-4C9E-AA1E-F97AFF46BCF1}
DEF_CLASSID(ELFArchive, 0xe6252f42, 0x8ee6, 0x4c9e, 0xaa, 0x1e, 0xf9, 0x7a, 0xff, 0x46, 0xbc, 0xf1);


// {89C3DC01-7ECE-4F85-9D32-4B083A976416}
DEF_CLASSID(HtmlArchive, 0x89c3dc01, 0x7ece, 0x4f85, 0x9d, 0x32, 0x4b, 0x8, 0x3a, 0x97, 0x64, 0x16);

// {45B1EDBC-3352-490D-9C17-044CD1908284}
DEF_CLASSID(IsoArchive,	0x45b1edbc, 0x3352, 0x490d, 0x9c, 0x17, 0x4, 0x4c, 0xd1, 0x90, 0x82, 0x84);

// {B2FCAC39-800A-4033-9725-AEC32259904C}
DEF_CLASSID(CPyPeArch,					0xb2fcac39, 0x800a, 0x4033, 0x97, 0x25, 0xae, 0xc3, 0x22, 0x59, 0x90, 0x4c);

// {28BE1D07-3559-4956-BE3E-E3C3F04375DF}
DEF_CLASSID(PYZArchive,					0x28be1d07, 0x3559, 0x4956, 0xbe, 0x3e, 0xe3, 0xc3, 0xf0, 0x43, 0x75, 0xdf);

DEF_CLASSID(CCpioArchive,				0xdaf13b4e, 0x6288, 0x4d45, 0x82, 0x78, 0xb7, 0xfb, 0x1, 0xdf, 0x5d, 0xdc);
DEF_CLASSID(CCramfsArchive,				0x5d5b423a, 0x8e0d, 0x4307, 0xab, 0x27, 0x7, 0xfd, 0xf2, 0x25, 0x64, 0x67);

// {B59B50FB-4BBE-41E8-8872-58C881E9D969}
DEF_CLASSID(CDebArchive,				0xb59b50fb, 0x4bbe, 0x41e8, 0x88, 0x72, 0x58, 0xc8, 0x81, 0xe9, 0xd9, 0x69);

DEF_CLASSID(CRpmArchive,				0xb15eab51, 0x61b7, 0x4749, 0x90, 0x9b, 0x6d, 0xde, 0x2, 0x2c, 0x1f, 0xb3);

// {8E9B9729-59BC-44AA-8C15-4E6C82666ED4}
DEF_CLASSID(CCrxArchive,				0x8e9b9729, 0x59bc, 0x44aa, 0x8c, 0x15, 0x4e, 0x6c, 0x82, 0x66, 0x6e, 0xd4);

// {C6BD90BC-A05B-457F-B352-1CBE7B7B2128}
DEF_CLASSID(CPycArch,					0xc6bd90bc, 0xa05b, 0x457f, 0xb3, 0x52, 0x1c, 0xbe, 0x7b, 0x7b, 0x21, 0x28);

// {32E9470E-D41E-4DFD-B344-120A49630A0A}
DEF_CLASSID(CImgArchive,				0x32e9470e, 0xd41e, 0x4dfd, 0xb3, 0x44, 0x12, 0xa, 0x49, 0x63, 0xa, 0xa);

// {7D1048E3-8D8E-484C-A580-FB7A706C9297}
DEF_CLASSID(CAHKArchive,				0x7d1048e3, 0x8d8e, 0x484c, 0xa5, 0x80, 0xfb, 0x7a, 0x70, 0x6c, 0x92, 0x97);

// {2FB310C7-780D-4406-BFC5-9E01B72B4E75}
DEF_CLASSID(CTextArchive,               0x2fb310c7, 0x780d, 0x4406, 0xbf, 0xc5, 0x9e, 0x1, 0xb7, 0x2b, 0x4e, 0x75);

// {71152AD7-23BC-400F-8462-822A1916C2A0}
DEF_CLASSID(CDAAArchive,				0x71152ad7, 0x23bc, 0x400f, 0x84, 0x62, 0x82, 0x2a, 0x19, 0x16, 0xc2, 0xa0);


// {38976422-ABAD-4CA9-BB2A-54AEFE3EA63F}
DEF_CLASSID(CEARArchive,				0x38976422, 0xabad, 0x4ca9, 0xbb, 0x2a, 0x54, 0xae, 0xfe, 0x3e, 0xa6, 0x3f);


// {8DB6F11B-2282-412B-B3E7-402F1B4ABC77}
DEF_CLASSID(UpxNode,					0x8db6f11b, 0x2282, 0x412b, 0xb3, 0xe7, 0x40, 0x2f, 0x1b, 0x4a, 0xbc, 0x77);

// {61143299-8595-445e-B40E-715198235B83}
DEFINE_GUID(CloudRavux, 0x61143299, 0x8595, 0x445e, 0xb4, 0xe, 0x71, 0x51, 0x98, 0x23, 0x5b, 0x83);


// {48B0F376-1304-4472-AA29-D6D95EADAAE2}
DEF_CLASSID(ELFHashFetcher, 0x48b0f376, 0x1304, 0x4472, 0xaa, 0x29, 0xd6, 0xd9, 0x5e, 0xad, 0xaa, 0xe2);
/////////////////////////////////////////////////////////
//将13移植到10下使用
// {847A0848-86DC-46B9-8237-37FC2D05B496}
DEFINE_GUID(CLSID_Eng13Env, 0x847a0848, 0x86dc, 0x46b9, 0x82, 0x37, 0x37, 0xfc, 0x2d, 0x5, 0xb4, 0x96);
// {A324EA6B-9C0C-47FD-B5D5-073DF2057692}
DEFINE_GUID(CLSID_Eng13VDB, 0xa324ea6b, 0x9c0c, 0x47fd, 0xb5, 0xd5, 0x7, 0x3d, 0xf2, 0x5, 0x76, 0x92);
DEFINE_GUID(PID_File_FFR,				0x31bb7c6e, 0x9108, 0x4087, 0xb0, 0x0a, 0xd4, 0xc0, 0x40, 0x6d, 0xa5, 0x43);
// VT_UI4:
DEFINE_GUID(PID_File_FFR_Index,			0x747ca55d, 0xc25e, 0x4308, 0xac, 0x43, 0xd4, 0xbe, 0x9a, 0x2e, 0xf2, 0x25);
DEFINE_GUID(PID_File_FileName,			0x4481ad4e, 0x7bd7, 0x4d7b, 0xb7, 0x0d, 0x90, 0xa9, 0xbe, 0x55, 0x51, 0x53);


#endif
