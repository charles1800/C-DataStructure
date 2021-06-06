#include <iostream>
using namespace std;


typedef struct DoubleLinkedList {
	singleLinkedList* next,*pre;
	int data;
}node, * pnode;

pnode linkHeadInsert();
void display(pnode);
node* initLinkedList();
void change(pnode, int, int);
bool deleteNode(pnode, int);
bool insertNode(pnode, int, int);

pnode initList() {
	pnode head = (pnode)malloc(sizeof(node));
	if (head == NULL) {
		cout << "Error generating head node" << endl;
		exit(-1);
	}


}



int main()
{
    std::cout << "Hello World!\n";
}
