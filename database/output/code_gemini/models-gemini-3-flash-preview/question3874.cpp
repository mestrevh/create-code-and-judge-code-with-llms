/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

struct CinCabeca {
    int age;
    long long id;
    string name;
    int points;

    CinCabeca() : points(0) {}
};

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool is_perfect_square(long long n) {
    if (n < 0) return false;
    long long root = (long long)(sqrt((long double)n) + 0.5);
    return root * root == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    CinCabeca h1, h2;

    if (!(cin >> h1.age >> h1.id >> h1.name)) return 0;
    if (!(cin >> h2.age >> h2.id >> h2.name)) return 0;

    // Rule 1: Name alphabetically larger (higher lexicographical value)
    if (h1.name > h2.name) {
        h1.points += 2;
    } else if (h2.name > h1.name) {
        h2.points += 2;
    }

    // Rule 2: Age is a prime number
    if (is_prime(h1.age)) {
        h1.points += 4;
    }
    if (is_prime(h2.age)) {
        h2.points += 4;
    }

    // Rule 3: ID is a perfect square
    if (is_perfect_square(h1.id)) {
        h1.points += 3;
    }
    if (is_perfect_square(h2.id)) {
        h2.points += 3;
    }

    // Determine the winner
    if (h1.points > h2.points) {
        cout << h1.name << " WINS" << endl;
    } else if (h2.points > h1.points) {
        cout << h2.name << " WINS" << endl;
    } else {
        cout << "CInCABECAS EMPATADOS" << endl;
    }

    return 0;
}