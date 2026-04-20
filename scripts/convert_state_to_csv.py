import csv
from pathlib import Path

base_dir = Path(__file__).resolve().parent.parent
input_file = base_dir / "viewer" / "data.csv"
output_file = base_dir / "viewer" / "transitions.csv"

rows = []
model_ids = {}
next_id = 1

with input_file.open("r", encoding="utf-8") as f:
    reader = csv.DictReader(f)
    for row in reader:
        time = row["time"]
        x = row["x"]
        y = row["y"]
        state = row["state"]

        model_name = f"({x},{y})"

        if model_name not in model_ids:
            model_ids[model_name] = next_id
            next_id += 1

        model_id = model_ids[model_name]

        rows.append([time, model_id, model_name, "", state])

with output_file.open("w", newline="", encoding="utf-8") as f:
    writer = csv.writer(f, delimiter=";")
    writer.writerow(["sep=;"])
    writer.writerow(["time", "model_id", "model_name", "port_name", "data"])
    writer.writerows(rows)

print(f"Created {output_file}")
