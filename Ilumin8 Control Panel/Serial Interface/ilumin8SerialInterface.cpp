#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <chrono>
#include <future>

#define DelayPeriod 12500 // delay period of writing to the serial port in microseconds, default is 12500 (80Hz)

int run(int argc, char *argv[]);
void inputHandler(uint8_t* buffer, bool isIntegrated, bool firstRun);

int main(int argc, char *argv[])
{
	int x = run(argc, argv);
	return x;
}

int run(int argc, char *argv[])
{

	bool isIntegrated = false; // cmd argument that indicates if this is an integrated process, changes output and program flow

	// start by parsing command line args
	for (int i = 0; i < argc; ++i) 
		if (strcmp(argv[i], "-integrated") == 0)
			isIntegrated = true;
		

	if (!isIntegrated)
	{
		std::cout << "ilumin8 Serial CLI" << std::endl;
		std::cout << "Enter com port number (i.e. \"9\" for COM9) and baud rate separated by a space:" << std::endl;
	}

	// get port number and baud rate from user
	int portNum = 0;
	int baudRate = 250000;
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
			if (isIntegrated) // if an integrated process, terminate execution
				return 1;
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
	if (!isIntegrated)
		std::cout << "opening serial port successful\n";

	// set serial communication parameters
	DCB dcbSerialParams = { 0 }; // Initializing DCB structure
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
	GetCommState(hComm, &dcbSerialParams);
	dcbSerialParams.BaudRate = baudRate;  // Setting BaudRate from user input
	dcbSerialParams.ByteSize = 8;         // Setting ByteSize = 8
	dcbSerialParams.StopBits = ONESTOPBIT;// Setting StopBits = 1
	dcbSerialParams.Parity   = NOPARITY;  // Setting Parity = None
	SetCommState(hComm, &dcbSerialParams);

	// initialize variables for our main program loop
	bool shouldExit = false;					// flag for if we should exit the progrma
	uint8_t serialBuffer[258] = {2};			// bytes to write to the arduino
	uint8_t dataStreamBuffer[257] = {2, 3, 1};	// bytes returned by inputHandler, parsed into dataBuffer
	uint8_t dataStreamSize = 2;					// number of bytes in the dataStream
	DWORD bytesToWrite;							// total number of bytes to write to the arduino
	DWORD bytesWritten = 0;						// total number of bytes written to the arduino
	auto nextRun = std::chrono::high_resolution_clock::now(); // timepoint representing when our next update time is
	std::future<void> inputFuture = std::async(std::launch::async, inputHandler, &dataStreamBuffer[0], isIntegrated, true);


	// our main program loop, repeats forever until program is exited
	while (!shouldExit)
	{
		while(nextRun > std::chrono::high_resolution_clock::now()) {} // wait until next output period
		if (inputFuture.wait_for(std::chrono::seconds(0)) == std::future_status::ready) // is inputHandler done executing (or is inputHandler not initialized yet)?
		{
			// first byte of dataStreamBuffer is the size, copy this out first
			dataStreamSize = serialBuffer[1] = dataStreamBuffer[0];
			// copy the rest of dataStreamBuffer into serialBuffer 
			for (int i = 1; i <= 256; i++)
			{
				serialBuffer[i + 1] = dataStreamBuffer[i];
			}
			if (dataStreamSize == 0) // checking if we should exit the program
			{
				CloseHandle(hComm); // Close the serial port before exiting
				return 0;
			}
			// reinitialize inputHandler function now that we're done using dataStreamBuffer
			inputFuture = std::async(std::launch::async, inputHandler, &dataStreamBuffer[0], isIntegrated, false);
		}
		else // inputHandler is not done, just send empty dataStream
		{
			dataStreamSize = serialBuffer[1] = 0;
		}

		// send out our datastream
		bytesToWrite = dataStreamSize + 2;
		bytesWritten = 0;
		WriteFile(hComm, serialBuffer, bytesToWrite, &bytesWritten, NULL);

		nextRun += std::chrono::microseconds(DelayPeriod);
	}


	// end of program
	CloseHandle(hComm); // Close the Serial Port
	return 0;
}

void inputHandler(uint8_t* buffer, bool isIntegrated, bool firstRun)
{
	if (isIntegrated)
	{
		std::cin >> buffer;
	}
	else
	{
		if (!firstRun)
			std::cout << "Ready for input, enter size of datastream followed by datastream, separate numbers with spaces. Enter \"0\" to exit program\n";
		char userIn[1028] = "";
		std::cin.getline(userIn, 1028);
		try
		{
			char * ptr = strtok(userIn, " ");
			int i = 0;
			while (ptr != NULL && i <= 256)
			{
				buffer[i] = atoi(ptr);
				ptr = strtok(NULL, " ");
				i++;
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "an error occured while parsing input\n";
			buffer[0] = 0;
		}
	}
	
}