#include <iostream>
using namespace std;

//원형리스트와 헤드노드를 추가한 이중연결리스트

class DNode {

public : 
	int data;
	DNode* llink;
	DNode* rlink;

	//생성자
	DNode() {
		llink = rlink = NULL;
	}
	DNode(int value) {
		data = value;
		llink = rlink = NULL;
	}

};

DNode* Head = NULL;

//리스트의 마지막에 노드를 삽입하는 경우
void insert_node(DNode *new_node) {

	new_node->rlink = Head;
	new_node->llink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;

}



void delete_node(int key) {		

	for (DNode* list = Head->rlink; list != Head; list = list->rlink) {
		//list가 Head를 가리킬 때까지 오른쪽으로 이동(순방향)

		if (list->data == key)
		{
			list->llink->rlink = list->rlink;
			list->rlink->llink = list->llink;
			break;
		}

	}
}


void print_list() {
	cout << "리스트 내용 출력" << endl;
	
	for (DNode* list = Head->rlink; list != Head; list = list->rlink)
		cout << list->data << " "<< endl;
	
}

void main() {

	//헤드노드 생성 및 초기값 설정
	Head = new DNode;
	Head->llink = Head;
	Head->rlink = Head;

	int num, data, key;
	DNode* new_node;

	cout << "입력할 노드의 개수는 ? : ";
	cin >> num;

	for (int i = 0; i < num; i++) {
		// 노드 값 입력
		cin >> data;

		/*노드 하나를 할당
		DNode *new_node = new DNode;
		new_node->data = data;
		new_node->llink = NULL;
		new_node->rlink = NULL;*/
		DNode* new_node = new DNode(data);


		//노드를 리스트에 추가
		insert_node(new_node);

	}

	print_list();

	cout << "삭제할 값을 입력하세요 : ";
	cin >> key;

	delete_node(key);
	print_list();

}

