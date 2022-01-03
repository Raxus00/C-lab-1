#include <iostream>
#include <vector>
#include <string>
#include "Functions.hpp"


int main(int argc, char* argv[])
{
    std::vector<std::string> args; 
    for(int i = 0; i < argc; ++i)
    { 
        args.push_back(argv[i]); 
    }
    std::vector<std::string> coefficients(args.begin() + 2, args.end()); 

    if(argc < 3)
    {
        std::cout << "Too few arguments passed" << std::endl;
    }
    else if (args[1] == "-i" || args[1] == "-I")
    {
        std::cout << calculate_integral(coefficients)<< std::endl;
    }
    else if(args[1] == "-d" || args[1] == "-D")
    {
        std::cout << calculate_derivative(coefficients) << std::endl;
    }
    else
    {
        std::cout << "Unknown type flag:" , std::cout << args[1];
    }
    
}

