/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    int sum = 0;
    int temp = n;
    
    if (temp == 0) {
        sum = fact[0];
    } else {
        while (temp > 0) {
            sum += fact[temp % 10];
            temp /= 10;
        }
    }

    if (sum == n) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
        cout << sum << endl;
    }

    return 0;
}