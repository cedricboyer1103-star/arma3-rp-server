-- Arma 3 RP Server - Database Schema
-- MySQL Database Setup Script

-- Create database
CREATE DATABASE IF NOT EXISTS arma3_rp CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
USE arma3_rp;

-- Players table
CREATE TABLE IF NOT EXISTS players (
    player_id INT AUTO_INCREMENT PRIMARY KEY,
    steam_id VARCHAR(17) UNIQUE NOT NULL,
    player_name VARCHAR(64) NOT NULL,
    cash INT DEFAULT 0,
    bank INT DEFAULT 5000,
    position_x FLOAT DEFAULT 0,
    position_y FLOAT DEFAULT 0,
    position_z FLOAT DEFAULT 0,
    last_login TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    play_time INT DEFAULT 0,
    cop_level INT DEFAULT 0,
    medic_level INT DEFAULT 0,
    admin_level INT DEFAULT 0,
    INDEX idx_steam_id (steam_id)
) ENGINE=InnoDB;

-- Vehicles table
CREATE TABLE IF NOT EXISTS vehicles (
    vehicle_id INT AUTO_INCREMENT PRIMARY KEY,
    owner_steam_id VARCHAR(17) NOT NULL,
    vehicle_class VARCHAR(64) NOT NULL,
    position_x FLOAT DEFAULT 0,
    position_y FLOAT DEFAULT 0,
    position_z FLOAT DEFAULT 0,
    damage FLOAT DEFAULT 0,
    fuel FLOAT DEFAULT 1,
    inventory TEXT,
    active BOOLEAN DEFAULT TRUE,
    INDEX idx_owner (owner_steam_id),
    FOREIGN KEY (owner_steam_id) REFERENCES players(steam_id) ON DELETE CASCADE
) ENGINE=InnoDB;

-- Houses table
CREATE TABLE IF NOT EXISTS houses (
    house_id INT AUTO_INCREMENT PRIMARY KEY,
    owner_steam_id VARCHAR(17),
    position_x FLOAT NOT NULL,
    position_y FLOAT NOT NULL,
    position_z FLOAT NOT NULL,
    price INT NOT NULL,
    inventory TEXT,
    owned BOOLEAN DEFAULT FALSE,
    INDEX idx_owner (owner_steam_id),
    FOREIGN KEY (owner_steam_id) REFERENCES players(steam_id) ON DELETE SET NULL
) ENGINE=InnoDB;

-- Gangs table
CREATE TABLE IF NOT EXISTS gangs (
    gang_id INT AUTO_INCREMENT PRIMARY KEY,
    gang_name VARCHAR(64) UNIQUE NOT NULL,
    leader_steam_id VARCHAR(17) NOT NULL,
    bank INT DEFAULT 0,
    members TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    INDEX idx_leader (leader_steam_id),
    FOREIGN KEY (leader_steam_id) REFERENCES players(steam_id) ON DELETE CASCADE
) ENGINE=InnoDB;

-- Items table
CREATE TABLE IF NOT EXISTS items (
    item_id INT AUTO_INCREMENT PRIMARY KEY,
    item_name VARCHAR(64) UNIQUE NOT NULL,
    buy_price INT DEFAULT 0,
    sell_price INT DEFAULT 0,
    illegal BOOLEAN DEFAULT FALSE
) ENGINE=InnoDB;

-- Logs table for admin tracking
CREATE TABLE IF NOT EXISTS server_logs (
    log_id INT AUTO_INCREMENT PRIMARY KEY,
    log_type VARCHAR(32) NOT NULL,
    player_steam_id VARCHAR(17),
    message TEXT NOT NULL,
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    INDEX idx_type (log_type),
    INDEX idx_player (player_steam_id),
    INDEX idx_timestamp (timestamp)
) ENGINE=InnoDB;
