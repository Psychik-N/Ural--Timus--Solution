#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct Edge {
	int to;
	int dir;
	struct Edge *next;
}*edges[10001] = { 0 },*p;
int d[10001][2], mark[10001][2] = { 0 };
int main() {
	int n, m, x, y, i, j, bi, bj, bv;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		p = malloc(sizeof(struct Edge));
		p->to = y;
		p->dir = 0;
		p->next = edges[x];
		edges[x] = p;
		p = malloc(sizeof(struct Edge));
		p->to = x;
		p->dir = 1;
		p->next = edges[y];
		edges[y] = p;
	}
	scanf("%d%d", &x, &y);
	for (i = 1; i <= n; i++)d[i][0] = d[i][1] = 200000000;
	d[x][0] = d[x][1] = 0;
	for (i = 0; i < 2 * n; i++) {
		bv = 200000000;
		for (j = 1; j <= n; j++)if (mark[j][0] == 0 && d[j][0] < bv) {
			bv = d[j][0];
			bi = j;
			bj = 0;
		}
		for (j = 1; j <= n; j++)if (mark[j][1] == 0 && d[j][1] < bv) {
			bv = d[j][1];
			bi = j;
			bj = 1;
		}
		mark[bi][bj] = 1;
		p = edges[bi];
		while (p) {
			x = bv + (bj != p->dir);
			if (x < d[p->to][p->dir])d[p->to][p->dir] = x;
			p = p->next;
		}
	}
	printf("%d\n", d[y][0] < d[y][1] ? d[y][0] : d[y][1]);
	return 0;
}
