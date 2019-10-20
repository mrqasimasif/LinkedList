#include<iostream>
#include<fstream>
#include"nodeClass.cpp"
#include"linkList.cpp"

using namespace std;

int main() {

    //File Handling variables
	ifstream inData;
	ofstream oData;

    //Declaring List objects
    cList list,readList;
    
    //Node List
	cNode *n[5];

    //Putting Random data in Node List
	for (int i = 0; i < 5; ++i) {
		n[i] = new cNode(i+5);
	}

    //Inserting nodes to cList object 'list'
	for (int i = 0; i < 5; ++i) {
		list.insert(n[i]);
	}

	cout << "\nPrinting List Data\n";
	list.printList();

    //Opening and Clsosing file to write LIST to file data.bin
	oData.open("G:/uniBooksAndAssignments/3rdSemester/assignments/dsaTheory/linkedList/data.bin");
	list.writeListToFile(oData);
	oData.close();

	//Opeining and Closing file to read LIST from file data.bin
	inData.open("G:/uniBooksAndAssignments/3rdSemester/assignments/dsaTheory/linkedList/data.bin");
	readList.readListFromFile(inData);
    inData.close();

    //Printing Read List from file
	cout << "\nPrinting List Read from File\n";
	readList.printList();
	

	system("pause");

	return 0;

}