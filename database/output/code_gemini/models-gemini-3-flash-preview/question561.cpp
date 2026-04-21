/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    long long total_digits = 0;
    long long start = 1;
    long long length = 1;

    while (start <= n) {
        long long next_start = start * 10;
        long long end = next_start - 1;
        
        if (end > n) {
            end = n;
        }
        
        total_digits += (end - start + 1) * length;
        
        start = next_start;
        length++;
    }

    cout << total_digits << endl;

    return 0;
}

```cpp
```