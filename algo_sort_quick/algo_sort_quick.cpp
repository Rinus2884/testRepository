
#include <iostream>
using namespace std;

int DoPartition(int tArray[], int  tBegin, int tEnd)
{
    int tPivot = 0;//피벗, 분할의 기준점
    int L = 0;//왼쪽파트에서 오른쪽 집합에 포함될 원소들을 선별하기 위한 인덱스
    int R = 0;//오른쪽파트에서 왼쪽 집합에 포함될 원소들을 선별하기 위한 인덱스

    int tTemp = 0;  //교환을 위한 임시변수

    //L은 처음 시작이 맨 왼쪽 원소, R은 처음 시작이 맨 오른쪽 원소
    L = tBegin;
    R = tEnd;


    //피벗 선정
    tPivot = (tBegin + tEnd) / 2;

    while (L < R)
    {
        //적합한 L위치를 찾는다<-- L>=pivot
        while (tArray[L]<tArray[tPivot] && L<R)
        {
            L++;
            //L은 오른쪽으로 이동
        }
        //적합한 R위치를 찾는다<-- R<pivot
        while (tArray[R] >= tArray[tPivot] && L < R)
        {
            R--;
            //R은 왼쪽으로 이동
        }

        //여기까지 오면, tArray[L]>=tArray[tPivot]이란 의미
        //여기까지 오면, tArray[R]<tArray[tPivot]이란 의미
        //<------tArray[L]은  오른쪽에 있어야 한다.
        //<------tArray[R]은  오른쪽에 있어야 한다.

        if (L<R)
        {
            //교환루틴
            //tArray[L]값과 tArray[R]값의 교환
            //  L             R
            //       pivot

            tTemp = tArray[L];
            tArray[L] = tArray[R];
            tArray[R] = tTemp;

            if (L == tPivot)//L이 Pivot인 경우의 처리
            {
             //  L             R
            //  pivot

            // 여기서 L과 R이 바뀌었으므로 이제 R이 있는 곳이 pivot 위치

            //  L             R
            //              pivot


                tPivot = R;
            }
        }


    }
    // L == R
    //
    //  L
    //  R
    //  pivot


    tTemp = tArray[tPivot];
    tArray[tPivot] = tArray[R];
    tArray[R] = tTemp;



    return R;
}




void QuickSort(int tArray[], int tBegin, int tEnd)
{
    //피벗: 임의의 기준점
    int tPivot = 0;

    
    if (tBegin < tEnd)
    {

        //파티션을 : 피벗을 결정하고 왼쪽, 오른쪽 부분집합으로 구별하여 만들어내는 과정
        tPivot = DoPartition(tArray, tBegin, tEnd);

        //파티셔닝을 거치고 나면, 부분집합들이 만들어지고
        //해당 부분집합들에 동일한 알고리즘을 적용한다.

        //recursive case
        //각각의 왼쪽, 오른쪽 부분집합에 대해 해당 퀵소트 알고리즘을 반복한다.
        //(재귀호출로 표현)
        QuickSort(tArray, tBegin, tPivot - 1);
        QuickSort(tArray, tPivot + 1, tEnd);

    }

    //tBegin < tEnd이 경우가 아니라면, 원소가 하나만 있다는 것이다. 더 이상 쪼갤 수 없다 라는 것이다.
    //base case
}





int main()
{
    int tArray[5] = { 69, 10, 30, 16, 2 };


    //before
    for (int t:tArray)
    {
        cout << t << ", ";
    }


    QuickSort(tArray, 0, 5 - 1);

    //after
    cout << endl;
    for (int t : tArray)
    {
        cout << t << ", ";
    }

    return 0;
}

//알고리즘 >> 원리 이해, 시간복잡도 이해, 코드를 외울 필요없다