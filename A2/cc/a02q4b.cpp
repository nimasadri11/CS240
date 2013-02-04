#include "a02q4b.h"
#include <cmath>

#ifdef NDEBUG
#include <iostream>
using namespace std;
#endif

int parent(int i){
	int temp = (i - 1) / 2;
	return temp > 0 ? temp : 0;
}

int left_child(int i){
	return 2*i + 1;
}

void swap(int *array, int i, int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int binary_branch_less(int *array, int start){
	int indice[start];
	int size = 0;
	int temp = start;
	for (int i = 0;; i++){
		if (temp == 0) break;
		indice[i] = temp;
		temp = parent(temp);
		size++;
	}
	indice[size] = 0;
	size++;

	int low, high;
	low = 0;
	high = size -1;
	int pivot = 0;
	int cur = 0;
	while(true){
		if (high < low) break;
		pivot = (high+low)/2;
		cur = indice[pivot];
		if (array[start] > array[cur]){
			low = pivot + 1;
		} else if (array[start] < array[cur]){
			high = pivot - 1;
		} else {
			return cur;
		}
	}
	if (array[start] > array[indice[pivot]]){
		return indice[pivot-1];
	} else {
		int new_p = pivot + 1;
		new_p = new_p < size? new_p : size-1;
#if 0
		cout << "new_p:" << new_p;
		cout << " array_start:" << array[start] << " array_idx:"<< 
			array[indice[new_p]] << " array_aaa:" << array[aaa]<< endl;
#endif
		return indice[new_p];
	}
}

void BubbleUp( int *array, int num_values, int start){
	if (num_values <= 0) return;
	int index = binary_branch_less(array, start);
	int it = start;
	int par;
	int temp = array[start];

	cout << "index:"<<index << " parent:";
	while (it > index){
		par= parent(it);
		cout  << par << " ";
		it = par;
	}
	cout << endl;

	it = start;
	while (it >= index){
		par = parent(it);
#if 1
		if (temp <= array[par]){
			break;
		}
#endif

#if 0
		if (par <= index){
		swap(array, it, par);
cout << "ENN1 ";
cout << "start:" << start;
			cout << " it:"<<it << " par:" << par << " index:"<< index<<endl;
			 break;
		}
#endif
		swap(array, it, par);
		it = par;
	}
}

#ifdef NDEBUG
void BubbleDown( int *array, int num_values, int start){
	int temp = array[start];
	int i = start, compare;
	while(true){
		compare = left_child(i);
		if (compare >= num_values) break;
		if (compare + 1 < num_values && array[compare] < array[compare+1]){
			compare++;
		}
		if (temp > array[compare]) break;
		swap(array, i, compare);
		i = compare;
	}
}
#endif

// Insert data into array in max-heap order.
// Assume that the caller never tries to insert too many values.
void MaxHeap::Insert( int data )
{
	// implement me please
	// sure

	array[num_values] = data;
	num_values++;
	BubbleUp(array, num_values, num_values-1);
}

#if NDEBUG
// Delete the max value from the heap and return that value.
// Assume that the caller 
int MaxHeap::DeleteMax()
{
	// implement me please
	// sure

	int ret = array[0];
	num_values--;
	array[0] = array[num_values];
	BubbleDown(array,num_values,0);
	return ret;
}

MaxHeap::~MaxHeap(){
	cout << "Destroying heap" << endl;
	//Print();
	int temp_num = num_values;
	int temp[num_values];
	for (int i = 0; i < temp_num; i++){
		temp[i] = DeleteMax();
	}
	
	int prev = temp[0];
{
	int i = 0;
	while (true){
		cout << temp[i] << ' ';
		i++;
		if (i >= temp_num)
			break;
		if (prev < temp[i]){
			cout << endl << "ERR "<<temp[i] << endl;
			throw "ERROR";
		}
		prev = temp[i];
	}
}
	cout << endl;
}

void MaxHeap::Tree(int i, int d){
	if (i >= num_values) return;
	Tree(left_child(i), d+1);
	for (int k = 0; k < d; k++){
		cout << "---";
	}
	cout << ' '<<array[i] << endl;
	Tree(left_child(i)+1, d+1);
}

void MaxHeap::Print(){
	if (!num_values) return;
	int prev = array[0];
	cout << "print: ";
	for (int i = 0;;){
		cout << prev << ' ';
		i++;
		if (i >= num_values) break;
		prev = array[i];
	}
	cout << endl;
}
#endif
