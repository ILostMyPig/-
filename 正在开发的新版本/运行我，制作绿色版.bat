@echo on
if /i "%PROCESSOR_ARCHITECTURE%"=="x86" (
    "C:\Program Files\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe" "%CD%\cs_fxb_win_hook.sln" /rebuild "release"
) else (
    "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe" "%CD%\cs_fxb_win_hook.sln" /rebuild "release"
)
rd /s /q ���������
md ���������
copy release\*.exe ���������\
copy release\*.dll ���������\
del ���������\*.vshost.exe
xcopy /e ��������������ļ�\* ���������\
@echo off
echo.
echo - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
echo.
echo ע�������װVS2010ʱ���޸��˰�װ·����
echo     ����Ҫ��VS2010���ֶ����ɳ������ִ�д��ļ���
echo.
echo ������ɣ�
echo.
echo ����������������� ��cs_fxb_win_hook.exe��
echo ���ó��� ��set_ini.exe��
echo.
echo - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
explorer ���������\
pause