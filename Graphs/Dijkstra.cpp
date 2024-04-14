#include<bits/stdc++.h>
using namespace std;


//[u] ---> pair<weight , v> 
//Dijkstra's algorithm on directed graphs.
void dijkstra(unordered_map<int, vector<pair<int, int>>> &g, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq, int*& dist, bool*& visited){
    if(pq.empty()){
        return;
    }
    int curr = pq.top().second;
    visited[curr] = true;
    pq.pop();
    for(auto u : g[curr]){
        int potential_dist = dist[curr]+ u.first;
        if(dist[u.second] > potential_dist){
            //update the distance;
            dist[u.second] = potential_dist;
        }
        // and add it to the priority queue.
        if(!visited[u.second]){
            pq.push(u);
        }
    }
    //now visit the next nearest neghbour.
    if(!visited[pq.top().second]){

        dijkstra(g, pq, dist, visited);
    }
}
int* dijkstra_runner(unordered_map<int, vector<pair<int, int>>>& g, int& source){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    int* dist = new int[g.size()];
    bool* visited = new bool[g.size() + 1]{false};
    fill(dist, dist + g.size(), INT_MAX); // Initialize all distances to infinity
    dist[source] = 0;
    pq.push({0, source});
    dijkstra(g, pq, dist, visited);
    return dist;
}



int main(){

    unordered_map<int, vector<pair<int, int>>> g;
    g[0].push_back({4, 1});
    g[0].push_back({1, 2});
    g[1].push_back({1, 3});
    g[2].push_back({2, 1});
    g[2].push_back({5, 3});
    g[3].push_back({3, 4});
    g[4];
    int source = 0;
    int* shortest_dist = dijkstra_runner(g, source);
    for(int i = 0; i < g.size(); i++){
        cout << shortest_dist[i] << " " ;
    }


}

//Now to print the shortest path:
    // While relaxing a vertex distance, you update the prev[to] = curr;
    //return this prev array. now if you want the path from source to any vertex v:
        // recursive func:
            // if (i == source){cout and return;}
            // cout << i;
            // func(prev[i]);