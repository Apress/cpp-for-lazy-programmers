REM Erase folders you don't want -- here's my picks
for /r . %%d in (Debug,.vs) do @if exist "%%d" rd /s/q "%%d" 
REM Erase other files -- here's my picks. 
REM /s means "in subfolders too"
del /s *.ncb	REM used by earlier versions (before 2010) 
del /s *.sdf	REM used by earlier versions (2010-2015)
