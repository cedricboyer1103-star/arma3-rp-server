@echo off
REM Arma 3 RP Server - Windows Startup Script

REM Configuration
set SERVER_DIR=C:\arma3server
set SERVER_PORT=2302
set SERVER_CONFIG=server.cfg
set BASIC_CONFIG=basic.cfg
set SERVER_PROFILE=SC

REM Server executable
set SERVER_EXEC=arma3server_x64.exe

REM Mods to load (add your @mod folders here)
set MODS=
REM Example: set MODS=-mod=@CBA_A3;@task_force_radio;@AltisLife

REM Server parameters
set PARAMS=-port=%SERVER_PORT%
set PARAMS=%PARAMS% -config=%SERVER_CONFIG%
set PARAMS=%PARAMS% -cfg=%BASIC_CONFIG%
set PARAMS=%PARAMS% -profiles=%SERVER_PROFILE%
set PARAMS=%PARAMS% -name=%SERVER_PROFILE%
set PARAMS=%PARAMS% -world=empty
set PARAMS=%PARAMS% -ranking=ranking.log

REM Performance parameters
set PARAMS=%PARAMS% -cpuCount=4
set PARAMS=%PARAMS% -exThreads=7
set PARAMS=%PARAMS% -malloc=system
set PARAMS=%PARAMS% -limitFPS=60

REM Add mods if specified
if defined MODS set PARAMS=%PARAMS% %MODS%

REM Additional parameters
set PARAMS=%PARAMS% -autoInit
set PARAMS=%PARAMS% -loadMissionToMemory

REM Display startup information
echo ======================================
echo Arma 3 RP Server - Starting...
echo ======================================
echo Server Directory: %SERVER_DIR%
echo Port: %SERVER_PORT%
echo Config: %SERVER_CONFIG%
echo Profile: %SERVER_PROFILE%
echo Mods: %MODS%
echo ======================================

REM Change to server directory
cd /d "%SERVER_DIR%"
if errorlevel 1 (
    echo ERROR: Failed to change to server directory: %SERVER_DIR%
    pause
    exit /b 1
)

REM Start the server
echo Starting server with parameters:
echo "%SERVER_EXEC%" %PARAMS%
echo.
start "" "%SERVER_EXEC%" %PARAMS%

echo Server started!
pause
