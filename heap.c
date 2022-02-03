/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author: 
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"


/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void heapSort(struct Employee *A, int n)
{
	//TODO - BuildHeap on the list
	
	//TODO - while n > 0:
		//TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
		//TODO - A[n-1] now sorted in place!
		//TODO - So decrement n
		//TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
}


/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void buildHeap(struct Employee *A, int n)
{
	int half = (n/2); //floor
	for(int i=half;i>0; i--){
		heapify(A,i,n);
	}
	//heapify() every element from A[n/2] to A[0]
}


/**
 * We want to start with A[i] and trickle it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the list
 */
void heapify(struct Employee *A, int i, int n)
{
	int smaller = i;
	//get index of left child of element i
	 int leftChild = (2*(i+1)-1);
	//get index of right child of element i
	 int rightChild = (2*(i+1));
	//determine which child has a smaller salary. We'll call the index of this
	//element: "smaller"
	if(leftChild<n&&(A[leftChild].salary < A[i].salary)){
		smaller = leftChild; 
		printf("Left smaller\n");
	}
	if(rightChild<n&&(A[rightChild].salary<smaller)){
		smaller = rightChild;
		printf("Right smaller\n");
	}
	printf("smaller: %d\n", smaller);
	//recursively check if the salary at A[i] > the salary at A[smaller]. 
	//If it is, swap the two.Then recursively heapify A[smaller].
	if(smaller != i){
		swap(&A[i],&A[smaller]);
		heapify(A, smaller, n);
	}//Continue recursion as long as i is within range AND either right_child and left_child are still within range.
}

/**
 * Gets the minimally paid employee. Assumes the given list is a min-heap.
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
struct Employee *getMinPaidEmployee(struct Employee *A, int n)
{
	//TODO
	return A;
}


/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(struct Employee *e1, struct Employee *e2){
	struct Employee temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(struct Employee *A, int n){
	for (int i = 0; i < n; ++i) {
		printf("[id: %s salary: %d], \n", A[i].name, A[i].salary);
	}
}
