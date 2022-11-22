// algo_sort_quick.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int DoPartition(int tArray[], int tBegin, int tEnd)
{
    int tPivot      = 0;
    int L           = 0;
    int R           = 0;

    int tTemp = 0;

    L = tBegin;
    R = tEnd;

    //피벗 선정 
    tPivot = (int)((tBegin + tEnd) / 2);

    while (L < R)
    {
        //적합한 L을 찾는다
        while (tArray[L] < tArray[tPivot] && (L<R) )
        {
            L++;
        }
        //적합한 R을 찾는다
        while (tArray[R] >= tArray[tPivot] && (L < R))
        {
            R--;
        }

        if (L < R)
        {
            // L과 R 원소의 자리 교환
            tTemp       = tArray[L];
            tArray[L]   = tArray[R];
            tArray[R]   = tTemp;

            if (L == tPivot)    // L이 피봇인 경우,
            {
                tPivot = R;     // 변경된 피봇의 위치(R)를 저장!
            }
        }
    }

    // 더 이상 진행할 수 없으므로 R 원소와 피봇 원소의 자리를 교환하여 마무리
    tTemp           = tArray[tPivot];
    tArray[tPivot]  = tArray[R];
    tArray[R]       = tTemp;



    return R;
}


void QuickSort(int tArray[], int tBegin, int tEnd)
{
    int tPivot = 0;

    if (tBegin < tEnd)
    {
        tPivot = DoPartition(tArray, tBegin, tEnd);// 피봇의 위치에 의해 분할 위치 결정

        // 피봇의 왼쪽 부분집합에 대해 퀵 정렬을 재귀호출
        QuickSort(tArray, tBegin, tPivot - 1);
        // 피봇의 오른쪽 부분집합에 대해 퀵 정렬을 재귀호출
        QuickSort(tArray, tPivot + 1, tEnd);
    }

}



int main()
{
    std::cout << "algo_sort_quick"<<endl;

    int tArray[5] = { 69, 10, 30, 2, 16 };
    int tLength = 5;

    QuickSort(tArray, 0, tLength - 1);

    for (int ti = 0; ti < tLength; ti++)
    {
        cout << tArray[ti] << ", ";
    }



    return 0;
}


