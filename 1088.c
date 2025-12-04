#include <stdio.h>
#include <stdlib.h>

int arr[100005];
int temp[100005];

long long merge_and_count(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long count = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];
    return count;
}

long long merge_sort_and_count(int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        count += merge_sort_and_count(left, mid);
        count += merge_sort_and_count(mid + 1, right);
        count += merge_and_count(left, mid, right);
    }
    return count;
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        if (merge_sort_and_count(0, n - 1) % 2 != 0) {
            printf("Marcelo\n");
        } else {
            printf("Carlos\n");
        }
    }
    return 0;
}
