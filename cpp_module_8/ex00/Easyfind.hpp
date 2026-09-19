#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class NotFoundexcep : public std::exception
{
    virtual const char* what() const throw()
    {
        return"Value has not been found";
    }
};

template <typename T>

typename T::iterator easyfind(T &container, int val)
{
    typename T::iterator found = std::find(container.begin(), container.end(), val);
    if(found == container.end())
        throw NotFoundexcep();
    return found;
}

#endif