#include "RPN.hpp"

bool isInteger(std::string token)
{
    for (size_t i = 0; i < token.length(); ++i) {
        if (!isdigit(token[i])) {
            return false;
        }
    }
    int valeur = atoi(token.c_str());
    return (valeur < 10);
}
double calculate(std::stack<double> operands, std::stack<char> operators)
{
    if (operators.size() + 1 != operands.size())
        throw (std::invalid_argument("error: wrong number of digit or operators"));
    double operand1 = operands.top(); operands.pop();
    while(!operands.empty())
    {
        double operand2 = operands.top(); operands.pop();
        std::cout << "OP1: " << operand1 << "OP2: "<< operand2 << std::endl;
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
        operands.push(operand1);
        operators.pop();
    }
    return (operands.top());
}

int evaluateRPN(const std::string& expression) {
    std::istringstream iss(expression);
    std::stack<double> operands;
    std::stack<char> operators;
    std::string token;

    while (iss >> token)
    {
        if (isInteger(token))
        {
            char* endptr;
            double value = strtod(token.c_str(), &endptr);
            if (*endptr == '\0') {
                operands.push(value);
            }
        }
        else if (token[0] == '*' || token[0] == '+' || token[0] == '-' || token[0] == '/')
            operators.push(token[0]);
        else
            throw std::invalid_argument("invalid argument.");
    }
    return (calculate(operands, operators));
}
