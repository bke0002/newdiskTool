
#include "tool.h"

command tool::inputCommand(command& newCommand) {
	string userCommand;
	int index;

	// prompt the user to enter a command
	cout << "> ";
	getline(cin, userCommand); // saves the entire user input as one string

// *************Separate the input string into three words***************************************
	
	// save first word as type "set, run, help, etc."
	index = userCommand.find(" ");
	newCommand.type = userCommand.substr(0, index);
	userCommand = userCommand.substr(index + 1); // scroll to next word

	// save second word as field "interval, count, config, etc."
	if (userCommand != newCommand.type) {
		index = userCommand.find(" "); // loc second word
		newCommand.field = userCommand.substr(0, index);  
		userCommand = userCommand.substr(index + 1); //scroll to next word

		// save third word as condition "input values or 1|0 indentifiers"
		if (userCommand != newCommand.field) {
			index = userCommand.find(" ");
			newCommand.condition = userCommand.substr(0, index);

		}
		else {
			newCommand.condition.clear();  // if there is no third word, clear the condition
		}
	}
	else {
		newCommand.field.clear(); // if there is no second word, clear the field and the condition
		newCommand.condition.clear();
	}
// ***********************************************************************************************
	return newCommand;
}

command cmd;
config_info configInfo;
report report1(configInfo);

void tool::launchTool() {

	bool loop = true;
	cout << "auDiskTool, VERSION " << VERSION << ". Type 'help' to find more about commands.\n\n";

	while (loop) {

		// *********system("run")**********************

		cmd = inputCommand(cmd); // get command from user
		string type = cmd.type; //first word
		string field = cmd.field; //second word
		string condition = cmd.condition; //third word or number

		// calls report/record classes (gets output from Linux)
		if (type == "run" && field == "") {
			cout << "Tool is running..\n";
			report1.writeFile(configInfo);
			cout << "Report ready.\n"; // saves report, lets user know process has been completed
		}

		// loop will catch all setter methods (command 'type' is set)
		else if (type == "set" && condition != "") {

			// changes local file name for report
			if (field == "report") {
				configInfo.setReportName(condition);
			}
			
			// calls setter functions for interval and count fields
			else if (field == "interval" || field == "count") {
				//convert value to int
				int value = -1;
				istringstream convert(cmd.condition); 
				convert >> value; 

				if (value < 1) { // ensure that the user entered valid data (no negatives or zeros or non integers)
					cout << "Please enter a valid command.\n";
				}
				else if (field == "interval") {
					configInfo.setInterval(value);
				}
				else if (field == "count") {
					configInfo.setCount(value);
				}
			}
			else if (field == "blk_read") {
				//convert value to int
				int value;
				istringstream convert(cmd.condition); 
				convert >> value; 

				if (value != 0 && value != 1) { // checks for invalid input
					cout << "Please enter a valid input for value.\n";
				}
				else {
					configInfo.setBlk_read(value);
				}
			}
			else if (field == "blk_read/s") {
				//convert value to int
				int value;
				istringstream convert(cmd.condition);
				convert >> value;

				if (value != 0 && value != 1) { // checks for invalid input
					cout << "Please enter a valid input for value.\n";
				}
				else {
					configInfo.setBlk_reads(value);
				}
			}
			else if (field == "kb_read/s") {
				//convert value to int
				int value;
				istringstream convert(cmd.condition);
				convert >> value;

				if (value != 0 && value != 1) { // checks for invalid input
					cout << "Please enter a valid input for value.\n";
				}
				else {
					configInfo.setKb_reads(value);
				}
			}
			else if (field == "blk_write") {
				//convert value to int
				int value;
				istringstream convert(cmd.condition);
				convert >> value;

				if (value != 0 && value != 1) { // checks for invalid input
					cout << "Please enter a valid input for value.\n";
				}
				else {
					configInfo.setBlk_write(value);
				}
			}
			else if (field == "blk_write/s") {
				//convert value to int
				int value;
				istringstream convert(cmd.condition);
				convert >> value;

				if (value != 0 && value != 1) { // checks for invalid input
					cout << "Please enter a valid input for value.\n";
				}
				else {
					configInfo.setBlk_writes(value);
				}
			}
			else if (field == "kb_write") {
				//convert value to int
				int value;
				istringstream convert(cmd.condition);
				convert >> value;

				if (value != 0 && value != 1) { // checks for invalid input
					cout << "Please enter a valid input for value.\n";
				}
				else {
					configInfo.setKb_writes(value);
				}
			}
			else { // if user enters 'set' then invalid input reprompt user
				cout << "Please enter a valid command. Type 'help' to see commands.\n";
			}
		}

		else if (type == "print" && condition == "") {

			if (field == "conf") { // prints configuration data (local)
				configInfo.printConfig();
			}

			else if (field == "report") { // prints report
				report1.printReport(configInfo);
			}

			else {
				cout << "Please enter a valid command. Type 'help' to see commands.\n";
			}
		}
		else if (type == "exit") {
			cout << "Determining if config settings have been updated..\n";
			configInfo.save(); // writes configuration data to file and ends execution
			cout << "Exiting..\n";
			loop = false;
		}

		else if (type == "help") {
			printHelp();
		}

		else if (type == "save") {
			configInfo.save();
		}
		else {
			cout << "Please enter a valid command. Type 'help' to see commands.\n";
		}

	} // End while loop

}

void tool::printHelp() { // list of commands for user (when user enters help)
	cout << "run - run the monitoring tool.\n"
		"set interval [value] ? set sampling period to [value]\n"
		"set count [value] ? set the number of records to [value]\n"
		"set report [name] ? set report file name to [name]\n"
		"set blk_read [0|1] ? set print_blk_read to 0 or 1\n"
		"set blk_read/s [0|1] ? set print_blk_read/s to 0 or 1\n"
		"set kb_read/s [0|1] ? set print_kb_read/s to 0 or 1\n"
		"set blk_write [0|1] ? set print_blk_write to 0 or 1\n"
		"set blk_write/s [0|1] ? set print_blk_write/s to 0 or 1\n"
		"set kb_write [0|1] ? set print_kb_write to 0 or 1\n"
		"print conf ? display all the parameters\n"
		"print report ? open and display the report file\n"
		"save ? the configuration file audisktool.conf is updated\n"
		"exit ? exit the tool.\n\n";
}