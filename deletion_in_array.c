//these code will perform the deletation in our array by replacing index by its upcoming number and so on 

#include<stdio.h>
void show_arr(int arr[],int used_size)
{
    for(int i = 0 ; i < used_size ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void delet_element(int arr[] ,int *used_size ,int total_size , int index)
{
for(int i = index ; i <= *used_size ; i++)
{
   arr[i-1] = arr[i];
}
*used_size = *used_size - 1;
}
int main()
{
   int  arr_f[100] = {1,2,3,4};
   int total_size = 100,used_size = 4, index = 2;
   show_arr(arr_f,used_size);
   delet_element(arr_f,&used_size,total_size,index);
    show_arr(arr_f,used_size);

}