

# Downlink

When you want to send something from The Things Network back to your device,
your message will be scheduled to send, but will only send when recieving data
from the device.

#### :wrench: UNDER CONSTRUCTION :hammer:

This piece of example code will light up some LED's when a ... is recieved.



```cpp

/*  In een of andere 'void setup' waar onder andere (voor OTAA)
    een ttn.join(appEui, appKey); gedaan wordt, maak ik de volgende functie.
*/

ttn.onMessage(message);

// verder, nieuwe functie maken

void message(cont uint8_t *payload, size_t, port_t port){
    if (payload[0] == 1){       // als de eerste byte van de payload gelijk is aan 1
        <led 1 inschakelen>
        <led 2 uitschakelen>
    } else {
        <led 1 uitschakelen>
        <led 2 inschakelen>
    }

}

```



## Source
How to: The Things Uno Part 4 - Downlink; https://www.youtube.com/watch?v=VXNfNDcFU2c&list=WL&t=65s&index=78




[:octocat:](./../README.md)
