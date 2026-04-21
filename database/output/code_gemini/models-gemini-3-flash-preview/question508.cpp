/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t1, t2, t3, t4, t5;
    if (!(cin >> t1 >> t2 >> t3 >> t4 >> t5)) return 0;

    int sum = t1 + t2 + t3 + t4 + t5;
    int avg = sum / 5;
    
    long long total_seconds = (long long)avg * 100;
    
    long long hours = total_seconds / 3600;
    long long remaining_seconds = total_seconds % 3600;
    long long minutes = remaining_seconds / 60;
    long long seconds = remaining_seconds % 60;

    cout << avg << "\n";
    cout << hours << "\n";
    cout << minutes << "\n";
    cout << seconds << endl;

    return 0;
}