#include <iostream>
#include <fstream>


 //input = std::cin , output = std::cout; Can this be done?
void init(){

    std::string name = "",email = "",passcode = "",time_zone = "",file_path = "";
    do {
        std::cout<< "Enter your Name:\n";
        getline (std::cin, name);
    } while (name == "");

    do {
        std::cout<< "Enter your Email:\n";
        getline (std::cin, email);
    } while (email == "");


    do {
        std::cout<< "Enter a unique Passcode:\n";
        getline (std::cin, passcode);
    } while (passcode == "");


    do {
        std::cout<< "Enter your Time Zone:\n";
        getline (std::cin, time_zone);
    } while (time_zone == "");


     std::cout << "Enter path to Known Recipients file:\n";
    getline (std::cin, file_path);
    if (file_path == "") {
        file_path = "knownrecipients.txt";
    }

    std::ofstream init_outputf;
    init_outputf.open(file_path);

    init_outputf << name << '\n';
    init_outputf << email << '\n';
    init_outputf << passcode << '\n';
    init_outputf << time_zone << '\n';

    init_outputf.close();
}

void edit(){
    std::string edit_file_path, edit_name = "",edit_email = "",edit_passcode = "",edit_timezone = "";
    std::cout << "Enter path to Known Recipients file:\n";
    std::cin >> edit_file_path;

    std::ifstream edit_file_input;
    bool file_found = true;


    edit_file_input.open(edit_file_path);

    if (edit_file_input) {

        edit_file_input >> edit_name;
        std::cout << "The Name we have is " << edit_name<<'\n';

        edit_file_input >> edit_email;
        edit_file_input >> edit_passcode;
        edit_file_input >> edit_timezone;
        edit_file_input.close();
    }else{
        file_found = false;
        std::cout << "We are having a little problem\n";
    }

    if (file_found) {
        std::ofstream edit_output_file;
        edit_output_file.open(edit_file_path);

        do {
            std::cout << "Enter the new Name: \n";
            getline(std::cin, edit_name);
        }while (edit_name == "");

        edit_output_file << edit_name << '\n';
        edit_output_file << edit_email << '\n';
        edit_output_file << edit_passcode << '\n';
        edit_output_file << edit_timezone << '\n';

        edit_output_file.close();
    }else{
        std::cout << "Find correct file path before editing.\n";
    }
}

int main(int argc, char *argv[]) {

    char choice;
    std::cout << "Enter A to Create the config file or B to edit:\n";
    std::cin >> choice;

    switch (choice) {
        case 'A':
            init();
            break;

        case 'B':
            edit();
            break;

        default:
            std::cout << "You did not enter A or B !!.\n";
    }
    return 0;
}