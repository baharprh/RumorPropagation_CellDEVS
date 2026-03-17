import re
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter
from pathlib import Path

# Paths
base_dir = Path(__file__).resolve().parent.parent
input_file = base_dir / "logs" / "state.txt"
output_file = base_dir / "viewer" / "rumor_propagation.gif"

# Regex patterns
time_pattern = re.compile(r"^\s*([0-9]+(?:\.[0-9]+)?)\s*$")
state_pattern = re.compile(r"State for model .*_\((\d+),(\d+)\) is (\d+)")

frames = {}
current_time = None
max_x = 0
max_y = 0

# Read log file
with input_file.open("r", encoding="utf-8") as f:
    for line in f:
        line = line.strip()

        if not line:
            continue

        tmatch = time_pattern.match(line)
        if tmatch:
            current_time = float(tmatch.group(1))
            if current_time not in frames:
                frames[current_time] = {}
            continue

        smatch = state_pattern.search(line)
        if smatch and current_time is not None:
            x = int(smatch.group(1))
            y = int(smatch.group(2))
            state = int(smatch.group(3))

            frames[current_time][(x, y)] = state

            max_x = max(max_x, x)
            max_y = max(max_y, y)

# Build grids
times = sorted(frames.keys())
grids = []

for t in times:
    grid = np.zeros((max_y + 1, max_x + 1))

    for (x, y), state in frames[t].items():
        grid[max_y - y, x] = state

    grids.append(grid)

# Plot
fig, ax = plt.subplots(figsize=(6,6))
im = ax.imshow(grids[0], cmap="viridis", vmin=0, vmax=2)

ax.set_title(f"Rumor Propagation t={times[0]}")
ax.set_xlabel("X")
ax.set_ylabel("Y")

def update(frame):
    im.set_data(grids[frame])
    ax.set_title(f"Rumor Propagation t={times[frame]}")
    return [im]

ani = FuncAnimation(fig, update, frames=len(grids), interval=300)

# Save animation
output_file.parent.mkdir(parents=True, exist_ok=True)
ani.save(output_file, writer=PillowWriter(fps=3))

print("Animation saved to:", output_file)
