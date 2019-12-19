:loop

rand.exe
A.exe
AA.exe

fc ans.txt cmp.txt
if errorlevel==1 pause

goto loop