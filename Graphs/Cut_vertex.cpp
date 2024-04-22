// finding articulation points.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
typedef unordered_map<int, vector<int>> graph;

void dfs(int curr, int*& parent, int*& inTime, int*& low,
        bool*& visited, graph& g, int& counter, bool*& ans){


            visited[curr] = true;
            low[curr] = inTime[curr] = counter++;


            for(auto neibr : g[curr]){
                if(visited[neibr] && parent[neibr] != curr){
                    //back edge,,
                    low[curr] = min(low[curr], inTime[neibr]);

                }
                else if(!visited[neibr]){
                    parent[neibr] = curr;
                    dfs(neibr, parent, inTime, low, visited, g, counter, ans);
                    //when returning from dfs, check
                    low[curr] = min(low[curr], low[neibr]);
                    //and check if curr node is a cut vertex;
                    if(low[neibr] >= inTime[curr] && parent[curr] != -1){
                        //note that parent[curr] != -1 means it is not the root
                        ans[curr] = true;
                        //it is a cut vertex;
                    }

                }
            }

            if(parent[curr] == -1 && g[curr].size() > 1){
                ans[curr] = true;
            }
        

}


int main(){
    //this is an edge list

    vector<pair<int, int>> edges;
    graph g;
    edges.push_back({0,  1});
    edges.push_back({1, 2});
    edges.push_back({2, 0});
    edges.push_back({0, 3});
    edges.push_back({3, 4});
    // make graph from the edge list
    for (int i = 0; i < edges.size(); i++){

        int from = edges[i].first; 
        int to = edges[i].second;
        g[from].push_back(to);
        g[to].push_back(from);

    }
    // initiliazing the intime array
    int counter = 0;
    int* inTime = new int[g.size()];
    fill(inTime, inTime + g.size() , -1);

    // low array

    int* low = new int[g.size()];
    fill(low, low+ g.size(), -1);

    //visited array , filled with false by default
    bool* visited = new bool[g.size()];
    fill(visited, visited+g.size(), false);
    bool* ans = new bool[g.size()];
    fill(ans, ans+g.size(), false);
    int* parent = new int[g.size()];
    fill(parent, parent + g.size(), -1);


    dfs(0, parent, inTime, low, visited, g, counter, ans);

    for (int i = 0; i < g.size(); i++){
        cout << ans[i] << " ";
    }







}
