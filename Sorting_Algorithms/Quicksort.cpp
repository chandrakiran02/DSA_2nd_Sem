#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(vector<int>& arr, int lo, int hi) {
    if (lo >= hi) {  // Base case: sub-array with one or zero elements is already sorted
        return;
    }
    int mid = (lo + hi) / 2;
    if (arr[lo] > arr[mid]) {
        swap(arr[lo], arr[mid]);
    }
    if (arr[mid] > arr[hi]) {
        swap(arr[mid], arr[hi]);
    }
    if (arr[lo] > arr[hi]) {
        swap(arr[lo], arr[hi]);
    }

    // choose a pivot (here, the mid element)

    swap(arr[mid], arr[hi-1]);

    // partitioning
    int i = lo + 1; 
    int j = hi -1;
    while(i < j){
        while(arr[i] < arr[hi-1]){i++;}
        while(arr[j] >= arr[hi-1]){j--;}
        if(i < j){swap(arr[i], arr[j]);}
    }
    swap(arr[i], arr[hi-1]);  // move the pivot to its coorrrect position
    
    quicksort(arr, lo, i-1);
    quicksort(arr, i + 1, hi); 
}

int main() {
    vector<int> arr = {2 , -999, 22, 2 ,1, 2,  2 , 33 , 0, -223, 2, 2,2};
    quicksort(arr, 0, arr.size() - 1);
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
