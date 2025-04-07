
#include <iostream>
#include<fstream>
using namespace std;
struct Node{
    int vertex;
    Node* next;
};
class Graph{
    private:
    int numVertex;
    Node** adjList;
    public:
    Graph(int vetices){
        numVertex = vetices;
        adjList = new Node*[numVertex];
        for(int i=0;i<numVertex;i++){
            adjList[i] = nullptr;
        }
    }
    void addEdge(int u,int v){
        Node* newNode = new Node();
        newNode->vertex=v;
        newNode->next = adjList[u];
        adjList[u]=newNode;
    }
    void writeFile(const string& filename)
    {
        ofstream outfile(filename);
        if(!outfile){
            cout<<"Error:file not exists"<<endl;
            return;
        }
        outfile<<numVertex<<endl;
        for(int i=0;i<numVertex;i++){
            outfile<<i;
            Node* temp = adjList[i];
            while(temp!=nullptr){
                outfile<<"->"<<temp->vertex;
                temp=temp->next;
            }
            outfile<<endl;
        }
        
        outfile.close();
        cout<<"Adj matrix has been written in the file"<<filename<<endl;
    }
    void readFile(const string& filename){
    ifstream infile(filename);
    if(!infile){
        cout<<"Error:Can't read file"<<endl;
        return;
    }
    int vertices;
    infile>>vertices;
    cout<<"Adjancy Matrix from File"<<filename<<":"<<endl;
    string line;
    getline(infile,line);
    while(getline(infile,line)){
        cout<<line<<endl;
    }
    infile.close();
    }
    void displayAdjList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < numVertex; i++) {
            cout << i;
            Node* temp = adjList[i];
            while (temp != nullptr) {
                cout << " -> " << temp->vertex;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};


int main() {
    int vertices;
    cout<<"Enter the number of vertex of matirx: "<<endl;
    cin>>vertices;

   Graph g(vertices);
    cout<<"Enter number of edges:"<<endl;
    int edge;
    cin>>edge;
    cout<<"Enter edges (format: u v):"<<endl;
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    string filename = "Adj_List.txt";
    g.writeFile(filename);

    g.readFile(filename);
   
    return 0;
}