#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct  Data_b
{
    int n;
    std::string str;
}Data;


class serializer
{
    private:
        serializer();
        serializer(const serializer& cpy);
        serializer operator=(const serializer& op);
        ~serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif