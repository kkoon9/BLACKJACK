# BLACKAJACK
[Toy] C++로 구현한 블랙잭 게임

## Person
- 블랙잭에 참여한 사람
- 딜러 및 플레이어들의 정보를 가지는 구조체가 선언된 헤더파일
- cardSum : 카드 합
- alive : surrender하면 거짓
- mode : stay(0), hit(1), double down(2), surrender(3), split(4)
- EleCnt : ACE를 11로 계산한 카드의 수
- black : 블랙잭이 나왔다면 참
- split : 스플릿을 했다면 참
- bust : 버스트했다면 참
- evenMoney : 이븐머니를 했다면 참
- insurance : 인슈어런스를 했다면 참
- cardNum : 뽑은 카드의 숫자를 가지는 벡터
- Kindvec : 뽑은 카드의 문양을 가지는 벡터
- strNum : 마지막에 뽑은 카드의 숫자
- cardKind : 마지막에 뽑은 카드의 문양
- cardLine1 ~ 7 : 출력할 카드들을 가지는 문자열

## Const
- 상수, Person.h에 선언
- CARD : (13), 카드 숫자, A, 2~10, J, Q, K
- KIND : (4), 카드 문양, ◆, ♥, ♠, ♣
- PLAY : (6), 플레이어 수
- dealer : 딜러의 카드 및 점수를 가지는 구조체 변수
- player : 플레이어들의 카드 및 점수를 가지는 구조체 배열
