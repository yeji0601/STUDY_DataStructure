#include <iostream>
using namespace std;
//�ܼ����Ḯ��Ʈ���� ��� ����, ����, ����ϴ� ���α׷�

class Node {
public://��������� �����Ӱ� �� �� �ֵ��� ���
	int data;
	Node* link;
};

Node* Head;//���������

//���� ��� �̿��ϱ�
void insert_node_A(Node *pre, Node* new_node) {
	if (Head == NULL) { //���鸮��Ʈ�� ���
		Head = new_node;
	}
	else if (pre == NULL) { //pre�� NULL�̸� �� ��尡 ���ٴ� ��, ù��° ���� ����
		new_node->link = Head;
		Head = new_node;
	}
	else { //�� ��带 pre ������ ����
		new_node->link = pre->link;
		pre->link = new_node;
	}
}

//�ڿ� ��� �����ϱ�
void insert_node_at_rear(Node* new_node) {
	if (Head == NULL) { //���鸮��Ʈ�� ���
		Head = new_node;
	}
	else { 
		Node *list = Head;

		while (list->link != NULL) list = list->link;//list�� ������ ��尡 �ƴ϶��
		list->link = new_node;//������ ����� link�� �ٲ��ֱ�
	}
}//

//�տ� ��� �����ϱ�
void insert_node_at_front(Node* new_node) {
	new_node->link = Head; //new_node�� ���� ��带 Head�� ��ü
	Head = new_node; 
}

//��� �����ϱ�
void delete_node(int x) {//x���� ���� ��带 ���Ḯ��Ʈ���� ����
	Node* list = Head; // list ==> pre

	if (Head == NULL) return; 
	/*������ ��尡 ����
	�׻� �����͸� ���� ���� ���� ���� NULL���� Ȯ���ؾ���*/
	else if (Head->data == x) { //������ ��尡 ù ����� ���
		Head = Head->link;//Head��忡 �ִ� ��ũ�� ��������Ϳ� ����
		return;
	}
	else { //������ ��� 
		while (list->link != NULL) {
			if (list->link->data == x)
			{
				list->link = list->link->link;
				return;
			}
			else list = list->link;
		}
	}
}

//���Ḯ��Ʈ ����
void reverse_list() {
	Node* p, * q, * r;
	p = Head;// p�� ���� ����Ű�� ���, q�� ���� ���
	q = r = NULL;

	while (p != NULL) {
		r = q; //r�� q, q�� p�� ���ʷ� ���󰣴�
		q = p;
		p = p->link; // p�� �̸� �Ű� ���´�
		q->link = r; //q�� ��ũ ������ �ٲ۴�
	}
	Head = q; //q�� �������� �� ����Ʈ�� ��� ������
}

//���Ḯ��Ʈ�� ��ȸ�ϸ� ����ϴ� �Լ�
void print_list() {
	//ptr�� NULL�� �ƴ϶�� link�� ����Ų��
	for (Node* ptr = Head; ptr != NULL; ptr = ptr->link)
		if (ptr->link == NULL) cout << ptr->data << endl;			
		else { cout << ptr->data << "-->"; }
}

void main() {
	Head = NULL;

	int data_number, i_data, deleted;
	cout << "��ü �Է� �������� ������? : ";
	cin >> data_number;

	for (int i = 0; i < data_number; i++) {

		//����ڷκ��� �����͸� �Է¹ޱ�
		cout << "���ο� �� �Է� : (#" << i+1 <<")  ";
		cin >> i_data; 

		//���ο� ��带 ������ ������ �����ϱ� 
		Node* new_node = new Node;
		new_node->data = i_data;
		new_node->link = NULL;

		//��ü ���Ḯ��Ʈ�� �߰�/����
		insert_node_at_front(new_node);//�տ� �����ϱ� ������ ���� ���
	}
	cout << "##������ ���Ḯ��Ʈ�� : ";
	print_list();

	//������ �� �Է¹ޱ�
	for (int i = 0; i < 3; i++) {
		cout << "������ ���� �Է����ּ��� : ";
		cin >> deleted;
		delete_node(deleted);//��� ����
		cout << "##���� �� ���Ḯ��Ʈ�� : ";
		print_list();
	}

	//���� ���
	reverse_list();
	print_list();
}