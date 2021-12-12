#include "stdio.h"
#include "stdlib.h"
int i = 1; //id
typedef struct mem
{
	int start;
	int end;
	struct mem *next;
} mem;
typedef struct work
{
	int id;
	int size; //memsize
	int start;
	struct work *next;
} work;
work *initwork(int size)
{
	work *head = (work *)malloc(sizeof(head));
	head->id = i;
	head->start = 1;
	head->size = size;
	head->next = NULL;
	return head;
}
work *insertwork(work *head, int start, int size)
{
	i++;
	work *pi, *pb; //pi is the insert one ##pb is the point
	pi = (work *)malloc(sizeof(work));
	pi->id = i;
	pi->start = start;
	pi->size = size;
	pi->next = NULL;
	if (head == NULL)
	{
		head = pi;
		head->next = NULL;
	}
	pb = head;
	while (pb->next != NULL)
	{
		pb = pb->next;
	}
	pb->next = pi;

	return head;
}
mem *initmem(int size)
{
	mem *head = (mem *)malloc(sizeof(mem));
	head->start = 1;
	head->end = 640;
	head->next = NULL;
	return head;
}
mem *insertmem(mem *head, int start, int size)
{
	mem *pi, *pb, *pf;
	int pbsize;
	pb = head;
	pbsize = pb->end - pb->start + 1;
	pi = (mem *)malloc(sizeof(mem));
	pi->start = start;
	pi->end = size + start - 1;
	if (pb == NULL)
	{
		head = pi;
		pi->next = NULL;
	}
	else
	{
		while (pi->start > pb->start && pb->next != NULL)
		{
			pf = pb;
			pb = pb->next;
		}
		if (pi->start < pb->start)
		{
			if (pb == head)
			{

				head = pi; //ͷ�ڵ�
				pi->next = pb;
			}

			else
			{
				pf->next = pi; //����λ��
				pi->next = pb;
			}
		}
		else
		{
			pb->next = pi;
			pi->next = NULL; //�ڱ�ĩ����
		}
	}
	//�ϲ����ڵ��ڴ�
	pf = pb = head;
	while (pb->next != NULL)
	{
		if (pf->end + 2 > pb->start)
		{
			pf->end = pb->end;
			pf->next = pb->next;
		}
		pf = pb;
		pb = pb->next;
	}
	return head;
}
int getstart(work *head, int size)
{
	work *pb;
	pb = head;
	while (pb != NULL)
	{
		if (pb->size == size)
		{
			return pb->start;
		}

		pb = pb->next;
	}

	return 0;
}
int alloc_ff(mem *head, int size)
{
	mem *pb;
	pb = head;
	int a;

	while (pb != NULL)
	{
		if (size <= (pb->end - pb->start + 1))
		{

			a = pb->start;
			pb->start = pb->start + size;

			return a;
		}
		pb = pb->next;
	}
	return 0;
}
int alloc_bf(mem *head, int size)
{
	mem *pb, *pmin;
	pb = head;
	int a, s, min = 641;

	while (pb != NULL)
	{
		if (size <= (pb->end - pb->start + 1))
		{

			s = pb->end - pb->start + 1 - size;
			if (s < min)
			{
				min = s;
				pmin = pb;
			}
		}

		pb = pb->next;
	}
	if (min != 641)
	{
		a = pmin->start;
		pmin->start = pmin->start + size;
		return a;
	}
	return 0;
}

work *free1(work *head, int size)
{
	work *pb, *pf;
	while (head == NULL)
	{
		printf("no this nod");
		goto end;
	}
	pb = head;
	while (pb->size != size && pb->next != NULL)
	{

		pf = pb;
		pb = pb->next;
	}
	if (pb->size == size)
	{
		if (pb == head)
			head = pb->next;
		else
			pf->next = pb->next;
	}

end:
	return head;
}
void printw(work *head)
{
	work *pb;
	pb = head;
	while (pb != NULL)
	{
		printf("id    start    size---->\n");
		printf("%d%7d%8d\n", pb->id, pb->start, pb->size);
		pb = pb->next;
	}
}

void printm(mem *head)
{
	mem *pb;
	pb = head;
	while (pb != NULL)
	{
		printf("start    end---->\n");
		printf("%d%9d\n", pb->start, pb->end);
		pb = pb->next;
	}
}
void print(work *whead, mem *mhead)
{
	char c;
	printf("��ҵ������\n");
	printw(whead);
	printf("========================\n");
	printf("���з�������\n");
	printm(mhead);
	scanf("%c", &c);
}
int main()
{
	int wrec; //���շ��صĵ�ַ
	int mrec;
	mem *mhead;
	mhead = initmem(640);
	work *whead;

	//1
	whead = initwork(130);
	//	wrec=alloc_ff(mhead,130);
	wrec = alloc_bf(mhead, 130);
	print(whead, mhead);

	//2
	//	wrec=alloc_ff(mhead,60);
	wrec = alloc_bf(mhead, 60);
	whead = insertwork(whead, wrec, 60);
	print(whead, mhead);

	//3
	//	wrec=alloc_ff(mhead,100);
	wrec = alloc_bf(mhead, 100);
	whead = insertwork(whead, wrec, 100);
	print(whead, mhead);

	//4
	mrec = getstart(whead, 60);
	whead = free1(whead, 60);
	mhead = insertmem(mhead, mrec, 60);
	print(whead, mhead);

	//5
	//	wrec=alloc_ff(mhead,200);
	wrec = alloc_bf(mhead, 200);
	whead = insertwork(whead, wrec, 200);
	print(whead, mhead);

	//6
	mrec = getstart(whead, 100);
	whead = free1(whead, 100);
	mhead = insertmem(mhead, mrec, 100);
	print(whead, mhead);

	//7
	mrec = getstart(whead, 130);
	whead = free1(whead, 130);
	mhead = insertmem(mhead, mrec, 130);
	print(whead, mhead);

	//8
	//	wrec=alloc_ff(mhead,140);
	wrec = alloc_bf(mhead, 140);
	whead = insertwork(whead, wrec, 140);
	print(whead, mhead);

	//9
	//	wrec=alloc_ff(mhead,60);
	wrec = alloc_bf(mhead, 60);
	whead = insertwork(whead, wrec, 60);
	print(whead, mhead);

	//10
	//	wrec=alloc_ff(mhead,50);
	wrec = alloc_bf(mhead, 50);
	whead = insertwork(whead, wrec, 50);
	print(whead, mhead);

	//11
	mrec = getstart(whead, 60);
	whead = free1(whead, 60);
	mhead = insertmem(mhead, mrec, 60);
	print(whead, mhead);

	return 0;
}
