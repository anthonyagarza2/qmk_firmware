Prototype Planck + Accessory Firmware
=====================================

![Prototype](http://i.imgur.com/aH5vaPM.jpg)

Current Hardware Supported: Planck PCB rev4 + (1/2 Let's Split | The Sidearm)

Some hardware modifications are required. Mainly, soldering a TRS or TRRS socket to the planck rev 4 PCB.
This firmware uses the Serial protocol available in QMK for communication between halves.  
The default planck config assumes you are using pin D1 for the data connection between components. 
You must change the pin in planck/config.h if you use a different one. 

Make example for this keyboard (after setting up your build environment):

    make prototype-<target device>-<keymap>

See [build environment setup](https://docs.qmk.fm/build_environment_setup.html) then the [make instructions](https://docs.qmk.fm/make_instructions.html) for more information.
