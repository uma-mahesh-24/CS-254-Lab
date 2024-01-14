#include <iostream>
using namespace std;

int main()
{
    // Taking user input
    int n;
    cout<<"Enter the number of elements:\n";
    cin>>n;

    if(n < 2)
    {
        cout<<"At least 2 elements are required to find the answer.\n";
        return 0;
    }

    int arr[n];
    cout<<"Enter "<<n<<" elements:\n";
    for(int &i : arr)
        cin>>i;
    
    // Initializing a variable to store the position of the maximum value
    int max_pos = 0;
    for(int i = 1; i < n; ++i)
        if(arr[max_pos] < arr[i])
            max_pos = i;
        
    // Now the maximum sum value will be calculated from the rest of the array
    int max_sum = arr[0] + arr[1];
    for(int i = 0; i < n; ++i)
    {
        // To avoid duplication of the maximum value
        if(i == max_pos)
            continue;
        
        max_sum = max(max_sum, arr[max_pos] + arr[i]);
    }

    cout<<"The maximum sum of two elements in this array is "<<max_sum<<".\n";
}