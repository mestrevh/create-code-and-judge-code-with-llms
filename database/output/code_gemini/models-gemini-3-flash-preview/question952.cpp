/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long count[256] = {0};
    char ch;
    
    while (cin.get(ch)) {
        count[(unsigned char)tolower(ch)]++;
    }

    long long ans = count['v'];
    ans = min(ans, count['o']);
    ans = min(ans, count['u']);
    ans = min(ans, count['p'] / 2);
    ans = min(ans, count['a'] / 2);
    ans = min(ans, count['s'] / 2);
    ans = min(ans, count['r']);
    ans = min(ans, count['e']);
    ans = min(ans, count['m']);
    ans = min(ans, count['1']);

    cout << ans << endl;

    return 0;
}
