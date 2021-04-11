EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "AC/DC Converter Module"
Date "2021-04-10"
Rev "v0.1"
Comp "LUNAEmbedded.com"
Comment1 ""
Comment2 ""
Comment3 "Licensed under CERN-OHL-P v2.0"
Comment4 "Designed by Alfonso Luna"
$EndDescr
$Comp
L _AKL_Module:IRM-02-5 PS1
U 1 1 6071C45E
P 5900 3550
F 0 "PS1" H 5900 3750 50  0000 C CNN
F 1 "IRM-02-5" H 5900 3350 50  0000 C CNN
F 2 "Converter_ACDC:Converter_ACDC_MeanWell_IRM-02-xx_THT" H 5900 3250 50  0001 C CNN
F 3 "https://www.digikey.es/product-detail/es/mean-well-usa-inc/IRM-02-5/1866-3009-ND/7704628" H 6300 3200 50  0001 C CNN
F 4 "IRM-02-5" H 5900 3550 50  0001 C CNN "MPN"
	1    5900 3550
	1    0    0    -1  
$EndComp
$Comp
L _AKL_Connector:WJ124-3.81-2P J2
U 1 1 6071DBDD
P 7000 3450
F 0 "J2" H 7100 3450 50  0000 L CNN
F 1 "WJ124-3.81-2P" H 7100 3350 50  0000 L CNN
F 2 "_AKL_Connector:WJ124-3.81-2P" H 7000 3450 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Pluggable-System-Terminal-Block_Ningbo-Kangnex-Elec-WJ124-3-81-2P_C69811.html" H 7000 3450 50  0001 C CNN
F 4 "WJ124-3.81-2P" H 7000 3450 50  0001 C CNN "MPN"
	1    7000 3450
	1    0    0    -1  
$EndComp
$Comp
L _AKL_Connector:WJ124-3.81-2P J1
U 1 1 6071E7E8
P 4800 3550
F 0 "J1" H 4900 3450 50  0000 L CNN
F 1 "WJ124-3.81-2P" H 4900 3550 50  0000 L CNN
F 2 "_AKL_Connector:WJ124-3.81-2P" H 4800 3550 50  0001 C CNN
F 3 "https://lcsc.com/product-detail/Pluggable-System-Terminal-Block_Ningbo-Kangnex-Elec-WJ124-3-81-2P_C69811.html" H 4800 3550 50  0001 C CNN
F 4 "WJ124-3.81-2P" H 4800 3550 50  0001 C CNN "MPN"
	1    4800 3550
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR01
U 1 1 60720965
P 6700 3800
F 0 "#PWR01" H 6700 3550 50  0001 C CNN
F 1 "GND" H 6700 3650 50  0000 C CNN
F 2 "" H 6700 3800 50  0001 C CNN
F 3 "" H 6700 3800 50  0001 C CNN
	1    6700 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3450 5500 3450
Wire Wire Line
	6800 3450 6300 3450
Wire Wire Line
	6700 3650 6700 3550
Wire Wire Line
	6700 3550 6800 3550
Wire Wire Line
	5000 3550 5100 3550
Wire Wire Line
	5100 3550 5100 3650
Wire Wire Line
	5100 3650 5500 3650
Wire Wire Line
	6700 3800 6700 3650
Connection ~ 6700 3650
Wire Wire Line
	6300 3650 6700 3650
$EndSCHEMATC
