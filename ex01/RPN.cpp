#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->stack = other.stack;
    }
    return *this;
}

void    RPN::ReadInput(std::string input)
{
    std::string operations = "*/+-";
    int NumbersNum = 0;
    int OperationsNum = 0;

    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
            continue;
        if (operations.find(input[i]) != std::string::npos)
        {
            OperationsNum++;
            int num1 = this->stack.top();
            this->stack.pop();
            int num2 = this->stack.top();
            this->stack.top() = this->Calculate(num2, num1, input[i]);
        }
        else if (isdigit(input[i]))
        {
            NumbersNum++;
            this->stack.push(input[i] - '0');
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
            return ;
        }
    }
    if ((OperationsNum + 1) != NumbersNum)
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }
    std::cout << this->stack.top() << std::endl;
}

int    RPN::Calculate(int n1 , int n2, char op)
{
    if (n2 == 0 && op == '/')
    {
        std::cout << "Division by zero" << std::endl;
        exit(1);
    }
    if (op == '*')
        return n1 * n2;
    else if (op == '/')
        return n1 / n2;
    else if (op == '+')
        return n1 + n2;
    else if (op == '-')
        return n1 - n2;
    return 0;
}