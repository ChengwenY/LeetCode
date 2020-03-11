/**
	堆排序： 利用大顶堆或小顶堆排序 。
	时间复杂度： O（nlogn）
	空间复杂度： O（1）
*/
class Solution {
	public:
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
}
//java 用数组模拟建立小顶堆
static void heapify(int[] array, int length, int i) {
	int left = 2 * i + 1, right = 2 * i + 2；
	int largest = i;

	if (left < length && array[left] > array[largest]) {
		largest = left;
	}
	if (right < length && array[right] > array[largest]) {
		largest = right;
	}

	if (largest != i) {
		int temp = array[i]; array[i] = array[largest]; array[largest] = temp;
		heapify(array, length, largest);
	}
}

public static void heapSort(int[] array) {
	if (array.length == 0) return;

	int length = array.length;
	for (int i = length / 2-1; i >= 0; i-) 
		heapify(array, length, i);

	for (int i = length - 1; i >= 0; i--) {
		int temp = array[0]; array[0] = array[i]; array[i] = temp;
		heapify(array, i, 0);
	}
}
