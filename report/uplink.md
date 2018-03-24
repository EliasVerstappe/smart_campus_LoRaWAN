# Uplink

## Filter
<!-- Decoder -->
Using the payload functions, i can decode the received data and store it in a JSON string.

|Sensor         |Size       |Datatype    |Description                                                                       |
|---------------|:---------:|:----------:|----------------------------------------------------------------------------------|
|Temperatuur    |2 byte     |signed int  |+, - and komma. Send an integer from the mbed (21.5 * 10 = 215) and devide it by 10 in the filter.|
|Humidity       |1 byte     |signed int    |0 -> 100%                                                                         |
|Movement       |2 byte     |signed int    |Counts the amount of edges                                                        |

Example values: `21.5°, 27%, 73`

Binairy:
`0000 0000 1101 0111
0001 1011
0000 0000 0100 1001`

Hexadecimal:
`00D71B0049`

```js
function Decoder(bytes, port) {
// Decode an uplink message from a buffer
// (array) of bytes to an object of fields.
var decoded = {};

// Decode bytes to int
var temperature = bytes[0] | bytes[1];
var humidity = bytes[2];
var movement = bytes[3] | bytes[4];

// Decode int to float
decoded.temperature = temperature / 10;
decoded.humidity = humidity;
decoded.movement = movement;

return decoded;
}

```

Filtered result:
```js
{
  "humidity": 27,
  "movement": 73,
  "temperature": 21.5
}
```



[:octocat:](./../README.md)
