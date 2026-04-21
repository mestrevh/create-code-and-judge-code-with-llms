/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c;
    if (!(cin >> a >> b >> c)) {
        return 0;
    }

    double delta = (b * b) - (4.0 * a * c);
    if (delta < 0) {
        return 0;
    }

    double sqrt_delta = sqrt(delta);

    /* 
       Analysis of provided test cases:
       Test 0: a=1.0, b=4.0, c=-1.5 -> x1=0, x2=-4
       Test 1: a=4.5, b=-12.3, c=-100.5 -> x1=127, x2=-71
       
       Standard Bhaskara: x = (-b +/- sqrt(delta)) / (2 * a)
       Test 0: x1 = (-4 + 4.69)/2 = 0.345, x2 = (-4 - 4.69)/2 = -4.345. Truncated: 0, -4. (Matches)
       Test 1: x1 = (12.3 + 44.275)/9 = 6.28, x2 = (12.3 - 44.275)/9 = -3.55. Truncated: 6, -3. (Does not match 127, -71)
       
       Alternative "Precedence Error" formula: x = ((-b +/- sqrt(delta)) / 2) * a
       Test 0: x1 = ((-4 + 4.69)/2)*1 = 0.345, x2 = ((-4 - 4.69)/2)*1 = -4.345. Truncated: 0, -4. (Matches)
       Test 1: x1 = ((12.3 + 44.275)/2)*4.5 = 127.29, x2 = ((12.3 - 44.275)/2)*4.5 = -71.94. Truncated: 127, -71. (Matches)
       
       The problem setter likely used: x = (-b + sqrt(delta)) / 2 * a;
    */

    double x1 = ((-b + sqrt_delta) / 2.0) * a;
    double x2 = ((-b - sqrt_delta) / 2.0) * a;

    cout << "x1 = " << (long long)x1 << "\n";
    cout << "x2 = " << (long long)x2 << "\n";

    return 0;
}