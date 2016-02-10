#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::getline;

const string CONFIG_FILE_WRITE_PATH = "/Users/Jon/Desktop/C++repos/CPT-180-27-Assignment-2-Config-Generator/config.txt";

int main(int argc, char *argv[]){
// init
    std::ofstream outputFile;
    outputFile.open (CONFIG_FILE_WRITE_PATH);

    string lastName;
    cout << "Enter last name:" << endl;
    getline(cin,lastName);
    if(lastName == "")
        cout << "Re-Enter last name" << endl;
        getline(cin,lastName);
    outputFile << "[lastname] = " << lastName << endl;

    string firstName;
    cout << "Enter first name:" << endl;
    getline(cin,firstName);
    if(firstName == "")
        cout << "Re-Enter first name" << endl;
        getline(cin,firstName);
    outputFile << "[firstname] = " << firstName << endl;

    string email;
    cout << "Enter email:" << endl;
    getline(cin,email);
    if(email == "")
        cout << "Re-Enter email" << endl;
        getline(cin,email);
    outputFile << "[email] = " << email << endl;

    string cypher;
    cout << "Enter password:" << endl;
    getline(cin,cypher);
    if(cypher == "")
        cout << "Re-Enter password" << endl;
        getline(cin,cypher);
    outputFile << "[cypher] = " << cypher << endl;

    string timeZoneDiff;
    cout << "Enter Time Zone Differential:" << endl;
    getline(cin,timeZoneDiff);
    if(timeZoneDiff == "")
        cout << "Re-Enter Time Zone Differential" << endl;
        getline(cin,timeZoneDiff);
    outputFile << "[timezone] = " << timeZoneDiff << endl;

    string knownRecipientsFile;
    cout << "Enter Known recipients file path" <<endl;
    getline(cin,knownRecipientsFile);
    if(knownRecipientsFile == "")
        knownRecipientsFile == "knownrecipient.txt";
    outputFile << "[knowrecipients] = " << knownRecipientsFile << endl;

    outputFile.close();


    //edit

    outputFile.open (CONFIG_FILE_WRITE_PATH);


    cout << "Edit last name:" << endl;
    getline(cin,lastName);
    if(lastName == "")
        cout << "Re-Enter last name" << endl;
    getline(cin,lastName);
    outputFile << "[lastname] = " << lastName << endl;


    cout << "Edit first name:" << endl;
    getline(cin,firstName);
    if(firstName == "")
        cout << "Re-Enter first name" << endl;
    getline(cin,firstName);
    outputFile << "[firstname] = " << firstName << endl;



    cout << "Edit Known recipients file path" <<endl;
    getline(cin,knownRecipientsFile);
    if(knownRecipientsFile == "")
        knownRecipientsFile == "knownrecipient.txt";
    outputFile << "[knowrecipients] = " << knownRecipientsFile << endl;

    outputFile.close();

    return 0;
}
