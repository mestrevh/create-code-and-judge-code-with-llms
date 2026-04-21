/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Optimized primality test
bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string date_str;
    if (!(cin >> date_str)) return 0;

    // Parse date in format dd/mm/aaaa
    // substr(start, length)
    int d = stoi(date_str.substr(0, 2));
    int m = stoi(date_str.substr(3, 2));
    int a = stoi(date_str.substr(6, 4));

    int n;
    if (!(cin >> n)) return 0;

    long long y = 0;
    for (int i = 0; i < n; ++i) {
        long long q;
        if (!(cin >> q)) break;
        // Logic: if Q is odd and prime, lose Q days, else gain Q days
        if (q % 2 != 0 && is_prime(q)) {
            y -= q;
        } else {
            y += q;
        }
    }

    if (y < 0) {
        cout << "Matheusinho precisa parar AGORA ou vai de F" << endl;
    } else {
        // Output based on Test Case format (more reliable than description text)
        cout << "Matheusinho tem " << y << " dias pra se recuperar" << endl;

        // Calendar logic: 1 month = 30 days, 1 year = 12 months
        // Using long long for all calculations to prevent overflow
        long long total_d = (long long)d + y;
        long long total_m = (long long)m + (total_d - 1) / 30;
        long long fin_d = (total_d - 1) % 30 + 1;
        long long fin_m = (total_m - 1) % 12 + 1;
        long long fin_a = (long long)a + (total_m - 1) / 12;

        cout << "Se não vai de F em " << fin_d << "/" << fin_m << "/" << fin_a << endl;
    }

    return 0;
}