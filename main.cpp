// Read data from config file

#include <stdio.h>
#include <iostream>
#include <fstream>

const std::string CONFIG_FILE_PATH = "C:\\Users\\naomibrown\\assignments\\Assignment2\\MyConfigFile.txt";
int main(int argc, char *argv[]) {

    // Choose init or edit
    std::int entryMode = "";
    do{
        std::cout<<"Please enter your start-up mode - 1 for initialize or 2 and field name for edit: ";
        getline(std::cin,entryMode);
    } while (entryMode=="");

        switch (entryMode){

            case 1: // Initialize
                std:: ifstream inputFile;

                inputFile.open("MyConfigFile.txt");
                std:: cout << "Reading data from the config file.\n";

                // Get first name
                std::string firstName = "";
                do{
                    std::cout<<"Please enter your first name: ";
                    getline(std::cin,firstName);
                } while (firstName=="");

                // Get last name
                std::string lastName = "";
                do{
                    std::cout<<"Please enter your last name: ";
                    getline(std::cin,lastName);
                } while(lastName=="");

                // Get email address
                std::string emailAddress = "";
                do{
                    std::cout<<"Please enter your e-mail address: ";
                    getline(std::cin,emailAddress);
                } while(emailAddress=="");

                // Get password
                std::string password = "";
                do{
                    std::cout<<"Please enter your password: ";
                    getline(std::cin,password);
                } while(password=="");

                // Get time zone offset
                std::string timezoneOffset = "";
                do{
                    std::cout<<"Please enter your time zone offset: ";
                    getline(std::cin,timezoneOffset);
                } while(timezoneOffset=="");

                // Get knownrecipients file path
                std::string knownrecipientsFilePath = "";
                std::cout<<"Please enter the file path for your knownrecipients file: ";
                getline(std::cin,knownrecipientsFilePath);

                inputFile.close()
                break;

            case 2: // Edit field

                std::string editField;
                editField = static_cast<std::string>(argv[2]);

                switch (editField){
                    case "firstName":
                        do{
                            std::cout<<"First Name field is currently set to"[firstName]
                                    "Please enter NEW first name: ";
                            std::cin,firstName;
                        } while(firstName=="");

                    case "lastName":
                        do{
                            std::cout<<"Last Name field is currently set to"[lastName]
                            "Please enter NEW last name: ";
                            std::cin,lastName;
                        } while(lastName=="");

                    case "emailAddress":
                        do{
                            std::cout<<"Email Address field is currently set to"[emailAddress]
                            "Please enter NEW email address: ";
                            std::cin,emailAddress;
                        } while(emailAddress=="");

                    case "password":
                        do{
                            std::cout<<"Password field is currently set to"[password]
                            "Please enter NEW password: ";
                            std::cin,password;
                        } while(password=="");

                    case "timezoneOffset":
                        do{
                            std::cout<<"Time Zone Offset field is currently set to"[timezoneOffset]
                            "Please enter NEW time zone offset: ";
                            std::cin,timezoneOffset;
                        } while(timezoneOffset=="");

                    case "knownrecipientsFilePath":
                        std::cout<<"File path field is currently set to"[knownrecipientsFilePath]
                            "Please enter NEW file path: ";
                        std::cin,knownrecipientsFilePath;

                        if(knownrecipientsFilePath == "")
                            char * dir = getcwd(NULL,0)
                            knownrecipientsFilePath = dir);

                        break;
                }
        }
return 0;
}