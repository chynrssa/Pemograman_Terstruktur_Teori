#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

bool Operator(char karakter) {
    return karakter == '+' or karakter == '-' or karakter == '*' or karakter == '/' or 
                        karakter == '%' or karakter == '(' or karakter == ')';
}

bool Digit(char karakter) {
    return isdigit(karakter);
}

vector<string> strToInfix(const string &infix) {
    vector<string> token;
    stringstream pengumpulString;
    bool sebelumnyaoperator = true, karakterPertama = true;

    for (size_t i = 0; i < infix.size(); ++i) {
        char karakter = infix[i];

        if (Digit(karakter)) {
            pengumpulString << karakter;
            sebelumnyaoperator = false;
            karakterPertama = false;
        } else if (Operator(karakter)) {
            if (pengumpulString.str().length() > 0) {
                token.push_back(pengumpulString.str());
                pengumpulString.str("");
            }

            if (karakter == '-' and (sebelumnyaoperator or (i > 0 and infix[i - 1] == '('))) {
                if (karakterPertama and i + 1 < infix.size() and infix[i + 1] == '(') {
                    token.push_back("-1");
                    token.push_back("*");
                } else if (karakterPertama) {
                    pengumpulString << karakter;
                    karakterPertama = false;
                } else {
                    token.push_back("-1");
                    token.push_back("*");
                }
            } else {
                token.push_back(string(1, karakter));
            }
            sebelumnyaoperator = (karakter != ')');
            karakterPertama = false;
        } else if (karakter == ' ') {
            if (pengumpulString.str().length() > 0) {
                token.push_back(pengumpulString.str());
                pengumpulString.str("");
            }
        }
    }
    if (pengumpulString.str().length() > 0) {
        token.push_back(pengumpulString.str());
    }
    return token;
}