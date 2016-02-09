#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::ofstream;

void init() {
    const string FILE_PATH = "C:\\Users\\Samantha\\ClionProjects\\Assignment2-Config-Files\\Config.txt";
    const int SIZE = 5;
    const string PROMPTS[SIZE] = {"Please enter your first and last name: ", "Please enter your email address: ", "Please enter"
      " your password: ", "Please enter a timezone offset: ", "Enter a file path for the config file: "};
    const string HEADERS[SIZE] = {"[Name]","[E-mail]","[Password]", "[Timezone Offset]", "[File Path]"};

    cout << "\nCONFIG FILE CREATION\n\n";
    string results[SIZE];

    // prompt for all questions that require input
    for(int i = 0; i < SIZE; i++) {
        cout << "\t" + PROMPTS[i];
        getline(cin, results[i]);
        while(results[i].length() == 0) {
            if(i == (SIZE - 1)){
                results[i] = FILE_PATH;
                cout << "\t* File path set to default location *";
            } else {
                cout << "You did not enter any input. Please try again.\n";
                cout << PROMPTS[i];
                cin >> results[i];
            }
        }
    }

    // create/open file and print headers and user input
    ofstream config;
    config.open(FILE_PATH);
    if(config) {
        for(int i = 0; i < SIZE; i++){
            config << HEADERS[i] + "\n\t" + results[i] + "\n";
        }
    }

    // make sure to close the file!
    config.close();
}
void edit() {
    cout << "EDIT";
}

int main(int argc, char *argv[]) {
    if(static_cast<string>(argv[1]) == "init"){
        init();

    } else if (static_cast<string>(argv[1]) == "edit"){
        edit();
    } else {
        cout << "Sorry, you did not provide a valid argument";
    }
    return 0;
}
