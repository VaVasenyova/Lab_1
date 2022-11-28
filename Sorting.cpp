#include <iostream>
#include <ctime>

void printArr(int array[], int size)//function to print array
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << "; ";
	}
	std::cout << std::endl;
}

void BubleSort(int array[], int size)//bubble sort
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])//if the item before is bigger
			{
				int temp = 0;
				temp = array[j];
				array[j] = array[j + 1];//we change items' places
				array[j + 1] = temp;
			}
		}
	}

	printArr(array, size);//print array
}


int partition(int arr[], int idx_start, int idx_end)
{
	int pivot = arr[rand()%6]; //randomly choose the element to divide our array too 2 arrays
	int counter = 0;
	int idx_pivot = 0;

	for (int i = idx_start + 1; i <= idx_end; i++)//place elements that are smaller than pivot to the left
	{
		if (arr[i] <= pivot)//the ones that bigger - to the right
		{
			counter++;
		}
	}

	idx_pivot = idx_start + counter; 

	std::swap(arr[idx_pivot], arr[idx_start]);//change places

	int i = idx_start;
	int j = idx_end;


	while (i<idx_pivot && j > idx_pivot)
	{
		while (arr[i] <= pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		if (i < idx_pivot && j > idx_pivot)
		{
			std::swap(arr[i], arr[j]);
		}

	}
	return idx_pivot;
}


void QuickSort(int arr[], int idx_start, int idx_end)// do the sort in the recurtion form
{
	if (idx_start <= idx_end)
		return;

	int idx_pivot = partition(arr, idx_start, idx_end);
	QuickSort(arr, idx_start, idx_pivot - 1);
	QuickSort(arr, idx_pivot + 1, idx_end);

}

void InsertionSort(int array[], int size)
{

	for (int i = 1; i < size; i++) 
	{
		int temp = array[i];
		int j = i - 1;

		while (j >= 0 && array[j] > temp) //if the previous item is bigger than this one
		{
			array[j + 1] = array[j];// change their places
			j = j - 1;
		}
		array[j + 1] = temp;
	}

	printArr(array, size);// print array
}

void time() //timer that counts seconds of sort
{
	unsigned int start_time = clock();
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	std::cout << search_time;
}

int main()
{
	int array[10];// my array
	for (int i = 0; i < 10; i++)
	{
		array[i] = rand(); // random numbers in array
	}

	int size = sizeof(array) / sizeof(array[0]);// count it's size
	std::cout << "There is my array: ";
	printArr(array, size);// print my array

	std::cout << "There is the BubbleSort: ";
	BubleSort(array, size);//do the bubble sort

	std::cout << "Bubble time = ";//time for the first sort
	time();
	std::cout << std::endl;

	QuickSort(array, 0, size-1);//do the quick sort
	std::cout << "There is the QuickSort: ";
	printArr(array, size);//print the array after the quick sort

	std::cout << "Quick time = ";//time for the second sort
	time();
	std::cout << std::endl;

	std::cout << "There is the InsertionSort: ";
	InsertionSort(array, size);//do the insertion sort

	std::cout << "Insertion time = ";//time for the third sort
	time();
	std::cout << std::endl;

	return 0;
}