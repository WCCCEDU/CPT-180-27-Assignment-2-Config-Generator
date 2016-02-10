#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const string CONFIG_FILE_PATH = "/users/Clayton/documents/recipients.txt"
const string blank = "";

void init() {

    string name;
    do {
        std::cout << "Enter Your First Name and Last Name" << std::endl;
        getline(cin, name);
    } while (name == blank);

    string email;
    do {
        std::cout << "Enter Your Email Address" << std::endl;
        getline(cin, email);
    } while (email == blank);

    string cypher;
    do {
        std::cout << "Enter Your Cypher" << std::endl;
        getline(cin, cypher);
    } while (cypher == blank);

    string timezone_offset;
    do {
        std::cout << "Enter your Timezone Offset" << std::endl;
        getline(cin, timezone_offset);
    } while (timezone_offset == blank);

    string file_path;
    do {
        std::cout << "Enter Recipient's File Path" << std::endl;
        getline(cin, file_path);
    } while (file_path == blank);

    std::ofstream init_output_file;
    init_output_file.open(file_path);

    init_output_file << name << endl;
    init_output_file << email << endl;
    init_output_file << cypher << endl;
    init_output_file << timezone_offset << endl;
    init_output_file << file_path << endl;
    init_output_file.close();
}

void edit() {
    bool file = true;
    string edit_path;
    std::cout << "Enter Path For Recipient" << endl;
    cin >> edit_path;

    std::ifstream edited_file;
    string name_edit = blank;
    string email_edit = blank;
    string cypher_edit = blank;
    string timezone_offset_edit = blank;
    edited_file.open(edit_path);








}


