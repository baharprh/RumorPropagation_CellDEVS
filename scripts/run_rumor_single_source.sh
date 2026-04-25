#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN_PATH="$ROOT_DIR/bin/rumor_sim"
CONFIG_PATH="$ROOT_DIR/model/rumor_config_1.json"
LOG_PATH="$ROOT_DIR/logs/single_source_run.log"
VIEWER_LOG="$ROOT_DIR/viewer/transitions.csv"

mkdir -p "$ROOT_DIR/logs"

if [[ ! -x "$BIN_PATH" ]]; then
  echo "Missing executable: $BIN_PATH"
  echo "Build the project first with:"
  echo "  mkdir -p build && cd build && cmake .. && cmake --build ."
  exit 1
fi

echo "Running single-source rumor propagation scenario..."
"$BIN_PATH" "$CONFIG_PATH" 50

if [[ -f "$VIEWER_LOG" ]]; then
  cp "$VIEWER_LOG" "$LOG_PATH"
  echo "Log saved to: $LOG_PATH"
else
  echo "Error: expected viewer log not found: $VIEWER_LOG"
  exit 1
fi