// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DIS_START_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DIS_START_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef DIS_START_EXPORTS
#define DIS_START_API __declspec(dllexport)
#else
#define DIS_START_API __declspec(dllimport)
#endif

// DLL����:
// ���ؿ�ʼ��ť�Ϳ�ʼ����
extern "C" DIS_START_API int StartdisStart(void);
extern "C" DIS_START_API int StopdisStart(void);