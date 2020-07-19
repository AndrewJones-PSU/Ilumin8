#include <Windows.h>
#include <stdio.h>
#include <iostream>

int main()
{
	std::cout << "ilumin8 Serial CLI" << std::endl;
	std::cout << "Enter com port number (i.e. \"9\" for COM9) and baud rate separated by a space:" << std::endl;
	
	// get port number and baud rate from user
	int portNum = 0;
	int baudRate = 256000;
	bool continueFlag = true;
	do
	{
		try
		{
			std::cin >> portNum >> baudRate;
			continueFlag = true;
		}
		catch (const std::exception& e)
		{
			std::cout << "could not parse input, please enter 2 valid integers." << std::endl;
			continueFlag = false;
		}
	} while (!continueFlag);

	// parse portname input
	char portName[9] = "";
	sprintf(portName, "\\\\.\\COM%d", portNum);

	// create file handle for writing to serial port
	HANDLE hComm;
	hComm = CreateFile(portName,				//port name
				GENERIC_READ | GENERIC_WRITE,	//Read/Write
				0,								// No Sharing
				NULL,							// No Security
				OPEN_EXISTING,					// Open existing port only
				0,								// Non Overlapped I/O
				NULL);							// Null for Comm Devices
	if (hComm == INVALID_HANDLE_VALUE)
	{
		std::cout << "Error in opening serial port, exiting program";
		return 1;
	}
	std::cout << "opening serial port successful";
	
	DCB dcbSerialParams = { 0 }; // Initializing DCB structure
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	GetCommState(hComm, &dcbSerialParams);

	dcbSerialParams.BaudRate = baudRate;  // Setting BaudRate from user input
	dcbSerialParams.ByteSize = 8;         // Setting ByteSize = 8
	dcbSerialParams.StopBits = ONESTOPBIT;// Setting StopBits = 1
	dcbSerialParams.Parity   = NOPARITY;  // Setting Parity = None

	SetCommState(hComm, &dcbSerialParams);

	uint8_t portBuffer[] = {2, 2, 3, 1};
	DWORD dNoOfBytesToWrite;
	DWORD dNoOfBytesWritten = 0;
	dNoOfBytesToWrite = sizeof(portBuffer);
	WriteFile(hComm, portBuffer, dNoOfBytesToWrite, &dNoOfBytesWritten, NULL);

	uint8_t noDataBuffer[] = {2, 0};
	dNoOfBytesWritten = 0;
	dNoOfBytesToWrite = sizeof(noDataBuffer);
	WriteFile(hComm, noDataBuffer, dNoOfBytesToWrite, &dNoOfBytesWritten, NULL);

	CloseHandle(hComm);//Closing the Serial Port
	return 0;
}
