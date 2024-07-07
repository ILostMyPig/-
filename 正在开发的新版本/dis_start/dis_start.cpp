// dis_start.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "dis_start.h"

HWND re_gdi = NULL; // ��ʼ��ť�ľ����
HWND re_fw = NULL; // ��ʼ���ľ����

/// <summary>���ؿ�ʼ��ť�Ϳ�ʼ����
/// <returns>
/// <para>return 0���ɹ���</para>
/// <para>return -1��û���ҵ���ʼ���ľ����</para>
/// <para>return -2��û���ҵ���ʼ��ť�ľ����</para>
/// </returns></summary>
DIS_START_API int StartdisStart(void)
{
	BOOL re;

	// ���ؿ�ʼ����
	re_fw=FindWindow(L"Shell_TrayWnd", NULL); // ��ȡ��ʼ���ľ����
	if(re_fw == NULL){return -1;}
	re = ShowWindow(re_fw, SW_HIDE); // ���ؿ�ʼ����

	// ���ؿ�ʼ��ť��
	re_gdi=FindWindow(L"Button", NULL); // ��ȡ��ʼ��ť�ľ����
	if(re_gdi == NULL){return -2;}
	re = ShowWindow(re_gdi, SW_HIDE); // ���ؿ�ʼ��ť��

	return 0;
}

/// <summary>��ʾ��ʼ��ť�Ϳ�ʼ����
/// <returns>
/// <para>return 0���ɹ���</para>
/// </returns></summary>
DIS_START_API int StopdisStart(void)
{
	BOOL re;

	re = ShowWindow(re_gdi, SW_SHOW); // ��ʾ��ʼ����
	re = ShowWindow(re_fw, SW_SHOW); // ��ʾ��ʼ��ť��

	return 0;
}