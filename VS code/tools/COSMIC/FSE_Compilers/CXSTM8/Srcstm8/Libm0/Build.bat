@echo off
cls
echo.
echo Building the LIBM0.SM8 Machine Library in progress...
echo.
castm8 -vb *.s
clib -c libm0.sm8 *.o
del *.o
castm8 -vb -dSTM8L eep*.s
clib -c libl0.sm8 *.o
del *.o
echo.
echo Done.
