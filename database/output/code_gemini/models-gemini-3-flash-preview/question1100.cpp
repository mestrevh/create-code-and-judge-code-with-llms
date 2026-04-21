/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double h, l, L;
    if (!(cin >> h >> l >> L)) return 0;

    double area_menor = l * l;
    double area_maior = L * L;
    double volume = (h / 3.0) * (area_maior + area_menor + sqrt(area_maior * area_menor));

    cout << fixed << setprecision(1) << volume << endl;

    return 0;
}

```cpp
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double h, l, L;
    while (cin >> h >> l >> L) {
        double area_menor = l * l;
        double area_maior = L * L;
        double volume = (h / 3.0) * (area_maior + area_menor + (l * L));
        cout << fixed << setprecision(1) << volume << "\n";
    }

    return 0;
}
```