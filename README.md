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
After building, the executable will be available at:
```bash
./bin/rumor_sim
```
To check that the executable was created, run:
```bash
ls bin
```
You should see:
```bash
rumor_sim
```
## Running the Simulation

General command:
```bash

./bin/rumor_sim ./model/rumor_config.json [MAX_TIME]
```
Example:
```bash
./bin/rumor_sim ./model/rumor_config.json 50
```

## Experiment Scripts
The following scripts are provided to execute different simulation scenarios:
```bash
bash scripts/run_rumor_default.sh
bash scripts/run_rumor_single_source.sh
bash scripts/run_rumor_three_sources.sh
bash scripts/run_rumor_large_grid.sh
```

Each script runs one experiment:

| Command | Description |
|---|---|
| `bash scripts/run_rumor_default.sh` | Runs the default 30x30 rumor propagation scenario. |
| `bash scripts/run_rumor_single_source.sh` | Runs the scenario with one initial infected cell. |
| `bash scripts/run_rumor_three_sources.sh` | Runs the scenario with three initial infected cells. |
| `bash scripts/run_rumor_large_grid.sh` | Runs the larger-grid rumor propagation scenario. |

## Logs and Simulation Results

The simulation produces output files that are preserved in the logs/ directory.
After running the experiment scripts, the following log files should be created:

For each experiment, the file viewer/grid_log.csv is copied into the logs/ directory to create preserved experiment logs:
After running the experiment scripts, the following log files are generated:

| Log File | Description |
|---|---|
| `logs/default_run.log` | Contains the results of the default 30x30 rumor propagation scenario. |
| `logs/single_source_run.log` | Contains the results of the scenario with one initial infected cell. |
| `logs/three_sources_run.log` | Contains the results of the scenario with three initial infected cells. |
| `logs/large_grid_run.log` | Contains the results of the larger-grid rumor propagation scenario. |

To verify the generated logs, run:
```bash
ls logs
```
Each log file contains the state evolution of the grid over time and can be used to verify the simulation results.

## Configuration Files
The configuration files are located in the model/ directory:

- ` rumor_config.json (default)`
- ` rumor_config_1.json`
- ` rumor_config_3sources.json`
- ` rumor_config_large.json`

The main configuration parameters include:

- ` scenario.shape : grid size`
- ` scenario.wrapped : boundary condition`
- ` cells.infected : initial rumor sources`

## Cell States
The model uses the following cell states:

| State Value | Cell Meaning |
|---|---|
| `0` | Unaware cell. The cell has not received the rumor yet. |
| `1` | Spreading cell. The cell currently has the rumor and can spread it to neighboring cells. |
| `2` | Inactive cell. The cell has already received the rumor but is no longer spreading it. |

## Visualization
Simulation results can be visualized using the provided local web-based viewer and generated animation assets.

Relevant files:

- `viewer/index.html` is the local web page used to display the rumor propagation visualization.
- `viewer/simulation.json` contains the viewer configuration settings.
- `viewer/transitions.csv` contains the transition data used by the viewer.
- `viewer/rumor_propagation.gif` is the generated animation of the rumor propagation process.
- `viewer/state_messages.txt` contains the state messages generated during the simulation.

Run local viewer:
```bash
cd viewer
python3 -m http.server 8080
```
Then open in browser:

```bash
http://127.0.0.1:8080/index.html
```
This page displays the generated rumor propagation GIF animation and also provides direct access to the corresponding CSV transition log and state message files.

## Included Assets

Pre-generated outputs are included:

- `viewer/grid_log.csv`
- `viewer/data.csv`
- `viewer/state_messages.txt`
- `rumor_propagation_visualization.mp4`
- `Report and Video`

## ## Report, DEVS Form, and Visualization Media:
Report:
report/Rumor_Propagation_CellDEVS_Final_Report.docx

DEVS Model Form:
report/DEVSmodelsForm.doc

Video:
rumor_propagation_visualization.mp4

## Reproducibility
To fully reproduce results:
```bash
bash scripts/run_rumor_default.sh
bash scripts/run_rumor_single_source.sh
bash scripts/run_rumor_three_sources.sh
bash scripts/run_rumor_large_grid.sh
```

Then verify generated logs:

```bash
ls logs
```

The generated visualization can then be inspected locally through the viewer/ web page or through the included animation media.
