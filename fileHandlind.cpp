#include <iostream>
#include<fstream>
using namespace std;
void writeFile(const string& filename,int** matrix,int size)
{
    ofstream outfile(filename);
    if(!outfile){
        cout<<"Error:file not exists"<<endl;
        return;
    }
    outfile<<size<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            outfile<<matrix[i][j]<<" ";
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
int size;
infile>>size;
int** matrix = new int*[size];
for(int i=0;i<size;i++){
    matrix[i] = new int[size];
}
cout<<"Adjancy Matrix from File"<<filename<<":"<<endl;
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        infile>>matrix[i][j];
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
}
infile.close();
}

int main() {
    int size;
    cout<<"Enter the size of matirx: "<<endl;
    cin>>size;
    int** adjMatrix = new int*[size];
    for(int i=0;i<size;i++){
        adjMatrix[i] = new int[size];
    for(int j=0;j<size;j++){
        adjMatrix[i][j]=0;
    }
    }
    cout<<"Enter number of edges:"<<endl;
    int edge;
    cin>>edge;
    cout<<"Enter edges (format: u v):"<<endl;
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        adjMatrix[u][v] =1;
    }
    string filename = "Adj_Matrix.txt";
    writeFile(filename,adjMatrix,size);

    readFile(filename);
   
    return 0;
}