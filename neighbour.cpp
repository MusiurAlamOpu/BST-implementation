#include <iostream>
#include <stdio.h>
#include <queue>

#define GREEN 1
#define YELLOW 2
#define RED 3

using namespace std;

int adj[100][100];
int node, edge;
int color[100];
int time = 1;
int sTime[100];
int parent[100];
int dis[100];

void visitNode(int x){
    color[x] = YELLOW;
    sTime[x] = time;
    ++time;
    cout << "Node: " << x << endl;
    for(int i = 0; i < node; i++){
        cout << color[i] << " ";
    } cout << endl;
    for(int i = 0; i < node; i++){
            if(adj[x][i] == 1){
                if(color[i] == GREEN){
                visitNode(i);
            }
        }
    }
    color[x] = RED;
}
void dfs(){
    for(int i = 0; i < node; i++){
        color[i] = GREEN;
    }
    for(int i = 0; i < node; i++){
        if(color[i] == GREEN){
            visitNode(i);
        }
    }
}

//bfs
void bfs(int startingNode){
    for(int i = 0; i < node; i++){
        color[i] = GREEN;
        dis[i] = INT_MIN;
        parent[i] = -1;
    }
    dis[startingNode] = 0;
    parent[startingNode] = -1;
    queue <int> q;
    q.push(startingNode);
    while(!q.empty()){
        int x;
        x = q.front();
        q.pop();
        color[x] = YELLOW;
        //works
    for(int i = 0; i < node; i++){
        if(adj[x][i] == 1){
            if(color[i] == GREEN){
                q.push(i);
                parent[i] = x;
                dis[i] = dis[x];
            }
        }
    }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    
    cin >> node >> edge;
    int n1, n2;
    for(int i = 0; i < edge; i++){
        cin >> n1 >> n2;
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }
    //printing the graph
    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    //finding neighbours of each node
    for(int i = 0; i < node; i++){
        cout << "Neighbours of " << i << " are : ";
        for(int j = 0; j < node; j++){
            if(adj[i][j] == 1){
                cout << j << " ";
            }
            // cout << endl;
        }
        cout << endl;
    }
    //traversing with DFS(Depth First Search)
    // for(int i = 0; i < node; i++){
    //     cout << color[i] << " ";
    // } cout << endl;
    // dfs();
    // for(int i = 0; i < node; i++){
    //     cout << color[i] << " ";
    // } cout << endl;

    //traversing with BSF(Breath First Search)
    bfs(0);
    cout << parent[3] << endl;
    cout << dis[7] << endl;

    return 0;
}