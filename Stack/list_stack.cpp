#include <iostream>
using namespace std;

//���Ḯ��Ʈ�� �̿��� ������ �⺻ �Լ� ���� �� ������ ���Ի��� �ڵ�
#define element int

class Node {
public:
	element data;
	Node* link;
};

Node* SP = NULL; //����������


bool is_stack_empty() { //������ ������� Ȯ���ϴ� �Լ�
	return (SP == NULL); // ���ǽ��� ���̸� true ��ȯ �ƴ϶�� false ��ȯ
}

//���Ḯ��Ʈ�� full�� ���� �ʱ� ������ is_stack_full�Լ� ����

void push(element data) {
	//���ο� ��带 ù ���� �߰�
	Node* new_node = new Node;
	new_node->data = data;
	new_node->link = SP;
	SP = new_node;
}

element pop() { // ���� ���� data return & top ����
	if (is_stack_empty()) {
		cout << "ERROR: ������ ������ϴ�" << endl;
		return -1; // exit();
	}
	else {
		element item = SP->data;//ù��° ��� ���� �� ������ ���
		SP = SP->link;
		return item;
	}

}

element peek() {
	if (is_stack_empty()) {
		cout << "ERROR: ������ ������ϴ�" << endl;
		return -1;
	}
	else {
		return SP->data;
	}
}

void print_stack() {
	cout << "STACK STATUS" << endl;

	if (is_stack_empty()) {
		cout << "ERROR: ������ ������ϴ�" << endl;
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
