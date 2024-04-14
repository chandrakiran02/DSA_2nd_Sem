#include<bits/stdc++.h>
using namespace std;
struct compare{
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }

};
typedef unordered_map<int, vector<pair<int, int>>> graph;
typedef priority_queue<vector<int>, vector<vector<int>>, compare> pq;
//custom disjoint set for krushkal algo that handles the cycle forming case.
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

void krushkal(graph& g, int& edge_count, graph& ans, pq& p, disjoint_set& s){
    if(edge_count == g.size() - 1){return;}
    
    auto curr = p.top();
    int x = s.find(curr[0]); int y = s.find(curr[2]);
    //Note that when im doing union, the function internally checks if a cycle is forming and takes appropriate action.
    s.Union(x, y);
    if(x!=y){
        ans[curr[0]].push_back({curr[1], curr[2]});
        ans[curr[2]].push_back({curr[1], curr[0]});
    }
    p.pop();
    edge_count++;
    krushkal(g, edge_count, ans, p, s);

}
graph krushkal_runner(graph& g, int edges, vector<vector<int>>& edge){
    bool* edge_exists  = new bool[edges];
    fill(edge_exists, edge_exists+edges, false);
    disjoint_set s(g.size());
    pq Pqueue;
    for(int i = 0; i < edges; i++){
        if(!edge_exists[edge[i][0]] || !edge_exists[edge[i][2]]){
            Pqueue.push({edge[i][0], edge[i][1], edge[i][2]});
        }
    }
    graph ans;
    //runner 
    int cnt = 0;
    krushkal(g, cnt, ans, Pqueue, s);
    return ans;

}


void make_undirected_graph(graph& g, vector<vector<int>>& edges){
    for(auto edge : edges){
        g[edge[0]].push_back({edge[1], edge[2]});
        g[edge[2]].push_back({edge[1], edge[0]});
    }
}

int main(){
    int e;
    cin >> e;
    
    vector<vector<int>> edges(e, vector<int>(3));
    for(int i = 0; i < e; i++){
        for(int j = 0; j < 3; j++){
        cin >> edges[i][j];
        }
    }
    graph g;
    make_undirected_graph(g, edges);
    graph ans = krushkal_runner(g, e, edges);
    cout << endl;
    for(auto x : ans){
        
        for(auto pairs : ans[x.first]){
            cout<< x.first << " " << pairs.first << " " << pairs.second << endl;
        }
    }
    

}