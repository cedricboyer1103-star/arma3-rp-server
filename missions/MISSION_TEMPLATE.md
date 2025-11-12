# Sample RP Mission Structure

This is a template/reference for creating an Altis Life / RP mission.

## Basic Mission Structure

```
MissionName.Altis/
├── description.ext          # Mission configuration
├── mission.sqm              # Mission objects and settings
├── init.sqf                 # Main initialization
├── initPlayerLocal.sqf      # Client-side player init
├── initServer.sqf           # Server-side init
├── onPlayerRespawn.sqf      # Respawn handling
├── Functions.hpp            # Function definitions
├── stringtable.xml          # Localization
├── briefing.sqf             # Mission briefing
│
├── core/                    # Core scripts
│   ├── session/            # Session management
│   ├── vehicle/            # Vehicle systems
│   ├── housing/            # Housing systems
│   ├── items/              # Item systems
│   ├── economy/            # Economy/shops
│   └── functions/          # Utility functions
│
├── dialog/                  # UI Dialogs
│   ├── player_inv.hpp      # Player inventory
│   ├── vehicle_shop.hpp    # Vehicle shop
│   ├── item_shop.hpp       # Item shop
│   └── atm.hpp             # ATM interface
│
├── config/                  # Mission configuration
│   ├── Config_Vehicles.hpp # Vehicle definitions
│   ├── Config_Items.hpp    # Item definitions
│   ├── Config_Shops.hpp    # Shop configurations
│   └── Config_License.hpp  # License definitions
│
└── scripts/                 # Additional scripts
    ├── safezone.sqf        # Safe zones
    ├── spawn.sqf           # Spawn system
    └── wanted.sqf          # Wanted system
```

## Essential Files

### description.ext
```cpp
// Basic mission info
author = "Your Name";
onLoadName = "Altis Life RP";
onLoadMission = "Bienvenue sur notre serveur RP";
loadScreen = "images\logo.paa";

// Respawn settings
respawn = "BASE";
respawnDelay = 5;
respawnDialog = 0;

// Disable channels (optional)
disableChannels[] = {{0,true,true},{1,true,true},{2,true,true}};

// Include functions
#include "Functions.hpp"

// Include dialogs
#include "dialog\MasterHandler.hpp"

// Include configs
#include "config\Config_Master.hpp"
```

### init.sqf
```sqf
// Client-side initialization
if (!isDedicated) then {
    // Wait for player
    waitUntil {!isNull player && player == player};
    
    // Initialize player systems
    [] call life_fnc_initPlayer;
    
    // Setup event handlers
    player addEventHandler ["Respawn", {_this call life_fnc_onPlayerRespawn}];
};
```

### initServer.sqf
```sqf
// Server-side initialization
if (isServer) then {
    // Initialize server systems
    [] call life_fnc_initServer;
    
    // Start economy system
    [] call life_fnc_economyInit;
    
    // Start cleanup system
    [] spawn life_fnc_cleanup;
};
```

### Functions.hpp
```cpp
class Life_Client_Core {
    tag = "life";
    
    class Player {
        file = "core\player";
        class initPlayer {};
        class savePlayer {};
        class loadPlayer {};
    };
    
    class Vehicle {
        file = "core\vehicle";
        class vehicleShop {};
        class buyVehicle {};
        class sellVehicle {};
    };
    
    class Economy {
        file = "core\economy";
        class atmMenu {};
        class bankTransfer {};
        class buyItem {};
    };
};
```

## Database Integration

Example database calls using extDB3 or similar:

```sqf
// Save player to database
_query = format["UPDATE players SET cash=%1, bank=%2, position='%3' WHERE steam_id='%4'",
    life_cash,
    life_bank,
    str(getPosATL player),
    getPlayerUID player
];
[_query, 1] call DB_fnc_asyncCall;

// Load player from database
_query = format["SELECT cash, bank, position FROM players WHERE steam_id='%1'", getPlayerUID player];
_result = [_query, 2] call DB_fnc_asyncCall;
```

## Important Considerations

### Performance
- Use scheduled scripts for heavy operations
- Implement cleanup for abandoned vehicles
- Optimize database queries
- Use area restrictions wisely

### Security
- Validate all player inputs
- Sanitize database queries
- Implement anti-cheat measures
- Restrict admin functions properly

### Persistence
- Save player data regularly
- Auto-save on disconnect
- Handle server crashes gracefully
- Implement rollback procedures

### User Experience
- Clear UI/dialogs
- Helpful notifications
- Tutorial for new players
- Fair economy balance

## Testing

Before deploying to production:

1. **Local Testing**
   - Test all systems in single player
   - Verify database connections
   - Check for script errors

2. **Multiplayer Testing**
   - Test with multiple clients
   - Verify persistence
   - Check network performance

3. **Security Testing**
   - Test for exploits
   - Verify anti-cheat
   - Check admin tools

## Resources

- [Bohemia Wiki - Mission Files](https://community.bistudio.com/wiki/Mission_Files)
- [Altis Life Framework](https://github.com/AsYetUntitled/Framework)
- [SQF Syntax Guide](https://community.bistudio.com/wiki/SQF_Syntax)

## Notes

- This is a reference structure, adapt to your needs
- Consider using existing frameworks as a base
- Document your custom systems
- Keep backups of working versions
