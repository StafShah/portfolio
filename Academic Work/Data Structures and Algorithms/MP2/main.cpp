/*Mustafa Shah*/
#include <iostream>
#include <string>
#include "mystack.h"

using namespace std;

bool pattern1(const string& s) {
    
    char delimiter = '#';
    
    if (s.empty()) {
        return false;
    }
    
    myStack<char> matchedChars(s.length());
    bool passedDelimiter = false;

    
    for (char c: s) {
        if (!passedDelimiter) {
            if (c != delimiter) {
                matchedChars.push(c);
            } else {
                passedDelimiter = true;
            }
        } else {
            char currS = matchedChars.top();
            if (!matchedChars.empty() && c == currS) {
                matchedChars.pop();
                continue;
            } else {
                return false;
            }
        }
        
    }
    
    if (matchedChars.empty()) {
        return true;
    }
    
    return false;
}

char digitToChar(int digit) {
    if (digit >= 0 && digit <= 9)
        return digit + '0';
    else
        return digit - 10 + 'A';
}

void multibaseOutput(int number, int base) {
    if (number == 0) {
        cout << "0 base " << base << " is 0" << endl;
        return;
    }

    myStack<char> stack(32); 
    int temp = number;

    while (temp != 0) {
        int remainder = temp % base;
        stack.push(digitToChar(remainder));
        temp /= base;
    }

    cout << number << " base " << base << " is ";
    while (!stack.empty()) {
        cout << stack.top();
        stack.pop();
    }
    cout << endl;
}

void rpnCalculator(const string& expression) {
    myStack<int> stack(expression.length());
    for (char c : expression) {
        if (isdigit(c)) {
            stack.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();
            switch (c) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                default:
                    cout << "Invalid operator: " << c << endl;
                    return;
            }
        }
    }
    cout << "Result: " << stack.top() << endl;
}

int main()
{
    while (true) {
        string input;
        cout << "Input a string: ";
        getline(cin, input);
        
        if (input.length() == 0) {
            break;
        }
        
        if (pattern1(input)) {
            cout << input << " matches the pattern." << endl;
        } else {
            cout << input << " does not match the pattern." << endl;
        }
    }
    
    while (true) {
        int number, base;
        cout << "Enter a non-negative decimal number and base" << endl;
        cout << "(2 <= B <= 16)" << endl;
        cout << "or 0 0 to terminate: ";
        cin >> number >> base;

        if (number == 0 && base == 0)
            break;

        if (base < 2 || base > 16) {
            cout << "Invalid base. Base should be between 2 and 16." << endl;
            continue;
        }

        multibaseOutput(number, base);
    }
    
    string expression;
    cout << "Enter an expression in Reverse Polish Notation (RPN): ";
    cin.ignore();
    getline(cin, expression);
    rpnCalculator(expression);

    return 0;
}