#ifndef MMUTANTSTACK_HPP
#define MMUTANTSTACK_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <stack>
#include <exception>

template <typename T>

class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack <T> (){}
        MutantStack(const MutantStack & cpy) : std::stack<T>(cpy){}
        MutantStack& operator=(const MutantStack & op)
        {
            if(this != &op)
            {
                std::stack<T>::operator=(op);
            }
            return(*this);
        }
        ~MutantStack(){}

        //n3tiw lhad 5ona iterators dyalo!
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        //db n3tiwlo funcs dyalo!
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
        reverse_iterator rbegin()
        {
            return this->c.rbegin();
        }
        reverse_iterator rend()
        {
            return this->c.rend();
        }
        const_iterator begin() const
        {
            return this->c.begin();
        }
        const_iterator end() const
        {
            return this->c.end();
        }
        const_reverse_iterator rbegin() const
        {
            return this->c.rbegin();
        }
        const_reverse_iterator rend() const
        {
            return this->c.rend();
        }
};

#endif