#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node* next;
};

struct list {
	struct node* head;
};

struct list* init() {
	struct list* l = malloc(sizeof(struct list));

	l->head = NULL;

	return l;
}

int size(struct list* list) {
	int count = 0;
	struct node* current = list->head;

	while (current != NULL) {
		current = current->next;
		count++;
	}

	return count + 1;
}

void appendAtHead(struct list* list, int value) {
	struct node* new = malloc(sizeof(struct node));

	new->val = value;
	if (list->head == NULL) {
		list->head = new;
		list->head->next = NULL;
	}
	else {
		new->next = list->head;
		list->head = new;
	}
}

void appendAtPosition(struct list* list, int index, int value) {
	struct node* new = malloc(sizeof(struct node));
	struct node* current = list->head;
	int count = 0;

	new->val = value;

	if (index < 0 || index > size(list)) {
		printf("%s\n", "IndexError: list is empty");
		return;
	}
	else {
		if (index =! 0) {
			while(count + 1 < index) {
				current = current->next;
				count++;
			}

			new->next = current->next;
			current->next = new;
		}
		else {
			appendAtHead(list, value);
		}
	}
}

void deleteValue(struct list* list, int value) {
	struct node* previous = list->head;
	struct node* toDelete = malloc(sizeof(struct node));
	int count;

	if (size(list) == 0) {
		printf("%s\n", "IndexError: list is empty");
		return;
	}

	if(list->head->val == value) {
		toDelete = list->head;
		list->head = list->head->next;
		free(toDelete);
		return;
	}

	while (previous->next != NULL) {
		if (previous->next->val == value) {
			toDelete = previous->next;
			previous->next = previous->next->next;
			free(toDelete);
			return;
		}
		previous = previous->next;
		count++;
	}

}

void deleteIndex(struct list* list, int index) {
	struct node* previous = list->head;
	struct node* toDelete = malloc(sizeof(struct node));
	int count = 0;

	if (size(list) == 0) {
		printf("%s\n", "IndexError: list is empty");
		return;
	}

	if (index > size(list)) {
		printf("%s\n", "IndexError: Index does not exist");
		return;
	}

	if (index == 0) {
		toDelete = list->head;
		list->head = list->head->next;
		free(toDelete);
		return;
	}
	else {
		while (count + 1 != index) {
			count++;
			previous = previous->next;
		}
		toDelete = previous->next;
		previous->next = previous->next->next;
		free(toDelete);
	}
}

void printList(struct list* list) {
	struct node* current = list->head;

	printf("[");
	while (current->next != NULL) {
		printf("%d ", current->val);
		current = current->next;
	}
	printf("%d]\n", current->val);
}

int main() {
	return 0;
}