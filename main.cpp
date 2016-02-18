/*This is the first draft of a Config file
 * that asks for your name, email, pin, timezone and knowFile
 * Joseph Thompson CPT 180
 */

#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

int main() {

    string name, email, pin, timeZone, knownFile;

    while (name.size() == 0){
        cout << "Please Enter Your First and Last Name: " << endl;
        getline(cin, name);
    }
    cout << "Your name is: " << name << endl;

    while (email.size() == 0) {
        cout << "Enter your e-mail address: " << endl;
        getline(cin, email);
    }
        cout << "Your E-Mail Address is : " << endl;

    while (pin.size() == 0){
        cout << "Enter you cypher" << endl;
    getline(cin, pin);
}
    cout << "You have entered your cypher" << endl;

    while (timeZone.size()== 0) {
        cout << "Enter a timezone: " << endl;
        getline(cin, timeZone);
    }
        cout << "Time Zone entered: " << endl;

    cout << "Enter a knownFile recipient, If none type 0:  " << endl;
        getline(cin, knownFile);
    if (knownFile == "0") {
        knownFile = "c:\\default";
        cout << "The Default File has been choosen" << endl;
    }
        else
        cout << "You have finished data input" << endl;
     // Send information to config.txt file

    ofstream outputFile;
    outputFile.open("config.txt");
    outputFile << "Name: " << name << endl;
    outputFile << "Email: " << email << endl;
    outputFile << "Cypher: " << pin << endl;
    outputFile << "TimeZone: " << timeZone << endl;
    outputFile << "Known File Recipient: " << endl;

    outputFile.close();


    return 0;
}