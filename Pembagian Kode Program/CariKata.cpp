#include <iostream>
#include <string>
using namespace std;

for (int i = 0; i < WordCount; ++i){
    if(FindWords(matriks, JumlahBaris, JumlahKolom, Word[i])) {
        cout << "Ada" << endl;
    } else {
        cout << "Tidak Ada" << endl;
    }


    delete[] Word;

    return 0;
}