# Rumor Propagation using Cell-DEVS (Cadmium)

## 1. Project Overview

This project implements a **rumor propagation model** using the **Cell-DEVS formalism** within the **Cadmium simulation framework**.

The system represents how information (rumor) spreads across a **2D grid** through **local interactions between neighboring cells (Moore neighborhood)**.

This project satisfies the requirements of **SYSC 5104 – Assignment 2**, including:
- Cell-DEVS modeling
- Cadmium implementation
- Experimental simulation
- Visualization using the Web Viewer
- Video demonstration

---

## 2. Conceptual Model

The system models a population where each individual is represented as a cell in a 2D grid.

Each cell can be in one of the following states:

| State | Meaning |
|------|--------|
| 0 | Uninformed |
| 1 | Informed (has the rumor) |

### Behavior:
- A cell becomes **informed** if at least one of its neighbors is informed.
- The model uses a **Moore neighborhood (8 neighbors)**.
- The rumor spreads step-by-step over time.

---

## 3. Formal Cell-DEVS Specification

Each cell is defined as:

- **State (S):** {0, 1}
- **Neighborhood:** Moore (8 adjacent cells)
- **Local Transition Function:**



**Local Transition Function:**
```text
if any neighbor == 1:
    next_state = 1
else:
    next_state = current_state
```
- **Delay:** 1 simulation step

## 4. Project Structure


RumorPropagation_CellDEVS/
├── src/ # Cell-DEVS C++ models
├── model/ # JSON configuration files
├── scripts/ # Data processing scripts
├── logs/ # Simulation outputs
├── viewer/ # Web visualization
├── report/ # Final report
├── bin/ # Executables
├── build/ # Build directory
├── RumorPropagation_Assign2/ # Assignment implementation
└── README.md
---

## 5. Requirements

- C++17 compatible compiler  
- CMake ≥ 3.16  
- Python 3  
- Web browser  
- Cadmium library (included via submodule)

---

## 6. How to clone

```bash
git clone https://github.com/baharprh/RumorPropagation_CellDEVS.git
cd RumorPropagation_CellDEVS
git submodule update --init --recursive
```
## 7. How to Build

```bash
rm -rf build
mkdir build
cd build
cmake ..
make
```

## 8. How to Run
```bash
cd build
../bin/rumor_sim ../model/rumor_config.json 50
```
## 9. Experimental Framework

The simulation behavior is controlled using:

`model/rumor_config.json`

### Key Parameters:

- `scenario.shape` → grid size  
- `scenario.wrapped` → boundary condition  
- `cells.infected` → initial rumor sources  

This enables evaluation of the model under different initial conditions and validates the propagation behavior.
## 10. Output Files

After simulation:

logs/

Generated files:

output_messages.txt → simulation messages
state.txt → grid evolution
## 11. Data Processing

Convert simulation output to visualization format:

python3 scripts/convert_state_to_csv.py

This generates:

viewer/data.csv
## 12. Visualization (REQUIRED)

Start local server:

cd viewer
python3 -m http.server 8000

Open in browser:

http://localhost:8000/index.html

✔ This step is MANDATORY for grading (prof will check this)

## 13. Video Demonstration

The file:

Media1.mp4

demonstrates the rumor propagation behavior using the Web Viewer.

## 14. Experimental Variations

Different scenarios tested:

Single vs multiple rumor sources
Small vs large grids
Sparse vs dense initialization

These variations demonstrate system behavior under different conditions.

## 15. Scripts Description

### convert_state_to_csv.py

This script:
- Reads simulation output (`state.txt`)
- Converts it into CSV format
- Generates `viewer/data.csv` for visualization in the Web Viewer
## 16. Verification (IMPORTANT FOR PROF)

To verify correctness from a clean environment:

git clone https://github.com/baharprh/RumorPropagation_CellDEVS.git
cd RumorPropagation_CellDEVS
git submodule update --init --recursive

mkdir build
cd build
cmake ..
make

../bin/rumor_sim ../model/rumor_config.json 50

✔ If this works → project is correct

## 17. Common Issues

| Issue | Solution |
|------|--------|
| File not found | Check paths |
| JSON error | Validate config file |
| No output | Ensure simulation runs |
| Empty viewer | Run conversion script |
## 18. Key Features

- Cell-DEVS discrete-event simulation  
- Local interaction modeling  
- Scalable grid-based system  
- Visualization using Web Viewer  
- Fully reproducible simulation  
## 19. References

- Cadmium Simulation Framework  
- Cell-DEVS Formalism  
- https://devssim.carleton.ca/cell-devs-viewer/
