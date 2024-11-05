#include <stdio.h>

void sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int a[100], n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, n);

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        if (i != 0)
            printf(", %d", a[i]);
        else
            printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}
