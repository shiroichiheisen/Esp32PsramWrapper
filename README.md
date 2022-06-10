# Esp32PsramWrapper

Library for using the psram with the esp32, just a wrapper to make better code read and make less dificult to implement the Psram;

## ☕ Using this library

To use this library, just declare the object and use the functions:

```
  char *day1 = (char *)ps_calloc(1, size of the string);
  char *day1 = (char *)ps_calloc(1, 1000000); // Allocates 1MB of memory
```

After declared the object, you can use the functions on the .h archive:

```	
dataSave(char *str, String data) //Save data on the psram
dataSize(char *str) //Returns the size of the data
dataReset(char *str, String data) //Reset the data
```

## dataSave(char *str, String data)

    * str: The pointer to the data
    * data: The data to save on the psram


## dataSize(char *str)

    * str: The pointer to the data

    Returns the size of the data

## dataReset(char *str, String data)

    * str: The pointer to the data
    * data: The data to save on the psram

    When using this function, if you want to just clear the data, just pass the pointer to the data without the data (ex: dataReset(str);).

    If you want to clear and save some data on the psram, just pass the pointer to the data with the data (ex: dataReset(str, "Hello World");).

## How to declare the object and use the functions:

    ```
    setup() {
    }
    loop(){
  char *day1 = (char *)ps_calloc(1, 1000000); // Allocates 1MB of memory
  while(1){ //you need this while!!! if you declare globally the object on the line above, the object will inicialize before the psram can initialize, so a quick fix is using the while on the loop
dataSave(day1, "Hello"); // Save data to day1
Serial.println(day1); // Prints the data
		delay(1000);			 // Wait 1 second
Serial.println(dataSize(day1));	 // Get the size of the data in the string
		delay(1000);			 // Wait 1 second
		dataReset(day1);		 // Reset data on day1, to empty and write the data just use dataReset(day1, String newdata)
Serial.println(day1); // Prints the data
		delay(1000);			 // Wait 1 second
  }
    }
    ```

    If you use arduino ide you need to enable the psram on the tools menu

    If you use the platformio platform you need to enable the psram on the platformio.ini file, just add the following lines on the end of the archive:
build_flags =
    -DBOARD_HAS_PSRAM 
    -mfix-esp32-psram-cache-issue