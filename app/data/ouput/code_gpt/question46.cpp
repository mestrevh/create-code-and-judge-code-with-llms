/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace std;

int main() {
    string date1, date2;
    cin >> date1 >> date2;

    struct std::tm tm1 = {}, tm2 = {};
    istringstream ss1(date1);
    ss1 >> get_time(&tm1, "%d/%m/%Y");
    istringstream ss2(date2);
    ss2 >> get_time(&tm2, "%d/%m/%Y");

    auto time1 = std::chrono::system_clock::from_time_t(mktime(&tm1));
    auto time2 = std::chrono::system_clock::from_time_t(mktime(&tm2));

    auto duration = std::chrono::duration_cast<std::chrono::days>(time2 - time1).count();
    
    cout << duration << endl;
    return 0;
}
