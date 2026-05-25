#include <iostream>
#include "Homework02.h";

using namespace std;

void Homework02_Run()
{
	printf("자리수 분해해서 합치기\n");
	//0. 입력 받기 (인티져 최대 범위까지)
	int InputNumber = 0;
	int Sum = 0;
	cin >> InputNumber;

	//1. 자리수 분리와 합치기
	//입력한 숫자가 0이면 종료
	while (InputNumber)
	{
		//1-0. 숫자를 10으로 나눈 나머지를 구해서 1의 자리수를 추출
		int Digit = InputNumber % 10;
		//1-1. 1의 자리의 숫자를 총합에 더한다.
		Sum += Digit;
		//1-2. 숫자를 10으로 나눠 전체적으로 아랫자리수로 만든다 (10의 자리 -> 1의자리)
		InputNumber /= 10;
	}

	//2. 값 출력하기
	printf("모든 자리수의 합은 : [%d] 입니다!.\n\n", Sum);
}