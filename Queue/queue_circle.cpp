#include <iostream>
using namespace std;

//�迭�� �̿��� ����ť ����
#define element int
const int MAX_SIZE = 6;


class CQUEUE {
public:
	element CQueue[MAX_SIZE]; //ť�迭 ����
	int front, rear; //�ʱ�ȭ 

	CQUEUE() {
		front = rear = -1;
	}

	bool is_queue_empty() { //ť�� ������� Ȯ���ϴ� �Լ�
	
		return (front == rear); 
	}

	bool is_queue_full() { //ť�� á���� Ȯ���ϴ� �Լ�
		if (front == (rear + 1) % MAX_SIZE)
			return true;
		else return false;
	}

	void enQueue(element data) {
		if (is_queue_full()) {
			cout << "ERROR: ť�� ��� á���ϴ�" << endl;
			return;
		}
		else {
			rear = (rear + 1) % MAX_SIZE;
			CQueue[rear] = data;
		}

	}

	element deQueue() {
		if (is_queue_empty()) {

			cout << "ERROR: ť�� ������ϴ�" << endl;
			return -1;
		}
		else {
			front = (front + 1) % MAX_SIZE;
			return CQueue[front];
		}
	}

	element peek() {
		if (is_queue_empty()) {
			cout << "ERROR: ť�� ������ϴ�" << endl;
			exit;
		}
		else {
			return CQueue[front + 1];
		}
	}

	void print_queue() {
		if (front <= rear) {
			for (int i = front + 1; i <= rear; i++)
				cout << CQueue[i] << " ";
		}
		else {
			for (int i = front + 1; i < MAX_SIZE; i++)
				// front���� ������ ���ұ��� ���
				cout << CQueue[i] << " ";
			for (int i = 0; i <= rear; i++)
				//rear���� ���
				cout << CQueue[i] << " ";
		}
		cout << endl;
	}
};


	void main() {
		CQUEUE myQueue;

		myQueue.enQueue(20);
		myQueue.enQueue(30);
		myQueue.enQueue(40);
		myQueue.enQueue(50);
		myQueue.enQueue(60);
		myQueue.deQueue();
		myQueue.enQueue(40);

		myQueue.print_queue();

		myQueue.deQueue();
		myQueue.deQueue();
		myQueue.enQueue(50);
		myQueue.enQueue(70);
		
		myQueue.print_queue();
	}