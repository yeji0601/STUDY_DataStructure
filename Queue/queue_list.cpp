#include <iostream>
using namespace std;

//���Ḯ��Ʈ�� �̿��� ť�� �⺻ �Լ� ���� �� ������ ���Ի��� �ڵ�
#define element int

class Node {
public:
	element data;
	Node* link;
};

Node* front = NULL;
Node* rear = NULL;  

bool is_queue_empty() { //ť�� ������� Ȯ���ϴ� �Լ�
	return (front == NULL); // rear == NULL �� ���� ����
}

void enQueue(element data) {
	//���ο� ��带 ù ���� �߰�
	Node* new_node = new Node;
	new_node->data = data;
	new_node->link = NULL;

	if (is_queue_empty()) {//ù ��尡 ���� ���� front�� rear �� �� �ٲٱ�
		 front = rear = new_node;
	} else {
		rear->link = new_node; // rear�� ��ũ�� �� ��带 ����Ű����
		rear = new_node; // �� ��带 rear�� ����
	}

}

element deQueue() { 
	if (is_queue_empty()) {
		cout << "ERROR: ť�� ������ϴ�" << endl <<endl;
		return -1; // exit();
	} else {

		element item = front->data;
		front = front->link;
		if (front == NULL) rear = NULL;// ������ ��带 ���� �� rear�� �ٲٱ�		
		return item;
	}

		
}


element peek() { 
	if (is_queue_empty()) { //front == NULL
		cout << "ERROR: ť�� ������ϴ�"<< endl << endl;
		return -1;
	}
	else {		
		return front->data;
	}
}

void print_queue() {
	cout << "QUEUE STATUS" << endl;

	if (is_queue_empty()) {
		cout << "ERROR: ť�� ������ϴ�" << endl << endl;
		return;
	}
	else {
		for (Node* ptr = front; ptr != NULL; ptr = ptr->link)
			cout << ptr->data << " ";
	}
	cout << endl;
	cout << "peek���� " <<peek() << endl << endl;
}


void main() {

	enQueue(10);
	enQueue(20);
	deQueue();
	deQueue();
	deQueue();
	print_queue();

	enQueue(10);
	deQueue();
	enQueue(20);
	enQueue(30);
	print_queue();

	enQueue(50);
	enQueue(60);
	enQueue(70);
	deQueue();
	print_queue();
}
