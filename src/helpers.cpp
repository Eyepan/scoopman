#include "helpers.h"

void ParamApps::parseOptions()
{
    //popping out the first element since it's obviously pacman
    tokens.erase(tokens.begin());

    //save the flag to the flags variable and then pop out the first element
    this->parseFlags(tokens[0]);

    //now tokens only have applications inside of it. Hereafter referring to tokens is the same as referring to applications
}

void ParamApps::parseFlags(std::string flags)
{
    tokens.erase(tokens.begin());
    switch(flag[flags])
    {
        case S:
            {
                std::string installables;
                for (auto i : tokens)
                    installables.append(i);
                std::string command = "scoop install " + installables;
                system(command.c_str());
                break;
            }
        case Syu:
            {
                system("scoop update *");
                break;
            }
        default: 
            std::cerr << "INVALID OPERATOR";
            break; 

                
    }
}
ParamApps::ParamApps(int argc, char** argv)
{
    // convert everything to a vector instead of doing it the manual way
    for (int i = 0; i < argc; i++)
    {
        this->tokens.push_back(std::string(argv[i]));
    }

    //now parse that vector and do stuff with it
    this->parseOptions();
}