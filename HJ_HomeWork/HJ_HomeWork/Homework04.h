#pragma once

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