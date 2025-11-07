# Server Logs

This directory contains server logs and BattlEye logs.

## Log Files

### server.log
Main server log containing:
- Server startup information
- Player connections/disconnections
- Mission loading events
- Errors and warnings

### BattlEye Logs
BattlEye anti-cheat logs (if enabled):
- `bans.txt` - Banned players
- `beserver.log` - BattlEye server log
- `scripts.log` - Script restriction violations

## Log Rotation

Recommended to implement log rotation to prevent disk space issues:
```bash
# Example logrotate config
/path/to/logs/*.log {
    daily
    rotate 7
    compress
    missingok
    notifempty
}
```

## Monitoring

Monitor logs for:
- Connection issues
- Performance problems
- Security violations
- Player reports

## Notes

- Logs can grow large over time - implement rotation
- Review logs regularly for issues
- Keep logs for debugging and admin purposes
- Consider using log analysis tools for large servers
