#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

int h[SIZE] = {0};

void insert();
void search();
void display();

int main()
{
	int choice;
	while(true)
	{
		cout << "1. Insert" << endl;
		cout << "2. Search" << endl;
		cout << "3. Display" << endl;
		cout << "4. Exit" << endl;
		
		cin >> choice;
		
		switch(choice)
		{
			case 1: insert();
					break;
					
			case 2: search();
					break;
				
			case 3: display();
					break;
					
			case 4: exit(0);
					
			default: cout << "Invalid Option" << endl;
		}
	}
	
	return 0;
}

void insert()
{
	int key;
	cout << "Enter the value: ";
	cin >> key;
	
	int hkey = key % SIZE;
	
	int i, index;
	for(i = 0; i < SIZE; i++)
	{
		index = (hkey + i) % SIZE;
		
		if(h[index]  == 0)
		{
			h[index] = key;
			break;
		}
	}
	
	if(i == SIZE)
		cout << "Array is Full" << endl;
}

void search()
{
	int key;
	cout << "Enter the value: ";
	cin >> key;
	
	int hkey = key % SIZE;
	
	int i, index;
	for(i = 0; i < SIZE; i++)
	{
		index = (hkey + i) % SIZE;
		
		if(h[index]  == key)
		{
			cout << "Element Found at location " << index+1 << endl;
			break;
		}
	}
	
	if(i == SIZE)
		cout << "Element Not Found" << endl;
}

void display()
{
	cout << "Elements are " << endl;
	for(int i = 0; i < SIZE; i++)
		cout << i << "  " << h[i] << endl;
}
