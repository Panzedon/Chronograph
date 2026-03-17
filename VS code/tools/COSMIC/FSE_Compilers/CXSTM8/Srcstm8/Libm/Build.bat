@echo off
cls
echo.
echo Building the LIBM.SM8 Machine Library in progress...
echo.
castm8 -vb *.s
clib -c libm.sm8 *.o
del *.o
castm8 -vb -dSTM8L eep*.s
clib -c libl.sm8 *.o
del *.o
echo.
echo Done.
