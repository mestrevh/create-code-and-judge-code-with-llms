/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int sum_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int x, n;
    cin >> x >> n;

    int best_channel = -1;
    int best_minute = -1;
    int min_diff = -1;

    for (int channel = 1; channel <= n; ++channel) {
        int a, b;
        cin >> a >> b;

        vector<int> seq;
        seq.push_back(a);
        seq.push_back(b);

        for (int i = 3; ; ++i) {
            int next = seq[i - 2] + seq[i - 3];
            seq.push_back(next);
            if (next > 2 * x) break;
        }

        for (int i = 0; i < seq.size(); ++i) {
            int diff = abs(x - seq[i]);
            if (best_channel == -1 || diff < min_diff || (diff == min_diff && channel > best_channel)) {
                best_channel = channel;
                best_minute = i + 1;
                min_diff = diff;
            }
        }
    }
    
    int a,b;
    
    vector<int> seq_best;
    if (best_channel != -1){
        int best_val;
        if (best_channel == 1){
            int a1, b1;
             cin >> a1 >> b1;
             cin >> a >> b;

            seq_best.push_back(a1);
            seq_best.push_back(b1);
            
             for (int i = 3; ; ++i) {
                int next = seq_best[i - 2] + seq_best[i - 3];
                seq_best.push_back(next);
                if (next > 2 * x) break;
             }
             best_val = seq_best[best_minute - 1];
            
        } else {
            int a1, b1;
            cin >> a >> b;
             cin >> a1 >> b1;

            seq_best.push_back(a);
            seq_best.push_back(b);

             for (int i = 3; ; ++i) {
                int next = seq_best[i - 2] + seq_best[i - 3];
                seq_best.push_back(next);
                if (next > 2 * x) break;
             }
             best_val = seq_best[best_minute - 1];
        }


        if (sum_digits(best_val) > 10) {
            cout << "Xupenio, para ir ao lulupalooza vc deve entrar no canal " << best_channel << " e sera chamado mais ou menos no minuto " << best_minute << " e com o VIP garantido!!!" << endl;
        } else {
            cout << "Xupenio, para ir ao lulupalooza vc deve entrar no canal " << best_channel << " e sera chamado mais ou menos no minuto " << best_minute << ", mas o ingresso VIP não vai rolar :(" << endl;
        }

    }

    return 0;
}
`