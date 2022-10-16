/*Name : Tanmay Deepak Goregaonkar
Roll no : 33227
Batch : L-10
Assignment no : 2B_Bsearch (child)
*/

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(int argc, char *argv[])
{
    // displaying file name
    printf("\n\n----- ----- ----- ----- -----\n");
    printf("We are in search file\n");

    // convert argv to integer array
    int n = argc - 1;
    int arr[n];
    for (int i = 1; i <= n; i++)
    {
        arr[i - 1] = atoi(argv[i]);
    }

    // input element to search for in array
    int x;
    printf("\nEnter element to search\n");
    scanf("%d", &x);

    // perform binary search on array
    int result = binarySearch(arr, 0, n - 1, x);

    // display if element found in array or not
    if (result == -1)
    {
        printf("Element is not present in array\n");
    }
    else
    {
        printf("Element is present at index %d\n", result);
    }

    return 0;
}
