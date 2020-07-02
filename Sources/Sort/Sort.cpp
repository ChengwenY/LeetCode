#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
void selectionSort(vector<int> &arr) {
	int len = arr.size();
	for (int i = 0; i < len-1; i++) {
		for(int j = i+1; j < len; j++) {
			if (arr[j] < arr[i]) {
				swap(arr[i], arr[j]);
			}
		}
	}
}

void bubbleSort(vector<int> &arr) {
	int len = arr.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void insertSort(vector<int> &arr) {
	int len = arr.size(), preIndex = 0, current = 0;
	for (int i = 1; i < len; i++) {
		preIndex = i-1;
		current = arr[i];
		while (preIndex >= 0 && current < arr[preIndex]) {
			swap(arr[preIndex], arr[preIndex+1]);
			preIndex--;
		}
		arr[preIndex+1] = current;
	}
}

int partition(vector<int> &arr, int begin, int end) {
	int pivot = end, counter = begin;
	for (int i = begin; i < end; i++) {
		if (arr[i] < arr[pivot]) {
			swap(arr[i], arr[counter]);
			counter ++;
		}
	}
	swap(arr[counter], arr[pivot]);
	return counter;
}

void quickSort(vector<int> &arr, int begin, int end) 
{
	if(begin >= end) return;
	int qivot = partition(arr, begin, end);
	quickSort(arr, begin, qivot-1);
	quickSort(arr, qivot+1, end);
}

void merge(vector<int>&arr, int begin, int mid, int end) {
	int i = begin, j = mid + 1, k = 0;
	vector<int> temp(end-begin+1);
	while (i <= mid && j <= end) {
		temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= mid) temp[k++] = arr[j++];
	for (int i = 0; i < temp.size(); i++) {
		arr[begin + i] = temp[i];
	}
}

void mergeSort(vector<int> &arr, int begin, int end) {
	if (begin >= end) return;
	int mid = begin + (end-begin)/2;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid+1, end);
	merge(arr, begin, mid, end);
}

void heapSort(vector<int> &arr) {
	priority_queue<int,vector<int>,greater<int> > q;
	for (int i = 0; i < arr.size(); i++) {
		q.push(arr[i]);
	}
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = q.top();
		q.pop();
	}
}


int main(int argc, char *argv[]) {
	int a[5] = {5,2,3,4,1};
	vector<int> arr(a, a+5);
	mergeSort(arr, 0, 4);
	for (int i = 0; i < arr.size(); i++) {
		cout<<arr[i];
	}
}