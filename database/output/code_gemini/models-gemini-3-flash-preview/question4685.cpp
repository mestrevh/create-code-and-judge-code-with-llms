/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> tasks[6];
    int op;

    while (cin >> op && op != 0) {
        if (op == 1) {
            string desc;
            int prio;
            
            // cin >> ws consumes leading whitespace/newlines, including those from previous entries
            if (!(cin >> ws)) break;
            getline(cin, desc);
            
            if (!(cin >> prio)) break;
            
            if (prio >= 1 && prio <= 5) {
                tasks[prio].push_back(desc);
            }
        } else if (op == 2) {
            // According to the instruction, print a newline first
            cout << "\n";
            
            // Iterate from highest priority (1) to lowest (5)
            for (int i = 1; i <= 5; ++i) {
                // For same priority, most recent (added last) should come first (LIFO order)
                for (int j = (int)tasks[i].size() - 1; j >= 0; --j) {
                    cout << i << ". " << tasks[i][j] << "\n";
                }
            }
        }
    }

    return 0;
}