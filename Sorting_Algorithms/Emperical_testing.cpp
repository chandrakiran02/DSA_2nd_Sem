#include<iostream>
#include<vector>
#include<chrono>
#include<random>
using namespace std;

//MERGESORT

void merge_v(vector<int> & v, int start, int mid, int end){
    // merge start, mid and mid+1 , end;;

    int arr[end - start + 1];
    int k = 0;
    int i = start; int j = mid+1;
    while(i <=mid && j <= end){

        if(v[i] <= v[j]){
            arr[k] = v[i];
            k++; i++;
        }
        else if(v[i] > v[j]){
            arr[k] = v[j];
            k++; j++;
        }

    }

    if(i > mid && j <= end){
        while(j <= end){
            arr[k] = v[j];
            j++; k++;
        }
    }
    if(j > end && i <= mid){
        while(i <= mid){
            arr[k] = v[i];
            i++;k++;
        }
    }

    // after merging , copy them back!!
    int p = 0;
    for(int o = start; o <= end; o++){
        v[o] = arr[p];
        p++;
    }
    
    return;

}
void mergesort_v(vector<int>& v, int start, int end){
    if(start < end){

        mergesort_v(v, start, (end+start)/2);
        mergesort_v(v, (end+start)/2 + 1, end);

        merge_v(v, start, (end+start)/2,  end);
    }
}


//QUICKSORT
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



//HEAPSORT

//Note that if you want to sort a random array using heapsort, then you have to turn it into a heap first 

void perculate_down(vector<int> & v, int curr, int end){


    int k = curr;
    while(k < end){ 
        int index; 
        if(2*k + 2 < end){
            index = (v[2*k+2] > v[2*k+1]) ? 2*k+2 : 2*k+ 1;
        }
        else if(2*k+1 < end){
            if(v[k] < v[2*k+1]){index = 2*k+1;}
            else{return;}
        }
        else {
            return;
        }

        swap(v[k], v[index]);
        k = index;

    }

}

void heapify(vector<int>& v){

    //Note that this creates a min heap.
    //Also note that 0 based indexing is used, i.e l.child = 2*curr + 1, r.child = 2*curr+2

    int end = v.size()/2 - 1;
    for(int i = end; i >= 0; i--){
        perculate_down(v, i, v.size());
    }
}

void heapsort(vector<int>& v){
    heapify(v);
    //inplace heapsort.
    // swap the top node(arr[0]) with "last" which moves towards the start from the end.
    int last = v.size() - 1;
    while(last){
        swap(v[0], v[last]);
        //the current last will be the size of the array.
        perculate_down(v, 0, last);
        last--;
    }
}





void randomize_array(vector<int>& v, int n){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-999, 999);

    for (int i = 0; i < n; ++i) {
        int random_number = dis(gen);
        v.push_back(random_number);
    }
}



void calculate__time(vector<int>& v, int n){
    cout << "For " << n <<  " elements" << endl;
    vector<int> vec(v.begin(), v.end());
    cout << "Mergesort : ";
    auto start = std::chrono::high_resolution_clock::now();
    mergesort_v(vec, 0, vec.size()-1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << duration.count() << endl;
    vec.clear();

    cout << "Quicksort : " ;
    vector<int> vec2(v.begin(), v.end());
    auto start1 = std::chrono::high_resolution_clock::now();
    quicksort(vec2,0, vec2.size() - 1 );
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);

    cout << duration1.count() << endl;
    vec.clear();


    cout << "HeapSort : ";
    vector<int> vec3(v.begin(), v.end());
    auto start2 = std::chrono::high_resolution_clock::now();
    heapsort(vec3);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
    cout << duration2.count() << endl;
    vec.clear(); 


}
int main(){
    vector<int> v;
    for(int i = 200; i <=1000; i = i + 200){

        randomize_array(v, i);
        calculate__time(v, i);
        cout << endl;
    }


}


