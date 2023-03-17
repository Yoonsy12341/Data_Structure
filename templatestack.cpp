#include <iostream>
using namespace std;

template <typename E>
class stack{
private:
	E* arr;
	int cap;
	int t;


public:
	stack(int c) : cap(c), t(-1), arr(new E[cap]) { }
	bool empty() {
		return t == -1;
	}
	int size() {
		return t + 1;
	}
	E top() {
		if (empty()) {
			throw runtime_error("Empty");
		}
		return arr[t];
	}
	void push(const E& data){
		if (size() == cap) {
			throw runtime_error("Full");
		}
		arr[++t] = data;
	}
	void pop() {
		if (empty()) {
			throw runtime_error("EMpty");
		}
		t--;
	}
};


int main() {
	int N, value;
	string str;

	cin >> N;
	stack<int> stk(N);

		while (N--) {
			cin >> str;

			if (str == "empty") {
				cout << stk.empty() << endl;
			}
			else if (str == "size") {
				cout << stk.size() << endl;
			}
			else if (str == "top") {
				try {
					cout << stk.top() << endl;
				}
				catch (const runtime_error& e) {
					cerr << e.what() << endl;
				}
			}
			else if (str == "push") {
				try {
					cin >> value;
					stk.push(value);
				}
				catch (const runtime_error& e) {
					cerr << e.what() << endl;
				}
			}
			else if (str == "pop") {
				try {
					stk.pop();
				}
				catch (const runtime_error& e) {
					cerr << e.what() << endl;
				}
			}

		}


}