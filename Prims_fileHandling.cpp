#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<climits>
using namespace std;

vector<vector<int>> created_Matrix(const string& filename, vector<char>& vertices){
    ifstream inputFile(filename);
    if(!inputFile){
        cerr<<"Error: File not found"<<endl;
        exit(1);
    }
    string line;
    getline(inputFile, line);
    for(char vertex : line){
        if(vertex != ' ') vertices.push_back(vertex);
    }
    int n = vertices.size();
    vector<vector<int>> adjMatrix(n, vector<int> (n,0));
    map<char, int> VertexIndex;
    for(int i=0;i<n;i++){
        VertexIndex[vertices[i]] =i;
    }
    getline(inputFile, line);
    for(size_t i=0;i<line.size();i++){
        if(line[i]=='('){
            char u = line[i+1];
            char v = line[i+3];
            int weight = line[i+5]-'0';
            int uIndex = VertexIndex[u];
            int vIndex = VertexIndex[v];
            adjMatrix[uIndex][vIndex] = weight;
            adjMatrix[vIndex][uIndex] = weight;
        }
    }
    inputFile.close();
    return adjMatrix;

}

void PrimsMST(vector<vector<int>>& adjMatrix, vector<char>& vertices){
    int n= vertices.size();
    vector<int> key(n,INT_MAX);
    vector<bool> vis(n, false);
    vector<int> parent(n,-1);
    key[0]=0;
    parent[0] =-1;
    for(int count =0;count<n-1;count++){
        int minKey = INT_MAX , u;
        for(int v=0;v<n;v++){
            if(!vis[v] && key[v]< minKey){
                minKey= key[v];
                u =v;
            }
        }
        vis[u] = true;

        for(int v=0;v<n;v++){
            if(adjMatrix[u][v] && !vis[v] && adjMatrix[u][v]<key[v]){
                key[v] = adjMatrix[u][v];
                parent[v]=u;
            }
        }
    }
    cout<<"MST :"<<endl;
    int totalWt =0;
    for(int i=1;i<n;i++){
        cout<<vertices[parent[i]]<<"-"<<vertices[i]<<"-"<<adjMatrix[parent[i]][i]<<endl;
        totalWt+= adjMatrix[parent[i]][i];
    }
    cout<<"Total Weight:"<<totalWt<<endl;
}



int main(){
vector<char> vertices;
string filename ="MST.txt";
vector<vector<int>> adjMatrix = created_Matrix(filename,vertices);
for(const auto& row : adjMatrix){
    for(const auto& val: row){
        cout<<val<<" ";
    }
    cout<<endl;
}
PrimsMST(adjMatrix,vertices);
    return 0;
}