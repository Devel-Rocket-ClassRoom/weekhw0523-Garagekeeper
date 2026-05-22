#include "Homework.h"

using namespace std;

void Homework_RunAll()
{
	//Homework02_Run();
	//Homework03_Run();
	Homework04_Run();
	//Homework05_Run();
}

int RandomRange(int Min, int Max)
{
	return rand() % (Max - Min + 1) + Min;
}

int RandomRange(int Max)
{
	return RandomRange(0, Max);
}

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
		Sum += Digit = 0;
		//1-2. 숫자를 10으로 나눠 전체적으로 아랫자리수로 만든다 (10의 자리 -> 1의자리)
		Digit /= 10;
	}

	//2. 값 출력하기
	printf("모든 자리수의 합은 : [%d] 입니다!.\n\n", Sum);
}

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
			return T7Ratio;	// 100000배
		}
		else
		{
			return JPTation;		// 50배
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
	if (PrizeRatio == T7Ratio)
	{
		printf("777 잭팟!\n");

	}
	else if (PrizeRatio == JPTation)
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
	printf("슬롯 머신 게임 만들기\n\n");
	//0. 초기값 설정
	const int SlotMax = 7;
	const int SlotMin = 6;
	const int MinBet = 100;
	const int InitialMoney = 10'000;
	const int SlotSize = 3;

	int Slots[SlotSize] = { 0, };
	int PrizeRatio = 0;

	int PlayerMoney = InitialMoney;
	int PlayerBet = 0;

	while (PlayerMoney > MinBet)
	{
		// 다음을 반복
		//0. 현재금액 출력
		printf("현재금액 :[ %d ]\n", PlayerMoney);

		//1. 베팅(슬롯에 돈 넣기)
		do
		{
			printf("베팅금을 입력해주세요. (최소 100원부터 가능합니다)\n");
			printf("베팅금: ");
			cin >> PlayerBet;
			//1-0. 최소 100원 베팅
		} while (PlayerBet < 100 || MinBet > PlayerBet);
		// 1-1 베팅금 차감
		PlayerMoney -= PlayerBet;
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

void FisherYatesShuffle(int* Array, int Length)
{
	//0. 배열의 마지막에서 처음 방향으로 진행
	//1. 현재 인덱스랑 자기 앞의 인덱스 (자기포함)에서 랜덤으로 골라서 swap
	//2. 다음 인덱스로 진행
	//3. 0번 인덱스까지 가면 1회 한 것.

	for (int i = Length - 1; i > 0; i--)
	{
		int Target = rand() % (i + 1);
		int Temp = Array[i];
		Array[i] = Array[Target];
		Array[Target] = Temp;
	}
}

void DealerCardSelect(int* CardArray, int CardArrayLength, int* DealerCard, int  DealerCardLength)
{
	//0. 카드 배열을 섞는다.
	FisherYatesShuffle(CardArray, CardArrayLength);

	//1. 섞인 카드 배열의 앞에서 DealerCardLength - 1개를 고른다 (중복 없음)
	for (int i = 0; i < DealerCardLength - 1; i++)
		DealerCard[i] = CardArray[i];
	//2. 마지막으로 조커 추가
	DealerCard[DealerCardLength - 1] = Joker;

	//4. 손패도 섞는다.
	FisherYatesShuffle(DealerCard, DealerCardLength);
}

int PlayerCardSelect(int* DealerCard, int DealerCardLength)
{
	int Res = -1;
	int Index = 0;
	
	do
	{
		printf("카드를 선택헤주세요, 1번부터 %d번까지 있습니다.\n", DealerCardLength);
		cin >> Index;
		Res = DealerCard[Index];
	} while (Index < 1 || Index > DealerCardLength);

	// 배열을 왼쪽으로 붙임 (중간에 -1 없애기)
	for (int i = Index - 1; i < DealerCardLength - 1; i++)
	{
		DealerCard[i] = DealerCard[i + 1];
	}

	// 고른 카드를 반환
	return Res;
}

int  DetermineOutCome(int PlayerSelect, int PlayerBet)
{
	int PlayerEarn = 0;
	if (PlayerSelect == Joker)
	{
		// 4-0 플레이어가 조커뽑음, 승리, 베팅금 2배 반환
		PlayerEarn = PlayerBet * 2;
		printf("당신의 승리!!!!\n");
		printf("베팅금의 2배인 %d를 받습니다.\n", PlayerEarn);
	}
	else
	{
		// 4-1 플레이어가 조커실패
		printf("당신의 패배\n");
	}

	return PlayerEarn;
}

void PrintCard(int Card)
{
	if (Card == 0)
		printf("A");
	if (Card == 10)
		printf("J ");
	if (Card == 11)
		printf("J ");
	if (Card == 12)
		printf("Q ");
	if (Card == 13)
		printf("K ");
	if (Card == 99)
		printf("Joker ");
	if (1 <= Card && Card <= 9)
		printf("%d ", Card);

	printf("를 뽑았습니다!\n");
}

void Homework04_Run()
{
	printf("도둑 잡기 만들기\n");
	//초기값 설정
	const int InitialMoney = 10'000;
	const int MinBet = 100;
	// 조커를 제외한 카드 수
	const int CardSize = 14;
	const int DealerhandSizeMax = 3;
	int DealerHandSize = DealerhandSizeMax;

	int PlayerBet = 0;
	int PlayerMoney = InitialMoney;
	int PlayerSelect = 0;
	int PlayerEarn = 0;

	// 딜러의 손패를 위한 배열
	int DealerCard[DealerhandSizeMax] = { 0, };
	// 카드 뽑기를 위한 배열 
	int CardArray[CardSize];
	for (int i = 0; i < CardSize; i++)
		CardArray[i] = i;

	//다음을 반복
	while (PlayerMoney > MinBet)
	{
		//0.현재 금액 출력
		printf("\n현재금액 :[ %d ]\n", PlayerMoney);

		//1. 베팅
		do
		{
			printf("베팅금을 입력해주세요. (최소 100원부터 가능합니다)\n");
			printf("베팅금: ");
			cin >> PlayerBet;
			//1-0. 최소 100원 베팅
		} while (PlayerBet < 100 || MinBet > PlayerBet);
		// 1-1 베팅금 차감
		PlayerMoney -= PlayerBet;
		printf("\n베팅 후 현재 금액:[ %d ]\n", PlayerMoney);

		//2. 딜러 카드 선택
		// 2-0 A~K까지 중복없이 2장 + 조커
		DealerCardSelect(CardArray, CardSize, DealerCard, DealerHandSize);
		
		//3.플레이어 카드선택
		PlayerSelect = PlayerCardSelect(DealerCard, DealerHandSize);
		DealerHandSize--;

		//플레이어가 뽑은 카드 출력
		PrintCard(PlayerSelect);
		PlayerEarn = DetermineOutCome(PlayerSelect, PlayerBet);

		if (PlayerEarn == 0 && PlayerMoney > MinBet)
		{
			printf("두가지 선택지가 있습니다.\n");
			printf("1.다음 게임으로. 2. 베팅금의 2배를 추가로 베팅하고 한번 더 고르기\n");
			int PlayerChoice = 0;
			cin >> PlayerChoice;

			// 4-1-1 배팅금의 2배 지불 후 다시 고르기
			if (PlayerChoice == 2)
			{
				int Delta = PlayerBet * 2;
				PlayerMoney -= Delta;
				printf("베팅금의 2배인 %d를 지불하고 한번 더 고릅니다.\n", Delta);
				printf("\n현재금액 :[ %d ]\n", PlayerMoney);
				PlayerBet += Delta;

				PlayerSelect = PlayerCardSelect(DealerCard, DealerHandSize);
				PrintCard(PlayerSelect);
				PlayerEarn = DetermineOutCome(PlayerSelect, PlayerBet);
			}
		}
		else
		{
			PlayerMoney += PlayerEarn;
		}
		
		
		// 5. 종료 판단
		if (PlayerMoney <= MinBet)
		{
			printf("소지금 100 이하는 게임에 참가할 수 없습니다\n");
			printf("게임을 종료합니다\n\n");
			break;
		}

		// 딜러가 들 수 있는 카드의 개수 초기화
		DealerHandSize = DealerhandSizeMax;
	}

}

void Homework05_Run()
{
	printf("미로게임 턴제 전투 만들기\n");
	// 0.초기값 설정
	//다음을 반복
		// 1. 격자 출력
		// 2. 이동 가능 방향 판단
		// 3. 이동 가능 방향 출력
		// 4. 플레이어 입력
		// 5. 이동
		// 6. 일정확률로 적을 만남
			// 1. 턴제전투 (다음을 반복)
				//1. 내가 먼저 때린다
				//2. 상대가 때린다.
				//각 공격에는 크리티컬 확률이 있음.
		// 7. 종료조건 확인

}
