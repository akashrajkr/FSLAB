#include <bits/stdc++.h>
using namespace std;

bool present(queue<int> que, int val)
{
	while(!que.empty())
	{
		if(que.front() == val)
			return true;
		
		que.pop();
	}

	return false;
}

int main()
{
	int bufferSize = 4;
	int noOfPages = 12;
	
	int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
	
	int pageFaults = 0;
	
	queue<int> que;
	for(int i = 0; i < noOfPages; i++)
	{
		if(que.size() < bufferSize && !present(que, pages[i]))
		{
			que.push(pages[i]);
			pageFaults++;
		}
		else if(!present(que, pages[i]))
		{
				que.pop();
				que.push(pages[i]);
				pageFaults++;
		}
	}
	
	cout << "Number of page faults: " << pageFaults << endl;
	
	return 0;
}
