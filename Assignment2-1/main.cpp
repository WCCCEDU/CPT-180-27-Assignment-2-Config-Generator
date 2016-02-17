#include <iostream>
#include <fstream>
#include <limits>

using std::cout;
using std::cin;
using std::string;
using std::endl;



int main(int argc, char *argv[]) {

    string Menu = "";
    do {
        cout << "Enter CREATE to enter data, or EDIT to edit existing data" << endl;
        getline(cin, Menu);
    } while (Menu == "");

    if (Menu == "CREATE") {
        std::string Username = "";
        do {
            std::cout << "Enter your name(first and last)" << std::endl;
            getline(std::cin, Username);
        } while (Username == "");

        std::string Email = "";
        do {
            std::cout << "Enter your Email address" << std::endl;
            getline(std::cin, Email);
        } while (Email == "");

        std::string Pass = "";
        do {
            std::cout << "Enter your password" << std::endl;
            getline(std::cin, Pass);
        } while (Pass == "");

        std::string Timezone = "";
        do {
            std::cout << "Enter your timezone" << std::endl;
            getline(std::cin, Timezone);
        } while (Timezone == "");

        string Location = "";
        std::cout << "Enter file location, leave blank for default" << std::endl;
        getline(std::cin, Location);
        if (Location == "") {
            Location = "knownrecipients";
        }

        std::ofstream textfile;
        textfile.open(Location);

        textfile << "[Username]" << std::endl << Username << std::endl;
        textfile << "[Email]" << std::endl << Email << std::endl;
        textfile << "[Password]" << std::endl << Pass << std::endl;
        textfile << "[Timezone]" << std::endl << Timezone << std::endl;
        textfile.close();

    }else if (Menu == "EDIT"){

        string Location = "";
        std::cout << "Enter file location, leave blank for default" << std::endl;
        getline(std::cin, Location);
        if (Location == "") {
            Location = "knownrecipients";
        }

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

        string Edit_Variable = "";
        do {
            cout << "Enter a variable to edit (Username, Email, Password, or Timezone" << endl;
            getline(std::cin, Edit_Variable);
        }while (Edit_Variable == "");

        if (Edit_Variable == "Username") {
            std::string New_Username = "";
            do {
                std::cout << "Enter new Username" << std::endl;
                getline(std::cin, New_Username);
            } while (New_Username == "");
            textfile << "[Username]" << std::endl << New_Username << std::endl;
            textfile << "[Email]" << std::endl << Saved_Email << std::endl;
            textfile << "[Password]" << std::endl << Saved_Password << std::endl;
            textfile << "[Timezone]" << std::endl << Saved_Timezone << std::endl;
            textfile.close();
            cout << "Edits Complete" << endl;

        }else if (Edit_Variable == "Email"){
            std::string New_Email = "";
            do {
                std::cout << "Enter new Email" << std::endl;
                getline(std::cin, New_Email);
            } while (New_Email == "");
            textfile << "[Username]" << std::endl << Saved_Username << std::endl;
            textfile << "[Email]" << std::endl << New_Email << std::endl;
            textfile << "[Password]" << std::endl << Saved_Password << std::endl;
            textfile << "[Timezone]" << std::endl << Saved_Timezone << std::endl;
            textfile.close();
            cout << "Edits Complete" << endl;

        }else if (Edit_Variable == "Password"){
            std::string New_Password = "";
            do {
                std::cout << "Enter new Password" << std::endl;
                getline(std::cin, New_Password);
            } while (New_Password == "");
            textfile << "[Username]" << std::endl << Saved_Username << std::endl;
            textfile << "[Email]" << std::endl << Saved_Email << std::endl;
            textfile << "[Password]" << std::endl << New_Password << std::endl;
            textfile << "[Timezone]" << std::endl << Saved_Timezone << std::endl;
            textfile.close();
            cout << "Edits Complete" << endl;
        }else if (Edit_Variable == "Timezone"){
            std::string New_Timezone = "";
            do {
                std::cout << "Enter new Timezone" << std::endl;
                getline(std::cin, New_Timezone);
            } while (New_Timezone == "");
            textfile << "[Username]" << std::endl << Saved_Username << std::endl;
            textfile << "[Email]" << std::endl << Saved_Email << std::endl;
            textfile << "[Password]" << std::endl << Saved_Password << std::endl;
            textfile << "[Timezone]" << std::endl << New_Timezone << std::endl;
            textfile.close();
            cout << "Edits Complete" << endl;
        }else{
            cout << "Unknown Input";
        }
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

    }



    return 0;
}
