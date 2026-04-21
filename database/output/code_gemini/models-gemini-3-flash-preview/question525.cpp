/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

struct Reversal {
    int i, j;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, caseNum = 1;
    while (cin >> N && N != 0) {
        int R;
        if (!(cin >> R)) break;
        
        vector<Reversal> revs(R);
        for (int k = 0; k < R; ++k) {
            cin >> revs[k].i >> revs[k].j;
        }

        int Q;
        if (!(cin >> Q)) break;
        
        cout << "Genome " << caseNum++ << "\n";
        for (int k = 0; k < Q; ++k) {
            int gene;
            cin >> gene;
            
            int pos = gene;
            for (int m = 0; m < R; ++m) {
                if (pos >= revs[m].i && pos <= revs[m].j) {
                    pos = revs[m].i + revs[m].j - pos;
                }
            }
            cout << pos << "\n";
        }
    }

    return 0;
}