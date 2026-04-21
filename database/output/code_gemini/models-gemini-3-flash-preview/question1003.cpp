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

    int first_drawn;
    while (cin >> first_drawn) {
        bool is_drawn[51] = {false};
        if (first_drawn >= 1 && first_drawn <= 50) {
            is_drawn[first_drawn] = true;
        }
        for (int i = 1; i < 10; ++i) {
            int val;
            cin >> val;
            if (val >= 1 && val <= 50) {
                is_drawn[val] = true;
            }
        }

        int N;
        if (!(cin >> N)) break;

        vector<string> buckets[11];
        int max_m = -1;
        int min_m = 11;

        for (int i = 0; i < N; ++i) {
            string id;
            cin >> id;
            int matches = 0;
            for (int j = 0; j < 15; ++j) {
                int num;
                cin >> num;
                if (num >= 1 && num <= 50 && is_drawn[num]) {
                    matches++;
                }
            }
            buckets[matches].push_back(id);
            if (matches > max_m) max_m = matches;
            if (matches < min_m) min_m = matches;
        }

        if (max_m != -1) {
            cout << "Faixa: " << max_m << (max_m == 1 ? " acerto" : " acertos") << "\n";
            for (const string& s : buckets[max_m]) {
                cout << s << "\n";
            }
            cout << buckets[max_m].size() << (buckets[max_m].size() == 1 ? " ganhador" : " ganhadores") << "\n";
        }

        if (max_m != -1 && min_m != 11) {
            cout << "\n";
        }

        if (min_m != -1) {
            cout << "Faixa: " << min_m << (min_m == 1 ? " acerto" : " acertos") << "\n";
            for (const string& s : buckets[min_m]) {
                cout << s << "\n";
            }
            cout << buckets[min_m].size() << (buckets[min_m].size() == 1 ? " ganhador" : " ganhadores") << "\n";
        }
    }

    return 0;
}