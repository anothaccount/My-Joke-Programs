@echo off
title Solve This!
set /a num=%random% %%20 +1
set x=%num%
set /a num=%random% %%20 +1
set y=%num%

set /a z = x + y
echo Solve this equation to continue your session.
echo.
echo %x% + %y% = ?
echo.
:bruh
set /p g=
echo.
if %g%==%z% GOTO CORRECT
if NOT %g%==%z% GOTO WRONG
goto bruh
:correct
echo.
echo Correct!
pause
EXIT /B
:wrong
echo.
color 04
echo WRONG!
echo.
timeout 2 > nul /nobreak
exit /b