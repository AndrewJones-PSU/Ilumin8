#ifndef __COMMAND_LIST_ILUMIN8_H__
#define __COMMAND_LIST_ILUMIN8_H__

/*
 * This namespace contains all the commands that can be sent over serial.
 * Some commands imply values will be sent after them.
 * I'll eventually make a well-documented file on how these commands
 * are used and how the code on both ends interacts with these commands.
 * 
 * quick and dirty runthrough of how sending the datastream from the PC to the arduino works
 * -arduino waits for serial data
 * -once PC sends some serial data, the arduino starts reading, also checking that the first byte is a DatastreamStart byte
 * -the arduino reads the second byte, which defines the size of the rest of the incoming datastream in bytes
 * -the arduino then reads the number of bytes defined in the second byte, storing them to a buffer
 * -after reading the datastream, the arduino then processes it and updates the proper values accordingly
 * -after processing the datastream, the arduino then writes to the lightstrips, and then updates the values of the LED array
 * (note that an empty datastream can be sent (i.e. the 2nd byte is 0) and the arduino simply won't parse it and skip right to updating LEDs)
 */
namespace cmds
{
	// byte indicating the start of a datastream
	#define DatastreamStart (byte)2

	// General Commands
	#define ChangeLightshow (byte)3
	#define ChangeOption (byte)4

	// Option Selection, put after a ChangeOption byte
	#define Option_SetBrightness (byte)1
}

#endif