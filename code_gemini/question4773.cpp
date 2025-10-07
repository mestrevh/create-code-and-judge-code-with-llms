/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int d, m, y;
    char slash;
    cin >> d >> slash >> m >> slash >> y;

    int n;
    cin >> n;

    int days = 0;
    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        if (q % 2 != 0 && is_prime(q)) {
            days -= q;
        } else {
            days += q;
        }
    }

    if (days < 0) {
        cout << "Matheusinho precisa parar AGORA ou vai de F" << endl;
    } else {
        cout << "Matheusinho tem " << days << " dias pra se recuperar" << endl;

        int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            days_in_month[2] = 29;
        }
        
        for (int i = 0; i < days; ++i) {
            d++;
            if (d > days_in_month[m]) {
                d = 1;
                m++;
                if (m > 12) {
                    m = 1;
                    y++;
                    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
                        days_in_month[2] = 29;
                    } else {
                         days_in_month[2] = 28;
                    }
                }
            }
        }

        cout << "Se não vai de F em " << setfill('0') << setw(2) << d << "/" << setfill('0') << setw(2) << m << "/" << y << endl;
    }

    return 0;
}
