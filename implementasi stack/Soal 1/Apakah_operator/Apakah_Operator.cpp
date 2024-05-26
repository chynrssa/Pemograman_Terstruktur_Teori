#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

bool Operator(char karakter) {
    return karakter == '+' or karakter == '-' or karakter == '*' or karakter == '/' or 
                        karakter == '%' or karakter == '(' or karakter == ')';
}