#!/bin/bash
# Arma 3 RP Server - Startup Script

# Configuration
SERVER_DIR="/home/arma3server"
SERVER_PORT=2302
SERVER_CONFIG="server.cfg"
BASIC_CONFIG="basic.cfg"
SERVER_PROFILE="SC"
MODS_DIR="addons"

# Server executable
SERVER_EXEC="./arma3server"

# Mods to load (add your @mod folders here)
MODS=""
# Example: MODS="-mod=@CBA_A3;@task_force_radio;@AlisLife"

# Server parameters
PARAMS="-port=$SERVER_PORT"
PARAMS="$PARAMS -config=$SERVER_CONFIG"
PARAMS="$PARAMS -cfg=$BASIC_CONFIG"
PARAMS="$PARAMS -profiles=$SERVER_PROFILE"
PARAMS="$PARAMS -name=$SERVER_PROFILE"
PARAMS="$PARAMS -world=empty"
PARAMS="$PARAMS -ranking=ranking.log"

# Performance parameters
PARAMS="$PARAMS -cpuCount=4"
PARAMS="$PARAMS -exThreads=7"
PARAMS="$PARAMS -malloc=system"
PARAMS="$PARAMS -limitFPS=60"

# Add mods if specified
if [ ! -z "$MODS" ]; then
    PARAMS="$PARAMS $MODS"
fi

# Additional parameters
PARAMS="$PARAMS -autoInit"
PARAMS="$PARAMS -loadMissionToMemory"

# Display startup information
echo "======================================"
echo "Arma 3 RP Server - Starting..."
echo "======================================"
echo "Server Directory: $SERVER_DIR"
echo "Port: $SERVER_PORT"
echo "Config: $SERVER_CONFIG"
echo "Profile: $SERVER_PROFILE"
echo "Mods: $MODS"
echo "======================================"

# Change to server directory
if ! cd "$SERVER_DIR"; then
    echo "ERROR: Failed to change to server directory: $SERVER_DIR"
    exit 1
fi

# Start the server
echo "Starting server with parameters:"
echo "$SERVER_EXEC $PARAMS"
echo ""
"$SERVER_EXEC" $PARAMS

# If server crashes, restart after 5 seconds
echo "Server stopped. Waiting 5 seconds before restart..."
sleep 5
exec $0
