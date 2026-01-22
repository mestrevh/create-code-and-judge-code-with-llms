/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int sumDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int X, N;
    cin >> X >> N;
    vector<pair<int, int>> channels(N);
    for (int i = 0; i < N; ++i) {
        cin >> channels[i].first >> channels[i].second;
    }
    
    int bestChannel = -1, bestMinute = -1, minDistance = INT_MAX;
    
    for (int i = 0; i < N; ++i) {
        int a = channels[i].first, b = channels[i].second;
        vector<int> seq;
        seq.push_back(a);
        seq.push_back(b);
        
        for (int j = 2; j < 100; ++j) {
            seq.push_back(seq[j-1] + seq[j-2]);
        }
        
        for (int j = 0; j < seq.size(); ++j) {
            int distance = abs(seq[j] - X);
            if (distance < minDistance || (distance == minDistance && bestChannel < i + 1)) {
                minDistance = distance;
                bestChannel = i + 1;
                bestMinute = j + 1;
            }
        }
    }
    
    bool vip = sumDigits(seq[bestMinute - 1]) > 10;

    cout << "Xupenio, para ir ao lulupalooza vc deve entrar no canal " << bestChannel 
         << " e sera chamado mais ou menos no minuto " << bestMinute 
         << (vip ? ", e com o VIP garantido!!!" : ", mas o ingresso VIP não vai rolar :(") 
         << endl;
    
    return 0;
}
