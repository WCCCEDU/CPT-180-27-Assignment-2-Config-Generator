#include <iostream>
#include <fstream>

// Location of config txt file
const std::string DEFAULT_FILE_PATH = "/Users/naomibrown/assignments/Assignment2/MyConfigFile.txt";

int main(int argc, char *argv[]) {
    // Before doing any processing, check to see if there are sufficient arguments entered

    if(argc<2){
        std::cout << "You must enter at least one argument to run this program.\n";
        return -1;
    }

    // Declare/initialize variables used in IF and ELSE IF statements
    std::string firstName = "";
    std::string lastName = "";
    std::string emailAddress = "";
    std::string password = "";
    std::string timezoneOffset = "";
    std::string knownrecipientsFilePath = "";

    // Process information based on user entry (init or edit)

    // Initialize mode
    if (static_cast<std::string>(argv[1]) == "init") {

        // Get first name
        do {
            std::cout << "Please enter your first name: "<<std::endl;
            std::getline(std::cin, firstName);
        } while (firstName == "");

        // Get last name
        do {
            std::cout << "Please enter your last name: "<<std::endl;
            std::getline(std::cin,lastName);
        } while (lastName == "");

        // Get email address
        do {
            std::cout << "Please enter your e-mail address: "<<std::endl;
            std::getline(std::cin,emailAddress);
        } while (emailAddress == "");

        // Get password
        do {
            std::cout << "Please enter your password: "<<std::endl;
            std::getline(std::cin,password);
        } while (password == "");

        // Get time zone offset
        do {
            std::cout << "Please enter your time zone offset: "<<std::endl;
            std::getline(std::cin,timezoneOffset);
        } while (timezoneOffset == "");

        // Get knownrecipients file path
        std::cout <<"Please enter file path for knownrecipients file (If no file path is entered, a default file path "
                "will be set): "<<std::endl;
            std::getline(std::cin,knownrecipientsFilePath);
            if (knownrecipientsFilePath == "") {
                knownrecipientsFilePath = DEFAULT_FILE_PATH;
            }

        // Open and Write initialize data to file
        std::ofstream outputFile;

        outputFile.open(knownrecipientsFilePath);

        std::cout << "Writing initialize data to file.\n";
        outputFile << firstName << std::endl;
        outputFile << lastName << std::endl;
        outputFile << emailAddress << std::endl;
        outputFile << password << std::endl;
        outputFile << timezoneOffset << std::endl;
        outputFile << knownrecipientsFilePath << std::endl;

        // Close the open file
        outputFile.close();
    }

    else if (static_cast<std::string>(argv[1]) == "edit") {
        // Edit mode
        std::string editField = static_cast<std::string>(argv[2]);
        int editFieldNum = 0;

        if (editField == "firstName") {
            editFieldNum = 1;
        }
        if (editField == "lastName") {
            editFieldNum = 2;
        }
        if (editField == "emailAddress") {
            editFieldNum = 3;
        }
        if (editField == "password") {
            editFieldNum = 4;
        }
        if (editField == "timezoneOffset") {
            editFieldNum = 5;
        }
        if (editField == "knownrecipientsFilePath") {
        editFieldNum = 6;
        }
        // Open config file and read contents

        std::ifstream inputFile;
        inputFile.open(knownrecipientsFilePath);
        inputFile >> firstName;
        inputFile >> lastName;
        inputFile >> emailAddress;
        inputFile >> password;
        inputFile >> timezoneOffset;
        inputFile >> knownrecipientsFilePath;
        inputFile.close();

        switch (editFieldNum) {
            case 1: // firstName
                do {
                    std::cout << "First Name field is currently set to " << firstName << std::endl;
                    std::cout<<"Please enter NEW first name: "<<std::endl;
                    std::getline(std::cin, firstName);
                } while (firstName == "");
                break;

            case 2: // lastName
                do {
                    std::cout << "Last Name field is currently set to " << lastName << std::endl;
                    std::cout<<"Please enter NEW last name: "<<std::endl;
                    std::getline(std::cin, lastName);
                } while (lastName == "");
                break;

            case 3: // emailAddress
                do {
                    std::cout << "Email Address field is currently set to " << emailAddress << std::endl;
                    std::cout<<"Please enter NEW email address: "<<std::endl;
                    std::getline(std::cin, emailAddress);
                } while (emailAddress == "");
                break;

            case 4: // password
                do {
                    std::cout << "Password field is currently set to " << password << std::endl;
                    std::cout<<"Please enter NEW password: "<<std::endl;
                    std::getline(std::cin, password);
                } while (password == "");
                break;

            case 5: // timezoneOffset
                do {
                    std::cout << "Time Zone Offset field is currently set to " << timezoneOffset << std::endl;
                    std::cout<<"Please enter NEW time zone offset: "<<std::endl;
                    std::getline(std::cin, timezoneOffset);
                } while (timezoneOffset == "");
                break;

            case 6: // knownrecipientsFilePath
                std::cout << "File path field is currently set to " << knownrecipientsFilePath << std::endl;
                std::cout<<"Please enter NEW file path (If no file path is entered, a default file path"
                        "will be set): "<<std::endl;

                if (knownrecipientsFilePath == "") {
                    knownrecipientsFilePath = DEFAULT_FILE_PATH;
                    std::getline(std::cin, knownrecipientsFilePath);
                }

                break;
        }
        // Write data back to config file (changed or unchanged)

        std::ofstream outputFile;

        outputFile.open(knownrecipientsFilePath);

        std::cout << "Writing edited data to file.\n";
        outputFile << firstName << std::endl;
        outputFile << lastName << std::endl;
        outputFile << emailAddress << std::endl;
        outputFile << password << std::endl;
        outputFile << timezoneOffset << std::endl;
        outputFile << knownrecipientsFilePath << std::endl;

        // Close the open file
        outputFile.close();
    }

    return 0;
}