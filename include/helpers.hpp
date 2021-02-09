#include <iostream>
#include <string>
#include <vector>

class Command
{
    std::string man =
"\nFLAGS           USE CASE                         SCOOP EQUIVALENT"
"\n- (or) -h       Show this page                   scoop help"
"\n-S              Install an/multiiple apps        scoop install"
"\n-Syu            Update and install new apps      scoop update * && scoop install"
"\n-Q              List all installed apps          scoop list"   
"\n-Qe             Search for installed apps        scoop which"
"\n-Ss             Searches online for apps         scoop search"
"\n-R              Removes/Uninstalls an app        scoop uninstall"
"\nAnything else   INVALID OPTION                   scoop help";
    std::string applicationslist;
    std::string flags;
    std::vector<std::string> tokens;            //parsed vector form of the arguments in the token file
    void parseCommands(int argc, char** argv);  //get these in the main file
    void executeCommand(std::string command);
    enum comm { install, update, searchinstalled, searchonline, list, uninstall, help, error};
    comm decideCommand();
    void queueCommand(comm decidedcommand);

public:
    Command(int argc, char** argv);
};