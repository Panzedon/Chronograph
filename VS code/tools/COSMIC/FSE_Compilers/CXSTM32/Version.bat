@echo off
cls
echo.
echo Catch version and date of Compiler and utilities in: VERSION.TXT...
echo --------------------------------->Version.txt
echo STM32 COSMIC C 32K Compiler>>Version.txt
echo Version: 4.3.12 Date: 14 Dec 2023>>Version.txt
echo --------------------------------->>Version.txt
.\cxcorm -vers 2>>Version.txt
.\cpcorm -vers 2>>Version.txt
.\cgcorm -vers 2>>Version.txt
.\cocorm -vers 2>>Version.txt
.\cacorm -vers 2>>Version.txt
.\clnk -vers 2>>Version.txt
.\chex -vers 2>>Version.txt
.\clabs -vers 2>>Version.txt
.\clib -vers 2>>Version.txt
.\clst -vers 2>>Version.txt
.\cobj -vers 2>>Version.txt
.\cprd -vers 2>>Version.txt
.\cvdwarf -vers 2>>Version.txt
echo Done !
echo.
type Version.txt
echo on
