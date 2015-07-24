
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

	cout << "auDiskTool, VERSION " << VERSION << ". Type 'help' to find more about commands.\n\n";

	while (1) {

		//        system("run");

		cmd = inputCommand(cmd); // get command from user
		string type = cmd.type; //first word
		string flag = cmd.field; //second word
		string value = cmd.condition; //third word or number

		if (type == "run" && flag == "") {
			cout << "Tool is running..\n";
			report1.writeFile(configInfo);
			cout << "Report ready.\n";
		}

		else if (type == "set" && value != "") {

			if (flag == "report") {
				configInfo.setReportName(value);
				//                cout << "report name updated to: " << configInfo.getReportName() << endl;
			}

			else if (flag == "interval" || flag == "count") {
				//convert value to int
				int value;
				istringstream convert(cmd.condition);
				convert >> value;

				if (value < 1) {
					cout << "Please enter a valid command.\n";
				}
				else if (flag == "interval") {
					configInfo.setInterval(value);
				}
				else if (flag == "count") {
					configInfo.setCount(value);
				}
			}
			else if (flag == "blk_read") {
				//convert value to int
				int value;
				istringstream convert(cmd.condition);
				convert >> value;

				if (value != 0 && value != 1) {
					cout << "Please enter a valid input for value.\n";
				}
				else {
					configInfo.setBlk_read(value);
				}
			}
			else if (flag == "blk_read/s") {
				//convert value to int
				int value;
				istringstream convert(cmd.condition);
				convert >> value;

				if (value != 0 && value != 1) {
					cout << "Please enter a valid input for value.\n";
				}
				else {
					configInfo.setBlk_reads(value);
				}
			}
			else if (flag == "kb_read/s") {
				//convert value to int
				int value;
				istringstream convert(cmd.condition);
				convert >> value;

				if (value != 0 && value != 1) {
					cout << "Please enter a valid input for value.\n";
				}
				else {
					configInfo.setKb_reads(value);
				}
			}
			else if (flag == "blk_write") {
				//convert value to int
				int value;
				istringstream convert(cmd.condition);
				convert >> value;

				if (value != 0 && value != 1) {
					cout << "Please enter a valid input for value.\n";
				}
				else {
					configInfo.setBlk_write(value);
				}
			}
			else if (flag == "blk_write/s") {
				//convert value to int
				int value;
				istringstream convert(cmd.condition);
				convert >> value;

				if (value != 0 && value != 1) {
					cout << "Please enter a valid input for value.\n";
				}
				else {
					configInfo.setBlk_writes(value);
				}
			}
			else if (flag == "kb_write") {
				//convert value to int
				int value;
				istringstream convert(cmd.condition);
				convert >> value;

				if (value != 0 && value != 1) {
					cout << "Please enter a valid input for value.\n";
				}
				else {
					configInfo.setKb_writes(value);
				}
			}
			else {
				cout << "Please enter a valid command. Type 'help' to see commands.\n";
			}
		}

		else if (type == "print" && value == "") {

			if (flag == "conf") {
				configInfo.printConfig();
			}

			else if (flag == "report") {
				report1.printReport(configInfo);
			}

			else {
				cout << "Please enter a valid command. Type 'help' to see commands.\n";
			}
		}
		else if (type == "exit") {
			//todo: move to Tool class
			cout << "Determining if config settings have been updated..\n";
			configInfo.save();
			cout << "Exiting..\n";
			exit(0);
		}

		else if (type == "help") {
			//fdo: move to Tool class
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

void tool::printHelp() { //todo: move to Tool class (if we use Tool class?)
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