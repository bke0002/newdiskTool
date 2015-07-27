
#include "record.h"

record::record(config_info configInfo) {
	record::configInfo = configInfo;
}

string record::makeRecord() {

	ifstream inStream("/proc/diskstats"); // open file location for linux disk stats

	if (!inStream.is_open()) { // close program if there is an issue reading from the linux folder
		std::cout << "Error: file could not be opened. Program will terminate.\n";
		exit(0);
	}

	string report[6];

	for (int index = 0; index < 6; index++) { //initialize report array
		report[index] = "N/A";
	}

	string inputString;
	getline(inStream, inputString);

	long loc = inputString.find("sda");
	if (loc > 0) { // remove 1st three fields since they aren't used
		inputString = inputString.substr(loc);
		inputString = inputString.substr(inputString.find(' ') + 1);
	}

	int diskData[11];

	for (int index = 0; index < 11; index++) { // put 11 data elements from disk into array
		std::istringstream convert(inputString.substr(0, inputString.find(' ')).c_str());
		inputString = inputString.substr(inputString.find(' ') + 1);
		convert >> diskData[index];
	}

	if (configInfo.getBlk_read() == 1) { // report[0]

		float temp = diskData[0];
		std::stringstream ss; // use stringstream to convert from string to float
		ss << temp;
		std::string tempString = ss.str();
		report[0] = tempString; // put value in report array (to be written to file)
	}

	if (configInfo.getBlk_reads() == 1) { //report[1]

		float temp = ((float)diskData[0] / (float)diskData[3]) * 1000;
		std::stringstream ss; // use stringstream to convert from string to float
		ss << temp;
		std::string tempString = ss.str();
		report[1] = tempString; // put value in report array (to be written to file)

	}

	if (configInfo.getKb_reads() == 1) { //report[2]
		// amount of data blocks read from disk per second in kb/s - size of sector is 1kb
		float temp = (((float)diskData[0] / (float)diskData[3]) * 1000) * 2;
		std::stringstream ss;
		ss << temp;  // use stringstream to convert from string to float
		std::string tempString = ss.str();
		report[2] = tempString; // put value in report array (to be written to file)
	}

	if (configInfo.getBlk_write() == 1) { //report[3]

		float temp = diskData[4];
		std::stringstream ss;
		ss << temp; // use stringstream to convert from string to float
		std::string tempString = ss.str();
		report[3] = tempString;  // put value in report array (to be written to file)
	}

	if (configInfo.getBlk_writes() == 1) { //report[4]
		// number of data blocks written to disk per second - 4/7
		float temp = ((float)diskData[4] / (float)diskData[7]) * 1000;
		std::stringstream ss;
		ss << temp;  // use stringstream to convert from string to float
		std::string tempString = ss.str();
		report[4] = tempString;  // put value in report array (to be written to file)
	}

	if (configInfo.getKb_writes() == 1) { //report[5]
	// number of data blocks written to disk per second - in kb/s

		float temp = (((float)diskData[4] / (float)diskData[7]) * 1000) * 2;
		std::stringstream ss;
		ss << temp;  // use stringstream to convert from string to float
		std::string tempString = ss.str();
		report[5] = tempString;  // put value in report array (to be written to file)
	}

	std::stringstream out("");

	for (int index = 0; index < 6; index++) {
		out << report[index] << "\t";
	}

	return out.str(); // return string of formatted data
}