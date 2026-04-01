/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    int mid = n / 2;
    long long sum1 = 0;
    long long sum2 = 0;

    for (int i = 0; i < mid; ++i) {
        sum1 += (s[i] - '0');
    }
    for (int i = mid; i < n; ++i) {
        sum2 += (s[i] - '0');
    }

    if (sum1 == sum2) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}