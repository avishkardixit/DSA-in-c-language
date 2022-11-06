#include<stdio.h>
#include<stdlib.h>

void print_array(int arr[],int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}

void merg(int * arr,int low ,int mid ,int high)
{
       int i , j , k ;
       int arr_2[high + 1];
       i = low;
       j = mid+1;
       k = low;
       while(i <= mid && j <= high)
       {  
           if(arr[i]<arr[j])
           {
               arr_2[k]=arr[i];
               i++;k++;
           }
           else
           {
               arr_2[k]=arr[j];
               j++,k++;
           }
        
       }
       while(i<=mid)
       {
           arr_2[k] = arr[i];
           k++;i++;
       }
       while(j<=high)
       {
           arr_2[k] = arr[j];
           k++;j++;
       }
       for(int i = low ; i <= high ; i++)
       {
            arr[i] = arr_2[i];
       }
       
}

void merg_sort(int * arr,int low ,int high)
{ int mid;
    if(low<high)
    {
       mid = (low +high)/2;
       merg_sort(arr,low ,mid);
       merg_sort(arr,mid+1,high);
       merg(arr ,low , mid , high);
    }
    

}

int main ()
{
     int arr[] ={ 12 ,136 ,15 , 40, 5 ,5, 54 ,100 ,87};
     int size = 9;
     print_array(arr,9);
      merg_sort(arr,0,9);
     print_array(arr,9);
}