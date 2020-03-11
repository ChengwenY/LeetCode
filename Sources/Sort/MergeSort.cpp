/**
	归并排序：采用分治思想，
	先将长度为n的序列等分为两个子序列，
	分别对两个子序列归并排序，
	最后将两个排序好的子序列合并成1个最终排好序的序列
	时间复杂度： 最好最坏都是O(nlogn)
	空间复杂度: O(n)
*/
class Solution {
	public:
		void merge(vector<int> &arr, int begin, int mid, int end) {
			vector<int> newArr(end-begin+1); 
			int i = begin, j = mid+1, k = 0; 
			while (i <= mid && j <= end) {
				newArr[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++]; //注意一定要通过下标直接赋值newArr 因为newArr元素初始值都是0 push_back会将元素加到末尾
			}
			while (i <= mid) {newArr[k++] =arr[i++];}
			while (j <= end) {newArr[k++] =arr[j++];}
			for (int k = 0; k < newArr.size(); k++) {
				arr[begin+k] = newArr[k];
			}
		}

		void mergeSort(vector<int> &arr, int begin, int end) {
			if (end <= begin) return; // 必须有= 否则会死循环
			int mid = (begin + end) >> 1; //begin + (end-begin)/2 
			mergeSort(arr, begin, mid);
			mergeSort(arr, mid+1, end);
			merge(arr, begin, mid, end);
		}
}
