#include <iostream>
using namespace std;

int main()
{
    // file IO
    freopen("input1.txt", "r", stdin);
    // Taking user input

    static int arr[int(1e7)];
    int n = 1e7;
    cout<<"Input taken from file `input1.txt`. Execution in process.\n";
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