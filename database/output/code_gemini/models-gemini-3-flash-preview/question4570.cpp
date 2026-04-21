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

    int n;
    if (!(cin >> n)) return 0;

    string dummy;
    getline(cin, dummy);

    for (int i = 1; i <= n; ++i) {
        string s;
        if (!getline(cin, s)) break;

        string cleaned = "";
        for (int j = 0; j < (int)s.length(); ++j) {
            char c = s[j];
            if (c >= 'a' && c <= 'z') {
                cleaned += c;
            } else if (c >= 'A' && c <= 'Z') {
                cleaned += (char)(c + 32);
            } else if (c >= '0' && c <= '9') {
                cleaned += c;
            }
        }

        bool is_pal = true;
        if (cleaned.length() < 2) {
            is_pal = false;
        } else {
            int left = 0;
            int right = (int)cleaned.length() - 1;
            while (left < right) {
                if (cleaned[left] != cleaned[right]) {
                    is_pal = false;
                    break;
                }
                left++;
                right--;
            }
        }

        cout << "Aluno " << i << ": ";
        if (is_pal) {
            cout << "Correto!, entendeu e trouxe um palindromo" << "\n";
        } else {
            cout << "Incorreto!, não entendeu o que é um palindromo" << "\n";
        }
    }

    return 0;
}