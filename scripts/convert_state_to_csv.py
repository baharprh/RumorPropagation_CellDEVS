from pathlib import Path

base_dir = Path(__file__).resolve().parent.parent
input_file = base_dir / "viewer" / "data.csv"
output_file = base_dir / "viewer" / "grid_log.csv"

with input_file.open("r", encoding="utf-8") as fin:
    lines = fin.readlines()

with output_file.open("w", encoding="utf-8") as fout:
    for line in lines:
        line = line.strip()
        if not line:
            continue
        if line.lower().startswith("time,"):
            continue
        fout.write(line + "\n")

print(f"Created {output_file}")
