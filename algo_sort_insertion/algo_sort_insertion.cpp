/*
	Insertion Sort
	삽입 정렬


	오름차순 정렬을 가정한다
*/
#include <iostream>
using namespace std;


void InsertionSort(int tArray[], int tLength)
{
	int ti = 0;		//카운트 용
	int tEdge = 0;	//sorted와 unsorted의 경계

	int tTemp = 0;	//교환용 임시 변수


	//unsorted부분집합 의 첫번째 원소를 기억해둠
	for (ti = 1;ti<tLength;++ti)
	{
		tTemp = tArray[ti];//삽입을 위해 임시변수에 담아둔다(사실상 교환루틴)
		tEdge = ti;//<--'경계'는 unsorted의 첫번째 원소로 가정해둔다

		/*
			sorted부분집합의 뒤에서부터 원소들과 비교하여
			적합한 위치를 찾고
			(sorted부분집합의 원소들을 하나씩 뒤로 밀어)
			삽입하기 적절한 위치를 마련한다
		*/

		while (tEdge > 0 && tArray[tEdge-1]>tTemp)
		{
			tArray[tEdge] = tArray[tEdge - 1];
			tEdge = tEdge - 1;
		}

		tArray[tEdge] = tTemp;
	}




}





int main()
{
	int tArray[5] = { 69, 10, 30, 2, 16};
	
	//before
	for (int t:tArray)
	{
		cout << t << "\t";
	}


	InsertionSort(tArray, 5);


	cout << endl;
	//after
	for (int t : tArray)
	{
		cout << t << "\t";
	}



   return 0;
}

