#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
#include <stack>
#include <string>

using namespace std;

bool Operator(char karakter) {
    return karakter == '+' or karakter == '-' or karakter == '*' or karakter == '/' or 
                        karakter == '%' or karakter == '(' or karakter == ')';
}

bool Digit(char karakter) {
    return isdigit(karakter);
}
