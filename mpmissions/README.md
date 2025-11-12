# Missions Directory

This directory contains the mission files for the Arma 3 RP server.

## Structure

- `mpmissions/` - Multiplayer missions that will be available on the server
- Each mission should be in its own folder with the format: `MissionName.MapName`

## Example Mission

A typical Altis Life / RP mission structure would be:
```
Altis_Life.Altis/
├── description.ext      # Mission configuration
├── mission.sqm          # Mission data
├── init.sqf             # Initialization script
├── initPlayerLocal.sqf  # Player initialization
├── initServer.sqf       # Server initialization
├── core/                # Core scripts
├── dialog/              # UI dialogs
└── Functions.hpp        # Function definitions
```

## Adding a Mission

1. Create a new folder in `mpmissions/` with the format `MissionName.MapName`
2. Add your mission files to that folder
3. Update `server.cfg` to include the mission in the rotation
4. Restart the server

## Notes

- Make sure mission files are properly signed if using signature verification
- Test missions in local environment before deploying to production server
