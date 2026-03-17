@echo off
cxcorm -lv +mods +debug acia.c vector.c
if errorlevel 1 goto bad
:clink
echo.
echo Linking ...
clnk -o acia.cxm -m acia.map acia.lkf
if errorlevel 1 goto bad
:chexa
echo.
echo Converting ...
chex -o acia.hex acia.cxm
if errorlevel 1 goto bad
:cllabs
echo.
echo Generating absolute listing ...
clabs acia.cxm
if errorlevel 1 goto bad
echo.
echo.
echo        The Cross Compiler for CORTEX-M is now installed.
goto sortie
:bad
echo.
echo.
echo        THE COMPILER INSTALLATION FAILED.
:sortie
echo on
