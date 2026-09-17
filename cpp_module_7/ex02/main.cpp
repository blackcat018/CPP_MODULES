
#include "Array.hpp"

int main()
{
    std::cout << "=== 1. Testing Default (Empty) Array ===" << std::endl;
    Array<int> emptyArr;
    std::cout << "Empty array size: " << emptyArr.sizer() << std::endl;

    try {
        std::cout << "Trying to access emptyArr[0]..." << std::endl;
        std::cout << emptyArr[0] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== 2. Testing Sized Array & Default Values ===" << std::endl;
    Array<int> intArr(5);
    std::cout << "intArr size: " << intArr.sizer() << std::endl;
    
    std::cout << "Default value at index 0: " << intArr[0] << std::endl;

    for (unsigned int i = 0; i < intArr.sizer(); i++) {
        intArr[i] = (i + 1) * 10;
    }

    std::cout << "Modified values: ";
    for (unsigned int i = 0; i < intArr.sizer(); i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== 3. Testing Deep Copy (Copy Constructor & Assignment) ===" << std::endl;
    Array<int> copyArr(intArr);
    Array<int> assignArr;
    assignArr = intArr;

    intArr[0] = 999;

    std::cout << "Original intArr[0]: " << intArr[0] << " (Modified)" << std::endl;
    std::cout << "Copy copyArr[0]:     " << copyArr[0] << " (Should stay 10)" << std::endl;
    std::cout << "Assign assignArr[0]: " << assignArr[0] << " (Should stay 10)" << std::endl;

    std::cout << "\n=== 4. Testing Complex Types (std::string) ===" << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "42";
    strArr[2] = "Network";

    for (unsigned int i = 0; i < strArr.sizer(); i++) {
        std::cout << "strArr[" << i << "] = " << strArr[i] << std::endl;
    }

    std::cout << "\n=== 5. Testing Const Correctness ===" << std::endl;
    const Array<std::string> constStrArr(strArr);
    std::cout << "constStrArr[1]: " << constStrArr[1] << std::endl;

    std::cout << "\n=== 6. Testing Out-of-Bounds Exception ===" << std::endl;
    try {
        std::cout << "Accessing index 100 on array of size 5..." << std::endl;
        intArr[100] = 42;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
}