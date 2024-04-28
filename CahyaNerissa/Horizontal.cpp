#include <iostream>
#include <string>
using namespace std;

bool FindWords (const string* matriks, int JumlahBaris, int JumlahKolom, const string& Word) {
    int WordLength = Word.length();

    for (int Horizontal = 0; Horizontal < JumlahBaris; ++Horizontal) {
        for (int Vertikal = 0; Vertikal <= JumlahKolom - WordLength; ++Vertikal) {
            string Potongan = matriks[Horizontal].substr(Vertikal, WordLength);
            if (Potongan == Word) {
                return true;
            }
        }
    }
}