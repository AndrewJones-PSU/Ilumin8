#ifndef __COMMAND_LIST_ILUMIN8_H__
#define __COMMAND_LIST_ILUMIN8_H__

/*
 * This namespace contains all the commands that can be sent over serial.
 * Some commands imply values will be sent after them.
 * I'll eventually make a well-documented file on how these commands
 * are used and how the code on both ends interacts with these commands.
 * 
 * quick and dirty runthrough of how sending the datastream from the PC to the arduino works
 * -PC sends HANDSHAKE to arduino
 * -once arduino finishes next or current fastLED update, it responds with HANDSHAKE and clears pre-allocated memory for the datastream
 * -PC then sends DATASTREAM_START, along with an additional byte representing the size of the datastream in bytes
 * -PC then sends the datastream, no end of stream byte is sent since the arduino already knows its length and will
 * simply stop reading from serial once it's at the end. This is the end of serial transmission.
 * -arduino then interprets and executes the commands.
 */
namespace cmds
{
	#define Handshake 1
	#define DatastreamStart (byte)2
	#define ChangeLightshow (byte)3
	#define ChangeOption (byte)4
	#define CanWrite (byte) 253
	#define BusyDNW (byte) 254

	#define Option_SetBrightness (byte)1
}

#endif