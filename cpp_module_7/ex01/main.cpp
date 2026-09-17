#include "iter.hpp"

void decrement(int &i)
{
    i = i - 1;
}

int main()
{
    std::cout << "----------- test -----------" << std::endl;
    int arr[10];
    for(int i = 0; i < 10;i++){
        arr[i] = 6;
    }
    std::cout << "\n----------- the array before iter -----------" << std::endl;
    int i = 0;
    while(i < 10)
    {
        std::cout << "arr[" << i << "] : " << arr[i]  << std::endl;
        i++;
    }
    iter(arr,10,decrement);
    std::cout << "\n----------- the array after iter -----------" << std::endl;
    i = 0;
    while(i < 10)
    {
        std::cout << "arr[" << i << "] : " << arr[i]  << std::endl;
        i++;
    }
}