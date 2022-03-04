#include <iostream>
using namespace std;

//ť�� �⺻ �Լ� ����
#define element int
const int MAX_SIZE = 100;


class QUEUE {
public:
	element Queue[MAX_SIZE]; //100���� ť�迭 ����
	int front, rear; //�ʱ�ȭ 

	QUEUE() {
		front = rear = -1;
	}

	bool is_queue_empty() { //ť�� ������� Ȯ���ϴ� �Լ�
	//front�� rear�� ������ ť�� �� ��
		return (front == rear); // ���ǽ��� ���̸� true ��ȯ �ƴ϶�� false ��ȯ
	}

	bool is_queue_full() { //ť�� á���� Ȯ���ϴ� �Լ�
		return (rear == MAX_SIZE);
	}

	void enQueue(element data) {
		if (is_queue_full()) {
			cout << "ERROR: ť�� ��� á���ϴ�" << endl;
			return;
		}
		else {
			Queue[++rear] = data; // rear++; Queue[rear] = data;
		}

	}

	element deQueue() {
		if (is_queue_empty()) {

			cout << "ERROR: ť�� ������ϴ�" << endl;
			return -1;
		}
		else {
			return Queue[front + 1]; //front�� ���� �� ���� / ������ ������ ���� ����Ŵ->front ���� �� return
		}
	}

	element peek() {
		if (is_queue_empty()) {
			cout << "ERROR: ť�� ������ϴ�" << endl;
			exit;
		}
		else {
			return Queue[front + 1];//++front�� front�� �ٲٸ� ����� �� ��� ������ ����
		}
	}

	void print_queue() {
		cout << "ť : ( front = " << front << ", rear = " << rear << " )" << endl;

		if (is_queue_empty()) {
			cout << "ERROR: ť�� ������ϴ�" << endl;
			exit;
		}
		else {
			for (int i = front + 1; i <= rear; i++)
				cout << Queue[i] << " ";
		}
		cout << endl;
	}
};


void main() {
	QUEUE myQueue; 

	myQueue.enQueue(20);
	myQueue.enQueue(30);
	myQueue.enQueue(40);
	myQueue.deQueue();
	myQueue.print_queue();

	myQueue.enQueue(50);
	myQueue.enQueue(70);
	myQueue.deQueue();
	myQueue.enQueue(60);
	myQueue.enQueue(40);
	myQueue.print_queue();
}