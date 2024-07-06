// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DISABLE_THE_ACCESSIBILITY_SHORTCUT_KEYS_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DISABLE_THE_ACCESSIBILITY_SHORTCUT_KEYS_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef DISABLE_THE_ACCESSIBILITY_SHORTCUT_KEYS_EXPORTS
#define DISABLE_THE_ACCESSIBILITY_SHORTCUT_KEYS_API __declspec(dllexport)
#else
#define DISABLE_THE_ACCESSIBILITY_SHORTCUT_KEYS_API __declspec(dllimport)
#endif

// DLL����
// ����ϵͳ�ĸ�������
// ��ճ����STICKYKEYS������shift����5�Ρ�
// �л�����TOGGLEKEYS����shift��ס5�롣
// ɸѡ����FILTERKEYS����num lock����ס5�롣
// ������MOUSEKEYS����alt+��shift+num lock����
// �߶Աȶȣ�HIGHCONTRAST����alt+shift+print screen����
extern "C" DISABLE_THE_ACCESSIBILITY_SHORTCUT_KEYS_API void StartDisASK();
extern "C" DISABLE_THE_ACCESSIBILITY_SHORTCUT_KEYS_API void StopDisASK();