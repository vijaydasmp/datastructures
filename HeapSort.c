/*
 * HeapSort.c
 *
 *  Created on: Sep 4, 2012
 *      Author: vijay
 */

#define left(i) (2*(i))
#define right(i) (2*(i)+1)

/*
 *  input: integer pointer to the base of
 */
void display_heap(int *array, int n)
{

}
void build_maxheap(int *array, int n)
{

}

/*
 *  max-heapify function assumes that the Left subtree and Right subtree of the Heap is max-heap but
 *  array at index i may be violating max heap property so "max-heapify" function allows array[i] to float down
 *  in the array
 *
 */
void max_heapify(int *array, int index, int n)
{
	int largest;
	int l;
	int r;
	l = left(index);
	r = right(index);

	if (l < n && array[l] > array[index])
	{
		largest = l;
	}
	else
	{
		largest = index;
	}

	if (r<n && array[r] > array[largest])
	{
		largest = r;
	}

	/* Swap value at index location with value at largest location*/

	if(largest != index)
	{
		int tmp;

		tmp = array[index];
		array[index] = array[largest];
		array[largest] = tmp;
		max_heapify(array,largest,n);
	}
}

void heapsort(int *array, int n)
{

}


