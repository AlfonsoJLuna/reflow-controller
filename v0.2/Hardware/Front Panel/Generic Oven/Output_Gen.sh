#!/bin/bash

mkdir Output

~/.local/bin/kikit fab jlcpcb \
    ./Generic_Oven.kicad_pcb ./Output
