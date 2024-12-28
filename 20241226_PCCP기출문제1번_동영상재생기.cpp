//#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
당신은 동영상 재생기를 만들고 있습니다.당신의 동영상 재생기는 10초 전으로 이동, 10초 후로 이동, 오프닝 건너뛰기 3가지 기능을 지원합니다.각 기능이 수행하는 작업은 다음과 같습니다.

10초 전으로 이동 : 사용자가 "prev" 명령을 입력할 경우 동영상의 재생 위치를 현재 위치에서 10초 전으로 이동합니다.현재 위치가 10초 미만인 경우 영상의 처음 위치로 이동합니다.영상의 처음 위치는 0분 0초입니다.
10초 후로 이동 : 사용자가 "next" 명령을 입력할 경우 동영상의 재생 위치를 현재 위치에서 10초 후로 이동합니다.동영상의 남은 시간이 10초 미만일 경우 영상의 마지막 위치로 이동합니다.영상의 마지막 위치는 동영상의 길이와 같습니다.
오프닝 건너뛰기 : 현재 재생 위치가 오프닝 구간(op_start ≤ 현재 재생 위치 ≤ op_end)인 경우 자동으로 오프닝이 끝나는 위치로 이동합니다.
동영상의 길이를 나타내는 문자열 video_len, 기능이 수행되기 직전의 재생위치를 나타내는 문자열 pos, 오프닝 시작 시각을 나타내는 문자열 op_start, 오프닝이 끝나는 시각을 나타내는 문자열 op_end, 사용자의 입력을 나타내는 1차원 문자열 배열 commands가 매개변수로 주어집니다.이때 사용자의 입력이 모두 끝난 후 동영상의 위치를 "mm:ss" 형식으로 return 하도록 solution 함수를 완성해 주세요.

제한사항
video_len의 길이 = pos의 길이 = op_start의 길이 = op_end의 길이 = 5
video_len, pos, op_start, op_end는 "mm:ss" 형식으로 mm분 ss초를 나타냅니다.
0 ≤ mm ≤ 59
0 ≤ ss ≤ 59
분, 초가 한 자리일 경우 0을 붙여 두 자리로 나타냅니다.
비디오의 현재 위치 혹은 오프닝이 끝나는 시각이 동영상의 범위 밖인 경우는 주어지지 않습니다.
오프닝이 시작하는 시각은 항상 오프닝이 끝나는 시각보다 전입니다.
1 ≤ commands의 길이 ≤ 100
commands의 원소는 "prev" 혹은 "next"입니다.
"prev"는 10초 전으로 이동하는 명령입니다.
"next"는 10초 후로 이동하는 명령입니다.

입출력 예
video_len	pos	    op_start	op_end	    commands	               result
"34:33"	   "13:00"	"00:55"	    "02:55"     ["next", "prev"]	       "13:00"
"10:55"	   "00:05"	"00:15"	    "06:55"     ["prev", "next", "next"]   "06:55"
"07:22"	   "04:05"	"00:15"	    "04:07"     ["next"]	               "04:17"

입출력 예 설명
입출력 예 #1
    시작 위치 13분 0초에서 10초 후로 이동하면 13분 10초입니다.
    13분 10초에서 10초 전으로 이동하면 13분 0초입니다.
    따라서 "13:00"을 return 하면 됩니다.

입출력 예 #2
    시작 위치 0분 5초에서 10초 전으로 이동합니다.현재 위치가 10초 미만이기 때문에 0분 0초로 이동합니다.
    0분 0초에서 10초 후로 이동하면 0분 10초입니다.
    0분 10초에서 10초 후로 이동하면 0분 20초입니다. 0분 20초는 오프닝 구간이기 때문에 오프닝이 끝나는 위치인 6분 55초로 이동합니다.따라서 "06:55"를 return 하면 됩니다.

입출력 예 #3
    시작 위치 4분 5초는 오프닝 구간이기 때문에 오프닝이 끝나는 위치인 4분 7초로 이동합니다. 4분 7초에서 10초 후로 이동하면 4분 17초입니다.따라서 "04:17"을 return 하면 됩니다.
*/

//[PCCP 기출문제] 1번 / 동영상 재생기
//비주얼스투디오에서 확인해본바로는 정상작동이 되는거 같은데  
//사이트에서 함수부분만 넣어서 "코드실행"하면 애러가 나는데 이유를 잘 모르겠습니다.


// commands_len은 배열 commands의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
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

    //현재 pos가 op_start보다 크고 op_end보다 작을때 => 오프닝 구간일때 오프닝end위치에 일단 배치해둔다.(고정사항)
    if (tempTimeArr[0] > tempTimeArr[1] && tempTimeArr[0] < tempTimeArr[2])
        tempTimeArr[0] = tempTimeArr[2];

    //prev,next버튼조작이 들어옴에 따른 pos변화.
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

    //위의 prev,next버튼조작으로 변경된 현재 pos가 오프닝사이의 구간인지 다시 체크.
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