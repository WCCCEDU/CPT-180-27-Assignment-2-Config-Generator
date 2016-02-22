#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    string name = "";
    string email = "";
    string cypher = "";
    string timezone_offset = "";
    string file_path = "";


    if(static_cast<string>(argv[1]) == "init")
    {
        while (name == "")
        {
            cout << "Enter first and last name: ";
            getline(cin, name);
        }
        while (email == "" )
        {
            cout << "Enter e-mail address: ";
            getline(cin, email);
        }

        while (cypher == "")
        {
            cout << "Enter cypher: ";
            getline(cin, cypher);
        }

        while (timezone_offset == "")
        {
            cout << "Enter timezone offset: ";
            getline(cin, timezone_offset);
        }

        cout << "Enter path to known recipients file: ";
        getline(cin, file_path);

        if (file_path == "")
        {
            file_path = "knownrecipients.txt";
        }

        cout << file_path << endl;
    }
    else if (static_cast<string>(argv[1]) == "edit")
    {
        //DO stuff here
        ;
    }
    else
        cout << "Please pass a command as an argument (init or edit)" << endl;

    return 0;
}