if not exist build mkdir build
cd build_sim
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\VsDevCmd.bat" -host_arch=amd64 -arch=amd64
cmake .. -G "NMake Makefiles"
nmake