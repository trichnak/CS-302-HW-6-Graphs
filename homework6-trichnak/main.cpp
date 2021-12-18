#include "Graph.h"
#include "City.h"
#include <iostream>
#include <string>
#include <sstream>

#define MAX_DISTANCE 999999
#define INVALID_DISTANCE -1

using namespace std;

void display(string n) {
    cout << n << endl;
}

void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

void generatePaths(ofstream& ofile, Graph<City>* graph, vector<City> cities, int start, int end) {
    if (start == end) {
        int totLength = 0;
        int edgeLength;
        for(int i = 0; i < cities.size(); i++) {
            ofile << cities[i] << "->";
            if(i >= 4) {
                edgeLength = graph->getEdgeWeight(cities[i].position, cities[0].position);
            }
            else {
                edgeLength = graph->getEdgeWeight(cities[i].position, cities[i+1].position);
            }  

            if(edgeLength > 0) {
                totLength += edgeLength;
                if(i == 4) {
                    ofile << cities[0] << ": "; 
                }
            }
            else {
                ofile << "Invalid Path: ";
                totLength = INVALID_DISTANCE;
                break;
            } 
        }
        ofile << totLength << " miles" << endl;
    }
    else {
        for (int i = start; i <= end; i++) {
            swap(cities[start], cities[i]);
            generatePaths(ofile, graph, cities, start+1, end);
            swap(cities[start], cities[i]);
        }
    }
}

string findShortestPath(ifstream& ifile) {
    string line, token, shortest = "";
    int length, min = MAX_DISTANCE;
    while(getline(ifile, line)) {
        token = line.substr(line.find(": ") + 2, line.find(" miles"));
        stringstream convert(token);
        convert >> length;
        if(length < min && length > 0) {
            min = length;
            shortest = line;
        }
    }
    return shortest;
}

int main() {
    City reno("Reno", 0), sanFran("San Francisco", 1), saltLake("Salt Lake City", 2), seattle("Seattle", 3), lasVegas("Las Vegas", 4);
    vector<City> cities {reno, sanFran, saltLake, seattle, lasVegas};
    Graph<City> graph(cities.size(), cities);
    ofstream ofile;
    ifstream ifile;

    graph.add(reno.position, sanFran.position, 218);
    graph.add(reno.position, saltLake.position, 518);
    graph.add(reno.position, seattle.position, 704);
    graph.add(reno.position, lasVegas.position, 438);
    graph.add(sanFran.position, seattle.position, 808);
    graph.add(sanFran.position, lasVegas.position, 569);
    graph.add(saltLake.position, seattle.position, 830);
    graph.add(saltLake.position, lasVegas.position, 515);

    ofile.open("paths.txt");
    if(ofile.is_open()) {
        generatePaths(ofile, &graph, cities, 1, 4);
    }
    ofile.close();

    ifile.open("paths.txt");
    if(ifile.is_open()) {
        ofile.open("paths.txt", std::ios_base::app);
        if(ofile.is_open()) {
            ofile << "\nShortest Path: \n" << findShortestPath(ifile);
        }
        ofile.close();
    }
    ifile.close();

    return 0;
}