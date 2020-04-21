#ifndef singularlinkedlist_h_
#define singularlinkedlist_h_

struct node {
	int val;
	struct node* next;
};

struct list {
	struct node* head;
};

int size(struct list* list);

void appendAtHead(struct list* list, int value);

void appendAtPosition(struct list* list, int index, int value);

void deleteValue(struct list* list, int value);

void deleteIndex(struct list* list, int index);

void printList(struct list* list);

#endif
