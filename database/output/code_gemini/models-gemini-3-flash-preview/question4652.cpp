/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line)) {
        string_view sv(line);
        
        size_t first = sv.find_first_not_of(' ');
        if (first == string_view::npos) {
            cout << "\n";
            continue;
        }
        
        sv.remove_prefix(first);
        size_t last = sv.find_last_not_of(' ');
        if (last != string_view::npos) {
            sv.remove_suffix(sv.size() - 1 - last);
        }
        
        cout << sv << "\n";
    }

    return 0;
}