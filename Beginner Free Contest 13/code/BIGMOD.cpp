#include <bits/stdc++.h>
using namespace std;

typedef vector<int> bigInt;
const int base = 10000;

bigInt operator * (const bigInt a, const bigInt b) {
	bigInt c(a.size() + b.size() + 5, 0);
	for (int i = 0; i < a.size(); i++) {
		int carry = 0;
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += a[i] * b[j] + carry;
			carry = c[i + j] / base;
			c[i + j] %= base;
		}
		if (carry) c[i + b.size()] += carry;
	}
	while (!c.back() && c.size() > 1) c.pop_back();
	return c;
}

int main() {
    string a, b;
    int MOD;
    cin >> a >> b >> MOD;

    

    return 0;
}
