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
		// left�� right�� 1�� ������ ���� ������ ���� for���� �������ʾ�  CurYaksuArr.size 0�� �ǰ� 
		// if (0 == CurYaksuArr.size() % 2)�Ʒ� ���ǹ��� ���� TotalSum += 1�� ���ְ� �Ǿ�  �ַ��� ����.
		// ���� for������ ���� half = CurNum / 2; �̰�꿡 ���� CurNum�� 1�϶� half�� 0�� �Ǿ� for���� ���� ����.
		// 1�� ����� 1 �� ���� 1��! Ȧ���̴� ��Ģ����  -1�� ������� �Ѵ�.
		if (CurNum == 1)
		{
			TotalSum -= 1;
			continue;
		}
		sort(CurYaksuArr.begin(), CurYaksuArr.end());
		auto unique_v = unique(CurYaksuArr.begin(), CurYaksuArr.end());
		CurYaksuArr.erase(unique_v, CurYaksuArr.end());


		//����� ���ϱ����� ���� A�� �������� ���� ������� ������ ¦���ϰ�� A�� �����ְ�
		// ���� ������� ���� Ȧ���� ��� A�� ����.
		if (0 == CurYaksuArr.size() % 2)
			TotalSum += NumberArr[j];
		else
			TotalSum -= NumberArr[j];
		CurYaksuArr.clear();
	}
	return answer = TotalSum;
}