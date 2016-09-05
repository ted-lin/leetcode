#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::cout;
using std::endl;
using std::string;

int idxCheck(char c) {
	int i = 0;
	char a[6] = { '(', '[', '{', ')', ']', '}' };
	for(i = 0; i < 6; ++i) {
		if (a[i] == c)
			return i;
	}
	return -1;
}

bool isValid(string s) {
	stack<int> _stack;
	int i = 0, idx;

	if (s.length() % 2)
		return false;

	if (idxCheck(s[0]) >= 3)
		return false;

	for(i = 0; i < s.length(); ++i) {
		idx = idxCheck(s[i]);
		if (idx == -1)
			return false;

		if (idx < 3) {
			/* push */
#ifdef DEBUG
			printf("push idx %d\n", idx);
#endif
			_stack.push(idx);
		} else {
			/* pop */
			int top = _stack.top();
#ifdef DEBUG
			printf("pop idx %d\n", top);
#endif
			if (idx != top + 3) {
				return false;
			}
			_stack.pop();
		}
	}

	if (_stack.size() != 0)
		return false;

	return true;
}

int main() {
	string str(")}{({))[{{[}");
	printf("%d\n", isValid(str));
	return 0;
}
