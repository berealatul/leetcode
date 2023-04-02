#pragma once
#include <vector>
#include "myFunction.h"
using namespace std;

void bubbleSort(vector<int>& list) {
	bool isSwapped = true;
	int listSize = list.size() - 1;

	while (isSwapped) {
		isSwapped = false;
		for (int i = 0; i < listSize; i++) {
			if (list[i] > list[i + 1]) {
				swap(list[i], list[i + 1]);
				isSwapped = true;
			}
		}
		listSize--;
	}
}


int findMinIndex(vector<int>& list, int start) {
	int minIndex = start;
	for (int i = start + 1; i < list.size(); i++) {
		if (list[i] < list[minIndex]) minIndex = i;
	}
	return minIndex;
}

void selectionSort(vector<int>& list) {
	int start = 0;
	while (start < list.size()) {
		int minIndex = findMinIndex(list, start);		
		swap(list[start], list[minIndex]);
		start++;
	}
}


void insertionSort(vector<int>& list) {
	int buffer;
	for (int i = 0, n = list.size(); i < n; i++) {
		buffer = list[i];
		int index = i;
		while (index) {
			if (list[index - 1] > buffer) {
				list[index] = list[index - 1];
				index--;
			}
			else break;
		}
		list[index] = buffer;
	}
}


void merge(vector<int>& left, vector<int>& right, vector<int>& list) {
	int i = 0, j = 0, k = 0;

	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j]) list[k++] = left[i++];
		else list[k++] = right[j++];
	}

	while(i < left.size()) list[k++] = left[i++];
	
	while(j < right.size()) list[k++] = right[j++];
}

void mergeSort(vector<int>& list) {
	if (list.size() < 2) return;

	auto middle = list.size() / 2;

	vector<int> left(middle);
	for (auto i = 0; i < middle; i++) left[i] = list[i];

	vector<int> right(list.size() - middle);
	for (auto i = middle; i < list.size(); i++) right[i-middle] = list[i];

	mergeSort(left);
	mergeSort(right);

	merge(left, right, list);
}


int partition(vector<int>& list, int start, int end) {
	auto pivot = list[end];
	auto boundary = start - 1;
	for (int i = start; i <= end; i++) {
		if (list[i] <= pivot) {
			swap(list[++boundary], list[i]);
		}
	}
	return boundary;
}

void quickSort(vector<int>& list, int start, int end) {
	if (start >= end) return;

	auto boundary = partition(list, start, end);
	// sort left
	quickSort(list, start, boundary - 1);
	// sort right
	quickSort(list, boundary + 1, end);
	
}

void quickSort(vector<int>& list) {
	quickSort(list, 0, list.size() - 1);
}

void countingSort(vector<int>& list, int k) {
	vector<int> repetitionCount(k + 1, 0);
	for (auto& val : list) repetitionCount[val]++;
	
	int index = 0;
	for (int i = 0; i <= k; i++) {
		while(repetitionCount[i]--) list[index++] = i;
	}
}

vector<vector<int>> createBuckets(vector<int>& list, int bucketSize) {
	vector<vector<int>> buckets(bucketSize);
	for (auto& val : list) {
		// limiting index to range of bucketSize
		auto index = (val / bucketSize >= bucketSize) ? bucketSize - 1 : val / bucketSize;
		buckets[index].push_back(val);
	}
	return buckets;
}

void bucketSort(vector<int>& list, int bucketSize) {
	vector<vector<int>> buckets = createBuckets(list, bucketSize);

	int index = 0;
	for (auto& bucket : buckets) {
		bubbleSort(bucket);
		for (auto& val : bucket) list[index++] = val;
	}
}

int linearSearch(vector<int>& list, int target) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i] == target) return i;
	}
	return -1;
}

int binarySearch(vector<int>& list, int target, int left, int right) {
	if (left > right) return -1;

	auto middle = (left + right) / 2;
	
	if (target == list[middle]) return middle;
	
	if (target < list[middle]) return binarySearch(list, target, left, middle - 1);
	
	return binarySearch(list, target, middle + 1, right);
}

int binarySearchR(vector<int>& list, int target) {
	return binarySearch(list, target, 0, list.size() - 1);
}

int binarySearchI(vector<int>& list, int target) {
	int left = 0;
	int right = list.size() - 1;
	
	while (left <= right) {
		int middle = (left + right) / 2;

		if (list[middle] == target) return middle;

		if (target < list[middle]) right = middle - 1;
		else left = middle + 1;
	}

	return -1;
}

int ternarySearch(vector<int>& list, int target, int left, int right) {
	if (left > right) return -1;

	auto partitionSize = (right - left) / 3;
	auto mid1 = left + partitionSize;
	auto mid2 = right - partitionSize;
	
	if (list[mid1] == target) return mid1;
	if (list[mid2] == target) return mid2;
	
	if (target < list[mid1]) return ternarySearch(list, target, left, mid1 - 1);
	if (target > list[mid2]) return ternarySearch(list, target, mid2 + 1, right);
	return ternarySearch(list, target, mid1 + 1, mid2 - 1);
}

int ternarySearchR(vector<int>& list, int target) {
	return ternarySearch(list, target, 0, list.size() - 1);
}

int ternarySearchI(vector<int>& list, int target) {
	int left = 0;
	int right = list.size() - 1;

	while (left <= right) {
		auto partitionSize = (right - left) / 3;
		auto mid1 = left + partitionSize;
		auto mid2 = right - partitionSize;

		if (list[mid1] == target) return mid1;
		if (list[mid2] == target) return mid2;

		if (target < list[mid1]) right = mid1 - 1;
		else if (target > list[mid2]) left = mid2 + 1;
		else left = mid1 + 1, right = mid2 - 1;
	}
	return -1;
}

int jumpSearch(vector<int>& list, int target) {
	auto blockSize = static_cast<int>(sqrt(list.size()));
	
	int start = 0;
	int next = start + blockSize;
	while (start < list.size() && target > list[next - 1]) {
		start += blockSize;
		if (start >= list.size()) break;

		next += blockSize;
		if (next > list.size()) next = list.size();
	}

	while (start < next) {
		if (list[start] == target) return start;
		start++;
	}

	return -1;
}

int exponentialSearch(vector<int>& list, int target) {
	int bound = 1;
	while (bound < list.size() && target > list[bound]) bound *= 2;

	int left = bound / 2;
	int right = (bound >= list.size()) ? list.size() - 1 : bound;
	
	return binarySearch(list, target, left, right);
}