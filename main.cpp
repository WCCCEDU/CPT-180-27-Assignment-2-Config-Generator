#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::ofstream;
using std::ifstream;

const string CONFIG_FILE_PATH = "config.txt";
const string NEW_CONFIG_FILE_PATH = "Editconfig.txt";

void init() {
    ofstream outputFile;
    outputFile.open(CONFIG_FILE_PATH);

    string Name;
    cout << "Enter name:" << endl;
    cin >> Name;
    while (Name == "") {
        cout << "Re-Enter name" << endl;
        cin >> Name;
    }
    outputFile << "[name] = " << Name << endl;

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
int main (int argc, char *argv[]) {
    if (static_cast<string>(argv[1]) == "init") {
        init();
    }
    else if(static_cast<string>(argv[1]) == "edit") {

        ifstream inputfile;
        inputfile.open(CONFIG_FILE_PATH);


        string Name;
        string email;
        string cypher;
        string timeZoneDiff;
        string knownRecipientsFile;

// read config file
        inputfile >> Name;
        inputfile >> email;
        inputfile >> cypher;
        inputfile >> timeZoneDiff;
        inputfile >> knownRecipientsFile;

        inputfile.close();
        ofstream new_outputfile;
        new_outputfile.open(NEW_CONFIG_FILE_PATH);
        cout << argv[2];
        if (static_cast<string>(argv[2]) == "name") {
            cout << "Edit  name:" << endl;
            cin >> Name;
            while (Name == "") {
                cout << "Re-Enter name" << endl;
                cin >> Name;
            }
            new_outputfile << "[name] = " << Name << endl;
        }

        if (static_cast<string>(argv[2]) == "email") {
            cout << "edit email:" << endl;
            cin >> email;
            while (email == "") {
                cout << "Re-Enter email" << endl;
                cin >> email;
            }
            new_outputfile << "[email] = " << email << endl;
        }
        if (static_cast<string>(argv[2]) == "password") {
            cout << "edit password:" << endl;
            cin >> cypher;
            while (cypher == "") {
                cout << "Re-Enter password" << endl;
                cin >> cypher;
            }
            new_outputfile << "[cypher] = " << cypher << endl;
        }
        if (static_cast<string>(argv[2]) == "timezone") {
            cout << "edit Time Zone Differential:" << endl;
            cin >> timeZoneDiff;
            while (timeZoneDiff == "") {
                cout << "Re-Enter Time Zone Differential" << endl;
                cin >> timeZoneDiff;
            }
            new_outputfile << "[timezone] = " << timeZoneDiff << endl;
        }
        if (static_cast<string>(argv[2]) == "knownrecipients") {
            cout << "Enter Known recipients file path" << endl;
            cin >> knownRecipientsFile;
            if (knownRecipientsFile == "") {
                new_outputfile << "[knowrecipients] = knownrecipient.txt" << endl;
            } else
                new_outputfile << "[knowrecipients] = " << knownRecipientsFile << endl;
        }
    }

        return 0;
}

