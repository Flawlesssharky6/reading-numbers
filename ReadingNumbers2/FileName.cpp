#include <iostream>
#include <fstream>
using namespace std;
const int SIZE = 500, DIVISOR = 12;
const int baseline = 50;
bool EvenNumber(int i);
bool readFile(string fileName, int numbers[], int size);
void Max(int num, int& CurrentMax);
bool Greater(int baseline, int greater);
void divisibility(int divisor, int dividend, int& quotient);
int SumOfDivide(int sum, int divisor, int dividend);
int Total(int total, int numbers);
template <class T>
void shellsort(T a[], int size);
template <class T>
void swapper(T& a, T& b);
template <class T>
int search(T a[], T key);

int main()
{
	int numbers[SIZE];
	int total=0;
	int max, divisible = 0, sum = 0;
	int num_greater = 0, chosen_number;
	string file;
	int evens = 0, odds = 0;
	cout << "Enter file name: ";
	cin >> file;
	if (readFile(file, numbers, SIZE))
	{
		shellsort(numbers, SIZE);
		cout << "Choose a number to find: ";
		cin >> chosen_number;
		int x = search(numbers, chosen_number);
		if (x != -1)
			cout << numbers[x] << " found at: " << x << endl;
		else
			cout << "not found" << endl;
		max = numbers[0];
		for (int i = 0; i < SIZE; i++) {
			total = Total(total, numbers[i]);
			sum = SumOfDivide(sum, DIVISOR, numbers[i]);
			Max(numbers[i], max);
			divisibility(DIVISOR, numbers[i], divisible);
			if (Greater(baseline, numbers[i])) {
				num_greater++;
			}
			if (EvenNumber(numbers[i])) {
				evens++;
			}
			else {
				odds++;
			}

		}
		cout << "Number of even numbers: " << evens << endl << "Number of odd numbers: " << odds << endl;
		cout << "The first number is: " << numbers[0] << endl << "The last number is: " << numbers[499] << endl;
		cout << "The greatest value is: " << max << endl;
		cout << "There are " << num_greater << " numbers greater than " << baseline << endl;
		cout << "There are " << divisible << " numbers divisible by " << DIVISOR << endl;
		cout << "The sum of the numbers divisible by " << DIVISOR << " is: " << sum << endl;
		cout << "The total of the values is: " << total << endl;
		cout << "The average of the values is: " << total / SIZE << endl;

	}
	else {
		cout << "Unable to open file! Aborting ......" << endl;
	}
	return 0;
}

bool EvenNumber(int i) {
	bool even;
	double Remainder = i % 2;
	if (Remainder == 0) {
		even = true;
	}
	else {
		even = false;
	}
	return even;
}

bool readFile(string fileName, int numbers[], int size)
{
	bool OK = true;
	ifstream fin;
	int i = 0;
	fin.open(fileName);
	if (!fin)
		OK = false;
	else
	{
		while (fin >> numbers[i])
		{
			i++;
		}
	}
	return OK;
}
void Max(int num, int& max) {
	if (num > max) {
		max = num;
	}
}
bool Greater(int baseline, int greater) {
	bool comparison = false;
	if (greater > baseline) {
		comparison = true;
	}
	return comparison;
}
void divisibility(int divisor, int dividend, int& quotient) {
	if (dividend % divisor == 0) {
		quotient++;
	}
}
int SumOfDivide(int sum, int divisor, int dividend) {
	if (dividend % divisor == 0) {
		sum += dividend;
	}
	return sum;
}
int Total(int total, int numbers) {
	total += numbers;
	return total;
}
template <class T>
void shellsort(T a[], int size) {
	bool flag = true;
	int i, d = size;
	while (flag || d > 1) {
		flag = false;
		d = (d + 1) / 2;
		for (i = 0; i < (size - d); i++) {
			if (a[i + d] < a[i]) {
				T temp = a[i];
				a[i] = a[i + d];
				a[i + d] = temp;
				//swapper(a[i], a[i+d])

				flag = true;
			}
		}
	}
}

template <class T>
void swapper(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
int search(T a[], T key) {
	int first = 0;
	int last = SIZE - 1, middle, pos = -1;
	bool found = false;
	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (a[middle] == key) {
			found = true;
			pos = middle;
		}
		else {
			if (a[middle] > key) {
				last = middle - 1;
			}
			else {
				first = middle + 1;
			}
		}
	}
	return pos;
}