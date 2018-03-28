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

### Compiling

You can build the program and flash it to your mbed
```
mbed compile -f -m LPC1768 -t GCC_ARM
```

<<<<<<< HEAD
[NUCLEO](/report/NUCLEO.md)
=======
[NUCLEO](./NUCLEO.md)
>>>>>>> 1c851411d40450ef245a9d5218d8cfdea860052f

When using the `NUCLEO-L073RZ`, use the following command:
```
mbed compile -f -m NUCLEO_L073RZ -t GCC_ARM
```

# The Things network

[Uplink](/report/uplink.md)

[Downlink](/report/downlink.md)





## Source

This project mostly uses sillevl's code.
You wan find it here:
https://github.com/sillevl/mbed-ttnmapper




:octocat:
