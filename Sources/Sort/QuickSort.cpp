/**
	快速排序： 基本思想是通过一趟排序将待排序的数组分成两部分，一部分比基准小，另一部分比基准大，分别对这两部分继续排序，以达到整个序列有序。
	具体算法： 从数列中挑出一个元素，称为 “基准”（pivot）；
			 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
			 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。
	时间复杂度： O(nlogn);
*/
class Solution {
public:
	int partition(vector<int> &arr, int begin, int end) {
		int pivot = end, counter = begin; //4.以end为基准，counter为小于pivot的个数
		for (int i = begin; i < end; i++) { //5.遍历begin 到end 
			if (arr[i] < arr[pivot]) {  
				swap(arr[i], arr[counter]); //6.将小于pivot的值与counter交换位置，并将个数+1
				counter++;
			}
		}
		swap(arr[pivot], arr[counter]); //7.经过循环后counter之前的值均小于pivot，交换pivot 和 counter
		return counter;
	}
	int partition1(vector<int> &arr, int begin, int end) {
		int pivot = begin, index = pivot + 1; //4.以begin为基准，
		for (int i = index; i <= end; i++) { //5.遍历begin+1 到end 
			if (arr[i] < arr[pivot]) {  
				swap(arr[i], arr[index]); //6.将小于pivot的元素交换在pivot之后，即index的位置，并记录当前小于pivot元素的位置index++
				index ++;
			}
		}
		swap(arr[pivot], arr[index-1]); //7.经过循环后index之前均为小于pivot的元素 将pivot与index-1的元素交换，此时index-1即为pivot
		return index-1;
	}

	void quickSort(vector<int> &arr, int begin, int end) {
		
		if (end <= begin) return;
		int pivot = partition(arr, begin, end); //1.挑出基准 以 begin为基准，将小于begin放前面，大于begin放后面，确定begin的位置即基准
		quickSort(arr, begin, pivot-1); //2.排序基准左边
		quickSort(arr, pivot+1, end);//3.排序基准右边
	}
}