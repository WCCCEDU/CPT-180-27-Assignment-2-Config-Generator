#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

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

        ofstream init_output;
        init_output.open (file_path);

        init_output << name << endl;
        init_output << email << endl;
        init_output << cypher << endl;
        init_output << timezone_offset << endl;
        init_output << file_path << endl;

        init_output.close();
    }
    else if (static_cast<string>(argv[1]) == "edit")
    {

        ifstream init_output;
        init_output.open(file_path);

        init_output >> name;

        init_output >> email;
        string temp_email = email;

        init_output >> cypher;
        string temp_cypher = cypher;

        init_output >> timezone_offset;
        string temp_timezone = timezone_offset;

        init_output >> file_path;
        string temp_file_path = file_path;

        string new_name;
        cout << "Enter a new name: " <<endl;
        getline(cin, new_name);

        init_output.close();


        ofstream edit_output;
        edit_output.open(file_path);

        edit_output << new_name << endl;
        edit_output << temp_email << endl;
        edit_output << temp_cypher << endl;
        edit_output << temp_timezone << endl;
        edit_output << temp_file_path << endl;


        edit_output.close();
    }
    else
        cout << "Please pass a command as an argument (init or edit)" << endl;

    return 0;
