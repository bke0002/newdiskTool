//
// Created by Connor Jones on 7/14/15.
//

//#include "unistd.h"
#include "report.h"
#include "windows.h"

using namespace std;
//need to include record

void report::printReport(config_info configInfo) {
	//    todo: need to catch exception where file can't be opened
	//todo: need to print # of records found in the report

	ifstream inStream(configInfo.getReportName().c_str());


	std::string temp; // used to temporarily hold each line record
	std::string reportString;
	int numLines = 0;

	while (getline(inStream, temp)) {
		numLines++;
		reportString += temp + "\n";
	}

	std::cout << "Records found: " << numLines << endl;
	std::cout << "blk_read blk_read/s kb_read/s blk_write blk_write/s kb_write/s\n";
	std::cout << reportString << endl;

	inStream.close();
}

void report::writeFile(config_info configInfo) { //parameter needed so that object is updated if user changes config between runs
	ofstream outStream(configInfo.getReportName().c_str(), ios_base::app);

	// call makeRecord in the record class count times
	for (int i = 0; i < configInfo.getCount(); i++) {
		record record1(configInfo);
		std::string lineRecord = record1.makeRecord();

		outStream << lineRecord << endl;
		Sleep((unsigned int)(configInfo.getInterval()));
	}


	outStream.flush();
	outStream.close();
}

report::report(config_info configInfo) { //todo: may not need the constructor
										 //    report::configInfo = configInfo;
										 //    string file = "\"" + configInfo.getReportName() + "\"";
										 //    report::fileName = file;
}
