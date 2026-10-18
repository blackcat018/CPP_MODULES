#include "Pmergeme.hpp"

const char* PmergeMe::invalidException::what() const throw()
{
    return ("Error: Invalid input.\n"
            "Usage: Positive integers only, no duplicates or overflow.");
}

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &cpy): data(cpy.data), sorted(cpy.sorted){}
PmergeMe& PmergeMe::operator=(const PmergeMe& op)
{
    (void) op;//will stay like this untill we add out container in private  
    return *this;
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
        // std::cout << av[i] << std::endl;
        i++;
    }
}
void printit(std::vector<t_pairs> blocks)
{
    int i  = 0;
    int len = blocks.size();
    while(i < len)
    {
        std::cout << "{" << blocks[i].a << " , " << blocks[i].b << "}" << std::endl;
        i++;
    }
}
std::vector<t_pairs> PmergeMe::pairing(int ac, char **av)
{
    int i = 1;
    Parser(ac,av);
    std::vector<t_pairs> blocks;
    t_pairs tmp;
    while(av[i] && av[i + 1])
    {
        if(std::atoi(av[i]) > std::atoi(av[i + 1]))
        {
           tmp.a = std::atoi(av[i]);
           tmp.b = std::atoi(av[i + 1]);
           blocks.push_back(tmp);
        }
        else if(std::atoi(av[i]) < std::atoi(av[i + 1]))
        {
           tmp.b = std::atoi(av[i]);
           tmp.a = std::atoi(av[i + 1]);
           blocks.push_back(tmp);
        }
        i = i + 2;
    }
    // printit(blocks);
    return blocks;
}

void PmergeMe::merge(std::vector<t_pairs>& left, std::vector<t_pairs>& right, std::vector<t_pairs>& blocks) {
    size_t i = 0;
    size_t j = 0;
    
    blocks.clear();

    while (i < left.size() && j < right.size()) {
        if (left[i].a < right[j].a) {
            blocks.push_back(left[i]);
            i++;
        } else {
            blocks.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        blocks.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        blocks.push_back(right[j]);
        j++;
    }
}

void PmergeMe::splitter(std::vector<t_pairs> &blocks)
{
    if(blocks.size() <= 1)
        return;
    size_t mid = blocks.size() / 2;

    std::vector<t_pairs> left(blocks.begin(), blocks.begin() + mid);
    std::vector<t_pairs> right(blocks.begin() + mid, blocks.end());

    splitter(left);
    splitter(right);

    merge(left,right,blocks);
}

std::vector<size_t> JacobsthalSequence(size_t pendSize) {
    
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

void PmergeMe::unpack(int ac, char **av)
{
    std::vector<t_pairs> blocks = pairing(ac,av);
    splitter(blocks);
    std::deque<int> sorted;
    std::deque<int> pend;
    int i = 1;
    int j = 1;
    int len = blocks.size();
    sorted.push_back(blocks[0].b);
    sorted.push_back(blocks[0].a);
    while(i < len)
    {
        sorted.push_back(blocks[i].a);
        i++;
    }
    while(j < len)
    {
        pend.push_back(blocks[j].b);
        j++;
    }
    if((ac - 1) % 2 != 0)
        pend.push_back(std::atoi(av[ac -1]));
   std::vector<size_t> jacobSeq = JacobsthalSequence(pend.size());
    size_t insertedCount = 0;
    size_t previousJacob = 0; 

    for (size_t k = 0; k < jacobSeq.size(); ++k)
    {
        size_t currentJacob = jacobSeq[k];
        size_t targetIndex = (currentJacob < pend.size()) ? currentJacob : pend.size();

        for (size_t j = targetIndex; j > previousJacob; --j) {
            size_t pendIdx = j - 1; 

            std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), pend[pendIdx]);
            sorted.insert(it, pend[pendIdx]);
            insertedCount++;
        }
        previousJacob = currentJacob;
    }

    while (insertedCount < pend.size()) {
        std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), pend[insertedCount]);
        sorted.insert(it, pend[insertedCount]);
        insertedCount++;
    }
    int p = 0;
    int ss = sorted.size();
    while(p < ss)
    {
        std::cout << sorted[p] ;
        if(p < ss - 1)
            std::cout << " ,";
        p++;
    }
    std::cout << std::endl;
}