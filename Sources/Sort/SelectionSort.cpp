/**
	选择排序
	工作原理： 首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。 
	
	时间复杂度： O(n^2)
	空间复杂度： O(1)
*/
class Solution
{
public:
	void selectionSort(vector<int> &arr) {
		int len = arr.size(), minIndex = 0;
		for (int i = 0; i < len - 1; i++) {
			minIndex = i;
			for (int j = i+1; j < len; j++) {
				if (arr[j] < arr[minIndex]) {
					minIndex = j;
				}
			}
			swap(arr[i], arr[minIndex]);
		}
	}
}
