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

         std::ofstream outfile;
        outfile.open("config.txt");
     if (outfile.is_open())
        {
        outfile << "File successfully open";
        outfile.close();
        }
    else
    {
        cout << "Error opening file";
    }
        string first_name;
        cout << "enter your first name:" << endl;
        getline(cin, first_name);
         if (first_name == "") {
        cout << first_name << endl;
        }
        string last_name;
        cout << "enter your last name" << endl;
        getline(cin, last_name);
        while (last_name == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your last name: " << endl;
        getline(cin, last_name);
     }

        string email_address;
        cout << "enter your email address" << endl;
        getline(cin, email_address);
        while (last_name == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your email address: " << endl;
        getline(cin, email_address);
        }
        cout << "[email]=" << email_address << endl;

     string cypher_code;
        cout << "please enter your unique cypher: " << endl;
        std::getline(cin, cypher_code);
     while (cypher_code == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your unique cypher: " << endl;
        getline(cin, cypher_code);
        }
        outfile << "[cypher]=" << cypher_code << endl;
        cypher_code = "";

     string time_offset;
        cout << "please enter your time offset: " << endl;
        getline(cin, time_offset);
        while (time_offset == "") {
        cout << "I'm sorry, we have come across an error. Please re-enter your time offset: " << endl;
        getline(cin, time_offset);
     }
     outfile << "[timeoffset]=" << time_offset << endl;

        string known_recipients_file;
        cout << "please enter the known recipients file: " << endl;
     if (known_recipients_file == "") {
        outfile << "[knownfile] = knownrecipients.txt";
        } else {
        outfile << "[knownrecipient]=" << known_recipients_file << endl;
    }
    outfile.close();
    return 0;
}





