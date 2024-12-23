#!/bin/python3
from sys import argv
from random import random

MAP = [
    'P',
    '1',
    '0',
    'C',
    'E'
]

def main() -> None:
    width = int(argv[1])
    file = argv[2]
    player_placed = False
    bab = False
    with open(file, "w+") as f:
        for i in range(width):
            for j in range(width):
                if j == 0 or j == width - 1 or i == 0 or i == width - 1:
                    f.write('1')
                    continue
                s = MAP[int(random() * len(MAP))]
                if s == 'E' and not bab:
                    bab = True
                    f.write(s)
                    continue
                if s == 'P' and not player_placed:
                    player_placed = True
                    f.write(s)
                    continue
                while s == 'P':
                    s = MAP[int(random() * len(MAP))]
                while s == 'E':
                    s = MAP[int(random() * len(MAP))]
                if s == 'P' and player_placed or s == 'E' and bab:
                    f.write('0')
                    continue
                f.write(s)
            f.write("\n")
    return 0

main()
