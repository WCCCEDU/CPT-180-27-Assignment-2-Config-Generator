#include <iostream>
#include <fstream>
#include <string>

const std::string CONFIG = "C:/Users/Tim/ClionProjects/Assignment_2_File_Generator/config.txt";
const std::string EDIT = "C:/Users/Tim/ClionProjects/Assignment_2_File_Generator/edit.txt";

int main(int argc, char *argv[])
{
    std::cout << "Please type either init or edit to continue" << std::endl;
    if (static_cast<std::string>(argv[1]) == "init")

    {
    std::ofstream myfile;
    myfile.open(CONFIG);

    std::string first_and_last = "", email = "", cypher = "", timezone;

    std::cout << "Enter your first and last name, please" << std::endl;
    std::getline(std::cin, first_and_last);

    while (first_and_last == "")
    {
        std::cout << "Please enter your first and last name to continue" << std::endl;
        std::getline(std::cin, first_and_last);
    }
    myfile << first_and_last << std::endl;

    std::cout << "Enter your email address, please" << std::endl;
    std::getline(std::cin, email);

    while (email == "")
    {
        std::cout << "Please enter your email to continue" << std::endl;
        std::getline(std::cin, email);
    }
    myfile << email << std::endl;

    std::cout << "Enter your unique cypher, please" << std::endl;
    std::getline(std::cin, cypher);

    while (cypher == "")
    {
        std::cout << "Please enter your unique cypher to continue" << std::endl;
        std::getline(std::cin, cypher);
    }
    myfile << cypher << std::endl;

    std::cout << "Enter your timezone offset, please" << std::endl;
    std::getline(std::cin, timezone);


    while (timezone == "")
    {
        std::cout << "Please enter your timezone to continue" << std::endl;
        std::getline(std::cin, timezone);
    }
    myfile << timezone << std::endl;



    myfile.close();

    }
    else if (static_cast<std::string>(argv[2])= "edit")
    // Get Value from Config, and Edit
    {



        std::ifstream myfile;
        myfile.open(CONFIG);

        myfile << first_and_last << email << cypher << timezone << path << std::endl;

        myfile.close();

        std::string path = "";
        std::cout << "Enter path to knownrecipients file, please" << std::endl;
        std::getline(std::cin, path);

        while (path == "")
        {
            std::cout << "Please enter knownrecipients path to continue" << std::endl;
            std::getline(std::cin, path);
        }


        std::string name_edit = "", email_edit = "", cypher_edit = "", timezone_edit, path_edit = "";

        std::ofstream editfile;
        editfile.open(EDIT);

        std::cout << "Enter your new first and last name, please" << std::endl;
        std::getline(std::cin, first_and_last);

        while (first_and_last == "") {
            std::cout << "Please enter your new first and last name to continue" << std::endl;
            std::getline(std::cin, first_and_last);
        }

        std::cout << "Enter your new email address, please" << std::endl;
        std::getline(std::cin, email);

        while (email == "") {
            std::cout << "Please enter your new email to continue" << std::endl;
            std::getline(std::cin, email);
        }

        std::cout << "Enter your new unique cypher, please" << std::endl;
        std::getline(std::cin, cypher);

        while (cypher == "") {
            std::cout << "Please enter your new unique cypher to continue" << std::endl;
            std::getline(std::cin, cypher);
        }


        std::cout << "Enter your new timezone offset, please" << std::endl;
        std::getline(std::cin, timezone);


        while (timezone_edit == "") {
            std::cout << "Please enter your new timezone to continue" << std::endl;
            std::getline(std::cin, timezone);
        }


        std::cout << "Enter thew new path to knownrecipients file, please" << std::endl;
        std::getline(std::cin, path);

        while (path == "") {
            std::cout << "Please enter the new knownrecipients path to continue" << std::endl;
            std::getline(std::cin, path);
        }
        // editfile << all the new stuff


        editfile.close();
    }
            // ifstream myfile ("known_recipients.txt);
            // if (myfile.is_oerwpen())
            // {
            //while ( getline (myfile, line))

            //}

    else
    {
        std::cout << "Unacceptable! Please try something different." << std::endl;

    }
return(0);
}