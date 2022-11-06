#include<stdio.h>

void print_array(int arr[],int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}

void selection_sorting(int * arr, int size)
{   int minimum_index; 
    int temp;
    for(int i = 0 ; i < size-1 ; i++)
    {   
         minimum_index = i;
         for(int j = i+1 ; j < size ; j++)
         {
             if(arr[j] <arr[minimum_index] )
             {
                minimum_index = j;
             }
              
         }      temp = arr[i];
                arr[i] =arr[minimum_index];
                arr[minimum_index] = temp;
    }

}


int main ()
{
     int arr[] ={ 12 ,136 ,15 , 40, 5 ,54 ,100 ,87};
     int size = 8;
     print_array(arr,8);
     selection_sorting(arr,8);
     print_array(arr,8);
}