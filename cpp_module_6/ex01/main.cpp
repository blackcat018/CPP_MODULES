#include "serialize.hpp"

int main()
{
    Data *test = new Data;
    test->n = 67;
    test->str = "kirk";

    std::cout << "----------------- the Data before serializing -----------------" << std::endl;
    std::cout << "\nThe number is: " << test->n << std::endl;
    std::cout << "The message is: " << test->str << std::endl;

    uintptr_t val = serializer::serialize(test);

    std::cout << "\n----------------- The Data after serialization -----------------" << std::endl;
    std::cout << "the data from before has become : " << val << std::endl;

    std::cout <<"\n----------------- The Data after The deserialization -----------------" << std::endl;
    Data *Back = serializer::deserialize(val);
        std::cout << "\nThe deserialized number is: " << Back->n << std::endl;
    std::cout << "The deserialized message is: " << Back->str << std::endl;

    if(Back == test)
        std::cout << "THE SERIALIZATION AND DESERIALIZATION HAVE BEEN SUCCESSFUL!" << std::endl;
    else
        std::cout << "womp womp!" << std::endl;
    delete test;
    return 0;
}