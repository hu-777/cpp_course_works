@echo off
pushd .

if not exist build (
    md build
)

cd build
cmake -G"MinGW Makefiles" "C:\Users\hfq18\Desktop\cpp-training-start (1)\cpp-training"
mingw32-make.exe

popd
