#include <iostream>
#include <fstream>


using std::cin;
using std::cout;
using std::endl;
using std::string;

const string CONFIG_FILE = "C:/Users/Brandon/Documents/config.txt";

void init() {
    std::ofstream outfile;
    outfile.open("config.txt");

    //init user enter first name
    string first_name = "";
    do {
        cout << "enter your first name:" << endl;
        getline(cin, first_name);
    } while (first_name == "");

    //init user enter last name
    string last_name;
    do {
        cout << "enter your last name" << endl;
        getline(cin, last_name);
    } while (last_name == "");

    //init user enter email address
    string email_address = "";
    do {
        cout << "enter your email address" << endl;
        std::getline(cin, email_address);
    } while (email_address == "");

    //init user enter cypher
    string cypher_passcode;
    do {
        cout << "enter your cypher: " << endl;
        std::getline(cin, cypher_passcode);
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
        getline(cin, known_recipients_file);
    } while (known_recipients_file == "");
    cout << "known_recipients_file= knownrecipients.txt" << endl;

    outfile.close();
}

int main(int argc, char *argv[]) {


    cout << argc;
    if (argc != 0) {
        cout << "opening config file" << CONFIG_FILE << endl;
    }

    if (static_cast<string>(argv[1]) == "init") {
        cout << init;
    }

    if (static_cast<string>(argv[2]) == "edit") {
        cout << edit;
    }
}


void edit() {
    std::ifstream infile;
    infile.open("config.txt");
    cout << "Reading data from the file.\n";


    string edit_first_name;
    string edit_last_name;
    string edit_email_address;
    string edit_cypher_passcode;
    string edit_time_offset;

    infile >> edit_first_name;
    infile >> edit_last_name;
    infile >> edit_email_address;
    infile >> edit_cypher_passcode;
    infile >> edit_time_offset;

    string new_email_address;
    getline(cin, new_email_address);
    cout << "enter new email address for the file: ";
    while (new_email_address == "") {
        cout << "enter new email address for the file: ";
        getline(cin, new_email_address);
    }

    std::ofstream outfile;
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





