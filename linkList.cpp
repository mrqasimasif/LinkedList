#include<iostream>
#include<fstream>
#include"nodeClass.cpp"

using namespace std;

class cList {
    //The HEAD reference of LIST object
	cNode *headNode;
public:
    //Keep record of the number of elements of LIST class
	int count = 0;

    //LIST constructors
	cList() { headNode = NULL; count = 0; }
	cList(cNode *&nodeRef) { headNode = nodeRef;  headNode->nextNode = NULL; count = 1; }

    //COPY CONSTRUCTOR of LIST class	
	cList(cList &listRef) {
		this->headNode = listRef.headNode;
		if (listRef.headNode) {
			cNode *sptr, *dptr;
			dptr = headNode = new cNode(*listRef.headNode);
			sptr = headNode->nextNode;
			while (sptr) {
				dptr->nextNode = new cNode(*sptr);
				dptr = dptr->nextNode;
				sptr = sptr->nextNode;
			}
		}
	}

    //Overloading ASSIGNMENT OPERATOR
	cList& operator = (const cList &listRef) {
		if (this == &listRef) return *this;

		if (true) { cList temp; temp.headNode = this->headNode; }
		if (true) { cList temp; temp = listRef ; this->headNode = temp.headNode; temp.headNode = NULL; }
		return *this;
	}

    //Constructors for FILE HANDLING 'INPUT DATA FROM FILE'
	cList(ifstream &inFile) :headNode(NULL), count(0) {
		inFile.read((char*)&count, sizeof(count));
		if (count > 0) {
			cNode *ptr;
			ptr = headNode = new cNode(inFile);
			for (int i = 1; i < count; ++i) {
				ptr->nextNode = new cNode(inFile);
				ptr = ptr->nextNode;
			}
			ptr->nextNode = NULL;
		}
	}

    //Constructors for FILE HANDLING 'OUTPUT DATA TO FILE'
	cList(ofstream &outFile) {
		outFile.write((char*)&count, sizeof(count));
		if (count > 0) {
			cNode *ptr = headNode;
			ptr = new cNode(outFile);
			for (int i = 1; i < count; i++) {
				ptr->nextNode = new cNode(outFile);
				ptr = ptr->nextNode;
			}
		}
	}

    //Function for writing LIST data to file
	void writeListToFile(ofstream &oFile) {
		if (!(oFile.is_open())) {
			cout << "File is not opened for writing !" << endl;
		}
		else {
			oFile.write((char*)&count, sizeof(count));

			if (count > 0) {
				cNode *rptr = headNode;
				for (int i = 0; i < count; ++i) {
					rptr->writeNodetoFile(oFile);
					rptr = rptr->nextNode;
				}
			}
		}
	}

    //Function for reading LIST data from file
	void readListFromFile(ifstream &inFile) {
		if (true) { cList temp; temp.headNode = this->headNode; }
		
		if (!(inFile.is_open())) {
			cout << "File is not opened for writing !" << endl;
		}
		else {
			inFile.read((char*)&count, sizeof(count));
			cout << "The count read is " << count << endl;
			if (count > 0) {
				cNode *rptr = headNode = new cNode(inFile);
				for (int i = 1; i < count; ++i) {
					rptr->nextNode = new cNode(inFile);
					rptr = rptr->nextNode;
				}
				rptr->nextNode = NULL;
			}
		}
	}

    //Class pre-conditions
	bool isEmpty() { if (headNode) return false; else return true; }
	bool isNotEmpty() { if (headNode) return true; else return false; }

    //Insert a node at the beginning of the LIST
	cList& insert(cNode *&nodeRef) {
		nodeRef->nextNode = headNode;
		headNode = nodeRef;
		nodeRef = NULL;
		++count;
		return *this;
	}

    //Insert a node at a specific position of the LIST
	cList& insertAt(cNode *&nodeRef, int index) {
		if (index <= 0)
			return insert(nodeRef);
		if (index >= count)
			index = count;

		cNode *rptr = headNode;
		for (int i = 0; i < count; i++)
			rptr = rptr->nextNode;
		nodeRef->nextNode = rptr->nextNode;
		rptr->nextNode = nodeRef;
		nodeRef = NULL;
		++count;
		return *this;
	}

    //Remove node form the beginning of the LIST
	cNode* remove() {
		if (isNotEmpty()) {
			cNode *temp = headNode;
			headNode = temp->nextNode;
			temp->nextNode = NULL;
			--count;
			return temp;
		}
		else {
			cerr << "The list is already empty and can't remove a node from list " << endl;
			exit(1);
		}
	}

    //Remove node from some specific location from LIST
	cNode* removeAt(int index) {
		if (index <= 0)
			return remove();
		if (index >= count)
			index = count;

		cNode *temp, *rptr;
		rptr = headNode;

		for (int i = 0; i < index - 1; ++i)
			rptr = rptr->nextNode;

		temp = rptr->nextNode;
		rptr->nextNode = temp->nextNode;
		--count;
		temp->nextNode = NULL;

		return temp;
	}

    //Helper function to DISPLAY node DATA of LIST
	void printList() {
		if (!headNode)
			cout << "\nEMPTY DATA STRUCTURE\n";
		else {
			cout << "The elements from TOP to BOTTOM are \n";
			cNode *nodeRef = headNode;
			//print all elements until last node NULL reference is reached
			while (nodeRef) {
				nodeRef->printNode();
				cout << "\n";
				nodeRef = nodeRef->nextNode;
			}
		}
	}

    //Class Destructor
	~cList() {
		deleteNode(headNode);
		{
			void deleteNode(cNode *nodeRef);
		}
	}
    //Local function for Destructor
	void deleteNode(cNode *nodeRef) {
		if (nodeRef) {
			deleteNode(nodeRef->nextNode);
			delete nodeRef;
		}
	}
	
};