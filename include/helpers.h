#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

class ParamApps
{
public:
    std::vector<std::string> tokens;
    enum flags
    {
        Syu, S, Qe, R, Ss
    };
    std::map<std::string, flags> flag;
    void parseOptions();

    void parseFlags(std::string flags);

    ParamApps(int argc, char** argv);
};
