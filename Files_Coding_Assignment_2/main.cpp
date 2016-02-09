#include <iostream>
#include <fstream>
#include <io.h>


using std::cin;
using std::cout;
using std::endl;
using std::string;

const string outfile = "C:/users/Brandon/Files_Coding_Assignment_2/config.txt";
const string infile = "C:/users/Brandon/Documents/knownrecipients.txt";

int main(int argc, char *argv[]) {

    string argument = "";
    string argument_choice, argument0, argument1, argument2;
    cout << "enter argument 0 to open file, enter 1 to output config file content, enter 2 to edit";
    if (argc != 0) {
        argument0 = static_cast<string>(argv[0]);
    }
//valid (init);

    if (argument_choice == "1") {
        argument1 = static_cast<string>(argv[1]);
        cout << "you are now entering the init stage";
    }
    std::ofstream outfile;
    outfile.open("config.txt");

    string test_value;
    cout << "enter your first name:" << endl;
    getline(cin, test_value);

    //if the user entered something incorrect
    while (test_value == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your first name: " << endl;
        std::getline(cin, test_value);
    }
    outfile << "[firstname]=" << test_value << endl;
    test_value = "";

    cout << "enter your last name" << endl;
    getline(cin, test_value);
    while (test_value == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your last name: " << endl;
        getline(cin, test_value);
    }
    outfile << "[lastname]=" << test_value << endl;
    test_value = "";

    cout << "enter your email address" << endl;
    getline(cin, test_value);
    while (test_value == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your email address: " << endl;
        getline(cin, test_value);
    }
    outfile << "[email]=" << test_value << endl;
    test_value = "";

    cout << "please enter your unique cypher: " << endl;
    std::getline(cin, test_value);
    while (test_value == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your unique cypher: " << endl;
        getline(cin, test_value);
    }
    outfile << "[cypher]=" << test_value << endl;
    test_value = "";

    cout << "please enter your time offset: " << endl;
    getline(cin, test_value);
    while (test_value == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your time offset: " << endl;
        getline(cin, test_value);
    }
    outfile << "[timeoffset]=" << test_value << endl;
    test_value = "";

    cout << "please enter the known recipients file: " << endl;
    if (test_value == "") {
        outfile << "[knownfile] = knownrecipients.txt";
    } else {
        outfile << "[knownrecipient]=" << test_value << endl;
    }
    outfile.close();

//valid(edit)
    std::ifstream infile;
    infile.open("knownrecipients.txt");

    std::ofstream outfile;
    outfile.open.("knownrecipients");

    if (infile.fail()) {
        cout << "Error opening file. \n" << endl;
    }
    else {
        //Process the file.
    }
    string char;
    cout << "Reading data from the file.\n" << endl;

//Reading the text from the file, seeing if the file opened, and outputting them
    char my_character;
    int number_of_lines = 0;

    if (!infile.eof()) {

        infile.get(my_character);
        cout << my_character;
        if (my_character == '\n') {
            cout << number_of_lines << ++number_of_lines << endl;
        }
        cout << "NUMBER OF LINES: " << number_of_lines << endl;
    }

    if (number_of_lines == 6){
         cout << "Let's party on! On to the editing part!" << endl;
    }

    //Declaration of variables

    string first_name;
    string last_name;
    string email_address;
    string cypher_passcode;
    string time_offset;
    string known_file;

    //editing the text from the file, allowing the user to enter the data

    infile >> "[firstname]";
    cout << infile << "[firstname]" << endl;

    cout << "Enter the information relating to you.\n";
    cout << "Enter your first name: ";
    cin >> first_name;
    infile >> "[firstname]";
    cout << infile << "[firstname]" << endl;

    cout << "Enter your last name: ";
    cin >> last_name;
    infile >> "[lastname]";
    cout << infile << "[lastname]" << endl;

    cout << "Enter your email address: ";
    cin >> email_address;
    infile >> "[email]";
    cout << infile << "[email]=" << endl;

    cout << "Enter your cypher: ";
    cin >> cypher_passcode;
    infile >> "[cypher]";
    cout << infile << "[cypher]=" << endl;

    cout << "Enter your time offset: ";
    cin >> time_offset;
    infile >> "[timeoffset]";
    cout << infile << "[timeoffset]=" << endl;

    cout << "Enter your known recipient file name:";
    cin >> known_file;
    infile >> "[knownfile]";
    cout << infile << "[knownfile]=";

    //Writing the name to the file
    infile << first_name << endl;
    infile << last_name << endl;
    infile << email_address << endl;
    infile << cypher_passcode << endl;
    infile << time_offset << endl;
    infile << known_file << endl;

    cout << "The information is saved to the file .\n";

    //closing file
    infile.close();

    return 0;
}