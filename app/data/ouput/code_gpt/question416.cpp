/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string convertToBase(int num, int base) {
    string result;
    const char digits[] = "0123456789ABCDEF";
    stack<char> s;
    
    while (num > 0) {
        s.push(digits[num % base]);
        num /= base;
    }
    
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    
    return result.empty() ? "0" : result;
}

int main() {
    int n;
    cin >> n;
    vector<string> results;
    
    for (int i = 0; i < n; i++) {
        int x, b;
        cin >> x >> b;
        results.push_back(convertToBase(x, b));
    }
    
    for (const auto& res : results)
        cout << res << endl;

    return 0;
}
