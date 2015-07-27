//
// Created by Connor Jones on 7/14/15.
//

#include "config_info.h"

// getter function for interval (returns the local form of interval)
int config_info::getInterval() const { return interval; }

// accessor function for interval (only changes the local form)
void config_info::setInterval(int interval) {
	if (interval != getInterval()) { // checks to see if the user input interval is the same as the current interval
		config_info::interval = interval;
		config_updated = true; // if the interval is updated, changes update marker for configuration file
		std::cout << "The sampling interval has been changed to " << interval << " seconds.\n";
	}
	else { // let the user know that their selection is the same as the current interval setting
		std::cout << "Interval is already " << interval << ".\n";
	}
}

// getter function for count (returns the local form of count)
int config_info::getCount() const { return count; }

// accessor function for count (only changes the local)
void config_info::setCount(int count) {
	if (count != getCount()) { // checks to see if the user input count is the same as the current count
		config_info::count = count;
		config_updated = true; // update marker for configuration file
		std::cout << "The number of records in each run has been changed to " << getCount() << ".\n";
	}
	else { // let the user know that their selection is the same as the current count setting
		std::cout << "The number of records generated in each run is already set to " << getCount() << ".\n";
	}
}

// getter function for blk_read (returns the local form)
int config_info::getBlk_read() const { return blk_read; }

// accessor function for blk_read (only changes the local)
void config_info::setBlk_read(int blk_read) {
	if (blk_read != getBlk_read()) {
		config_info::blk_read = blk_read;
		config_updated = true; // update marker for configuration file
		std::cout << "print_blk_read has been changed to " << getBlk_read() << ".\n";
	}
	else { // let the user know that their selection is the same as the current setting
		std::cout << "print_blk_read was " << getBlk_read() << "; the parameter remains unchanged to "
			<< getBlk_read() << ".\n";
	}
}

// getter function for blk_reads (returns the local form)
int config_info::getBlk_reads() const { return blk_reads; }

// accessor function for blk_reads (only changes the local)
void config_info::setBlk_reads(int blk_reads) {
	if (blk_reads != getBlk_reads()) {
		config_info::blk_reads = blk_reads;
		config_updated = true; // update marker for configuration file
		std::cout << "print_blk_read/s has been changed to " << getBlk_reads() << ".\n";
	}
	else { // let the user know that their selection is the same as the current setting
		std::cout << "print_blk_read/s was " << getBlk_reads() << "; the parameter remains unchanged to "
			<< getBlk_reads() << ".\n";
	}
}

// getter function for kb_reads (returns the local form)
int config_info::getKb_reads() const { return kb_reads; }

// accessor function for kb_reads (only changes the local)
void config_info::setKb_reads(int kb_reads) {
	if (kb_reads != getKb_reads()) {
		config_info::kb_reads = kb_reads;
		config_updated = true; // update marker for configuration file
		std::cout << "print_kb_reads has been changed to " << getKb_reads() << ".\n";
	}
	else { // let the user know that their selection is the same as the current setting
		std::cout << "print_kb_reads was " << getKb_reads() << "; the parameter remains unchanged to "
			<< getKb_reads() << ".\n";
	}
}

// getter function for blk_write (returns the local form)
int config_info::getBlk_write() const { return blk_write; }

// accessor function for blk_write (only changes the local)
void config_info::setBlk_write(int blk_write) {
	if (blk_write != getBlk_write()) {
		config_info::blk_write = blk_write;
		config_updated = true; // update marker for configuration file
		std::cout << "print_blk_write has been changed to " << getBlk_write() << ".\n";
	}
	else { // let the user know that their selection is the same as the current setting
		std::cout << "print_blk_write was " << getBlk_write() << "; the parameter remains unchanged to "
			<< getBlk_write() << ".\n";
	}
}

// getter function for blk_writes(returns the local form)
int config_info::getBlk_writes() const { return blk_writes; }

// accessor function for blk_writes (only changes the local)
void config_info::setBlk_writes(int blk_writes) {
	if (blk_writes != getBlk_writes()) {
		config_info::blk_writes = blk_writes;
		config_updated = true; // update marker for configuration file
		std::cout << "print_blk_write/s has been changed to " << getBlk_writes() << ".\n";
	}
	else { // let the user know that their selection is the same as the current setting
		std::cout << "print_blk_write/s was " << getBlk_writes() << "; the parameter remains unchanged to "
			<< getBlk_writes() << ".\n";
	}
}

// getter function for kb_writes (returns the local form)
int config_info::getKb_writes() const { return kb_writes; }

// accessor function for kb_writes (only changes the local)
void config_info::setKb_writes(int kb_writes) {
	if (kb_writes != getKb_writes()) {
		config_info::kb_writes = kb_writes;
		config_updated = true; // update marker for configuration file
		std::cout << "print_kb_write/s has been changed to " << getKb_writes() << ".\n";
	}
	else { // let the user know that their selection is the same as the current setting
		std::cout << "print_kb_write/s was " << getKb_writes() << "; the parameter remains unchanged to "
			<< getKb_writes() << ".\n";
	}
}

// getter function for report file name (returns the local form, i.e. default if the filename is not currently set)
const string &config_info::getReportName() const { return reportName; }

// accessor function for report file name (only changes the local)
void config_info::setReportName(const string name) {
	string oldName = getReportName();
	config_info::reportName = name;
	std::cout << "The report file name is changed from " << oldName << "' to '" << getReportName()
		<< "'. \nYou can now type 'run' to generate new records to be saved in '"
		<< getReportName() << "'. \nNote: '" << oldName << "' will not be deleted by audisktool.\n";
}

// prints the current configurations settings  (local configuration)
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
	if (config_updated) { // only saves file if changes have been made (marker is updated)
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
		// TODO: should we reset the configuration update marker???????????
	}
	else { // let the user know that nothing was updated
		std::cout << "audisktool.conf has not been updated. There is no need to save the file.\n";
	}
}


// Reads information from the configuration file, called at beginning of execution.
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

	inStream.close();

	reportName = "report.txt";
	config_updated = false; // reset configuration marker

}
