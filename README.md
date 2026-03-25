Rumor Propagation using Cell-DEVS (Cadmium)
 Overview

This project implements a rumor propagation model using the Cell-DEVS formalism in the Cadmium simulation framework. The system models how a rumor spreads across a 2D grid based on local interactions between neighboring cells (Moore neighborhood).

The objective is to simulate and analyze how information propagates spatially under different initial conditions and configurations.

Project Structure
RumorPropagation_CellDEVS/
│
├── src/                # C++ source files (Cell-DEVS models)
├── model/              # JSON configuration files
├── scripts/            # Data processing scripts
├── logs/               # Simulation outputs
├── viewer/             # Web visualization (D3.js)
├── report/             # Final report
├── bin/                # Executable files
├── build/              # Build directory
├── RumorPropagation_Assign2/  # Assignment 2 implementation
└── README.md
⚙️ Requirements
C++17 compatible compiler
CMake ≥ 3.16
Python 3
Web browser
Cadmium library (environment configured in devssim)
 How to Clone
git clone https://github.com/baharprh/RumorPropagation_CellDEVS.git
cd RumorPropagation_CellDEVS
git submodule update --init --recursive
🛠️ How to Build
Clean Build (Recommended)
rm -rf build
mkdir build
cd build
cmake ..
make

Executable will be generated at:

./bin/rumor_sim
 How to Run
 Main Project
cd build
../bin/rumor_sim ../model/rumor_config.json 50
 Assignment 2
cd RumorPropagation_Assign2
mkdir -p build
cd build
cmake ..
make
../bin/rumor_sim ../model/rumor_config.json 50
 Configuration

The file:

model/rumor_config.json

controls the simulation.

Key Parameters:
Parameter	Description
scenario.shape	Grid size [rows, cols]
scenario.wrapped	Boundary condition
cells.default	Default cell behavior
cells.infected	Initial rumor sources
 Example Configuration
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
 Output

After running simulation, output files are generated in:

logs/
Files:
output_messages.txt → simulation events
state.txt → grid state evolution
Cell States:
Value	Meaning
0	Uninformed
1	Informed
 Data Processing

Convert simulation output for visualization:

python3 scripts/convert_state_to_csv.py

This generates:

viewer/data.csv
 Visualization
cd viewer
python3 -m http.server 8000

Then open:

http://localhost:8000/index.html
Features:
Grid visualization
Time-step animation
Rumor spread evolution
 Experimental Variations

You can test different scenarios by modifying:

Grid size (e.g., 20×20, 50×50)
Number of initial infected cells
Cell positions

Example experiments:

Single source vs multiple sources
Sparse vs dense infection
Small vs large grid
 Scripts Description
scripts/convert_state_to_csv.py
Reads state.txt
Converts simulation data into CSV format
Generates viewer/data.csv
Used for visualization in browser
 Video Demonstration
Media1.mp4 shows visualization of rumor propagation
Demonstrates dynamic behavior of the model
 Verification Steps (IMPORTANT)

To ensure correct execution:

git clone https://github.com/baharprh/RumorPropagation_CellDEVS.git
cd RumorPropagation_CellDEVS
git submodule update --init --recursive

mkdir build
cd build
cmake ..
make

../bin/rumor_sim ../model/rumor_config.json 50

Then:

cd ..
python3 scripts/convert_state_to_csv.py
cd viewer
python3 -m http.server 8000
