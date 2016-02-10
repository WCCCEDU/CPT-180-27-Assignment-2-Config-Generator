#include <iostream>
#include <fstream>



using std::cin;
using std::cout;
using std::endl;
using std::string;

const string CONFIG_FILE_PATH = "/users/outla/Documents/WCCC/Semester 4/CPT-180/Assignment2/app.cfg";
const string BLANK = "";


void init() {

    string name;
    if(name == BLANK){
        cout << "Please Enter Your Name (First and Last)" << endl;
        getline(cin, name);
    }else{
        cout << "You Must Enter a Name" << endl;
    }

    string email;
    if(email == BLANK){
        cout << " Please Enter Your Email Address" << endl;
        getline(cin, email);
    }else{
        cout << "You Must Enter an Email Address" << endl;
    }

    string cypher;
    if(cypher == BLANK){
        cout << "Please Enter Your Unique Cypher" << endl;
        getline(cin, cypher);
    }else{
        cout << "You Must Enter a Cypher" << endl;
    }

    string timezone_offset;
    if(timezone_offset == BLANK){
        cout << "Please Enter Your Timezone Offset)" << endl;
        getline(cin, timezone_offset);
    }else{
        cout << "You Must Enter an Offset" << endl;
    }

    string file_path;
    if(file_path == BLANK){
        cout << "Please Enter the Recipient's File Path" << endl;
        getline(cin, file_path);
    }else{
        cout << "You Must Enter a File Path" << endl;
    }


    std::ofstream init_output_file;
    init_output_file.open(file_path);

    init_output_file << name << endl;
    init_output_file << email << endl;
    init_output_file << cypher << endl;
    init_output_file << timezone_offset << endl;
    init_output_file << file_path << endl;
    init_output_file.close();
    }

void edit(){
    bool file = true;
    string edit_path;
    cout << "Enter Path for the Recipient" << endl;
    cin >> edit_path;


    std::ifstream edited_file;
    string name_edit = BLANK;
    string email_edit = BLANK;
    string cypher_edit = BLANK;
    string timezone_edit = BLANK;
    edited_file.open(edit_path);

    if (edited_file) {

        edited_file >> name_edit;
        edited_file >> email_edit;
        edited_file >> cypher_edit;
        edited_file >> timezone_edit;

        if(name_edit == BLANK){
            cout << "Please Enter Your Name (First and Last)" << endl;
            getline(cin, name_edit);
        }else{
            cout << "You Must Enter a Name" << endl;
        }

        if(email_edit == BLANK){
            cout << " Please Enter Your Email Address" << endl;
            getline(cin, email_edit);
        }else{
            cout << "You Must Enter an Email Address" << endl;
        }

        if(cypher_edit == BLANK){
            cout << "Please Enter Your Unique Cypher" << endl;
            getline(cin, cypher_edit);
        }else{
            cout << "You Must Enter a Cypher" << endl;
        }

        if(timezone_edit == BLANK){
            cout << "Please Enter Your Timezone Offset)" << endl;
            getline(cin, timezone_edit);
        }else{
            cout << "You Must Enter an Offset" << endl;
        }
        edited_file.close();

    } else{
          file= false;
        cout << "No File Found" << endl;
        }
    if(file){
        std::ofstream output_edited_file;
        output_edited_file.close();

        output_edited_file << name_edit << endl;
        output_edited_file << email_edit << endl;
        output_edited_file << cypher_edit << endl;
        output_edited_file << timezone_edit << endl;

        output_edited_file.close();
    }else{
        cout << " Please Find the Correct File Path" << endl;
    }
    }



int main(int argc, char *argv[]) {

    int option;
    cout << "Please Enter Option" << endl;
    cout << "1. Load File" << endl;
    cout << "2. Edit File" << endl;
    if (option == 1){
        init();
    } else if(option == 2){
        edit();
    }else if( option > 2 or option < 1){
        cout << "Please Enter 1 or 2" << endl;
    }
    return 0;
}

