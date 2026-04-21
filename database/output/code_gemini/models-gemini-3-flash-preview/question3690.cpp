/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

bool is_perfect_square(ll n) {
    if (n < 0) return false;
    if (n == 0) return true;
    ll r = (ll)round(sqrt((double)n));
    return r * r == n;
}

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int sum_digits(ll n) {
    if (n < 0) n = -n;
    int s = 0;
    while (n > 0) {
        s += (int)(n % 10);
        n /= 10;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    ll score_a = 0, score_b = 0;
    for (int i = 0; i < n; ++i) {
        string a_str, b_str;
        cin >> a_str >> b_str;

        ll sum_a = 0;
        for (char c : a_str) {
            sum_a += (c - '0');
        }
        // Rule: The team scores if the number of divisors of the sum of digits is even.
        // The number of divisors D(x) is even if and only if x is not a perfect square.
        if (!is_perfect_square(sum_a)) {
            score_a++;
        }

        ll sum_b = 0;
        for (char c : b_str) {
            sum_b += (c - '0');
        }
        if (!is_perfect_square(sum_b)) {
            score_b++;
        }
    }

    // Apply special prime adjustment rules to the team scores.
    int s_score_a = sum_digits(score_a);
    if (s_score_a == 2) {
        score_a -= 4;
    } else if (is_prime(s_score_a)) {
        score_a += 3;
    }

    int s_score_b = sum_digits(score_b);
    if (s_score_b == 2) {
        score_b -= 4;
    } else if (is_prime(s_score_b)) {
        score_b += 3;
    }

    // If scores are equal at the end, one team gets an extra point.
    if (score_a == score_b) {
        score_a += 1;
    }

    ll diff = score_a - score_b;
    if (diff < 0) diff = -diff;

    cout << "Quem ganhou foi aquele time." << endl;
    cout << diff << endl;

    return 0;
}