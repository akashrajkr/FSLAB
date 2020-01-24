#include <bits/stdc++.h>
#include <ctime>
#include <cstdio>
#include <unistd.h>
#include <fstream>
using namespace std;

void fileRead();
void fileWrite();
void fileReset();
void find();
void findNext();
void modify();
void fileDelete();

int main()
{	
	bool done = false;
	while(!done)
	{
		int choice;
		cout << "1 Read\n2 Write\n3 Reset\n4 Find\n5 Modify\n6 Delete\n7 Close\n";
		cout << "Enter your choice" << endl;  
		cin >> choice;
		
		switch(choice)
		{
			case 1: fileRead();
					break;
					
			case 2: fileWrite();
					break;
					
			case 3: fileReset();
					break;
					
			case 4: find();
					break;
	
			case 5: modify();
					break;
					
			case 6: fileDelete();
					break;
					
			case 7: done = true;
					break;
					
			default: cout << "Invalid operation" << endl;
		}
		
		sleep(2);
	}
	
	return 0;	
}

void fileRead()
{
	ifstream fin;
	string line;
	fin.open("temp.txt");
	
	cout << "File content is " << endl;
	
	while(fin)
	{
		getline(fin, line);
		cout << line << endl;
	}
	
	cout << endl;
	
	fin.close();
}

void fileWrite()
{
	ofstream fout;
	string line;
	
	fout.open("temp.txt", ios::app);
	cout << "Enter a string to append to file OR enter -1 to stop" << endl;
	
	while(fout)
	{
		getline(cin, line);
		
		if(line == "-1")
			break;
			
		fout << line << endl;
	}
	
	fout.close();
}

void fileReset()
{
	ofstream fout;
	fout.open("temp.txt", ios::trunc);
	cout << "File contents is cleared" << endl;
	fout.close();
}

void find()
{
	/*string line;
	string str;
	cout <<  "Enter a string to find: ";
	cin >> str;
	
	ifstream fin;
	fin.open("temp.txt");
	
	int lineCnt = 0, pos;
	while(fin)
	{
		lineCnt++;
		getline(fin, line);
		
		pos = line.find(str);
		if(pos != string::npos)
		{
			cout << str << " found at line no " << lineCnt << " and position value " << pos << endl;
			fin.close();
			
			return;
		}
	}
	
	fin.close();
	cout << str << " does not exist" << endl;*/
	
	string fileName;
	cout << "Enter the file name: ";
	cin >> fileName;
	
	ifstream fin;
	fin.open(fileName.c_str());
	
	if(fin.good())
		cout << "File Found" << endl;
	else
		cout << "File Does Not Exist" << endl;
}

void modify()
{
	string fileName;
	cout << "Enter the file name: ";
	cin >> fileName;
	
	string newName;
	cout << "Enter the new file name: ";
	cin >> newName;
	
	if(rename(fileName.c_str(), newName.c_str()) == 0)
		cout << "File Modified Successfully" << endl;	
	else
		cout << "File Does Not Exist" << endl;
}

void fileDelete()
{
	string fileName;
	cout << "Enter the file name: ";
	cin >> fileName;
	
	if(remove(fileName.c_str()) == 0)
		cout << "File deleted Successfully" << endl;
	else
		cout << "file does not exist" << endl;
}
