#include "RPN.hpp"

Rpn::Rpn(){}

Rpn::Rpn(const Rpn& cpy) : oper(cpy.oper){}

Rpn& Rpn::operator=(const Rpn& op)
{
    if(this != &op)
    {
        this->oper = op.oper;
    }
    // std::cout << "Operator onstructor is done!" <<std::endl;
    return *this;
}

Rpn::~Rpn(){}

int Rpn::calculate(int a, int b, char op)
{
    switch(op)
    {
        case '+':
            return(a + b);
        case '-':
            return(a - b);
        case '*':
            return(a * b);
        case '/':
            if(b == 0)
                throw std::runtime_error("Error! you are trying to devide by 0??");
            return(a / b);
        default:
            throw std::runtime_error("Error! Not an Operator! try one of \'+\', \'-\', \'*\', or \'/\'");
    }
}

bool Rpn::isOperation(char str)
{
    return(str == '+' || str == '-'|| str == '*' || str == '/');
}

int Rpn::doOp(const std::string & arg)
{
    std::size_t i = 0;
    std::string tmp = arg;
    std::string buf;
    int num = 0;
    while(i < arg.size())
    {
        if(std::isdigit(tmp[i]))
        {
            num = tmp[i] - '0';
            // std::cout << "-------------------------- " << num  << " --------------------------" <<std::endl;
            oper.push(num);
        }
        else if(isOperation(tmp[i]))
        {
            if(oper.size() < 2)
                throw std::runtime_error("Not enough numbers to operate on!");
            int b = oper.top();
            oper.pop();
            int a = oper.top();
            oper.pop();
            int res = calculate(a,b,tmp[i]);
            oper.push(res);
        }
        
        else if(!std::isspace(tmp[i]))
            throw std::runtime_error("Not a valid input! try again!");
        i++;
    }
    if(oper.size() != 1)
        throw std::runtime_error("the input does not meet the polish format standards!");
    return(oper.top());
}
