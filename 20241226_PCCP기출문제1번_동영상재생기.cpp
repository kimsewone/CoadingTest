//#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// commands_len�� �迭 commands�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* video_len, const char* pos, const char* op_start, const char* op_end, const char* commands[], size_t commands_len) 
{
    char elementArr[6][3] = { {0} };

    for (int i = 0; i < 2;++i)
    {
        elementArr[0][i] = pos[i];
        elementArr[1][i] = op_start[i];
        elementArr[2][i] = op_end[i];
    }
    for (int i = 0; i < 2;++i)
    {
        elementArr[3][i] = pos[3 + i];
        elementArr[4][i] = op_start[3 + i];
        elementArr[5][i] = op_end[3 + i];
    }

    int elelemtIntArr[2][3];
    int temp1 = 0;
    int temp2 = 0;
    for (int i = 0; i < 3;++i)
    {
        temp1 = atoi(elementArr[i]);
        temp2 = atoi(elementArr[3 + i]);
        elelemtIntArr[0][i] = temp1;
        elelemtIntArr[1][i] = temp2;
    }
    int tempTimeArr[3];
    int tempT = 0;
    for (int i = 0; i < 3;++i)
    {
        tempT = elelemtIntArr[0][i];
        tempTimeArr[i] = tempT * 60;
        tempT = elelemtIntArr[1][i];
        tempTimeArr[i] += tempT;
    }

    //���� pos�� op_start���� ũ�� op_end���� ������ => ������ �����϶� ������end��ġ�� �ϴ� ��ġ�صд�.(��������)
    if (tempTimeArr[0] > tempTimeArr[1] && tempTimeArr[0] < tempTimeArr[2])
        tempTimeArr[0] = tempTimeArr[2];

    //prev,next��ư������ ���ȿ� ���� pos��ȭ.
    int tempV = 0;
    for (int i = 0; i < commands_len;++i)
    {
        if (commands[i] == "prev") {//-10;
            tempV = tempTimeArr[0] - 10;
            tempTimeArr[0] = tempV < 0 ? 0 : tempV;
        }
        else {//+10;
            tempV = tempTimeArr[0] + 10;
            tempTimeArr[0] = tempV > tempTimeArr[2] ? tempTimeArr[2] : tempV;
        }
    }

    tempTimeArr[0] = tempV;

    //���� prev,next��ư�������� ����� ���� pos�� �����׻����� �������� �ٽ� üũ.
    if (tempTimeArr[0] > tempTimeArr[1] && tempTimeArr[0] < tempTimeArr[2])
        tempTimeArr[0] = tempTimeArr[2];

    int fireTime = tempTimeArr[0] / 60;
    int secondTime = tempTimeArr[0] % 60;

    char* T1 = (char*)malloc(3);
    char* T2 = (char*)malloc(3);

    if (fireTime == 0)
        sprintf_s(T1, 3, "00");
    else {
        sprintf_s(T1, 3, "%02d", fireTime);
    }
    if (secondTime == 0)
        sprintf_s(T2, 3, "00");
    else {
        sprintf_s(T2, 3, "%02d", secondTime);
    }
    //"video_len : %s /Pos : %s /op_start : %s /op_end : %s ", video_len, pos, op_start, op_end
    char* tempTotalResult = (char*)malloc(80);
    sprintf_s(tempTotalResult, 80, "video_len : %s /Pos : %s /op_start : %s /op_end : %s /", video_len, pos, op_start, op_end);


    char* T3 = (char*)malloc(18);
    T3[0] = '\0'; 
    sprintf_s(T3, 18, " / Result : %s:%s\0", T1, T2);

    int totallength = 5 * commands_len;

    size_t size = 5 * commands_len;
    char* commads2 = (char*)malloc(size);
    commads2[0] = '\0';

    for (int i = 0; i < commands_len;++i)
    {
        strcat_s(commads2, size, commands[i]);
        temp2 = commands_len - 1;
        if (i < temp2)
        {
            strcat_s(commads2, size, ",");
        }
   }
   char* TotalResult = (char*)malloc(100);
   TotalResult[0] = '\0';

   strcat_s(TotalResult, 100, tempTotalResult);
   strcat_s(TotalResult, 100, commads2);
   strcat_s(TotalResult, 100,  T3 );
 

   //printf("video_len : %s /Pos : %s /op_start : %s /op_end : %s ", video_len, pos, op_start, op_end);
   //printf("/commads : ");
   //for(int i = 0 ; i < commands_len;++i)
   //  printf("% s", commands[i]);

   //printf(" /Result : %s ",  T3); 

   return TotalResult;
}
int main()
{
    const char* cmd[3] = { "prev", "next" , "next" };
    char* result = solution("10:55", "00:05", "00:15", "06:55", cmd, 3);

    printf(result);

    return 0;
}