#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool> &rec, vector<vector<int>>& prerequisites) { //O(V + E)

        vis[src] = true;
        rec[src] = true;

        for(int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            if(u == src) {
                if(!vis[v]) {
                    if(isCycle(v, vis, rec, prerequisites)) {
                    return true;
                    }
                } else {
                    if(rec[v]) {
                        return true;
                    }
                }
            }
        }
        rec[src] = false;
        return false;
    }

    void topoSort(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>> &prerequisites) {
        vis[src] = true;

        for(int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            if(u == src) {
                if(!vis[v]) {
                    topoSort(v, vis, s, prerequisites);
                }
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) { //prerequisites = graph
    int V = numCourses;
    vector<bool> vis(V, false);
    vector<bool> rec(V, false);
    vector<int> ans;

    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            if(isCycle(i, vis, rec, prerequisites)) {
                return ans;
            }
        }
    }

    //topological sorting
    vector<bool> vis2(V, false);
    stack<int> s;
    for(int i=0; i<V; i++) {
        if(!vis2[i]) {
            topoSort(i, vis2, s, prerequisites);
        }
    }

    while(s.size() > 0) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
    }
};