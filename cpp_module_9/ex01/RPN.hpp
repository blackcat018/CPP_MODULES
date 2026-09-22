#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cctype>
#include <sstream>
#include <cstdlib>
#include <string>

class Rpn
{
    private:
        std::stack<int> oper;
        bool isOperation(char ope);
        // bool isNumber(const std::string &str);
        int calculate(int a,int b,char op);
    public:
        Rpn();
        Rpn(const Rpn& cpy);
        Rpn& operator=(const Rpn& op);
        ~Rpn();
        int doOp(const std::string &arg);
};
#endif
