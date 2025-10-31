/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    vector<int> series;
    series.push_back(a);
    series.push_back(b);
    
    for (int i = 2; i < n; i++) {
        int next = series[i - 1] - series[i - 2];
        series.push_back(next);
    }
    
    for (int term : series) {
        cout << term << endl;
    }
    
    return 0;
}
