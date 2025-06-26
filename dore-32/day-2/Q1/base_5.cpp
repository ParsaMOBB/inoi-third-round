#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n = 1e18;
    vector<int> digits;
    while (n) {
        digits.push_back(n % 5);
        n /= 5;
    }
    reverse(digits.begin(), digits.end());
    for (int i = 0; i < digits.size(); i++) {
        cout << digits[i];
    }
    cout << endl;
    
    return 0;
}