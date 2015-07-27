
#include "report.h"

void report::printReport(config_info configInfo) {

    string reportName = configInfo.getReportName().c_str();
    ifstream inStream(reportName.c_str());

    if(inStream.is_open()){ // make sure file is open
        std::string temp; // used to temporarily hold each line record
        std::string reportString;
        int numLines = 0;

        while(getline(inStream, temp)){
            numLines++;
            reportString += temp + "\n";
        }

        if(numLines > 0) { // make sure there are records in the file
            std::cout << numLines << " records found in '" << reportName << "'\n";
            std::cout << "blk_read blk_read/s kb_read/s blk_write blk_write/s kb_write/s\n";
            std:: cout << reportString << endl;
        } else {
            std::cout << " No record found in '" << reportName <<"'\n";
        }

        inStream.close();
    } else { 
        std::cout << "The file '" << reportName << "' could not be opened.\n";
    }


}

void report::writeFile(config_info configInfo) { //parameter needed so that object is updated if user changes config between runs
    ofstream outStream(configInfo.getReportName().c_str(), ios_base::app);

    // call makeRecord in the record class count number of times
    for(int count = 0; count < configInfo.getCount(); count++) {
        record record1(configInfo);
        std::string lineRecord = record1.makeRecord();

        outStream << lineRecord << endl;
        Sleep((unsigned int) (configInfo.getInterval()*1000)); // HAD TO CHANGE THIS LINE FOR WINDOWS!! 
    }


    outStream.flush();
    outStream.close();
}

// constructor (used mostly in development)
report::report(config_info configInfo) { 

}