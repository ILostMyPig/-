#ifndef __KEYBOARDHOOK_INTERFACE__
#define __KEYBOARDHOOK_INTERFACE__
#endif
// DLL���ܣ�
// ʹ�õͼ����̹��ӣ������˰�����Ϣ��
// ����ϵͳ�ȼ����޷����ˣ����ܻ�ð�����Ϣ�����磺ctrl+alt+del����������
extern "C"
{
	bool StartHook();
	bool StopHook();
};

