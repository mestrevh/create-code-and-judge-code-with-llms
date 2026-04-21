/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    while (cin >> n) {
        if (n <= 0) {
            continue;
        }
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        if (n == 1) {
            cout << "Jolly\n";
            continue;
        }
        
        vector<bool> found(n, false);
        int count = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            long long diff = abs((long long)a[i] - (long long)a[i + 1]);
            if (diff >= 1 && diff < n && !found[diff]) {
                found[diff] = true;
                count++;
            }
        }
        
        if (count == n - 1) {
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
    }
    
    return 0;
}