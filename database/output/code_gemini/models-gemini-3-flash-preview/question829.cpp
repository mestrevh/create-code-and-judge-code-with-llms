/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<char> letters(5);
    for (int i = 0; i < 5; ++i) {
        if (!(cin >> letters[i])) break;
    }

    sort(letters.begin(), letters.end());

    bool is_continuous = true;
    for (int i = 1; i < 5; ++i) {
        if (letters[i] != letters[i - 1] + 1) {
            is_continuous = false;
            break;
        }
    }

    if (is_continuous) {
        cout << "sim" << endl;
    } else {
        cout << "nao" << endl;
    }

    return 0;
}