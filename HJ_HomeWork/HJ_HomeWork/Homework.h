#pragma once
#include <iostream>

// 잭팟 배율 상수
const int T7Ratio = 10'000;
const int JPTation = 50;
const int NoPrize = 0;

const int Joker = 99;

void Homework_RunAll();

/// <summary>
/// Min 부터 Max사이의 랜덤 값을 반환하는 함수
/// </summary>
/// <param name="Min">랜덤값의 최소</param>
/// <param name="Max">랜덤값의 최대</param>
/// <returns>Min 부터 Max사이의 랜덤 값</returns>
int RandomRange(int Min, int Max);

/// <summary>
/// 0 부터 Max사이의 랜덤 값을 반환하는 함수
/// </summary>
/// <param name="Max">랜덤값의 최대</param>
/// <returns>0 부터 Max사이의 랜덤 값</returns>
int RandomRange(int Max);


void Homework02_Run();


/// <summary>
/// 슬롯머신을을 시작하는(당기는) 함수
/// </summary>
/// <param name="Slots">슬롯 배열</param>
/// <param name="Length">슬롯 배열의 길이</param>
/// <param name="SlotMin">각 슬롯의 최솟값</param>
/// <param name="SlotMax">각 슬롯의 최댓값</param>
void StartSlot(int* Slots, int Length, int SlotMin, int SlotMax);

/// <summary>
/// 슬롯머신 결과에 따른 상금 비율을 정하고 반환합니다.
/// </summary>
/// <param name="Slots">슬롯 배열</param>
/// <param name="Length">슬롯 배열의길이</param>
/// <returns>일반 잭판은 JPTation, 777 잭팟은 T7Ratio, 꽝은 NoPrize를 반환합니다. </returns>
int SelectPrizeRatio(int* Slots, int Length);

/// <summary>
/// 현재 슬롯머신의 상태를 출력합니다.
/// </summary>
/// <param name="Slots">슬롯 배열</param>
/// <param name="Length">슬롯 배열의길이</param>
void PrintSlot(int* Slots, int Length);
/// <summary>
/// 축하메시지를 출력하는 함수 입니다. 상금 비율에 따라 메시지가 달라집니다.
/// </summary>
/// <param name="PrizeRatio">상금 비율</param>
void PrintCongratMsg(int PrizeRatio);
void Homework03_Run();

/// <summary>
/// 피셔 예이츠 셔플, 배열을 섞어준다
/// </summary>
/// <param name="Array">대상 배열</param>
/// <param name="Length">대상 배열의 길이</param>
void FisherYatesShuffle(int* Array, int Length);

/// <summary>
/// 딜러의 카드를 고르는 함수
/// </summary>
/// <param name="CardArray">카드 배열</param>
/// <param name="CardArrayLength">카드 배열 길이</param>
/// <param name="DealerCard">딜러의 손패 배열</param>
/// <param name="DealerCardLength">딜러의 손배 배열 길이</param>
void DealerCardSelect(int* CardArray, int CardArrayLength, int* DealerCard, int  DealerCardLength);

/// <summary>
/// 플레이어 카드를 고르는 함수
/// 입력을 받아 카드를 고른다
/// 카드를 고르면 내부적으로 삭제한데(배열의 유효범위 줄이기)
/// </summary>
/// <param name="DealerCard">딜러의 손패 배열</param>
/// <param name="DealerCardLength">딜러의 손패 배열 길이</param>
/// <returns>플레이어가 고른 카드</returns>
int PlayerCardSelect(int* DealerCard, int DealerCardLength);

/// <summary>
/// 플레이어가 고른 카드를 기반으로 결과를 계산하고
/// 플레이어가 획득한 금액을 반환한다
/// </summary>
/// <param name="PlayerSelect">플레이어가 고른 카드</param>
/// <param name="PlayerBet">플레이어의 베팅금</param>
/// <returns>플레이어가 얻은 금액</returns>
int DetermineOutCome(int PlayerSelect, int PlayerBet);

/// <summary>
/// A~K 까지의 카드중에 Card번째 카드를 출력한다.
/// </summary>
/// <param name="Card">출력할 카드</param>
void PrintCard(int Card);
void Homework04_Run();
void Homework05_Run();