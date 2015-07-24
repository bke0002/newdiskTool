//
// Created by Connor Jones on 7/14/15.
//

#include "record.h"
#include "math.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

record::record(config_info configInformation) {
	record::configInfo = configInformation;
}

string record::makeRecord() {
	// insert linux commands here to get disk stats
	ifstream inStream("/proc/diskstats");
	//    ifstream inStream("diskstats.txt");
	//todo: check to verify that file was opened - could put all below operations in if(inStream.is_open()) statement

	if (!inStream.is_open()) {
		std::cout << "Error: file could not be opened. Program will terminate.\n";
		exit(0);
	}

	std::string report[6];

	for (int i = 0; i < 6; i++) { //initialize report array
		report[i] = "N/A";
	}

	std::string inputString;
	getline(inStream, inputString);

	//    std::cout << "test: " << inputString;

	long loc = inputString.find("sda");
	if (loc > 0) { // remove 1st three fields since they aren't used
		inputString = inputString.substr(loc);
		inputString = inputString.substr(inputString.find(' ') + 1);
	}

	int diskData[11];

	for (int i = 0; i < 11; i++) { // put 11 data elements from disk into array
								   //        diskData[i] = atoi(inputString.substr(0,inputString.find(' ')).c_str());
		std::istringstream convert(inputString.substr(0, inputString.find(' ')).c_str());
		inputString = inputString.substr(inputString.find(' ') + 1);
		convert >> diskData[i];
	}

	//todo: currently not formatted. Just put in place for testing. Decimals need to be rounded to 2 places
	if (configInfo.getBlk_read() == 1) { //report[0]
										 // number of reads completed
		float temp = diskData[0];
		std::stringstream ss;
		ss << temp;
		std::string tempString = ss.str();
		report[0] = tempString;
		//        report[0] = std::to_string(diskData[0]);
	}

	if (configInfo.getBlk_reads() == 1) { //report[1]
										  // number of reads per second
		float temp = ((float)diskData[0] / (float)diskData[3]) * 1000;
		std::stringstream ss;
		ss << temp;
		std::string tempString = ss.str();
		report[1] = tempString;
		//        report[1] = std::to_string( ((float)diskData[0]/(float)diskData[3]) * 1000);
	}

	if (configInfo.getKb_reads() == 1) { //report[2]
										 // amount of data blocks read from disk per second in kb/s - size of sector is 1kb
										 //        report[2] = std::to_string((((float)diskData[0]/(float)diskData[3]) * 1000) * 2);
		float temp = (((float)diskData[0] / (float)diskData[3]) * 1000) * 2;
		std::stringstream ss;
		ss << temp;
		std::string tempString = ss.str();
		report[2] = tempString;
	}

	if (configInfo.getBlk_write() == 1) { //report[3]
										  // total number of blocks written
		float temp = diskData[4];
		std::stringstream ss;
		ss << temp;
		std::string tempString = ss.str();
		report[3] = tempString;
		//        report[3] = std::to_string(diskData[4]);
	}

	//todo: see below, something to try for rounding. Worried may not work right with floats
	//    12.456789 * 100 (10 to the 2nd power) = 1245.6789
	//    ceil( 1245.6789 ) = 1246
	//    1246 / 100 (10 to the 2nd power) = 12.46

	if (configInfo.getBlk_writes() == 1) { //report[4]
										   // number of data blocks written to disk per second - 4/7
										   //todo: getting nan
		float temp = ((float)diskData[4] / (float)diskData[7]) * 1000;
		std::stringstream ss;
		ss << temp;
		std::string tempString = ss.str();
		report[4] = tempString;
		//        report[4] = std::to_string(((float)diskData[4] / (float)diskData[7]) * 1000);
	}

	if (configInfo.getKb_writes() == 1) { //report[5]
										  // number of data blocks written to disk per second - in kb/s
										  //todo: getting nan
		float temp = (((float)diskData[4] / (float)diskData[7]) * 1000) * 2;
		std::stringstream ss;
		ss << temp;
		std::string tempString = ss.str();
		report[5] = tempString;
		//        report[5] = std::to_string((((float)diskData[4] / (float)diskData[7]) * 1000) * 2);
	}

	std::stringstream out("");

	for (int i = 0; i < 6; i++) {
		out << report[i] << " ";
	}

	//    std::cout << "output string: " << out.str() << endl;


	return out.str(); // return string of formatted data
}
