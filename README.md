# Rumor Propagation using Cell-DEVS (Cadmium) 

## Overview

This project implements a rumor propagation model using the Cell-DEVS formalism in the Cadmium simulation framework. The model simulates how a rumor spreads across a 2D grid through local neighborhood interactions.

The repository includes:

- the C++ Cell-DEVS model
- multiple JSON scenario configurations
- scripts for processing simulation outputs
- a restored working viewer based on a generated GIF
- the final report document

---

## Project Structure

- `src/` : C++ source files for the Cell-DEVS model
- `model/` : simulation configurations and model notes
- `scripts/` : helper scripts for post-processing simulation output
- `viewer/` : visualization assets and viewer page
- `report/` : final report document
- `bin/` : compiled executable

---

## Main Files

- `src/main.cpp` : simulation entry point
- `src/rumorCell.hpp` : cell behavior definition
- `src/rumor_coupled.hpp` : coupled grid model
- `model/rumor_config.json` : default simulation configuration
- `viewer/index.html` : visualization page
- `viewer/rumor_propagation.gif` : working animation used by the viewer
- `bin/rumor_sim` : compiled simulation executable

---

## Requirements

- C++17 compatible compiler
- CMake 3.16 or newer
- Python 3
- Web browser
- Cadmium library configured in your environment

---

## Build

From the repository root:

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

The executable is available at:

```bash
./bin/rumor_sim
```

---

## Run the Simulation

From the repository root:

```bash
./bin/rumor_sim ./model/rumor_config.json [MAX_TIME]
```

Example:

```bash
./bin/rumor_sim ./model/rumor_config.json 50
```

Depending on your Cadmium setup, the simulation may generate raw log files such as:

- `logs/state.txt`
- `logs/output_messages.txt`

These raw files are used by the helper scripts in `scripts/`.

---

## Configuration

The main simulation parameters are stored in `model/rumor_config.json`.

Useful fields include:

- `scenario.shape` : grid size as `[rows, cols]`
- `scenario.wrapped` : whether the grid wraps at the edges
- `cells.default` : default state for cells
- `cells.infected` : initial rumor source positions

Additional scenarios are also included in `model/`, such as:

- `rumor_config_1.json`
- `rumor_config_3sources.json`
- `rumor_config_large.json`

---

## Cell States

- `0` : unaware
- `1` : spreading rumor
- `2` : inactive

---

## Visualization

The current working visualization is the restored GIF-based viewer in `viewer/`.

Important files:

- `viewer/index.html`
- `viewer/rumor_propagation.gif`
- `viewer/state_messages.txt`
- `viewer/data.csv`

### Open the Visualization

From the `viewer/` directory:

```bash
python3 -m http.server 8080
```

Then open:

```text
http://127.0.0.1:8080/index.html
```

Notes:

- `8080` is recommended because port `8000` may already be in use on your machine.
- If you are already inside the `viewer/` folder, do not run `cd viewer` again.
- The viewer displays `viewer/rumor_propagation.gif`, so it can be opened reliably through the browser without depending on external JavaScript libraries.

### If Port 8080 Is Busy

Try another port:

```bash
python3 -m http.server 8090
```

Then open:

```text
http://127.0.0.1:8090/index.html
```

---

## Included Viewer Assets

Pre-generated visualization assets are already included in this repository:

- `viewer/rumor_propagation.gif`
- `viewer/state_messages.txt`
- `viewer/data.csv`

This means you can open the visualization immediately without rerunning the full simulation first.

---

## Helper Scripts

The repository includes helper scripts in `scripts/` for post-processing simulation outputs:

- `scripts/convert_state_to_csv.py`
- `scripts/make_messages_log.py`
- `scripts/make_rumor_animation.py`
- `scripts/run_rumor_default.sh`
- `scripts/run_rumor_single_source.sh`
- `scripts/run_rumor_three_sources.sh`
- `scripts/run_rumor_large_grid.sh`

These scripts are intended to process raw simulation logs, generate viewer assets, and run the main experimental configurations included in the repository.

### Run Scripts

From the repository root, the supported experiment scripts are:

```bash
./scripts/run_rumor_default.sh
./scripts/run_rumor_single_source.sh
./scripts/run_rumor_three_sources.sh
./scripts/run_rumor_large_grid.sh
```

These scripts were verified against the current repository layout and run the following scenarios:

- `run_rumor_default.sh` : default 30x30 rumor propagation setup
- `run_rumor_single_source.sh` : 20x20 grid with one initial source
- `run_rumor_three_sources.sh` : 20x20 grid with three initial sources
- `run_rumor_large_grid.sh` : larger 30x30 scenario using the alternate configuration file

Each script runs `bin/rumor_sim` with a different configuration file from `model/`.

---

## Report and Video

The final report is available at:

- `report/Rumor_Propagation_CellDEVS_Final_Report.docx`

The visualization video is available at:

- `rumor_propagation_visualization.mp4`

---

## Submission Note

One manual submission item still needs to be checked before final delivery:

- include the required `DEVSmodelsForm` file if it has not yet been added to the repository

---

## Notes

- The model uses local neighborhood interactions on a 2D grid.
- Different rumor-spread scenarios can be tested by changing the JSON configuration.
- The current restored viewer is based on the generated GIF asset, because that is the workflow confirmed to work reliably in this repository.
