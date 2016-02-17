#include <iostream>

using namespace std;
#include <fstream>

int main() {

    const int ARRAY_SIZE = 8;
    string congen_entry[ARRAY_SIZE];
    string congen_read[ARRAY_SIZE];
    int question;
    int count = 0;
    ofstream myofile;
    ifstream myifile;


    cout << "Do you want to enter data into the generator?\n";
    cout << "Enter 1 for yes and any other number for no.";
    cin >> question;


    if(question == 1){

        cout << "Enter your data now." << endl;
        cout << "Enter your first and last name.";
        cin >> congen_entry[0];
        cout << "Enter your email address.";
        cin >> congen_entry[1];
        cout << "Enter your unique password.";
        cin >> congen_entry[2];
        cout << "Enter your timezone-offset.";
        cin >> congen_entry[3];
        cout << "Enter path to known recipients file.";
        cin >> congen_entry[4];
        myofile.open ("congen.txt");

        for (count = 0; count < ARRAY_SIZE; count++)
            myofile << congen_entry[count] << endl;
        myofile.close();
    }
    else
        cout << "No entry confirmed.\n";

    cout << "Do you want to read the current file?" << endl;
    cout << "Enter 1 for yes and any other number for no.";
    cin >> question;

    if (question == 1){
        myifile.open("congen.txt");

        while (count < ARRAY_SIZE && myifile >> congen_read[count])
            count++;

        myifile.close();
        cout << "This file contains the following data.\n" << endl;

        for (count = 0; count < ARRAY_SIZE; count++)
            cout << congen_read[count] << endl;
    }
    else
        cout << "Not reading confirmed.\n";

    cout << "Do you want to edit a specific answer of the file?\n";
    cout << "Enter 1 for yes and any other number for no.";
    cin >> question;

    if (question == 1){
        myifile.open("congen.txt");

        while (count < ARRAY_SIZE && myifile >> congen_read[count])
            count++;

        myifile.close();

        int choice = 0;
        cout << "You can now re-answer one of the five answers.\n";
        cout << "Press 1 for name, 2 for email, 3 for password, ";
        cout << "4 for time, 5 for path, and anything else for no change.";
        cin >> choice;

        switch (choice)
       {
           case 1:cout << "Enter your first and last name.";
               cin >> congen_entry[0];
               break;

           case 2:cout << "Enter your email address.";
               cin >> congen_entry[1];
               break;

           case 3:cout << "Enter your unique password.";
               cin >> congen_entry[2];
               break;

           case 4:cout << "Enter your timezone-offset.";
               cin >> congen_entry[3];
               break;

           case 5:cout << "Enter path to known recipients file.";
               cin >> congen_entry[4];
               break;

           default:cout << "No changes selected.";
               break;

       }
    }
    else
        cout << "That's all. Run the program again for anything else.";

    myofile.open ("congen.txt");

    for (count = 0; count < ARRAY_SIZE; count++)
        myofile << congen_entry[count] << endl;

    myofile.close();
    cout << "That's all. Run the program again for anything else.";


    return 0;
}

