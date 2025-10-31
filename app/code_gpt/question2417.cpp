/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string S1, S2, S3, S4;
    cin >> S1 >> S2 >> S3 >> S4;

    if (S1 == "Carne" && S2 == "Bamboo" && S3 == "Shoyu" && S4 == "Ovo") {
        cout << "Luffy - ¥475" << endl;
    } else if (S1 == "Carne" && S2 == "Bamboo" && S3 == "Nori" && S4 == "Ovo") {
        cout << "Kirito - ¥450" << endl;
    } else if (S1 == "Carne" && S2 == "Cebolinha" && S3 == "Kimushi" && S4 == "Nori") {
        cout << "Misty - ¥600" << endl;
    } else if (S1 == "Carne" && S2 == "Bamboo" && S3 == "Sal" && S4 == "Ovo") {
        cout << "Naruto - ¥500" << endl;
    } else {
        cout << "Está tentando inventar um novo prato? O chef aqui sou eu!" << endl;
    }

    return 0;
}
