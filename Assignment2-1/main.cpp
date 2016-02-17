#include <iostream>
#include <fstream>
#include <limits>

using std::cout;
using std::cin;
using std::string;
using std::endl;



int main(int argc, char *argv[]) {

    //Asks the user what they want to do. create a config file or edit one
    //leaving Menu blank will ask the question again
    string Menu = "";
    do {
        cout << "Enter 'Create' to enter data, or 'Edit' to edit existing data" << endl;
        getline(cin, Menu);
    } while (Menu == "");

    // Asks the user to fill in each category for the config file
    if (Menu == "Create") {
        string Username = "";
        do {
            cout << "Enter your name(first and last)" << endl;
            getline(cin, Username);
        } while (Username == "");

        string Email = "";
        do {
            cout << "Enter your Email address" << endl;
            getline(cin, Email);
        } while (Email == "");

        string Pass = "";
        do {
            cout << "Enter your password" << endl;
            getline(cin, Pass);
        } while (Pass == "");

        string Timezone = "";
        do {
            cout << "Enter your timezone" << endl;
            getline(cin, Timezone);
        } while (Timezone == "");

        //Asks for a file location ***WIP*** (right now just names file)
        string Location = "";
        cout << "Enter file name (example 'document.txt') leave blank for default" << endl;
        getline(cin, Location);
        if (Location == "") {
            Location = "Config.txt";
        }

        //Saves the data to a text file named by "location"
        std::ofstream textfile;
        textfile.open(Location);

        textfile << "[Username]" << endl << Username << endl;
        textfile << "[Email]" << endl << Email << endl;
        textfile << "[Password]" << endl << Pass << endl;
        textfile << "[Timezone]" << endl << Timezone << endl;
        textfile.close();

    //typing Edit in the menu allows you to change data
    }else if (Menu == "Edit"){

        //asks for file name same as above
        string Location = "";
        cout << "Enter file name, leave blank for default" << endl;
        getline(cin, Location);
        if (Location == "") {
            Location = "Config.txt";
        }

        //retrieves data currently saved in file and prints for user
        string Saved_Username = "";
        string Saved_Email = "";
        string Saved_Password = "";
        string Saved_Timezone = "";
        string line;
        std::ifstream myfile(Location);
        while (!myfile.eof()) {
            for (int lineno = 0; getline(myfile, line) && lineno < 8; lineno++) {
                if (lineno == 1) {
                    Saved_Username = line;
                }
                if (lineno == 3){
                    Saved_Email = line;
                }
                if (lineno == 5){
                    Saved_Password = line;
                }
                if (lineno == 7){
                    Saved_Timezone = line;
                }
            }
        }
        cout << "Saved Username:   " << Saved_Username << endl;
        cout << "Saved Email:      " << Saved_Email << endl;
        cout << "Saved Password:   " << Saved_Password << endl;
        cout << "Saved Timezone:   " << Saved_Timezone << endl;
        myfile.close();

        std::ofstream textfile;
        textfile.open(Location);

        //asks user which variable to edit in the config file
        string Edit_Variable = "";
        do {
            cout << "Enter a variable to edit (Username, Email, Password, or Timezone" << endl;
            getline(cin, Edit_Variable);
        }while (Edit_Variable == "");

        //prompts the user to enter a new variable and replaces the old one in the text file.
        if (Edit_Variable == "Username") {
            string New_Username = "";
            do {
                cout << "Enter new Username" << endl;
                getline(cin, New_Username);
            } while (New_Username == "");
            textfile << "[Username]" << endl << New_Username << endl;
            textfile << "[Email]" << endl << Saved_Email << endl;
            textfile << "[Password]" << endl << Saved_Password << endl;
            textfile << "[Timezone]" << endl << Saved_Timezone << endl;
            textfile.close();
            cout << "Edits Complete" << endl;

        }else if (Edit_Variable == "Email"){
            string New_Email = "";
            do {
                cout << "Enter new Email" << endl;
                getline(cin, New_Email);
            } while (New_Email == "");
            textfile << "[Username]" << endl << Saved_Username << endl;
            textfile << "[Email]" << endl << New_Email << endl;
            textfile << "[Password]" << endl << Saved_Password << endl;
            textfile << "[Timezone]" << endl << Saved_Timezone << endl;
            textfile.close();
            cout << "Edits Complete" << endl;

        }else if (Edit_Variable == "Password"){
            string New_Password = "";
            do {
                cout << "Enter new Password" << endl;
                getline(cin, New_Password);
            } while (New_Password == "");
            textfile << "[Username]" << endl << Saved_Username << endl;
            textfile << "[Email]" << endl << Saved_Email << endl;
            textfile << "[Password]" << endl << New_Password << endl;
            textfile << "[Timezone]" << endl << Saved_Timezone << endl;
            textfile.close();
            cout << "Edits Complete" << endl;
        }else if (Edit_Variable == "Timezone"){
            string New_Timezone = "";
            do {
                cout << "Enter new Timezone" << endl;
                getline(cin, New_Timezone);
            } while (New_Timezone == "");
            textfile << "[Username]" << endl << Saved_Username << endl;
            textfile << "[Email]" << endl << Saved_Email << endl;
            textfile << "[Password]" << endl << Saved_Password << endl;
            textfile << "[Timezone]" << endl << New_Timezone << endl;
            textfile.close();
            cout << "Edits Complete" << endl;
        }else{
            cout << "Unknown Input";
        }
        //Reads and displays the new data ***WIP***
        //(for some reason does not read changes and displays information from before the edit)
        while (!myfile.eof()) {
            for (int lineno = 0; getline(myfile, line) && lineno < 8; lineno++) {
                if (lineno == 1) {
                    Saved_Username = line;
                }
                if (lineno == 3){
                    Saved_Email = line;
                }
                if (lineno == 5){
                    Saved_Password = line;
                }
                if (lineno == 7){
                    Saved_Timezone = line;
                }
            }
        }
        cout << "Saved Username:     " << Saved_Username << endl;
        cout << "Saved Email:        " << Saved_Email << endl;
        cout << "Saved Password:     " << Saved_Password << endl;
        cout << "Saved Timezone:     " << Saved_Timezone << endl;
        myfile.close();

    }



    return 0;
}
