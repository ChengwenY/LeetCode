/**
	插入排序
	工作原理： 通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。  （将第0个元素作为排好序的序列。）
	
	时间复杂度： O(n^2)
	空间复杂度： O(1)
*/

class Solution
{
public:
	void insertSort(vector<int> &arr) {
		int len = arr.size(), preIndex = 0, current = 0;
		for (int i = 1; i < len; i++) {
			preIndex = i-1;
			current = arr[i];
			while (preIndex >=0 && arr[preIndex] > current) {
				arr[preIndex + 1] = arr[preIndex];
				preIndex--;
			}
			arr[preIndex + 1] = current;
		}
	}
}