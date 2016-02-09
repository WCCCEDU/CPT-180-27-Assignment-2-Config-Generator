#include <iostream>
#include <fstream>



using std::cin;
using std::cout;
using std::endl;
using std::string;

const string CONFIG_FILE_PATH = "/users/outla/Documents/WCCC/Semester 4/CPT-180/Assignment2/app.cfg";
const string blank = "";


void init() {

    string name;
    do{ cout << "Please Enter Your Name (First and Last)" << endl;
    getline(cin, name);
    } while( name == blank);

    string email;
    do{
        cout << " Please Enter Your Email Address" << endl;
        getline(cin, email);
    }while( email == blank);

    string cypher;
    do{
        cout << "Please Enter Your Unique Cypher" << endl;
        getline(cin, cypher);
    }while(cypher == blank);

    string timezone_offset;
    do{
        cout << "Please Enter Your Timezone Offset" << endl;
        getline(cin, timezone_offset);
    }while(timezone_offset == blank);

    string file_path;
    do{
        cout << "Please Enter the Recipient's File Path " << endl;
        getline(cin, file_path);
    }while (file_path == blank);

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
    string name_edit = blank;
    string email_edit = blank;
    string cypher_edit = blank;
    string timezone_edit = blank;
    edited_file.open(edit_path);

    if (edited_file) {

        edited_file >> name_edit;
        edited_file >> email_edit;
        edited_file >> cypher_edit;
        edited_file >> timezone_edit;

        edited_file.close();
    } else{
          file= false;
        cout << "No File Found" << endl;
        }
    if(file){
        std::ofstream output_edited_file;
        output_edited_file.close();

        do{ cout << "Please Enter Your Name (First and Last)" << endl;
            getline(cin, name_edit);
        } while( name_edit == blank);

        output_edited_file << name_edit << endl;
        output_edited_file << email_edit << endl;
        output_edited_file << cypher_edit << endl;
        output_edited_file << timezone_edit << endl;

        output_edited_file.close();
    }else{
        cout << " PLease Find the Correct File Path" << endl;
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

