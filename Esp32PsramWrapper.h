void dataSave(char *str, String data) // Save data to psram
{
	strcat(str, data.c_str());
}

int dataSize(char *str) // returns the size of the data in the string
{
	return strlen(str);
}

void dataReset(char *str, String data = "") // reset data to empty string
{
	strcpy(str, data.c_str());
}

loop()
{
	char *day1 = (char *)ps_calloc(1, 1000000); // Call the ps_calloc function to allocate memory for the string
	while (1)
	{							 // This loop is very important! if you don't have this loop, the data location on psram will clear
		dataSave(day1, "Hello"); // Save data to day1
		delay(1000);			 // Wait 1 second
		dataSize(day1);			 // Get the size of the data in the string
		delay(1000);			 // Wait 1 second
		dataReset(day1);		 // Reset data on day1, to empty and write the data just use dataReset(day1, String newdata)
		delay(1000);			 // Wait 1 second
	}
}