#include<stdio.h>
//快速排序
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int nums[], int low, int high) {
    int pivot = nums[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (nums[j] < pivot) {
            i++;
            swap(&nums[i], &nums[j]);
        }
    }
    swap(&nums[i + 1], &nums[high]);
    return i + 1;
}
void quickSort(int nums[], int low, int high) {
    if (low < high) {
        int pi = partition(nums, low, high);
        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high);
    }
}


int locate(int nums[], int key,int size)
{
    int count=0;
    int l=0,r=size-1;
    int mid;
    while(l<r){
        count++;
        mid=(l+r)/2;
        if(nums[mid]==key){
            printf("查找次数为：%d\n", count);
            return mid;
        }
        else if(nums[mid]>key){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}
int main()
{
    int a[] = {12, 76, 29, 15, 62, 35, 33, 89, 48, 20};
    int key = 35;
    quickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    int index = locate(a, key,sizeof(a) / sizeof(a[0]));
    printf("index = %d\n", index);
    return 0;
}
