//these program will run binary search of number by dividing array in parts and comparing it 

#include<stdio.h>
int binarry_search(int arr[],int size,int element)
{
    int low , mid , high ;
    low = 0;
    high = size-1;
   

while(low<=high)//these loop will check whether the mid of our array is requred array or not and if not it will check 
                //whether the element is lower than mid or greater than mid then it will take that segment of array wher the
                //element is and continue that dividation untile element is equal to mid
{  
     mid = (low+high)/2;

    if(arr[mid] == element)
    {
        return mid;
    }
    if(arr[mid]<element)
    {
        low = mid + 1;
    }
    else
    {
        high = mid -1;
    }
}
return -1;
}
int main()
{
    int arr[100] = {12,34,445,666,777,779,867};
    int element = 777;
    int size = 7;
   int result =  binarry_search( arr, size, element);
       
    if(result >= 0) 
    {
        printf("element %d found at %d th index",element,result);
    }
    if(result == -1)
    {
         printf("element not found !!!");
    }

}