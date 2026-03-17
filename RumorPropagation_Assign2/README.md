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
- `rumor_simulation.mp4` : recorded simulation video

## Main Files
- `src/main.cpp` : simulation entry point
- `src/rumorCell.hpp` : atomic Cell-DEVS model (cell behavior)
- `src/rumor_coupled.hpp` : coupled grid model
- `model/rumor_config.json` : simulation configuration
- `viewer/index.html` : visualization interface
- `viewer/data.csv` : processed simulation data

---

## How to Run

### 1. Build the project
mkdir build
cd build
cmake ..
cmake --build .

### 2. Run the simulation
./main

This will generate output logs in the `logs/` folder.

---

### 3. Generate visualization data
python scripts/convert_state_to_csv.py

This creates:
viewer/data.csv

---

### 4. Run the web viewer

cd viewer
python -m http.server 8000

Open in browser:
http://localhost:8000/viewer/index.html

---

## Output

- Grid-based visualization of rumor spread over time
- Color-coded states:
  - Yellow: uninformed
  - Blue: informed
  - Red: active rumor spreaders

---

## Notes
- The simulation is based on local interactions between neighboring cells.
- Different initial conditions can be tested by modifying `rumor_config.json`.

---

## Requirements
- C++ compiler
- CMake
- Python 3
- Web browser