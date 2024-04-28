#include <iostream>
#include <string>
using namespace std;

bool FindWords (const string* matriks, int JumlahBaris, int JumlahKolom, const string& Word) {
    int WordLength = Word.length();

    for (int Horizontal = 0; Horizontal < JumlahBaris; ++Horizontal) {
        for (int Vertikal = 0; Vertikal <= JumlahKolom - WordLength; ++Vertikal) {
            string Potongan = matriks[Horizontal].substr(Vertikal, WordLength);
            if (Potongan == Word){
                return true;
            }
        }
    }
    
    for (int Vertikal = 0; Vertikal < JumlahKolom; ++Vertikal) {
        for (int Horizontal = 0; Horizontal <= JumlahBaris - WordLength; ++Horizontal) {
            string VertikalKata = "";
            for (int i = 0; i < WordLength; ++i) {
                VertikalKata += matriks[Horizontal + i][Vertikal];
            }
            if (VertikalKata == Word) {
                return true;
            }
        }
    }

    for (int Horizontal = 0; Horizontal <= JumlahBaris - WordLength; ++Horizontal) {
        for (int Vertikal = 0; Vertikal <= JumlahKolom - WordLength; ++Vertikal) {
            bool ditemukan = true;
            for ( int i = 0; i < WordLength; ++i){
                if (matriks[Horizontal + i][Vertikal + i] != Word[i]) {
                    ditemukan = false;
                    break;
                }
            }
            if (ditemukan) {
                return true;
            }
        }
    }

    for (int Horizontal = 0; Horizontal <= JumlahBaris - WordLength; ++Horizontal) {
        for (int Vertikal = JumlahKolom - 1; Vertikal >= WordLength - 1; --Vertikal) {
            bool ditemukan = true;
            for ( int i = 0; i < WordLength; ++i){
                if (matriks[Horizontal + i][Vertikal - i] != Word[i]) {
                    ditemukan = false;
                    break;
                }
            }
            if (ditemukan) {
                return true;
            }
        }
    }   
return 0;
}