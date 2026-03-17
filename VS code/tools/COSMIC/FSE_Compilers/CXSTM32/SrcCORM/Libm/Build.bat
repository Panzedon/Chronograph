@echo off
cls
echo.
echo ==== CORTEX-M3/M4 Machine Library ====
echo.
echo Building LIBM.CXM ...
cacorm -v *.s
clib -c libm.cxm *.o
del *.o
echo.
echo Done.
