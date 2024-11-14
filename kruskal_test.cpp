#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;   
int parent[MAX];

int find(int x){ //function to find the parent of the subset that (x) belongs to
    while(parent[x]!=x){
        parent[x]=parent[parent[x]];
        x=parent[x];    
    }
    return x;
}

void union_(int a,int b){ //function to merge two subsets
    int c=find(a);
    int d=find(b);

    parent[c]=parent[d];
}

int main(){
    int vertices,edges;
    cin>>vertices>>edges;

    vector<pair<int,pair<int,int>>>adjlist;  // vector to store the edges in the form - > {weight, {source, destination}}

    for(int i=0;i<edges;i++){
        int src,dest,wt;
        cin>>src>>dest>>wt;
        adjlist.push_back({wt,{src,dest}}); //inserting each edge into adjacentcy list
    }

    sort(adjlist.begin(),adjlist.end());  // sorting the edges by decreasing order(default)

    for(int i=0;i<vertices;i++){
        parent[i]=i; // initialising the parent of each node as itself
    }

    vector<pair<int,int>>mst_edges; // vector for storing the edges of the minimum spanning tree
    int mst_weight = 0; //initialising the total weight to 0

    for(auto i:adjlist){
        int a=i.second.first;
        int b=i.second.second;

        int cost=i.first;

        if(find(a)!=find(b)){ // if the two vertices are in different subsets, merge them into one
            mst_weight=mst_weight+cost;
            union_(a,b);
            mst_edges.push_back({a,b});
        }
    }

    cout<<"Edges are : "<<endl;
    for(auto i:mst_edges){
        cout<<i.first<<"---"<<i.second<<endl;
    }
    cout<<"Total weight of MST : "<<mst_weight<<endl;

      for(int i=0;i<vertices;i++){
        cout<<parent[i]<<endl;// initialising the parent of each node as itself
    }

}