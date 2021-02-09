#include <iostream>
#include <vector>
#include <string>
#include <map>

int main(int argc, char** argv)
{
    std::string man =
"\nFLAGS           USE CASE"
"\n-               Show this page. Yeah that's how you got here"
"\n-S              Install an/multiiple apps"
"\n-Syu            Update the system and install apps (if you want tho)"
"\n-Q              List all apps installed (You can also grep this if you want to search for a single app)"
"\n-Qe             Runs scoop which for your app of choice"
"\n-Ss             Search online for your app"
"\n-R              Removes/Uninstalls an app"
"\nAnything else   INVALID OPTION and you also get this file as a ball of shame!";
    //converting command line arguments into tokens and saving it into a vector
    std::vector<std::string> tokens;
    for(int i = 0; i < argc; i++)
    {
        tokens.push_back(argv[i]);
    }

    //remove the first token since it's pacman always
    tokens.erase(tokens.begin());

    //get the flags into a separate string and then remove the first element again
    std::string flags = tokens[0];
    tokens.erase(tokens.begin());

    std::string applications = "";
    for (auto i : tokens)
    {
        applications.append(i + " ");
    }
    

    if (flags == "-Syu")
    {
        std::cout << "UPDATING ALL APPLICATIONS\n";
        system("scoop update *");
        std::cout << "RUNNING SCOOP STATUS\n";
        system("scoop status");
        if (applications.length() > 2)
        {
            std::cout << "INSTALLING: " << applications << "\n";
            std::string command = "scoop install " + applications + " --global";
            system(command.c_str());
        }
    }
    else if (flags == "-S")
    {
        std::cout << "INSTALLING: " << applications << "\n";
        std::string command = "scoop install " + applications + " --global";
        system(command.c_str());
    }
    else if (flags == "-Qe")
    {
        std::cout << "SEARCHING INSTALLED FOR: " << applications << "\n";
        std::string command = "scoop which " + applications + " --global";
        system(command.c_str());
    }
    else if (flags == "-Ss")
    {
        std::cout << "SEARCHING ONLINE FOR: " << applications << "\n";
        std::string command = "scoop search " + applications + " --global";
        system(command.c_str());
    }
    else if (flags == "-Q")
    {
    	std::cout << "LISTING ALL APPS:\n";
        system("scoop list");
    }
    else if (flags == "-R")
    {
        std::cout << "UNINSTALLING: " << applications << "\n";
        std::string command = "scoop uninstall " + applications + " --global";
        system(command.c_str());
    }
    else if (flags == "-h")
    {
        std::cout << man << "\n";
    }
    else
    {
        std::cout << "INVALID OPTION\n";
        std::cout << man << "\n";
    }
    // system("pause");
    return 0;
}