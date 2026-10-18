#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits.h>
#include <errno.h>
#include <vector>
#include <deque>

typedef struct s_Pairs
{
    int a;
    int b;

}t_pairs;

void printit(std::vector<t_pairs> blocks);

class PmergeMe
{
    private:
        std::vector<int> data;
        std::vector<int> sorted;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& cpy);
        PmergeMe& operator=(const PmergeMe& op);
        ~PmergeMe();

        //logic
        void Parser(int ac, char **av);
        std::vector<t_pairs>  pairing(int ac, char **av);
        void splitter(std::vector <t_pairs> &blocks);
        void unpack(int ac, char **av);
        void merge(std::vector<t_pairs>& left, std::vector<t_pairs>& right, std::vector<t_pairs>& blocks);
        class invalidException :public  std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif