// dis_cad_dll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "dis_cad_dll.h"

long WinlogonPID;

typedef long ( NTAPI *_NtSuspendProcess )( IN HANDLE ProcessHandle );
typedef long ( NTAPI *_NtResumeProcess )( IN HANDLE ProcessHandle );

bool WCHAR_same(WCHAR *a, WCHAR *b, int c);
long GetWinlogonPID(void);

/// <summary>����ǰ������Ȩ��
/// <returns>
/// <para>return true���ɹ���</para>
/// <para>return false��ʧ�ܡ�</para>
/// </returns></summary>
DIS_CAD_DLL_API bool EnableDebugPrivilege(void)
{
	DWORD e;
	WCHAR ss[111];
	LPVOID lpMsgBuf;

	bool re;
	TOKEN_PRIVILEGES TP;

	long r;
	//��������Ȩ��
	HANDLE gcp;

	SetLastError(ERROR_SUCCESS);
	gcp=GetCurrentProcess();
	e = GetLastError();
	FormatMessage (
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		e,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0, NULL );
	swprintf(ss, 11, L"%s", lpMsgBuf);
	if(e != 0)MessageBox(NULL, ss, _T("EDP -> GetCurrentProcess"),MB_OK);

	HANDLE hToken;
	SetLastError(ERROR_SUCCESS);
	r = OpenProcessToken(gcp, TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);
	e = GetLastError();
	FormatMessage (
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		e,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0, NULL );
	swprintf(ss, 11, L"%s", lpMsgBuf);
	if(e != 0)MessageBox(NULL, ss, _T("EDP -> OpenProcessToken"),MB_OK);
	if (r &&  !e)
	{
		SetLastError(ERROR_SUCCESS);
		r = LookupPrivilegeValue(NULL, L"SeDebugPrivilege", &TP.Privileges[0].Luid);
		e = GetLastError();
		FormatMessage (
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			e,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR) &lpMsgBuf,
			0, NULL );
		swprintf(ss, 11, L"%s", lpMsgBuf);
		if(e != 0)MessageBox(NULL, ss, _T("EDP -> LookupPrivilegeValue"),MB_OK);
		if (r && !e)
		{
			TP.PrivilegeCount = 1;
			TP.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
			SetLastError(ERROR_SUCCESS);
			r = AdjustTokenPrivileges(hToken, false, &TP, sizeof(TP), 0, 0);
			e = GetLastError();
			FormatMessage (
				FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
				NULL,
				e,
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				(LPTSTR) &lpMsgBuf,
				0, NULL );
			swprintf(ss, 11, L"%s", lpMsgBuf);
			if(e != 0)MessageBox(NULL, ss, _T("EDP -> AdjustTokenPrivileges"),MB_OK);
			if(e == 0)
			{
				re = true;
			}
			else
			{
				re=false;
			}
		}
		else
		{
			re = false;
		}
	}
	else
	{
		re = false;
	}

	CloseHandle(hToken);
	return re;
}

/// <summary>����winlogon���̡�����ε��ñ�������Ҳ�����ͬ����� ResWin �������ָܻ����̡�
/// <returns>
/// <para>return ���ɹ���</para>
/// </returns></summary>
DIS_CAD_DLL_API bool SusWin(void)
{
	DWORD e;
	WCHAR ss[11];
	LPVOID lpMsgBuf;

	HANDLE hP;
	SetLastError(ERROR_SUCCESS);
	hP = OpenProcess(PROCESS_ALL_ACCESS, false, GetWinlogonPID());
	e = GetLastError();
	FormatMessage (
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		e,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0, NULL );
	swprintf(ss, 11, L"%s", lpMsgBuf);
	if(e != 0)MessageBox(NULL, ss, _T("SW -> OpenProcess"),MB_OK);
	if (hP == 0 )
	{
		return false;
	}

	_NtSuspendProcess NtSuspendProcess = 0;
	NtSuspendProcess = (_NtSuspendProcess)
		GetProcAddress( GetModuleHandle( L"ntdll" ), "NtSuspendProcess" );

	long re;
	SetLastError(ERROR_SUCCESS);
	re=NtSuspendProcess(hP) >= 0;
	e = GetLastError();
	FormatMessage (
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		e,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0, NULL );
	swprintf(ss, 11, L"%s", lpMsgBuf);
	if(e != 0)MessageBox(NULL, ss, _T("SW -> OpenProcess"),MB_OK);
	CloseHandle( hP);

	return true;
}

/// <summary>��ȡ��ǰ���̵�PID��
/// <returns>
/// <para>return ��PID��</para>
/// </returns></summary>
long GetWinlogonPID(void)
{
	DWORD e;
	WCHAR ss[11];
	LPVOID lpMsgBuf;

	long re = 0;
	long lngResult;
	HANDLE hSnapShot;

	PROCESSENTRY32 PEE ;
	SetLastError(ERROR_SUCCESS);
	hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	e = GetLastError();
	FormatMessage (
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		e,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0, NULL );
	swprintf(ss, 11, L"%s", lpMsgBuf);
	if(e != 0)MessageBox(NULL, ss, _T("GWPID -> CreateToolhelp32Snapshot"),MB_OK);


	PEE.dwSize = sizeof(PEE);
	SetLastError(ERROR_SUCCESS);
	lngResult = Process32First(hSnapShot, &PEE);
	e = GetLastError();
	FormatMessage (
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		e,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0, NULL );
	swprintf(ss, 11, L"%s", lpMsgBuf);
	if(e != 0)MessageBox(NULL, ss, _T("GWPID -> Process32First"),MB_OK);

	//�������̿��գ�ѭ�����ҽ���

	WCHAR strExe[13]={0};
	while(lngResult != 0)
	{

		for (int i =0;i<=11;i++)//��ֵ
		{
			strExe[i]=PEE.szExeFile[i];
		}

		bool x;
		WCHAR strsame[]=L"winlogon.exe";
		x = WCHAR_same(strExe, strsame,12);

		if( true == x) //�ҵ�winlogon.exe�򷵻�
		{
			re= PEE.th32ProcessID;
			CloseHandle( hSnapShot);
			WinlogonPID=re;
			return re;
		}
		SetLastError(ERROR_SUCCESS);
		lngResult = Process32Next(hSnapShot, &PEE);
		e = GetLastError();
		FormatMessage (
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			e,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR) &lpMsgBuf,
			0, NULL );
		swprintf(ss, 11, L"%s", lpMsgBuf);
		if(e != 0)MessageBox(NULL, ss, _T("GWPID -> Process32Next"),MB_OK);
	}
	CloseHandle (hSnapShot);
	return re;
}

/// <summary>�ָ�winlogin���̡�����ε��� SusWin ������Ҳ�����ͬ����ı��������ָܻ����̡�
/// <returns>
/// <para>return true���ɹ���</para>
/// <para>return false��ʧ�ܡ�</para>
/// </returns></summary>
DIS_CAD_DLL_API bool ResWin(void)
{
	HANDLE hP;
	hP = OpenProcess(PROCESS_ALL_ACCESS, false, WinlogonPID);
	if (hP == 0)
	{
		return false;
	}

	_NtResumeProcess NtResumeProcess = 0;
	NtResumeProcess = (_NtResumeProcess)
		GetProcAddress( GetModuleHandle( _T("ntdll") ), "NtResumeProcess" );

	bool re;
	re=NtResumeProcess(hP) >= 0;

	CloseHandle (hP);
	return re;
}

/// <summary>�Ƚ����� WCHAR ���͵������Ƿ���ͬ��
/// <returns>
/// <para>return false����ͬ��</para>
/// <para>return true����ͬ��</para>
/// </returns></summary>
/// <param name="a">��һ�� WCHAR ���ݡ�</param>
/// <param name="b">�ڶ��� WCHAR ���ݡ�</param>
/// <param name="c">WCHAR ����Ҫ�Աȵ�Ԫ��������</param>
bool WCHAR_same(WCHAR *a, WCHAR *b, int c)
{
	for (int i=0;i<c;i++)
	{
		if( a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}