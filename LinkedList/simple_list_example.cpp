#include <iostream>
using namespace std;
//단순연결리스트에서 노드 삽입, 삭제, 출력하는 프로그램

class Node {
public://멤버변수를 자유롭게 쓸 수 있도록 허용
	int data;
	Node* link;
};

Node* Head;//헤드포인터

//선행 노드 이용하기
void insert_node_A(Node *pre, Node* new_node) {
	if (Head == NULL) { //공백리스트인 경우
		Head = new_node;
	}
	else if (pre == NULL) { //pre가 NULL이면 앞 노드가 없다는 뜻, 첫번째 노드로 삽입
		new_node->link = Head;
		Head = new_node;
	}
	else { //새 노드를 pre 다음에 삽입
		new_node->link = pre->link;
		pre->link = new_node;
	}
}

//뒤에 노드 삽입하기
void insert_node_at_rear(Node* new_node) {
	if (Head == NULL) { //공백리스트인 경우
		Head = new_node;
	}
	else { 
		Node *list = Head;

		while (list->link != NULL) list = list->link;//list가 마지막 노드가 아니라면
		list->link = new_node;//마지막 노드의 link를 바꿔주기
	}
}//

//앞에 노드 삽입하기
void insert_node_at_front(Node* new_node) {
	new_node->link = Head; //new_node의 다음 노드를 Head로 교체
	Head = new_node; 
}

//노드 삭제하기
void delete_node(int x) {//x값을 갖는 노드를 연결리스트에서 삭제
	Node* list = Head; // list ==> pre

	if (Head == NULL) return; 
	/*삭제할 노드가 없음
	항상 포인터를 쓰기 전에 앞의 값이 NULL인지 확인해야함*/
	else if (Head->data == x) { //삭제할 노드가 첫 노드인 경우
		Head = Head->link;//Head노드에 있던 링크를 헤드포인터에 복사
		return;
	}
	else { //나머지 경우 
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

//연결리스트 역순
void reverse_list() {
	Node* p, * q, * r;
	p = Head;// p는 현재 가리키는 노드, q는 이전 노드
	q = r = NULL;

	while (p != NULL) {
		r = q; //r은 q, q는 p를 차례로 따라간다
		q = p;
		p = p->link; // p를 미리 옮겨 놓는다
		q->link = r; //q의 링크 방향을 바꾼다
	}
	Head = q; //q는 역순으로 된 리스트의 헤드 포인터
}

//연결리스트를 순회하며 출력하는 함수
void print_list() {
	//ptr이 NULL이 아니라면 link를 가리킨다
	for (Node* ptr = Head; ptr != NULL; ptr = ptr->link)
		if (ptr->link == NULL) cout << ptr->data << endl;			
		else { cout << ptr->data << "-->"; }
}

void main() {
	Head = NULL;

	int data_number, i_data, deleted;
	cout << "전체 입력 데이터의 개수는? : ";
	cin >> data_number;

	for (int i = 0; i < data_number; i++) {

		//사용자로부터 데이터를 입력받기
		cout << "새로운 값 입력 : (#" << i+1 <<")  ";
		cin >> i_data; 

		//새로운 노드를 생성해 내용을 수정하기 
		Node* new_node = new Node;
		new_node->data = i_data;
		new_node->link = NULL;

		//전체 연결리스트에 추가/삽입
		insert_node_at_front(new_node);//앞에 삽입하기 때문에 역순 출력
	}
	cout << "##구성된 연결리스트는 : ";
	print_list();

	//삭제할 값 입력받기
	for (int i = 0; i < 3; i++) {
		cout << "삭제할 값을 입력해주세요 : ";
		cin >> deleted;
		delete_node(deleted);//노드 삭제
		cout << "##삭제 후 연결리스트는 : ";
		print_list();
	}

	//역순 출력
	reverse_list();
	print_list();
}