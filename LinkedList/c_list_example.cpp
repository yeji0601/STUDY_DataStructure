#include <iostream>
using namespace std;
//�������Ḯ��Ʈ���� ��� ����, ����, ����ϴ� ���α׷�

class CNode {
public://��������� �����Ӱ� �� �� �ֵ��� ���
	int data;
	CNode* link;
};

CNode* Head;//���������

//���� �ڿ� ��� �����ϱ�
void insert_node_at_rear(CNode* new_node) {
	if (Head == NULL) { 
		new_node->link = new_node; //�ڱⰡ �ڱ⸦ ����Ű���� ��
		Head = new_node; //Head�� ���ο� ��带 ����Ű����
	}else {
		new_node->link = Head->link; 
		Head->link = new_node;
		Head = new_node; //head�� �׻� ������ ��带 ����Ŵ
	}
}


//��� �����ϱ�
void delete_node(int key) {//x���� ���� ��带 ���Ḯ��Ʈ���� ����
	
	if (Head == NULL) return; //�� ����Ʈ
	else if (Head->link == Head && Head->data == key) { 
	//��� 1���� ��Ȳ�� ���� ��ġ�ϴ� ���
		Head = NULL;
	} else { 
	//������ ��� 
		CNode* pre = Head;//Head�� ������ ��带 ����Ű�� ����

		do{
			if (pre->link->data == key) //pre�� ���� ��� �����Ͱ� ���ϴ� �����Ͷ��
			{
				CNode* removed = pre->link;//�Ʒ����� pre->link���� �ٲ�� ������ removed�� �̸� ����
				pre->link = removed->link; //pre�� removed��� ���� ��带 ����Ŵ
				if (Head == removed) Head = pre;//��������� �缳��
				return;
			}
			else pre = pre->link;
		} while (pre != Head);
	}
}


//���Ḯ��Ʈ�� ��ȸ�ϸ� ����ϴ� �Լ�
void print_list() {
	
	if (Head == NULL) return;
	else {
		CNode* ptr = Head; //ptr�� ������ ������ ����
		do {
			cout << ptr->link->data << endl;//ptr���� ����� �����ͺ��� ���
			ptr = ptr->link;
		} while (ptr != Head);
	}
}

void main() {
	Head = NULL;

	int data_number, i_data, deleted;
	cout << "��ü �Է� �������� ������? : ";
	cin >> data_number;

	for (int i = 0; i < data_number; i++) {

		//����ڷκ��� �����͸� �Է¹ޱ�
		cout << "���ο� �� �Է� : (#" << i + 1 << ")  ";
		cin >> i_data;

		//���ο� ��带 ������ ������ �����ϱ� 
		CNode* new_node = new CNode;
		new_node->data = i_data;
		new_node->link = NULL; 
		
		//��ü ���Ḯ��Ʈ�� �߰�/����
		insert_node_at_rear(new_node);
	}
	cout << "##�������Ḯ��Ʈ ���" << endl;
	print_list();

	//������ �� �Է¹ޱ�
	for (int i = 0; i < 3; i++) {
		cout << "������ ���� �Է����ּ��� : ";
		cin >> deleted;
		delete_node(deleted);//��� ����
		cout << "##���� �� ���Ḯ��Ʈ"<< endl;
		print_list();
	}
}