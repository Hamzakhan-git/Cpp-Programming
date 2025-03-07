#include<iostream>
using namespace std;
struct Node{
int vertex;
Node* next;
};

struct Graph{
    int numVertices;
    Node** adjList;
    int ** adjMatrix;

    //construct
    Graph(int vertices){
        numVertices = vertices;
        adjList = new Node*[numVertices];
        for(int i=0;i<numVertices;i++){
            adjList[i]=nullptr;
        }
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
           adjMatrix[i] = new int[numVertices];
           for(int j=0;j<numVertices;j++){
            adjMatrix[i][j]=0;
           }
        }
    }

    void addEdge(int u,int v){
        Node* newNode = new Node();
        newNode->vertex = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;


         newNode = new Node();
        newNode->vertex = u;
        newNode->next = adjList[v];
        adjList[v] = newNode;
        
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void printAdjList(){
        cout<<"Adjancy List:"<<endl;
        for(int i=0;i<numVertices;i++){
            cout<<i<<"->";
            Node* temp = adjList[i];
            while(temp!=nullptr){
                cout<<temp->vertex<<" ";
                temp= temp->next;
            }
            cout<<endl;
        }

    }
    void printAdjMatrix(){
        cout<<"Adjancy Matrix:"<<endl;
        for(int i=0;i<numVertices;i++){
            for(int j=0;j<numVertices;j++){
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }


};



int main(){
    int vertices,edges;
    cout<<"Enter the number of vertices:";
    cin>>vertices;
    Graph g(vertices);
    cout<<"Enter the number of edges:";
    cin>>edges;
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.printAdjList();
    g.printAdjMatrix();


    return 0;
}