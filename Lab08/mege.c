#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stddef.h>

#define size 1000 // maximum size od array 

int array[size]; // original size array
int temp[size]; //temp array for merging

typedef struct {
    int high;
    int low;
} mer;
//merging two subarrays
void merge(int high, int mid, int low) {
    int i, j, k;
    //merging arrays by comapiring
    for (i = high, j = mid + 1, k = high; i <= mid && j <= low; k++) {
        if (array[i] <= array[j]) {
            temp[k] = array[i++];
        } else {
            temp[k] = array[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = array[i++];
    }
    while (j <= low) {
        temp[k++] = array[j++];
    }
    for (k = high; k <= low; k++) {
        array[k] = temp[k];
    }
}
//reccursive function
void *merge_sort(void *data) {
    mer *m = (mer *) data;
    int high = m->high;
    int low = m->low;
    //base case: sorted if only one element
    if (high < low) {
    //calculating mid point
        int mid = (high + low) / 2;
    //create threads 
        pthread_t thread_high, thread_low;

        mer high_mer = {high, mid};
        mer low_mer = {mid + 1, low};

        pthread_create(&thread_high, NULL, merge_sort, &high_mer);
        pthread_create(&thread_low, NULL, merge_sort, &low_mer);

     //wait for threads to complete before merging
        pthread_join(thread_high, NULL);
        pthread_join(thread_low, NULL);
     //merge two sorted halves
        merge(high, mid, low);
    }
    pthread_exit(NULL);
}

int main() {
    int n, i;
    pthread_t tid;

//get the no of elements
    printf("Enter No Of Elements: ");
    scanf("%d", &n);
//get the elements of array
    printf("Enter The Elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    mer data = {0, n - 1};
//create the complete array and merge
    pthread_create(&tid, NULL, merge_sort, &data);
    pthread_join(tid, NULL);
//print sorted array
    printf("Sorted elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
