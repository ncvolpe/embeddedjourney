# ESP32 Personal Tinkering

### Boards on Hand
 - WROOM32
 - Probably others

## FreeRTOS: ESP IDF vs. Arduino AVR

WHAT ON EARTH IS GOING ON

2 Frameworks
 - ESP IDF
	- No real idea on what actual documentation is referring to 
		- Maybe create everything in your IDE of choice, then separately use workflow described in documentation (idf.py, etc.)

 - Arduino AVR
	- Supposedly is actually just ESP IDF under the hood? 

IDEs
 - Arduino IDE
	- Usable Frameworks
		- Arduino AVR
		- ESP IDF
	- Personal Comments:
		- EXTREMELY confused. Digikey's tutorial series on FreeRTOS with ESP32 (Found here: https://www.youtube.com/playlist?list=PLEBQazB0HUyQ4hAPU1cJED6t3DU0h34bz) 
		  Uses Arduino IDE, but refers to ESP IDF FreeRTOS implementation stuff, and uses code that is only referred to in the ESP IDF FreeRTOS documentation:
    		```c
		// Use only core 1 for demo purposes
		#if CONFIG_FREERTOS_UNICORE
		  static const BaseType_t app_cpu = 0;
		#else
		  static const BaseType_t app_cpu = 1;
		#endif
		```

		I could not find any reference to "CONFIG_FREERTOS_UNICORE" in my project directory, or anything when trying "Go To Declaration" in VSCode.
		I found reference to this in the ESP IDF Project Configuration Documentation: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/kconfig.html#config-freertos-unicore
		CONFIG_FREERTOS_UNICORE
		Run FreeRTOS only on first core

		Found in: Component config > FreeRTOS > Kernel

		This version of FreeRTOS normally takes control of all cores of the CPU. Select this if you only want to start it on the first core. This is needed when e.g. another process needs complete control over the second core.


 - VSCode
	- Extensions
		- PlatformIO
			- Usable Frameworks
				- ESP IDF
					- Needs Compilers, set up, etc.
				- Arduino AVR
					- Is Actually just ESP IDF but further abstracted?
		- ESP IDF: Explorer
			- I could not get started


Current Task:
Read This
https://docs.platformio.org/en/latest/frameworks/espidf.html#tutorials
