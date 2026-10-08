"""Compile separately with make; exercise representative console behavior."""
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]
CASES = [('1\n100\nSample Account\n100\n2\n100\n25\n3\n100\n10\n6\n4\n100\n6\n0\n', 'balance: $115'), ('0\n', 'Goodbye.')]
for input_text, expected in CASES:
    result = subprocess.run([str(ROOT / "build/example")], input=input_text,
                            text=True, capture_output=True, timeout=5, check=True)
    assert expected in result.stdout, f"Expected {expected!r} in output: {result.stdout}"
print(f"Passed {len(CASES)} smoke checks.")
