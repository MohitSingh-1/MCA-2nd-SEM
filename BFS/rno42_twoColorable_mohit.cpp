// To redirect the standard input use command: Get-Content rno42_twocolorable_input_mohit.txt | .\rno42_twocolorable_mohit.exe

#include <iostream> 
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& adj,int V){
    vector<int> vis(V,-1);      // here -1 represents no-color , 0:grey and 1:white
    queue<int> q;
    q.push(0);
    vis[0] = 0;    // marking the source as grey

    while(!q.empty()){
        int curr_node = q.front();
        q.pop();

        for(auto neighbor:adj[curr_node]){
            if(vis[neighbor]==-1){      // if neighbor is not visited then adding to the queue
                q.push(neighbor);
                vis[neighbor] = !vis[curr_node];      // marking neighbor as opposite color of parent 
            }
            else if(vis[neighbor]!=vis[curr_node]){     // neighbor is visited but color if diffenet from parent then continue as it is even length cycle
                continue;
            }else{
                return false;
            }
        }
    }
    return true;
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
        cout<<x<<"--"<<y<<endl;
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

    // calling the bfs function to perform BFS traversal on the graph
    bool twoColor = isBipartite(adj,V);       // passing 0 as source node 

    if(twoColor){
        cout<<"Graph is bipartite."<<endl;
    }else{
        cout<<"Grapg is not bipartite."<<endl;
    }
    return 0;
}