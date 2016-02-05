#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void init(){
    string first_name = "";
    do {
        cout << "Enter your first name:" << endl;
        getline (cin, first_name);
    } while (first_name == "");

    string last_name = "";
    do {
        cout << "Enter your last name:" << endl;
        getline (cin, last_name);
    } while (last_name == "");

    string email_address = "";
    do {
        cout << "Enter your email address:" << endl;
        getline (cin, email_address);
    } while (email_address == "");

    string cypher = "";
    do {
        cout << "Enter a unique cypher:" << endl;
        getline (cin, cypher);
    } while (cypher == "");

    string time_offset = "";
    do {
        cout << "Enter your Time Zone offset:" << endl;
        getline (cin, time_offset);
    } while (time_offset == "");

    string file_path = "";
    cout << "Enter path to knownrecipients file:" << endl;
    getline (cin, file_path);
    if (file_path == "") {
        file_path = "knownrecipients.txt";
    }

    std::ofstream output_file_init;
    output_file_init.open(file_path);

    output_file_init << first_name << endl;
    output_file_init << last_name << endl;
    output_file_init << email_address << endl;
    output_file_init << cypher << endl;
    output_file_init << time_offset << endl;

    output_file_init.close();
}

void edit(){
    string file_path_edit;
    cout << "Enter path to knownrecipients file:" << endl;
    cin >> file_path_edit;

    std::ifstream input_file_edit;
    bool file_found = true;
    string first_name_edit = "";
    string last_name_edit = "";
    string email_address_edit = "";
    string cypher_edit = "";
    string time_offset_edit = "";
    input_file_edit.open(file_path_edit);

    if (input_file_edit) {

        input_file_edit >> first_name_edit;
        input_file_edit >> last_name_edit;
        cout << "The current name in the file is: " << first_name_edit << " " << last_name_edit << endl;

        input_file_edit >> email_address_edit;
        input_file_edit >> cypher_edit;
        input_file_edit >> time_offset_edit;
        input_file_edit.close();
    }else{
        file_found = false;
        cout << "Error opening file." << endl;
    }

    if (file_found) {
        std::ofstream output_file_edit;
        output_file_edit.open(file_path_edit);

        do {
            cout << "Enter the new first name:" << endl;
            getline(cin, first_name_edit);
        }while (first_name_edit == "");

        do {
            cout << "Enter the new last name:" << endl;
            getline(cin, last_name_edit);
        }while (last_name_edit == "");

        output_file_edit << first_name_edit << endl;
        output_file_edit << last_name_edit << endl;
        output_file_edit << email_address_edit << endl;
        output_file_edit << cypher_edit << endl;
        output_file_edit << time_offset_edit << endl;

        output_file_edit.close();
    }else{
        cout << "Find correct file path before editing." << endl;
    }
}

int main(int argc, char *argv[]) {

    int choice;
    cout << "Enter 1 to initialize config file or 2 to edit:" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            init();
            break;

        case 2:
            edit();
            break;

        default:
            cout << "You did not enter a valid number." << endl;
    }
    return 0;
}