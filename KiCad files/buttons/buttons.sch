EESchema Schematic File Version 4
EELAYER 30 0
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
L Connector_Generic:Conn_01x07 Connector0
U 1 1 5ECE01A2
P 7900 3800
F 0 "Connector0" H 7980 3792 50  0000 L CNN
F 1 "Conn_01x06" H 7980 3701 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x07_P2.54mm_Vertical" H 7900 3800 50  0001 C CNN
F 3 "~" H 7900 3800 50  0001 C CNN
	1    7900 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 4000 7500 3700
Wire Wire Line
	7500 3700 7700 3700
Wire Wire Line
	7550 4050 7550 3800
Wire Wire Line
	7550 3800 7700 3800
Wire Wire Line
	7600 4100 7600 3900
Wire Wire Line
	7600 3900 7700 3900
Wire Wire Line
	7450 3600 7700 3600
Wire Wire Line
	7450 3600 7450 3950
Wire Wire Line
	7450 3950 7000 3950
Wire Wire Line
	7000 3950 7000 3900
Wire Wire Line
	7500 4000 6500 4000
Wire Wire Line
	6500 4000 6500 3900
Wire Wire Line
	7550 4050 6000 4050
Wire Wire Line
	6000 4050 6000 3900
Wire Wire Line
	7600 4100 5500 4100
Wire Wire Line
	5500 4100 5500 3900
Wire Wire Line
	7650 4150 5000 4150
Wire Wire Line
	5000 4150 5000 3900
$Comp
L Switch:SW_Push BtnBack0
U 1 1 5ED06160
P 7000 3700
F 0 "BtnBack0" V 7046 3652 50  0000 R CNN
F 1 "SW_Push" V 6955 3652 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 7000 3900 50  0001 C CNN
F 3 "~" H 7000 3900 50  0001 C CNN
	1    7000 3700
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push BtnLeft0
U 1 1 5ED06FB6
P 6500 3700
F 0 "BtnLeft0" V 6546 3652 50  0000 R CNN
F 1 "SW_Push" V 6455 3652 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6500 3900 50  0001 C CNN
F 3 "~" H 6500 3900 50  0001 C CNN
	1    6500 3700
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push BtnUp0
U 1 1 5ED0764A
P 6000 3700
F 0 "BtnUp0" V 6046 3652 50  0000 R CNN
F 1 "SW_Push" V 5955 3652 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6000 3900 50  0001 C CNN
F 3 "~" H 6000 3900 50  0001 C CNN
	1    6000 3700
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push BtnDown0
U 1 1 5ED07A4D
P 5500 3700
F 0 "BtnDown0" V 5546 3652 50  0000 R CNN
F 1 "SW_Push" V 5455 3652 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5500 3900 50  0001 C CNN
F 3 "~" H 5500 3900 50  0001 C CNN
	1    5500 3700
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push BtnRight0
U 1 1 5ED07D5E
P 5000 3700
F 0 "BtnRight0" V 5046 3652 50  0000 R CNN
F 1 "SW_Push" V 4955 3652 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5000 3900 50  0001 C CNN
F 3 "~" H 5000 3900 50  0001 C CNN
	1    5000 3700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7700 3500 7000 3500
Wire Wire Line
	7000 3500 6500 3500
Connection ~ 7000 3500
Wire Wire Line
	6500 3500 6000 3500
Connection ~ 6500 3500
Wire Wire Line
	5500 3500 6000 3500
Connection ~ 6000 3500
Wire Wire Line
	5500 3500 5000 3500
Connection ~ 5500 3500
Wire Wire Line
	7650 4150 7650 4000
Wire Wire Line
	7650 4000 7700 4000
$Comp
L Switch:SW_Push BtnSelect0
U 1 1 5ED33317
P 4500 3700
F 0 "BtnSelect0" V 4546 3652 50  0000 R CNN
F 1 "SW_Push" V 4455 3652 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 4500 3900 50  0001 C CNN
F 3 "~" H 4500 3900 50  0001 C CNN
	1    4500 3700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7700 4100 7700 4200
Wire Wire Line
	7700 4200 4500 4200
Wire Wire Line
	4500 4200 4500 3900
Wire Wire Line
	4500 3500 5000 3500
Connection ~ 5000 3500
$EndSCHEMATC