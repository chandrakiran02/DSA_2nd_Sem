#include <bits/stdc++.h>
using namespace std;


struct compare{
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }

};

typedef unordered_map<int, vector<pair<int, int>>> graph;
typedef priority_queue<vector<int>, vector<vector<int>>, compare> pq;


//tuple<we>
void prims(graph& g, bool*& visited, pq& pQueue, graph &ans, int& edge_count){
    if(edge_count == g.size()-1){return;}
    int curr = pQueue.top()[2];
    pQueue.pop();
    for(auto neighbour : g[curr]){
        if(!visited[neighbour.second]){
            vector<int> edge = {curr, neighbour.first, neighbour.second};
            pQueue.push(edge);
        }
    }
    visited[curr] = true;
    while(!pQueue.empty() && visited[pQueue.top()[2]]){
        pQueue.pop();
    }
    if(!pQueue.empty()){
        ans[pQueue.top()[0]].push_back({pQueue.top()[1], pQueue.top()[2]});
        ans[pQueue.top()[2]].push_back({pQueue.top()[1], pQueue.top()[0]});
        edge_count++;
    }
    prims(g, visited, pQueue, ans, edge_count);
}

graph prims_runner(graph& g, int source){
    bool* visited = new bool[g.size()+1]();
    pq pQueue;
    pQueue.push({0, 0, 0});
    graph ans; int edge_cnt = 0;
    prims(g ,visited, pQueue, ans, edge_cnt);
    delete[] visited;
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
    graph ans = prims_runner(g, 0);
    cout << endl;
    for(auto x : ans){
        
        for(auto pairs : ans[x.first]){
            cout<< x.first << " " << pairs.first << " " << pairs.second << endl;
        }
    }
    

    return 0;
}


// Indeed, all spanning trees of an unweighted (or equally weighted) graph G are
// minimum spanning trees, since each contains exactly n − 1 equal-weight edges.
// Such a spanning tree can be found using depth-first or breadth-first search.