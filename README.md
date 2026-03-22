# Rumor Propagation using Cell-DEVS (Cadmium)

## Overview
This project implements a rumor propagation model using the Cell-DEVS formalism in the Cadmium simulation framework. The system models how a rumor spreads across a 2D grid based on local interactions between neighboring cells.

## Project Structure
- `src/` : C++ source files for the Cell-DEVS model
- `model/` : JSON configuration files (initial conditions and parameters)
- `scripts/` : scripts for processing logs and generating visualization data
- `logs/` : simulation output files
- `viewer/` : web-based visualization (D3.js)
- `report/` : final report document
- `bin/` : compiled executables
- `RumorPropagation_Assign2/` : Assignment 2 subfolder with its own simulation

## Main Files
- `src/main.cpp` : simulation entry point
- `src/rumorCell.hpp` : atomic Cell-DEVS model (cell behavior)
- `src/rumor_coupled.hpp` : coupled grid model
- `model/rumor_config.json` : simulation configuration
- `viewer/index.html` : visualization interface
- `bin/rumor_sim` : compiled simulation executable

---

## Requirements
- C++ compiler (C++17 or later)
- CMake 3.16+
- Python 3
- Web browser
- Cadmium library (CADMIUM environment variable must be set)

---

## How to Build

```bash
# From the project root directory
mkdir build
cd build
cmake ..
cmake --build .
```

The executable will be created at: `./bin/rumor_sim`

---

## How to Run

### Main Project
```bash
./bin/rumor_sim ./model/rumor_config.json [MAX_TIME]
```

Example:
```bash
./bin/rumor_sim ./model/rumor_config.json 50
```

This will generate output logs in the `logs/` folder:
- `output_messages.txt` : detailed simulation messages
- `state.txt` : cell states over time

### Assignment 2
```bash
cd RumorPropagation_Assign2
./bin/rumor_sim ./model/rumor_config.json [MAX_TIME]
```

---

## Configuration

The `model/rumor_config.json` file controls the simulation parameters:
- `scenario.shape` : grid dimensions [rows, cols]
- `scenario.wrapped` : whether grid wraps at edges (true/false)
- `cells.default` : default cell configuration
- `cells.infected` : infected/seed cells initial positions

Example configuration:
```json
{
  "scenario": {
    "shape": [30, 30],
    "wrapped": false
  },
  "cells": {
    "default": {
      "delay": "inertial",
      "cell_type": "rumor",
      "state": { "state": 0 },
      "neighborhood": [
        {
          "type": "moore",
          "range": 1,
          "vicinity": 1
        }
      ]
    },
    "infected": {
      "state": { "state": 1 },
      "cell_map": [[7, 7], [15, 15], [22, 22]]
    }
  }
}
```

---

## Output

Simulation generates two output files in `logs/`:
- **output_messages.txt** : timestamped messages and state transitions
- **state.txt** : complete state snapshots at each time step

Cell states:
- `0` : uninformed (no rumor)
- `1` : informed/infected (has rumor)

---

## Data Processing

To generate CSV data for visualization:
```bash
python3 scripts/convert_state_to_csv.py
```

This creates `viewer/data.csv` with formatted data for the web viewer.

---

## Web Visualization

View the simulation results in a web browser:
```bash
cd viewer
python3 -m http.server 8000
```

Then open your browser and navigate to: `http://localhost:8000/index.html`

The visualization displays:
- **Grid of cells** colored by state (rumor spread over time)
- **Timeline controls** to step through the simulation
- **Real-time state updates** as the rumor propagates

**Note:** Pre-generated visualization data is included in `viewer/data.csv`

---

## Notes
- The simulation uses Moore neighborhood (8-connected cells)
- Rumor propagation is based on local interactions between neighboring cells
- Different initial conditions can be tested by modifying `model/rumor_config.json`
- Maximum simulation time can be specified as a command-line argument

---

## References
- Cadmium Library: Cell-DEVS simulation framework
- Cell-DEVS: Discrete Event Modeling of continuous/discrete systems
