#include <services.hpp>
#include <fstream>
#include <iostream>

json* JSON::readFile(std::string path)
{
    json* mem = new json();
    std::ifstream fin(path);

    fin >> *mem;
    
    fin.close();

    return mem;
}

void JSON::saveFile(std::string path, json *data)
{
    std::ofstream fout(path);

    fout << data->dump(4);

    fout.close();

    return ;
}
