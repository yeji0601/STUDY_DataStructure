#include <iostream>
using namespace std;
//원형연결리스트에서 노드 삽입, 삭제, 출력하는 프로그램

class CNode {
public://멤버변수를 자유롭게 쓸 수 있도록 허용
	int data;
	CNode* link;
};

CNode* Head;//헤드포인터

//가장 뒤에 노드 삽입하기
void insert_node_at_rear(CNode* new_node) {
	if (Head == NULL) { 
		new_node->link = new_node; //자기가 자기를 가리키도록 함
		Head = new_node; //Head는 새로운 노드를 가리키도록
	}else {
		new_node->link = Head->link; 
		Head->link = new_node;
		Head = new_node; //head는 항상 마지막 노드를 가리킴
	}
}


//노드 삭제하기
void delete_node(int key) {//x값을 갖는 노드를 연결리스트에서 삭제
	
	if (Head == NULL) return; //빈 리스트
	else if (Head->link == Head && Head->data == key) { 
	//노드 1개인 상황에 값도 일치하는 경우
		Head = NULL;
	} else { 
	//나머지 경우 
		CNode* pre = Head;//Head는 마지막 노드를 가리키고 있음

		do{
			if (pre->link->data == key) //pre의 다음 노드 데이터가 원하는 데이터라면
			{
				CNode* removed = pre->link;//아래에서 pre->link값이 바뀌기 때문에 removed값 미리 저장
				pre->link = removed->link; //pre가 removed노드 다음 노드를 가리킴
				if (Head == removed) Head = pre;//헤드포인터 재설정
				return;
			}
			else pre = pre->link;
		} while (pre != Head);
	}
}


//연결리스트를 순회하며 출력하는 함수
void print_list() {
	
	if (Head == NULL) return;
	else {
		CNode* ptr = Head; //ptr은 마지막 노드부터 시작
		do {
			cout << ptr->link->data << endl;//ptr다음 노드의 데이터부터 출력
			ptr = ptr->link;
		} while (ptr != Head);
	}
}

void main() {
	Head = NULL;

	int data_number, i_data, deleted;
	cout << "전체 입력 데이터의 개수는? : ";
	cin >> data_number;

	for (int i = 0; i < data_number; i++) {

		//사용자로부터 데이터를 입력받기
		cout << "새로운 값 입력 : (#" << i + 1 << ")  ";
		cin >> i_data;

		//새로운 노드를 생성해 내용을 수정하기 
		CNode* new_node = new CNode;
		new_node->data = i_data;
		new_node->link = NULL; 
		
		//전체 연결리스트에 추가/삽입
		insert_node_at_rear(new_node);
	}
	cout << "##원형연결리스트 결과" << endl;
	print_list();

	//삭제할 값 입력받기
	for (int i = 0; i < 3; i++) {
		cout << "삭제할 값을 입력해주세요 : ";
		cin >> deleted;
		delete_node(deleted);//노드 삭제
		cout << "##삭제 후 연결리스트"<< endl;
		print_list();
	}
}