# Installation Guide - Arma 3 RP Server

This guide will help you set up and configure your Arma 3 roleplay server.

## Prerequisites

### System Requirements
- **OS**: Windows Server 2016+ or Linux (Ubuntu 20.04+)
- **RAM**: Minimum 8GB (16GB+ recommended)
- **CPU**: 4+ cores recommended
- **Storage**: 50GB+ free space
- **Network**: Static IP, open ports 2302-2306 (UDP)

### Required Software
- **Arma 3 Dedicated Server** (SteamCMD or Steam)
- **MySQL/MariaDB** (for database)
- **Git** (optional, for updates)

## Installation Steps

### 1. Install SteamCMD

**Windows:**
```batch
Download from: https://steamcdn-a.akamaihd.net/client/installer/steamcmd.zip
Extract to C:\steamcmd
```

**Linux:**
```bash
sudo apt update
sudo apt install steamcmd
```

### 2. Download Arma 3 Server

**Windows:**
```batch
cd C:\steamcmd
steamcmd +login anonymous +force_install_dir C:\arma3server +app_update 233780 validate +quit
```

**Linux:**
```bash
steamcmd +login anonymous +force_install_dir /home/arma3server +app_update 233780 validate +quit
```

### 3. Clone This Repository

```bash
cd /home/arma3server  # or C:\arma3server
git clone https://github.com/cedricboyer1103-star/arma3-rp-server.git config
```

### 4. Copy Configuration Files

Copy the configuration files to your Arma 3 server directory:

```bash
cp config/server.cfg ./
cp config/basic.cfg ./
cp config/start_server.sh ./  # Linux
# or
copy config\start_server.bat .\  # Windows
```

### 5. Setup Database

Install MySQL/MariaDB and create the database:

```bash
# Install MySQL (Ubuntu)
sudo apt install mysql-server

# Create database
mysql -u root -p < config/database/schema.sql

# Create user
mysql -u root -p
CREATE USER 'arma3_user'@'localhost' IDENTIFIED BY 'your_password';
GRANT ALL PRIVILEGES ON arma3_rp.* TO 'arma3_user'@'localhost';
FLUSH PRIVILEGES;
```

### 6. Configure Server

Edit `server.cfg`:
- Set `hostname` to your server name
- Set `passwordAdmin` to a secure admin password
- Set `serverCommandPassword` to a secure command password
- Configure `maxPlayers` as needed

Edit `database/config.md`:
- Update database credentials
- Configure connection settings

### 7. Install Mods (Optional)

Download required mods from Steam Workshop:
1. Subscribe to mods in Steam Workshop
2. Copy from `\steamapps\workshop\content\107410\<mod_id>` to server
3. Rename to `@ModName` format
4. Add to startup script

Common RP mods:
- @CBA_A3
- @task_force_radio
- @AltisLife (or your preferred RP framework)

### 8. Setup Mission Files

1. Place your RP mission in `mpmissions/` folder
2. Format: `MissionName.MapName` (e.g., `Altis_Life.Altis`)
3. Update `server.cfg` mission class to match

### 9. Configure Firewall

**Linux (UFW):**
```bash
sudo ufw allow 2302:2306/udp
sudo ufw reload
```

**Windows:**
```batch
netsh advfirewall firewall add rule name="Arma 3 Server" dir=in action=allow protocol=UDP localport=2302-2306
```

### 10. Start Server

**Linux:**
```bash
./start_server.sh
```

**Windows:**
```batch
start_server.bat
```

## Post-Installation

### Testing
1. Launch Arma 3 client
2. Use "Remote" filter in multiplayer
3. Connect to your server IP:2302
4. Test admin access with admin password

### Monitoring
- Check `logs/server.log` for errors
- Monitor player connections
- Review BattlEye logs if enabled

### Maintenance
- Regular backups of database
- Keep server and mods updated
- Monitor server performance
- Review and rotate logs

## Troubleshooting

### Server Won't Start
- Check `logs/server.log` for errors
- Verify all config files are present
- Check file permissions (Linux)
- Ensure ports are not in use

### Players Can't Connect
- Verify firewall rules
- Check server is running
- Confirm port forwarding (if behind NAT)
- Verify mods match between server and client

### Database Connection Failed
- Check MySQL service is running
- Verify credentials in config
- Test database connection manually
- Check firewall allows MySQL port

### Performance Issues
- Increase server RAM allocation
- Reduce max players
- Optimize mission scripts
- Consider headless client for AI

## Support

For issues and questions:
- Check Arma 3 server documentation
- Review community forums
- Check mod documentation
- Review server logs for errors

## Security

**Important:**
- Change all default passwords immediately
- Keep server software updated
- Regular security audits
- Backup regularly
- Use strong passwords for admin access
