import csv
import re
from pathlib import Path

base_dir = Path(__file__).resolve().parent.parent
input_file = base_dir / "logs" / "state.txt"
output_file = base_dir / "viewer" / "rumor_viewer_log.csv"

time_pattern = re.compile(r"^\s*([0-9]+(?:\.[0-9]+)?)\s*$")
state_pattern = re.compile(r"State for model .*_\((\d+),(\d+)\) is (\d+)")

rows = []
current_time = None
model_ids = {}
next_id = 1

with input_file.open("r", encoding="utf-8") as f:
    for line in f:
        line = line.strip()
        if not line:
            continue

        tmatch = time_pattern.match(line)
        if tmatch:
            current_time = float(tmatch.group(1))
            continue

        smatch = state_pattern.search(line)
        if smatch and current_time is not None:
            x = int(smatch.group(1))
            y = int(smatch.group(2))
            state = int(smatch.group(3))

            model_name = f"({x},{y})"
            if model_name not in model_ids:
                model_ids[model_name] = next_id
                next_id += 1

            model_id = model_ids[model_name]

            # Viewer-style row
            rows.append([current_time, model_id, model_name, "", f"<{state}>"])

output_file.parent.mkdir(parents=True, exist_ok=True)

with output_file.open("w", newline="", encoding="utf-8") as f:
    writer = csv.writer(f, delimiter=";")
    writer.writerow(["sep=;"])
    writer.writerow(["time", "model_id", "model_name", "port_name", "data"])
    writer.writerows(rows)

print(f"Wrote {len(rows)} rows to {output_file}")
