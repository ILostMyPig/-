// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DIS_CAD_DLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DIS_CAD_DLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef DIS_CAD_DLL_EXPORTS
#define DIS_CAD_DLL_API __declspec(dllexport)
#else
#define DIS_CAD_DLL_API __declspec(dllimport)
#endif

// DLL���ܣ�
// ����winlogin���̡�
// Ŀ���ǽ���ctrl+alt+del��
extern "C" DIS_CAD_DLL_API bool EnableDebugPrivilege(void);
extern "C" DIS_CAD_DLL_API bool SusWin(void);
extern "C" DIS_CAD_DLL_API bool ResWin(void);