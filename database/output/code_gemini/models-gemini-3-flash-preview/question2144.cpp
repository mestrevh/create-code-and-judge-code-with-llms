/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Process multiple test cases if provided
    while (cin >> n) {
        // Data structure to store the laboratory (array of lists/vectors)
        vector<vector<long long>> rows(n);
        for (int i = 0; i < n; ++i) {
            int row_size;
            if (!(cin >> row_size)) break;
            rows[i].resize(row_size);
            for (int j = 0; j < row_size; ++j) {
                cin >> rows[i][j];
            }
        }

        // Ritual proclamation before class starts
        cout << "Pessoal, vai ter aula de IP aqui agora" << endl;

        long long shout_count = 0;
        long long cumulative_reduction = 0;

        // Sérgio passes through each row
        for (int i = 0; i < n; ++i) {
            bool row_has_on_monitor = false;
            // Check if any computer in the current row has a monitor still on
            for (long long audacity : rows[i]) {
                if (audacity - cumulative_reduction > 0) {
                    row_has_on_monitor = true;
                    break;
                }
            }

            // If a monitor is found in this row, Sérgio shouts once
            if (row_has_on_monitor) {
                shout_count++;
                // The reduction factor increases every time he shouts
                cumulative_reduction += shout_count;
                cout << "Desliga o monitor..." << endl;
            }
        }

        // After passing all rows, count how many monitors remain on
        long long expelled_count = 0;
        for (int i = 0; i < n; ++i) {
            for (long long audacity : rows[i]) {
                if (audacity - cumulative_reduction > 0) {
                    expelled_count++;
                }
            }
        }

        // If any monitors are still on, Sérgio loses his patience
        if (expelled_count > 0) {
            cout << "Sergio pistolou e expulsou " << expelled_count << " aluno(s) do laboratorio." << endl;
        }
    }

    return 0;
}