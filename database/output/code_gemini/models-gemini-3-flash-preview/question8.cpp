/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef __int128_t int128;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n_ll, m_ll;
    while (cin >> n_ll >> m_ll) {
        if (n_ll == 0 && m_ll == 0) break;
        if (n_ll == 0 || m_ll == 0) {
            cout << "0.00" << endl;
            continue;
        }

        int128 n = n_ll;
        int128 m = m_ll;
        int128 nm = n * m;
        int128 k = (n < m) ? n : m;

        // t is the sum of all values from 1 to n*m
        int128 t = nm * (nm + 1) / 2;

        // Based on test case analysis:
        // x is the sum of the diagonal starting at cell 1 (main diagonal i-j=0)
        // y is the sum of the diagonal starting at the last cell (main diagonal i-j=n-m)
        // For both cases, the sum x+y simplifies to k * (nm + 1) where k = min(n, m)
        int128 x_plus_y = k * (nm + 1);

        // a is the sum of the first column
        // a = sum_{i=1 to n} [(i-1)m + 1] = m * n(n-1)/2 + n
        int128 a = n * (m * (n - 1) + 2) / 2;

        // b is the sum of the last column
        // b = sum_{i=1 to n} [(i-1)m + m] = m * sum_{i=1 to n} i = m * n(n+1)/2
        int128 b = m * n * (n + 1) / 2;

        // c is the sum of the first row
        // c = sum_{j=1 to m} j = m(m+1)/2
        int128 c = m * (m + 1) / 2;

        // d is the sum of the last row
        // d = sum_{j=1 to m} [(n-1)m + j] = m^2(n-1) + m(m+1)/2
        int128 d = m * (2 * n * m - m + 1) / 2;

        // Formula: ( t - (x+y) + (a * b) - (c * d) ) / (n * m)
        int128 numerator = t - x_plus_y + (a * b) - (c * d);
        
        long double res = (long double)numerator / (long double)nm;

        cout << fixed << setprecision(2) << (double)res << endl;
    }

    return 0;
}