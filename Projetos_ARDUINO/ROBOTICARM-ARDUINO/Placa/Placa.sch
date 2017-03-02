EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATMEGA328P-P IC?
U 1 1 572D4B0B
P 7900 3550
F 0 "IC?" H 7150 4800 50  0000 L BNN
F 1 "ATMEGA328P-P" H 8300 2150 50  0000 L BNN
F 2 "DIL28" H 7900 3550 50  0000 C CIN
F 3 "" H 7900 3550 50  0000 C CNN
	1    7900 3550
	1    0    0    -1  
$EndComp
$Comp
L Switch_DPST SW?
U 1 1 572D4F37
P 550 1700
F 0 "SW?" H 850 1750 50  0000 C CNN
F 1 "Switch_DPST" H 850 1650 50  0000 C CNN
F 2 "" H 550 1700 50  0000 C CNN
F 3 "" H 550 1700 50  0000 C CNN
	1    550  1700
	1    0    0    -1  
$EndComp
$Comp
L Switch_DPST SW?
U 1 1 572D4FFA
P 7350 1150
F 0 "SW?" H 7650 1200 50  0000 C CNN
F 1 "Switch_DPST" H 7650 1100 50  0000 C CNN
F 2 "" H 7350 1150 50  0000 C CNN
F 3 "" H 7350 1150 50  0000 C CNN
	1    7350 1150
	1    0    0    -1  
$EndComp
$Comp
L Switch_DPST SW?
U 1 1 572D5066
P 3700 1750
F 0 "SW?" H 4000 1800 50  0000 C CNN
F 1 "Switch_DPST" H 4000 1700 50  0000 C CNN
F 2 "" H 3700 1750 50  0000 C CNN
F 3 "" H 3700 1750 50  0000 C CNN
	1    3700 1750
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 572D50C6
P 7850 1750
F 0 "R?" V 7930 1750 50  0000 C CNN
F 1 "R" V 7850 1750 50  0000 C CNN
F 2 "" V 7780 1750 50  0000 C CNN
F 3 "" H 7850 1750 50  0000 C CNN
	1    7850 1750
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 572D51EB
P 9650 1950
F 0 "R?" V 9730 1950 50  0000 C CNN
F 1 "R" V 9650 1950 50  0000 C CNN
F 2 "" V 9580 1950 50  0000 C CNN
F 3 "" H 9650 1950 50  0000 C CNN
	1    9650 1950
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 572D5245
P 8950 2000
F 0 "R?" V 9030 2000 50  0000 C CNN
F 1 "R" V 8950 2000 50  0000 C CNN
F 2 "" V 8880 2000 50  0000 C CNN
F 3 "" H 8950 2000 50  0000 C CNN
	1    8950 2000
	1    0    0    -1  
$EndComp
$Comp
L POT RV?
U 1 1 572D52AC
P 8800 1100
F 0 "RV?" H 8800 1000 50  0000 C CNN
F 1 "POT" H 8800 1100 50  0000 C CNN
F 2 "" H 8800 1100 50  0000 C CNN
F 3 "" H 8800 1100 50  0000 C CNN
	1    8800 1100
	0    1    1    0   
$EndComp
$Comp
L POT RV?
U 1 1 572D5395
P 8500 1900
F 0 "RV?" H 8500 1800 50  0000 C CNN
F 1 "POT" H 8500 1900 50  0000 C CNN
F 2 "" H 8500 1900 50  0000 C CNN
F 3 "" H 8500 1900 50  0000 C CNN
	1    8500 1900
	0    1    1    0   
$EndComp
$Comp
L POT RV?
U 1 1 572D53DC
P 9500 1150
F 0 "RV?" H 9500 1050 50  0000 C CNN
F 1 "POT" H 9500 1150 50  0000 C CNN
F 2 "" H 9500 1150 50  0000 C CNN
F 3 "" H 9500 1150 50  0000 C CNN
	1    9500 1150
	0    1    1    0   
$EndComp
$Comp
L CP C?
U 1 1 572D5426
P 6600 1550
F 0 "C?" H 6625 1650 50  0000 L CNN
F 1 "CP" H 6625 1450 50  0000 L CNN
F 2 "" H 6638 1400 50  0000 C CNN
F 3 "" H 6600 1550 50  0000 C CNN
	1    6600 1550
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 572D5509
P 6150 1400
F 0 "C?" H 6175 1500 50  0000 L CNN
F 1 "CP" H 6175 1300 50  0000 L CNN
F 2 "" H 6188 1250 50  0000 C CNN
F 3 "" H 6150 1400 50  0000 C CNN
	1    6150 1400
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 572D55E3
P 7000 2050
F 0 "C?" H 7025 2150 50  0000 L CNN
F 1 "CP" H 7025 1950 50  0000 L CNN
F 2 "" H 7038 1900 50  0000 C CNN
F 3 "" H 7000 2050 50  0000 C CNN
	1    7000 2050
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 572D563E
P 9200 1400
F 0 "C?" H 9225 1500 50  0000 L CNN
F 1 "CP" H 9225 1300 50  0000 L CNN
F 2 "" H 9238 1250 50  0000 C CNN
F 3 "" H 9200 1400 50  0000 C CNN
	1    9200 1400
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 572D56CC
P 9950 1350
F 0 "C?" H 9975 1450 50  0000 L CNN
F 1 "CP" H 9975 1250 50  0000 L CNN
F 2 "" H 9988 1200 50  0000 C CNN
F 3 "" H 9950 1350 50  0000 C CNN
	1    9950 1350
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 572D572D
P 8400 1100
F 0 "C?" H 8425 1200 50  0000 L CNN
F 1 "CP" H 8425 1000 50  0000 L CNN
F 2 "" H 8438 950 50  0000 C CNN
F 3 "" H 8400 1100 50  0000 C CNN
	1    8400 1100
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P?
U 1 1 572D5A9D
P 10650 4200
F 0 "P?" H 10650 4400 50  0000 C CNN
F 1 "CONN_01X03" V 10750 4200 50  0000 C CNN
F 2 "" H 10650 4200 50  0000 C CNN
F 3 "" H 10650 4200 50  0000 C CNN
	1    10650 4200
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P?
U 1 1 572D5BF9
P 10650 4800
F 0 "P?" H 10650 5000 50  0000 C CNN
F 1 "CONN_01X03" V 10750 4800 50  0000 C CNN
F 2 "" H 10650 4800 50  0000 C CNN
F 3 "" H 10650 4800 50  0000 C CNN
	1    10650 4800
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P?
U 1 1 572D5C7F
P 10650 5400
F 0 "P?" H 10650 5600 50  0000 C CNN
F 1 "CONN_01X03" V 10750 5400 50  0000 C CNN
F 2 "" H 10650 5400 50  0000 C CNN
F 3 "" H 10650 5400 50  0000 C CNN
	1    10650 5400
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P?
U 1 1 572D5CEE
P 10600 6000
F 0 "P?" H 10600 6200 50  0000 C CNN
F 1 "CONN_01X03" V 10700 6000 50  0000 C CNN
F 2 "" H 10600 6000 50  0000 C CNN
F 3 "" H 10600 6000 50  0000 C CNN
	1    10600 6000
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 572D5DA0
P 10200 4200
F 0 "C?" H 10225 4300 50  0000 L CNN
F 1 "CP" H 10225 4100 50  0000 L CNN
F 2 "" H 10238 4050 50  0000 C CNN
F 3 "" H 10200 4200 50  0000 C CNN
	1    10200 4200
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 572D5E35
P 10200 4750
F 0 "C?" H 10225 4850 50  0000 L CNN
F 1 "CP" H 10225 4650 50  0000 L CNN
F 2 "" H 10238 4600 50  0000 C CNN
F 3 "" H 10200 4750 50  0000 C CNN
	1    10200 4750
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 572D5E9B
P 10200 5400
F 0 "C?" H 10225 5500 50  0000 L CNN
F 1 "CP" H 10225 5300 50  0000 L CNN
F 2 "" H 10238 5250 50  0000 C CNN
F 3 "" H 10200 5400 50  0000 C CNN
	1    10200 5400
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 572D5F1A
P 10200 6000
F 0 "C?" H 10225 6100 50  0000 L CNN
F 1 "CP" H 10225 5900 50  0000 L CNN
F 2 "" H 10238 5850 50  0000 C CNN
F 3 "" H 10200 6000 50  0000 C CNN
	1    10200 6000
	1    0    0    -1  
$EndComp
$Comp
L 7400 U?
U 1 1 572D6034
P 5250 2300
F 0 "U?" H 5250 2350 50  0000 C CNN
F 1 "7400" H 5250 2200 50  0000 C CNN
F 2 "" H 5250 2300 50  0000 C CNN
F 3 "" H 5250 2300 50  0000 C CNN
	1    5250 2300
	1    0    0    -1  
$EndComp
$Comp
L 7400 U?
U 3 1 572D61B0
P 1700 3250
F 0 "U?" H 1700 3300 50  0000 C CNN
F 1 "7400" H 1700 3150 50  0000 C CNN
F 2 "" H 1700 3250 50  0000 C CNN
F 3 "" H 1700 3250 50  0000 C CNN
	3    1700 3250
	1    0    0    -1  
$EndComp
$Comp
L 7400 U?
U 4 1 572D63B5
P 1700 4000
F 0 "U?" H 1700 4050 50  0000 C CNN
F 1 "7400" H 1700 3900 50  0000 C CNN
F 2 "" H 1700 4000 50  0000 C CNN
F 3 "" H 1700 4000 50  0000 C CNN
	4    1700 4000
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 572D6B1F
P 1050 750
F 0 "R?" V 1130 750 50  0000 C CNN
F 1 "R" V 1050 750 50  0000 C CNN
F 2 "" V 980 750 50  0000 C CNN
F 3 "" H 1050 750 50  0000 C CNN
	1    1050 750 
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 572D6CF6
P 1050 2250
F 0 "R?" V 1130 2250 50  0000 C CNN
F 1 "R" V 1050 2250 50  0000 C CNN
F 2 "" V 980 2250 50  0000 C CNN
F 3 "" H 1050 2250 50  0000 C CNN
	1    1050 2250
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 572D724E
P 1050 4350
F 0 "R?" V 1130 4350 50  0000 C CNN
F 1 "R" V 1050 4350 50  0000 C CNN
F 2 "" V 980 4350 50  0000 C CNN
F 3 "" H 1050 4350 50  0000 C CNN
	1    1050 4350
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 572D733D
P 1100 2900
F 0 "R?" V 1180 2900 50  0000 C CNN
F 1 "R" V 1100 2900 50  0000 C CNN
F 2 "" V 1030 2900 50  0000 C CNN
F 3 "" H 1100 2900 50  0000 C CNN
	1    1100 2900
	1    0    0    -1  
$EndComp
$Comp
L 7400 U?
U 1 1 572D838C
P 1750 5050
F 0 "U?" H 1750 5100 50  0000 C CNN
F 1 "7400" H 1750 4950 50  0000 C CNN
F 2 "" H 1750 5050 50  0000 C CNN
F 3 "" H 1750 5050 50  0000 C CNN
	1    1750 5050
	1    0    0    -1  
$EndComp
$Comp
L 7400 U?
U 2 1 572D8592
P 1750 5750
F 0 "U?" H 1750 5800 50  0000 C CNN
F 1 "7400" H 1750 5650 50  0000 C CNN
F 2 "" H 1750 5750 50  0000 C CNN
F 3 "" H 1750 5750 50  0000 C CNN
	2    1750 5750
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 572D8881
P 1150 4700
F 0 "R?" V 1230 4700 50  0000 C CNN
F 1 "R" V 1150 4700 50  0000 C CNN
F 2 "" V 1080 4700 50  0000 C CNN
F 3 "" H 1150 4700 50  0000 C CNN
	1    1150 4700
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 572D8A48
P 1150 6150
F 0 "R?" V 1230 6150 50  0000 C CNN
F 1 "R" V 1150 6150 50  0000 C CNN
F 2 "" V 1080 6150 50  0000 C CNN
F 3 "" H 1150 6150 50  0000 C CNN
	1    1150 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 4850 1150 4950
$Comp
L LM7805CT U?
U 1 1 572D8E51
P 4550 1050
F 0 "U?" H 4350 1250 50  0000 C CNN
F 1 "LM7805CT" H 4550 1250 50  0000 L CNN
F 2 "TO-220" H 4550 1150 50  0000 C CIN
F 3 "" H 4550 1050 50  0000 C CNN
	1    4550 1050
	-1   0    0    1   
$EndComp
$Comp
L BARREL_JACK CON?
U 1 1 572D9133
P 6000 800
F 0 "CON?" H 6000 1050 50  0000 C CNN
F 1 "BARREL_JACK" H 6000 600 50  0000 C CNN
F 2 "" H 6000 800 50  0000 C CNN
F 3 "" H 6000 800 50  0000 C CNN
	1    6000 800 
	-1   0    0    1   
$EndComp
$Comp
L D D?
U 1 1 572D936A
P 5450 900
F 0 "D?" H 5450 1000 50  0000 C CNN
F 1 "D" H 5450 800 50  0000 C CNN
F 2 "" H 5450 900 50  0000 C CNN
F 3 "" H 5450 900 50  0000 C CNN
	1    5450 900 
	1    0    0    -1  
$EndComp
$Comp
L 7400 U?
U 2 1 572D60FD
P 5200 3800
F 0 "U?" H 5200 3850 50  0000 C CNN
F 1 "7400" H 5200 3700 50  0000 C CNN
F 2 "" H 5200 3800 50  0000 C CNN
F 3 "" H 5200 3800 50  0000 C CNN
	2    5200 3800
	1    0    0    -1  
$EndComp
$EndSCHEMATC
