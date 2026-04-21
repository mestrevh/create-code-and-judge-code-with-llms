/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isWeekend(int day1to7) {
    return day1to7 == 6 || day1to7 == 7;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double R, V, B, S;
    int W, D;
    if (!(cin >> R >> W >> D >> V >> B >> S)) return 0;

    int n = min(D, 7); // prevent overly large, but D likely small; still safe
    int day = W;
    int counted = 0;

    for (int i = 1; counted < D; i++) {
        day++;
        if (day == 6) { // saturday -> not payable, still counts if within delay
            day = 1; // not used; this wrap assumes day cycles modulo 5 incorrectly; so do robust mod below
        }
    }

    // Correctly compute day of week with modulo 5 (since only 1..5 are weekdays in statement)
    // But statement says w=1..5; and payment must be on Monday when noticed weekend.
    // We'll compute actual weekday positions using a repeating 5-day week.
    day = W;
    int atrasoConsiderado = 0;
    int multiplierIndex = 0;

    // Need to count only weekdays elapsed during the D days overdue, excluding weekends.
    // Timeline: payment was due on weekday W. It is now D days later (including weekend days).
    // For each day after due day, if it lands on Mon-Fri, it counts as a delay day.
    // If lands on weekend, it doesn't count. Also, if payment attempt is on weekend, Sofia must pay Monday.
    // For "pay now", if current day (due day + D) is weekend, she cannot pay now => option "pay now" is invalid.
    // For "pay at salary arrival" on Friday of next week.

    int currentDayOfWeek = W + D;
    // Map to 1..5 weekdays using 5-day repeating (Mon=1..Fri=5).
    auto normWeekday = [&](int x)->int{
        int m = x % 5;
        if (m == 0) m = 5;
        return m;
    };
    currentDayOfWeek = normWeekday(currentDayOfWeek);

    int totalDelayDays = 0;
    int d = D;
    for (int k = 1; k <= d; k++) {
        int dow = normWeekday(W + k);
        if (dow >= 1 && dow <= 5) {
            // weekdays are 1..5, but weekend would map to 1..5 in this model, which is wrong.
        }
    }

    // The statement's model: weekdays are Mon-Fri; weekends are Sat-Sun.
    // Thus we need a 7-day cycle with weekend at 6,7.
    // Input W is 1..5; we interpret it on a 7-day cycle:
    // Mon=1 Tue=2 Wed=3 Thu=4 Fri=5 Sat=6 Sun=7.
    // Then advance by D days in 7-day cycle.
    auto norm7 = [&](int x)->int{
        int m = x % 7;
        if (m == 0) m = 7;
        return m;
    };

    int cur = norm7(W + D);

    for (int k = 1; k <= D; k++) {
        int dow = norm7(W + k);
        if (!isWeekend(dow)) totalDelayDays++;
    }

    double multa = 0.0;
    for (int i = 1; i <= totalDelayDays; i++) multa += (double)i * B;

    double totalNow = V + multa;

    auto formatMoney = [&](double x)->string{
        long long cents = llround(x * 100.0 + 1e-9);
        bool neg = cents < 0;
        if (neg) cents = -cents;
        long long whole = cents / 100;
        long long frac = cents % 100;
        stringstream ss;
        if (neg) ss << "-";
        ss << whole << "." << setw(2) << setfill('0') << frac;
        return ss.str();
    };

    bool canPayNow = !isWeekend(cur) && R >= totalNow;

    if (canPayNow) {
        double sobra = R - totalNow;
        cout << "Nao precisa esperar e nem pedir emprestimo pague agora e ainda vai sobrar R$ " << formatMoney(sobra) << " no final de tudo";
        return 0;
    }

    // Pay at salary: Friday of next week.
    // Determine next week's Friday relative to current date (which is W + D).
    // Compute current day index relative to Monday; W is weekday 1..5.
    // Use 7-day cycle. Salary arrives at Friday of next week:
    // That is the Friday after the current week ends (Sunday).
    // Equivalent: if current day is any day, go to next Friday where year-week defined as Mon..Sun.
    // Next week's Friday = Friday in the week that starts next Monday.
    // Let's compute current absolute day number: day0 = 0 at due day? We'll just use absolute offset.
    int absDay = W + D; // offset from Monday=1? doesn't matter, relative mod 7 enough.
    // Determine day-of-week for absDay: dayOfWeek = norm7(absDay)
    int dow = cur;

    // Find next Monday after current date
    // If current day is Sunday (7), next Monday is +1.
    int stepsToNextMonday = (8 - dow) % 7; // 0 if dow=1 -> means already Monday
    if (stepsToNextMonday == 0) stepsToNextMonday = 0; // ok
    int nextMondayOffset = stepsToNextMonday;

    // Next week's Friday is 4 days after next Monday (Mon+4=Fri)
    int stepsToSalary = nextMondayOffset + 4;

    int salaryDow = norm7(W + D + stepsToSalary);
    // Should be 5 (Friday)
    // Now compute total delay days by then: includes additional elapsed weekdays since due date up to salary day.
    int D2 = D + stepsToSalary;
    int totalDelayDaysAtSalary = 0;
    for (int k = 1; k <= D2; k++) {
        int dayw = norm7(W + k);
        if (!isWeekend(dayw)) totalDelayDaysAtSalary++;
    }
    double multa2 = 0.0;
    for (int i = 1; i <= totalDelayDaysAtSalary; i++) multa2 += (double)i * B;

    double totalAtSalary = V + multa2;

    if (S >= totalAtSalary) {
        double sobra = S - totalAtSalary;
        if (R < totalNow || isWeekend(cur) || R < totalNow) {
            cout << "Nao da pra pagar agora mas se esperar o dinheiro chegar ao inves de adquirir uma nova divida, vai sobrar R$ " << formatMoney(sobra) << " no final de tudo";
            return 0;
        }
    }

    // Else need loan at earliest feasible time? Statement says if cannot pay now, consider waiting; if cannot even when salary arrives, borrow.
    // If cannot pay at salary, loan amount = totalAtSalary - S
    double falta = totalAtSalary - S;
    if (falta < 0) falta = 0;
    cout << "Nao da pra pagar nem quando o salario chegar, vai ter que pedir um emprestimo de R$ " << formatMoney(falta) << " no final de tudo";
    return 0;
}