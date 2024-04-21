#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib> // Pour strtod()

bool isInteger(std::string token)
{
    for (size_t i = 0; i < token.length(); ++i) {
        if (!isdigit(token[i])) {
            return false;
        }
    }
    // Convertir la chaîne en entier et vérifier si elle est inférieure à 10
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
            } else {
                std::cerr << "Erreur de conversion de la chaîne en double." << std::endl;
                return 0.0;
            }
        }
        else if (token[0] == '*' || token[0] == '+' || token[0] == '-' || token[0] == '/')
        {
			numberOfOperator++;
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
	if (numberOfOperator +1 != numberOfDigit)
		throw std::invalid_argument("invalid argument.");
	else
        return operands.top();
}

int main() {
    try {
        std::string expression = "3 + 4 + 2 *";
        int result = evaluateRPN(expression);
        std::cout << "Le résultat de l'expression RPN est : " << result << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
