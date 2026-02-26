#include <iostream>
#include <string>

static std::string uppies(std::string str)
{
    int i = 0;
    while (str[i])
    {
        if(str[i] <= 122 && str[i] >= 97)
            str[i] = str[i] - 32;
        i++;
    }
    return(str);
}
int main (int ac, char **av)
{
    int i = 1;
    if(ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; 
        return (0);
    }
    while(av[i])
    {
        std::cout << uppies(av[i]);
        i++;
    }
    std::cout << std::endl;
    return(0);
}