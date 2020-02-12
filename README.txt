# ------------------------------------------------- SOUND SENSOR PROJECT -----------------------------------------------------

This project is meant to collect sound level at a proximity of a Rasberry Pi device. The RPi is equipped with a USB sound card
(C-Media Electronics, Inc. Audio Adapter) and a microphone. The sound is recorded at 16000Hz sample rate and every second will
produce 80 pieces of RMS value as a bar-diagram...

Table of Content
----------------
1. Configuration
2. Installation
3. Operation
4. Manifest (list of files and short description of their roles)
5. License
6. Contact information

1. Configuration
----------------
This project requires a Raspberry Pi 3 with following components:
	* Micro SD card with Raspberry Pi operating system.
	* RJ45 network cable.
	* Micro USB to USB cable.
	* Sound card.
	* Microphone with 3.5mm jack.
	* Internet
And also source files.

2. Installation
---------------
Installing Sound Project
	* Insert the SD card
	* Insert the keyboard
	* Insert the sound card and the microphone to the Raspberry
	* Connect to a power supply by the Micro USB to USB cable
	* Connect the Raspberry Pi to a Internet domain by the RJ45 cable
	* Initialize the Raspberry, set up the sound card and sound setting
	* Remote the Raspberry microprocessor, create a folder name "AppDev", copy all the downloaded
		files of the Sound Project to the folder
	* Using the IP which is sent to your email to connect to the terminal

3. Operation
------------
	* Open the PUTTY terminal, logining in using the IP that was sent
	* "login as": pi and apply the password
	* Access to the "AppDev" folder by "cd AppDev" command.
	* Checking presence of files by command "ls"
	* Compilling by typing "make" command
	* Run "./sound.a" command to start the programme
	* Using the microphone to sense the presence and the variation of the sound movement
		- If the sound is less than 15dB, the cursor will appear as a white column.
		- If the sound is in range of 15dB and 20dB, the cursor will appear as a yellow column.
		- If the sound is greater than 20dB, the cursor will appear as a red column.
		(all of the sound is recorded as a 1-second sector)
		
4. Manifest
-----------
	a. main.c
	This is the main, the operating file
	b. sound.c
	This is the file for extracting the information contended in a .wav file and calculation for dB
	c. sound.h
	This is the header file for sound.c. This file content the library, definition for constants
	d. screen.c
	This file is for displaying RMS values into bars on the screen.
	e. screen.h
	This is the header file for screen.c
	f. comm.c
	This file is the communication between the Raspberry Pi and the server which it sent RMS values to
	g. comm.h
	This is the header file for comm.c
	h. makefile
	This file contains the way of compilling and other menthods such as clean files or make .tar file
	i. sound.php
	This file is kept in the server so that the server can receive the RMS values
	
	***** All of the source files can be download at: https://github.com/superbolt1105/sounds *****
5. Lisense
----------
Thanks for curl post menthod! The information can be found at: https://curl.haxx.se

***** All the sources are free to use and distribute! *****


6. Contact information
----------------------
	Quan Nguyen, Departure of Information Technology
	Vaasa University of Applied Sciences
	Wolffintie 30, 65050 Vaasa, Finland
	Homepage: http://www.cc.puv.fi/~e1700693/html/homepage.html
	Email: e1700693(at)edu.vamk.fi
