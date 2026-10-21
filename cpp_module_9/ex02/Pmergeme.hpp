#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <deque>
#include <errno.h>
#include <ctime>
#include <algorithm>
#include <limits.h>

typedef struct s_Pairs
{
    int a;
    int b;
} t_pairs;


class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& cpy);
        PmergeMe& operator=(const PmergeMe& op);
        ~PmergeMe();

        void sortAndTime(int ac, char **av);
        void Parser(int ac ,char **av);
        std::vector<size_t> JacobsthalSequence(size_t pendSize);
        class invalidException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        template <typename PairContainer>
        PairContainer pairing(int ac, char **av)
        {
            PairContainer blocks;
            t_pairs tmp;
            int i = 1;
            (void)ac;
            while(av[i] && av[i + 1])
            {
                int first = std::atoi(av[i]);
                int second = std::atoi(av[i + 1]);
                
                if (first > second)
                {
                    tmp.a = first;
                    tmp.b = second;
                } 
                else
                {
                    tmp.a = second;
                    tmp.b = first;
                }
                blocks.push_back(tmp);
                i += 2;
            }
            return blocks;
        }

        template <typename MergeContainer>
        void merge(MergeContainer& left, MergeContainer& right, MergeContainer& blocks)
        {
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

        template <typename PairContainer>
        void splitter(PairContainer& blocks)
        {
            if (blocks.size() <= 1) return;
            size_t mid = blocks.size() / 2;
            
            PairContainer left(blocks.begin(), blocks.begin() + mid);
            PairContainer right(blocks.begin() + mid, blocks.end());
            
            splitter(left);
            splitter(right);
            merge(left, right, blocks);
        }

        template <typename IntContainer>
        void insertPendIntoMain(IntContainer& sorted, IntContainer& pend)
        {
            std::vector<size_t> jacobSeq = JacobsthalSequence(pend.size());
            size_t insertedCount = 0;
            size_t previousJacob = 0; 

            for (size_t k = 0; k < jacobSeq.size(); ++k)
            {
                size_t currentJacob = jacobSeq[k];
                size_t targetIndex = (currentJacob < pend.size()) ? currentJacob : pend.size();

                for (size_t j = targetIndex; j > previousJacob; --j) {
                    size_t pendIdx = j - 1; 
                    typename IntContainer::iterator it = std::lower_bound(sorted.begin(), sorted.end(), pend[pendIdx]);
                    sorted.insert(it, pend[pendIdx]);
                    insertedCount++;
                }
                previousJacob = currentJacob;
            }

            while (insertedCount < pend.size()) {
                typename IntContainer::iterator it = std::lower_bound(sorted.begin(), sorted.end(), pend[insertedCount]);
                sorted.insert(it, pend[insertedCount]);
                insertedCount++;
            }
        }

        template <typename PairContainer, typename IntContainer>
        IntContainer runAlgorithm(PairContainer& blocks, int ac, char **av) 
        {
            splitter(blocks);
            
            IntContainer sorted;
            IntContainer pend;
            int len = blocks.size();

            sorted.push_back(blocks[0].b);
            sorted.push_back(blocks[0].a);
            for (int i = 1; i < len; i++) {
                sorted.push_back(blocks[i].a);
                pend.push_back(blocks[i].b);
            }
            if ((ac - 1) % 2 != 0)
                pend.push_back(std::atoi(av[ac - 1]));
            insertPendIntoMain(sorted, pend);    
            return sorted;
        }
};

#endif