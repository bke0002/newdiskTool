// Report stores data from each call to linux or 'record' in a file. Can also print data directly out to the user

#ifndef AUDISKTOOL_REPORT_H
#define AUDISKTOOL_REPORT_H

#include "record.h"
#include "windows.h"
//#include "unistd.h"

using namespace std; 

using std::ifstream;
using std::ofstream;

class report {
private:
	config_info configInfo;

public:
	report(config_info configInfo); //constructor really only utilized in development and testing
	void printReport(config_info);
	void writeFile(config_info);

};


#endif //AUDISKTOOL_REPORT_H
