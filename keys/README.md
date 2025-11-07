# Server Keys

This directory contains BattlEye signature keys for mod verification.

## Purpose

Keys are used to verify the authenticity of addon files (PBO files) to prevent:
- Modified or hacked content
- Unauthorized addons
- Cheating tools

## Usage

1. When you install a mod, copy its `.bikey` file to this directory
2. Configure `server.cfg` with `verifySignatures = 2` to enforce signature checking
3. Players must have the same signed mods to connect

## Key Management

- Keep this directory organized
- Remove keys for mods that are no longer in use
- Regularly update keys when mods are updated

## Notes

- BattlEye keys typically have `.bikey` extension
- Each mod usually provides its own key file
- Server will not start if signature verification fails for loaded mods
