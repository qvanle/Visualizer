#include <services.hpp>
#include <fstream>
#include <iostream>

std::vector<std::string> FILEE::readFile(std::string path)
{
    std::vector<std::string> result;

    std::ifstream fin(path);

    std::string line;

    while(std::getline(fin, line))
    {
        result.push_back(line);
    }

    fin.close();

    return result;
}
