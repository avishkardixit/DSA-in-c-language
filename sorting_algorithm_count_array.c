

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void print_array(int arr[],int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}


void count_sort(int *arr , int size)
{   int max_element = 0;
    int i,j;
    for( i = 0 ; i < size ; i++)
    {
        if(arr[i]>max_element)
        {
           max_element = arr[i];
        }
    }
    

    int* count = (int *) malloc ((max_element+1)*sizeof(int));
    for ( i =  0 ; i < max_element+1 ;i++)
    {
        count [i] = 0;
    }

     for ( i =  0 ; i < size ;i++)
    {
        count[arr[i]]= count[arr[i]] + 1;
    }
    i = 0 ;
    j = 0;

    while(i < max_element+1)
    {
        if(count[i]> 0)
        {
            arr[j] = i;
            count[i] = count[i] -1;
            j++;
        }
        else
        {
            i++;
        }
    }

}

int main ()
{
     int arr[] ={ 12 ,136 ,15 , 40, 5 ,54 ,100 ,87};
     int size = 8;
     print_array(arr,8);
      count_sort(arr,size);
     print_array(arr,8);
}