#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template<typename T>

class Array
{
    private:
        T *data;
        unsigned int size;
    public:
        Array() : data(NULL), size(0){};


        Array(unsigned const int S) : data(NULL), size(S)
        {
            data = new T[S]();
        }


        Array(const Array &cpy) : data(NULL), size(cpy.size)
        {
            if (cpy.size > 0)
            {
                data = new T[cpy.size];
                for (unsigned int i = 0; i < cpy.size; i++)
                {
                    data[i] = cpy.data[i];
                }
            }
        }


        Array& operator=(const Array &op)
        {
            if(this != &op)
            {
                if(data)
                    delete[] data;
                size = op.size;
                if(size > 0)
                {
                    unsigned int i = 0;
                    data = new T[size];
                    while(i < size)
                    {
                        data[i] = op.data[i];
                        i++;
                    }
                }
                else if(size == 0)
                    data = NULL;
            }
            return *this;
        }


        ~Array()
        {
            if(data)
                delete[] data;
        }


        unsigned int sizer() const
        {
            return(size);
        }


        T& operator[](unsigned int i)
        {
            if (i >= size)
            throw std::out_of_range("Index out of bounds");

            return(data[i]);
        }

        const T & operator[](unsigned int i) const
        {
            if (i >= size)
                throw std::out_of_range("Index out of bounds");
            return data[i];
        }

};

#endif