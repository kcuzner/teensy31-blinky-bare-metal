# Blinky for Teensy 3.1 without Ardiuno IDE
### Kevin Cuzner

Based on the article by Karl Lunt: http://www.seanet.com/~karllunt/bareteensy31.html

## Purpose

I really don't like the Arduino IDE. It lacks so many basic features that it is
almost rendered unusable (IMO) to people who have used a variety of IDEs. The
point of this is to demonstrate building a program for the Teensy 3.1 outside
the Arduino IDE while still using the utilities provided by Teensyduino. I can't
quite call this bare metal since the Teensyduino library provides assistance,
but its certainly close enough for me.

The main difference between this an Karl Lunt's Makefile is that this is meant
to use only the Teensyduino source files rather than also needing some source
from freescale. This is purely for my own personal preference.

Another difference is that this Makefile uses the src/obj/bin structure which I
have always wanted to have in a Makefile.

## How to use

This isn't really meant to be used out of the box; its more of a demonstration.
Several things in the makefile would need to be changed in order to get this to
work and build.

### Prerequisites

 * `arm-none-eabi` and `arm-none-eabi-binutils` as they are called on Archlinux.
   More generally, `arm-none-eabi-gcc`, `arm-none-eabi-as`,
   `arm-none-eabi-ar`, `arm-none-eabi-ld`, `arm-none-eabi-objcopy`,
   `arm-none-eabi-size`, and `arm-none-eabi-objdump` should be available for
   use. These don't necessarily need to be installed globally, but I did.
 * Make. This does use a Makefile, so some sort of Make utility needs to be
   available to run it.

### Brief desription of some Makefile variables

Some variables may need to be tweaked. The foremost among these will be listed.
There are lots of comments in the Makefile which should hopefully describe the
rest of the variables.

`PROJECT`: This is the name of the output files. These will be placed in the
`$(OUTPUTDIR)` directory. They will be generated as `$(PROJECT).elf`,
`$(PROJECT).bin`, `$(PROJECT).hex`, etc.

`TEENSY3X_BASEPATH = $(HOME)/arduino-1.0.5/hardware/teensy/cores/teensy3`: This
variable points to the Teensyduino installation path for the Teensy3. On my
machine, this in in my home directory, but on machines with a global
installation of the Arduino IDE, this will need to be changed.

`TOOLPATH = /usr`: This is the "base directory" for the installation of the
`arm-none-eabi` build toolchain. In my case, I had a global installation of this
and so the base directory was my `/usr` directory. Whatever this directory is,
it is expected that there is a `bin` directory containing the `arm-none-eabi`
binaries and an `arm-eabi-none/include` directory containing the gcc include
files.
