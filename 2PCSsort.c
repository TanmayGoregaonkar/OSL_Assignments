/*Name : Tanmay Deepak Goregaonkar
 Roll no : 33227
 Batch : L-10
 Assignment No : 2a
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

// Merge Sort
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
// Printing Array
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Quick Sort
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void sorting()
{
    
    int arr[5];
    printf("\nEnter elements of array\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    pid_t pid = fork();
    // Parent merge sort
    

    if (pid > 0)
    {
        printf("\nParent Process %d\n", (int)getpid());

        printf("\nGIven array is \n");
        printArray(arr, 5);

        mergeSort(arr, 0, 5 - 1);

        printf("\n Sorted array is \n");
        printArray(arr, 5);
        printf("\n");
    }
    // child quick sort
    else
    {
        printf("\nChild Process %d\n", (int)getppid());
        printf("\nParent of Child %d\n", (int)getppid());

        int arr[] = {18, 65, 90, 33, 44};
        int arr_size = sizeof(arr) / sizeof(arr[0]);

        quickSort(arr, 0, arr_size - 1);
        printArray(arr, arr_size);
        printf("\n");
    }
}

void orphan()
{
    pid_t p;
    p = fork();
    if (p == 0)
    {
        sleep(2);
        printf("This is a child %d\n", (int)getpid());
        printf("This is a parent %d\n", (int)getppid());
    }
    else
    {
        printf("This is a parent process%d\n", (int)getpid());
        system("ps -elf | grep fork.out");
    }
}

void zombie()
{
    pid_t child_pid = fork();

    if (child_pid > 0)
    {
        sleep(2);
        printf("This is a parent process %d\n", (int)getpid());
        printf("Before sleep\n");
        system("top -b1 -n1 | grep Z");

        sleep(5);
        printf("After sleep\n");
        system("top -b1 -n1 | grep Z");
    }
    else
    {
        printf("Before exit\n");
        system("top -b1 -n1 | grep Z");

        printf("This is a child process %d\n", (int)getpid());
        printf("This is a parent process %d\n", (int)getppid());
        exit(0);

        printf("After exit\n");
        system("top -b1 -n1 | grep Z");
    }
}
int main()
{
    int opt;

    do
    {
        printf("1. Sorting\n");
        printf("2. Orphan\n");
        printf("3. Zombie\n");
        printf("4. Exit\n");

        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            sorting();
            break;
        case 2:
            orphan();
            break;

        case 3:
            zombie();
            break;

        case 4:
            printf("terminating !!!");
            break;
        default:
            printf("Invalid choice");
            break;
        }
    } while (opt != 4);

    return 0;
}
