// Configuration editor
// Command line utiltiy to create configuration files
// Valid arguments are init and edit

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>


using std::cout;
using std::endl;
using std::string;
using std::cin;

const string CONFIG_FILE_PATH = "/users/bconway/SourceTree/School/CPT-180-27-Assignment-2-Config-Generator/app.cfg";


int main(int argc, char *argv[]) {

    string argument1 = "";
    // Make sure that the argument isn't empty
    if (argv[1] != nullptr) {
        argument1 = static_cast<string>(argv[1]);
    }

    if (argument1 == "init") {

        // initialize the config file
        // TODO determine if the file exists and handle the exception

        std::ofstream config_file;

        config_file.open(CONFIG_FILE_PATH);

        // array to hold prompts, setting name and default values
        const int ARRAY_SIZE = 5;
        const string SETTING_NAME[ARRAY_SIZE] = {"name", "email", "cypher", "timezone", "knownrecipients"};
        const string SETTING_PROMPT[ARRAY_SIZE] = {"Enter your name (first and last):", "Enter your email address:",
                                                   "Enter your unique cypher (password):",
                                                   "Enter your timezone-offset (example -5:00):",
                                                   "Enter path to knownrecipients file (hit enter for the default knownrecipients.txt):"};
        const string SETTING_DEFAULT[ARRAY_SIZE] = {"", "", "", "", "./knownrecipients.txt"};

        string temp_value = "";
        for (int x = 0; x < ARRAY_SIZE; x++) {
            // Get each value from the array
            temp_value = "";
            cout << SETTING_PROMPT[x] << endl;
            std::getline(cin, temp_value);

            // If the default value is not blank then use the default value
            if (SETTING_DEFAULT[x] != "" && temp_value == "") {
                temp_value = SETTING_DEFAULT[x];
            }
            while (temp_value == "") {
                cout << "Error, please do not leave the " << SETTING_NAME[x] << " value blank." << endl;
                cout << SETTING_PROMPT[x] << endl;
                std::getline(cin, temp_value);
            }


            config_file << SETTING_NAME[x] << "=" << temp_value << endl;
        }


        config_file.close();


    } else if (argument1 == "edit") {
        // edit the config file

        // Create a backup of the config file

        const string FILE = CONFIG_FILE_PATH;
        const string BACKUP_FILE = FILE + ".backup";

        // Delete the previous backup if it exists
        std::remove(BACKUP_FILE.c_str());

        // Create a backup of the config before it is edited
        int result = std::rename(FILE.c_str(), BACKUP_FILE.c_str());

        if (result == 0) {

            // TODO if the edit item is missing then cycle through the
            // config file allowing the user to accept the current settings

            std::ifstream infile;
            std::ofstream outfile;

            infile.open(BACKUP_FILE);
            outfile.open(FILE);

            // Check if the second argument is blank
            string command_argument = "";
            if (argv[2] != nullptr) {
                command_argument = static_cast<string>(argv[2]);
            }


            string read_line = "";
            string current_setting = "";
            string new_setting = "";

            if (infile.is_open()) {
                while (std::getline(infile, read_line)) {

                    // Get the setting from the each line
                    string temp_value = "";
                    string setting_value = "";
                    string setting_name = "";
                    bool found_first_bracket = false; // Make true when the first '[' is found

                    for (int i = 0; i < read_line.length(); i++) {
                        if (!found_first_bracket) {
                            if (read_line[i] == '[') {
                                found_first_bracket = true;
                            }
                        } else {
                            // Check for the next "]"
                            if (read_line[i] == ']') {
                                setting_name = temp_value;
                                setting_value = read_line.substr(i + 2, read_line.length() - i + 2);
                                found_first_bracket = false;
                                temp_value = "";
                                break;
                            } else {
                                // Enter the line one char at a time and convert the char
                                // to lower case for comparison.
                                std::locale loc;
                                temp_value = temp_value + std::tolower(read_line[i], loc);
                            }
                        }
                    }

                    // If no setting value is set then prompt for each line
                    if (command_argument == "") {

                        cout << "The current setting for " << setting_name << " is: ";
                        cout << setting_value << "." << endl;
                        cout << "Please enter the new value ";
                        cout << "or press enter to keep the ";
                        cout << "current value." << endl;
                        std::getline(cin, new_setting);
                        if (new_setting == "") {
                            outfile << read_line << endl;
                        } else {
                            outfile << "[" << setting_name << "]" << "=" << new_setting << endl;
                        }
                        current_setting = "";
                        new_setting + "";

                    } else {

                        // If the entered argument matches the current setting then
                        // allow it to be updated else just save the current line
                        // to the new file.
                        if (command_argument == setting_name) {
                            cout << "The current setting for " << setting_name << " is: ";
                            cout << setting_value << "." << endl;
                            cout << "Please enter the new value ";
                            cout << "or press enter to keep the ";
                            cout << "current value." << endl;
                            std::getline(cin, new_setting);
                            if (new_setting == "") {
                                outfile << read_line << endl;
                            } else {
                                outfile << "[" << setting_name << "]" << "=" << new_setting << endl;
                            }
                            current_setting = "";
                            new_setting + "";

                        } else {
                            outfile << read_line << endl;
                        }

                    }
                }
            }

            infile.close();
            outfile.close();

        } else {
            cout << "Error backing up original config file";
        }
    }

    else {
// invalid argument
        cout << "Invalid argument us int or edit." <<
        endl;
        cout << "When using edit either enter a value to edit" <<
        endl;
        cout << "(name, email, cypher, timezone, or knownrecipients)." <<
        endl;
        cout << "If no setting is entered then the settings will be cycled through" <<
        endl;
    }

    return 0;
}

