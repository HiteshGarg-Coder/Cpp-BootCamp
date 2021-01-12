#include <iostream>

using namespace std;

void Bubble_Sort(int arr[], int size_of_array)
{
    int i,j;
    for(i=0;i<size_of_array;i++)
    {
        for(j=i;j<size_of_array;j++)
        {
            if(arr[i] > arr[j])
            {
                arr[i] = (arr[i] + arr[j]) - (arr[j] = arr[i]);
            }
        }
    }
    for(i=0;i<size_of_array;i++)
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
    
    Bubble_Sort(arr,size_of_array);
    return 0;
}

