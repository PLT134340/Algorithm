# [Gold III] Card Hand Sorting - 13356 

[문제 링크](https://www.acmicpc.net/problem/13356) 

### 성능 요약

메모리: 17296 KB, 시간: 200 ms

### 분류

브루트포스 알고리즘, 다이나믹 프로그래밍, 가장 긴 증가하는 부분 수열: O(n log n)

### 제출 일자

2024년 9월 9일 16:59:36

### 문제 설명

<p>When dealt cards in the card game Plump it is a good idea to start by sorting the cards in hand by suit and rank. The different suits should be grouped and the ranks should be sorted within each suit. But the order of the suits does not matter and within each suit, the cards may be sorted in either ascending or descending order on rank. It is allowed for some suits to be sorted in ascending order and others in descending order. </p>

<p>Sorting is done by moving one card at a time from its current position to a new position in the hand, at the start, end, or in between two adjacent cards. What is the smallest number of moves required to sort a given hand of cards?</p>

### 입력 

 <p>The first line of input contains an integer n (1 ≤ n ≤ 52), the number of cards in the hand. The second line contains n pairwise distinct space-separated cards, each represented by two characters. The first character of a card represents the rank and is either a digit from 2 to 9 or one of the letters T, J, Q, K, and A representing Ten, Jack, Queen, King and Ace, respectively, given here in increasing order. The second character of a card is from the set {s, h, d, c} representing the suits spades ♠, hearts ♥, diamonds ♦, and clubs ♣</p>

### 출력 

 <p>Output the minimum number of card moves required to sort the hand as described above.</p>

