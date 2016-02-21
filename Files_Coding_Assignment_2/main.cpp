#include <iostream>
#include <fstream>


using std::cin;
using std::cout;
using std::endl;
using std::string;
const string CONFIG_FILE = "C:/Users/Brandon/Documents/config.txt";

int main(int argc, char *argv[]) {


    cout << "enter 1 for init or 2 for edit: " << endl;
    string argument;
    getline(cin, argument);
    if (argument == "1") {
        (static_cast<string>(argv[1]) == "init");
        cout << "init" << true << CONFIG_FILE;
    } else argument = "2";
    (static_cast <string>(argv[2]) == "edit");
    cout << "edit" << true;

    std::ofstream outfile;
    outfile.open("config.txt");

    //init user enter first name
    string first_name = "";
    do {
        cout << "enter your first name:" <<
        endl;
        getline(cin, first_name);
    } while (first_name == "");

//init user enter last name
    string last_name;
    do {
        cout << "enter your last name" <<
        endl;
        getline(cin, last_name);
    } while (last_name == "");

//init user enter email address
    string email_address = "";
    do {
        cout << "enter your email address" <<
        endl;
        std::getline(cin, email_address
        );
    } while (email_address == "");

//init user enter cypher
    string cypher_passcode;
    do {
        cout << "enter your cypher: " <<
        endl;
        std::getline(cin, cypher_passcode
        );
    } while (cypher_passcode == "");

//init user enter time offset
    string time_offset = "";
    do {
        cout << "enter your time offset: " << endl;
        std::getline(cin, time_offset);
    } while (time_offset == "");

//init user enter known recipients file
    string known_recipients_file = "";
    do {
        cout << "enter known recipients file: " << endl;
        getline(cin, known_recipients_file
        );
    } while (known_recipients_file == "");
    cout << "known_recipients_file= knownrecipients.txt" << endl;

    outfile.close();


    std::ifstream infile;
    infile.open("config.txt");
    cout << "Reading data from the file.\n";


    string file_first_name;
    string file_last_name;
    string file_email_address;
    string file_cypher_passcode;
    string file_time_offset;
    string file_known_recipients;

    infile >> file_first_name;
    infile >> file_last_name;
    infile >> file_email_address;
    infile >> file_cypher_passcode;
    infile >> file_time_offset;
    infile >> file_known_recipients;

    string edit_first_name;
    string edit_last_name;
    string edit_email_address;
    string edit_cypher_passcode;
    string edit_time_offset;
    string edit_known_recipients_file;

    cout << "enter new first name, last name, email address, cypher passcode, time offset, known file for the file: " << endl;
    string choose_field;
    getline(cin, choose_field);
    if (choose_field == "first name") {
        cout << "you have decided to edit the first name" << endl;
        cout << "enter first name: " << edit_first_name << endl;
        getline(cin, edit_first_name);
    } else if (choose_field == "last name") {
        cout << "you have decided to edit the last name" << endl;
        cout << "enter last name: " << edit_last_name << endl;
        getline(cin, edit_last_name);
    } else if (choose_field == "email address") {
        cout << "you have decided to edit the email address" << endl;
        cout << "enter email address: " << edit_email_address << endl;
        getline(cin, edit_email_address);
    } else if (choose_field == "cypher passcode") {
        cout << "you have decided to edit the cypher passcode" << endl;
        cout << "enter cypher passcode: " << edit_cypher_passcode << endl;
        getline(cin, edit_cypher_passcode);
    } else if (choose_field == "time offset") {
        cout << "you have decided to edit the time offset" << endl;
        cout << "enter time offset: " << edit_time_offset << endl;
        getline(cin, edit_time_offset);
    } else if (choose_field == "known file") {
        cout << "you have decided to edit the known recipients file" << endl;
        cout << "enter new file name: ";
        getline(cin, edit_known_recipients_file);
    }


    outfile.open("config.txt");

    outfile << edit_first_name << endl;
    outfile << edit_last_name << endl;
    outfile << edit_email_address << endl;
    outfile << edit_cypher_passcode << endl;
    outfile << edit_time_offset << endl;
    cout << "The information was saved to the file .\n" << endl;

    outfile.close();

    infile.close();
}









