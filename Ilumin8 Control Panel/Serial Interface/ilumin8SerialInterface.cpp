#include <Windows.h>
#include <stdio.h>
#include <iostream>

int main()
{
	std::cout << "Hello, World!" << std::endl;
	HANDLE hComm;

	hComm = CreateFile("COM9",					//port name
				GENERIC_READ | GENERIC_WRITE,	//Read/Write
				0,								// No Sharing
				NULL,							// No Security
				OPEN_EXISTING,					// Open existing port only
				0,								// Non Overlapped I/O
				NULL);							// Null for Comm Devices
	if (hComm == INVALID_HANDLE_VALUE)
		printf("Error in opening serial port");
	else
		printf("opening serial port successful");
	

	DCB dcbSerialParams = { 0 }; // Initializing DCB structure
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	GetCommState(hComm, &dcbSerialParams);

	dcbSerialParams.BaudRate = CBR_115200;// Setting BaudRate = 115200
	dcbSerialParams.ByteSize = 8;         // Setting ByteSize = 8
	dcbSerialParams.StopBits = ONESTOPBIT;// Setting StopBits = 1
	dcbSerialParams.Parity   = NOPARITY;  // Setting Parity = None

	SetCommState(hComm, &dcbSerialParams);

	uint8_t portBuffer[] = {2, 2, 3, 1};
	DWORD dNoOfBytesToWrite;
	DWORD dNoOfBytesWritten = 0;
	dNoOfBytesToWrite = sizeof(portBuffer);

	WriteFile(hComm, portBuffer, dNoOfBytesToWrite, &dNoOfBytesWritten, NULL);

	CloseHandle(hComm);//Closing the Serial Port
	return 0;
}
