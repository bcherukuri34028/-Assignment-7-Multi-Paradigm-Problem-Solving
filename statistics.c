#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

float mean(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    return (float)sum / size;
}

float median(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
    if(size % 2 == 0)
        return (arr[size/2 - 1] + arr[size/2]) / 2.0;
    else
        return arr[size/2];
}

void mode(int arr[], int size) {
    int maxCount = 0;
    printf("Mode: ");
    for(int i = 0; i < size; ++i) {
        int count = 0;
        for(int j = 0; j < size; ++j)
            if(arr[j] == arr[i])
                count++;
        if(count > maxCount)
            maxCount = count;
    }

    for(int i = 0; i < size; ++i) {
        int count = 0;
        for(int j = 0; j < size; ++j)
            if(arr[j] == arr[i])
                count++;
        if(count == maxCount) {
            int isNew = 1;
            for(int k = 0; k < i; ++k)
                if(arr[k] == arr[i])
                    isNew = 0;
            if(isNew)
                printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Mean: %.2f\n", mean(arr, size));
    printf("Median: %.2f\n", median(arr, size));
    mode(arr, size);

    return 0;
}