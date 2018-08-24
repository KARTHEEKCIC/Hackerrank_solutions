#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

class BigNaturalNum
{
	const static unsigned long long BASE = 1000000000ULL;
	const static unsigned long long MAX_ADD_MULTIPLY = ULLONG_MAX - (BASE - 1)*(BASE - 1) - (ULLONG_MAX / BASE);
	
	vector<unsigned long long> nums;

	void normalize(size_t startIdx) {
		for (size_t i = startIdx; i < nums.size() - 1; i++) {
			nums[i + 1] += (nums[i] / BigNaturalNum::BASE);
			nums[i] %= BigNaturalNum::BASE;
		}
	}
	void addFirstGreater(const BigNaturalNum& x, const BigNaturalNum& y) {
		unsigned long long carry = 0;
		nums.assign(x.nums.size(), 0);
		for (size_t i = 0; i < x.nums.size(); i++) {
			unsigned long long l = x.nums[i] + (i < y.nums.size() ? y.nums[i] : 0) + carry;
			nums[i] = l % BASE;
			carry = l / BASE;
		}
		if (carry > 0) {
			nums.push_back(1);
		}
	}

public:
	BigNaturalNum(const BigNaturalNum& v) {
		nums = v.nums;
	}
	BigNaturalNum(unsigned long long v=0) {
		nums.push_back(v);
	}	
	void swap(BigNaturalNum& x) {
		nums.swap(x.nums);
	}
	void add(const BigNaturalNum& x, const BigNaturalNum& y) {
		if (x.nums.size() >= y.nums.size()) {
			addFirstGreater(x, y);
		} else {
			addFirstGreater(y, x);
		}
	}	
	void multiply(const BigNaturalNum& x, const BigNaturalNum& y) {
		nums.assign(x.nums.size() + y.nums.size() + 1, 0);
		for (size_t i = 0; i < x.nums.size(); i++) {
			for (size_t j = 0; j < y.nums.size(); j++) {
				if (nums[i + j] > MAX_ADD_MULTIPLY) {
					normalize(i + j);
				}
				nums[i + j] += x.nums[i] * y.nums[j];
			}
		}
		normalize(0);
		for (size_t i = nums.size() - 1; (i > 0) && (nums[i] == 0); i--) {
			nums.pop_back();
		}
	}

	friend ostream& operator<<(ostream &os, const BigNaturalNum& rhs) {		
		bool bFirstZero = true;
		for (size_t i = rhs.nums.size(); i > 0;) {			
			unsigned long long y = rhs.nums[--i];			
			for (unsigned long long base = BASE / 10;  base > 0; base /= 10) {
				unsigned long long digit = y / base;
				if (!bFirstZero || (digit != 0)) {
					bFirstZero = false;
					os << digit;
				}
				y %= base;				
			}
		}		
		return os;
	}
};

void modifiedFibo(int t0, int t1, int n, BigNaturalNum& v)
{
	if (n > 1) {
		BigNaturalNum r0 = t0;
		BigNaturalNum r1, r2;		
		
		v = t1;
		for (int i = 2; i < n; i++) {
			r1.multiply(v, v);
			r2.add(r1, r0);
			r0.swap(v);
			v.swap(r2);
		}
	} else {
		v = t0;
	}
}

int main() {
    int t1, t2, n;
    BigNaturalNum t;
    
	cin >> t1 >> t2 >> n;
    modifiedFibo(t1, t2, n, t);
	cout << t << endl;	
    return 0;
}
