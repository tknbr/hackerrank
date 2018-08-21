#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Date
{
    int day;
    int month;
    int year;
    
    public:
        Date(int, int, int);
        int hackos(Date d2){
            if(d2.year < year){
                return 0;
            } else if(d2.year == year && d2.month < month){
                return 0;
            } else if(d2.year == year && d2.month == month && d2.day <= day){
                return 0;
            } else if (d2.year == year && d2.month == month){
                return (d2.day - day)*15;
            } else if (d2.year == year){
                return (d2.month - month)*500;
            } else {
                return 10000;
            }
        }
    
};

Date::Date(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}

int main() {
    int day;
    int month;
    int year;
    cin >> day >> month >> year;
    Date d1(day, month, year);
    cin >> day >> month >> year;
    Date d2(day, month, year);
    cout << d2.hackos(d1) << endl;
    return 0;
}