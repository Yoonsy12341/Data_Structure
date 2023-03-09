#include <iostream>
#include <string>
#include "dLL.h"

using namespace std;


int main() {
	int t = 0, idx = 0, value, size;
	string str;
	doublyLinkedList list;

	cin >> t;
	
	while (t--) {
		cin >> str;
		if (str == "append") {
			cin >> value;
			list.append(value);
		}
		else if (str == "insertion") {
			cin >> idx >> value;
			list.insertion(idx, value);
		}
		else if (str == "deletion") {
			cin >> idx;
			list.deletion(idx);
		}
		else if (str == "print") {
			list.print();
		}

	}




}
