/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char ch;
    vector<char> letters;
    while (cin >> ch) {
        letters.push_back(ch);
    }

    if (letters.empty()) {
        return 0;
    }

    sort(letters.begin(), letters.end());

    for (size_t i = 0; i < letters.size(); ++i) {
        cout << letters[i] << (i + 1 == letters.size() ? "" : " ");
    }
    cout << endl;

    return 0;
}