#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
// �ڴ���룬����Ӧ����mem_block�Ĵ�С������Ӧ����4��������
#define ALIGNMENT 8

// ��ʼ���ѵĴ�С
#define HEAP_SIZE 10000

// ������Ϣ�ṹ��
struct mem_block
{
	int size;    // ����Ĵ�С
	int is_free; // �Ƿ��ѷ���
};
typedef struct mem_block mem_block;

// �ѵ���ʼ��ַ�ͽ�����ַ
void *g_heap_start = 0;
void *g_heap_end = 0;

bool g_heap_inited = false;

// ��ʼ����
void init_simple_malloc()
{
	g_heap_inited = true;
	g_heap_start = malloc(HEAP_SIZE);
	if (g_heap_start == 0)
		return;
	mem_block* pos = (mem_block*)g_heap_start;
	pos->size = HEAP_SIZE;
	pos->is_free = 1;
	g_heap_end = (void*)((char*)g_heap_start + HEAP_SIZE - 1);

}

// �ڲ�ʹ�õķ����ڴ溯��
void *_simple_malloc(size_t size)
{
	if (g_heap_start == 0)
		return 0;
	// �����ڴ��С���������Ҫ��
	size = (size + ALIGNMENT - 1) & (~(ALIGNMENT - 1));
	mem_block *pos = (mem_block*)g_heap_start;
	while ((void*)pos < g_heap_end)
	{
		// ������Ӧ��
		if (pos->is_free && pos->size >= sizeof(mem_block)+size)
		{
			if (pos->is_free == sizeof(mem_block)+size)
				pos->is_free = 0;
			else
			{
				// ȡ����Ҫ�Ĵ�С��ʣ�µĳ�Ϊ���е�һ���¿�
				mem_block *next_pos = (mem_block*)((char*)pos + sizeof(mem_block)+size);
				next_pos->is_free = 1;
				next_pos->size = pos->size - sizeof(mem_block)-size;
				pos->is_free = 0;
				pos->size = sizeof(mem_block)+size;
				return (void*)((char*)pos + sizeof(mem_block));
			}
			return (void*)((char*)pos + sizeof(mem_block));
		}
		else
			pos = (mem_block*)((char*)pos + pos->size);
	}
	return 0;
}

// �ڲ�ʹ�õĺϲ����п麯��
void _merge_free_blocks()
{
	mem_block *pos = (mem_block*)g_heap_start;
	while ((void*)((char*)pos + pos->size) < g_heap_end)
	{
		mem_block *next_pos = (mem_block*)((char*)pos + pos->size);
		// �����ڵ������鶼�ǿ��У��϶�Ϊһ
		if (pos->is_free && next_pos->is_free)
			pos->size = pos->size + next_pos->size;
		else
			pos = next_pos;
	}
	return;
}

// �ⲿʹ�õ��ڴ���亯��
void *simple_malloc(size_t size)
{
	if (!g_heap_inited)
		init_simple_malloc();
	void * pos = _simple_malloc(size);
	if (pos)
		return pos;
	// ����һ�η����ڴ�ʧ�ܣ�����кϲ����п飬�ٴγ��Է���
	_merge_free_blocks();
	return _simple_malloc(size);
}

// �ⲿʹ�õ��ڴ��ͷź���
void simple_free(void *p)
{
	mem_block * pos = (mem_block*)((char*)p - sizeof(mem_block));
	// �ͷŽ�����һ��
	pos->is_free = 1;
	return;
}

// ����ʹ�õĴ�ӡ����Ϣ����
void print_heap_info()
{
	mem_block *pos = (mem_block*)g_heap_start;
	puts("Heap info:");
	while ((void*)pos < g_heap_end)
	{
		// ����������п��ƿ����ʼ��ַ����С��ʹ�����
		printf("mem_block info: start_addr, %d; size, %d; is_free, %d\n", pos, pos->size, pos->is_free);
		pos = (mem_block*)((char*)pos + pos->size);
	}
	putchar('\n');
	return;
}

int main()
{
	void *p1 = simple_malloc(3000);
	// ״̬һ
	puts("State 1");
	print_heap_info();

	void *p2 = simple_malloc(5000);
	// ״̬��
	puts("State 2");
	print_heap_info();

	void *p3 = simple_malloc(1000);
	// ״̬��
	puts("State 3");
	print_heap_info();

	simple_free(p1);
	simple_free(p2);
	simple_free(p3);
	// ״̬��
	puts("State 4");
	print_heap_info();

	void *p4 = simple_malloc(8000);
	// ״̬��
	puts("State 5");
	print_heap_info();

	simple_free(p4);
	// ״̬��
	puts("State 6");
	print_heap_info();
	system("pause");
	return 0;
}