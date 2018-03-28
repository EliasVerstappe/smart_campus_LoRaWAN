# LoRaWAN Smart Campus using NUCLEO_L073RZ board

### Pin connection
![chip connection 1](../media/image1.png)
![chip connection 2](../media/image2.png)
![LoRaWAN1](../media/Knipsel.png)
![LoRaWAN2](../media/Knipsel2.png)


### Pinmap

| Sensor   | Arduino | STM32L073x8 |Pin op LoRa bord  |
| -------- | ------- | ----------- |------------------|
| MOSI     | D11     | PA7         |      |
| MISO     | D12     | PA6         |      |
| SCK      | D13     | PA5         |      |
| NSS      | D10     | PB6         |      |
| RESET    | D9      | PC7         |      |
| SDA      | A4      | PC1         |      |
| SCL      | A5      | PC0         |      |
| PIR      | D8      | PA9         |      |
| PIR-VCC  | A0      | PA0         |      |
| TEMP-VCC | A1      | PA1         |      |
| DIO0     | D2      | PA10        |      |
| DIO1     | D3      | PB3         |      |
| DIO2     | D4      | PB5         |      |
| DIO3     | D5      | PB4         |      |
| DIO4     | D6      | PB10        |      |
| DIO5     | D7      | PA8         |      |



### Pinout in 'config' file
Changes have been made in:
`Simple-LoRaWAN/src/SX1276Lib/sx1276/sx1276-hal.cpp`



Added this, still in comment:
```
/*                        #elif defined( TARGET_NUCLEO_L073RZ )
                        :   SX1276( events, D11, D12, D13, D10, A0, D2, D3, D4, D5, D8, D9 ),
                            antSwitch( P0_23 ),
                            fake( A3 )                                                      
*/
```
