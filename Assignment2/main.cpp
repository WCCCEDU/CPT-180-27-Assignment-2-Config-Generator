#include <iostream>
#include <fstream>




int main() {

    std::string menu = "";
    std::cout << "Enter init or edit" << std::endl;
    std::cin >> menu;
    std::cout << "Menu selected" << std::endl;
    if (menu == "edit") {

        std::string Username = "";
        std::cout << "Enter your name(first and last)" << std::endl;
        getline(std::cin, Username);

        std::string Email = "";
        std::cout << "Enter your Email address" << std::endl;
        getline(std::cin, Email);

        std::string Pass = "";
        std::cout << "Enter your password" << std::endl;
        getline(std::cin, Pass);

        std::string Timezone = "";
        std::cout << "Enter your timezone" << std::endl;
        getline(std::cin, Timezone);

        std::string Location = "knownrecipients.txt";
        std::ofstream textfile;
        textfile.open(Location);
        //if (textfile.is_open()){
        //    std::cout << "file is open" << std::endl;
        //}

        textfile << Username << std::endl;
        textfile << Email << std::endl;
        textfile << Pass << std::endl;
        textfile << Timezone << std::endl;
        textfile.close();
    }else if(menu == "init") {

        std::string Location = "knownrecipients.txt";
        std::string line = "";
        std::ifstream myfile(Location);
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                std::cout << line << std::endl;

            }
        }

        std::string saved_Username = "";
        std::string saved_Email = "";
        std::string saved_Pass = "";
        std::string saved_Timezone = "";

        std::string Username = "";
        do {
            std::cout << "Enter your name(first and last)" << std::endl;
            getline(std::cin, Username);
        }while (Username != saved_Username);

        std::string Email = "";
        do {
            std::cout << "Enter your Email address" << std::endl;
            getline(std::cin, Email);
        }while (Email != saved_Email);

        std::string Pass = "";
        do {
            std::cout << "Enter your password" << std::endl;
            getline(std::cin, Pass);
        }while (Pass != saved_Pass);

        std::string Timezone = "";
        do {
            std::cout << "Enter your timezone" << std::endl;
            getline(std::cin, Timezone);
        } while (Timezone != saved_Timezone);
    }else{
        std::cout << "Incorrect command" << std::endl;
    }


    return 0;
}