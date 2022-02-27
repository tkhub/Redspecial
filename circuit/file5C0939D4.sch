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
Sheet 4 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 2450 1550 0    60   Input ~ 0
SSR_RSNS_AO
Text GLabel 2450 1900 0    60   Input ~ 0
SSR_LSNSINV_AO
Text GLabel 2450 2300 0    60   Input ~ 0
MCU_STRCMD_AO
$Comp
L POT RV?
U 1 1 5C094367
P 1400 3100
F 0 "RV?" V 1225 3100 50  0000 C CNN
F 1 "POT" V 1300 3100 50  0000 C CNN
F 2 "" H 1400 3100 50  0001 C CNN
F 3 "" H 1400 3100 50  0001 C CNN
	1    1400 3100
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C094386
P 1400 2800
F 0 "R?" V 1480 2800 50  0000 C CNN
F 1 "R" V 1400 2800 50  0000 C CNN
F 2 "" V 1330 2800 50  0001 C CNN
F 3 "" H 1400 2800 50  0001 C CNN
	1    1400 2800
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C0943B1
P 1400 3400
F 0 "R?" V 1480 3400 50  0000 C CNN
F 1 "R" V 1400 3400 50  0000 C CNN
F 2 "" V 1330 3400 50  0001 C CNN
F 3 "" H 1400 3400 50  0001 C CNN
	1    1400 3400
	1    0    0    -1  
$EndComp
$Comp
L VDDA #PWR?
U 1 1 5C094402
P 1400 2650
F 0 "#PWR?" H 1400 2500 50  0001 C CNN
F 1 "VDDA" H 1400 2800 50  0000 C CNN
F 2 "" H 1400 2650 50  0001 C CNN
F 3 "" H 1400 2650 50  0001 C CNN
	1    1400 2650
	1    0    0    -1  
$EndComp
$Comp
L VSSA #PWR?
U 1 1 5C09442E
P 1400 3550
F 0 "#PWR?" H 1400 3400 50  0001 C CNN
F 1 "VSSA" H 1400 3700 50  0000 C CNN
F 2 "" H 1400 3550 50  0001 C CNN
F 3 "" H 1400 3550 50  0001 C CNN
	1    1400 3550
	-1   0    0    1   
$EndComp
Wire Wire Line
	1550 3100 1750 3100
Text Label 1750 3100 0    60   ~ 0
STRADJ
$EndSCHEMATC
