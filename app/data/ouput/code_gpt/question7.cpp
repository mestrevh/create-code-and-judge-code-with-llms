/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double num1, num2, result;
    char op;

    cin >> num1 >> num2 >> op;
    result = (op == '+') ? num1 + num2 :
             (op == '-') ? num1 - num2 :
             (op == '*') ? num1 * num2 :
             (op == '/' && num2 != 0) ? num1 / num2 : (cout << "operacao nao pode ser realizada" << endl, return 0);

    cout << fixed << setprecision(3) << result << endl;

    while (true) {
        double nextNum;
        char nextOp;
        cin >> nextNum >> nextOp;
        if (nextOp == '&') break;

        if (nextOp == '+') result += nextNum;
        else if (nextOp == '-') result -= nextNum;
        else if (nextOp == '*') result *= nextNum;
        else if (nextOp == '/' && nextNum != 0) result /= nextNum;
        else {
            cout << "operacao nao pode ser realizada" << endl;
            continue;
        }
        
        cout << fixed << setprecision(3) << result << endl;
    }

    return 0;
}
