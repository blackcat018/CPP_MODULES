#include "Pmergeme.hpp"

const char* PmergeMe::invalidException::what() const throw()
{
    return ("Error: Invalid input.\n"
            "Usage: Positive integers only, no duplicates or overflow.");
}

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
    (void)cpy;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& op)
{
    (void) op;  
    return *this;//mothing to assign, no member variables to copy
}

PmergeMe::~PmergeMe(){}

static int check_digit(char *str)
{
    int i =0;
    if(str[i] == '+')
        i++;
    while(str[i])
    {
        if(!isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}

static int check_limits(char *str)
{
    char *buf;

    long val = strtol(str, &buf, 10);
    if (errno == ERANGE || val > INT_MAX)
        return 0;
    return 1;
}

void PmergeMe::Parser(int ac ,char **av)
{
    int i = 1;
    while(i < ac)
    {
        if(!av[i][0] || !check_digit(av[i]) || !check_limits(av[i]))
            throw invalidException();
        i++;
    }
}

std::vector<size_t> PmergeMe::JacobsthalSequence(size_t pendSize) 
{
    std::vector<size_t> jacob;
    if (pendSize == 0)
        return jacob;

    size_t j1 = 3;
    size_t j2 = 5;
    
    jacob.push_back(j1);
    if (pendSize >= 2) {
        jacob.push_back(j2);
    }
    
    while (true) {
        size_t nextJ = j2 + 2 * j1;
        if (nextJ >= pendSize + 2)
        {
            jacob.push_back(pendSize);
            break;
        }
        jacob.push_back(nextJ);
        j1 = j2;
        j2 = nextJ;
    }
    return jacob;
}

void PmergeMe::sortAndTime(int ac, char **av)
{
    Parser(ac, av);

    std::cout << "Before: ";
    for (int i = 1; i < ac; i++) {
        std::cout << av[i] << " ";
    }
    std::cout << std::endl;
    std::vector<t_pairs> vecBlocks = pairing< std::vector<t_pairs> >(ac, av);
    clock_t start_vec = clock();
    std::vector<int> vecSorted = runAlgorithm< std::vector<t_pairs>, std::vector<int> >(vecBlocks, ac, av);
    clock_t end_vec = clock();
    double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000.0;
    std::deque<t_pairs> deqBlocks = pairing< std::deque<t_pairs> >(ac, av);
    clock_t start_deq = clock();
    std::deque<int> deqSorted = runAlgorithm< std::deque<t_pairs>, std::deque<int> >(deqBlocks, ac, av);
    clock_t end_deq = clock();
    double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "After:  ";
    for (size_t i = 0; i < vecSorted.size(); i++) {
        std::cout << vecSorted[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << (ac - 1) 
              << " elements with std::vector : " << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << (ac - 1) 
              << " elements with std::deque  : " << time_deq << " us" << std::endl;
}
