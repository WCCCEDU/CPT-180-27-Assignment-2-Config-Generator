#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;

const string FILE_PATH = "C:\\Users\\Samantha\\ClionProjects\\Assignment2-Config-Files\\Config.txt";

void init() {
    const int SIZE = 5;
    const string HEADERS[SIZE] = {"[Name]","[E-mail]","[Password]", "[Timezone Offset]", "[File Path]"};
    const string PROMPTS[SIZE] = {"Please enter your first and last name: ", "Please enter your email address: ", "Please enter"
      " your password: ", "Please enter a timezone offset: ", "Enter a file path for the config file: "};

    cout << "\nCONFIG FILE CREATION\n\n";
    string results[SIZE];

    // prompt for all questions that require input
    for(int i = 0; i < SIZE; i++) {
        cout << "\t" + PROMPTS[i];
        getline(cin, results[i]);
        while(results[i].length() == 0) {
            if(i == (SIZE - 1)){
                results[i] = FILE_PATH;
                cout << "\t( File path set to default location )";
            } else {
                cout << "You did not enter any input. Please try again.\n";
                cout << PROMPTS[i];
                cin >> results[i];
            }
        }
    }

    // create/open file and print headers and user input
    ofstream config(FILE_PATH);
    if(config) {
        for(int i = 0; i < SIZE; i++){
            config << HEADERS[i] + "\n\t" + results[i] + "\n";
        }
    }else{
        cout << "Error in file creation.";
    }

    // make sure to close the file!
    config.close();
    cout << "\n\tFile Created!";
}
void edit(string field) {
    const int SIZE = 5;

    cout << "\nCONFIG FILE EDIT\n\n";
    cout << "\tEnter a filepath, or press 'Enter' to open the default path: ";
    string path;
    getline(cin, path);
    if(path.length() == 0) {
        path = FILE_PATH;
    }

    // open file and store data for editing
    ifstream config;
    config.open(path);
    if(config){
        string text; string headers[SIZE]; string values[SIZE]; int i = 0;
        while(!config.eof()){
            getline(config, headers[i]);
            getline(config, values[i]);
            i++;
        }
        // file closes after it is finished reading input
        config.close();

        // prompt user to change given field
        cout << "\tEnter a new value for the " + field + " field: ";
        if(field == "name"){
            getline(cin, values[0]);
            values[0] = "\t" + values[0];
        } else if(field == "email"){
            getline(cin,values[1]);
            values[1] = "\t" + values[1];
        } else if(field == "password"){
            getline(cin, values[2]);
            values[2] = "\t" + values[2];
        } else if(field == "timezone"){
						getline(cin, values[3]);
            values[3] = "\t" + values[3];
        } else {
						getline(cin, values[4]);
            values[4] = "\t" + values[4];
        }
        ofstream config(path);
        for(i = 0; i < SIZE; i++){
            config << headers[i] << "\n" << values[i] << "\n";
        }
        cout << "\n\tFile Updated!";
        config.close();
    } else {
        cout << "Error in locating file.";
    }
}

int main(int argc, char *argv[]) {
    // initialize variables with given arguments
    string arg1 =  static_cast<string>(argv[1]);
    string arg2 = "";
    if(argc == 3){
        arg2 = static_cast<string>(argv[2]);
    }

    if(arg1 == "init"){
        init();
    }else if(arg1 == "edit"){
			if(arg2 == "name" || arg2 == "email" || arg2 == "password" || arg2 == "timezone" || arg2 == "filepath") {
					edit(arg2);
			} else {
				do{
					cout << "You did not enter the right argument. To edit a field, enter \"name\", \"email\", \"password\", "
						<< "\"timezone\", or \"filepath\": ";
					cin >> arg2;
				}while(arg2 != "name" && arg2 != "email" && arg2 != "password" && arg2 != "timezone" && arg2 != "filepath");
				edit(arg2);
			}
    } else {
			do {
				cout << "You did not provide valid arguments. Enter \"init\" to create a new config file or \"edit\""
									<< "to change an existing one: ";
				cin >> arg1;
			}while(arg1 != "init" && arg1 != "edit");
			if(arg1 == "init"){
				init();
			}else{
				cout << "Enter one of the following fields to edit its value: \"name\", \"email\", \"password\","
									<< "\"timezone\", \"filepath\"";
				cin >> arg2;
				while(arg2 != "name" && arg2 != "email" && arg2 != "password" && arg2 != "timezone" && arg2 != "filepath") {
					cout << "You did not enter an acceptable argument. Please enter one of the following: \"name\", \"email\","
									<< "\"password\", \"timezone\", \"filepath\"";
					cin >> arg2;
				}
			}
    }
    return 0;
}
