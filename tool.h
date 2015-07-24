


#ifndef TOOL_H
#define TOOL_H

#include <fstream>
#include <iostream>
#include <string>
#include "config_info.h"
#include "report.h"
#include <sstream>


using namespace std;

struct command {
	string type;
	string flag;
	string value;
};



class tool {
private:
	const string VERSION = "1.0.0";

public:
	void launchTool();
	void printHelp();
	command inputCommand(command&);
};

#endif