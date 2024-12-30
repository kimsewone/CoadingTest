//URL : https://school.programmers.co.kr/learn/courses/30/lessons/77884#

#include <string>
#include <vector>
#include <algorithm>

int solution(int left, int right) {
	int answer = 0;

	vector<int> CurYaksuArr;
	vector<int> NumberArr;
	vector<int> SumArr;
	int temp = 0;

	left = left < 1 ? 1 : left;
	left = left > 1000 ? 1000 : left;
	right = right < 1 ? 1 : right;
	right = right > 1000 ? 1000 : right;

	int BetweenNumCnt = 0;
	temp = left;
	while (right >= temp)
	{
		temp++;
		BetweenNumCnt++;
	}


	for (int i = 0; i < BetweenNumCnt; ++i)
	{
		NumberArr.push_back(left + i);
	}

	int half = 0;

	int TotalSum = 0;
	int CurNum = 0;
	for (int j = 0; j < NumberArr.size();++j)
	{
		CurNum = NumberArr[j];
		half = CurNum / 2;
		for (int i = 1; i <= half;++i)
		{
			if (0 == CurNum % i)
			{
				temp = CurNum / i;
				CurYaksuArr.push_back(i);
				if (i != temp)
					CurYaksuArr.push_back(temp);
			}
		}
		// left나 right에 1이 들어오면 현재 로직엔 위의 for문에 들어오질않아  CurYaksuArr.size 0이 되고 
		// if (0 == CurYaksuArr.size() % 2)아래 조건문에 의해 TotalSum += 1을 해주게 되어  애러가 난다.
		// 위의 for문들어가기 직전 half = CurNum / 2; 이계산에 의해 CurNum이 1일때 half가 0이 되어 for문에 들어가지 않음.
		// 1의 약수는 1 즉 원소 1개! 홀수이니 규칙에의  -1을 더해줘야 한다.
		if (CurNum == 1)
		{
			TotalSum -= 1;
			continue;
		}
		sort(CurYaksuArr.begin(), CurYaksuArr.end());
		auto unique_v = unique(CurYaksuArr.begin(), CurYaksuArr.end());
		CurYaksuArr.erase(unique_v, CurYaksuArr.end());


		//약수를 구하기위한 숫자 A를 기준으로 구한 약수들의 갯수가 짝수일경우 A를 더해주고
		// 구한 약수들의 갯수 홀수일 경우 A를 뺀다.
		if (0 == CurYaksuArr.size() % 2)
			TotalSum += NumberArr[j];
		else
			TotalSum -= NumberArr[j];
		CurYaksuArr.clear();
	}
	return answer = TotalSum;
}