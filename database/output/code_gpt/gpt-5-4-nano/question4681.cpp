/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> pieces(n);
    for (int i = 0; i < n; i++) cin >> pieces[i];

    int a, b;
    cin >> a >> b; // open ends in increasing order (a <= b)
    string s;
    cin >> s;

    string code = s.substr(0, s.size() - 6);
    string num = s.substr(s.size() - 6, 6);
    int num1 = stoi(num.substr(0, 3));
    int num2 = stoi(num.substr(3, 3));
    if (num2 == 0) num2 = 1;
    int x = num1 / num2;

    auto hasPiece = [&](int val) -> bool {
        return binary_search(pieces.begin(), pieces.end(), val);
    };

    bool possible = false;

    if (code == "manbr") {
        int left = a, right = b;
        if (left == x && right == x) possible = hasPiece(x);
        else if (left == x) possible = hasPiece(right);
        else if (right == x) possible = hasPiece(left);
        else possible = false;
    } else if (code == "rpf") {
        possible = hasPiece(x);
    } else if (code == "rrs") {
        bool need = (a != x) && (b != x);
        if (need) possible = hasPiece(x);
        else {
            if (a == x) possible = hasPiece(b);
            else possible = hasPiece(a);
        }
    } else if (code == "dsfs") {
        possible = true;
    }

    if (possible) cout << "ai maezinha\n";
    else cout << "cade o douze\n";

    return 0;
}