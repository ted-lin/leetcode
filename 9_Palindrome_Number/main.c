#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x) {
	int orig = x;
	int len = 0, orig_len = 0;
	int i = 0;
	char *target = NULL;
	int remainder = 0;

	if (x < 0)
		return false;

	while (x) {
		remainder = x % 10;
		++len;
		x /= 10;
		target = (char *) realloc(target, sizeof(char) * len + 1);
	}
	orig_len = len;
	while(orig_len) {
		target[orig_len - 1] = orig % 10;
		orig /= 10;
		--orig_len;
	}

#ifdef DEBUG
	printf("len: %d\n", len);
	printf("target: ");
	while(target[i++])
		printf("%d ", target[i - 1]);
	printf("\n");
#endif
	if (!len)
		return true;

	for (i = 0; i < len; ++i) {
		if (i >= len - i - 1)
			break;
		if (target[i] == target[len - i - 1])
			continue;
		else {
			free(target);
			return false;
		}
	}
	free(target);
	return true;
}

int main() {
	printf("%d\n", isPalindrome(-12321));
	printf("%d\n", isPalindrome(-123211));
	printf("%d\n", isPalindrome(-123321));
	printf("%d\n", isPalindrome(-1231));
	return 0;
}
