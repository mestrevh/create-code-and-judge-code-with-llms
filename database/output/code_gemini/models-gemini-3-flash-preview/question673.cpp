/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        string s;
        int x;
        if (!(cin >> s >> x)) break;

        int h = 0, m = 0;
        size_t i = 0;
        while (i < s.size() && s[i] != ':') {
            h = h * 10 + (s[i] - '0');
            i++;
        }
        i++; 
        while (i < s.size()) {
            m = m * 10 + (s[i] - '0');
            i++;
        }

        int total_mins = h * 60 + m;

        int sub_total = (total_mins - (x % 1440) + 1440) % 1440;
        int add_total = (total_mins + (x % 1440)) % 1440;

        int subH = sub_total / 60;
        int subM = sub_total % 60;
        int addH = add_total / 60;
        int addM = add_total % 60;

        cout << setfill('0') << setw(2) << subH << ":" << setw(2) << subM << " "
             << setw(2) << addH << ":" << setw(2) << addM << "\n";
    }

    return 0;
}