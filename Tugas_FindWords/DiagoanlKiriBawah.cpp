#include <iostream>
#include <string>

using namespace std;

bool FindWords(const string* matriks, int jumlahBaris, int jumlahKolom, const string& Word) {
    string WordUpper = Word;
    for (char& c : WordUpper) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }
    }

    int WordLength = WordUpper.length();

    for (int Horizontal = jumlahBaris - 1; Horizontal >= WordLength - 1; --Horizontal) {
        for (int Vertikal = jumlahKolom - 1; Vertikal >= WordLength - 1; --Vertikal) {
            bool ditemukan = true;
            for (int i = 0; i < WordLength; ++i) {
                if (matriks[Horizontal - i][Vertikal - i] != WordUpper[i]) {
                    ditemukan = false;
                    break;
                }
            }

            if (ditemukan) {
                return true;
            }
        }
    }

    return false;
}