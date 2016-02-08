#include <iostream>
#include <fstream>


using std::cin;
using std::cout;
using std::endl;
using std::string;

const string config_file = "/users/Brandon/Files_Coding_Assignment_2/config.txt";

int main(int argc, char *argv[]) {

    if (argc != 0)
        cout << "opening config file" << config_file;
    endl;

    std::ofstream config_file;
    outputFile.open("config.txt");

    //I am trying compare it to the config and output false if user enters it incorrectly
    string first_name;
    cout << "enter your first name" << endl;
    getline(cin, first_name);


    string last_name;
    cout << "enter your last name" << endl;
    getline(cin, last_name);

    string email_address;
    cout << "enter your email address" << endl;
    getline(cin, email_address);

    string cypher_passcode;
    cout << "enter your cypher" << endl;
    getline(cin, cypher_passcode);

    string time_offset;
    cout << "enter your time offset" << endl;
    getline(cin, time_offset);


    string known_recipients_file;
    cout << "enter the known recipients file" << endl;
    getline(cin, known_recipients_file);
outputFile.close("config.txt");
}