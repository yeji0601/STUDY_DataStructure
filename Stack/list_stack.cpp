#include <iostream>
using namespace std;

//연결리스트를 이용한 스택의 기본 함수 구현 및 간단한 삽입삭제 코드
#define element int

class Node {
public:
	element data;
	Node* link;
};

Node* SP = NULL; //스택포인터


bool is_stack_empty() { //스택이 비었는지 확인하는 함수
	return (SP == NULL); // 조건식이 참이면 true 반환 아니라면 false 반환
}

//연결리스트는 full이 되지 않기 때문에 is_stack_full함수 삭제

void push(element data) {
	//새로운 노드를 첫 노드로 추가
	Node* new_node = new Node;
	new_node->data = data;
	new_node->link = SP;
	SP = new_node;
}

element pop() { // 가장 위의 data return & top 감소
	if (is_stack_empty()) {
		cout << "ERROR: 스택이 비었습니다" << endl;
		return -1; // exit();
	}
	else {
		element item = SP->data;//첫번째 노드 삭제 전 데이터 백업
		SP = SP->link;
		return item;
	}

}

element peek() {
	if (is_stack_empty()) {
		cout << "ERROR: 스택이 비었습니다" << endl;
		return -1;
	}
	else {
		return SP->data;
	}
}

void print_stack() {
	cout << "STACK STATUS" << endl;

	if (is_stack_empty()) {
		cout << "ERROR: 스택이 비었습니다" << endl;
		return;
	}
	else {
		for (Node* ptr = SP; ptr != NULL; ptr = ptr->link)
			cout << ptr->data << endl;
	}
	cout << endl;

}


void main() {

	push(10);
	push(20);
	push(30);
	pop();
	print_stack();

	push(70);
	pop();
	push(60);
	push(50);
	print_stack();
}
