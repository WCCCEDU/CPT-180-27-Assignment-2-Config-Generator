#include <iostream>
#include <fstream>



using std::cin;
using std::cout;
using std::endl;
using std::string;

const string outfile = "/users/Brandon/Files_Coding_Assignment_2/config.txt";

int main(int argc, char *argv[]) {

    string argument = "";
    string  argument_choice, argument0, argument1, argument2;
    cout << "enter argument 0 to open file, enter 1 to output config file content, enter 2 to edit";
    if (argc != 0) {
        argument0 = static_cast<string>(argv[0]);
    }

    if (argument_choice == "1") {
        argument1 = static_cast<string>(argv[1]);
        cout << "you are now entering the init stage";
    }
    std::ofstream outfile;
    outfile.open("config.txt");

    string test_value;
    cout << "enter your first name:" << endl;
    std::getline(cin, test_value);

    //if the user entered something incorrect
    while (test_value == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your first name: " << endl;
        std::getline(cin, test_value);
    }
    std::outfile << "[firstname]=" << test_value << endl;
    test_value = "";

    cout << "enter your last name" << endl;
    getline(cin, test_value);
    while (test_value == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your last name: " << endl;
        std::getline(cin, test_value);
    }
    std::outfile << "[lastname]=" << test_value << endl;
    test_value = "";

    cout << "enter your email address" << endl;
    std::getline(cin, test_value);
    while (test_value == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your email address: " << endl;
        std::getline(cin, test_value);
    }
    std::outfile << "[email]=" << test_value << endl;
    test_value = "";

    cout << "please enter your unique cypher: " << endl;
    std::getline(cin, test_value);
    while (test_value == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your unique cypher: " << endl;
        std::getline(cin, test_value);
    }
    std::outfile << "[cypher]=" << test_value << endl;
    test_value = "";

    cout << "please enter your time offset: " << endl;
    std::getline(cin, test_value);
    while (test_value == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your time offset: " << endl;
        std::getline(cin, test_value);
    }
    std::outfile << "[timeoffset]=" << test_value << endl;
    test_value = "";

    cout << "please enter the known recipients file: " << endl;
    if (test_value == "") {
        outfile << "[knownfile] = knownrecipients.txt";
    } else {
        outfile << "[knownrecipient]=" << test_value << endl;
    }
    outfile.close();
}else{(argument2)
argument2 = static_cast<string>(argv[2]);
cout << "you are now entering the edit stage";

  return 0;
}