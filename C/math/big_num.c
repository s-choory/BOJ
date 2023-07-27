#include <stdio.h>
#include <string.h>

int main(void)
{
	char A[1000001], B[1000001], C[1000002];
	int A_len, B_len, C_len, sum = 0, carry = 0;

	scanf("%s %s", A, B);

	A_len = strlen(A);
	B_len = strlen(B);

	if(A_len > B_len)
	{
		for(int i = B_len - 1; i >= 0; i--)
			B[i + A_len - B_len] = B[i];
		for(int i = 0; i < A_len - B_len; i++)
			B[i] = '0';
		B[A_len] = '\0';
		B_len = A_len;
	}
	else if(A_len < B_len)
	{
		for(int i = A_len - 1; i >= 0; i--)
			A[i + B_len - A_len] = A[i];
		for(int i = 0; i < B_len - A_len; i++)
			A[i] = '0';
		A[B_len] = '\0';
		A_len = B_len;
	}

	for(int i=A_len - 1; i>=0; i--)
	{
		sum = (A[i] - '0') + (B[i] - '0') + carry;
		C[i+1] = (sum % 10) + '0';
		carry = sum / 10;
	}
	if(carry > 0)
	{
		C[0] = carry + '0';
		C[A_len+1] = '\0';
	}	
	else
	{
		C[0] = '0';
		C[A_len+1] = '\0';
	}
	C_len = strlen(C);
	if(C[0] == '0')
		printf("%s", C + 1);
	else
		printf("%s", C);
	return 0;
}
