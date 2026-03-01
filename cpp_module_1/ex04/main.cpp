#include "includes.hpp"

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cout << "Wrong number of args!" << std::endl;
        return(1);
    }
    std::string buffer;
    std::string origin = av[2];
    std::string newString = av[3];

    std::ifstream file;
    if(origin.empty())
        return(0);
    file.open(av[1]);
    if(!file)
    {
        std::cout << "Failed to open the file : " << av[1] << std::endl;
        return(1);
    }
    std::string replaceFile = std::string(av[1]) + ".replace";
    std::ofstream repFile;
    repFile.open(replaceFile.c_str());
    if(!repFile)
    {
        std::cout << "Failed to open the file : " << replaceFile << std::endl;
        return(1); 
    }
    size_t position;
    while(std::getline(file,buffer))
    {
        position = 0;
        while ((position = buffer.find(origin, position)) != std::string::npos)
        {
            buffer.erase(position, origin.length());
            buffer.insert(position, newString);
            position += newString.length();
        }
        repFile <<buffer;
        if (file.peek() != EOF)
            repFile << '\n';
    }
    return(0);
}