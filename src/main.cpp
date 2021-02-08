#include <iostream>
#include <vector>
#include <string>
#include <map>

int main(int argc, char** argv)
{
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
        system("echo Updating all applications");
        system("scoop update *");
        if (applications.length() > 2)
        {
            std::cout << "INSTALLING :\n" << applications;
            std::string command = "scoop install " + applications + " --global";
            system(command.c_str());
        }
    }
    else if (flags == "-S")
    {
        std::cout << "INSTALLING :\n" << applications;
        std::string command = "scoop install " + applications + " --global";
        system(command.c_str());
    }
    else if (flags == "-Q")
    {
    	std::cout << "LISTING ALL APPS:\n";
        system("scoop list");
    }
    else if (flags == "-R")
    {
        std::cout << "UNINSTALLING" << applications << "\n";
        std::string command = "scoop uninstall " + applications + " --global";
        system(command.c_str());
    }
    // system("pause");
    return 0;
}