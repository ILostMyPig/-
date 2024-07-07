// Disable_the_Accessibility_Shortcut_Keys.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Disable_the_Accessibility_Shortcut_Keys.h"

// ��� StartDisASK �����л�ȡ�ĵ�ǰ���á�
STICKYKEYS g_StartupStickyKeys = {sizeof(STICKYKEYS), 0}; // ����������ճ���������ݽṹ��
TOGGLEKEYS g_StartupToggleKeys = {sizeof(TOGGLEKEYS), 0}; // ���������л����������ݽṹ��
FILTERKEYS g_StartupFilterKeys = {sizeof(FILTERKEYS), 0}; // ��������ɸѡ���������ݽṹ��
MOUSEKEYS g_StartupMouseKeys = {sizeof(MOUSEKEYS), 0}; // �������������������ݽṹ��
HIGHCONTRAST g_StartupHighContrast = {sizeof(HIGHCONTRAST), 0}; // ���������߶Աȶȡ������ݽṹ��


/// <summary>���ø�������
/// </summary>
DISABLE_THE_ACCESSIBILITY_SHORTCUT_KEYS_API void StopDisASK()
{  
	BOOL re;
	// ʹ�� StartDisASK �����л�ȡ�ĵ�ǰ�������ָ���
	re = SystemParametersInfo(SPI_SETSTICKYKEYS, sizeof(STICKYKEYS), &g_StartupStickyKeys, 0);
	re = SystemParametersInfo(SPI_SETTOGGLEKEYS, sizeof(TOGGLEKEYS), &g_StartupToggleKeys, 0);
	re = SystemParametersInfo(SPI_SETFILTERKEYS, sizeof(FILTERKEYS), &g_StartupFilterKeys, 0);
	re = SystemParametersInfo(SPI_SETMOUSEKEYS, sizeof(MOUSEKEYS), &g_StartupMouseKeys, 0);
	re = SystemParametersInfo(SPI_SETHIGHCONTRAST, sizeof(HIGHCONTRAST), &g_StartupHighContrast, 0);
}

/// <summary>���ø�������
/// </summary>
DISABLE_THE_ACCESSIBILITY_SHORTCUT_KEYS_API void StartDisASK()
{
	BOOL re;
	// ��ȡ��ǰ���á�
	re = SystemParametersInfo(SPI_GETSTICKYKEYS, sizeof(STICKYKEYS), &g_StartupStickyKeys, 0); 
	re = SystemParametersInfo(SPI_GETTOGGLEKEYS, sizeof(TOGGLEKEYS), &g_StartupToggleKeys, 0);
	re = SystemParametersInfo(SPI_GETFILTERKEYS, sizeof(FILTERKEYS), &g_StartupFilterKeys, 0);
	re = SystemParametersInfo(SPI_GETMOUSEKEYS, sizeof(MOUSEKEYS), &g_StartupMouseKeys, 0);
	re = SystemParametersInfo(SPI_GETHIGHCONTRAST, sizeof(HIGHCONTRAST), &g_StartupHighContrast, 0);

	// ����ǰ���ø��Ƶ���������õı����С�
	STICKYKEYS skOff = g_StartupStickyKeys;
	TOGGLEKEYS tkOff = g_StartupToggleKeys;
	FILTERKEYS fkOff = g_StartupFilterKeys;
	MOUSEKEYS mkOff = g_StartupMouseKeys;
	HIGHCONTRAST hcOff = g_StartupHighContrast;

	// �������õ�Ч����Ϊ���ø�������Ȼ����������Ч��
	skOff.dwFlags &= ~SKF_HOTKEYACTIVE;
	skOff.dwFlags &= ~SKF_CONFIRMHOTKEY;
	re = SystemParametersInfo(SPI_SETSTICKYKEYS, sizeof(STICKYKEYS), &skOff, 0);

	tkOff.dwFlags &= ~TKF_HOTKEYACTIVE;
	tkOff.dwFlags &= ~TKF_CONFIRMHOTKEY;
	re = SystemParametersInfo(SPI_SETTOGGLEKEYS, sizeof(TOGGLEKEYS), &tkOff, 0);

	fkOff.dwFlags &= ~FKF_HOTKEYACTIVE;
	fkOff.dwFlags &= ~FKF_CONFIRMHOTKEY;
	re = SystemParametersInfo(SPI_SETFILTERKEYS, sizeof(FILTERKEYS), &fkOff, 0);

	mkOff.dwFlags &= ~FKF_HOTKEYACTIVE;
	mkOff.dwFlags &= ~FKF_CONFIRMHOTKEY;
	re = SystemParametersInfo(SPI_SETMOUSEKEYS, sizeof(MOUSEKEYS), &mkOff, 0);

	hcOff.dwFlags &= ~FKF_HOTKEYACTIVE;
	hcOff.dwFlags &= ~FKF_CONFIRMHOTKEY;
	re = SystemParametersInfo(SPI_SETHIGHCONTRAST, sizeof(HIGHCONTRAST), &hcOff, 0);
}