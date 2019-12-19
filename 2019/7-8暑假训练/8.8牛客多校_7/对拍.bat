:loop

rand.exe
A.exe
4.exe

fc ans.txt cmp.txt
if errorlevel==1 pause

goto loop