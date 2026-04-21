/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

bool is_leap_year(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return (y % 4 == 0);
}

int get_days_in_month(int m, int y) {
    if (m == 2) {
        return is_leap_year(y) ? 29 : 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    return 31;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d, m, y;
    if (!(cin >> d >> m >> y)) return 0;
    
    int h_now, min_now;
    if (!(cin >> h_now >> min_now)) return 0;
    
    int h_extra, min_extra;
    if (!(cin >> h_extra >> min_extra)) return 0;

    long long total_minutes = (long long)h_now * 60 + min_now + (long long)h_extra * 60 + min_extra;
    
    long long days_to_advance = total_minutes / 1440;
    int remaining_minutes = total_minutes % 1440;
    int final_hour = remaining_minutes / 60;
    int final_minute = remaining_minutes % 60;

    int res_d = d, res_m = m, res_y = y;
    for (long long i = 0; i < days_to_advance; ++i) {
        res_d++;
        if (res_d > get_days_in_month(res_m, res_y)) {
            res_d = 1;
            res_m++;
            if (res_m > 12) {
                res_m = 1;
                res_y++;
            }
        }
    }

    cout << setfill('0') << setw(2) << res_d << "\\"
         << setw(2) << res_m << "\\"
         << setw(4) << res_y << "\n";
    
    cout << setfill('0') << setw(2) << final_hour << ":"
         << setw(2) << final_minute << "\n";
    
    cout << "Falta " << days_to_advance << " dias até a data que o Esquisito falou\n";

    return 0;
}