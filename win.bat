
call "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat"



mkdir build
cd build
cmake -G Ninja ..
cmake --build .

pause