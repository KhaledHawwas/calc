@echo off
:start
gcc -g -c calc.c
gcc -o calc.exe calc.o
pause
