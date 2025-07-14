# Bill of Materials

This is a BOM for the controller PCB. Headerpins will also be needed for some of the connectors.


|Reference |Footprint	 |	Qty	| Link | Notes
|----------|----------|----|--------|-------|
|ADT1	|Conn_01x04_Socket|	1 |https://amzn.to/469HaiG | This is really a generic I2C connection |	
|B1	|SPARKFUN_LOGIC_LEVEL_CONVERTER|1 |https://amzn.to/4nIsf5v|	
|C1|	470uF|	1| ||	
|HCSR04-1,HCSR04-2,HCSR04-3| Conn_01x04_Pin| 3 | https://amzn.to/44LDqRY| Header for Ultrasound distance sensors|
|L298N1| Conn_01x04_Pin | 1 | https://amzn.to/4nMWF6s||
|WS2812B-1,WS2812B-2|	Conn_01x04_Pin| 2| https://amzn.to/4nMWF6s| Header for WS2812B LEDs if required|
|J2|	Screw_Terminal_01x03| 1 |	https://amzn.to/4nMWF6s||
|J3|	PinHeader_1x03_P2.54mm_Vertical|1|| Uart0 Connector|	
|Motor1|	Conn_01x06_Pin| 1|https://amzn.to/3U7HU0u| Motor used 132:1 grear ratio|
|R1|	220R| Resistor_THT| 1 |||
|RZ1	|RP2040-Zero| 1|https://amzn.to/3IHgJHf||
|SW1|	SW_PUSH_6mm_H8.5mm |1|https://amzn.to/3TEUpAC||	
|U1,U2,U3|	HC-SR04| 3|https://amzn.to/44LDqRY||
