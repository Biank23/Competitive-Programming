#include <bits/stdc++.h>

using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //given information: 1 Jan 2000 was a Monday
    int day = 1; //0 = Sunday
    int month = 0; //0 = January
    int year = 1900;

    auto isLeap = [](int year) {
        return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0); 
    };

    int res = 0;
    while (year <= 2000) {
        if (year > 1900 && day == 0) {
            res++;
        }
        day += days[month];
        if (month == 1 && isLeap(year)) {
            day++;
        }
        day %= 7;
        month++;
        if (month == 12) {
            month = 0, year++;
        }
    }
    cout << res << '\n';

    return 0;
}