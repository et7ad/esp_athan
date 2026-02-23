#!/bin/bash
# Quick relay control script for ESP athan device
# Usage: ./relay_control.sh [on|off|toggle|status]
# Requirement: ESPHome firmware must have web server enabled (webserver:)
# Alternatively, this can be done through alias in terminal through adding the following lines to ~/.zshrc or ~/.bash_profile:
# alias relay='curl -f -m 10 "http://athan.local/switch/external_relay/toggle" -s && echo "✅ Toggled"'
# alias relay-on='curl -f -m 10 "http://athan.local/switch/external_relay/turn_on" -s && echo "✅ ON"'
# alias relay-off='curl -f -m 10 "http://athan.local/switch/external_relay/turn_off" -s && echo "✅ OFF"'

# ========== CONFIGURATION ==========
ESP_IP="athan.local"  # Change to your ESP's IP address if .local doesn't work (e.g., "192.168.1.100")
ESP_PASSWORD="jAOYf5QQGoONCqGQnC7fwPhSeb/ZTUTlawp1Lvu63ZI="
ENTITY_ID="external_relay"
# ===================================

ACTION="${1:-toggle}"

case "$ACTION" in
    on)
        echo "🔌 Turning relay ON..."
        if curl -f -m 10 "http://${ESP_IP}/switch/${ENTITY_ID}/turn_on" -s; then
            echo "✅ Relay turned ON"
        else
            echo "❌ Failed to connect to ESP"
            exit 1
        fi
        ;;
    off)
        echo "🔌 Turning relay OFF..."
        if curl -f -m 10 "http://${ESP_IP}/switch/${ENTITY_ID}/turn_off" -s; then
            echo "✅ Relay turned OFF"
        else
            echo "❌ Failed to connect to ESP"
            exit 1
        fi
        ;;
    toggle)
        echo "🔌 Toggling relay..."
        if curl -f -m 10 "http://${ESP_IP}/switch/${ENTITY_ID}/toggle" -s; then
            echo "✅ Relay toggled"
        else
            echo "❌ Failed to connect to ESP"
            exit 1
        fi
        ;;
    status)
        echo "🔍 Checking relay status..."
        RESPONSE=$(curl -f -m 10 "http://${ESP_IP}/switch/${ENTITY_ID}" -s 2>&1)
        if [ $? -eq 0 ]; then
            if [ -n "$RESPONSE" ]; then
                echo "$RESPONSE" | python3 -m json.tool 2>/dev/null || echo "$RESPONSE"
            else
                echo "⚠️  ESP returned empty response (relay state cannot be queried via HTTP)"
            fi
        else
            echo "❌ Failed to connect to ESP"
            exit 1
        fi
        ;;
    *)
        echo "Usage: $0 [on|off|toggle|status]"
        echo "  on     - Turn relay ON"
        echo "  off    - Turn relay OFF"
        echo "  toggle - Toggle relay state (default)"
        echo "  status - Check current relay status"
        exit 1
        ;;
esac
