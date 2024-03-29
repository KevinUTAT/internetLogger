// internetLogger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <ctime>
#include "windows.h"


// The implomentation of this function come from
// the internet, thanks for TrungTN and Rashad
// on StackOverflow
const std::string currentDateTime()
{
	time_t     now = time(nullptr);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}


int main()
{
	std::ofstream log_out;
	log_out.open("connection_log.txt");
	while (true)
	{
		std::string curr_time = currentDateTime();
		int result = system("ping www.google.com");
		if (result == 0) //connection good
		{
			std::cout << curr_time << ": connected" << std::endl;
			log_out << curr_time << ": connection is good\n";
		}
		else
		{
			std::cout << curr_time << ": disconnected" << std::endl;
			log_out << curr_time << ": connection lost\n";
		}
		Sleep(60000);
	}
    return 0;
}

