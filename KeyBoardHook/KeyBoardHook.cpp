#include <Windows.h>
#include <fstream>

//#define DEBUG
#ifdef DEBUG
#define LOG(x,z) {std::ofstream outfile(x,std::ios::app);outfile<<z<<std::endl;outfile.close();}
#else
#define LOG(x,z) 
#endif

HINSTANCE g_hInstance = NULL;
HHOOK g_hHook = NULL; // ���ӵľ����

BOOL APIENTRY DllMain( HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved )
{
	g_hInstance = (HINSTANCE)hDllHandle;
	return TRUE;
}

/// <summary>��SetWindowsHookEx����һ��ʹ�õ�Ӧ�ó������ⶨ��Ļص�������</summary>
LRESULT CALLBACK KeyBoardProc(int code, WPARAM wParam, LPARAM lParam)
{	// ��Ҫ������Ϣ��ʹ��Ϣ���ٴ�����ȥ���򷵻�1��
	// ������0�����ʾ����������ʧ�ܣ�ϵͳ�����Ϣ������һ�����ӣ��൱�ڵ���CallNextHookEx��

	KBDLLHOOKSTRUCT *pKeyInfo = (KBDLLHOOKSTRUCT *)lParam;
	DWORD a = pKeyInfo->vkCode;

	if (code >= HC_ACTION) // �� code < HC_ACTION���򴫵ݱ���Ϣ��������ʹ��Ҫ��
	{
		SHORT keyState= 0 ;

		// MSDN��flag�ĵ�8bitΪ��������̧���־������Ϊ1��̧��Ϊ0��
		// �����ԣ�flag����Ϊ0��̧��Ϊ128����ס��̧����һֱ���밴����Ϣ��
		LOG("KeyboardHook.log","pKeyInfo->vkCode : " << pKeyInfo->vkCode);
		LOG("KeyboardHook.log","pKeyInfo->flags : " << pKeyInfo->flags ); 
		LOG("KeyboardHook.log","pKeyInfo->time : " << pKeyInfo->time  );

		if ( // ����������İ���,�����ء�
			(a == VK_TAB) || (a == VK_RETURN) || (a == VK_CAPITAL) || (a == VK_SPACE) // ���ܼ���tab��enter��caps��space��
			|| (a >= VK_SPACE && a <= VK_HOME)  // ���ܼ���space��home��end��pgup��pgdn��
			|| (a == VK_INSERT) || (a == VK_DELETE) // ���ܼ���
			|| (a == VK_F5) || (a == VK_NUMLOCK) || (a == VK_BACK) // ���ܼ���
			|| (a == VK_CONTROL) || (a == VK_LCONTROL) || (a == VK_RCONTROL) // CONTROL��
			|| (a == VK_SHIFT) ||(a == VK_LSHIFT) || (a == VK_RSHIFT) // SHIFT�� 
			|| (a >= VK_LEFT && a <= VK_DOWN) // ������������ҡ�
			|| (a >= 0x30 && a <= 0x39) // ���ּ�0-9��
			|| (a >= 0x41 && a <= 0x5A) // ��ĸA-Z��
			|| (a >= VK_NUMPAD0 && a <= VK_DIVIDE) // С���̣�0-9���ˡ��ӡ��س��������㡢����
			|| (a >= VK_OEM_4 && a <= VK_OEM_7) || (a >= VK_OEM_1 && a <= VK_OEM_3) // ���š�
			)
		{
			if((pKeyInfo->flags & 0x80) == 0)
			{ // ��Ϊ̧����Ϣ�������ء�
				return CallNextHookEx(g_hHook, code, wParam, lParam);
			}
			else
			{
				if ((pKeyInfo->flags & LLKHF_ALTDOWN) !=0) // alt״̬�ḽ�����������İ�����Ϣ�С�					
				{ // ��Я��alt���������ء�
					return 1;
				}
				else
				{
					// ʹ��VK_CONTROL���жϣ���Ϊ����ڹ��Ӵ���֮ǰ�͸��°���״̬
					keyState = GetKeyState(VK_CONTROL); 
					if (keyState < 0) // ��ctrl����ס,�������һ���жϡ�
					{
						if ( // �����ؼ�space��shift��x��c��v��
							(a == VK_SPACE) // space��
							|| (a == VK_SHIFT) || (a == VK_LSHIFT) || (a == VK_RSHIFT) // shift��
							|| (a == 0x43) || (a == 0x58) || (a == 0x56) //c��x��v��
							)
							return CallNextHookEx(g_hHook, code, wParam, lParam);
						else
							return 1;
					}
					else
					{
						return CallNextHookEx(g_hHook, code, wParam, lParam);
					}
				}
			}
		}
		else
		{
			return 1;
		}
	}		
}

extern "C"
{
	/// <summary>��װ�ͼ����̹��ӡ�
	/// <returns>
	/// <para>return FALSE��ʧ�ܡ�</para>
	/// <para>return TRUE���ɹ���</para>
	/// </returns></summary>
	__declspec(dllexport) bool StartHook()
	{
		if (g_hHook)
		{
			return FALSE;
		}
		else
		{
			g_hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyBoardProc, g_hInstance, 0);
			if (g_hHook)
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
	}

	/// <summary>ɾ���ͼ����̹��ӡ�
	/// <returns>
	/// <para>return FALSE��ʧ�ܡ�</para>
	/// <para>return TRUE���ɹ���</para>
	/// </returns></summary>
	__declspec(dllexport) bool StopHook()
	{
		if (UnhookWindowsHookEx(g_hHook))
		{
			g_hHook = NULL;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
};