#include <iostream>
#include <string>
using namespace std;

bool FindWords (const string* matriks, int JumlahBaris, int JumlahKolom, const string& Word) {
    string WordUpper = Word;
    for (char& c : WordUpper) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }
    }
    
    int WordLength = WordUpper.length();

    for (int Horizontal = 0; Horizontal < JumlahBaris; ++Horizontal) {
        for (int Vertikal = 0; Vertikal <= JumlahKolom - WordLength; ++Vertikal) {
            string Potongan = matriks[Horizontal].substr(Vertikal, WordLength);
            for (char& c : Potongan) {
                if (c >= 'a' && c <= 'z') {
                    c = c - 'a' + 'A'; 
                }
            }
            if (Potongan == WordUpper){
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
            for (char& c : VertikalKata) {
                if (c >= 'a' && c <= 'z') {
                    c = c - 'a' + 'A';
                }
            }
            if (VertikalKata == WordUpper) {
                return true;
            }
        }
    }

    for (int Horizontal = 0; Horizontal <= JumlahBaris - WordLength; ++Horizontal) {
        for (int Vertikal = 0; Vertikal <= JumlahKolom - WordLength; ++Vertikal) {
            bool ditemukan = true;
            for ( int i = 0; i < WordLength; ++i){
                if (matriks[Horizontal + i][Vertikal + i] != WordUpper[i]) {
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
                if (matriks[Horizontal + i][Vertikal - i] != WordUpper[i]) {
                    ditemukan = false;
                    break;
                }
            }
            if (ditemukan) {
                return true;
            }
        }
    }

    for (int Horizontal = jumlahBaris - 1; Horizontal >= WordLength - 1; --Horizontal) {
        for (int Vertikal = 0; Vertikal <= jumlahKolom - WordLength; ++Vertikal) {
            bool ditemukan = true;
            for (int i = 0; i < WordLength; ++i) {
                if (matriks[Horizontal - i][Vertikal + i] != WordUpper[i]) {
                    ditemukan = false;
                    break;
                }
            }

            if (ditemukan) {
                return true;
            }
        }
    }

    for (int Horizontal = JumlahBaris - 1; Horizontal >= WordLength - 1; --Horizontal) {
        for (int Vertikal = JumlahKolom - 1; Vertikal >= WordLength - 1; --Vertikal) {
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

int main(){
    cout << "Tugas Find Words" << endl;
    cout << "=====================================================" << endl;
    cout << "Kelompok 4" << endl;
    cout << " Nama Anggota:" << endl;
    cout << "    1. Cahya Nerissa         2317051032\n";  
    cout << "    2. Nabila Cahaya Putri   2357051010\n";  
    cout << "    3. Ria Safitri           2317051113\n";
    cout << "====================================================="  << endl;

    int WordCount;
    cin >> WordCount;

    string* Word = new string[WordCount];
        for (int i = 0; i < WordCount; ++i) {
            cin >> Word[i];
}

    const int JumlahBaris = 23;
    const int JumlahKolom = 23;
    string matriks[JumlahBaris] = {
        "AAFLKHPFSSUFICICLESGNNH",
        "SFVREOMRWLRTTSXOQQNAOAO",
        "QEIAIFXAEIRFVFYSXIMINJI",
        "WSTRLGOCAPBIAFIWIWTUACM",
        "FEYAEAISTPCRLUJKOAKCERS",
        "RVDAKPNDDEEHDEMSNCKKFOAH",
        "MRNEDSLCRRIWNRSAAFITMMI",
        "YAAECIEAHYMOTAVHRSSTISB",
        "RJSEWELCCENNIETOHWSGLSE",
        "ATANYYMOIEESNESIOIRELTR",
        "UTENEWEBHMYBETNNRAIEBEN",
        "RCLKUTEAEQJLSGSHTGDSKOA",
        "BHOICATNRRSDDECEHOOLGIT",
        "ENSLUARIRSETALOCOHCTOHE",
        "FZFUDQJYMADOYIWYGLOVESU",
        "TEKALFWONSNAEBMIEJTZNTG",
        "ESWPOSJXEUTUYOZUWAKEZHM",
        "KZUHBPEZEERFLMSNOWBALLH",
        "NSNOWBOARDYTVWYCLEVOHSA",
        "ACOCRQLGZIYCHODRAZZILBI",
        "LBVKKWANZAAQINWOLPWONSL",
        "BFREEZINGRAINSLILGTMELT",
        "HQPYLWHFMNFFUFPSWXNUMMV"
    };

for (int i = 0; i < WordCount; ++i) {
    if (FindWords(matriks, JumlahBaris, JumlahKolom, Word[i])) {
            cout << "Ada" << endl;
        } else { 
            cout << "Tidak Ada" << endl;
        }
    }

delete[] Word;

return 0;
}
