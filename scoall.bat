@echo off
dir /b *.c > myfiles.txt
FOR /F %%G IN (myfiles.txt) DO scocl gtaiv %%G .\pc\
del myfiles.txt