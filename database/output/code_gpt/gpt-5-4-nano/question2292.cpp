/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TPilha {
    vector<T> a;
public:
    void push(const T& x) { a.push_back(x); }
    void pop() { if (!a.empty()) a.pop_back(); }
    T top() const { return a.back(); }
    bool empty() const { return a.empty(); }
    size_t size() const { return a.size(); }
};

char* hexadecimal(int n) {
    TPilha<char> p;
    if (n == 0) {
        char* s = (char*)malloc(2);
        s[0] = '0';
        s[1] = '\0';
        return s;
    }
    const char* digits = "0123456789ABCDEF";
    while (n > 0) {
        int r = n % 16;
        p.push(digits[r]);
        n /= 16;
    }
    char* s = (char*)malloc(p.size() + 1);
    size_t i = 0;
    while (!p.empty()) {
        s[i++] = p.top();
        p.pop();
    }
    s[i] = '\0';
    for (size_t l = 0, r = i ? i - 1 : 0; l < r; ++l, --r) swap(s[l], s[r]);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    char* s = hexadecimal(n);
    cout << s << '\n';
    free(s);
    return 0;
}