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
P 5450 6200
F 0 "DS1" H 5450 5900 50  0000 C CNN
F 1 "Waveshare_17344" H 5450 6500 50  0000 C CNN
F 2 "_AKL_Module:Waveshare_17344" H 5450 6600 50  0001 C CNN
F 3 "https://www.waveshare.com/2inch-lcd-module.htm" H 5550 6600 50  0001 C CNN
F 4 "Waveshare_17344" H 5450 6700 50  0001 C CNN "MPN"
	1    5450 6200
	1    0    0    -1  
$EndComp
$Comp
L _AKL_Module:WeAct_MiniF4 U1
U 1 1 5FE41ABC
P 3900 3550
F 0 "U1" H 3900 2450 50  0000 C CNN
F 1 "WeAct_MiniF4" H 3900 4650 50  0000 C CNN
F 2 "_AKL_Module:WeAct_MiniF4" H 3900 4750 50  0001 C CNN
F 3 "https://github.com/WeActTC/MiniF4-STM32F4x1" H 3800 2250 50  0001 C CNN
F 4 "WeAct_MiniF4_STM32F411CEU6" H 3900 4750 50  0001 C CNN "MPN"
	1    3900 3550
	1    0    0    -1  
$EndComp
$Comp
L _AKL_Switch:TS-1095-A13B3-D1 SW1
U 1 1 5FE4917D
P 2100 5950
F 0 "SW1" H 2200 6050 50  0000 C CNN
F 1 "TS-1095-A13B3-D1" H 2100 5850 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H9.5mm" H 2100 6150 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Tactile-Switches_Yuandi-TS-1095-A13B3-D1_C493018.html" H 2100 6150 50  0001 C CNN
F 4 "TS-1095-A13B3-D1" H 2100 6250 50  0001 C CNN "MPN"
	1    2100 5950
	0    -1   -1   0   
$EndComp
$Comp
L _AKL_Switch:TS-1095-A13B3-D1 SW2
U 1 1 5FE4A11F
P 2750 5950
F 0 "SW2" H 2850 6050 50  0000 C CNN
F 1 "TS-1095-A13B3-D1" H 2750 5850 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H9.5mm" H 2750 6150 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Tactile-Switches_Yuandi-TS-1095-A13B3-D1_C493018.html" H 2750 6150 50  0001 C CNN
F 4 "TS-1095-A13B3-D1" H 2750 6250 50  0001 C CNN "MPN"
	1    2750 5950
	0    -1   -1   0   
$EndComp
$Comp
L _AKL_Switch:TS-1095-A13B3-D1 SW3
U 1 1 5FE4A824
P 3400 5950
F 0 "SW3" H 3500 6050 50  0000 C CNN
F 1 "TS-1095-A13B3-D1" H 3400 5850 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H9.5mm" H 3400 6150 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Tactile-Switches_Yuandi-TS-1095-A13B3-D1_C493018.html" H 3400 6150 50  0001 C CNN
F 4 "TS-1095-A13B3-D1" H 3400 6250 50  0001 C CNN "MPN"
	1    3400 5950
	0    -1   -1   0   
$EndComp
$Comp
L _AKL_Speaker:HNB09A03 BZ1
U 1 1 5FE55D58
P 5400 4000
F 0 "BZ1" H 5550 4050 50  0000 L CNN
F 1 "HNB09A03" H 5550 3950 50  0000 L CNN
F 2 "_AKL_Speaker:HNB09A03" H 5400 4300 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Buzzers_Jiangsu-Huaneng-Elec-HNB09A03_C96102.html" V 5375 4100 50  0001 C CNN
F 4 "HNB09A03" H 5400 4200 50  0001 C CNN "MPN"
	1    5400 4000
	1    0    0    -1  
$EndComp
$Comp
L _AKL_IC:MAX31855KASA+T U2
U 1 1 5FE4AAE6
P 4900 1450
F 0 "U2" H 4900 1050 50  0000 C CNN
F 1 "MAX31855KASA+T" H 4900 1800 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 4900 950 50  0001 C CIN
F 3 "https://lcsc.com/product-detail/Interface-ICs_Maxim-Integrated_MAX31855KASA-T_Maxim-Integrated-MAX31855KASA-T_C52028.html" H 5150 1900 50  0001 C CNN
F 4 "MAX31855KASA+T" H 4900 1050 50  0001 C CNN "MPN"
	1    4900 1450
	-1   0    0    -1  
$EndComp
$Comp
L _AKL_Capacitor_603:100n C1
U 1 1 5FE4AA5F
P 5700 1450
F 0 "C1" H 5815 1496 50  0000 L CNN
F 1 "100n" H 5815 1405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5738 1300 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_SAMSUNG_CL10B104KB8NNNC_100nF-104-10-50V_C1591.html" H 5700 1450 50  0001 C CNN
F 4 "CL10B104KB8NNNC" H 5700 1450 50  0001 C CNN "MPN"
	1    5700 1450
	-1   0    0    -1  
$EndComp
$Comp
L _AKL_Capacitor_603:10n C2
U 1 1 5FE4B1F0
P 4100 1300
F 0 "C2" H 4215 1346 50  0000 L CNN
F 1 "10n" H 4215 1255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4138 1150 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_SAMSUNG_CL10B103KB8NNNC_10nF-103-10-50V_C1589.html" H 4100 1300 50  0001 C CNN
F 4 "CL10B103KB8NNNC" H 4100 1300 50  0001 C CNN "MPN"
	1    4100 1300
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5FE4C2DA
P 5700 1800
F 0 "#PWR01" H 5700 1550 50  0001 C CNN
F 1 "GND" H 5700 1650 50  0000 C CNN
F 2 "" H 5700 1800 50  0001 C CNN
F 3 "" H 5700 1800 50  0001 C CNN
	1    5700 1800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5250 1250 5700 1250
Wire Wire Line
	5700 1250 5700 1300
Wire Wire Line
	5700 1600 5700 1700
Wire Wire Line
	5250 1700 5700 1700
Connection ~ 5700 1700
Wire Wire Line
	5700 1700 5700 1800
Text Label 5700 1250 2    50   ~ 0
3V3
Wire Wire Line
	4550 1350 4300 1350
Wire Wire Line
	4300 1350 4300 1500
Wire Wire Line
	4300 1500 4100 1500
Wire Wire Line
	4100 1500 4100 1450
Wire Wire Line
	4300 1250 4300 1100
Wire Wire Line
	4300 1100 4100 1100
Wire Wire Line
	4100 1100 4100 1150
Wire Wire Line
	4550 1250 4300 1250
$Comp
L Device:Ferrite_Bead FB1
U 1 1 5FE4F156
P 3550 1100
F 0 "FB1" V 3500 1300 50  0000 C CNN
F 1 "Ferrite_Bead" V 3600 1400 50  0000 C CNN
F 2 "Inductor_SMD:L_0603_1608Metric" V 3480 1100 50  0001 C CNN
F 3 "DNP" H 3550 1100 50  0001 C CNN
F 4 "DNP" V 3550 1100 50  0001 C CNN "MPN"
	1    3550 1100
	0    -1   1    0   
$EndComp
$Comp
L Device:Ferrite_Bead FB2
U 1 1 5FE500B8
P 3550 1500
F 0 "FB2" V 3500 1700 50  0000 C CNN
F 1 "Ferrite_Bead" V 3600 1800 50  0000 C CNN
F 2 "Inductor_SMD:L_0603_1608Metric" V 3480 1500 50  0001 C CNN
F 3 "DNP" H 3550 1500 50  0001 C CNN
F 4 "DNP" V 3550 1500 50  0001 C CNN "MPN"
	1    3550 1500
	0    -1   1    0   
$EndComp
Wire Wire Line
	3700 1100 4100 1100
Connection ~ 4100 1100
Wire Wire Line
	4100 1500 3700 1500
Connection ~ 4100 1500
Wire Wire Line
	3400 1100 2750 1100
Wire Wire Line
	3400 1500 2750 1500
Text Label 4550 1500 2    50   ~ 0
CS2
Text Label 4550 1600 2    50   ~ 0
SCK2
Text Label 4550 1700 2    50   ~ 0
MISO2
Text Label 2750 1500 0    50   ~ 0
T-
Text Label 3700 1100 0    50   ~ 0
T+_FILTER
Text Label 3700 1500 0    50   ~ 0
T-_FILTER
$Comp
L _AKL_Connector:WJ124-3.81-2P J1
U 1 1 5FE5BA4C
P 2150 4300
F 0 "J1" H 2300 4300 50  0000 C CNN
F 1 "WJ124-3.81-2P" H 2550 4200 50  0000 C CNN
F 2 "_AKL_Connector:WJ124-3.81-2P" H 2150 4300 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Pluggable-System-Terminal-Block_Ningbo-Kangnex-Elec-WJ124-3-81-2P_C69811.html" H 2150 4300 50  0001 C CNN
F 4 "WJ124-3.81-2P" H 2150 4300 50  0001 C CNN "MPN"
	1    2150 4300
	-1   0    0    -1  
$EndComp
$Comp
L _AKL_Connector:WJ124-3.81-2P J4
U 1 1 5FE5CB8F
P 9650 4000
F 0 "J4" H 9750 4000 50  0000 L CNN
F 1 "WJ124-3.81-2P" H 9750 3900 50  0000 L CNN
F 2 "_AKL_Connector:WJ124-3.81-2P" H 9650 4000 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Pluggable-System-Terminal-Block_Ningbo-Kangnex-Elec-WJ124-3-81-2P_C69811.html" H 9650 4000 50  0001 C CNN
F 4 "WJ124-3.81-2P" H 9650 4000 50  0001 C CNN "MPN"
	1    9650 4000
	1    0    0    -1  
$EndComp
Text Label 2350 4300 0    50   ~ 0
5V
$Comp
L _AKL_Transistor:FDN327N Q1
U 1 1 5FE65FE8
P 8400 2200
F 0 "Q1" H 8604 2246 50  0000 L CNN
F 1 "FDN327N" H 8604 2155 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8600 2300 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/MOSFET_ON-Semiconductor-FDN327N_C154560.html" H 8400 2200 50  0001 C CNN
F 4 "FDN327N" H 8400 2200 50  0001 C CNN "MPN"
	1    8400 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5FE66FB0
P 8500 2700
F 0 "#PWR011" H 8500 2450 50  0001 C CNN
F 1 "GND" H 8500 2550 50  0000 C CNN
F 2 "" H 8500 2700 50  0001 C CNN
F 3 "" H 8500 2700 50  0001 C CNN
	1    8500 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 2400 8500 2700
Wire Wire Line
	8500 2000 8500 1950
Text Label 8600 1300 2    50   ~ 0
5V
Wire Wire Line
	2700 1250 2750 1250
Wire Wire Line
	2750 1250 2750 1100
Wire Wire Line
	2700 1350 2750 1350
Wire Wire Line
	2750 1350 2750 1500
Text Label 2750 1100 0    50   ~ 0
T+
$Comp
L _AKL_Connector:WJ124-3.81-2P J2
U 1 1 5FE5C187
P 2500 1250
F 0 "J2" H 2600 1250 50  0000 L CNN
F 1 "WJ124-3.81-2P" H 2600 1150 50  0000 L CNN
F 2 "_AKL_Connector:WJ124-3.81-2P" H 2500 1250 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Pluggable-System-Terminal-Block_Ningbo-Kangnex-Elec-WJ124-3-81-2P_C69811.html" H 2500 1250 50  0001 C CNN
F 4 "WJ124-3.81-2P" H 2500 1250 50  0001 C CNN "MPN"
	1    2500 1250
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5FE85903
P 8000 2700
F 0 "#PWR09" H 8000 2450 50  0001 C CNN
F 1 "GND" H 8000 2550 50  0000 C CNN
F 2 "" H 8000 2700 50  0001 C CNN
F 3 "" H 8000 2700 50  0001 C CNN
	1    8000 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 2600 8000 2700
Wire Wire Line
	8200 2200 8000 2200
Wire Wire Line
	8000 2200 8000 2300
Connection ~ 8000 2200
Text Label 7350 2200 0    50   ~ 0
OUT1
NoConn ~ 4750 4500
NoConn ~ 4750 4100
$Comp
L _AKL_Resistor_603:10K R4
U 1 1 5FE9A89F
P 8000 2450
F 0 "R4" H 8070 2496 50  0000 L CNN
F 1 "10K" H 8070 2405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8000 2450 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_10KR-1002-1_C98220.html" H 8000 2450 50  0001 C CNN
F 4 "RC0603FR-0710KL" H 8000 2450 44  0001 C CNN "MPN"
	1    8000 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 2200 8000 2200
Text Label 9350 1950 2    50   ~ 0
OUT1-
$Comp
L _AKL_Diode:MBR120VLSFT3G D1
U 1 1 5FEA0970
P 8500 1750
F 0 "D1" V 8454 1829 50  0000 L CNN
F 1 "MBR120VLSFT3G" V 8545 1829 50  0000 L CNN
F 2 "_AKL_Diode:SOD-123FL" H 8500 1750 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/_ON-Semiconductor-ON-MBR120VLSFT3G_C295749.html" H 8500 1750 50  0001 C CNN
F 4 "MBR120VLSFT3G" H 8500 1750 50  0001 C CNN "MPN"
	1    8500 1750
	0    1    1    0   
$EndComp
Wire Wire Line
	8500 1600 8500 1550
Wire Wire Line
	9350 1950 8500 1950
Connection ~ 8500 1950
Wire Wire Line
	8500 1950 8500 1900
Wire Wire Line
	9350 1800 9350 1950
Wire Wire Line
	8500 1550 9350 1550
Wire Wire Line
	9450 1800 9350 1800
Wire Wire Line
	9350 1700 9450 1700
Wire Wire Line
	9350 1550 9350 1700
$Comp
L _AKL_Connector:WJ124-3.81-2P J3
U 1 1 5FE5C6A2
P 9650 1700
F 0 "J3" H 9750 1700 50  0000 L CNN
F 1 "WJ124-3.81-2P" H 9750 1600 50  0000 L CNN
F 2 "_AKL_Connector:WJ124-3.81-2P" H 9650 1700 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Pluggable-System-Terminal-Block_Ningbo-Kangnex-Elec-WJ124-3-81-2P_C69811.html" H 9650 1700 50  0001 C CNN
F 4 "WJ124-3.81-2P" H 9650 1700 50  0001 C CNN "MPN"
	1    9650 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 1550 8500 1300
Connection ~ 8500 1550
Wire Wire Line
	8500 1300 8600 1300
$Comp
L _AKL_Transistor:FDN327N Q2
U 1 1 5FEB2292
P 8400 4500
F 0 "Q2" H 8604 4546 50  0000 L CNN
F 1 "FDN327N" H 8604 4455 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8600 4600 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/MOSFET_ON-Semiconductor-FDN327N_C154560.html" H 8400 4500 50  0001 C CNN
F 4 "FDN327N" H 8400 4500 50  0001 C CNN "MPN"
	1    8400 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5FEB2298
P 8500 5000
F 0 "#PWR012" H 8500 4750 50  0001 C CNN
F 1 "GND" H 8500 4850 50  0000 C CNN
F 2 "" H 8500 5000 50  0001 C CNN
F 3 "" H 8500 5000 50  0001 C CNN
	1    8500 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 4700 8500 5000
Wire Wire Line
	8500 4300 8500 4250
Text Label 8600 3600 2    50   ~ 0
5V
$Comp
L power:GND #PWR010
U 1 1 5FEB22A1
P 8000 5000
F 0 "#PWR010" H 8000 4750 50  0001 C CNN
F 1 "GND" H 8000 4850 50  0000 C CNN
F 2 "" H 8000 5000 50  0001 C CNN
F 3 "" H 8000 5000 50  0001 C CNN
	1    8000 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 4900 8000 5000
Wire Wire Line
	8200 4500 8000 4500
Wire Wire Line
	8000 4500 8000 4600
Connection ~ 8000 4500
Text Label 7350 4500 0    50   ~ 0
OUT2
$Comp
L _AKL_Resistor_603:10K R5
U 1 1 5FEB22AD
P 8000 4750
F 0 "R5" H 8070 4796 50  0000 L CNN
F 1 "10K" H 8070 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8000 4750 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_10KR-1002-1_C98220.html" H 8000 4750 50  0001 C CNN
F 4 "RC0603FR-0710KL" H 8000 4750 44  0001 C CNN "MPN"
	1    8000 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 4500 8000 4500
Text Label 9350 4250 2    50   ~ 0
OUT2-
$Comp
L _AKL_Diode:MBR120VLSFT3G D2
U 1 1 5FEB22B6
P 8500 4050
F 0 "D2" V 8454 4129 50  0000 L CNN
F 1 "MBR120VLSFT3G" V 8545 4129 50  0000 L CNN
F 2 "_AKL_Diode:SOD-123FL" H 8500 4050 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/_ON-Semiconductor-ON-MBR120VLSFT3G_C295749.html" H 8500 4050 50  0001 C CNN
F 4 "MBR120VLSFT3G" H 8500 4050 50  0001 C CNN "MPN"
	1    8500 4050
	0    1    1    0   
$EndComp
Wire Wire Line
	8500 3900 8500 3850
Wire Wire Line
	9350 4250 8500 4250
Connection ~ 8500 4250
Wire Wire Line
	8500 4250 8500 4200
Wire Wire Line
	9350 4100 9350 4250
Wire Wire Line
	8500 3850 9350 3850
Wire Wire Line
	9450 4100 9350 4100
Wire Wire Line
	9350 4000 9450 4000
Wire Wire Line
	9350 3850 9350 4000
Wire Wire Line
	8500 3850 8500 3600
Connection ~ 8500 3850
Wire Wire Line
	8500 3600 8600 3600
Wire Wire Line
	2350 4300 3050 4300
Text Label 3050 4500 2    50   ~ 0
3V3
Text Label 4750 2800 0    50   ~ 0
3V3
Text Label 4750 2600 0    50   ~ 0
5V
Wire Wire Line
	2350 4400 2400 4400
$Comp
L power:GND #PWR03
U 1 1 5FECCC8F
P 2400 4500
F 0 "#PWR03" H 2400 4250 50  0001 C CNN
F 1 "GND" H 2400 4350 50  0000 C CNN
F 2 "" H 2400 4500 50  0001 C CNN
F 3 "" H 2400 4500 50  0001 C CNN
	1    2400 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 4500 2400 4400
Connection ~ 2400 4400
Wire Wire Line
	2400 4400 3050 4400
$Comp
L _AKL_Resistor_603:10K R1
U 1 1 5FEE8BFA
P 2100 6750
F 0 "R1" H 2170 6796 50  0000 L CNN
F 1 "10K" H 2170 6705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2100 6750 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_10KR-1002-1_C98220.html" H 2100 6750 50  0001 C CNN
F 4 "RC0603FR-0710KL" H 2100 6750 44  0001 C CNN "MPN"
	1    2100 6750
	1    0    0    -1  
$EndComp
$Comp
L _AKL_Resistor_603:10K R2
U 1 1 5FEE8F29
P 2750 6750
F 0 "R2" H 2820 6796 50  0000 L CNN
F 1 "10K" H 2820 6705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2750 6750 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_10KR-1002-1_C98220.html" H 2750 6750 50  0001 C CNN
F 4 "RC0603FR-0710KL" H 2750 6750 44  0001 C CNN "MPN"
	1    2750 6750
	1    0    0    -1  
$EndComp
$Comp
L _AKL_Resistor_603:10K R3
U 1 1 5FEE913A
P 3400 6750
F 0 "R3" H 3470 6796 50  0000 L CNN
F 1 "10K" H 3470 6705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3400 6750 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_10KR-1002-1_C98220.html" H 3400 6750 50  0001 C CNN
F 4 "RC0603FR-0710KL" H 3400 6750 44  0001 C CNN "MPN"
	1    3400 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5FEED8F2
P 2100 7000
F 0 "#PWR02" H 2100 6750 50  0001 C CNN
F 1 "GND" H 2100 6850 50  0000 C CNN
F 2 "" H 2100 7000 50  0001 C CNN
F 3 "" H 2100 7000 50  0001 C CNN
	1    2100 7000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5FEEDD55
P 2750 7000
F 0 "#PWR04" H 2750 6750 50  0001 C CNN
F 1 "GND" H 2750 6850 50  0000 C CNN
F 2 "" H 2750 7000 50  0001 C CNN
F 3 "" H 2750 7000 50  0001 C CNN
	1    2750 7000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5FEEDE6F
P 3400 7000
F 0 "#PWR05" H 3400 6750 50  0001 C CNN
F 1 "GND" H 3400 6850 50  0000 C CNN
F 2 "" H 3400 7000 50  0001 C CNN
F 3 "" H 3400 7000 50  0001 C CNN
	1    3400 7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 6900 3400 7000
Wire Wire Line
	2750 7000 2750 6900
Wire Wire Line
	2100 6900 2100 7000
Wire Wire Line
	2100 6150 2100 6500
Wire Wire Line
	2750 6150 2750 6500
Wire Wire Line
	3400 6150 3400 6500
Connection ~ 2100 6500
Wire Wire Line
	2100 6500 2100 6600
Connection ~ 2750 6500
Wire Wire Line
	2750 6500 2750 6600
Connection ~ 3400 6500
Wire Wire Line
	3400 6500 3400 6600
Text Label 2400 6500 2    50   ~ 0
BTN_A
Text Label 3050 6500 2    50   ~ 0
BTN_B
Wire Wire Line
	2100 6500 2400 6500
Wire Wire Line
	2750 6500 3050 6500
Text Label 3700 6500 2    50   ~ 0
BTN_C
Wire Wire Line
	3400 6500 3700 6500
Wire Wire Line
	2100 5750 2100 5400
Wire Wire Line
	2100 5400 2250 5400
Text Label 2250 5400 2    50   ~ 0
3V3
Wire Wire Line
	2750 5750 2750 5400
Wire Wire Line
	2750 5400 2900 5400
Text Label 2900 5400 2    50   ~ 0
3V3
Wire Wire Line
	3400 5750 3400 5400
Wire Wire Line
	3400 5400 3550 5400
Text Label 3550 5400 2    50   ~ 0
3V3
Text Label 4750 2900 0    50   ~ 0
BTN_A
Text Label 4750 3100 0    50   ~ 0
BTN_B
Text Label 4750 3200 0    50   ~ 0
BTN_C
$Comp
L power:GND #PWR08
U 1 1 5FF0EE77
P 5200 4200
F 0 "#PWR08" H 5200 3950 50  0001 C CNN
F 1 "GND" H 5200 4050 50  0000 C CNN
F 2 "" H 5200 4200 50  0001 C CNN
F 3 "" H 5200 4200 50  0001 C CNN
	1    5200 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 4200 5200 4100
Wire Wire Line
	5200 4100 5300 4100
Text Label 3050 3800 2    50   ~ 0
OUT1
Text Label 3050 3900 2    50   ~ 0
OUT2
Text Label 3050 2600 2    50   ~ 0
CS2
Text Label 3050 2700 2    50   ~ 0
SCK2
Text Label 3050 2800 2    50   ~ 0
MISO2
$Comp
L power:GND #PWR06
U 1 1 5FF5C86E
P 5000 6450
F 0 "#PWR06" H 5000 6200 50  0001 C CNN
F 1 "GND" H 5000 6300 50  0000 C CNN
F 2 "" H 5000 6450 50  0001 C CNN
F 3 "" H 5000 6450 50  0001 C CNN
	1    5000 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 6350 5000 6350
Wire Wire Line
	5000 6350 5000 6450
Text Label 5100 6050 2    50   ~ 0
3V3
Text Label 5800 6050 0    50   ~ 0
DC
Text Label 5800 6150 0    50   ~ 0
CS1
Text Label 5800 6250 0    50   ~ 0
SCK1
Text Label 5800 6350 0    50   ~ 0
MOSI1
Text Label 5100 6150 2    50   ~ 0
RST
Text Label 5100 6250 2    50   ~ 0
BL
Text Label 4750 3800 0    50   ~ 0
DC
Text Label 4750 3600 0    50   ~ 0
CS1
Text Label 4750 3500 0    50   ~ 0
SCK1
Text Label 4750 3300 0    50   ~ 0
MOSI1
Text Label 4750 3700 0    50   ~ 0
RST
Text Label 4750 3400 0    50   ~ 0
BL
$Comp
L power:GND #PWR07
U 1 1 5FF7D37D
P 5150 2800
F 0 "#PWR07" H 5150 2550 50  0001 C CNN
F 1 "GND" H 5150 2650 50  0000 C CNN
F 2 "" H 5150 2800 50  0001 C CNN
F 3 "" H 5150 2800 50  0001 C CNN
	1    5150 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 2700 5150 2700
Wire Wire Line
	5150 2700 5150 2800
NoConn ~ 4750 4400
NoConn ~ 4750 4300
NoConn ~ 4750 4200
NoConn ~ 4750 3000
NoConn ~ 3050 3100
NoConn ~ 3050 3000
NoConn ~ 3050 3200
NoConn ~ 3050 3300
NoConn ~ 3050 3400
NoConn ~ 3050 3500
NoConn ~ 3050 3600
NoConn ~ 3050 3700
Wire Wire Line
	4750 3900 5300 3900
Text Label 4750 3900 0    50   ~ 0
BUZZER
NoConn ~ 4750 4000
NoConn ~ 3050 2900
NoConn ~ 3050 4000
NoConn ~ 3050 4100
NoConn ~ 3050 4200
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5FFC24F3
P 9700 6100
F 0 "#FLG0101" H 9700 6175 50  0001 C CNN
F 1 "PWR_FLAG" H 9700 6273 50  0000 C CNN
F 2 "" H 9700 6100 50  0001 C CNN
F 3 "~" H 9700 6100 50  0001 C CNN
	1    9700 6100
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5FFC32AE
P 10200 6100
F 0 "#FLG0102" H 10200 6175 50  0001 C CNN
F 1 "PWR_FLAG" H 10200 6273 50  0000 C CNN
F 2 "" H 10200 6100 50  0001 C CNN
F 3 "~" H 10200 6100 50  0001 C CNN
	1    10200 6100
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5FFC351B
P 10700 6100
F 0 "#FLG0103" H 10700 6175 50  0001 C CNN
F 1 "PWR_FLAG" H 10700 6273 50  0000 C CNN
F 2 "" H 10700 6100 50  0001 C CNN
F 3 "~" H 10700 6100 50  0001 C CNN
	1    10700 6100
	1    0    0    -1  
$EndComp
Text Label 10200 6100 3    50   ~ 0
3V3
Text Label 9700 6100 3    50   ~ 0
5V
$Comp
L power:GND #PWR0101
U 1 1 5FFC4A22
P 10700 6150
F 0 "#PWR0101" H 10700 5900 50  0001 C CNN
F 1 "GND" H 10700 6000 50  0000 C CNN
F 2 "" H 10700 6150 50  0001 C CNN
F 3 "" H 10700 6150 50  0001 C CNN
	1    10700 6150
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10700 6100 10700 6150
$EndSCHEMATC
