#include <cmath>
#include <iostream>
#include <string>
#include "calculator.h"

bool ReadNumber(Number& result) {
    std::cin >> result;

    if (std::cin.fail()) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
    return true;
}

bool RunCalculatorCycle() {
    Number start_number = 0;
    
    if (!ReadNumber(start_number)) {
        return false;
    }
    
    std::string input;
    Number number = 0;
    Number save_number = 0;
    bool isSave = false;
    
    while (!std::cin.fail()) {
        std::cin >> input;
        
        if (input == "q") {
            break;
        } else if (input == "c") {
              start_number = 0;
        } else if(input == "s") {
            save_number = start_number;
            isSave = true;
        } else if(input == "l") {
            if(isSave) {
                start_number = save_number;
            } else {
                std::cerr << "Error: Memory is empty" << std::endl;
                break;
            }
        } else if (input == "=") {
              std::cout << start_number << std::endl;
        } else if (input == ":") {
            if(!ReadNumber(number)) {
                break;
            } else {
                start_number = number;
                }
        } else if (input == "+") {
            if(!ReadNumber(number)) {
                break;
            } else {
                start_number += number;
            }
        } else if (input == "-") {
            if(!ReadNumber(number)) {
                break;
            } else {
                start_number -= number;
            }
        } else if (input == "/") {
            if(!ReadNumber(number)) {
                break;
            } else {
                start_number /= number;
            }
        } else if (input == "**") {
            if(!ReadNumber(number)) {
                break;
            } else {
                start_number = pow(start_number, number);
            }
        } else if(input == "*") {
            if(!ReadNumber(number)) {
                break;
            } else {
                start_number *= number;
            }
        } else {
            std::cerr << "Error: Unknown token " << input << std::endl;
            break;
        }
    }
    return true;
}

