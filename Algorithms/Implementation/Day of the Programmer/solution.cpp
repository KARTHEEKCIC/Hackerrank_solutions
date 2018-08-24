/**
    @Author B Kartheek Reddy
    @Hackerrank hackerrank.com/KARTHEEK04
 **/

#include <bits/stdc++.h>

using namespace std;

string solve(int year){
    // Complete this function
    if(year > 1918) {
        //gregorian
        if(year%400 == 0 || (year%4 == 0 && year%100 != 0)) {
            return "12.09." + std::to_string(year);
        } else return "13.09." + std::to_string(year);
    } else if(year == 1918) {
            return "26.09."+std::to_string(year);
    } else {
        //julian
        if(year%4 == 0) {
            return "12.09." + std::to_string(year);
        } else return "13.09." + std::to_string(year);
    }
}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}

