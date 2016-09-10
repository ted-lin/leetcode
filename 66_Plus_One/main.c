#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i = 0, carry = 0;
    int *sum = (int *) calloc(digitsSize + 1, sizeof(int));
    
    if (digitsSize == 0) {
        *returnSize = 1;
        sum[0] = 1;
        return sum;
    }
    
    digits[digitsSize-1] += 1;
    
    for (i = digitsSize; i > 0; --i) {
        sum[i] += digits[i-1];
        if (sum[i] >= 10) {
            sum[i-1] += 1;
            sum[i] = sum[i] % 10;
        }
    }
    
    *returnSize = digitsSize;
    if (sum[0] > 0)
        (*returnSize)++;
    else {
        for(i = 1; i <= digitsSize; ++i)
            sum[i-1] = sum[i];
    }
#ifdef DEBUG
    for(i = 0; i < digitsSize + 1; ++i)
        printf("%d ", sum[i]);
    printf("\n");
#endif
    return sum;
}

int main () {
	int a[4] = { 8, 9, 9, 9 };
	int i = 0, len = 0;
	int *sum = plusOne(a, sizeof(a)/ sizeof(int), &len);

	printf("Sum = ");
	for (i = 0; i < len; ++i)
		printf("%d ", sum[i]);
	printf("\n");

	free(sum);

	return 0;
}
