#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN_PATH="$ROOT_DIR/bin/rumor_sim"
CONFIG_PATH="$ROOT_DIR/model/rumor_config_large.json"
LOG_PATH="$ROOT_DIR/logs/large_grid_run.log"

mkdir -p "$ROOT_DIR/logs"

if [[ ! -x "$BIN_PATH" ]]; then
  echo "Missing executable: $BIN_PATH"
  echo "Build the project first with:"
  echo "  mkdir -p build && cd build && cmake .. && cmake --build ."
  exit 1
fi

echo "Running large-grid rumor propagation scenario..."
"$BIN_PATH" "$CONFIG_PATH" | tee "$LOG_PATH"

echo "Log saved to: $LOG_PATH"
