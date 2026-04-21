/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int groups[20001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, city = 1;
    while (cin >> N && N != 0) {
        if (city > 1) cout << "\n";
        
        memset(groups, 0, sizeof(groups));
        long long total_x = 0;
        long long total_y = 0;
        
        for (int i = 0; i < N; i++) {
            int X, Y;
            cin >> X >> Y;
            int avg = Y / X;
            if (avg <= 20000) {
                groups[avg] += X;
            }
            total_x += (long long)X;
            total_y += (long long)Y;
        }
        
        cout << "Cidade# " << city++ << ":\n";
        
        bool first = true;
        for (int i = 0; i <= 20000; i++) {
            if (groups[i] > 0) {
                if (!first) cout << " ";
                cout << groups[i] << "-" << i;
                first = false;
            }
        }
        cout << "\n";
        
        long long total_100 = total_y * 100;
        long long avg_100 = total_100 / total_x;
        long long integral = avg_100 / 100;
        long long fractional = avg_100 % 100;
        
        cout << "Consumo medio: " << integral << "." 
             << setfill('0') << setw(2) << fractional << " m3.\n";
    }
    
    return 0;
}