#include <iostream>
#include <fstream>


using std::cin;
using std::cout;
using std::endl;
using std::string;

const string CONFIG_FILE = "C:/Users/Brandon/Documents/config.txt";

int main(int argc, char *argv[]) {

    cout << argc;
    if (static_cast<string>(argv[1]) == "init") {
        cout << "init" << endl;
    }
    void("init");
    std::ofstream outfile;
    outfile.open("config.txt");


    string first_name;
    string last_name;
    string email_address;
    string cypher_code;
    string time_offset;
    string known_recipients_file;

    cout << "enter your first name: " << endl;
    getline(cin, first_name);
    if (first_name.empty()) {
        cout << "ERROR: Please re-enter your first name" << endl;
    } else {
        cout << "enter your last name: " << endl;
        getline(cin, last_name);
        if (last_name.empty()) {
            cout << "ERROR: Please re-enter your last name: " << endl;
        } else {
            cout << "enter your email address: " << endl;
            getline(cin, email_address);
            if (email_address.empty()) {
                cout << "ERROR: Please re-enter your email address: " << endl;
            } else {
                cout << "please enter your unique cypher: " << endl;
                getline(cin, cypher_code);
                if (cypher_code.empty()) {
                    cout << "ERROR: Please re-enter your unique cypher: " << endl;
                } else {
                    cout << "please enter your time offset: " << endl;
                    getline(cin, time_offset);
                    if (time_offset.empty()) {
                        cout << "ERROR: Please re-enter your time offset: " << endl;
                    } else {
                        cout << "known_recipients_file = knownrecipients.txt" << endl;
                    }
                    outfile.close();
                    return 0;
                }

            }

        }
    }
}