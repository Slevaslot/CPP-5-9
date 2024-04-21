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

int evaluateRPN(const std::string& expression) {
    std::istringstream iss(expression);
    std::stack<double> operands;
    std::string token;
	int	numberOfOperator = 0;
	int numberOfDigit = 0;

    while (iss >> token)
    {
        if (isInteger(token))
        {
			numberOfDigit++;
            char* endptr;
            double value = strtod(token.c_str(), &endptr);
            if (*endptr == '\0') {
                operands.push(value);
            }
        }
        else if (token[0] == '*' || token[0] == '+' || token[0] == '-' || token[0] == '/')
        {
			numberOfOperator++;
            if (operands.size() < 2)
                throw std::invalid_argument("not enough digit to operate.");
            double operand2 = operands.top(); operands.pop();
            double operand1 = operands.top(); operands.pop();

            if (token == "+") {
                operands.push(operand1 + operand2);
            } else if (token == "-") {
                operands.push(operand1 - operand2);
            } else if (token == "*") {
                operands.push(operand1 * operand2);
            } else if (token == "/") {
                operands.push(operand1 / operand2);
            }
        }
        else
            throw std::invalid_argument("invalid argument.");
    }
    if (numberOfOperator + 1 == numberOfDigit)
        return operands.top();
    else
        throw std::invalid_argument("not enough operator to operate.");
}
