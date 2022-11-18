// =================================================================
//
// File: main.cpp
// Author: Alan Patricio González Bernal
// Date: 17/11/2022
//
// =================================================================

#include <iostream>
#include <list>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#include <string.h>
using namespace std;

int contador;

class Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

   public:
  Graph(int V);
  void addEdge(char src, char dest);
  void DFS(int vertex);
};

// Initialize graph
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(char src, char dest) {
  adjLists[src].push_front(dest);
}

// DFS algorithm
void Graph::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];

  cout << vertex << " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
	  contador++;
}


int main(int argc, char *argv[]) {
  // main, <inputfile.txt> outputfile.txt
  ifstream inputfile;
  ofstream outputfile;

  if(argc != 3){
    cout<< "Invocación incorrecta !" << endl; 
  }
  
  inputfile.open(argv[1]); // entrada a array
  if(inputfile.fail()){

    cout << "No se pudo leer el archivo de entrada bro" << endl;
    return -1;
  
  }

  outputfile.open(argv[2]);
  if(inputfile.fail()){

    cout << "No se pudo abrir el archivo de salida bro" << endl;
    return -1;
  
  }

  //declaración variables 
  int ports, conections, MNP; 
  char reach_ports1, reach_ports2; 

  class Grafofinal{
	public:
	int conections, ports, MNP;
	char reach_ports1, reach_ports2;
  };

	//Creamos el vector de los barcos

	vector <Grafofinal> portGrafo;

	//Primera linea a leer

	inputfile >> conections;
	Graph g(conections);

	//Todos los puertos
	for (int i = 0 ; i < conections ; i++) {

		inputfile >> reach_ports1 >> reach_ports2;
		g.addEdge(reach_ports1, reach_ports2);
		
	}

	// cuantos espacios se puede mover
	inputfile >> ports;

	for (int i = 0 ; i < ports ; i++){

	//Puerto del que sale y los espacios que se moverá
		inputfile >> reach_ports1 >> MNP;
		g.DFS(MNP);
		outputfile << "Case" << i << ":" << contador
		 << " ports not reachable from port" << 
		reach_ports1 << "with MNP = " << MNP;
	}



	 
}

