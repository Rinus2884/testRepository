/*
    Selection Sort
    선택 정렬

    오름차순 정렬을 가정한다.
    <--즉, 선택의 값으로 최소값을 가정한다.
*/
#include <iostream>
using namespace std;

void SelectionSort(int tArray[], int tLength)
{
    //카운트용
    int ti = 0;
    int tj = 0;

    int tMin = 0;       //최소값 기록용
    int tTemp = 0;     //교환용 임시변수

    //기준위치는 첫원소에서부터 시작해서
    //마지막 원소 바로 전까지 증가
    for (ti = 0;ti<tLength - 1;++ti)
    {
        //기준위치 선정( 기준위치에 있는 것을 일단 최소값으로 가정하고 시작한다 )
        tMin = ti;

        //기준 위치 이후에 있는 원소들과 비교한다.
        //(첫 시작은 기준위치 바로 다음)
        for (tj = ti + 1;tj<tLength;++tj)
        {
            //더 작은 값이 발견되면 최소값 갱신(최소값이 있는 인덱스를 기억시켜 둔다)
            if (tArray[tMin] > tArray[tj])
            {
                tMin = tj;
            }
        }

        //여기까지 오면 선택완료
        if (ti != tMin)
        {
            //교환 루틴
            tTemp = tArray[ti];//<--기준위치의 원소의 값
            tArray[ti] = tArray[tMin];
            tArray[tMin] = tTemp;
        }


    }

}


int main()
{
    int tArray[5] = { 69,10,30,2,16 };
    int tLength = 5;

    //before
    for (int t:tArray)
    {
        cout << t<<"\t";
    }

    SelectionSort(tArray, tLength);


    //after
    cout << endl;
    for (int t : tArray)
    {
        cout << t << "\t";
    }


    return 0;
}


