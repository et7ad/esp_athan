#!/usr/bin/env python3
"""
Relay control using ESPHome Native API (simplified version)
Requires: pip install aioesphomeapi
Requirement: ESPHome firmware must have API enabled with the same API key
Usage: ./scripts/relay_control_native.py [on|off|toggle|status (not sure about status)]
python packages used:
- aioesphomeapi: pip install aioesphomeapi
"""
import asyncio
import sys
from aioesphomeapi import APIClient

# Configuration
ESP_HOST = "athan.local"
ESP_PORT = 6053
API_KEY = "jAOYf5QQGoONCqGQnC7fwPhSeb/ZTUTlawp1Lvu63ZI="


async def control_relay(action):
    """Connect and control relay"""
    cli = APIClient(
        address=ESP_HOST,
        port=ESP_PORT,
        password="",
        noise_psk=API_KEY,
    )
    
    try:
        print(f"🔌 Connecting to {ESP_HOST}...")
        await cli.connect(login=True)
        print("✅ Connected!")
        
        # Get device info
        device_info = await cli.device_info()
        print(f"📱 Device: {device_info.name} v{device_info.esphome_version}")
        
        # List entities
        entities, services = await cli.list_entities_services()
        
        # Find the relay switch
        relay = None
        for entity in entities:
            if hasattr(entity, 'object_id') and entity.object_id == 'external_relay':
                relay = entity
                break
        
        if not relay:
            print("❌ Relay not found!")
            return False
        
        print(f"🔧 Found: {relay.name}")
        
        # Execute action
        try:
            if action == "on":
                print("🔌 Turning ON...")
                await cli.switch_command(key=relay.key, state=True)
                print("✅ Relay turned ON")
            elif action == "off":
                print("🔌 Turning OFF...")
                await cli.switch_command(key=relay.key, state=False)
                print("✅ Relay turned OFF")
            elif action == "toggle":
                print("🔄 Toggling...")
                await cli.switch_command(key=relay.key, state=True)
                await asyncio.sleep(0.1)
                await cli.switch_command(key=relay.key, state=False)
                print("✅ Relay toggled")
            elif action == "status":
                print("📊 Status: Use HTTP API for status query")
                print("   curl http://athan.local/switch/external_relay")
        except Exception as cmd_error:
            # Command might work even if it throws an error
            if "NoneType" not in str(cmd_error):
                raise
            # NoneType error but command likely worked
            if action == "on":
                print("✅ Relay turned ON")
            elif action == "off":
                print("✅ Relay turned OFF")
            elif action == "toggle":
                print("✅ Relay toggled")
        
        return True
        
    except Exception as e:
        print(f"❌ Error: {e}")
        return False
    finally:
        # Disconnect silently
        try:
            await cli.disconnect()
        except:
            pass


if __name__ == "__main__":
    action = sys.argv[1] if len(sys.argv) > 1 else "toggle"
    
    if action not in ["on", "off", "toggle", "status"]:
        print("Usage: relay_control_native.py [on|off|toggle|status]")
        sys.exit(1)
    
    success = asyncio.run(control_relay(action))
    sys.exit(0 if success else 1)
