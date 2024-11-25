#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void dijkstra(int src, vector<vector<Edge>> graph, int V) { //O((V + E)*logV)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //minHeap
    //pair (dist[v], v);
    vector<int> dist(V, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(pq.size() > 0) {
        int u = pq.top().second;
        pq.pop();

        vector<Edge> edges = graph[u];
        for(Edge e : edges) { //e.v, e.wt
            if(dist[e.v] > dist[u] + e.wt) {
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }

    for(int d : dist) {
        cout << d << " ";
    } 
    cout << endl; 
}

void bellmanFord(vector<vector<Edge>> graph, int V, int src) { //O(V*E)
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i=0; i<V-1; i++) {
        for(int u=0; u<V; u++) {
            for(Edge e : graph[u]) {
                if(dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    for(int i=0; i<V; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<Edge>> graph1(6);

    graph1[0].push_back(Edge(1, 2));
    graph1[0].push_back(Edge(2, 4));

    graph1[1].push_back(Edge(2, 1)); 
    graph1[1].push_back(Edge(3, 7));

    graph1[2].push_back(Edge(4, 3));

    graph1[3].push_back(Edge(5, 1));

    graph1[4].push_back(Edge(3, 2));
    graph1[4].push_back(Edge(3, 5));

    dijkstra(0, graph1, 6);

    //Bellman Ford Graph
    vector<vector<Edge>> graph2(5);

    graph2[0].push_back(Edge(1, 2));
    graph2[0].push_back(Edge(2, 4));

    graph2[1].push_back(Edge(2, -4));

    graph2[2].push_back(Edge(3, 2));
    
    graph2[3].push_back(Edge(4, 4));

    bellmanFord(graph2, 5, 0);
    return 0;
}