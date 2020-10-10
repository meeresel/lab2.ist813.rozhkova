#include <stdio.h>
#define SIZE 10000000
#include <time.h>  /* clock_t, clock(), CLOCKS_PER_SEC */
int myArray[SIZE - 1];
void quickSort(int *numbers, int left, int right)
{
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}
void init()
{
    int i;
    for( i = 0; i < SIZE - 1; i++)
    {
        myArray[i] = rand()%SIZE;
    }
}
int main()
{
    init();
    clock_t t;
    t = clock();
    quickSort(myArray, 0, SIZE-1);
    t = clock() - t;
    printf ("QuickSort took %f seconds.\n",
            ((double)t)/CLOCKS_PER_SEC);
    return 0;
}

