#include <stdio.h>
#include <unistd.h>

void* g_begin = NULL;

void init (void) {
	g_begin = sbrk (0);
}

void deinit (void) {
	brk (g_begin);
}

void push (int data) {
	*(int*)sbrk (sizeof (int)) = data;
}

int pop (void) {
	int data = *((int*)sbrk (0) - 1);
	sbrk (-sizeof (int));
	return data;
}

int top (void) {
	return *((int*)sbrk (0) - 1);
}

int empty (void) {
	return sbrk (0) == g_begin;
}
/*
int main (void) {
	init ();

	int i;
	for (i = 0; i < 10; i++)
		push (i);

	while (! empty ())
		printf ("%d ", pop ());
	printf ("\n");

	deinit ();

	return 0;
}
*/
void print (unsigned int data, int base)
{
	init ();

	do
	{
		push (data % base);
	}	while (data /= base);

	for (; ! empty (); pop ())
		if (top () < 10)
			printf ("%d", top ());
		else
			printf ("%c", top () - 10 + 'A');
	printf ("\n");

	deinit ();
}

int main (void)
{	/*
	init ();

	int i;
	for (i = 0; i < 10; i++)
		push (i);

	while (! empty ())
	{
		printf ("%d ", top ());
		pop ();
	}
	printf ("\n");

	deinit ();
	*/
	printf ("Enter an integer: ");
	int data;
	scanf ("%d", &data);

	printf ("Enter a base: ");
	int base;
	scanf ("%d", &base);

	print (data, base);

	return 0;
}
