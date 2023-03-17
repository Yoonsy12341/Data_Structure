#include <iostream>
using namespace std;

template <typename E>
class ArrayStack {
private:
	E* S;
	int cap;
	int t;

public:
	ArrayStack(int c) :S(new E[c]), cap(c), t(-1) {}

	void pop() {
		if (empty()) {
			cout << "Pop from empty stack";
			return;
		}
		t--;
	}
	void push(const E& e) {
		if (size() == cap) {
			cout << "Push to full stack";
			return;
		}
		S[++t] = e;
	}
	E top() { return S[t]; }
	int size() { return t + 1; }
	bool empty() {
		if (t == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	void print() {
		int s = size();
		while (s--) {
			cout << S[s] << " ";
		}
		cout << endl;
	}

};

int main() {
	ArrayStack <string> stkchar{ 100 };

	int N;
	cin >> N;
	string x, y;

	string str;
	while (N--) {
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				x = str[i];
				stkchar.push(x);
			}
			else if ((str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')) {
				x = stkchar.top();
				stkchar.pop();
				y = stkchar.top();
				stkchar.pop();
				
				stkchar.push(y + str[i] + x);
				
			}
		}
		cout << stkchar.top() << endl;
	}
}