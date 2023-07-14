#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Stack.h"

// ≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);

// œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);

void sortprint(int* a, int n);

// —°‘Ò≈≈–Ú
void SelectSort(int* a, int n);

void BubbleSort(int* a, int n);

// ∂—≈≈–Ú
void AdjustDwon(int* a, int n, int root);

void HeapSort(int* a, int n);

void QuickSort(int* a, int begin, int end);

void QuickSortNonR(int* a, int begin, int end);