#include <iostream>
#include <string>
using namespace std;

bool FindWords (const string* matriks, int JumlahBaris, int JumlahKolom, const string& Word) {
    int WordLength = Word.length();

    for (int Horizontal = 0; Horizontal <= JumlahBaris - WordLength; ++Horizontal) {
        for (int Vertikal = JumlahKolom - 1; Vertikal >= WordLength  - 1; --Vertikal) {
            bool ditemukan = true;
            for (int i = 0; i < WordLength; ++i) {
                if (matriks[Horizontal + i][Vertikal - i] != Word[i]) {
                    ditemukan = false;
                    break;
                }
            }
            if(ditemukan) {
                return true;
            }
        }
    }
}