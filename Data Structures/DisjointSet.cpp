/*
    Author : Arush Kumar
    
    DisjointSet takes a size of array/nodes to initialise
    Two member functions:
    findParent(int node) - gives the ultimate/topmost node of node
    unionByRank(int u,int v) - merges the components u and v using rank
    unionBySize(int u,int v) - does the same work but using size 
     
    Note : Use only one at a time either rank or size 
*/
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
        vector<int>rank,parent,size;
    public:
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
            }
        }
        int findParent(int node)
        {
            if(node==parent[node])
                return node;
            return parent[node]=findParent(parent[node]);
        }
        void unionByRank(int u,int v)
        {
            int ulp_u=findParent(u);
            int ulp_v=findParent(v);
            if(ulp_u!=ulp_v)
            {
                if(rank[ulp_u]<rank[ulp_v])
                {
                    parent[ulp_u]=ulp_v;
                }
                else if(rank[ulp_u]>rank[ulp_v])
                {
                    parent[ulp_v]=ulp_u;
                }
                else
                {
                    parent[ulp_v]=ulp_u;
                    rank[ulp_u]++;
                }
            }
        }
        void unionBySize(int u,int v)
        {
            int ulp_u=findParent(u);
            int ulp_v=findParent(v);
            if(ulp_u!=ulp_v)
            {
                if(size[ulp_u]<size[ulp_v])
                {
                    parent[ulp_u]=ulp_v;
                    size[ulp_v]+=size[ulp_u];
                }
                else
                {
                    parent[ulp_v]=ulp_u;
                    size[ulp_u]+=size[ulp_v];
                }
            }
        }
};

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findParent(3)==ds.findParent(7))
    {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
    ds.unionBySize(3,7);
    if(ds.findParent(3)==ds.findParent(7))
    {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
    return 0;
}