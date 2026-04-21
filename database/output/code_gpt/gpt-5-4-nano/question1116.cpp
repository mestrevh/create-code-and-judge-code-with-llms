/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

string toLowerStr(string s){
    for(char &c: s) c = (char)tolower((unsigned char)c);
    return s;
}

bool isLeap(int y){
    if(y % 400 == 0) return true;
    if(y % 100 == 0) return false;
    return y % 4 == 0;
}

int daysInMonth(int m, int y){
    static int mdays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(m == 2) return mdays[m] + (isLeap(y) ? 1 : 0);
    return mdays[m];
}

bool validDate(int d,int m,int a){
    if(a < 1900 || a > 2100) return false;
    if(m < 1 || m > 12) return false;
    if(d < 1 || d > daysInMonth(m,a)) return false;
    return true;
}

string unitWord(int n){
    static vector<string> w = {"zero","um","dois","tres","quatro","cinco","seis","sete","oito","nove"};
    return w[n];
}

string teenWord(int n){
    static vector<string> w = {"dez","onze","doze","treze","quatorze","quinze","dezesseis","dezessete","dezoito","dezenove"};
    return w[n-10];
}

string tensWord(int n){
    if(n < 10) return unitWord(n);
    if(n < 20) return teenWord(n);
    static vector<string> tens = {"","","vinte","trinta","quarenta","cinquenta","sessenta","setenta","oitenta","noventa"};
    if(n % 10 == 0) return tens[n/10];
    return tens[n/10] + " e " + unitWord(n%10);
}

string hundredsWord(int n){
    if(n < 100) return tensWord(n);
    int h = n/100;
    int r = n%100;
    string res;
    if(h == 1) res = "cem";
    else res = unitWord(h) + "cento";
    if(r == 0){
        if(h == 1) return "cem";
        return res;
    }
    if(h == 1) {
        res = "cento";
    }
    else {
        res = unitWord(h) + "cento";
    }
    res += " e " + (r < 100 ? tensWord(r) : hundredsWord(r));
    return res;
}

string twoDigits(int n){
    return tensWord(n);
}

string yearToWords(int y){
    int a = y / 100;
    int b = y % 100;
    string res;
    if(a == 0){
        res = twoDigits(b);
    } else {
        res = (a == 1) ? "dois mil" : (a == 19 && b == 0 ? "dezenove mil" : "");
    }
    return res;
}

string yearPart(int y){
    int a = y/100;
    int b = y%100;
    string res;
    if(a == 19 && b == 0){
        res = "dezenove";
    } else {
        res = "";
    }
    return res;
}

string number0to999(int n){
    if(n == 0) return "zero";
    if(n < 100) return tensWord(n);
    int h = n/100;
    int r = n%100;
    if(n == 100) return "cem";
    string res = unitWord(h) + "cento";
    if(r == 0) return res;
    return res + " e " + tensWord(r);
}

string yearWords(int y){
    int first = y/100;
    int last = y%100;
    if(first == 19){
        string res = "mil e novecentos";
        if(last == 0) return res;
        res += " e " + twoDigits(last);
        return res;
    }
    if(first == 20){
        string res = "dois mil";
        if(last == 0) return res;
        if(last < 10) res += " e " + unitWord(last);
        else res += " e " + twoDigits(last);
        return res;
    }
    return "";
}

string monthWord(int m){
    static vector<string> months = {
        "", "janeiro","fevereiro","marco","abril","maio","junho",
        "julho","agosto","setembro","outubro","novembro","dezembro"
    };
    return months[m];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d,m,a;
    if(!(cin >> d >> m >> a)) return 0;

    if(!validDate(d,m,a)){
        cout << "data invalida";
        return 0;
    }

    auto dayWords = [&] (int x)->string{
        if(x == 100) return "cem";
        if(x < 10) return unitWord(x);
        if(x < 20) return teenWord(x);
        if(x < 100) return tensWord(x);
        return number0to999(x);
    };

    string out = dayWords(d) + " de " + monthWord(m) + " de " + yearWords(a);
    for(char &c: out){
        if(c=='ç') c='c';
        if(c=='ã') c='a';
        if(c=='á') c='a';
        if(c=='é') c='e';
        if(c=='í') c='i';
        if(c=='ó') c='o';
        if(c=='ú') c='u';
    }
    cout << out;
    return 0;
}