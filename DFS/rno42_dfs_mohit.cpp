// To redirect the standard input use command: Get-Content rno42_dfs_input_mohit.txt | .\rno42_dfs_mohit.exe

#include <iostream> 
#include <vector>
using namespace std;

// Depth-First Search recursive function
void dfs_mohit(vector<vector<int>>& adj,vector<int>& vis,int start_node){
    vis[start_node] = 1; // Mark the node as visited
    cout<<start_node<<" ";  // Output the node

    // Recur for all unvisited adjacent nodes
    for(auto it:adj[start_node]){
        if(!vis[it]){
            dfs_mohit(adj,vis,it);
        }
    }
}

// DFS function to cover all component
void dfs(vector<vector<int>>& adj,int V){
    cout<<"DFS output : ";
    vector<int> vis(V,0);  // visited array

    // Start DFS for each unvisited node
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs_mohit(adj,vis,i);
        }
    }
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

    // calling the dfs function to perform DFS traversal on the graph
    dfs(adj,V);

    return 0;
}