#!/bin/bash

mkdir Output

~/.local/bin/kikit panelize \
    --layout 'grid; rows: 2; cols: 2; space: 2mm' \
    --tabs 'fixed; width: 10mm;' \
    --cuts vcuts \
    --framing 'tightframe; width: 3mm; space: 2mm; cuts: true' \
    --post 'millradius: 1mm' \
    Mainboard.kicad_pcb ./Output/Mainboard_Panel.kicad_pcb

~/.local/bin/kikit fab jlcpcb \
    ./Output/Mainboard_Panel.kicad_pcb ./Output
