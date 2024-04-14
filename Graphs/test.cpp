#include<bits/stdc++.h>

using namespace std;

//custom disjoint set
class disjoint_set{
    public:
    int* parent;
    disjoint_set(int size){
        parent = new int[size];
        fill(parent, parent+size, -1);
    }


    int find(int x){
        if(parent[x]<0){return x;}
        else{
            return find(parent[x]);
        }
    }

    void Union(int node1, int node2){
        //we want to union them iff they dont belong to same disjoint set.
        int x = find(node1); int y = find(node2);
        if(x != y){
            //union by size

            if(abs(parent[x]) >= abs(parent[y])){
                parent[x]+= parent[y];
                parent[y] = x;
                
            }
            else{
                parent[y] += parent[x];
                parent[x] = y;
            }
        }
    }

};

int main(){
    disjoint_set x(10);
    for(int i = 0; i < 10; i++){
        cout << x.parent[i] << " ";
    }
    x.Union(1, 2);
    cout << x.find(2);
}