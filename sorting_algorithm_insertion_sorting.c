#include<stdio.h>


void print_array(int arr[],int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}

void insert_sort(int *arr , int size)
{   int key,j;
    for(int i = 1 ; i <= size - 1 ; i++)
    {
        key = arr[i];
        j = i-1;

        while(j>= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
     int arr[] ={ 12 ,13 ,15 , 40, 50 ,54 ,100 ,87};
     int size = 8;
     print_array(arr,8);
     insert_sort(arr,8);
     print_array(arr,8);
}