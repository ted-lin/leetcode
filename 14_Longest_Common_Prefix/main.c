#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int len = 0;
    char *res = NULL;

	if (!strsSize)
		return "";

    len = strlen(strs[strsSize-1]);
    res = (char *) malloc(sizeof(char) * len + 1);
    memcpy(res, strs[strsSize-1], len);
    res[len] = '\0';

    --strsSize;

    for(;strsSize;--strsSize) {
        while (len) {
            if (strlen(res) < strlen(strs[strsSize-1])) {
                if (strncmp(res, strs[strsSize-1], len)) {
                    --len;
                    continue;
                }
            } else {
                if (strncmp(strs[strsSize-1], res, len)) {
                    --len;
                    continue;
                }
            }
            break;
        }
    }

    res[len] = '\0';
    printf("ans: %s\n", res);
    return res;
}

int main() {
    char *a = "abcd";
    char *b = "ab";
    char *c = "abc";

    char* s[3];
    s[0] = a;
    s[1] = b;
    s[2] = c;

    longestCommonPrefix(s, 3);
    return 0;
}

