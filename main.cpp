#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {

       // this is the initial input portion of the program.

    string fname = "";
    do {
        cout << "Please enter your first name:" << endl;
        getline (cin, fname);
    } while (fname == "");

    string lname = "";
    do {
        cout << "Please enter your last name:" << endl;
        getline (cin, lname);
    } while (lname == "");

    string email = "";
    do {
        cout << "Please enter your email address:" << endl;
        getline (cin, email);
    } while (email == "");

    string password = "";
    do {
        cout << "Please enter a unique password:" << endl;
        getline (cin, password);
    } while (password == "");

    string time_zone_offset = "";
    do {
        cout << "Please enter your Time Zone offset:" << endl;
        getline (cin, time_zone_offset);
    } while (time_zone_offset == "");


    string file_location = "";
    cout << "Enter path to config_file:" << endl;
    getline (cin, file_location);
    if (file_location == "") {
        file_location = "config_file.txt";
    }


    // Get the name of the file to be opened.

    std::ofstream outputFile;

    // Open the file.

    outputFile.open("c:\\users\\owner\\documents\\cp_repo\\config_file.txt");

    // Write the information to the file location.

    outputFile << fname;
    outputFile << lname;
    outputFile << email;
    outputFile << password;
    outputFile << time_zone_offset;

    // Close the file.

    outputFile.close();
    cout << "Complete.\n";

    return 0;
}