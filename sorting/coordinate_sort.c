#include <stdio.h>

void merge(int arr[][2], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // 임시 배열 생성
    int L[n1][2], R[n2][2];

    // 데이터 복사
    for (i = 0; i < n1; i++) {
        L[i][0] = arr[l + i][0];
        L[i][1] = arr[l + i][1];
    }
    for (j = 0; j < n2; j++) {
        R[j][0] = arr[m + 1 + j][0];
        R[j][1] = arr[m + 1 + j][1];
    }

    // 합병
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i][0] < R[j][0]) {
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            i++;
        }
        else if (L[i][0] > R[j][0]) {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            j++;
        }
        else { // L[i][0] == R[j][0]
            if (L[i][1] < R[j][1]) {
                arr[k][0] = L[i][0];
                arr[k][1] = L[i][1];
                i++;
            }
            else {
                arr[k][0] = R[j][0];
                arr[k][1] = R[j][1];
                j++;
            }
        }
        k++;
    }

    // 남은 요소들 복사
    while (i < n1) {
        arr[k][0] = L[i][0];
        arr[k][1] = L[i][1];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k][0] = R[j][0];
        arr[k][1] = R[j][1];
        j++;
        k++;
    }
}

void mergeSort(int arr[][2], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(void)
{
    int arr[100000][2] = { 0 }, n, tmp;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d %d", &arr[i][0], &arr[i][1]);

    mergeSort(arr, 0, n-1);
    
    for(int i=0; i<n; i++)
        printf("%d %d\n", arr[i][0], arr[i][1]);
    return 0;
}