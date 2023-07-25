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
    int n;

    scanf("%d", &n);
    int arr[n];

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    mergesort(arr, 0, n-1);
    printf("%d", arr[0] * arr[n-1]);
    return 0;
}