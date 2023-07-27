#include <stdio.h>

void merge(int arr[], int left, int right, int mid)
{
	int i=left, j = mid+1, k = 0;
	int tmp[right - left + 1];

	while(i <= mid && j <= right)
	{
		if(arr[i] <= arr[j])
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

void mergesort(int arr[], int left, int right)
{
	int mid;
	if(left < right)
	{
		mid = (right+left) / 2;
		mergesort(arr, left, mid);
		mergesort(arr, mid+1, right);
		merge(arr, left, right, mid);
	}
}

int main(void)
{
    int n, k, arr[1000001] = { 0 }, arr2[1000001] = { 0 };

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        arr2[i] == arr[i];
    }
    mergesort(arr, 0, n-1);

    arr2[0] = 0;
    k = 0;
    for(int i=1; i<n; i++)
    {
        if(arr[i] != arr[i-1])
            k++;
        arr2[i] = k;
    }
    for(int i=0; i<n; i++)
        printf("%d ", arr2[i]);
    return 0;
}