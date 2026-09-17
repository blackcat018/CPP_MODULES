#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename S>

void iter(T *array, std::size_t lenght, S func)
{
    if(!array || !func)
    {
        return;
    }
    std::size_t i = 0;
    while(i < lenght)
    {
        func(array[i]);
        i++;
    }
}

#endif