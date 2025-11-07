# Addons Directory

This directory contains custom addons and modifications for the Arma 3 RP server.

## Structure

```
addons/
├── @mod_name/          # Custom mod folders
│   ├── addons/         # PBO files
│   └── keys/           # Signature keys
└── scripts/            # Custom server-side scripts
```

## Common RP Addons

### Essential Mods
- **Altis Life Framework** - Core RP framework
- **CBA_A3** - Community Base Addons
- **Task Force Radio** - Advanced radio communication
- **Advanced Towing** - Vehicle towing system
- **Enhanced Movement** - Better player movement

### Custom Scripts
- Player economy system
- Job systems (Police, EMS, etc.)
- Vehicle shops
- Housing system
- Gang/faction systems

## Installation

1. Download required mods from Steam Workshop or other sources
2. Extract mod folders to `addons/@mod_name/`
3. Add mod to server startup parameters: `-mod=@mod_name`
4. Copy mod keys to `keys/` directory for signature verification

## Development

For custom scripts:
1. Create new `.sqf` files in `addons/scripts/`
2. Reference them in mission files or server config
3. Test thoroughly before production deployment

## Notes

- Keep mods updated to prevent compatibility issues
- Document any custom modifications
- Backup before updating mods
