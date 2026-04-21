/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    
    int n = num1.size();
    int m = num2.size();
    vector<int> res(n + m, 0);
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int sum = mul + res[p2];
            
            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }
    
    string result = "";
    for (int p : res) {
        if (!(result.empty() && p == 0)) {
            result.push_back(p + '0');
        }
    }
    
    return result.empty() ? "0" : result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a, b;
    if (!(cin >> a)) return 0;
    if (!(cin >> b)) {
        // In case B is not provided or on the same line handled by cin
    }
    
    cout << multiply(a, b) << "\n";
    
    return 0;
}