#include<bits/stdc++.h>
using namespace std;



void bfs(unordered_map<int, vector<int>> & g, bool* &visited, queue<int>& q){
    //O(2E + V) time complexity.
    if(q.empty()){
        return;
    }

    int current = q.front();
    q.pop();

    //process the current

    cout << current << " ";

    //then plan to visit its adjacent nodes.

    for(auto i : g[current]){

        // plan to visit only the nodes which are not visited.

        if(!visited[i]){
            // this is the parent thing that i will use to find shortest path.
            // parent[i] = current;
            
            visited[i] = true;
            //push to queue.
            q.push(i);
        }
       
    }
    //recursively go to any of its adjacent vertices.
    bfs(g, visited, q);
}

int connected_components(unordered_map<int, vector<int>> & g, bool* &visited, queue<int>& q){
    int count = 0; 
    for (int i = 0; i < g.size()+1; i++){
        if(!visited[i]){
            count++;
            bfs(g, visited, q);
        }
    }
    return count;
}


// depth first search ::


void dfs(unordered_map<int, vector<int>> & g, bool* &visited, int current, int*& parent_dfs, int& cycle_count){

    
    visited[current] = true;



    for(int u : g[current]){

        if(!visited[u]){
            
            parent_dfs[u] = current;
            dfs(g, visited, u, parent_dfs, cycle_count);

        }
        else if(visited[u] && parent_dfs[u] != current){
            cycle_count++;
            return;
            
        }
        
    }

    return;

}


bool two_colourable(){}

int detect_cycle(unordered_map<int, vector<int>> & g ){

    //maintain a parent structure in dfs
    // it wont

}

bool detect_cycle_directed(unordered_map<int, vector<int>> & g){}

void topological_sort(vector<int>& ans, unordered_map<int, vector<int>>&g, int key, bool*& visited){
    visited[key] = true;
    for(int u : g[key]){
        if(!visited[u]){
            topological_sort(ans, g, u, visited);
        }
    }
    ans.push_back(key);
}

void runner_code_for_topsort(vector<int> & ans, unordered_map<int, vector<int>> & g, bool*& visited){

    for (auto keys : g){
        if(!visited[keys.first]){
            topological_sort(ans, g, keys.first, visited);
        }
    }
    reverse(ans.begin(), ans.end());
    
}

void strongly_connected_components(unordered_map<int, vector<int>>&g , bool* visited, int& cntr, int* & unq_val, map<int, int>& connected, stack<int>& s, bool* Onstack, int curr){
    s.push(curr);
    Onstack[curr] = true;
    visited[curr] = true;
    unq_val[curr] = connected[curr] = cntr++;

    for(int u : g[curr]){
        if(!visited[u]){
            strongly_connected_components(g, visited, cntr, unq_val, connected, s, Onstack, u);
        }
        // on call back: 
        if(Onstack[u]){connected[curr] = min(connected[curr], connected[u]);}
    }

    if(unq_val[curr] = connected[curr]){
        while(s.top() != curr){
            s.pop();
            Onstack[s.top()] = false;
        }
        s.pop();
    }

}

void strongly_connected_components_runner(unordered_map<int, vector<int>>&g , bool* visited, int& cntr, int* & unq_val, map<int, int> &connected, stack<int>& s, bool* Onstack, int curr){

    for(auto pair: g){
        if(!visited[pair.first]){
            strongly_connected_components(g, visited, cntr, unq_val, connected, s, Onstack, pair.first);
        }
    }

}

int main(){
    

    unordered_map<int, vector<int>> g;
    unordered_map<int, vector<int>> t;

    t[2]  = {1, 3};
    t[1] = {4};
    t[3] = {4};

    queue<int> q;
    q.push(1);

    g[1] = {2, 3};
    g[2] = {1, 3, 4, 5 };
    g[3] = {1, 2, 5};
    g[4] = {2};
    g[5] = {2, 3};

    bool* visited = new bool[g.size() + 1]{false};
    int * parent = new int[g.size() + 1]{0};
    // visited[1] = true; // only if doing bfs, not for dfs
    // bfs(g, visited, q);

    // cout << endl;

    // for (int i = 1; i < g.size() + 1; i++){
    //     cout << parent[i] << " ";
    // }

    //Parent is used to find the shortest path recursively.
    //as given in sksekia.


    // cout << endl;
    // int i = 5;
    // while(parent[i] != 0){
    //     cout << i << " ";
    //     i = parent[i];
    // }

    // There are two points to remember when using breadth-first search to find a
    // shortest path from x to y: First, the shortest path tree is only useful if BFS was
    // performed with x as the root of the search. Second, BFS gives the shortest path
    // only if the graph is unweighted

    //CONNECTED COMPONENTS  : 

    // cout << connected_components(g, visited, q) <<endl;


    // You can also check wheather the graph can be 2colourable. aka bipartite.
    // the following code is not written but, you can visit Sksekia pg 180 to know about
    // the implementation.
    // More details about the chromatic number problem on its catalouge.

    // =========================================================================================//


    // DEPTH FIRST SEARCH.
   
   
    // int c = 0;
    // int* parent_dfs = new int[g.size()+ 1]{0};
    //  dfs(g, visited, 1, parent_dfs, c);
    //  cout << c ;

    // The other important property of a depth-first search is that it partitions the
    // edges of an undirected graph into exactly two classes: tree edges and back edges

    //: DFS organizes vertices by entry/exit times, and edges
    // into tree and back edges. This organization is what gives DFS its real power.

    // Thus there are two potential times to process each edge (x,y), namely when
    // exploring x and when exploring y.
    // we can also process the vertex v while coming back or while going as i did in the dfs algo 
    //that i wrote. (it processes teh vertices before we go to the next vertex)



    //5.9.1 Finding Cycles


    // Back edges are the key to finding a cycle in an undirected graph. If there is no
    // back edge, all edges are tree edges, and no cycle exists in a tree. But any back edge
    // going from x to an ancestor y creates a cycle with the tree path from y to x. Such
    // a cycle is easy to find using dfs

    //HOW DO U TELLL WHEATHER AN EDGE IS A BACK EDGE? 
    // if (parent[x] != y && visited[x] == true) <-- this condition.
    // note that this only detects cycles, possibly also counts the number of Cycles.
    //NOTE : IT DOSENT COUNT ALL THE CYCLES. THO, YOU CAN USE IT TO JUST DETECT CYCLES.



    //CYCLE DETECTION ON DIRECTED GRAPHS, THE ABOVE DFS TECHNIQUE DOSENT WORK.
    // INSTEAD USE AN EXTRA DATA STRUCTURE CALLED dfs[size] to mark/unmark the the entry and exit times. 
    //the condition is that if you encounter a visited node with dfs[u] marked 1, i.e dfs called on that node
    // then the cycle has been detected. Think of this! dfs has been called means that the vertex u,
    //is part of the loop!


    //TOPOLOGICAL SORTING.
            // Cant be possible on a directed cycle.
            // ONLY POSSIBLE ON A DIRECTED ACYCLIC GRAPH.
            //Only on a directed graph. 
            // u-v such that u comes always before v.
            // the algorithm is simple.
            // DO A DFS (for all the nodes).
            // in the dfs, when you BACKTRACK from a node, add that node to the stack.
            
    //RUNNER CODE FOR TOPSORT.
        // vector<int> ans;
        // runner_code_for_topsort(ans, t, visited);
        // for(int x : ans){cout << x << " ";}

    

    //STRONGLY CONNECTED COMPONENTS.

        //THERE EXISTS A DIRECTED PATH BETWEEN ANY TWO VERTICES U, V ()IN THE SUBGRAPH.
        //The algorithm is known as Tarjan's strogly connected algo 
        

        //Short explanation for the code:
        // 1. You need to give each vertex its unique ID (a number), While doing a dfs.
        // 1.5 : you also need to have a low_nerest value (this is what decides the component, essentially, all the set of nodes which __have_ the 
        //             same value of this belong to one strongly connected component.)
        // 2. You need to maintain a set. (or a  hashmap) c
        // 3. AND ALL OTHER THINGS THAT YOU NEED FOR A NORMAL DFS.

        // ,,, The Algo.::


        // U need to run a modified version of dfs on every vertex as source.


        // dfs::

        //     put a global counter = 0 to give unique ids to each node(increment when u visit a node.)

        //     while doing dfs, push the visited nodes to set. and set the nodes id and low_nerst to current counter value.
        //     if you encounter a recursive callback, then ::
        //                     if the discovered node from which we are recursing back is on the call stack : 
        //                             set the descovered node's low_nerse val to min(discoverer's low_ val and discovered's low_val).
        //                     else ::
        //                             do nothing.
        //                      Please do notethat to know if you are at thebeggining of a strongly connected component,, 
                                            // its UNQ_ID == COMPONENT_VAL.   

                                                //NOW IF THIS CONDITION IS MET, YOU CAN POP OFF THE NODES UPTILL THIS NODE IN THE STACK AND MARK THEM FALSE 
                                                    // IN THE OnStack ARRAY.


        // DO THIS UNTL  ALL NODES ARE VISITED.
        // THE NODES WITH THE SAME LOW_NEARST VAL ARE THE GROUP OF STRONGLY CONNECTED COMPONENTS ::))













}