/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int get_sum_of_squares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<bool> seen(1001, false);
    
    int current = n;
    while (current != 1) {
        if (current <= 1000) {
            if (seen[current]) {
                cout << "N" << endl;
                return 0;
            }
            seen[current] = true;
        }
        
        current = get_sum_of_squares(current);
        
        // After the first iteration, the sum of squares for N <= 1000 
        // will always be <= 243 (for 999), so current will stay <= 1000.
    }

    cout << "S" << endl;

    return 0;
}