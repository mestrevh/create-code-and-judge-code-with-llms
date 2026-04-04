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

    string token;
    string phrase = "";
    int wordCount = 0;
    int letterCount = 0;
    bool inWord = false;

    while (cin >> token && token != "fim") {
        if (token == "-") {
            phrase += " ";
            inWord = false;
        } else {
            phrase += token;
            letterCount++;
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        }
    }

    cout << "A palavra é: " << phrase << "\n";
    cout << "Ela tem " << wordCount << " palavras\n";
    cout << "Ela tem " << letterCount << " letras\n";

    return 0;
}