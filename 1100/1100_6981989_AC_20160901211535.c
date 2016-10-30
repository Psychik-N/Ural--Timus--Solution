#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _HeapItem {
	int index, value, data;
} HeapItem;
HeapItem heap[150001];
int hl = 0;
int parent(int child) {
	return (child - 1) / 2;
}
int lchild(int parent) {
	return parent * 2 + 1;
}
int rchild(int parent) {
	return parent * 2 + 2;
}
int haslchild(int parent) {
	if (hl >= parent * 2 + 2)return 1;
	return 0;
}
int hasrchild(int parent) {
	if (hl >= parent * 2 + 3)return 1;
	return 0;
}
int cmp(HeapItem *a, HeapItem *b) {
	if (a->value != b->value)return b->value - a->value;
	else return a->index - b->index;
}
void Push(HeapItem item) {
	int pos = hl;
	while (pos > 0 && cmp(&item, &heap[parent(pos)]) < 0) {
		heap[pos] = heap[parent(pos)];
		pos = parent(pos);
	}
	heap[pos] = item;
	hl++;
}
HeapItem Pop() {
	HeapItem item = heap[0];
	int pos = 0, next;
	hl--;
	while (haslchild(pos)) {
		next = -1;
		if (cmp(&heap[lchild(pos)], &heap[hl]) < 0)next = lchild(pos);
		if (hasrchild(pos) && cmp(&heap[rchild(pos)], &heap[hl]) < 0 && (next==-1|| cmp(&heap[rchild(pos)], &heap[lchild(pos)]) < 0)) next = rchild(pos);
		if (next == -1)break;
		heap[pos] = heap[next];
		pos = next;
	}
	heap[pos] = heap[hl];
	return item;
}
int main() {
	int n, i, value, data;
	HeapItem item;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &data, &value);
		item.data = data;
		item.index = i;
		item.value = value;
		Push(item);
	}
	for (i = 0; i < n; i++) {
		item = Pop();
		printf("%d %d\n", item.data, item.value);
	}
}
