#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac < 2)
        return (std::cout << "Error: invalid format, ex: ./RPN value value ..." << std::endl, -1);
    try {
            int result = evaluateRPN(av[1]);
            std::cout << "Le résultat de l'expression RPN est : " << result << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
