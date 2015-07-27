//
// Created by Connor Jones on 7/14/15.
//

#ifndef AUDISKTOOL_RECORD_H
#define AUDISKTOOL_RECORD_H

#include "math.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "config_info.h"

using namespace std;

class record {
private:
	config_info configInfo;

public:
	record(config_info configInfo);
	string makeRecord();
};


#endif //AUDISKTOOL_RECORD_H

