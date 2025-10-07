/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, strings[i]);
    }

    reverse(strings.begin(), strings.end());

    for (int i = 0; i < n; ++i) {
        cout << strings[i];
    }
    cout << endl;

    return 0;
}
