/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int backtrack(int idx, int cnt, int total, const vector<int>& prices, int M, int Q) {
    if (total > Q) return 0;
    if (cnt >= M) return (total <= Q) ? 1 : 0;
    if (idx >= prices.size()) return 0;

    int include = backtrack(idx + 1, cnt + 1, total + prices[idx], prices, M, Q);
    int exclude = backtrack(idx + 1, cnt, total, prices, M, Q);

    return include + exclude;
}

int main() {
    string line;
    int K;
    getline(cin, line);
    K = stoi(line);
    getline(cin, line); // blank line

    for (int case_num = 0; case_num < K; ++case_num) {
        int L;
        vector<int> prices;

        getline(cin, line);
        L = stoi(line);
        getline(cin, line);
        istringstream iss(line);
        prices.resize(L);
        for (int i = 0; i < L; ++i) {
            iss >> prices[i];
        }
        int M, Q;
        getline(cin, line);
        istringstream iss2(line);
        iss2 >> M >> Q;
        getline(cin, line); // blank line

        int result = backtrack(0, 0, 0, prices, M, Q);
        cout << "caso " << case_num << ": " << result << endl;
    }
    return 0;
}
