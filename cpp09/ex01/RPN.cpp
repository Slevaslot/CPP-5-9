#include "RPN.hpp"

bool isInteger(char token)
{
    if (!isdigit(token)) {
        return false;
    }
    return (true);
}
int calculate(std::stack<int> operands, std::stack<char> operators)
{
    if (operators.size() + 1 != operands.size())
        throw (std::invalid_argument("error: wrong number of digit or operators"));
    int operand1 = operands.top();
    while(operands.size() > 1 && operators.size() > 0)
    {
        operands.pop();
        int operand2 = operands.top();
        if (operators.top() == '+') {
            operand1 = (operand1 + operand2);
        } else if (operators.top() == '-') {
            operand1 = (operand1 - operand2);
        } else if (operators.top() == '*') {
            operand1 = (operand1 * operand2);
        } else if (operators.top() == '/') {
            if (operand2 == 0)
                throw std::invalid_argument("can't divise by 0.");
            operand1 = (operand1 / operand2);
        }
        operators.pop();
    }
    return (operand1);
}

int evaluateRPN(const std::string& expression) {
    std::istringstream iss(expression);
    std::stack<int> operands;
    std::stack<char> operators;
    std::string token;
    for (int i = expression.size() - 1; i >= 0; i--)
    {
        if (expression[i] == ' ')
            continue;
        else if (isInteger(expression[i]))
        {
            int value = expression[i] - '0';
            operands.push(value);
        }
        else if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-' || expression[i] == '/')
            operators.push(expression[i]);
        else
            throw std::invalid_argument("invalid argument.");
    }
    return (calculate(operands, operators));
}
