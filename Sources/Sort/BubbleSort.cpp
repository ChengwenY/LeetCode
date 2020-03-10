/**
	冒泡排序
	工作原理： 比较相邻元素，将较大的元素沉到最后，较小元素浮到数组顶端。注意第二个for循环判断条件 
	
	时间复杂度： O(n^2)
	空间复杂度： O(1)
*/
class Solution 
{
public:
	void bubbleSort(vector<int> &arr) {
		int len = arr.size();
		for (int i = 0; i < len - 1; i++) {
			for (int j = 0; j < len - 1 - i; j++) {
				if (arr[j] > arr[j+1]) {
					swap(arr[j], arr[j+1]);
				}
			}
		}
	}
}
