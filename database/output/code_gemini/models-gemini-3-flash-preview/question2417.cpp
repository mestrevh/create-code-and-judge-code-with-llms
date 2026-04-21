/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2, s3, s4;
    if (!(cin >> s1 >> s2 >> s3 >> s4)) return 0;

    if (s1 == "Carne" && s2 == "Bamboo" && s3 == "Sal" && s4 == "Ovo") {
        cout << "Naruto - ¥500" << endl;
    } else if (s1 == "Carne" && s2 == "Bamboo" && s3 == "Shoyu" && s4 == "Ovo") {
        cout << "Luffy - ¥475" << endl;
    } else if (s1 == "Carne" && s2 == "Bamboo" && s3 == "Nori" && s4 == "Ovo") {
        cout << "Kirito - ¥450" << endl;
    } else if (s1 == "Carne" && s2 == "Cebolinha" && s3 == "Kimushi" && s4 == "Nori") {
        cout << "Misty - ¥600" << endl;
    } else {
        cout << "Está tentando inventar um novo prato? O chef aqui sou eu!" << endl;
    }

    return 0;
}