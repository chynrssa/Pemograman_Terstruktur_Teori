#include <iostream>
#include <string>
using namespace std;

bool FindWords (const string* matriks, int JumlahBaris, int JumlahKolom, const string& Word) {
    int WordLength = Word.length();

    for (int Vertikal = 0; Vertikal < JumlahKolom; ++Vertikal) {
        for (int Horizontal = 0; Horizontal <= JumlahBaris - WordLength; ++Horizontal) {
            bool ditemukan = true;
            for (int i = 0; i < WordLength; ++i) {
                if(matriks[Horizontal + i][Vertikal + i] != Word[i]) {
                    ditemukan = false;
                    break;
                }
            }
            if (ditemukan) {
                return true;
            }
        }
    }
}