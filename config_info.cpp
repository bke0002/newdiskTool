//
// Created by Connor Jones on 7/14/15.
//

#include "config_info.h"

int config_info::getInterval() const { return interval; }

void config_info::setInterval(int interval) {
	if (interval != getInterval()) {
		config_info::interval = interval;
		config_updated = true;
		std::cout << "The sampling interval has been changed to " << interval << " seconds.\n";
	}
	else {
		std::cout << "Interval is already " << interval << ".\n";
	}
}

int config_info::getCount() const { return count; }

void config_info::setCount(int count) {
	if (count != getCount()) {
		config_info::count = count;
		config_updated = true;
		std::cout << "The number of records in each run has been changed to " << getCount() << ".\n";
	}
	else {
		std::cout << "The number of records generated in each run is already set to " << getCount() << ".\n";
	}
}

int config_info::getBlk_read() const { return blk_read; }

void config_info::setBlk_read(int blk_read) {
	if (blk_read != getBlk_read()) {
		config_info::blk_read = blk_read;
		config_updated = true;
		std::cout << "print_blk_read has been changed to " << getBlk_read() << ".\n";
	}
	else {
		std::cout << "print_blk_read was " << getBlk_read() << "; the parameter remains unchanged to "
			<< getBlk_read() << ".\n";
	}
}

int config_info::getBlk_reads() const { return blk_reads; }

void config_info::setBlk_reads(int blk_reads) {
	if (blk_reads != getBlk_reads()) {
		config_info::blk_reads = blk_reads;
		config_updated = true;
		std::cout << "print_blk_read/s has been changed to " << getBlk_reads() << ".\n";
	}
	else {
		std::cout << "print_blk_read/s was " << getBlk_reads() << "; the parameter remains unchanged to "
			<< getBlk_reads() << ".\n";
	}
}

int config_info::getKb_reads() const { return kb_reads; }

void config_info::setKb_reads(int kb_reads) {
	if (kb_reads != getKb_reads()) {
		config_info::kb_reads = kb_reads;
		config_updated = true;
		std::cout << "print_kb_reads has been changed to " << getKb_reads() << ".\n";
	}
	else {
		std::cout << "print_kb_reads was " << getKb_reads() << "; the parameter remains unchanged to "
			<< getKb_reads() << ".\n";
	}
}

int config_info::getBlk_write() const { return blk_write; }

void config_info::setBlk_write(int blk_write) {
	if (blk_write != getBlk_write()) {
		config_info::blk_write = blk_write;
		config_updated = true;
		std::cout << "print_blk_write has been changed to " << getBlk_write() << ".\n";
	}
	else {
		std::cout << "print_blk_write was " << getBlk_write() << "; the parameter remains unchanged to "
			<< getBlk_write() << ".\n";
	}
}

int config_info::getBlk_writes() const { return blk_writes; }

void config_info::setBlk_writes(int blk_writes) {
	if (blk_writes != getBlk_writes()) {
		config_info::blk_writes = blk_writes;
		config_updated = true;
		std::cout << "print_blk_write/s has been changed to " << getBlk_writes() << ".\n";
	}
	else {
		std::cout << "print_blk_write/s was " << getBlk_writes() << "; the parameter remains unchanged to "
			<< getBlk_writes() << ".\n";
	}
}

int config_info::getKb_writes() const { return kb_writes; }

void config_info::setKb_writes(int kb_writes) {
	if (kb_writes != getKb_writes()) {
		config_info::kb_writes = kb_writes;
		config_updated = true;
		std::cout << "print_kb_write/s has been changed to " << getKb_writes() << ".\n";
	}
	else {
		std::cout << "print_kb_write/s was " << getKb_writes() << "; the parameter remains unchanged to "
			<< getKb_writes() << ".\n";
	}
}

const string &config_info::getReportName() const { return reportName; }

void config_info::setReportName(const string name) {
	//todo: need to account for taking in full path? It may actually just work as is though. Will test.
	string oldName = getReportName();
	config_info::reportName = name;
	std::cout << "The report file name is changed from " << oldName << "' to '" << getReportName()
		<< "'. \nYou can now type 'run' to generate new records to be saved in '"
		<< getReportName() << "'. \nNote: '" << oldName << "' will not be deleted by audisktool.\n";
}

void config_info::printConfig() {
	std::cout << "Interval: " << config_info::interval << endl;
	std::cout << "Count: " << getCount() << endl;
	std::cout << "Blk_read: " << getBlk_read() << endl;
	std::cout << "Blk_read/s: " << getBlk_reads() << endl;
	std::cout << "Kb_reads: " << getKb_reads() << endl;
	std::cout << "Blk_write: " << getBlk_write() << endl;
	std::cout << "Blk_write/s: " << getBlk_writes() << endl;
	std::cout << "Kb_write/s: " << getKb_writes() << endl;
	std::cout << "file name: " << getReportName() << endl << endl;
}

void config_info::save() {
	if (config_updated) {
		//save
		std::cout << "Saving configuration settings..\n";


		ofstream outStream("audisktool.conf"); //open file
		outStream << interval;
		outStream << " ";

		outStream << count;
		outStream << " ";

		outStream << blk_read;
		outStream << " ";

		outStream << blk_reads;
		outStream << " ";

		outStream << kb_reads;
		outStream << " ";

		outStream << blk_write;
		outStream << " ";

		outStream << blk_writes;
		outStream << " ";

		outStream << kb_writes;
		outStream << " ";

		outStream.close(); //close file
		std::cout << "Configuration settings have been saved.\n";
	}
	else {
		std::cout << "audisktool.conf has not been updated. There is no need to save the file.\n";
	}
}

config_info::config_info() {
	ifstream inStream("audisktool.conf");
	inStream >> interval;
	inStream >> count;
	inStream >> blk_read;
	inStream >> blk_reads;
	inStream >> kb_reads;
	inStream >> blk_write;
	inStream >> blk_writes;
	inStream >> kb_writes;

	//        inStream.close();

	reportName = "report.txt";
	config_updated = false;

	//todo: should we close inStream?
}
