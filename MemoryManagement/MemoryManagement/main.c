// MEMORY MANAGEMENT :D

#include <stdlib.h>

typedef void* ptr;

typedef struct mynode_t
{
	unsigned short prevOffset;
	unsigned short nextOffset;
	unsigned short size;
	unsigned short sequence;
}mynode;

char* myinit(char* stack, unsigned short stackSize)
{
	mynode* node = (mynode*)stack;
	node->prevOffset = 0;
	node->nextOffset = 0;
	node->size = stackSize;
	node->sequence = 0;
	return stack;
}

char* myalloc(char* stack, unsigned short sz)
{
	// search for empty space large enough
	// offset to node location
	// set node
	// return pointer right after node
}

void myfree(char* block)
{
	// clear node right before block
}

int main(int const argc, char const* const argv[])
{
	typedef union scanner_t
	{
		ptr p;
		size_t s;
	} scanner;

	typedef union smallscanner_t
	{
		int ss;
		unsigned int su;
	}smallscanner;

	typedef struct malloc_node_t
	{
		ptr prev;
		ptr next;
		size_t pad0[3];
		size_t size;
		size_t sequence;
		size_t pad1;
	} malloc_node;


	ptr a, b, c, d;
	scanner* scan_a, * scan_b, * scan_c, * scan_d;
	malloc_node* node_a, * node_b, * node_c, * node_d;

	a = malloc(1024);
	c = malloc(1345);
	b = malloc(65535);
	d = malloc(1000000);

	if (a) *(int*)a = 72;
	if (b) *(int*)b = 1234567;
	if (c) *(int*)c = -86;
	if (d) *(int*)d = 200000000;
	
	scan_a = (scanner*)a;
	scan_b = (scanner*)b;
	scan_c = (scanner*)c;
	scan_d = (scanner*)d;

	node_a = (malloc_node*)a - 1;
	node_b = (malloc_node*)b - 1;
	node_c = (malloc_node*)c - 1;
	node_d = (malloc_node*)d - 1;

	free(a);
	free(b);
	free(c);
	free(d);



	// write your own 16-bit memory manager:
	char stack[65536];
	myinit(stack, sizeof(stack));
}