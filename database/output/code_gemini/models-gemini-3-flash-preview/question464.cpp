/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long total_people = 0;
    string cmd;

    while (cin >> n) {
        total_people += (n + 1);
        if (!(cin >> cmd)) break;
        
        string upper_cmd = "";
        for (char c : cmd) {
            upper_cmd += (char)toupper((unsigned char)c);
        }
        
        if (upper_cmd == "SAIR") break;
    }

    cout << total_people << "\n";
    cout << fixed << setprecision(2) << (double)total_people * 14.0 << "\n";

    return 0;
}