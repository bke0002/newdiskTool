//
// Created by Connor Jones on 7/14/15.
//

#ifndef AUDISKTOOL_REPORT_H
#define AUDISKTOOL_REPORT_H
//#include <fstream> //shouldn't be needed
//#include "config_info.h" //also might not need
#include "record.h"

using std::ifstream;
using std::ofstream;

class report {
private:
	config_info configInfo;

public:
	report(config_info configInfo); //todo: may not be needed
	void printReport(config_info);
	void writeFile(config_info);

};


#endif //AUDISKTOOL_REPORT_H
