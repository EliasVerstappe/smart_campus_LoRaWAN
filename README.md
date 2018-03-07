# mbed-ttnmapper
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



## Source

This project mostly uses sillevl's code.
You wan find it here:
https://github.com/sillevl/mbed-ttnmapper
