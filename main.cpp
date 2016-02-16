#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char *argv[]) {


    //std::string argument1 = "";

//std::string user_input = "";

//Location

//if(argument = init)
    std::ofstream myfile;
    myfile.open("known_recipients.txt");

    std::string first_and_last ="", email = "", cypher = "", timezone, path ="";

    std::cout << "Enter your first and last name, please" << std::endl;
    std::getline(std::cin, first_and_last);

    while(first_and_last == ""){
        std::cout << "Please enter your first and last name to continue" << std::endl;
        std::getline(std::cin, first_and_last);
        }

    std::cout << "Enter your email address, please" << std::endl;
    std::getline(std::cin, email);

    while(email == "") {
        std::cout << "Please enter your email to continue" << std::endl;
        std::getline(std::cin, email);
    }

    std::cout << "Enter your unique cypher, please" << std::endl;
    std::getline(std::cin, cypher);

    while(cypher == "") {
        std::cout << "Please enter your unique cypher to continue" << std::endl;
        std::getline(std::cin, cypher);
    }

    std::cout << "Enter your timezone offset, please" <<std::endl;
    std::getline(std::cin, timezone);

    while(timezone == ""){
        std::cout << "Please enter your timezone to continue" << std::endl;
        std::getline(std::cin, timezone);
    }

    std::cout << "Enter path to knownrecipients file, please" << std::endl;
    std::getline(std::cin, path);

    while(path == "") {
        std::cout << "Please enter knownrecipients path to continue" << std::endl;
        std::getline(std::cin, path);
        }

    myfile.close();

    // ;int menu_choice = 1;

    //}

    // ifstream myfile ("known_recipients.txt);
    // if (myfile.is_open())
   // {
        //while ( getline (myfile, line))

    //}
    //else cout << Unable to open file, please try something different. << std::endl;

    //else if (argument = 'edit')

    //Need to be able to make this into a switch for easy input by user

    //switch(menu_choice){
      //  case 1:
        //    argument1 == 'init';
        //case 2:
          // argument1 == 'edit'
           // break;
        //default:
           // menu_choice =1;

return(0);
}