#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::ofstream;
using std::ifstream;

const string CONFIG_FILE_PATH = "/Users/Jon/Desktop/C++repos/CPT-180-27-Assignment-2-Config-Generator/config.txt";
const string NEW_CONFIG_FILE_PATH = "/Users/Jon/Desktop/C++repos/CPT-180-27-Assignment-2-Config-Generator/Editconfig.txt";

void init() {
    ofstream outputFile;
    outputFile.open(CONFIG_FILE_PATH);

    string lastName;
    cout << "Enter last name:" << endl;
    cin >> lastName;
    while (lastName == "") {
        cout << "Re-Enter last name" << endl;
        cin >> lastName;
    }
    outputFile << "[lastname] = " << lastName << endl;

    string firstName;
    cout << "Enter first name:" << endl;
    cin >> firstName;
    while (firstName == "") {
        cout << "Re-Enter first name" << endl;
        cin >> firstName;
    }
    outputFile << "[firstname] = " << firstName << endl;

    string email;
    cout << "Enter email:" << endl;
    cin >> email;
    while (email == "") {
        cout << "Re-Enter email" << endl;
        cin >> email;
    }
    outputFile << "[email] = " << email << endl;

    string cypher;
    cout << "Enter password:" << endl;
    cin >> cypher;
    while (cypher == "") {
        cout << "Re-Enter password" << endl;
        cin >> cypher;
    }
    outputFile << "[cypher] = " << cypher << endl;

    string timeZoneDiff;
    cout << "Enter Time Zone Differential:" << endl;
    cin >> timeZoneDiff;
    while (timeZoneDiff == "") {
        cout << "Re-Enter Time Zone Differential" << endl;
        cin >> timeZoneDiff;
    }
    outputFile << "[timezone] = " << timeZoneDiff << endl;

    string knownRecipientsFile;
    cout << "Enter Known recipients file path" << endl;
    cin >> knownRecipientsFile;
    if (knownRecipientsFile == "") {
        outputFile << "[knowrecipients] = knownrecipient.txt" << endl;
    } else
        outputFile << "[knowrecipients] = " << knownRecipientsFile << endl;

    outputFile.close();
}
void edit() {
    ifstream inputfile;
    inputfile.open(CONFIG_FILE_PATH);

    string lastName;
    string firstName;
    string email;
    string cypher;
    string timeZoneDiff;
    string knownRecipientsFile;

// read config file
    inputfile >> lastName;
    inputfile >> firstName;
    inputfile >> email;
    inputfile >> cypher;
    inputfile >> timeZoneDiff;
    inputfile >>knownRecipientsFile;

    inputfile.close();
    ofstream new_outputfile;
    new_outputfile.open(NEW_CONFIG_FILE_PATH);

    cout << "Edit last name:" << endl;
    cin >> lastName;
    while (lastName == "") {
        cout << "Re-Enter last name" << endl;
        cin >> lastName;
    }
    new_outputfile << "[lastname] = " << lastName << endl;

    cout << "edit first name:" << endl;
    cin >> firstName;
    while (firstName == "") {
        cout << "Re-Enter first name" << endl;
        cin >> firstName;
    }
    new_outputfile << "[firstname] = " << firstName << endl;


    cout << "edit email:" << endl;
    cin >> email;
    while (email == "") {
        cout << "Re-Enter email" << endl;
        cin >> email;
    }
    new_outputfile << "[email] = " << email << endl;


    cout << "edit password:" << endl;
    cin >> cypher;
    while (cypher == "") {
        cout << "Re-Enter password" << endl;
        cin >> cypher;
    }
    new_outputfile << "[cypher] = " << cypher << endl;


    cout << "edit Time Zone Differential:" << endl;
    cin >> timeZoneDiff;
    while (timeZoneDiff == "") {
        cout << "Re-Enter Time Zone Differential" << endl;
        cin >> timeZoneDiff;
    }
    new_outputfile << "[timezone] = " << timeZoneDiff << endl;


    cout << "Enter Known recipients file path" << endl;
    cin >> knownRecipientsFile;
    if (knownRecipientsFile == "") {
        new_outputfile<< "[knowrecipients] = knownrecipient.txt" << endl;
    } else
        new_outputfile << "[knowrecipients] = " << knownRecipientsFile << endl;
}
main(int argc, char *argv[]);
    if(static_cast<string>(argv[1]) == "init"){
        init();
}
    else(static_cast<string>(argv[2]) == "edit"){
        edit()
}



