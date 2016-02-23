#include <iostream>
#include <fstream>

std::string name = "",email = "",passcode = "",time_zone = "",file_path = "";
 //input = std::cin , output = std::cout; Can this be done?
void users_name()
 {
     do {
         std::cout<< "Enter your Name:\n";
         getline (std::cin, name);
     } while (name == "");
 }
void email_address(){do {
        std::cout<< "Enter your Email:\n";
        getline (std::cin, email);
    } while (email == "");
}
void password(){do {
        std::cout<< "Enter a unique Passcode:\n";
        getline (std::cin, passcode);
    } while (passcode == "");}
void timezone()
{
    do {
        std::cout<< "Enter your Time Zone:\n";
        getline (std::cin, time_zone);
    } while (time_zone == "");
}
void create(){
    users_name();
    email_address();
    password();
    timezone();

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

void reconfigure(){
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
    std::cout << "Please enter 'create' to initialize config file or 'reconfigure' to edit the file:\n";
   if (static_cast<std::string>(argv[1]) == "create")
   {
       std::cout << "Prepping the creation of the Config File.\n";
       create();
   }
   else if (static_cast<std::string>(argv[1]) == "reconfigure")
   {
       std::cout << "Starting the Reconfiguration process.\n";
       reconfigure();
   }
    return 0;
    }