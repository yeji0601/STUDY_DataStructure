#include <iostream>
using namespace std;

//��������Ʈ�� ����带 �߰��� ���߿��Ḯ��Ʈ

class DNode {

public : 
	int data;
	DNode* llink;
	DNode* rlink;

	//������
	DNode() {
		llink = rlink = NULL;
	}
	DNode(int value) {
		data = value;
		llink = rlink = NULL;
	}

};

DNode* Head = NULL;

//����Ʈ�� �������� ��带 �����ϴ� ���
void insert_node(DNode *new_node) {

	new_node->rlink = Head;
	new_node->llink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;

}



void delete_node(int key) {		

	for (DNode* list = Head->rlink; list != Head; list = list->rlink) {
		//list�� Head�� ����ų ������ ���������� �̵�(������)

		if (list->data == key)
		{
			list->llink->rlink = list->rlink;
			list->rlink->llink = list->llink;
			break;
		}

	}
}


void print_list() {
	cout << "����Ʈ ���� ���" << endl;
	
	for (DNode* list = Head->rlink; list != Head; list = list->rlink)
		cout << list->data << " "<< endl;
	
}

void main() {

	//����� ���� �� �ʱⰪ ����
	Head = new DNode;
	Head->llink = Head;
	Head->rlink = Head;

	int num, data, key;
	DNode* new_node;

	cout << "�Է��� ����� ������ ? : ";
	cin >> num;

	for (int i = 0; i < num; i++) {
		// ��� �� �Է�
		cin >> data;

		/*��� �ϳ��� �Ҵ�
		DNode *new_node = new DNode;
		new_node->data = data;
		new_node->llink = NULL;
		new_node->rlink = NULL;*/
		DNode* new_node = new DNode(data);


		//��带 ����Ʈ�� �߰�
		insert_node(new_node);

	}

	print_list();

	cout << "������ ���� �Է��ϼ��� : ";
	cin >> key;

	delete_node(key);
	print_list();

}

