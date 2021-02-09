#include <helpers.hpp>


Command::Command(int argc, char** argv)
{
    parseCommands(argc, argv);      //so that we get our applications list and our tokens
    queueCommand(decideCommand());  //so that we decide on what we are going to do and queue it for execution
}

void Command::parseCommands(int argc, char** argv)
{
    //transferring the contents of the argv into a tokens vector iterativel
    for (int i = 0; i < argc; i++)
    {
        tokens.push_back(argv[i]);
    }

    //deleting the first token since it is going to be pacman
    tokens.erase(tokens.begin());

    //parsing and getting the flags
    flags = tokens[0];

    //removing the flags from the applications list
    tokens.erase(tokens.begin());

    //parsing and getting the list of applications
    for (auto i : tokens)
    {
        applicationslist.append(i + " ");
    }
}

Command::comm Command::decideCommand()
{
    //update based on comm
    if (flags == "-S")
    {
        return Command::comm::install;
    }
    else if (flags == "-Syu")
    {
        return Command::comm::update;
    }
    else if (flags == "-Qe")
    {
        return Command::comm::searchinstalled;
    }
    else if (flags == "-Ss")
    {
        return Command::comm::searchonline;
    }
    else if (flags == "-Q")
    {
        return Command::comm::list;
    }
    else if (flags == "-R")
    {
        return Command::comm::uninstall;
    }
    else if (flags == "-h")
    {
        return Command::comm::help;
    }
    else 
    {
        return Command::comm::error;
    }
}

void Command::queueCommand(Command::comm decidedCommand)
{
    switch(decidedCommand)
    {
        case install:
        {
            std::cout << "INSTALLING: " << applicationslist << "\n";
            executeCommand("scoop insatll " + applicationslist + " --global");
            break;
        }
        case update:
        {
            std::cout << "UPDATING ALL APPS\n";
            executeCommand("scoop update * --global");
            std::cout << "RUNNING SCOOP STATUS\n";
            executeCommand("scoop status");
            if (applicationslist.length() > 2)
            {
                std::cout << "INSTALLING: " << applicationslist << "\n";
                executeCommand("scoop insatll " + applicationslist + " --global");
            }
            break;
        }
        case searchinstalled:
        {
            std::cout << "SEARCHING INSTALLED FOR: " << applicationslist << "\n";
            executeCommand("scoop which " + applicationslist + " --global");
        }
        case searchonline:
        {
            std::cout << "SEARCHING ONLINE FOR: " << applicationslist << "\n";
            executeCommand("scoop search " + applicationslist + "--global");
        }
        case list:
        {
            std::cout << "LISTING ALL INSTALLED APPS:\n";
            executeCommand("scoop list");
        }
        case uninstall:
        {
            std::cout << "UNINSTALLING: " << applicationslist << "\n";
            executeCommand("scoop uninstall " + applicationslist + " --global");
        }
        case help:
        {
            std::cout << man << "\n";
            std::cout << "PRESS ENTER TO RUN SCOOP HELP:";
            std::cin.get();
            executeCommand("scoop help");
        }
        default:
        {
            std::cout << "INVALID OPTION";
            std::cout << man << "\n";
        }
    }
}

void Command::executeCommand(std::string command)
{
    system(command.c_str());
}
