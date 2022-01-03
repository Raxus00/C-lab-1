#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Functions.hpp"

std::vector<std::string> go_to_reverse(std::vector<std::string> polynom) 
{
    std::reverse(polynom.begin(),polynom.end());
    return polynom;
}


std::string derive(std::string coefficient, int index)
{
    int new_coefficient = std::stoi(coefficient) * index;
    std::string result = "";
    if(new_coefficient == 0)
    {
        result = "0";
    }
    else
    {
        result = std::to_string(new_coefficient);
        if(index != 1)
        {
            result += "*x^" + std::to_string(index - 1);
        }
        else
        {
            result += "";
        }
    }
    return result;
}

std::string calculate_derivative(std::vector<std::string> indata)
{
    int counter =0;
    std::vector<std::string> polynom;
    for(std::string part : indata)
    {
        if(part != "0")
        {
            std::string result = derive(part, counter);
            if(result !="0")
            {
                polynom.push_back(result);
            }
        }
       counter+=1;
    } 
    std::string result = "";
    for(std::string part : go_to_reverse(polynom))
    {
        result += part + " + ";
    }
    return result.erase(result.size()-3);
}

std::string integrate(std::string coefficient, int index)
{
    std::string result = "";
    int new_coefficient = std::stoi(coefficient) / (index + 1);
    if(std::stoi(coefficient) % (index + 1) == 0)
    {
        if(new_coefficient != 1.0)
        {
        result = std::to_string(new_coefficient) + "*";
        }
        else
        {
            result += "";
        }        
    }
    else
    {
        result = "(" + coefficient + "/" + std::to_string(index + 1) + ")*";
    }
    result += "x^" + std::to_string(index + 1);

    return result;      
}

std::string calculate_integral(std::vector<std::string> indata)
{
    int counter = 0;
    std::vector<std::string> polynom;
    for(std::string part : indata)
    {
        if(part !="0")
        {
            std::string result = integrate(part, counter);
            if(result !="0")
            {
                polynom.push_back(result);
            }
        }
        counter+=1;
    }
    std::string result = "";
    for(std::string part : go_to_reverse(polynom))
    {
        result += part + " + ";
    }
    return result + "C";
}