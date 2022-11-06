//these is the program for inserting the number in given array in sorted array meance 
//it will changes the position of numbers 

#include<stdio.h>
void display(int arr[],int a)//these function is works on traversal property in which we will go through
                             // every element of our array
{
    for(int i = 0 ; i < a ; i++ )
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//these function will perform the insertion in the array
int index_insertion(int arr[],  int used_arr,  int element_to_insert,  int total_arr ,int index)
{
 if(used_arr >= total_arr)
 {
     return 1;
 }
 else if(used_arr < total_arr )
{ for(int i = used_arr - 1; i >= index; i--)
   {
       arr[i+1]=arr[i];
   }
   arr[index]=element_to_insert;
   return 0;
   
}

}
int main()
{
    
    int arr[100] = {1,2,34,56};
    int used_arr = 4,total_arr = 100 , index = 3;
    int element_to_insert = 45;
    display(arr , used_arr);

    int result = index_insertion(arr, used_arr, element_to_insert, total_arr,index);
    used_arr = 5; 
      display(arr , used_arr);

      if(result = 0)
      {
          printf("ARRAY IS FULL !!!,insertion is diclined ");
      }
      else 
      {
          printf("array element is insurted succefully");
      }


    
    
}