#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) { //u---v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print() {
        for(int u=0; u<V; u++) { //0,1, 2, 3, 4
            list<int> neighbors = l[u];
            cout << u << " : ";
            for(int v : neighbors) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void bfsHelper(int st, vector<bool> &vis) { //O(V + E)
        queue<int> q;
        q.push(st);
        vis[st] = true;

        while(q.size() > 0) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            list<int> neighbors = l[u]; //u---v
            for(int v : neighbors) {
                //to ensure that one node is added only once to queue
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }

    void bfs() { // for disconnected components
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                bfsHelper(i, vis);
                cout << endl;
            }
        }
    }

    void dfsHelper(int u, vector<bool> &vis) { 
        vis[u] = true;
        cout << u << " ";

        list<int> neighbors = l[u];
        for(int v : neighbors) {
            if(!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    // void dfs() { //O(V + E)
    //     vector<bool> vis(V, false);
    //     dfsHelper(0, vis);
    //     cout << endl;
    // }

    void dfs() { //for disconnected components
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfsHelper(i, vis);
                cout << endl;
            }
        }

        cout << endl;
    }
};

int main() {
    Graph graph(7);
    
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    graph.bfs();
    graph.dfs();

    return 0;
}