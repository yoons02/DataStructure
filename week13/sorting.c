#include "sorting.h"

int main()
{
    int list[MAX_SIZE], n = MAX_SIZE;
    int exp_list[EXP_SIZE];

    printf("\n ----- insertion sort ----- \n");
    copy_list(original, list, n);
    print_list(list, 0, n - 1);
    num_compare = 0;
    insertion_sort(list, n, 1);
    printf("\n");
    print_list(list, 0, n - 1);
    printf("\n Total number of comparison = %d \n", num_compare);

    printf("\n ----- quick sort ----- \n");
    copy_list(original, list, n);
    print_list(list, 0, n - 1);
    num_compare = 0;
    quick_sort(list, 0, n - 1, 1);
    printf("\n");
    print_list(list, 0, n - 1);
    printf("\n Total number of comparison = %d \n", num_compare);

    printf("\n ----- merge sort ----- \n");
    copy_list(original, list, n);
    print_list(list, 0, n - 1);
    num_compare = 0;
    merge_sort(list, 0, n - 1, 1);
    printf("\n");
    print_list(list, 0, n - 1);
    printf("\n Total number of comparison = %d \n", num_compare);

    for (int i = 1; i <= 10; i++)
    {
        n = i * 1000;
        printf("\n ----- n = %d ----- \n", n);
        random_initialize(experiment, n);
        copy_list(experiment, exp_list, n);
        num_compare = 0;
        insertion_sort(exp_list, n, 0);
        printf("\n No. of comparison (insertion sort) = %d \n", num_compare);
        copy_list(experiment, exp_list, n);
        num_compare = 0;
        quick_sort(exp_list, 0, n - 1, 0);
        printf("\n No. of comparison (quick sort) = %d \n", num_compare);
        copy_list(experiment, exp_list, n);
        num_compare = 0;
        merge_sort(exp_list, 0, n - 1, 0);
        printf("\n No. of comparison (merge sort) = %d \n", num_compare);
    }

    return 0;
}

// insertion sort
void insertion_sort(int list[], int n, int show)
{
    int i, j, next;

    for (i = 1; i < n; i++)
    {
        next = list[i];
        for (j = i - 1; j >= 0 && next < list[j]; j--)
        {
            ++num_compare;
            list[j + 1] = list[j];
        }
        list[j + 1] = next;

        // 매 step에서 list 출력
        if (show)
        {
            print_list(list, 0, n - 1);
        }
    }
}

// quick sort
void quick_sort(int list[], int left, int right, int show)
{
    int i, j;
    int pivot, temp;

    if (left < right)
    {

        i = left;
        j = right + 1;
        pivot = list[left];

        // partition
        while (i < j)
        {
            while (i < right && list[++i] < pivot)
            {
                ++num_compare;
            }
            while (j > left && list[--j] > pivot)
            {
                ++num_compare;
            }
            if (i < j)
            {
                temp = list[j];
                list[j] = list[i];
                list[i] = temp;
            }
        }

        temp = list[j];
        list[j] = list[left];
        list[left] = temp;

        // 매 step에서 list 출력
        if (show)
        {
            print_list(list, left, right);
        }

        // recursive call for each partition
        quick_sort(list, left, j - 1, show);
        quick_sort(list, j + 1, right, show);
    }
}

// merge sort
void merge_sort(int list[], int left, int right, int show)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;

        merge_sort(list, left, mid, show);
        merge_sort(list, mid + 1, right, show);
        merge(list, left, mid, right);

        // 매 step에서 list 출력
        if (show)
        {
            print_list(list, left, right);
        }
    }
}


// merge
void merge(int list[], int left, int mid, int right)
{
    int i, j, k, m;
    int temp[EXP_SIZE];

    i = left;
    j = mid + 1;
    k = left;

    // merge list[left..mid] and list[mid+1..right] into temp list
    while (i <= mid && j <= right)
    {
        if (list[i] <= list[j])
        {
            temp[k++] = list[i++];
        }
        else
        {
            temp[k++] = list[j++];
        }
        ++num_compare;
    }
    if (i > mid)
    {
        for (m = j; m <= right; m++)
            temp[k++] = list[m];
    }
    else
    {
        for (m = i; m <= mid; m++)
            temp[k++] = list[m];
    }

    // copy temp list back to list
    for (m = left; m <= right; m++)
        list[m] = temp[m];
}

// list를 복사
void copy_list(int original[], int list[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        list[i] = original[i];
}

// list를 left 에서 right 까지만 출력
void print_list(int list[], int left, int right)
{
    int i;

    for (i = 0; i < left; i++)
        printf("    ");
    for (i = left; i <= right; i++)
        printf("%4d", list[i]);
    printf("\n");
}

void random_initialize(int list[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        list[i] = rand();
}
