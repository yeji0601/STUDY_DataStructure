#include <iostream>
using namespace std;

//연결리스트를 이용한 큐의 기본 함수 구현 및 간단한 삽입삭제 코드
#define element int

class Node {
public:
	element data;
	Node* link;
};

Node* front = NULL;
Node* rear = NULL;  

bool is_queue_empty() { //큐가 비었는지 확인하는 함수
	return (front == NULL); // rear == NULL 일 때도 같다
}

void enQueue(element data) {
	//새로운 노드를 첫 노드로 추가
	Node* new_node = new Node;
	new_node->data = data;
	new_node->link = NULL;

	if (is_queue_empty()) {//첫 노드가 들어올 때는 front와 rear 둘 다 바꾸기
		 front = rear = new_node;
	} else {
		rear->link = new_node; // rear의 링크가 새 노드를 가르키도록
		rear = new_node; // 새 노드를 rear로 변경
	}

}

element deQueue() { 
	if (is_queue_empty()) {
		cout << "ERROR: 큐가 비었습니다" << endl <<endl;
		return -1; // exit();
	} else {

		element item = front->data;
		front = front->link;
		if (front == NULL) rear = NULL;// 유일한 노드를 지울 때 rear도 바꾸기		
		return item;
	}

		
}


element peek() { 
	if (is_queue_empty()) { //front == NULL
		cout << "ERROR: 큐가 비었습니다"<< endl << endl;
		return -1;
	}
	else {		
		return front->data;
	}
}

void print_queue() {
	cout << "QUEUE STATUS" << endl;

	if (is_queue_empty()) {
		cout << "ERROR: 큐가 비었습니다" << endl << endl;
		return;
	}
	else {
		for (Node* ptr = front; ptr != NULL; ptr = ptr->link)
			cout << ptr->data << " ";
	}
	cout << endl;
	cout << "peek값은 " <<peek() << endl << endl;
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
