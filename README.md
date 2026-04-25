# Rumor Propagation using Cell-DEVS (Cadmium)

## Overview

This project implements a rumor propagation model using the Cell-DEVS formalism in the Cadmium simulation framework. The model simulates how a rumor spreads across a 2D grid through local neighborhood interactions.

The repository includes:

- C++ Cell-DEVS model implementation
- Multiple simulation scenarios (JSON configurations)
- Experiment scripts
- Simulation logs
- Visualization assets (Cell-DEVS viewer compatible)
- Final report and video

---

## Project Structure

- `src/` : C++ source files for the Cell-DEVS model  
- `model/` : simulation configurations  
- `scripts/` : experiment execution scripts  
- `logs/` : simulation output logs (per experiment)  
- `viewer/` : visualization files for Cell-DEVS viewer  
- `report/` : final report document  
- `bin/` : compiled executable  

---

## Build Instructions

From the repository root:

```bash
mkdir -p build
cd build
cmake ..
cmake --build .

cd ..
```
## Executable will be available at:
After building, the executable will be available at:
./bin/rumor_sim

## Running the Simulation

General command:

./bin/rumor_sim ./model/rumor_config.json [MAX_TIME]

Example:

./bin/rumor_sim ./model/rumor_config.json 50
Experiment Scripts

## Experiment Scripts
The following scripts are provided to execute different simulation scenarios:

bash scripts/run_rumor_default.sh
bash scripts/run_rumor_single_source.sh
bash scripts/run_rumor_three_sources.sh
bash scripts/run_rumor_large_grid.sh

Each script runs the simulator with a different configuration:

Script	Description
run_rumor_default.sh : Default 30x30 scenario
run_rumor_single_source.sh : Single initial infected cell
run_rumor_three_sources.sh : Three initial infected cells
run_rumor_large_grid.sh : Larger grid simulation

## Logs (Simulation Results)

Simulation outputs are generated as CSV files inside the viewer/ directory.

For each experiment, the file viewer/grid_log.csv is copied into the logs/ directory to create preserved experiment logs:

logs/default_run.log	Default scenario results
logs/single_source_run.log	Single-source scenario
logs/three_sources_run.log	Three-source scenario
logs/large_grid_run.log	Large-grid scenario

Each log file contains the full state evolution of the grid over time.

This ensures:

execution logs are preserved
experiments are reproducible
results can be independently verified

## Configuration Files
Located in model/:

rumor_config.json (default)
rumor_config_1.json
rumor_config_3sources.json
rumor_config_large.json

Main parameters:

scenario.shape : grid size
scenario.wrapped : boundary condition
cells.infected : initial rumor sources

## Cell States
0 → unaware
1 → spreading rumor
2 → inactive

## Visualization
Simulation results can be visualized using the provided local web-based viewer and generated animation assets.

Relevant files:

viewer/index.html
viewer/simulation.json
viewer/transitions.csv
viewer/rumor_propagation.gif
viewer/state_messages.txt

Run local viewer:

cd viewer
python3 -m http.server 8080

Then open in browser:

http://127.0.0.1:8080/index.html

This page displays the generated rumor propagation GIF animation and also provides direct access to the corresponding CSV transition log and state message files.

## Included Assets

Pre-generated outputs are included:

viewer/grid_log.csv
viewer/data.csv
viewer/state_messages.txt
rumor_propagation_visualization.mp4
Report and Video

## ## Report, DEVS Form, and Visualization Media:
Report:
report/Rumor_Propagation_CellDEVS_Final_Report.docx

DEVS Model Form:
report/DEVSmodelsForm.doc

Video:
rumor_propagation_visualization.mp4

## Reproducibility
To fully reproduce results:

bash scripts/run_rumor_default.sh
bash scripts/run_rumor_single_source.sh
bash scripts/run_rumor_three_sources.sh
bash scripts/run_rumor_large_grid.sh

Then verify generated logs:
ls logs
The generated visualization can then be inspected locally through the viewer/ web page or through the included animation media.
