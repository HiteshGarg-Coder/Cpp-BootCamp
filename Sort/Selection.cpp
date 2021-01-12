//Selection Sort

#include <iostream>

using namespace std;

void selection_sort(int arr[], int size)
{
    int i,j;
    for(i=0;i<size-1;i++)
    {
    	int min_idx = i;
        for(int j=i;j<size;j++)
        {
            if(arr[j] < arr[min_idx])
            {
               min_idx = j;
            }
        }
        swap(arr[i],arr[min_idx]);
    }
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main() 
{
    int size_of_array;
    
    cout<<"Enter size of array to sort: ";
    cin>>size_of_array;
    
    int arr[size_of_array];
    
    cout<<endl<<"Enter elements of array: "<<endl;
    for(int i=0;i<size_of_array;i++)
    {
        cin>>arr[i];
    }
    
    selection_sort(arr,size_of_array);
    return 0;
}

