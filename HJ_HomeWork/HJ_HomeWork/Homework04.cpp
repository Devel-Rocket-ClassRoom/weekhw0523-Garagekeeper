#include <iostream>
#include "Homework04.h";

using namespace std;

const int Joker = 99;

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
		Res = DealerCard[Index - 1];
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
		system("cls");
		//0.현재 금액 출력
		printf("\n현재금액 :[ %d ]\n", PlayerMoney);

		//1. 베팅
		do
		{
			printf("베팅금을 입력해주세요. (최소 100원부터 가능합니다)\n");
			printf("베팅금: ");
			cin >> PlayerBet;
			cin.clear();
			cin.ignore(10000, '\n');
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

		// 플레이어가 패배, 베팅금의 2배를 지불할 수 있으면
		if (PlayerEarn == 0 && PlayerMoney >= PlayerBet * 2)
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
				printf("\n베팅금의 2배인 %d를 지불하고 한번 더 고릅니다.\n", Delta);
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

		printf("엔터를 눌러서 다음 게임을 진행하세요");
		cin.clear();
		cin.ignore(10000, '\n');
		cin.get();

		// 딜러가 들 수 있는 카드의 개수 초기화
		DealerHandSize = DealerhandSizeMax;
	}

}
