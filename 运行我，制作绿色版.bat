@echo on
"C:\Program Files\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe" "%CD%\cs_fxb_win_hook.sln" /rebuild "release"
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
echo ע�������װvs2010ʱ���޸��˰�װ·������Ҫ�ֶ����ɳ������ִ���ҡ�
echo.
echo ������ɣ�
echo.
echo ����������������� ��cs_fxb_win_hook.exe��
echo ���ó��� ��set_ini.exe��
echo.
echo - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
explorer ���������\
pause