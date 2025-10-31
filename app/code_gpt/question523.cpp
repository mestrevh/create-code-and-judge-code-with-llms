/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        unordered_map<string, int> dict;
        for (int i = 0; i < N; i++) {
            string word;
            int time;
            cin >> word >> time;
            dict[word] = time;
        }
        int M;
        cin >> M;
        cin.ignore();
        stringstream ss;
        string S;
        getline(cin, S);
        int total_time = 0;
        istringstream words(S);
        for (string word; words >> word; ) {
            total_time += dict[word];
        }
        cout << "Caso " << t << ": " << total_time << endl;
    }
    return 0;
}
