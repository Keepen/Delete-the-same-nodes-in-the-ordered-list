#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

//�������
Node* BuyNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//ɾ����ͬ�Ľ��
Node* DeleteNode(Node* head) {
	//��������ָ��
	//��һ����ͷ�ڵ�����¼ɾ���ڵ���������׽ڵ�
	//�������������б������Ƚ�
	Node* fake = (Node*)malloc(sizeof(Node));
	fake->next = head;
	Node* pre = fake;//��¼��ǰ����ǰһ��λ��
	Node* cur = head;
	Node* next = cur->next;
	//�Ƚ��н��������ж�:���û�нڵ��ֻ��һ����㣬��ֱ�ӷ���ͷ�ڵ�
	if (cur == NULL || next == NULL) {
		return head;
	}
	//��ʼ���бȽϡ�ɾ����
	while (cur != NULL && cur->next != NULL) {
		//�����ظ��ڵ�ʱ
		if (cur->data == next->data) {
			//�����ظ��Ľ�㣬����next����ߣ�pre->nextָ��next
			while (next != NULL && cur->data == next->data) {
				next = next->next;
			}
			pre->next = next;
			cur = next;
			pre = cur;
		}
		//û�������ظ��ڵ�ʱ
		else {
			//����preָ��ǰ�ڵ㣬�ټ���������
			pre = cur;
			cur = next;
			next = next->next;
		}
	}
	head = fake->next;
	return head;
}


//��ӡ����
void NodePrint(Node* head) {
	Node* cur = head;
	//�Ƚ����п�
	if (cur == NULL) {
		printf("����Ϊ�գ�����\n");
		return;
	}
	while (cur != NULL) {
		if (cur->next != NULL) {
			printf("%d --> ", cur->data);
		}
		else {
			printf("%d\n", cur->data);
		}
		cur = cur->next;
	}
	return;
}



int main() {
	Node* n1 = BuyNode(1);
	Node* n2 = BuyNode(2);
	Node* n3 = BuyNode(2);
	Node* n4 = BuyNode(2);
	Node* n5 = BuyNode(2);
	//��������
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	NodePrint(n1);
	printf("\n\nɾ����ͬ�ڵ�������\n");
	Node* result = DeleteNode(n1);
	NodePrint(result);
	system("pause");
	return 0;
}