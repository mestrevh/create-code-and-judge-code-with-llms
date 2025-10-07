/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int ambrosio, guess;
    cin >> ambrosio;
    vector<int> guesses;

    while (true) {
        cin >> guess;
        if (guess == ambrosio) {
            cout << "Voce bebe!" << endl;
            break;
        }
        
        guesses.push_back(guess);
        sort(guesses.begin(), guesses.end());

        if (find(guesses.begin(), guesses.end(), ambrosio) != guesses.end() ||
            (guesses.size() > 1 && ambrosio > guesses.front() && ambrosio < guesses.back())) {
            cout << "Ambrosio bebe!" << endl;
            break;
        }
        
        if (guess < ambrosio) {
            cout << "Escolha um numero entre " << (guesses.empty() ? 0 : guesses.back()) << " e " << (guesses.empty() ? 100 : guesses.front()) << "!" << endl;
        } else {
            cout << "Escolha um numero entre " << (guesses.empty() ? 0 : guesses.front()) << " e " << (guesses.empty() ? 100 : guesses.back()) << "!" << endl;
        }
    }

    return 0;
}
