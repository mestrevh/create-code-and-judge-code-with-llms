/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> times(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> times[i];
    }
    
    int totalTime = 0;
    int lastActive = times[0];
    
    for (int i = 1; i < N; ++i) {
        if (times[i] > lastActive + 10) {
            totalTime += 10;
        } else {
            totalTime += times[i] - lastActive;
        }
        lastActive = times[i];
    }
    
    totalTime += 10; // Last person keeps it running for additional 10 seconds
    
    cout << totalTime << endl;
    return 0;
}
