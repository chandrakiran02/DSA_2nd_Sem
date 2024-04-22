//all sorting algos

#include<iostream>
#include<vector>
using namespace std;



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

// mergesort for linked list

class node{
    public:

    int val;
    node* next;

    node(int data){
        val = data;
        next = nullptr;
    }


};


node* merge_LL(node*& r1, node*& r2){
    
    node* prev = new node(0);
    node* z = prev;
    prev->next = r1;
    node* t1 = r1;
    node* t2 = r2;
    while(t1 && t2){
        if(t1->val >t2->val){
            //t2 comes before t1;

            prev->next = t2;
            node* temp = t2;
            t2 = t2->next;
            temp->next = t1;
            prev = prev->next;
        }
        else{

            t1 = t1->next;
            prev = prev->next;

        }
    }

    if(!t1 && t2){
        prev->next = t2;

    }
    node* tem = z->next;
    delete z;
    return tem;



}
node* mergesort_LL(node*& root){

    // base case
    if (!root || !root->next) {
        return root;
    }

    // then L::

    node* slow = root;
    node* fast = root->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    node* tip2 = slow->next;
    slow->next = nullptr;
    node* tip1 = root;

    // we have divided the ll into two haalves.
    tip1 = mergesort_LL(tip1);
    tip2 = mergesort_LL(tip2);

    node* p = merge_LL(tip1, tip2);
    return p;


}

void print(node* root){
    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    return;
}


/// quicksort


// insertion sort;


void insertion_sort(vector<int>& s){

    for (int i = 1; i < s.size(); i++){

        // take i th element and place it at correct posotion in 0 to i-1.
        int j = i;
        while(j > 0 && s[j] < s[j-1]){

            int temp = s[j];
            s[j] = s[j-1];
            s[j-1] = temp;

            j--;

        }
    }
}


void selection_sort(vector<int> & v){

    for(int i = 0; i < v.size() ;i++){
        //find hte smollest element in 0, n, swap them;

        int index;
        int small = 5e8;

        for(int j = i; j < v.size(); j++){

            if(v[j] < small){
                index = j;
                small = v[j];
            }
        }

        int temp = v[i];
        v[i] = v[index];
        v[index] = temp; 

    }
    return;

}



int main(){

    // vector<int> v;

    // int k; cin >> k;
    // while(k--){
    //     int a; 
    //     cin >> a;
    //     v.push_back(a);
    // }
    // mergesort_v(v, 0, v.size() - 1);

    // for(int x : v){
    //     cout << x << " ";
    // }

    // node* root = new node(5);
    // root->next = new node(4);
    // root->next->next = new node(3);
    // root->next->next->next = new node(2);
    // root->next->next->next->next = new node(1);
    // node* z = mergesort_LL(root);
    // print(z);
    

    vector<int> v;

    int k; cin >> k;
    while(k--){
        int a; 
        cin >> a;
        v.push_back(a);
    }
    insertion_sort(v);

    for(int x : v){
        cout << x << " ";
    }



}