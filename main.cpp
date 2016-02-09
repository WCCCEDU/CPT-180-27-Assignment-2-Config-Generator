#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void init() {

    string known_recipient_location = "";
    cout << "Please enter known recipient file path." << endl;
    cin >> known_recipient_location;
    if (known_recipient_location == "") {
        known_recipient_location == "recipientfile.txt";
    }
    cin.ignore();

    std::ofstream output_file_init;
    output_file_init.open (known_recipient_location);

    string full_name = "";
    cout << "Please enter full name." << endl;
    getline(cin, full_name);
    while (full_name == "") {
        cout << "Invalid entry. Please enter full name." << endl;
        getline(cin, full_name);
    }

    string email = "";
    cout << "Enter your email address." << endl;
    getline(cin, email);
    while (email == "") {
        cout << "Invalid entry! Please enter email address." << endl;
        getline(cin, email);
    }

    string cypher = "";
    cout << "Please enter password." << endl;
    getline(cin, cypher);
    while (cypher == "") {
        cout << "Invalid entry. Please enter password.";
        getline(cin, cypher);
    }

    int time_zone_offset;
    cout << "Enter time zone offset." << endl;
    cin >> time_zone_offset;
    if (time_zone_offset == 0) {
        time_zone_offset = 5;
    }

    output_file_init << full_name << endl;
    output_file_init << email << endl;
    output_file_init << cypher << endl;
    output_file_init << time_zone_offset << endl;

    output_file_init.close();
}

void edit() {

    string known_recipient_edit = "";
    cout << "Enter known recipient location." << endl;
    cin >> known_recipient_edit;
    cin.ignore();

    std::ifstream input_file;
    input_file.open(known_recipient_edit);

    string full_name_edit = "";
    input_file >> full_name_edit;

    string email_edit;
    input_file >> email_edit;

    string cypher_edit;
    input_file >> cypher_edit;

    int time_zone_edit;
    input_file >> time_zone_edit;

    input_file.close();

    string new_name = "";
    cout << "Enter new name." << endl;
    getline(cin, new_name);
    while (new_name == "" or new_name == full_name_edit) {
        cout << "Invalid Entry. Please enter a new name." << endl;
        getline(cin, new_name);
    }

    std::ofstream output_file_edit;
    output_file_edit.open(known_recipient_edit);

    output_file_edit << new_name << endl;
    output_file_edit << email_edit << endl;
    output_file_edit << cypher_edit << endl;
    output_file_edit << time_zone_edit << endl;

    output_file_edit.close();
}

int main(int argc, char * argv[]) {

    int selection;
    cout << "Enter 1 to initialize file, or enter 2 to edit the file." << endl;
    cin >> selection;

    switch (selection) {
        case 1:
            init();
            break;

        case 2:
            edit();
            break;

        default:
            cout << "Invalid number." << endl;

    }

    return 0;
}