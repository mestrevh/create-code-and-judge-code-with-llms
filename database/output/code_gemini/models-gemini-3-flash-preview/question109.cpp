/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N) {
        vector<int> counts(10, 0);
        for (int i = 0; i < N; ++i) {
            double val;
            if (!(cin >> val)) break;
            if (val <= 1.0) counts[0]++;
            else if (val <= 2.0) counts[1]++;
            else if (val <= 3.0) counts[2]++;
            else if (val <= 4.0) counts[3]++;
            else if (val <= 5.0) counts[4]++;
            else if (val <= 6.0) counts[5]++;
            else if (val <= 7.0) counts[6]++;
            else if (val <= 8.0) counts[7]++;
            else if (val <= 9.0) counts[8]++;
            else counts[9]++;
        }

        int max_f = 0;
        for (int i = 0; i < 10; ++i) {
            if (counts[i] > max_f) max_f = counts[i];
        }

        cout << "     ^" << endl;
        for (int i = 9; i >= 0; --i) {
            if (i == 9) cout << setw(4) << 10 << " |";
            else if (i == 4) cout << setw(4) << 5 << " |";
            else cout << "     |";

            if (max_f > 0) {
                int stars = (counts[i] * 20) / max_f;
                for (int s = 0; s < stars; ++s) cout << "*";
            }
            cout << endl;
        }

        cout << setw(4) << 0 << " +----+----+----+----+>" << endl;

        int v[5];
        v[0] = 0;
        v[1] = (max_f * 1) / 4;
        v[2] = (max_f * 2) / 4;
        v[3] = (max_f * 3) / 4;
        v[4] = max_f;

        string label_line(80, ' ');
        for (int i = 0; i < 5; ++i) {
            string s = to_string(v[i]);
            int anchor = 5 + i * 5;
            for (int j = 0; j < (int)s.length(); ++j) {
                label_line[anchor - ((int)s.length() - 1 - j)] = s[j];
            }
        }
        
        while (!label_line.empty() && label_line.back() == ' ') {
            label_line.pop_back();
        }
        if (!label_line.empty()) {
            cout << label_line << endl;
        }
    }

    return 0;
}