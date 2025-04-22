// To redirect the standard input use command: Get-Content rno42_cycleDetection_input_mohit.txt | .\rno42_cycleDetection_mohit.exe

#include <iostream> 
#include <vector>
using namespace std;

// Depth-First Search recursive function
bool dfs_mohit(vector<vector<int>>& adj,vector<int>& vis,int start_node,int parent){
    vis[start_node] = 1; // Mark the node as visited

    // Recurse for all unvisited neighbors 
    for(auto neighbor:adj[start_node]){
        if(!vis[neighbor]){             
            if(dfs_mohit(adj,vis,neighbor,start_node))return true;
        }
        else if(neighbor != parent)return true; // if the neighbor is visited and not equal to parent then it is a cycle.
    }
    return false;
}

// DFS function to cover all component
bool dfs(vector<vector<int>>& adj,int V){
    vector<int> vis(V,0);  // visited array

    // Start DFS for each unvisited node
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs_mohit(adj,vis,i,-1)){
                return true;
            }
        }
    }
    return false;
}

//A function to build a graph from user input
vector<vector<int>> create_graph_mohit(bool& successful,int &V){
    int vertices,edges;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    cout<<vertices<<endl;
    V = vertices;    // Set the number of vertices
    cout<<"Enter the number of edges: ";
    cin>>edges;
    cout<<edges<<endl;
    
    vector<vector<int>> adj(vertices,vector<int>());
    
    int x,y;
    // It will run till the number of edges
    // we suppose, our graph starts from 0
    cout<<"Now, enter the edges one by one like: '1 2' for edge 1--->2"<<endl;
    for(int i=0;i<edges;i++){
        cin>>x;
        cin>>y; 
        if(x>vertices || y>vertices){
            cout<<"Invelid input....."<<endl;
            successful = false;    // set failure flag
            break;
        }
        adj[x].push_back(y);   // add edge to adjacency list
        cout<<x<<"-->"<<y<<endl;
    }
    return adj;     // return the constructed graph
}


int main(){
    vector<vector<int>> adj;
    bool sucessful = true;
    int V;

    // building the graph
    adj = create_graph_mohit(sucessful,V);

    // if the graph creation was unsuccessful, exit the program
    if(!sucessful)return 0;

    // calling the dfs function to detect cycle, if any
    bool isCycle = dfs(adj,V);

    if(isCycle){
        cout<<"Graph has cycle."<<endl;
    }else{
        cout<<"Graph does not have cycle."<<endl;
    }

    return 0;
}