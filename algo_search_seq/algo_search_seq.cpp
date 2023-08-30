
#include <iostream>
using namespace std;
//순차검색 알고리즘
void SequentialSearch(int tArray[], int tLength, int tX)
{
    int ti = 0;


    while (ti<tLength && tArray[ti]!= tX)
    {
        ti++;
    }

    //검색 성공 또는 검색 실패( 자료구조 안에 해당 자료가 없을 수도 있으므로 )
    if (ti<tLength)
    {
        cout << "검색 성공" << endl;

    }
    else
    {
        cout << "검색 실패" << endl;
    }

}



int main()
{
    int tArray[7] = { 8,30,1,9,1,19,2 };
    int tLength = 7;




    return 0;
}

