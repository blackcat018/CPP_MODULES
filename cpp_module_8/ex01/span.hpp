#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <exception>

class span
{
    private:
        unsigned int N;
        std::vector <int> arr;
    public:
        span();
        span(const unsigned int C);
        span(const span& cpy);
        span &operator=(const span &op);
        ~span();

        void addNumber(unsigned int number);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        void print_minMax() const;
        int get_size()const;

        template <typename T>
        void addBatch(T begin, T end)
        {
            std::ptrdiff_t dist = std::distance(begin, end);
            if(dist <= 0)
            {
                throw noSpanException();
            }
            if(arr.size() +static_cast<unsigned long>(dist) > N)
            {
                throw fullSpanException();
            }
            this->arr.insert(this->arr.end(),begin,end);
        }

        class noSpanException : public std::exception
        {
            virtual const char* what() const throw(){
                return("there are not enough elements to calculate a span!");
            }
        };
        class fullSpanException : public std::exception
        {
            virtual const char* what() const throw(){
                return("the span is full! you cannot exceed the span's length!");
            }  
        };
};

#endif