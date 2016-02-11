#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

int main(int argc, char *argv[]) {
    std::string Username = "";
    do {
        std::cout << "Enter your name(first and last)" << std::endl;
        getline(std::cin, Username);
    }while (Username == "");

    std::string Email = "";
    do {
        std::cout << "Enter your Email address" << std::endl;
        getline(std::cin, Email);
    }while (Email == "");

    std::string Pass = "";
    do {
        std::cout << "Enter your password" << std::endl;
        getline(std::cin, Pass);
    }while (Pass == "");

    std::string Timezone = "";
    do {
        std::cout << "Enter your timezone" << std::endl;
        getline(std::cin, Timezone);
    }while (Timezone == "");

    std::string Location = "knownrecipients.txt";
    std::ofstream textfile;
    textfile.open(Location);

    textfile << "[Username]" << std::endl << Username << std::endl;
    textfile << "[Email]" << std::endl << Email << std::endl;
    textfile << "[Password]" << std::endl <<Pass <<  std::endl;
    textfile << "[Timezone]" << std::endl << Timezone << std::endl;
    textfile.close();


    string line;
    ifstream myfile (Location);
    while (! myfile.eof() ) {
            for (int lineno = 0; getline (myfile,line) && lineno < 7; lineno++)
                if (lineno == 3)
                    cout << "Current Username is " << line << endl;
    }
    myfile.close();



    return 0;
}
