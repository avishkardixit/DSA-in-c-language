#include<stdio.h>

void print_array(int arr[],int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}

int partition( int *arr ,int low , int high )
{
    int pivot =arr[low];//the element where partition takes place 

    int i = low+1;
    int j = high;
    int temp;

    do{
    while(arr[i]<= pivot)
    {
        i++;
    }
    while(arr[j] > pivot)
    {
        j--;
    }

    if(i<j)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

    }
    }while(i<j);

    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}

void quick_sort(int *arr,int low,int high )
{
   int partition_index; //it is the index wher the partition takes place meanse lef will low and
                                                                               // right will high
    if (low < high)
    {
    partition_index = partition(arr , low  , high); 
    quick_sort(arr,low ,partition_index - 1 );
    quick_sort(arr,partition_index + 1 ,high);
    }

}

int main ()
{
     int arr[] ={ 12 ,136 ,15 , 40, 5 ,54 ,100 ,87};
     int size = 8;
     print_array(arr,8);
     quick_sort(arr,0 , size - 1);
     print_array(arr,8);
}