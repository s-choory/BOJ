#include <stdio.h>
#include <stdlib.h>

typedef struct human{
    int age;
    char name[101];
}H;

void merge(H *arr, int left, int right, int mid, H *tmp)
{
	int i=left, j = mid+1, k = 0;

	while(i <= mid && j <= right)
	{
		if(arr[i].age <= arr[j].age)
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while(i <= mid)
		tmp[k++] = arr[i++];
	while(j <= right)
		tmp[k++] = arr[j++];
	
	k--;

	while(k >= 0)
	{
		arr[left+k] = tmp[k];
		k--;
	}
}

void mergesort(H *arr, int left, int right, H *tmp)
{
	int mid;
	if(left < right)
	{
		mid = (right+left) / 2;
		mergesort(arr, left, mid, tmp);
		mergesort(arr, mid+1, right, tmp);
		merge(arr, left, right, mid, tmp);
	}
}

int main(void)
{
    int n;
    scanf("%d", &n);

    H *p1 = malloc(sizeof(H) * n + 1);

    for(int i=0; i<n; i++)
        scanf("%d %s", &p1[i].age, p1[i].name);

    H *p2 = malloc(sizeof(H) * n + 1);

    mergesort(p1, 0, n-1, p2);

    for(int i=0; i<n; i++)
        printf("%d %s\n", p1[i].age, p1[i].name);

    free(p1);
    free(p2);
    return 0;
}