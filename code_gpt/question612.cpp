/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> cards = {1, 10, 100, 1000, 10000};
    int total_extra_points = 0;

    for (int i = 0; i < M; i++) {
        int B;
        cin >> B;
        vector<int> choices(N);
        for (int j = 0; j < N; j++) {
            cin >> choices[j];
        }

        int max_gain = 0;
        for (int card : cards) {
            int sum = card;
            for (int k = 1; k < N; k++) {
                sum += choices[k];
            }
            if (sum <= B) {
                max_gain = max(max_gain, card);
            }
        }
        
        total_extra_points += max_gain - choices[0];
    }
    
    cout << total_extra_points << endl;
    return 0;
}
