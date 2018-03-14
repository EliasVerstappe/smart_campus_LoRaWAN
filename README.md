# Smart Campus

#### mbed-ttnmapper (using LoRaWAN)
MBed implementation that sends data from an mbed to the things network.

## Installation

Clone the project using git.

Go into the cloned directory and start the `mbed deploy` command to download the libraries.
```
cd .\mbed-ttnmapper\
mbed deploy
```

In the src directory, you need to create a `settings.h` file. In this file
the LoRaWAN ABP settings need to be configured. You can copy
the example file, and edit it to your preferences.

```
cp .\src\settings.example.h .\src\settings.h
```

Now you can build the program and flash it to your mbed
```
mbed compile -f -m LPC1768 -t GCC_ARM
```
Because the .mbed file contains `TARGET=LPC1768` and `TOOLCHAIN=GCC_ARM`, you can also do this:

```
mbed compile -f
```

# The Things network

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

## Source

This project mostly uses sillevl's code.
You wan find it here:
https://github.com/sillevl/mbed-ttnmapper




:octocat:
