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
	ArrayStack <char> stkcharop{ 100 };
	int N;
	cin >> N;

	string str;
	while (N--) {
		cin >> str;
		for (int i = 0; i < (int)str.size(); i++) {
			if (str[i] >= 'A' && str[i <= 'Z']) {
				cout << str[i];
			}
			else {
				if (str[i] == '*' || str[i] == '/') {
					while (!stkcharop.empty() && (stkcharop.top() == '*' || stkcharop.top() == '/')) {
						cout << stkcharop.top();
						stkcharop.pop();
					}
					stkcharop.push(str[i]);

				}
				else if (str[i] == '+' || str[i] == '-') {
					while (!stkcharop.empty()) {
						cout << stkcharop.top();
						stkcharop.pop();
					}
					stkcharop.push(str[i]);
				}


			}
		}
		while (!stkcharop.empty()) {
			cout << stkcharop.top();
			stkcharop.pop();
		}
		cout << endl;
	}

}