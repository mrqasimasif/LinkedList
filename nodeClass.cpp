//The nodeClass to serve the nodes that act as LIST objects

#include<iostream>
#include<fstream>
using namespace std;

class cNode {
    //data members
	int data;
public:
    //reference to nextNode of list
	cNode *nextNode;

    //Constructors
	cNode() { data = 0; nextNode = NULL; }
	cNode(int number) { data = number; nextNode = NULL; }

    //Constructors for File Handling
	cNode(ifstream &inFile) { inFile.read((char*)this, sizeof(this)); }
	cNode(ofstream &oFile) { oFile.write((char*)this, sizeof(this)); }
	
    //Functions for File Handling
	void writeNodetoFile(ofstream &outData) { outData.write((char*)this, sizeof(this)); }
	void readNodefromFile(ifstream &inData) { inData.read((char*)this, sizeof(this)); }

    //Getter Setters
	int getData() { return data; }
	void setData(int numb) { data = numb; }
	
    //Printing Node Data
    void printNode() { cout << data; }
};
#pragma once