#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
	int i = left, j = mid + 1, k = 0;
    int tmp[right - left + 1]; //추가적인 공간이 필요하여 tmp할당.

	while (i <= mid && j <= right)      //분할 정렬된 list의 합병
	{
        if(arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
	}
    // 남아 있는 값들을 일괄 복사
    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= right)
        tmp[k++] = arr[j++];
    k--;
    // 배열 tmp[](임시 배열)의 리스트를 배열 arr[]로 재복사
    while(k >= 0)
    {
        arr[left + k] = tmp[k];
        k--;
    }
}

void mergesort(int arr[], int left, int right)
{
    int mid;
    
    if(left < right)
    {
        mid =(left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 - 분할
        mergesort(arr, left, mid); //앞쪽 부분 리스트 정렬 - 정복
        mergesort(arr, mid+1, right); //뒤쪽 부분 리스트 정렬 - 정복
        merge(arr, left, mid, right);  //정렬된 2개의 부분 배열을 합병 - 결합
    }
}

int main(void)
{	
	int n, a, range, maxfre, sum = 0, max = -4000, arr[500000] = { 0 }, arr2[500000] = { 0 }, arr3[8001] = { 0 };
	double aver, aver2, aver3;
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	aver = (double)(sum % n);
	aver2 = (double)(sum / n);
	aver3 = (double)(aver / n);
	if(sum >= 0)
	{
		if(aver3 * 10 < 5)
			aver = aver2;
		else
			aver = aver2 + 1;
	}
	else if(sum < 0)
	{
		if(aver3 * 10 <= -5)
			aver = aver2 - 1;
		else
			aver = aver2;
	}
	sum = (int)aver;
	
	mergesort(arr, 0, n-1);
	for(int i=0; i<n; i++)
    {
        a = arr[i];
        arr2[a]++;
		if(arr2[a] >= max)
			max = arr2[a];
    }
	int k = 0;
	for(int i=-4000; i<=4000; i++)
	{
		if(arr2[i] == max)
		{
			arr3[k] = i;
			k++;
		}
	}
	maxfre = k;
	if(maxfre == 1)  
		maxfre = arr3[0];
	else
		maxfre = arr3[1];
	if(n == 1)
		range = 0;
	else
		range = arr[n-1] - arr[0];
	printf("%d\n%d\n%d\n%d", sum, arr[n/2], maxfre, range);
	return 0;
}