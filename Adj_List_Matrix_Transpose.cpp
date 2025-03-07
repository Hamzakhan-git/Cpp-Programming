#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Graph{
    private:
    vector<string> vertices;
    vector<vector<int>> AdjMatrix;
    vector<vector<int>> AdjList;

public:
void AddVertex(const string& vertex){
    vertices.push_back(vertex);
    int newSize = vertices.size();
    AdjMatrix.resize(newSize,vector<int> (newSize,0));
    AdjList.resize(newSize);
}
 void addEdge(const string& from , const string& to){
    int u = findVertexIndex(from);
    int v = findVertexIndex(to);
    if(u == -1 || v== -1){
        cout << "Invalid edge (" << from << ", " << to << "). One or both vertices not found." << endl;
            return;
    }
    AdjMatrix[u][v]==1;
    AdjList[u].push_back(v);
 }

 void displayAdjList(){
    cout<<"Adjancy List:"<<endl;
    for(int i=0;i<vertices.size();i++){
        cout<<vertices[i]<<"->";
        for(auto it : AdjList[i]){
            cout<<vertices[it]<<" ";
        }
        cout<<endl;
    }
 }

 void displayAdjMatrix(){
    cout<<"Adjency Matrix:"<<endl;
    cout<<" ";
    for(const string& vertex : vertices){
        cout<<vertex<<" ";
    }
    cout<<endl;
    for (int i = 0; i < vertices.size(); ++i) {
        cout << vertices[i] << " ";
        for (int j = 0; j < vertices.size(); ++j) {
            cout << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    
 }
}


 private:
 int findVertexIndex(const string& vertex){
    for(int i=0;i< vertices.size();i++){
        if(vertices[i]== vertex)
        return i;
    }
    return -1;
 }
};



int main(){

    return 0;
  }