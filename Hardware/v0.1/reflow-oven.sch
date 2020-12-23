EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Reflow Oven Controller"
Date "2020-12-23"
Rev "v0.1"
Comp "alfonsoluna.io"
Comment1 ""
Comment2 ""
Comment3 "Licensed under CERN OHL v1.2"
Comment4 "Designed by Alfonso Luna"
$EndDescr
$Comp
L _AKL_Module:Waveshare_17344 DS1
U 1 1 5FE3D96D
P 3550 3600
F 0 "DS1" H 3550 3300 50  0000 C CNN
F 1 "Waveshare_17344" H 3550 3900 50  0000 C CNN
F 2 "_AKL_Module:Waveshare_17344" H 3550 4000 50  0001 C CNN
F 3 "https://www.waveshare.com/2inch-lcd-module.htm" H 3650 4000 50  0001 C CNN
F 4 "Waveshare_17344" H 3550 4100 50  0001 C CNN "MPN"
	1    3550 3600
	1    0    0    -1  
$EndComp
$Comp
L _AKL_Module:WeAct_MiniF4 U1
U 1 1 5FE41ABC
P 5200 3550
F 0 "U1" H 5200 2450 50  0000 C CNN
F 1 "WeAct_MiniF4" H 5200 4650 50  0000 C CNN
F 2 "_AKL_Module:WeAct_MiniF4" H 5200 4750 50  0001 C CNN
F 3 "https://github.com/WeActTC/MiniF4-STM32F4x1" H 5100 2250 50  0001 C CNN
F 4 "WeAct_MiniF4_STM32F411CEU6" H 5200 4750 50  0001 C CNN "MPN"
	1    5200 3550
	1    0    0    -1  
$EndComp
Text Notes 6450 3800 0    50   ~ 0
To do:\n- 3 o 4 pulsadores\n- Buzzer activo a 3.3V\n- MAX31855/MAX6675\n- Conector entrada alimentacion 5V\n- Conectores termopar\n- Conector salida de activacion SSR, preferiblemente con MOSFET a 5V\n- Conectores extra por si acaso: segundo rele o ventilador\n- Ver si falta algo mas\n
$EndSCHEMATC
