//
// Created by Connor Jones on 7/14/15.
//

#ifndef AUDISKTOOL_CONFIG_INFO1_H
#define AUDISKTOOL_CONFIG_INFO1_H
#include <fstream>
#include <iostream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::endl;
using std::string;


class config_info {

private:
	int interval;
	int count;
	int blk_read;
	int blk_reads;
	int kb_reads;
	int blk_write;
	int blk_writes;
	int kb_writes;
	bool config_updated;
	string reportName;

public:
	int getInterval() const;

	void setInterval(int);

	int getCount() const;

	void setCount(int);

	int getBlk_read() const;

	void setBlk_read(int);

	int getBlk_reads() const;

	void setBlk_reads(int);

	int getKb_reads() const;

	void setKb_reads(int);

	int getBlk_write() const;

	void setBlk_write(int);

	int getBlk_writes() const;

	void setBlk_writes(int);

	int getKb_writes() const;

	void setKb_writes(int);

	const string &getReportName() const;

	void setReportName(const string);

	void printConfig();

	void save();

	config_info();

};


#endif //AUDISKTOOL_CONFIG_INFO1_H
