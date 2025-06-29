@echo off
title Pike Game
echo Pike wants to play a game with you! 1) Yes 2) No
set /p pike=
if %pike%==1 goto game
if %pike%==2 goto toobad
:toobad
echo Wanna quit? Too bad! x3
timeout 2 > nul /nobreak
goto scare
:scare
exit
:game
cls
set /a num=%random% %%10 +1
echo Pick a number from 1-10! (You have 3 guesses)
set /p guess=
if %guess%==%num% goto win
if NOT %guess%==%num% goto tryagain
:tryagain
cls
echo Oops! Wrong!
echo Pick a number from 1-10! (You have 2 guesses)
set /p guess=
if %guess%==%num% goto win
if NOT %guess%==%num% goto tryagainfinal
:tryagainfinal
cls
echo Oops! One more chance!
echo Pick a number from 1-10! (You have 1 guesses)
set /p guess=
if %guess%==%num% goto win
if NOT %guess%==%num% goto loser
:loser
cls
echo Sorry! Pike will pop a balloon now! The number was %num%.
pause
goto scare
:win
cls
echo Yay! You win! The number was %num%.
pause
exit