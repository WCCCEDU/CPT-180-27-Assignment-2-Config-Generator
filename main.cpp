#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::string;


/* this program will open a file and read the contents of the file. I will attempt to delimit
     * the info so the prompt and variables read will be displayed to the user and enable an edit if
     * they so wish. Once complete we will write the new info to the file and close with changes.*/



    const string FILE_PATH = "C:\\Users\\Owner\\Documents\\CPT-180-27-Assignment-2-Config-Generator\\config_file.txt";

    string first_name = "";
    string last_name = "";
    string email_add = "";
    string cypher = "";
    string time_zone_offset = "";
    string known_recipients_path = "";

    void init() {

        std::ifstream input_file;
        input_file.open(FILE_PATH);

        cout << "Please wait while that file is read for you:" << endl;

        input_file >> first_name, last_name, email_add, cypher, time_zone_offset, known_recipients_path;

        cout << "The information in the file is as listed:\n";
        cout << "First name is\n" << first_name;
        cout << "Last name is\n" << last_name;
        cout << "Email address is\n" << email_add;
        cout << "Cypher is\n" << cypher;
        cout << "Time zone offset is\n" << time_zone_offset;
        cout << "File directory to the knownrecipients file is\n" << known_recipients_path;

        input_file.close();
    }



    void edit() {

        std::ofstream output_file;
        output_file.open(FILE_PATH);

        string first_name_new = "";
        do {
            cout << "The name in record is " << first_name <<
            "if you wish to change please enter your first name: " << endl;
            getline(cin, first_name_new);
        } while (first_name_new != first_name);
        string last_name_new = "";
        do {
            cout << "The last name in record is " << last_name <<
            "if you wish to change please enter your last name: " << endl;
            getline(cin, last_name_new);
        } while (last_name_new != last_name);
        string email_add_new = "";
        do {
            cout << "The email address on record is " << email_add <<
            " is you wish to change please enter a valid email address: " << endl;
            getline(cin, email_add_new);
        } while (email_add_new != email_add);
        string cypher_new = "";
        do {
            cout << "The cypher on record is " << cypher <<
            "is you wish to change please enter a cypher for the program: " << endl;
            getline(cin, cypher_new);
        } while (cypher_new != cypher);
        string time_zone_offset_new = "";
        do {
            cout << "The time zone offset on record is " << time_zone_offset <<
            "if you wish to change please enter your time zone offset in #.## format: " << endl;
            std::cin, (time_zone_offset_new);
        } while (time_zone_offset_new != time_zone_offset);
        string known_recipients_path_new = "";
        do {
            cout << "The file directory on record is " << known_recipients_path <<
            "if you wish to change please enter the directory path to the file 'knownrecipients':" << endl;
            getline(cin, known_recipients_path_new);
        } while (known_recipients_path_new != known_recipients_path);




        output_file << first_name_new << endl;
        output_file << last_name_new << endl;
        output_file << email_add_new << endl;
        output_file << cypher << endl;
        output_file << time_zone_offset_new << endl;
        output_file << known_recipients_path_new << endl;

        output_file.close();

        cout << "Thank you for your time";
    }

    int main(int argc, char *argv[]) {

    cout << "Please enter 'start' to initialize the file or 'edit' to edit the file." << endl;

    if (static_cast <string>(argv[1]) == "start"){
        cout << "We will now initialize the file please wait for prompt." << endl;
        init();
    } else if (static_cast<string>(argv[2]) == "edit") {
        cout << "Please wait while we prepare the file to edit" << endl;
        edit();}
    }
