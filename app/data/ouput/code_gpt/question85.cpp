/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, int> evaluateGuess(const string& password, const string& guess) {
    int excellent = 0, good = 0;
    vector<bool> password_used(password.length(), false);
    vector<bool> guess_used(guess.length(), false);

    for (int i = 0; i < password.length(); ++i) {
        if (guess[i] == password[i]) {
            excellent++;
            password_used[i] = true;
            guess_used[i] = true;
        }
    }

    for (int i = 0; i < guess.length(); ++i) {
        if (!guess_used[i]) {
            for (int j = 0; j < password.length(); ++j) {
                if (guess[i] == password[j] && !password_used[j]) {
                    good++;
                    password_used[j] = true;
                    break;
                }
            }
        }
    }

    return make_pair(excellent, good);
}

int main() {
    int K;
    cin >> K;
    while (K--) {
        int N;
        cin >> N;
        string password;
        cin >> password;

        string guess;
        while (true) {
            cin >> guess;
            if (guess == string(N, '0')) break;

            auto result = evaluateGuess(password, guess);
            cout << "(" << result.first << "," << result.second << ")" << endl;
        }
    }
    return 0;
}
