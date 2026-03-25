# Rumor Propagation using Cell-DEVS (Cadmium)

## Overview
This project implements a rumor propagation model using the Cell-DEVS formalism in the Cadmium simulation framework. The system models how a rumor spreads across a 2D grid based on local interactions between neighboring cells (Moore neighborhood).

The objective is to simulate and analyze how information propagates spatially under different initial conditions and configurations.

---

## Project Structure


RumorPropagation_CellDEVS/
├── src/ # C++ source files (Cell-DEVS models)
├── model/ # JSON configuration files
├── scripts/ # Data processing scripts
├── logs/ # Simulation outputs (generated after run)
├── viewer/ # Web visualization (D3.js)
├── report/ # Final report document
├── bin/ # Executable files
├── build/ # Build directory
├── RumorPropagation_Assign2/ # Assignment 2 implementation
├── CMakeLists.txt
├── Media1.mp4 # Visualization video
└── README.md


---

## Requirements

- C++17 compatible compiler  
- CMake ≥ 3.16  
- Python 3  
- Web browser  
- Cadmium library (configured in devssim environment)

---

## How to Clone

```bash
git clone https://github.com/baharprh/RumorPropagation_CellDEVS.git
cd RumorPropagation_CellDEVS
git submodule update --init --recursive
How to Build
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

Key Parameters
scenario.shape → grid size
scenario.wrapped → boundary condition
cells.default → default cell behavior
cells.infected → initial rumor sources
Output

After running the simulation, output files are generated in:

logs/
Files
output_messages.txt → simulation messages
state.txt → grid state evolution
Cell States
0 → uninformed
1 → informed
Data Processing

Convert simulation output for visualization:

python3 scripts/convert_state_to_csv.py

This generates:

viewer/data.csv
Visualization
cd viewer
python3 -m http.server 8000

Then open in browser:

http://localhost:8000/index.html

The visualization displays:

Grid evolution over time
Rumor propagation behavior
Interactive timeline
Experimental Variations

You can test different scenarios by modifying:

Grid size
Number of infected cells
Initial cell positions

Example experiments:

Single vs multiple sources
Sparse vs dense propagation
Small vs large grids
Scripts Description

convert_state_to_csv.py:

Reads simulation output (state.txt)
Converts data into CSV format
Generates viewer/data.csv for visualization
Video Demonstration

Media1.mp4 shows the dynamic rumor propagation behavior using the web viewer.

Verification Steps

To verify correctness from a clean setup:

git clone https://github.com/baharprh/RumorPropagation_CellDEVS.git
cd RumorPropagation_CellDEVS
git submodule update --init --recursive

mkdir build
cd build
cmake ..
make

../bin/rumor_sim ../model/rumor_config.json 50
Common Issues
No such file → incorrect path
scenario not found → wrong JSON file
No output generated → simulation not executed correctly
Empty visualization → run conversion script before viewer
Notes
Uses Moore neighborhood (8-connected cells)
Implements Cell-DEVS discrete-event simulation
Behavior is based on local interactions between neighboring cells
References
Cadmium Simulation Framework
Cell-DEVS Formalism
devssim Cell-DEVS Viewer
Final Checklist
Code compiles successfully
Simulation runs without errors
Logs are generated
Visualization works
README provides full instructions
