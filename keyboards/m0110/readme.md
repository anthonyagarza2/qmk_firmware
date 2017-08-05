Apple M0110 keyboard firmware
=============================

Firmware for [this](https://github.com/saucybulgogi/Apple-M0110-BT) pcb

Current firmware is working for the pcb using the Teensy 2.0 as the controller. 

Firmware for the Feather + I/O expander will be added once I've completed it. 

## Building

Download or clone the whole firmware and navigate to the keyboards/m0110 folder. Once your dev env is setup, you'll be able to type `make` to generate your .hex - you can then use the Teensy Loader to program your .hex file. 

Depending on which keymap you would like to use, you will have to compile slightly differently.

### Default

To build with the default keymap, simply run `make default`.