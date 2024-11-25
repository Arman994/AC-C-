// https://leetcode.com/problem-list/topological-sort/

#include <iostream>
#include <vector>
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

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) { //prerequisites = graph
    int V = numCourses;
    vector<bool> vis(V, false);
    vector<bool> rec(V, false);

    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            if(isCycle(i, vis, rec, prerequisites)) {
                return false;
            }
        }
    }

     return true;   
    }
};