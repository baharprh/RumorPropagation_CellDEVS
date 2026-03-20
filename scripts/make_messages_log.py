import re
from pathlib import Path

input_file = Path("logs/output_messages.txt")
output_file = Path("viewer/messages.log")

time_pattern = re.compile(r"^\s*(\d+)\s*$")
msg_pattern = re.compile(r"\{\((\d+),(\d+)\)\s*;\s*(\d+)\}")

current_time = None
out_lines = []

with input_file.open("r", encoding="utf-8") as f:
    for raw in f:
        line = raw.strip()

        tm = time_pattern.match(line)
        if tm:
            current_time = tm.group(1)
            continue

        mm = msg_pattern.search(line)
        if mm and current_time is not None:
            x, y, state = mm.groups()
            out_lines.append(f"{current_time} ({x},{y}) {state}")

with output_file.open("w", encoding="utf-8") as f:
    for row in out_lines:
        f.write(row + "\n")

print("DONE: messages.log fixed for viewer")