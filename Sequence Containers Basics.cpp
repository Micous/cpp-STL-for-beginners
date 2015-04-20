//Demonstration of sequence containers- vector, deque, list, forward list, array, queue.
//This includes some basic operations which will help you get started with modern C++.
//Author: Irfan Hamid - https://irfnhmd.github.io

#include<Windows.h>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<forward_list>
#include<array>
#include<algorithm>

using namespace std;

int main()
{
	//this is for the console window. You can skip this code or leave it as it is. Runs only in Visual studio.
	//if you are using anyother compiler, delete this code to the CONSOLE_STOP comment.
	HANDLE dataout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX font;
	GetCurrentConsoleFontEx(dataout, false, &font);
	font.dwFontSize.X = 12;
	font.dwFontSize.Y = 12;
	SetCurrentConsoleFontEx(dataout, false, &font);
	SetConsoleTextAttribute(dataout, 0x0B);// you can change the hex value for different colors of your choice.
	//CONSOLE_STOP

	cout << endl << "Result stack" << endl;
	//implementing vectors
	vector<int> vec;
	vec.push_back(4);//we can add elements dynamically also
	vec.push_back(1);
	vec.push_back(7);

	vector<int> ::iterator itr1 = vec.begin();
	vector<int> ::iterator itr2 = vec.end();

	cout << "Displaying a vector:" << endl;
	for (vector<int> ::iterator itr = itr1; itr != itr2; ++itr)
		cout << *itr << endl<<endl;

	//implementing queue
	queue<int> que;
	for (int i = 0; i <= 10; i++)
		que.push(i);

	cout << "###########################################" << endl << endl;
	cout << "Displaying queue elements:" << endl;
	while (!que.empty())
	{
		cout << que.front() << endl << endl;
		que.pop();
	}
	//implementing deque
	deque<int> deq = { 4, 6, 7 };
	deq.push_front(2);
	deq.push_back(9);

	deque<int> ::iterator _itr1 = deq.begin();   
	deque<int> ::iterator _itr2 = deq.end();

	/*for (int i = 0; i <= deq.size(); ++i)//inconveineint use of for loop for vectors and deque
		cout << "Displaying a deque:" << deq[i] << endl;*/
	cout << "###########################################" << endl << endl;
	cout << "Displaying a deque:" << endl;
	for (deque<int> ::iterator _itr = _itr1; _itr != _itr2; ++_itr)
		cout << *_itr << endl << endl;
	
	//implementing lists
	list<int> mylist = { 5, 2, 9 };
	mylist.push_back(6); // {5,2,9,6}
	mylist.push_front(4); //{4,5,2,9}

	list<int> ::iterator _litr1 = mylist.begin();
	list<int> ::iterator _litr2 = mylist.end();

	cout << "###########################################" << endl << endl;
	cout << "Displaying a list:" << endl;
	for (list<int> ::iterator _itrl = _litr1; _itrl != _litr2; ++_itrl)
		cout << *_itrl << endl << endl;

	list<int> ::iterator _litr = find(mylist.begin(), mylist.end(), 2);
	mylist.insert(_litr, 8);// inserts 8 at _litr->2
	_litr++;// now _litr points to 9

	mylist.erase(_litr);//erases 9 from the list

	list<int> ::iterator _litra = mylist.begin();
	list<int> ::iterator _litrb = mylist.end();

	cout << "###########################################" << endl << endl;
	cout << "Displaying a new list:" << endl;
	for (list<int> ::iterator _itrll = _litra; _itrll != _litrb; ++_itrll)
		cout << *_itrll << endl << endl;

	//implementing the biggest advantage of lists -> SPLICE
	list<int> mylist_ = { 1, 3, 5, 6 };
	list<int> ::iterator itr_a = mylist_.begin();
	list<int> ::iterator itr_b = mylist_.end();

	list<int> _mylist_ = { 2, 4, 7, 8 };
	list<int> ::iterator _mItr = _mylist_.begin();
	list<int> ::iterator _nItr = _mylist_.end();

	mylist_.splice(itr_b, _mylist_, _mItr, _nItr);

	list<int> ::iterator stItr = mylist_.begin();
	list<int> ::iterator enItr = mylist_.end();

	cout << "###########################################" << endl << endl;
	cout << "Displaying mylist with spliced elements:" << endl;
	for (list<int> ::iterator newItr = stItr; newItr != enItr; ++newItr)
		cout << *newItr << endl << endl;

	//sort the list elements
	mylist_.sort();
	cout << endl << "###########################################" << endl << endl;
	cout << "Final sorted list is:" << endl;
	for (auto& l : mylist_)
		cout << l << endl << endl;

	//implementing forward list
	forward_list<int> flist = { 2, 4, 1, 0, 6, 5, 9 };
	flist.push_front(10);//elements can only be added at front of this list. So got the name.

	forward_list<int> ::iterator fitr1 = flist.begin();
	forward_list<int> ::iterator fitr2 = flist.end();

	cout << endl << "###########################################" << endl << endl;
	cout << "Displaying a forward list:" << endl;
	for (forward_list<int> ::iterator fitr = fitr1; fitr != fitr2; ++fitr)
		cout << *fitr << endl << endl;

	//implementing arrays
	array<int, 7> _array = { 1, 2, 3, 4, 5, 6, 7 };
	array<int, 7> ::iterator aitr;
	int _size = _array.size();
	cout << endl << "###########################################" << endl << endl;
	cout << "Displaying the array of size" << " " << _size << ":" << endl;
	for (aitr = _array.begin(); aitr != _array.end(); ++aitr)
		cout << *aitr << endl << endl;
	system("pause");
	return 0;

}