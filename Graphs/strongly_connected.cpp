#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

typedef unordered_map<int, vector<int>> graph;
//Dont need edge weights

void dfs(graph& g, bool*& onStack, stack<int>& s, int& counter, int*& unq_id, int*& low_val, int curr){

    onStack[curr] = true;
    unq_id[curr] = low_val[curr] = counter++;
    s.push(curr);


    for (auto nebr : g[curr]){
        if(unq_id[nebr] == -1){
            dfs(g, onStack, s, counter, unq_id, low_val, nebr);
        }
        if(onStack[nebr]){low_val[curr] = min(low_val[nebr], low_val[curr]);}
    } 

    if(low_val[curr] == unq_id[curr]){
        while(s.top() != curr){
            onStack[s.top()] = false;
            low_val[s.top()] = low_val[curr]; //precautionary?
            s.pop();
        }
        onStack[s.top()] = false;
        s.pop();
        
    }
}


void runner(graph& g, bool*& onStack, stack<int>& s, int& counter, int*& low_val, int*& unq_id){

    for(auto keys : g){
        if(unq_id[keys.first] == -1){
            dfs(g, onStack, s, counter, unq_id, low_val, keys.first);
        }
    }

}




int main(){

    // make a graph
    vector<pair<int, int>> edges;
    edges.push_back({3, 4});
    edges.push_back({3, 7});
    edges.push_back({7, 3});
    edges.push_back({7, 5});
    edges.push_back({4, 5});
    edges.push_back({5, 6});
    edges.push_back({6, 4});
    edges.push_back({5, 0});
    edges.push_back({6, 0});
    edges.push_back({6, 2});
    edges.push_back({2, 0});
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    graph g;
    g[4];
    
    //make the graph

    for (auto edge : edges){
        g[edge.first].push_back(edge.second);
    }

    bool* onStack = new bool[g.size()];
    fill(onStack, onStack + g.size(), false);

    stack<int> s;
    int counter = 0;
    
    int* low_val = new int[g.size()];
    int* unq_id = new int[g.size()];
    fill(unq_id, unq_id + g.size(), -1);
    fill(low_val, low_val + g.size(), -1);


    runner(g, onStack, s, counter, low_val, unq_id);
    
    for (int i = 0; i < g.size(); i++){
        cout << low_val[i] << " ";
    }


}