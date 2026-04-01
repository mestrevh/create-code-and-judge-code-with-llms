/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Standard loop to handle potential multiple test cases or end of input
    while (cin >> N) {
        vector<int> vec(N);
        for (int i = 0; i < N; ++i) {
            if (!(cin >> vec[i])) break;
        }

        char cmd;
        // Pointer tracks the index currently "at the top"
        int pos = 0;
        while (cin >> cmd) {
            if (cmd == 'S') {
                long long V_after_S;
                // According to rules, S is followed by a value that can be ignored
                if (cin >> V_after_S) {}
                break;
            }
            
            long long V;
            if (!(cin >> V)) break;
            
            if (cmd == 'D') {
                // Rotating dial clockwise (D) moves the pointer counter-clockwise 
                // relative to the indices of the values.
                pos = (int)((pos - (V % N) + N) % N);
            } else if (cmd == 'E') {
                // Rotating dial counter-clockwise (E) moves the pointer clockwise
                // relative to the indices of the values.
                pos = (int)((pos + (V % N)) % N);
            }

            // Output the entire roulette starting from the current pointer position in clockwise order
            for (int i = 0; i < N; ++i) {
                // Each number followed by a space
                cout << vec[(pos + i) % N] << " ";
            }
            // Final space then a newline as per problem specification
            cout << "\n";
        }
    }

    return 0;
}