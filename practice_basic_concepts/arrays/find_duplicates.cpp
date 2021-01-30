#include <iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    //Write your code here
    // NOTE: allowed nums are 0 to n-2, so we can take n-1 size array
    int *outputArray = new int[n-1];
    int item = -1;

	// Initialize tracker outputArray with all -1
    for(int i = 0; i < n-1; i++) {
        outputArray[i] = -1;
    }

	// Check for duplictes
    for(int i=0; i < n; i++) {
        // cout<<arr[i]<<" ";
        item = arr[i];
        // If element is already inserted in outputArray means it is duplicate
        if(outputArray[item] != -1) {
            return item;
        } else {
            outputArray[item] = item;
        }
    }

    // Return last item if no duplicates found
    return item;
    // cout<<"\n";
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
    // Test cases
//     1
// 2
// 0 0
// Output - 0

  // 1
// 6
// 0 2 3 4 1 2
// Output -> 2
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}



	return 0;
}
