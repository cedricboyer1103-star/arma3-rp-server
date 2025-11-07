# Arma 3 RP Server - Database Configuration

## MySQL Database Configuration

host: localhost
port: 3306
database: arma3_rp
username: arma3_user
password: changeme

## Tables

### Players Table
- player_id (PRIMARY KEY)
- steam_id
- player_name
- cash
- bank
- position_x
- position_y
- position_z
- last_login
- play_time

### Vehicles Table
- vehicle_id (PRIMARY KEY)
- owner_steam_id
- vehicle_class
- position_x
- position_y
- position_z
- damage
- fuel
- inventory

### Houses Table
- house_id (PRIMARY KEY)
- owner_steam_id
- position_x
- position_y
- position_z
- price
- inventory

### Gangs Table
- gang_id (PRIMARY KEY)
- gang_name
- leader_steam_id
- bank
- members

## Notes
- Make sure to change the default password
- Create database schema before starting server
- Regular backups recommended
