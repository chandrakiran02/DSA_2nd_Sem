
#include<iostream>
#include<vector>
using namespace std;

//Here I will include some theory on heaps. note that I had already covered the heap assignments, so here i will Just write about
//the new things i have learnt.


//Building a heap from an array using a straightforward approach like pushing each element in an array and perculating up can 
//take a complexity of O(nlogn).

//We can do better tho!

// The above approach can be optimized by observing the fact that the leaf nodes need not to be heapified as they already follow
// the heap property.

// Also, the array representation of the complete binary tree contains the level order traversal of the tree. 
// So the idea is to find the position of the last non-leaf node and perform the heapify operation of each non-leaf node in reverse level order.


// Array = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
// Corresponding Complete Binary Tree is:

//                  1
//               /     \                      //
//            3         5
//         /    \     /  \                   //
//       4      6   13  10
//      / \    / \                           //
//    9   8  15 17

// The task to build a Max-Heap from above array.

// Total Nodes = 11.
//To build the heap, heapify only the nodes: [1, 3, 5, 4, 6] in reverse order.
// Last Non-leaf node index = (11/2) – 1 = 4.
// Therefore, last non-leaf node = 6.

//So for building a maxheap, perculate down starting from 6 all the way to 1.
//This theoritically was proved to take O(n) time !

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

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
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
int main(){
    vector<int> v = {-1 , -2, 11, 99};
    heapsort(v);
    for(int x : v){
        cout << x << " ";
    }

}