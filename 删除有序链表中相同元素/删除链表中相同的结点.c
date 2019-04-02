#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

//创建结点
Node* BuyNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//删除相同的结点
Node* DeleteNode(Node* head) {
	//三个遍历指针
	//用一个假头节点来记录删除节点后的链表的首节点
	//后两个用来进行遍历、比较
	Node* fake = (Node*)malloc(sizeof(Node));
	fake->next = head;
	Node* pre = fake;//记录当前结点的前一个位置
	Node* cur = head;
	Node* next = cur->next;
	//先进行结点个数的判断:如果没有节点或只有一个结点，就直接返回头节点
	if (cur == NULL || next == NULL) {
		return head;
	}
	//开始进行比较、删除。
	while (cur != NULL && cur->next != NULL) {
		//遇到重复节点时
		if (cur->data == next->data) {
			//遇到重复的结点，就让next向后走，pre->next指向next
			while (next != NULL && cur->data == next->data) {
				next = next->next;
			}
			pre->next = next;
			cur = next;
			pre = cur;
		}
		//没有遇到重复节点时
		else {
			//就让pre指向当前节点，再继续向后遍历
			pre = cur;
			cur = next;
			next = next->next;
		}
	}
	head = fake->next;
	return head;
}


//打印链表
void NodePrint(Node* head) {
	Node* cur = head;
	//先进行判空
	if (cur == NULL) {
		printf("链表为空！！！\n");
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
	//连接链表
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	NodePrint(n1);
	printf("\n\n删除相同节点后的链表：\n");
	Node* result = DeleteNode(n1);
	NodePrint(result);
	system("pause");
	return 0;
}