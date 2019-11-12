# BLACKAJACK
[Toy] C++로 구현한 블랙잭 게임
## index

- [Person 구조체](##Person)
- [사용한 상수](##Const)
- [Print 부분](##Print)
- [Data 부분](##Data)
- [Dealer 부분](##Dealer)
- [Rule 부분](##Rule)
- [Casino 부분](##Casino)

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

## Print
1. 기본 Print 구성
- MakePrint() : 뽑은 카드를 출력하는 함수  
ex) ♠7 카드를 뽑았을 때 다음과 같이 출력된다.  
┌───  
│ ♠  
│  7  
│    
└───  

2. NormalPrint.h
- NormalEnd(int i) : 더블 다운이 아닐 때에 카드의 마지막 부분을 처리해주는 함수
- NormalPrint(Person& person) : 더블 다운이 아닌 플레이어의 패를 출력해주는 함수

3. DoubleDownPrint.h
- DoubleDownEnd(Person& person int i) : 더블 다운일 때에 마지막 카드를 처리해주는 함수
- DoubleDownPrint(Person& person) : 더블 다운인 플레이어의 패를 출력해주는 함수

4. FinallyPrint.h
- PrintDealer(Person& person) : 딜러의 패를 출력하는 함수
- PrintPlayer(int i) : i번 째 플레이어의 패를 출력하는 함수
- Print() : PrintDealer, PrintPlayer 함수를 합쳐 딜러와 모든 플레이어의 패를 출력하는 함수

## Data
- 구조체 Person 타입의 변수들의 값을 변경해주는 함수로 구성되어 있다.
1. CardKind(int i) : i의 값에 따라 ◆(0), ♥(1), ♠(2), ♣(3) 리턴해주는 함수
2. PrintCardNum(int num) : 카드 숫자(num)에 따라 문자열로 리턴해주는 함수
3. Ask(Person& person) : person의 mode값을 입력받는 함수
4. IsBlackJack(Person& person) : person의 두 카드의 합을 계산하여 블랙잭 체크하는 함수
5. IsBust(Person& person) : person의 cardSum을 계산하여 버스트 체크하는 함수

## Dealer
- DealerHidden() : 딜러의 cardSum이 21이면 참을 출력하는 함수
- DealerInit : 딜러의 홀 카드까지 보이게 출력하게 만들어주는 함수

## Rule
- 블랙잭에서의 게임 규칙을 구현한 함수
- insurance() : 인슈어런스 및 이븐머니 여부를 플레이어에게 묻는 함수
- Split(int group) : Split을 진행해주는 함수
- HitandStay(Person& person) : Hit하여 카드를 뽑는 함수
- GetScore(Person& person, int num) : 카드를 뽑은 뒤 카드 총합을 계산해주는 함수

## Casino
- Initial() : 블랙잭의 처음 부분을 수행해주는 함수

