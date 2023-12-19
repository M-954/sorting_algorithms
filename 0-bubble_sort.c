#include "sort.h"

/**
 * bubble_sort - arranges the integers of an array in ascending order
 * @array: a pointer to the array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int temp;
	int count = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				count = 1;
				print_array(array, size);
			}
		}
		if (count == 0)
		{
			break;
		}
	}
}
