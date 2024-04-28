#include <iostream>
#include <string>

using namespace std;

bool FindWords(const string* matriks, int JumlahBaris, int JumlahKolom, const string& Word) {
    string WordUpper = Word;
    for (char& c : WordUpper) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }
    }
}