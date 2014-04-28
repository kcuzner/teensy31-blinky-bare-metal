/**
 * Shim file to take care of undefined init functions if we don't use them
 *
 * The point of this is so that we can cut stuff that we don't really need out
 * of the stuff that comes with teensyduino.
 */

void unused_void(void) { }

void analog_init(void) __attribute__ ((weak, alias("unused_void")));
void usb_init(void) __attribute__ ((weak, alias("unused_void")));
