#include<stdio.h>
void print_array(int arr[],int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}

// void adaptive_bubble_sort(int *arr, int size)//these method will stop sorting when array is fully sorted
// {   int temp;
//     int is_sorted = 0;
//      for(int i = 0 ; i < size-1 ; i++)//for number of passes 
//     {    printf("number of pass : %d\n",i+1);
//          is_sorted = 1;
//         for(int j = 0 ; j < size-1-i ; j++)//for comparisons in each pass
//         {  
//             if(arr[j] > arr[j+1])
//             {
//                temp = arr[j];
//                arr[j] =arr[j+1];
//                arr[j+1] = temp;
//                  is_sorted = 0;
//             }
          
//         }  
//         if(is_sorted)
//             {
//                 return;
//             }
//     }
// }
void bubble_sort(int *arr, int size)//these method will sort array till the end pass completed 
{   int temp;
    
     for(int i = 0 ; i < size-1 ; i++)//for number of passes 
    {    printf("number of pass : %d\n",i+1);
         
        for(int j = 0 ; j < size-1-i ; j++)//for comparisons in each pass
        {  
            if(arr[j] > arr[j+1])
            {
               temp = arr[j];
               arr[j] =arr[j+1];
               arr[j+1] = temp;
            
            }
          
        }  
        
    }
}

int main()
{
    int arr[] ={ 12 ,13 ,15 ,40,50 ,54 , 344 , 2334 ,100 ,87};
    int size = 10;

    print_array(arr,size);
    // adaptive_bubble_sort(arr,size);
    print_array(arr,size);
    bubble_sort(arr,size);
}