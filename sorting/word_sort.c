#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	char *s1 = (char *)a;
	char *s2 = (char *)b;

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if(len1 != len2)
		return len1 - len2;
	else
		return strcmp(s1, s2);
}

int main(void)
{
	int n;
	char arr[20001][51] = { 0 }, prev[51] = "";
	
	scanf("%d", &n);

	for(int i=0; i<n; i++)
		scanf("%s", arr[i]);

	qsort(arr, n, sizeof(char) * 51, compare);

	for(int i=0; i<n; i++)
	{
		if(strcmp(arr[i], prev) == 0)
			continue;
		printf("%s\n", arr[i]);
		strcpy(prev, arr[i]);
	}
	return 0;
}