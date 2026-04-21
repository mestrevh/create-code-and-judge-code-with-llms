/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

typedef long long ll;

/**
 * Extended Euclidean Algorithm
 * Computes the GCD 'd' of 'a' and 'b', and finds coefficients 'x' and 'y'
 * such that a*x + b*y = d.
 * This recursive implementation simulates the back-substitution method.
 */
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    // Read the two input integers
    if (!(cin >> a >> b)) return 0;

    // Handle edge case where both are zero (GCD is undefined)
    if (a == 0 && b == 0) return 0;

    ll x, y;
    ll d = extended_gcd(a, b, x, y);

    /**
     * The standard extended_gcd finds x, y such that a*x + b*y = d.
     * The problem asks for the linear combination in the form c1*x - c2*y.
     * This means we need to represent the GCD as a difference of two positive terms.
     * In the Euclidean algorithm back-substitution, one coefficient will be 
     * non-negative and the other will be non-positive.
     */
    if (y <= 0) {
        // Case: a*x is the positive term, b*y is negative or zero.
        // x*a + y*b = d  =>  x*a - (-y)*b = d
        cout << x << "*" << a << " - " << -y << "*" << b << endl;
    } else {
        // Case: b*y is the positive term, a*x is negative or zero.
        // x*a + y*b = d  =>  y*b - (-x)*a = d
        cout << y << "*" << b << " - " << -x << "*" << a << endl;
    }

    return 0;
}