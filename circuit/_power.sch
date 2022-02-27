EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
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
LIBS:dac7614
LIBS:org_opa
LIBS:poweramp
LIBS:q-opa
LIBS:s7136
LIBS:aki
LIBS:lt_chargepump
LIBS:kagura-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 5
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
L Conn_01x02_Male J?
U 1 1 5C0563DF
P 950 1200
F 0 "J?" H 950 1300 50  0000 C CNN
F 1 "Conn_01x02_Male" H 950 1000 50  0000 C CNN
F 2 "" H 950 1200 50  0001 C CNN
F 3 "" H 950 1200 50  0001 C CNN
	1    950  1200
	1    0    0    -1  
$EndComp
$Comp
L SW_DPDT_x2 SW?
U 1 1 5C05640C
P 2100 1200
F 0 "SW?" H 2100 1370 50  0000 C CNN
F 1 "SW_DPDT_x2" H 2100 1000 50  0000 C CNN
F 2 "" H 2100 1200 50  0001 C CNN
F 3 "" H 2100 1200 50  0001 C CNN
	1    2100 1200
	1    0    0    -1  
$EndComp
$Comp
L SW_DPDT_x2 SW?
U 2 1 5C056431
P 2100 2000
F 0 "SW?" H 2100 2170 50  0000 C CNN
F 1 "SW_DPDT_x2" H 2100 1800 50  0000 C CNN
F 2 "" H 2100 2000 50  0001 C CNN
F 3 "" H 2100 2000 50  0001 C CNN
	2    2100 2000
	1    0    0    -1  
$EndComp
$Comp
L Polyfuse F?
U 1 1 5C0565AB
P 1550 1200
F 0 "F?" V 1450 1200 50  0000 C CNN
F 1 "Polyfuse" V 1650 1200 50  0000 C CNN
F 2 "" H 1600 1000 50  0001 L CNN
F 3 "" H 1550 1200 50  0001 C CNN
	1    1550 1200
	0    1    1    0   
$EndComp
Wire Wire Line
	1150 1200 1400 1200
Wire Wire Line
	1900 1200 1700 1200
Wire Wire Line
	1900 2000 1350 2000
Wire Wire Line
	1350 2000 1350 1350
Wire Wire Line
	1350 1300 1150 1300
$Comp
L PWR_FLAG #FLG?
U 1 1 5C056729
P 2550 1200
F 0 "#FLG?" H 2550 1275 50  0001 C CNN
F 1 "PWR_FLAG" H 2550 1350 50  0000 C CNN
F 2 "" H 2550 1200 50  0001 C CNN
F 3 "" H 2550 1200 50  0001 C CNN
	1    2550 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1100 2350 1100
Wire Wire Line
	2350 1100 2350 1200
Wire Wire Line
	2350 1200 6100 1200
$Comp
L PWR_FLAG #FLG?
U 1 1 5C056775
P 2550 2000
F 0 "#FLG?" H 2550 2075 50  0001 C CNN
F 1 "PWR_FLAG" H 2550 2150 50  0000 C CNN
F 2 "" H 2550 2000 50  0001 C CNN
F 3 "" H 2550 2000 50  0001 C CNN
	1    2550 2000
	-1   0    0    1   
$EndComp
Wire Wire Line
	2300 1900 2350 1900
Wire Wire Line
	2350 1900 2350 2000
Wire Wire Line
	2350 2000 4200 2000
$Comp
L GNDPWR #PWR?
U 1 1 5C0568AF
P 6000 1750
F 0 "#PWR?" H 6000 1550 50  0001 C CNN
F 1 "GNDPWR" H 6050 1600 50  0000 C CNN
F 2 "" H 6000 1700 50  0001 C CNN
F 3 "" H 6000 1700 50  0001 C CNN
	1    6000 1750
	1    0    0    -1  
$EndComp
$Comp
L -9VA #PWR?
U 1 1 5C0568F3
P 2950 2000
F 0 "#PWR?" H 2950 1875 50  0001 C CNN
F 1 "-9VA" H 2950 2150 50  0000 C CNN
F 2 "" H 2950 2000 50  0001 C CNN
F 3 "" H 2950 2000 50  0001 C CNN
	1    2950 2000
	-1   0    0    1   
$EndComp
$Comp
L +9VA #PWR?
U 1 1 5C05690F
P 2950 1200
F 0 "#PWR?" H 2950 1075 50  0001 C CNN
F 1 "+9VA" H 2950 1350 50  0000 C CNN
F 2 "" H 2950 1200 50  0001 C CNN
F 3 "" H 2950 1200 50  0001 C CNN
	1    2950 1200
	1    0    0    -1  
$EndComp
Connection ~ 2550 2000
Connection ~ 2550 1200
$Comp
L CP C?
U 1 1 5C056AD7
P 3100 1550
F 0 "C?" H 3125 1650 50  0000 L CNN
F 1 "CP" H 3125 1450 50  0000 L CNN
F 2 "" H 3138 1400 50  0001 C CNN
F 3 "" H 3100 1550 50  0001 C CNN
	1    3100 1550
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 5C056B51
P 3350 1550
F 0 "C?" H 3375 1650 50  0000 L CNN
F 1 "CP" H 3375 1450 50  0000 L CNN
F 2 "" H 3388 1400 50  0001 C CNN
F 3 "" H 3350 1550 50  0001 C CNN
	1    3350 1550
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C056B7A
P 2700 1400
F 0 "R?" V 2780 1400 50  0000 C CNN
F 1 "R" V 2700 1400 50  0000 C CNN
F 2 "" V 2630 1400 50  0001 C CNN
F 3 "" H 2700 1400 50  0001 C CNN
	1    2700 1400
	1    0    0    -1  
$EndComp
$Comp
L LED D?
U 1 1 5C056BC4
P 2700 1800
F 0 "D?" H 2700 1900 50  0000 C CNN
F 1 "LED" H 2700 1700 50  0000 C CNN
F 2 "" H 2700 1800 50  0001 C CNN
F 3 "" H 2700 1800 50  0001 C CNN
	1    2700 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2700 1550 2700 1650
Wire Wire Line
	2700 1950 2700 2000
Connection ~ 2700 2000
Wire Wire Line
	2700 1250 2700 1200
Connection ~ 2700 1200
Wire Wire Line
	3100 1700 3100 2000
Connection ~ 2950 2000
Wire Wire Line
	3100 1200 3100 1400
Connection ~ 2950 1200
$Comp
L C C?
U 1 1 5C056D17
P 3600 1550
F 0 "C?" H 3625 1650 50  0000 L CNN
F 1 "C" H 3625 1450 50  0000 L CNN
F 2 "" H 3638 1400 50  0001 C CNN
F 3 "" H 3600 1550 50  0001 C CNN
	1    3600 1550
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5C056DA2
P 3850 1550
F 0 "C?" H 3875 1650 50  0000 L CNN
F 1 "C" H 3875 1450 50  0000 L CNN
F 2 "" H 3888 1400 50  0001 C CNN
F 3 "" H 3850 1550 50  0001 C CNN
	1    3850 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 1200 3350 1400
Wire Wire Line
	3350 1700 3350 2000
Wire Wire Line
	3600 1700 3600 2000
Wire Wire Line
	3850 2000 3850 1700
Connection ~ 3600 2000
Wire Wire Line
	3850 1200 3850 1400
Wire Wire Line
	3600 1400 3600 1200
Connection ~ 3600 1200
Connection ~ 3100 1200
Connection ~ 3350 1200
Connection ~ 3350 2000
Connection ~ 3100 2000
Text GLabel 4350 950  2    60   Output ~ 0
POWER_VBAT
$Comp
L R R?
U 1 1 5C05754D
P 4150 950
F 0 "R?" V 4230 950 50  0000 C CNN
F 1 "R" V 4150 950 50  0000 C CNN
F 2 "" V 4080 950 50  0001 C CNN
F 3 "" H 4150 950 50  0001 C CNN
	1    4150 950 
	0    1    1    0   
$EndComp
Wire Wire Line
	4350 950  4300 950 
Wire Wire Line
	4000 950  3950 950 
Wire Wire Line
	3950 950  3950 1200
Connection ~ 3850 1200
$Comp
L R-78E3.3-0.5_R-78E3.3/5.0-0.5 IC?
U 1 1 5C0579B8
P 6700 1200
F 0 "IC?" H 6700 1750 100 0000 C CNN
F 1 "R-78E3.3-0.5_R-78E3.3/5.0-0.5" H 6700 1600 100 0000 C CNN
F 2 "" H 6700 1200 60  0000 C CNN
F 3 "" H 6700 1200 60  0000 C CNN
	1    6700 1200
	1    0    0    -1  
$EndComp
Connection ~ 3950 1200
$Comp
L R R?
U 1 1 5C058160
P 5400 1700
F 0 "R?" V 5480 1700 50  0000 C CNN
F 1 "R" V 5400 1700 50  0000 C CNN
F 2 "" V 5330 1700 50  0001 C CNN
F 3 "" H 5400 1700 50  0001 C CNN
	1    5400 1700
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 5C058248
P 5150 1900
F 0 "C?" H 5175 2000 50  0000 L CNN
F 1 "C" H 5175 1800 50  0000 L CNN
F 2 "" H 5188 1750 50  0001 C CNN
F 3 "" H 5150 1900 50  0001 C CNN
	1    5150 1900
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C05833F
P 5400 2200
F 0 "R?" V 5480 2200 50  0000 C CNN
F 1 "R" V 5400 2200 50  0000 C CNN
F 2 "" V 5330 2200 50  0001 C CNN
F 3 "" H 5400 2200 50  0001 C CNN
	1    5400 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	4400 2200 5250 2200
Wire Wire Line
	5150 2200 5150 2050
Wire Wire Line
	5050 1700 5250 1700
Wire Wire Line
	5150 1750 5150 1700
Connection ~ 5150 1700
Wire Wire Line
	5550 1700 5650 1700
Wire Wire Line
	5600 1700 5600 2200
Wire Wire Line
	5600 2200 5550 2200
Wire Wire Line
	4400 2200 4400 1800
Wire Wire Line
	4400 1800 4450 1800
Connection ~ 5150 2200
$Comp
L R R?
U 1 1 5C058DD5
P 4200 1400
F 0 "R?" V 4280 1400 50  0000 C CNN
F 1 "R" V 4200 1400 50  0000 C CNN
F 2 "" V 4130 1400 50  0001 C CNN
F 3 "" H 4200 1400 50  0001 C CNN
	1    4200 1400
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C058FD6
P 4200 1800
F 0 "R?" V 4280 1800 50  0000 C CNN
F 1 "R" V 4200 1800 50  0000 C CNN
F 2 "" V 4130 1800 50  0001 C CNN
F 3 "" H 4200 1800 50  0001 C CNN
	1    4200 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 1550 4200 1650
Wire Wire Line
	4450 1600 4200 1600
Connection ~ 4200 1600
Wire Wire Line
	4200 1250 4200 1200
Connection ~ 4200 1200
Connection ~ 3850 2000
Wire Wire Line
	4200 1950 4200 2600
Connection ~ 4200 2000
Connection ~ 4650 1200
$Comp
L TL084 U?
U 1 1 5C05A0AE
P 6400 3950
F 0 "U?" H 6400 4150 50  0000 L CNN
F 1 "TL084" H 6400 3750 50  0000 L CNN
F 2 "" H 6350 4050 50  0001 C CNN
F 3 "" H 6450 4150 50  0001 C CNN
	1    6400 3950
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C05A0B4
P 7050 3950
F 0 "R?" V 7130 3950 50  0000 C CNN
F 1 "R" V 7050 3950 50  0000 C CNN
F 2 "" V 6980 3950 50  0001 C CNN
F 3 "" H 7050 3950 50  0001 C CNN
	1    7050 3950
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 5C05A0BA
P 6800 4150
F 0 "C?" H 6825 4250 50  0000 L CNN
F 1 "C" H 6825 4050 50  0000 L CNN
F 2 "" H 6838 4000 50  0001 C CNN
F 3 "" H 6800 4150 50  0001 C CNN
	1    6800 4150
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C05A0C0
P 7050 4450
F 0 "R?" V 7130 4450 50  0000 C CNN
F 1 "R" V 7050 4450 50  0000 C CNN
F 2 "" V 6980 4450 50  0001 C CNN
F 3 "" H 7050 4450 50  0001 C CNN
	1    7050 4450
	0    1    1    0   
$EndComp
Wire Wire Line
	6050 4450 6900 4450
Wire Wire Line
	6800 4450 6800 4300
Wire Wire Line
	6700 3950 6900 3950
Wire Wire Line
	6800 4000 6800 3950
Connection ~ 6800 3950
Wire Wire Line
	7200 3950 7400 3950
Wire Wire Line
	7250 3950 7250 4450
Wire Wire Line
	7250 4450 7200 4450
Wire Wire Line
	6050 4450 6050 4050
Wire Wire Line
	6050 4050 6100 4050
Connection ~ 6800 4450
$Comp
L R R?
U 1 1 5C05A0D1
P 5850 3650
F 0 "R?" V 5930 3650 50  0000 C CNN
F 1 "R" V 5850 3650 50  0000 C CNN
F 2 "" V 5780 3650 50  0001 C CNN
F 3 "" H 5850 3650 50  0001 C CNN
	1    5850 3650
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C05A0D7
P 5850 4050
F 0 "R?" V 5930 4050 50  0000 C CNN
F 1 "R" V 5850 4050 50  0000 C CNN
F 2 "" V 5780 4050 50  0001 C CNN
F 3 "" H 5850 4050 50  0001 C CNN
	1    5850 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3800 5850 3900
Wire Wire Line
	6100 3850 5850 3850
Connection ~ 5850 3850
Wire Wire Line
	5850 4200 5850 4450
Wire Wire Line
	6300 3650 6300 3650
Wire Wire Line
	6300 4250 6300 4250
$Comp
L R R?
U 1 1 5C05A894
P 4900 2600
F 0 "R?" V 4980 2600 50  0000 C CNN
F 1 "0" V 4900 2600 50  0000 C CNN
F 2 "" V 4830 2600 50  0001 C CNN
F 3 "" H 4900 2600 50  0001 C CNN
	1    4900 2600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4200 2600 4750 2600
Wire Wire Line
	7350 2600 5050 2600
Wire Wire Line
	6700 2600 6700 1700
Connection ~ 5600 1700
$Comp
L R R?
U 1 1 5C05B766
P 5800 1700
F 0 "R?" V 5880 1700 50  0000 C CNN
F 1 "0" V 5800 1700 50  0000 C CNN
F 2 "" V 5730 1700 50  0001 C CNN
F 3 "" H 5800 1700 50  0001 C CNN
	1    5800 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 1750 6000 1700
Wire Wire Line
	6000 1700 5950 1700
$Comp
L GND #PWR?
U 1 1 5C05B9EC
P 6600 2700
F 0 "#PWR?" H 6600 2450 50  0001 C CNN
F 1 "GND" H 6600 2550 50  0000 C CNN
F 2 "" H 6600 2700 50  0001 C CNN
F 3 "" H 6600 2700 50  0001 C CNN
	1    6600 2700
	1    0    0    -1  
$EndComp
Connection ~ 6700 2600
$Comp
L CP C?
U 1 1 5C05BC0F
P 7600 1850
F 0 "C?" H 7625 1950 50  0000 L CNN
F 1 "CP" H 7625 1750 50  0000 L CNN
F 2 "" H 7638 1700 50  0001 C CNN
F 3 "" H 7600 1850 50  0001 C CNN
	1    7600 1850
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 5C05BD84
P 1550 3650
F 0 "C?" H 1575 3750 50  0000 L CNN
F 1 "CP" H 1575 3550 50  0000 L CNN
F 2 "" H 1588 3500 50  0001 C CNN
F 3 "" H 1550 3650 50  0001 C CNN
	1    1550 3650
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5C05BDD6
P 7350 1850
F 0 "C?" H 7375 1950 50  0000 L CNN
F 1 "C" H 7375 1750 50  0000 L CNN
F 2 "" H 7388 1700 50  0001 C CNN
F 3 "" H 7350 1850 50  0001 C CNN
	1    7350 1850
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5C05BE4B
P 2400 3650
F 0 "C?" H 2425 3750 50  0000 L CNN
F 1 "C" H 2425 3550 50  0000 L CNN
F 2 "" H 2438 3500 50  0001 C CNN
F 3 "" H 2400 3650 50  0001 C CNN
	1    2400 3650
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 5C05C50F
P 2650 3650
F 0 "C?" H 2675 3750 50  0000 L CNN
F 1 "CP" H 2675 3550 50  0000 L CNN
F 2 "" H 2688 3500 50  0001 C CNN
F 3 "" H 2650 3650 50  0001 C CNN
	1    2650 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 1150 7350 1700
Wire Wire Line
	7350 1200 7300 1200
Wire Wire Line
	7350 2000 7350 2600
Wire Wire Line
	7350 2100 7600 2100
Wire Wire Line
	7600 2100 7600 2000
Connection ~ 7350 2100
Wire Wire Line
	7600 1700 7600 1600
Wire Wire Line
	7600 1600 7350 1600
Connection ~ 7350 1600
Wire Wire Line
	6600 2700 6600 2600
Connection ~ 6600 2600
$Comp
L VCC #PWR?
U 1 1 5C05D5E2
P 7350 1150
F 0 "#PWR?" H 7350 1000 50  0001 C CNN
F 1 "VCC" H 7350 1300 50  0000 C CNN
F 2 "" H 7350 1150 50  0001 C CNN
F 3 "" H 7350 1150 50  0001 C CNN
	1    7350 1150
	1    0    0    -1  
$EndComp
Connection ~ 7350 1200
$Comp
L VCC #PWR?
U 1 1 5C05DC78
P 2950 3550
F 0 "#PWR?" H 2950 3400 50  0001 C CNN
F 1 "VCC" H 2950 3700 50  0000 C CNN
F 2 "" H 2950 3550 50  0001 C CNN
F 3 "" H 2950 3550 50  0001 C CNN
	1    2950 3550
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCEC Q?
U 1 1 5C05DEB0
P 4650 3400
F 0 "Q?" H 4850 3450 50  0000 L CNN
F 1 "Q_NPN_BCEC" H 4850 3350 50  0000 L CNN
F 2 "" H 4850 3500 50  0001 C CNN
F 3 "" H 4650 3400 50  0001 C CNN
	1    4650 3400
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 5C05EBD9
P 4450 3700
F 0 "R?" V 4530 3700 50  0000 C CNN
F 1 "R" V 4450 3700 50  0000 C CNN
F 2 "" V 4380 3700 50  0001 C CNN
F 3 "" H 4450 3700 50  0001 C CNN
	1    4450 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 3700 4750 3700
Wire Wire Line
	4650 3700 4650 3600
Wire Wire Line
	4300 3700 4250 3700
$Comp
L R R?
U 1 1 5C05EEE0
P 4900 3700
F 0 "R?" V 4980 3700 50  0000 C CNN
F 1 "R" V 4900 3700 50  0000 C CNN
F 2 "" V 4830 3700 50  0001 C CNN
F 3 "" H 4900 3700 50  0001 C CNN
	1    4900 3700
	0    1    1    0   
$EndComp
Connection ~ 4650 3700
Wire Wire Line
	5050 3700 5100 3700
Wire Wire Line
	5100 3700 5100 3300
Wire Wire Line
	4850 3300 5850 3300
Wire Wire Line
	2250 3200 4450 3200
Wire Wire Line
	4400 3200 4400 3300
Connection ~ 4400 3300
$Comp
L +9VA #PWR?
U 1 1 5C06074C
P 1350 3150
F 0 "#PWR?" H 1350 3025 50  0001 C CNN
F 1 "+9VA" H 1350 3300 50  0000 C CNN
F 2 "" H 1350 3150 50  0001 C CNN
F 3 "" H 1350 3150 50  0001 C CNN
	1    1350 3150
	1    0    0    -1  
$EndComp
$Comp
L -9VA #PWR?
U 1 1 5C060FC0
P 1350 4400
F 0 "#PWR?" H 1350 4275 50  0001 C CNN
F 1 "-9VA" H 1350 4550 50  0000 C CNN
F 2 "" H 1350 4400 50  0001 C CNN
F 3 "" H 1350 4400 50  0001 C CNN
	1    1350 4400
	-1   0    0    1   
$EndComp
Wire Wire Line
	2950 3550 2950 3600
Wire Wire Line
	2950 3600 3000 3600
Wire Wire Line
	3350 3650 3350 3600
Wire Wire Line
	3300 3600 3650 3600
Connection ~ 3350 3600
Connection ~ 4400 3200
$Comp
L TL084 U?
U 1 1 5C062D66
P 4750 1700
F 0 "U?" H 4750 1900 50  0000 L CNN
F 1 "TL084" H 4750 1500 50  0000 L CNN
F 2 "" H 4700 1800 50  0001 C CNN
F 3 "" H 4800 1900 50  0001 C CNN
	1    4750 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 3800 3600 3800
Wire Wire Line
	1350 4400 5850 4400
Connection ~ 5100 3300
$Comp
L L L?
U 1 1 5C063F14
P 2100 3200
F 0 "L?" V 2050 3200 50  0000 C CNN
F 1 "L" V 2175 3200 50  0000 C CNN
F 2 "" H 2100 3200 50  0001 C CNN
F 3 "" H 2100 3200 50  0001 C CNN
	1    2100 3200
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 5C064F62
P 1800 3650
F 0 "C?" H 1825 3750 50  0000 L CNN
F 1 "C" H 1825 3550 50  0000 L CNN
F 2 "" H 1838 3500 50  0001 C CNN
F 3 "" H 1800 3650 50  0001 C CNN
	1    1800 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 3200 1800 3500
Wire Wire Line
	1350 3150 1350 3200
Wire Wire Line
	1350 3200 1950 3200
Wire Wire Line
	1550 3500 1550 3450
Wire Wire Line
	1550 3450 1800 3450
Connection ~ 1800 3450
Wire Wire Line
	1550 3800 1550 3900
Wire Wire Line
	1550 3900 1800 3900
Wire Wire Line
	1800 3800 1800 4400
Connection ~ 1800 3900
Connection ~ 1800 3200
Wire Wire Line
	2400 3200 2400 3500
Wire Wire Line
	2400 3800 2400 4400
Connection ~ 1800 4400
Wire Wire Line
	2650 3500 2650 3450
Wire Wire Line
	2650 3450 2400 3450
Connection ~ 2400 3450
Wire Wire Line
	2400 3900 2650 3900
Wire Wire Line
	2650 3900 2650 3800
Connection ~ 2400 3900
Connection ~ 2400 3200
$Comp
L R R?
U 1 1 5C0615DF
P 3150 3600
F 0 "R?" V 3230 3600 50  0000 C CNN
F 1 "R" V 3150 3600 50  0000 C CNN
F 2 "" V 3080 3600 50  0001 C CNN
F 3 "" H 3150 3600 50  0001 C CNN
	1    3150 3600
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 5C061905
P 3350 3800
F 0 "C?" H 3375 3900 50  0000 L CNN
F 1 "C" H 3375 3700 50  0000 L CNN
F 2 "" H 3388 3650 50  0001 C CNN
F 3 "" H 3350 3800 50  0001 C CNN
	1    3350 3800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5C06715E
P 3350 3950
F 0 "#PWR?" H 3350 3700 50  0001 C CNN
F 1 "GND" H 3350 3800 50  0000 C CNN
F 2 "" H 3350 3950 50  0001 C CNN
F 3 "" H 3350 3950 50  0001 C CNN
	1    3350 3950
	1    0    0    -1  
$EndComp
Connection ~ 2400 4400
$Comp
L +9VA #PWR?
U 1 1 5C0679F0
P 3850 3400
F 0 "#PWR?" H 3850 3275 50  0001 C CNN
F 1 "+9VA" H 3850 3550 50  0000 C CNN
F 2 "" H 3850 3400 50  0001 C CNN
F 3 "" H 3850 3400 50  0001 C CNN
	1    3850 3400
	1    0    0    -1  
$EndComp
$Comp
L -9VA #PWR?
U 1 1 5C067CB9
P 3850 4000
F 0 "#PWR?" H 3850 3875 50  0001 C CNN
F 1 "-9VA" H 3850 4150 50  0000 C CNN
F 2 "" H 3850 4000 50  0001 C CNN
F 3 "" H 3850 4000 50  0001 C CNN
	1    3850 4000
	-1   0    0    1   
$EndComp
$Comp
L TL084 U?
U 1 1 5C060C1F
P 3950 3700
F 0 "U?" H 3950 3900 50  0000 L CNN
F 1 "TL084" H 3950 3500 50  0000 L CNN
F 2 "" H 3900 3800 50  0001 C CNN
F 3 "" H 4000 3900 50  0001 C CNN
	1    3950 3700
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 5C0687EB
P 5600 3800
F 0 "C?" H 5625 3900 50  0000 L CNN
F 1 "CP" H 5625 3700 50  0000 L CNN
F 2 "" H 5638 3650 50  0001 C CNN
F 3 "" H 5600 3800 50  0001 C CNN
	1    5600 3800
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5C06892E
P 5350 3800
F 0 "C?" H 5375 3900 50  0000 L CNN
F 1 "C" H 5375 3700 50  0000 L CNN
F 2 "" H 5388 3650 50  0001 C CNN
F 3 "" H 5350 3800 50  0001 C CNN
	1    5350 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3250 5850 3500
Wire Wire Line
	5600 3550 5600 3650
Wire Wire Line
	5600 3550 5350 3550
Wire Wire Line
	5350 3300 5350 3650
Wire Wire Line
	5350 3950 5350 4400
Wire Wire Line
	5350 4000 5600 4000
Wire Wire Line
	5600 4000 5600 3950
Connection ~ 5350 4000
Connection ~ 5350 3300
Connection ~ 5350 3550
Connection ~ 5350 4400
$Comp
L +9VA #PWR?
U 1 1 5C06AC46
P 6300 3650
F 0 "#PWR?" H 6300 3525 50  0001 C CNN
F 1 "+9VA" H 6300 3800 50  0000 C CNN
F 2 "" H 6300 3650 50  0001 C CNN
F 3 "" H 6300 3650 50  0001 C CNN
	1    6300 3650
	1    0    0    -1  
$EndComp
$Comp
L -9VA #PWR?
U 1 1 5C06B1E3
P 6300 4250
F 0 "#PWR?" H 6300 4125 50  0001 C CNN
F 1 "-9VA" H 6300 4400 50  0000 C CNN
F 2 "" H 6300 4250 50  0001 C CNN
F 3 "" H 6300 4250 50  0001 C CNN
	1    6300 4250
	-1   0    0    1   
$EndComp
Connection ~ 7250 3950
$Comp
L R R?
U 1 1 5C06B708
P 7550 3950
F 0 "R?" V 7630 3950 50  0000 C CNN
F 1 "0" V 7550 3950 50  0000 C CNN
F 2 "" V 7480 3950 50  0001 C CNN
F 3 "" H 7550 3950 50  0001 C CNN
	1    7550 3950
	0    1    1    0   
$EndComp
$Comp
L GNDA #PWR?
U 1 1 5C06B8A6
P 7750 4000
F 0 "#PWR?" H 7750 3750 50  0001 C CNN
F 1 "GNDA" H 7750 3850 50  0000 C CNN
F 2 "" H 7750 4000 50  0001 C CNN
F 3 "" H 7750 4000 50  0001 C CNN
	1    7750 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 4000 7750 3950
Wire Wire Line
	7750 3950 7700 3950
$Comp
L VDDA #PWR?
U 1 1 5C06BD46
P 5850 3250
F 0 "#PWR?" H 5850 3100 50  0001 C CNN
F 1 "VDDA" H 5850 3400 50  0000 C CNN
F 2 "" H 5850 3250 50  0001 C CNN
F 3 "" H 5850 3250 50  0001 C CNN
	1    5850 3250
	1    0    0    -1  
$EndComp
Connection ~ 5850 3300
$Comp
L VSSA #PWR?
U 1 1 5C06C0F6
P 5850 4450
F 0 "#PWR?" H 5850 4300 50  0001 C CNN
F 1 "VSSA" H 5850 4600 50  0000 C CNN
F 2 "" H 5850 4450 50  0001 C CNN
F 3 "" H 5850 4450 50  0001 C CNN
	1    5850 4450
	-1   0    0    1   
$EndComp
Connection ~ 5850 4400
Wire Wire Line
	5200 3300 5200 4250
Wire Wire Line
	5200 4250 3600 4250
Wire Wire Line
	3600 4250 3600 3800
Connection ~ 5200 3300
$Comp
L +9VA #PWR?
U 1 1 5C06FB33
P 4650 1400
F 0 "#PWR?" H 4650 1275 50  0001 C CNN
F 1 "+9VA" H 4650 1550 50  0000 C CNN
F 2 "" H 4650 1400 50  0001 C CNN
F 3 "" H 4650 1400 50  0001 C CNN
	1    4650 1400
	1    0    0    -1  
$EndComp
$Comp
L -9VA #PWR?
U 1 1 5C06FD60
P 4650 2000
F 0 "#PWR?" H 4650 1875 50  0001 C CNN
F 1 "-9VA" H 4650 2150 50  0000 C CNN
F 2 "" H 4650 2000 50  0001 C CNN
F 3 "" H 4650 2000 50  0001 C CNN
	1    4650 2000
	-1   0    0    1   
$EndComp
$Comp
L LTC3265_DFN U?
U 1 1 5C0725EF
P 9250 2600
F 0 "U?" H 9250 850 60  0000 C CNN
F 1 "LTC3265_DFN" H 9250 750 60  0000 C CNN
F 2 "" H 9250 2600 60  0001 C CNN
F 3 "" H 9250 2600 60  0001 C CNN
	1    9250 2600
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5C072B60
P 9250 1150
F 0 "C?" H 9275 1250 50  0000 L CNN
F 1 "1uF" H 9275 1050 50  0000 L CNN
F 2 "" H 9288 1000 50  0001 C CNN
F 3 "" H 9250 1150 50  0001 C CNN
	1    9250 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	9100 1150 9100 1350
Wire Wire Line
	9400 1350 9400 1150
$Comp
L C C?
U 1 1 5C073097
P 9250 4050
F 0 "C?" H 9275 4150 50  0000 L CNN
F 1 "1uF" H 9275 3950 50  0000 L CNN
F 2 "" H 9288 3900 50  0001 C CNN
F 3 "" H 9250 4050 50  0001 C CNN
	1    9250 4050
	0    1    1    0   
$EndComp
Wire Wire Line
	9100 4050 9100 3950
Wire Wire Line
	9400 4050 9400 3950
$Comp
L R R?
U 1 1 5C073C3C
P 10400 1850
F 0 "R?" V 10480 1850 50  0000 C CNN
F 1 "R" V 10400 1850 50  0000 C CNN
F 2 "" V 10330 1850 50  0001 C CNN
F 3 "" H 10400 1850 50  0001 C CNN
	1    10400 1850
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C073D89
P 10400 2250
F 0 "R?" V 10480 2250 50  0000 C CNN
F 1 "R" V 10400 2250 50  0000 C CNN
F 2 "" V 10330 2250 50  0001 C CNN
F 3 "" H 10400 2250 50  0001 C CNN
	1    10400 2250
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5C073E13
P 10050 2450
F 0 "C?" H 10075 2550 50  0000 L CNN
F 1 "C" H 10075 2350 50  0000 L CNN
F 2 "" H 10088 2300 50  0001 C CNN
F 3 "" H 10050 2450 50  0001 C CNN
	1    10050 2450
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5C073EC2
P 10000 2750
F 0 "C?" H 10025 2850 50  0000 L CNN
F 1 "C" H 10025 2650 50  0000 L CNN
F 2 "" H 10038 2600 50  0001 C CNN
F 3 "" H 10000 2750 50  0001 C CNN
	1    10000 2750
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C0740D2
P 10350 3350
F 0 "R?" V 10430 3350 50  0000 C CNN
F 1 "R" V 10350 3350 50  0000 C CNN
F 2 "" V 10280 3350 50  0001 C CNN
F 3 "" H 10350 3350 50  0001 C CNN
	1    10350 3350
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C0741F2
P 10350 2950
F 0 "R?" V 10430 2950 50  0000 C CNN
F 1 "R" V 10350 2950 50  0000 C CNN
F 2 "" V 10280 2950 50  0001 C CNN
F 3 "" H 10350 2950 50  0001 C CNN
	1    10350 2950
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5C07480A
P 9950 4000
F 0 "C?" H 9975 4100 50  0000 L CNN
F 1 "10uF" H 9975 3900 50  0000 L CNN
F 2 "" H 9988 3850 50  0001 C CNN
F 3 "" H 9950 4000 50  0001 C CNN
	1    9950 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9950 1500 9900 1500
Wire Wire Line
	9950 900  9950 1500
Wire Wire Line
	9900 2600 10600 2600
Connection ~ 10050 2600
Connection ~ 10000 2600
Wire Wire Line
	10350 2600 10350 2800
Connection ~ 10350 2600
Wire Wire Line
	10400 2600 10400 2400
Connection ~ 10400 2600
Wire Wire Line
	9900 2900 10000 2900
Wire Wire Line
	10050 2300 9900 2300
Wire Wire Line
	9900 2000 10400 2000
Wire Wire Line
	10400 2000 10400 2100
Wire Wire Line
	10350 3200 9900 3200
Wire Wire Line
	10350 3100 10350 3200
Connection ~ 10350 3200
Connection ~ 10400 2000
Wire Wire Line
	9900 1700 10700 1700
Wire Wire Line
	9900 3500 10700 3500
Wire Wire Line
	9950 3850 9950 3800
Wire Wire Line
	9950 3800 9900 3800
$Comp
L C C?
U 1 1 5C077C0F
P 10700 1850
F 0 "C?" H 10725 1950 50  0000 L CNN
F 1 "C" H 10725 1750 50  0000 L CNN
F 2 "" H 10738 1700 50  0001 C CNN
F 3 "" H 10700 1850 50  0001 C CNN
	1    10700 1850
	1    0    0    -1  
$EndComp
Connection ~ 10400 1700
Connection ~ 10350 3500
$Comp
L C C?
U 1 1 5C077FAE
P 10700 3350
F 0 "C?" H 10725 3450 50  0000 L CNN
F 1 "C" H 10725 3250 50  0000 L CNN
F 2 "" H 10738 3200 50  0001 C CNN
F 3 "" H 10700 3350 50  0001 C CNN
	1    10700 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	10950 3200 10950 3100
Wire Wire Line
	10950 3100 10700 3100
Wire Wire Line
	10700 3100 10700 3200
Wire Wire Line
	8550 900  8550 2200
Wire Wire Line
	8550 2200 8600 2200
Wire Wire Line
	8550 900  9950 900 
Wire Wire Line
	8100 2350 8600 2350
Wire Wire Line
	8600 2550 8550 2550
Wire Wire Line
	8550 2350 8550 2650
Wire Wire Line
	8550 2650 8600 2650
Connection ~ 8550 2350
Connection ~ 8550 2550
Wire Wire Line
	8600 2850 8550 2850
Wire Wire Line
	8550 2850 8550 3000
Wire Wire Line
	8550 2950 8600 2950
Connection ~ 8550 2950
$Comp
L +9VA #PWR?
U 1 1 5C07A53C
P 8100 2300
F 0 "#PWR?" H 8100 2175 50  0001 C CNN
F 1 "+9VA" H 8100 2450 50  0000 C CNN
F 2 "" H 8100 2300 50  0001 C CNN
F 3 "" H 8100 2300 50  0001 C CNN
	1    8100 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 2300 8100 2350
Text Notes 7650 2500 0    60   ~ 0
INPUT=VBAT
$Comp
L +12VA #PWR?
U 1 1 5C07E232
P 10700 1650
F 0 "#PWR?" H 10700 1500 50  0001 C CNN
F 1 "+12VA" H 10700 1790 50  0000 C CNN
F 2 "" H 10700 1650 50  0001 C CNN
F 3 "" H 10700 1650 50  0001 C CNN
	1    10700 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	10700 1700 10700 1650
$Comp
L -12VA #PWR?
U 1 1 5C07E670
P 10700 3550
F 0 "#PWR?" H 10700 3400 50  0001 C CNN
F 1 "-12VA" H 10700 3690 50  0000 C CNN
F 2 "" H 10700 3550 50  0001 C CNN
F 3 "" H 10700 3550 50  0001 C CNN
	1    10700 3550
	-1   0    0    1   
$EndComp
Wire Wire Line
	10700 3500 10700 3550
Text Notes 9800 4900 0    60   ~ 0
VLDO+ = 1.2 *((R1/R2)+1)\nVLDO- = -1.2 *((R1/R2)+1)
Text Notes 9550 5250 0    60   ~ 0
VOUT+= 2*(VBAT - GNDPWR)\nVOUT- = -(VBAT - GNDPWR)
$Comp
L -9VA #PWR?
U 1 1 5C082951
P 8550 3000
F 0 "#PWR?" H 8550 2875 50  0001 C CNN
F 1 "-9VA" H 8550 3150 50  0000 C CNN
F 2 "" H 8550 3000 50  0001 C CNN
F 3 "" H 8550 3000 50  0001 C CNN
	1    8550 3000
	-1   0    0    1   
$EndComp
$Comp
L -9VA #PWR?
U 1 1 5C082BEB
P 10600 2600
F 0 "#PWR?" H 10600 2475 50  0001 C CNN
F 1 "-9VA" H 10600 2750 50  0000 C CNN
F 2 "" H 10600 2600 50  0001 C CNN
F 3 "" H 10600 2600 50  0001 C CNN
	1    10600 2600
	-1   0    0    1   
$EndComp
$Comp
L -9VA #PWR?
U 1 1 5C082E12
P 10700 2000
F 0 "#PWR?" H 10700 1875 50  0001 C CNN
F 1 "-9VA" H 10700 2150 50  0000 C CNN
F 2 "" H 10700 2000 50  0001 C CNN
F 3 "" H 10700 2000 50  0001 C CNN
	1    10700 2000
	-1   0    0    1   
$EndComp
$Comp
L -9VA #PWR?
U 1 1 5C082EBF
P 10950 3200
F 0 "#PWR?" H 10950 3075 50  0001 C CNN
F 1 "-9VA" H 10950 3350 50  0000 C CNN
F 2 "" H 10950 3200 50  0001 C CNN
F 3 "" H 10950 3200 50  0001 C CNN
	1    10950 3200
	-1   0    0    1   
$EndComp
$Comp
L -9VA #PWR?
U 1 1 5C08322D
P 9950 4150
F 0 "#PWR?" H 9950 4025 50  0001 C CNN
F 1 "-9VA" H 9950 4300 50  0000 C CNN
F 2 "" H 9950 4150 50  0001 C CNN
F 3 "" H 9950 4150 50  0001 C CNN
	1    9950 4150
	-1   0    0    1   
$EndComp
$EndSCHEMATC