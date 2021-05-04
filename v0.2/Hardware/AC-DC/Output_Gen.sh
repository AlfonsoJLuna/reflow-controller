#!/bin/bash

mkdir Output

~/.local/bin/kikit panelize \
    --layout 'grid; rows: 4; cols: 1; space: 2.5mm' \
    --tabs 'fixed; width: 10mm;' \
    --cuts vcuts \
    --framing 'railslr; width: 10mm; space: 2.5mm;' \
    --post 'millradius: 1mm' \
    AC-DC.kicad_pcb ./Output/AC-DC_Panel.kicad_pcb

~/.local/bin/kikit fab jlcpcb \
    ./Output/AC-DC_Panel.kicad_pcb ./Output
