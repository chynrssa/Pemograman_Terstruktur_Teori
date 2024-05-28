#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

vector<string> tokenize(const string &infix) {
    vector<string> token;
}
void cetakToken(const vector<string> &token) {
    for (size_t i = 0; i < token.size(); ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << token[i];
    }
    cout << "\n";
}