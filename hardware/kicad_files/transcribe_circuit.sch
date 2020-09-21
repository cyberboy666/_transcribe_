EESchema Schematic File Version 4
LIBS:transcribe_circuit-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "_transcribe_"
Date "2020-06-13"
Rev "0.2"
Comp "cyberboy666 & user43368831"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L transcribe_circuit-rescue:ProMicro-promicro U1
U 1 1 5E1CCE60
P 2200 2500
F 0 "U1" H 2200 3537 60  0000 C CNN
F 1 "ProMicro" H 2200 3431 60  0000 C CNN
F 2 "Module:ProMicro" H 2300 1450 60  0001 C CNN
F 3 "" H 2300 1450 60  0000 C CNN
	1    2200 2500
	1    0    0    -1  
$EndComp
$Comp
L Interface_UART:MAX232 U2
U 1 1 5E1CD5E9
P 5200 3675
F 0 "U2" H 4750 4950 50  0000 C CNN
F 1 "MAX232" H 4850 4850 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 5250 2625 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/max232.pdf" H 5200 3775 50  0001 C CNN
	1    5200 3675
	1    0    0    -1  
$EndComp
$Comp
L transcribe_circuit-rescue:usbHostMini-promicro U5
U 1 1 5E1D17C6
P 2575 6400
F 0 "U5" H 2575 7437 60  0000 C CNN
F 1 "usbHostMini" H 2575 7331 60  0000 C CNN
F 2 "Module:usbHostMidi" H 2675 5350 60  0001 C CNN
F 3 "" H 2675 5350 60  0000 C CNN
	1    2575 6400
	1    0    0    -1  
$EndComp
Text Notes 875  950  0    118  ~ 0
A. micro-controller
Text Notes 4275 975  0    118  ~ 0
B. rs232 serial
Text Notes 1000 4525 0    118  ~ 0
D. usb-host shield
Text Notes 7450 1025 0    118  ~ 0
C. midi serial
$Comp
L Device:R R3
U 1 1 5E1E86F1
P 8325 1900
F 0 "R3" V 8225 1900 50  0000 C CNN
F 1 "220" V 8325 1900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P5.08mm_Vertical" V 8255 1900 50  0001 C CNN
F 3 "~" H 8325 1900 50  0001 C CNN
	1    8325 1900
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5E1E9C5C
P 9825 1800
F 0 "R4" V 9725 1800 50  0000 C CNN
F 1 "10k" V 9825 1800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P5.08mm_Vertical" V 9755 1800 50  0001 C CNN
F 3 "~" H 9825 1800 50  0001 C CNN
	1    9825 1800
	0    1    1    0   
$EndComp
Text GLabel 10250 1800 2    50   Input ~ 0
MIDI_SERIAL_IN
$Comp
L Device:D D1
U 1 1 5E1EB2E4
P 8575 2050
F 0 "D1" V 8529 2129 50  0000 L CNN
F 1 "1N4148" H 8475 1950 50  0000 L CNN
F 2 "Diode_THT:D_T-1_P5.08mm_Horizontal" H 8575 2050 50  0001 C CNN
F 3 "~" H 8575 2050 50  0001 C CNN
	1    8575 2050
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR021
U 1 1 5E1EC60A
P 9575 1425
F 0 "#PWR021" H 9575 1275 50  0001 C CNN
F 1 "+5V" H 9590 1598 50  0000 C CNN
F 2 "" H 9575 1425 50  0001 C CNN
F 3 "" H 9575 1425 50  0001 C CNN
	1    9575 1425
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR022
U 1 1 5E1ED3DB
P 9700 2475
F 0 "#PWR022" H 9700 2225 50  0001 C CNN
F 1 "GND" H 9705 2302 50  0000 C CNN
F 2 "" H 9700 2475 50  0001 C CNN
F 3 "" H 9700 2475 50  0001 C CNN
	1    9700 2475
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 2475 9700 2200
Wire Wire Line
	9700 2200 9375 2200
Wire Wire Line
	9375 1800 9575 1800
Wire Wire Line
	9975 1800 10050 1800
Wire Wire Line
	9375 2100 10050 2100
Wire Wire Line
	10050 2100 10050 1800
Connection ~ 10050 1800
Wire Wire Line
	10050 1800 10250 1800
Wire Wire Line
	9575 1425 9575 1800
Connection ~ 9575 1800
Wire Wire Line
	9575 1800 9675 1800
NoConn ~ 9375 1900
Wire Wire Line
	8775 1900 8575 1900
Wire Wire Line
	8575 1900 8475 1900
Connection ~ 8575 1900
Text GLabel 7900 1900 0    50   Input ~ 0
MIDI_IN_PLUS
Text GLabel 7900 2250 0    50   Input ~ 0
MIDI_IN_DATA
Wire Wire Line
	8175 1900 7900 1900
Wire Wire Line
	8575 2200 8575 2250
Wire Wire Line
	8575 2250 7900 2250
$Comp
L Connector:AudioJack3_SwitchTR J4
U 1 1 5E1F0A6D
P 7650 3375
F 0 "J4" H 7632 3700 50  0000 C CNN
F 1 "MIDI_IN_TRS" H 7632 3609 50  0000 C CNN
F 2 "lib_fp:Tayda_3.5mm_stereo_TRS_jack_A-853" H 7650 3375 50  0001 C CNN
F 3 "~" H 7650 3375 50  0001 C CNN
	1    7650 3375
	1    0    0    -1  
$EndComp
Text GLabel 8000 3375 2    50   Input ~ 0
MIDI_IN_PLUS
Text GLabel 8000 3575 2    50   Input ~ 0
MIDI_IN_DATA
Wire Wire Line
	7850 3375 8000 3375
$Comp
L Connector:AudioJack3_SwitchTR J6
U 1 1 5E1F4FCA
P 7725 5700
F 0 "J6" H 7707 6025 50  0000 C CNN
F 1 "MIDI_OUT_TRS" H 7707 5934 50  0000 C CNN
F 2 "lib_fp:Tayda_3.5mm_stereo_TRS_jack_A-853" H 7725 5700 50  0001 C CNN
F 3 "~" H 7725 5700 50  0001 C CNN
	1    7725 5700
	1    0    0    -1  
$EndComp
Text GLabel 8075 5700 2    50   Input ~ 0
MIDI_OUT_PLUS
Text GLabel 8075 5900 2    50   Input ~ 0
MIDI_OUT_DATA
Wire Wire Line
	7925 5700 8075 5700
Text GLabel 9950 5000 2    50   Input ~ 0
MIDI_SERIAL_OUT
Text GLabel 7975 4775 0    50   Input ~ 0
MIDI_OUT_PLUS
Text GLabel 7975 5000 0    50   Input ~ 0
MIDI_OUT_DATA
$Comp
L power:+5V #PWR020
U 1 1 5E1F83DF
P 8425 4625
F 0 "#PWR020" H 8425 4475 50  0001 C CNN
F 1 "+5V" H 8440 4798 50  0000 C CNN
F 2 "" H 8425 4625 50  0001 C CNN
F 3 "" H 8425 4625 50  0001 C CNN
	1    8425 4625
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5E1F8F29
P 8225 4775
F 0 "R1" V 8125 4775 50  0000 C CNN
F 1 "220" V 8225 4775 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P5.08mm_Vertical" V 8155 4775 50  0001 C CNN
F 3 "~" H 8225 4775 50  0001 C CNN
	1    8225 4775
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5E1F93F1
P 8225 5000
F 0 "R2" V 8125 5000 50  0000 C CNN
F 1 "220" V 8225 5000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P5.08mm_Vertical" V 8155 5000 50  0001 C CNN
F 3 "~" H 8225 5000 50  0001 C CNN
	1    8225 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	8375 4775 8425 4775
Wire Wire Line
	8425 4775 8425 4625
Wire Wire Line
	8375 5000 8575 5000
Wire Wire Line
	8075 5000 7975 5000
Wire Wire Line
	8075 4775 7975 4775
$Comp
L Device:C C2
U 1 1 5E215C9F
P 4150 2925
F 0 "C2" H 4265 2971 50  0000 L CNN
F 1 "0.1u" H 4265 2880 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 4188 2775 50  0001 C CNN
F 3 "~" H 4150 2925 50  0001 C CNN
	1    4150 2925
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 2775 4150 2775
Wire Wire Line
	4400 3075 4150 3075
$Comp
L Device:C C4
U 1 1 5E2174FD
P 6250 2925
F 0 "C4" H 6365 2971 50  0000 L CNN
F 1 "0.1u" H 6365 2880 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 6288 2775 50  0001 C CNN
F 3 "~" H 6250 2925 50  0001 C CNN
	1    6250 2925
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 2775 6250 2775
Wire Wire Line
	6250 3075 6000 3075
$Comp
L Device:C C3
U 1 1 5E218A45
P 6150 3275
F 0 "C3" V 6000 3275 50  0000 C CNN
F 1 "0.1u" V 6300 3275 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 6188 3125 50  0001 C CNN
F 3 "~" H 6150 3275 50  0001 C CNN
	1    6150 3275
	0    1    1    0   
$EndComp
$Comp
L Device:C C5
U 1 1 5E219C1D
P 6300 3575
F 0 "C5" V 6150 3575 50  0000 C CNN
F 1 "0.1u" V 6450 3575 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 6338 3425 50  0001 C CNN
F 3 "~" H 6300 3575 50  0001 C CNN
	1    6300 3575
	0    1    1    0   
$EndComp
Wire Wire Line
	6150 3575 6000 3575
$Comp
L power:GND #PWR019
U 1 1 5E21C33E
P 6700 3500
F 0 "#PWR019" H 6700 3250 50  0001 C CNN
F 1 "GND" H 6705 3327 50  0000 C CNN
F 2 "" H 6700 3500 50  0001 C CNN
F 3 "" H 6700 3500 50  0001 C CNN
	1    6700 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 3275 6700 3500
Wire Wire Line
	6300 3275 6450 3275
Wire Wire Line
	6450 3575 6450 3275
Connection ~ 6450 3275
Wire Wire Line
	6450 3275 6700 3275
$Comp
L power:GND #PWR015
U 1 1 5E21F7F9
P 5200 4875
F 0 "#PWR015" H 5200 4625 50  0001 C CNN
F 1 "GND" H 5205 4702 50  0000 C CNN
F 2 "" H 5200 4875 50  0001 C CNN
F 3 "" H 5200 4875 50  0001 C CNN
	1    5200 4875
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR014
U 1 1 5E2205ED
P 5200 2475
F 0 "#PWR014" H 5200 2325 50  0001 C CNN
F 1 "+5V" H 5215 2648 50  0000 C CNN
F 2 "" H 5200 2475 50  0001 C CNN
F 3 "" H 5200 2475 50  0001 C CNN
	1    5200 2475
	1    0    0    -1  
$EndComp
NoConn ~ 4400 3975
NoConn ~ 6000 3975
NoConn ~ 4400 4375
NoConn ~ 6000 4375
$Comp
L Connector:AudioJack3_SwitchTR J2
U 1 1 5E2249E5
P 4150 1575
F 0 "J2" H 4132 1900 50  0000 C CNN
F 1 "RS232_SERIAL" H 4025 1800 50  0000 C CNN
F 2 "lib_fp:Tayda_3.5mm_stereo_TRS_jack_A-853" H 4150 1575 50  0001 C CNN
F 3 "~" H 4150 1575 50  0001 C CNN
	1    4150 1575
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5E2249F1
P 4500 1950
F 0 "#PWR013" H 4500 1700 50  0001 C CNN
F 1 "GND" H 4505 1777 50  0000 C CNN
F 2 "" H 4500 1950 50  0001 C CNN
F 3 "" H 4500 1950 50  0001 C CNN
	1    4500 1950
	1    0    0    -1  
$EndComp
NoConn ~ 3275 5650
NoConn ~ 1875 6750
$Comp
L power:+5V #PWR03
U 1 1 5E23779E
P 825 4900
F 0 "#PWR03" H 825 4750 50  0001 C CNN
F 1 "+5V" H 840 5073 50  0000 C CNN
F 2 "" H 825 4900 50  0001 C CNN
F 3 "" H 825 4900 50  0001 C CNN
	1    825  4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	825  4900 825  5025
Wire Wire Line
	825  5025 1000 5025
$Comp
L power:GND #PWR04
U 1 1 5E23A7A2
P 1300 5425
F 0 "#PWR04" H 1300 5175 50  0001 C CNN
F 1 "GND" H 1305 5252 50  0000 C CNN
F 2 "" H 1300 5425 50  0001 C CNN
F 3 "" H 1300 5425 50  0001 C CNN
	1    1300 5425
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 5325 1300 5350
Wire Wire Line
	3400 5950 3275 5950
$Comp
L power:GND #PWR012
U 1 1 5E23E240
P 3750 5750
F 0 "#PWR012" H 3750 5500 50  0001 C CNN
F 1 "GND" H 3755 5577 50  0000 C CNN
F 2 "" H 3750 5750 50  0001 C CNN
F 3 "" H 3750 5750 50  0001 C CNN
	1    3750 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3275 5750 3275 5700
Wire Wire Line
	3275 5700 3750 5700
Wire Wire Line
	3750 5700 3750 5750
$Comp
L power:GND #PWR08
U 1 1 5E23FDFB
P 1800 6075
F 0 "#PWR08" H 1800 5825 50  0001 C CNN
F 1 "GND" H 1805 5902 50  0000 C CNN
F 2 "" H 1800 6075 50  0001 C CNN
F 3 "" H 1800 6075 50  0001 C CNN
	1    1800 6075
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR09
U 1 1 5E244DDB
P 1900 7050
F 0 "#PWR09" H 1900 6900 50  0001 C CNN
F 1 "+5V" H 1915 7223 50  0000 C CNN
F 2 "" H 1900 7050 50  0001 C CNN
F 3 "" H 1900 7050 50  0001 C CNN
	1    1900 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 7050 2275 7050
Text GLabel 6250 3925 2    50   Input ~ 0
RS_SERIAL_OUT
Wire Wire Line
	6000 3775 6000 3925
Wire Wire Line
	6000 3925 6250 3925
Text GLabel 6250 4175 2    50   Input ~ 0
RS_SERIAL_IN
Wire Wire Line
	6250 4175 6000 4175
Text GLabel 4225 3775 0    50   Input ~ 0
ALT_SERIAL_OUT
Text GLabel 6150 1450 0    50   Input ~ 0
RS_SERIAL_OUT
Wire Wire Line
	4350 1575 4800 1575
Text GLabel 4800 1575 2    50   Input ~ 0
RS_SERIAL_IN
Wire Wire Line
	4225 3775 4400 3775
Text GLabel 4225 4175 0    50   Input ~ 0
ALT_SERIAL_IN
Wire Wire Line
	4225 4175 4400 4175
Text GLabel 1325 2450 0    50   Input ~ 0
ALT_SERIAL_OUT
Wire Wire Line
	1325 2450 1500 2450
Text GLabel 1275 2275 0    50   Input ~ 0
ALT_SERIAL_IN
Text GLabel 1325 1850 0    50   Input ~ 0
MIDI_SERIAL_IN
Text GLabel 1400 1675 0    50   Input ~ 0
MIDI_SERIAL_OUT
Wire Wire Line
	1275 2275 1275 2350
Wire Wire Line
	1275 2350 1500 2350
Wire Wire Line
	1400 1675 1400 1750
Wire Wire Line
	1400 1750 1500 1750
Wire Wire Line
	1325 1850 1500 1850
$Comp
L power:GND #PWR05
U 1 1 5E27B159
P 1350 2050
F 0 "#PWR05" H 1350 1800 50  0001 C CNN
F 1 "GND" H 1355 1877 50  0000 C CNN
F 2 "" H 1350 2050 50  0001 C CNN
F 3 "" H 1350 2050 50  0001 C CNN
	1    1350 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1950 1350 1950
Wire Wire Line
	1350 1950 1350 2050
Wire Wire Line
	1500 2050 1350 2050
Connection ~ 1350 2050
$Comp
L power:GND #PWR011
U 1 1 5E27F7BB
P 3500 1950
F 0 "#PWR011" H 3500 1700 50  0001 C CNN
F 1 "GND" H 3500 1800 50  0000 C CNN
F 2 "" H 3500 1950 50  0001 C CNN
F 3 "" H 3500 1950 50  0001 C CNN
	1    3500 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR010
U 1 1 5E282880
P 3500 1525
F 0 "#PWR010" H 3500 1375 50  0001 C CNN
F 1 "+5V" H 3525 1700 50  0000 C CNN
F 2 "" H 3500 1525 50  0001 C CNN
F 3 "" H 3500 1525 50  0001 C CNN
	1    3500 1525
	1    0    0    -1  
$EndComp
Text GLabel 2950 1950 2    50   Input ~ 0
RST_HOST
Text GLabel 1825 5850 0    50   Input ~ 0
RST_HOST
Wire Wire Line
	1875 5850 1825 5850
Text GLabel 3450 6450 2    50   Input ~ 0
SKC_HOST
Text GLabel 3450 6550 2    50   Input ~ 0
MISO_HOST
Text GLabel 3450 6650 2    50   Input ~ 0
MOSI_HOST
Text GLabel 3450 6750 2    50   Input ~ 0
SS_HOST
Wire Wire Line
	3450 6450 3275 6450
Wire Wire Line
	3450 6550 3275 6550
Wire Wire Line
	3450 6650 3275 6650
Wire Wire Line
	3450 6750 3275 6750
Text GLabel 3000 2550 2    50   Input ~ 0
SKC_HOST
Text GLabel 3000 2650 2    50   Input ~ 0
MISO_HOST
Text GLabel 3000 2750 2    50   Input ~ 0
MOSI_HOST
Text GLabel 3000 2850 2    50   Input ~ 0
SS_HOST
Wire Wire Line
	3000 2550 2900 2550
Wire Wire Line
	3000 2650 2900 2650
Wire Wire Line
	3000 2750 2900 2750
Wire Wire Line
	3000 2850 2900 2850
NoConn ~ 1500 2150
NoConn ~ 1500 2250
NoConn ~ 1500 2550
NoConn ~ 1500 2650
NoConn ~ 1500 2750
NoConn ~ 1500 2850
NoConn ~ 2900 2150
NoConn ~ 2900 2250
NoConn ~ 2900 2350
NoConn ~ 2900 2450
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5E2D96EE
P 750 5025
F 0 "#FLG01" H 750 5100 50  0001 C CNN
F 1 "PWR_FLAG" V 625 4900 50  0000 L CNN
F 2 "" H 750 5025 50  0001 C CNN
F 3 "~" H 750 5025 50  0001 C CNN
	1    750  5025
	0    -1   -1   0   
$EndComp
Wire Wire Line
	825  5025 750  5025
Connection ~ 825  5025
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5E2DCB0C
P 1100 5350
F 0 "#FLG02" H 1100 5425 50  0001 C CNN
F 1 "PWR_FLAG" V 975 5225 50  0000 L CNN
F 2 "" H 1100 5350 50  0001 C CNN
F 3 "~" H 1100 5350 50  0001 C CNN
	1    1100 5350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1100 5350 1300 5350
Connection ~ 1300 5350
Wire Wire Line
	1300 5350 1300 5425
Wire Wire Line
	8575 2250 8775 2250
Wire Wire Line
	8775 2250 8775 2100
Connection ~ 8575 2250
Wire Wire Line
	1875 5950 1800 5950
Wire Wire Line
	1800 5950 1800 6075
Text GLabel 1725 5025 2    50   Input ~ 0
3.3v
Wire Wire Line
	1600 5025 1725 5025
Text GLabel 3400 5950 2    50   Input ~ 0
3.3v
Wire Wire Line
	2900 1950 2950 1950
Wire Wire Line
	6225 1450 6150 1450
Text GLabel 4825 1775 2    50   Input ~ 0
RS_SERIAL_OUT
Text GLabel 6150 1250 0    50   Input ~ 0
RS_SERIAL_IN
Wire Wire Line
	6225 1250 6150 1250
$Comp
L power:GND #PWR016
U 1 1 5E231F19
P 6225 2125
F 0 "#PWR016" H 6225 1875 50  0001 C CNN
F 1 "GND" H 6230 1952 50  0000 C CNN
F 2 "" H 6225 2125 50  0001 C CNN
F 3 "" H 6225 2125 50  0001 C CNN
	1    6225 2125
	1    0    0    -1  
$EndComp
$Comp
L Connector:DB9_Female_MountingHoles J3
U 1 1 5E3595C7
P 6525 1450
F 0 "J3" H 6705 1452 50  0000 L CNN
F 1 "RS232_DSUB" H 6705 1361 50  0000 L CNN
F 2 "lib_fp:DSUB-9_Male_Vertical_Tayda" H 6525 1450 50  0001 C CNN
F 3 " ~" H 6525 1450 50  0001 C CNN
	1    6525 1450
	1    0    0    -1  
$EndComp
NoConn ~ 6225 1050
NoConn ~ 6225 1150
NoConn ~ 6225 1350
NoConn ~ 6225 1550
NoConn ~ 6225 1650
NoConn ~ 6225 1750
Text GLabel 9525 5700 0    50   Input ~ 0
MIDI_OUT_PLUS
Text GLabel 10325 5700 2    50   Input ~ 0
MIDI_OUT_DATA
$Comp
L Connector:DIN-5_180degree J7
U 1 1 5E26D6D4
P 9950 5800
F 0 "J7" H 9950 5525 50  0000 C CNN
F 1 "MIDI_OUT_DIN" H 9950 5434 50  0000 C CNN
F 2 "lib_fp:Tayda5pinMidi-A1010" H 9950 5800 50  0001 C CNN
F 3 "http://www.mouser.com/ds/2/18/40_c091_abd_e-75918.pdf" H 9950 5800 50  0001 C CNN
	1    9950 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 5700 9525 5700
Wire Wire Line
	10325 5700 10250 5700
NoConn ~ 9950 5500
NoConn ~ 9650 5800
NoConn ~ 10250 5800
Text GLabel 9425 3200 0    50   Input ~ 0
MIDI_IN_PLUS
Text GLabel 10225 3200 2    50   Input ~ 0
MIDI_IN_DATA
$Comp
L Connector:DIN-5_180degree J5
U 1 1 5E28B4C2
P 9850 3300
F 0 "J5" H 9850 3025 50  0000 C CNN
F 1 "MIDI_IN_DIN" H 9850 2934 50  0000 C CNN
F 2 "lib_fp:Tayda5pinMidi-A1010" H 9850 3300 50  0001 C CNN
F 3 "http://www.mouser.com/ds/2/18/40_c091_abd_e-75918.pdf" H 9850 3300 50  0001 C CNN
	1    9850 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 3200 9425 3200
Wire Wire Line
	10225 3200 10150 3200
NoConn ~ 9850 3000
NoConn ~ 9550 3300
NoConn ~ 10150 3300
$Comp
L Isolator:6N137 U3
U 1 1 5E2A25A4
P 9075 2000
F 0 "U3" H 9075 2425 50  0000 C CNN
F 1 "6N137" H 9075 2334 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 8875 1700 50  0001 L CIN
F 3 "https://optoelectronics.liteon.com/upload/download/DS70-2008-0032/6N135-L%206N136-L%20series.pdf" H 9075 2000 50  0001 L CNN
	1    9075 2000
	1    0    0    -1  
$EndComp
NoConn ~ 7850 3275
NoConn ~ 7925 5600
$Comp
L Regulator_Linear:L78L33_TO92 U6
U 1 1 5E33912E
P 1300 5025
F 0 "U6" H 1300 5267 50  0000 C CNN
F 1 "L78L33_TO92" H 1300 5176 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 1300 5250 50  0001 C CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/15/55/e5/aa/23/5b/43/fd/CD00000446.pdf/files/CD00000446.pdf/jcr:content/translations/en.CD00000446.pdf" H 1300 4975 50  0001 C CNN
	1    1300 5025
	1    0    0    -1  
$EndComp
Wire Wire Line
	7925 5900 8075 5900
NoConn ~ 7925 5800
NoConn ~ 7925 6000
Wire Wire Line
	7850 3575 8000 3575
NoConn ~ 7850 3475
NoConn ~ 7850 3675
Wire Wire Line
	4350 1775 4825 1775
Wire Wire Line
	4350 1475 4500 1475
$Comp
L 4xxx:4069 U4
U 1 1 5E28F9AC
P 8875 5000
F 0 "U4" H 8875 4683 50  0000 C CNN
F 1 "4069" H 8875 4774 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 8875 5000 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4069ubms.pdf" H 8875 5000 50  0001 C CNN
	1    8875 5000
	-1   0    0    1   
$EndComp
$Comp
L 4xxx:4069 U4
U 2 1 5E2B243C
P 9475 5000
F 0 "U4" H 9475 4683 50  0000 C CNN
F 1 "4069" H 9475 4774 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 9475 5000 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4069ubms.pdf" H 9475 5000 50  0001 C CNN
	2    9475 5000
	-1   0    0    1   
$EndComp
Wire Wire Line
	9775 5000 9950 5000
$Comp
L 4xxx:4069 U4
U 7 1 5E2B6FEB
P 6500 6925
F 0 "U4" H 6730 6971 50  0000 L CNN
F 1 "4069" H 6730 6880 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 6500 6925 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4069ubms.pdf" H 6500 6925 50  0001 C CNN
	7    6500 6925
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5E2B9176
P 6500 7425
F 0 "#PWR018" H 6500 7175 50  0001 C CNN
F 1 "GND" H 6505 7252 50  0000 C CNN
F 2 "" H 6500 7425 50  0001 C CNN
F 3 "" H 6500 7425 50  0001 C CNN
	1    6500 7425
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR017
U 1 1 5E2BA433
P 6500 6425
F 0 "#PWR017" H 6500 6275 50  0001 C CNN
F 1 "+5V" H 6515 6598 50  0000 C CNN
F 2 "" H 6500 6425 50  0001 C CNN
F 3 "" H 6500 6425 50  0001 C CNN
	1    6500 6425
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4069 U4
U 4 1 5E2BFA24
P 5850 6700
F 0 "U4" H 5850 6383 50  0000 C CNN
F 1 "4069" H 5850 6474 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 5850 6700 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4069ubms.pdf" H 5850 6700 50  0001 C CNN
	4    5850 6700
	-1   0    0    1   
$EndComp
$Comp
L 4xxx:4069 U4
U 6 1 5E2C11FA
P 5850 7200
F 0 "U4" H 5850 6883 50  0000 C CNN
F 1 "4069" H 5850 6974 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 5850 7200 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4069ubms.pdf" H 5850 7200 50  0001 C CNN
	6    5850 7200
	-1   0    0    1   
$EndComp
$Comp
L 4xxx:4069 U4
U 3 1 5E2C1EB1
P 5100 6700
F 0 "U4" H 5100 6383 50  0000 C CNN
F 1 "4069" H 5100 6474 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 5100 6700 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4069ubms.pdf" H 5100 6700 50  0001 C CNN
	3    5100 6700
	-1   0    0    1   
$EndComp
$Comp
L 4xxx:4069 U4
U 5 1 5E2C40C8
P 5075 7200
F 0 "U4" H 5075 6883 50  0000 C CNN
F 1 "4069" H 5075 6974 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 5075 7200 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4069ubms.pdf" H 5075 7200 50  0001 C CNN
	5    5075 7200
	-1   0    0    1   
$EndComp
NoConn ~ 4800 6700
NoConn ~ 5400 6700
NoConn ~ 5550 6700
NoConn ~ 6150 6700
NoConn ~ 6150 7200
NoConn ~ 5550 7200
NoConn ~ 5375 7200
NoConn ~ 4775 7200
NoConn ~ 2900 2050
$Comp
L Device:CP C1
U 1 1 5E242FE2
P 3500 1675
F 0 "C1" H 3618 1721 50  0000 L CNN
F 1 "100uf" H 3618 1630 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 3538 1525 50  0001 C CNN
F 3 "~" H 3500 1675 50  0001 C CNN
	1    3500 1675
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 1850 3500 1850
Wire Wire Line
	2900 1750 2900 1525
Wire Wire Line
	2900 1525 3500 1525
Connection ~ 3500 1525
Wire Wire Line
	3500 1825 3500 1850
Connection ~ 3500 1850
Wire Wire Line
	3500 1850 3500 1950
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J1
U 1 1 5E27F2FF
P 1250 3675
F 0 "J1" H 1300 3050 50  0000 C CNN
F 1 "europower" H 1300 3141 50  0000 C CNN
F 2 "lib_fp:PinHeader_2x08_P2.54_Euro" H 1250 3675 50  0001 C CNN
F 3 "~" H 1250 3675 50  0001 C CNN
	1    1250 3675
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR06
U 1 1 5E281F93
P 1750 3375
F 0 "#PWR06" H 1750 3225 50  0001 C CNN
F 1 "+5V" H 1765 3548 50  0000 C CNN
F 2 "" H 1750 3375 50  0001 C CNN
F 3 "" H 1750 3375 50  0001 C CNN
	1    1750 3375
	1    0    0    -1  
$EndComp
NoConn ~ 950  3275
NoConn ~ 950  3375
NoConn ~ 1450 3375
NoConn ~ 1450 3275
NoConn ~ 1450 3575
NoConn ~ 950  3575
$Comp
L power:GND #PWR07
U 1 1 5E29F8A8
P 1725 3975
F 0 "#PWR07" H 1725 3725 50  0001 C CNN
F 1 "GND" H 1730 3802 50  0000 C CNN
F 2 "" H 1725 3975 50  0001 C CNN
F 3 "" H 1725 3975 50  0001 C CNN
	1    1725 3975
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 3675 1725 3675
Wire Wire Line
	1725 3675 1725 3775
Wire Wire Line
	1450 3775 1725 3775
Connection ~ 1725 3775
Wire Wire Line
	1725 3775 1725 3875
Wire Wire Line
	1450 3875 1725 3875
Connection ~ 1725 3875
Wire Wire Line
	1725 3875 1725 3975
NoConn ~ 1450 3975
NoConn ~ 950  3975
Wire Wire Line
	6225 1850 6225 2050
Wire Wire Line
	6525 2050 6225 2050
Connection ~ 6225 2050
Wire Wire Line
	6225 2050 6225 2125
$Comp
L Device:D D2
U 1 1 5E8284AF
P 1600 3475
F 0 "D2" H 1600 3259 50  0000 C CNN
F 1 "1N4148" H 1600 3350 50  0000 C CNN
F 2 "Diode_THT:D_T-1_P5.08mm_Horizontal" H 1600 3475 50  0001 C CNN
F 3 "~" H 1600 3475 50  0001 C CNN
	1    1600 3475
	-1   0    0    1   
$EndComp
Wire Wire Line
	1750 3375 1750 3475
Wire Wire Line
	950  3475 1450 3475
Connection ~ 1450 3475
Wire Wire Line
	950  3675 1450 3675
Connection ~ 1450 3675
Wire Wire Line
	950  3775 1450 3775
Connection ~ 1450 3775
Wire Wire Line
	950  3875 1450 3875
Connection ~ 1450 3875
$Comp
L Connector_Generic:Conn_01x06 J8
U 1 1 5EE5600D
P 4625 5900
F 0 "J8" H 4543 5375 50  0000 C CNN
F 1 "Conn_01x06" H 4543 5466 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 4625 5900 50  0001 C CNN
F 3 "~" H 4625 5900 50  0001 C CNN
	1    4625 5900
	-1   0    0    1   
$EndComp
Text GLabel 4900 5900 2    50   Input ~ 0
SKC_HOST
Text GLabel 4900 6000 2    50   Input ~ 0
MISO_HOST
Text GLabel 4900 6100 2    50   Input ~ 0
MOSI_HOST
Text GLabel 4900 5800 2    50   Input ~ 0
RST_HOST
$Comp
L power:GND #PWR02
U 1 1 5EE5C0CB
P 5475 5700
F 0 "#PWR02" H 5475 5450 50  0001 C CNN
F 1 "GND" H 5480 5527 50  0000 C CNN
F 2 "" H 5475 5700 50  0001 C CNN
F 3 "" H 5475 5700 50  0001 C CNN
	1    5475 5700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 5EE5E849
P 5200 5600
F 0 "#PWR01" H 5200 5450 50  0001 C CNN
F 1 "+5V" H 5215 5773 50  0000 C CNN
F 2 "" H 5200 5600 50  0001 C CNN
F 3 "" H 5200 5600 50  0001 C CNN
	1    5200 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4825 6100 4900 6100
Wire Wire Line
	4825 6000 4900 6000
Wire Wire Line
	4825 5900 4900 5900
Wire Wire Line
	4825 5800 4900 5800
Wire Wire Line
	5475 5700 4825 5700
Wire Wire Line
	4825 5600 5200 5600
Text Notes 4550 5325 0    39   ~ 0
bootloader breakout
Wire Wire Line
	4500 1475 4500 1950
NoConn ~ 4350 1675
NoConn ~ 4350 1875
$EndSCHEMATC
