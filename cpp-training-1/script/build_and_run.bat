@echo off
pushd .

echo Building the project...
call "C:\Users\hfq18\Desktop\cpp-training-start (1)\cpp-training\script\build.bat"
echo Build Error Level: %errorlevel%
if %errorlevel% neq 0 (
    echo There was an error during the build process.
) else (
    echo Running the application...
    call "C:\Users\hfq18\Desktop\cpp-training-start (1)\cpp-training\script\run.bat"
    echo Run Error Level: %errorlevel%
    if %errorlevel% neq 0 (
        echo There was an error running the application.
    )
)

popd


