#include "Homework03.h"
#include <iostream>

using namespace std;

// 잭팟 배율 상수
const int Three7Ratio = 10'000;
const int JackpotTRatio = 50;
const int NoPrize = 0;

void StartSlot(int* Slots, int Length, int SlotMin, int SlotMax)
{

	// min 부터 max 까지 랜덤 값으로 슬롯을 세팅.
	for (int i = 0; i < Length; i++)
		Slots[i] = RandomRange(SlotMin, SlotMax);
}

int SelectPrizeRatio(int* Slots, int Length)
{
	// 슬롯끼리 같은 숫자인지 체크하는 변수
	bool bSamenumber = true;
	for (int i = 0; i < Length; i++)
	{

		// 슬롯의 값이 다른 경우 종료
		if (Slots[i] != Slots[0])
		{
			bSamenumber = false;
			break;
		}
	}

	// 모든 슬롯이 다 같은 경우
	if (bSamenumber)
	{
		// 그 중에서 모든 숫자가 전부 7일때
		if (Slots[0] == 7)
		{
			return Three7Ratio;	// 100000배
		}
		else
		{
			return JackpotTRatio;		// 50배
		}
	}
	return NoPrize;
}

void PrintSlot(int* Slots, int Length)
{
	printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	//printf("┃   %d    ┃     %d     ┃   %d   ┃\n", 1, 2, 3);
	for (int i = 0; i < Length; i++)
		printf("┃   %d    ", Slots[i]);
	printf("┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
}

void PrintCongratMsg(int PrizeRatio)
{

	// 그 중에서 모든 숫자가 전부 7일때
	if (PrizeRatio == Three7Ratio)
	{
		printf("777 잭팟!\n");

	}
	else if (PrizeRatio == JackpotTRatio)
	{
		printf("축하합니다!\n");
	}
	else
	{
		printf("아쉽습니다.....!\n");
	}
}

void Homework03_Run()
{
	//0. 초기값 설정
	const int SlotMax = 9;
	const int SlotMin = 1;
	const int MinBet = 100;
	const int InitialMoney = 10'000;
	const int SlotSize = 3;

	int Slots[SlotSize] = { 0, };
	int PrizeRatio = 0;

	int PlayerMoney = InitialMoney;
	int PlayerBet = 0;

	while (PlayerMoney > MinBet)
	{
		printf("슬롯 머신 게임 만들기\n\n");

		// 다음을 반복
		//0. 현재금액 출력
		printf("현재금액 :[ %d ]\n", PlayerMoney);

		//1. 베팅(슬롯에 돈 넣기)
		do
		{
			printf("베팅금을 입력해주세요. (최소 100원부터 가능합니다. 소지금까지)\n");
			printf("베팅금: ");
			cin >> PlayerBet;
			cin.clear();
			cin.ignore(10000, '\n');
			//1-0. 최소 100원 베팅
		} while (PlayerBet < 100 || MinBet > PlayerBet || PlayerBet > PlayerMoney);
		// 1-1 베팅금 차감
		PlayerMoney -= PlayerBet;
		system("cls");
		printf("베팅 후 현재 금액:[ %d ]\n", PlayerMoney);

		//2. 결과 생성
		StartSlot(Slots, SlotSize, SlotMin, SlotMax);

		//3. 슬롯결과 출력
		PrintSlot(Slots, SlotSize);

		//4. 결과 판단
		//4-0. 같은 숫자3개 -> 50배
		//4-1. 777 10000배
		PrizeRatio = SelectPrizeRatio(Slots, SlotSize);
		//축하 메시지 출력
		PrintCongratMsg(PrizeRatio);

		//5. 금액 계산
		int PlayerEarn = PlayerBet * PrizeRatio;
		//5-1 획득금액 출력
		if (PlayerEarn != NoPrize)
			printf("%d를 획득했습니다! \n", PlayerEarn);
		//5-2 금액 정산
		PlayerMoney += PlayerEarn;

		//6. 종료 조건 확인
		if (PlayerMoney <= MinBet)
		{
			printf("소지금 100 이하는 게임에 참가할 수 없습니다\n");
			printf("게임을 종료합니다\n\n");
			break;
		}

		printf("\n\n");
	}
}