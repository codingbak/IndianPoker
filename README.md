## IndianPoker

c++, tcp/ip 교육을 위한 indian Poker 게임 

# 개발 목적
회사에서 필요한 c++, tcp/ip능력을 키우기 위한 간단한 포커 프로젝트 진행
# 요구 사항 
* plyaer 2명과 host 1명이 진행
* 카드는 플레이어당 1팩만 사용한다 ( 1 ~ 10)
* 인디언 포커 룰을 따른다
* 베팅은 5,000,000으로 기본베팅은 100,000으로 표현한다.
* 턴제로 진행된다
* tcp/ip 교육을 받은 후 네트워크 통신을 활용한 멀티 가능 게임을 만든다.
# 게임 룰
* 플레이어 2명은 기본 베팅을 후 게임을 시작한다.
* 플레이어 2명은 카드를 각각 받는다.
* 플레이어는 상대방의 카드만 볼 수 있으며, 자신의 카드는 볼 수 없다.
* 베팅을 시작한다. 베팅 도중 call을 하면 베팅이 종료 후 카드를 확인한다.
* 높은 숫자의 카드를 가진 플레이어가 베팅 금액을 얻을 수 있다.
* 10을 가진 플레이어가 포기하면 패널티를 얻게 된다.
* 플레이어 자산이 기본 베팅 금액 보다 적어지면 게임을 종료한다.

# 미완성 부분
* 플레이어 콜, 레이스, 다이 관련 UI 개선
* 숫자 가독성을 위한 콤마 삽입
* 코드 리팩토링을 통한 모듈화
* 한명의 플레이어가 올인 후 무승부가 나왔을 경우의 로직

# 느낀점 & 부족한 점
* 호기롭게 클린코드를 외치며 시작했지만 모듈화 관련된 부분은 부족한 점이 많다고 생각한다.
* 딜러와 보드에서의 수행하는 역할들을 분리하고 싶었지만 많이 미흡했다.
* 변수명과 코드를 클린하게 짜보니까 다시 코드를 보고싶은 욕구가 샘솟는다.
* 프로젝트를 부족한 c++ 능력을 키웠다.
* 상속 개념과 템플릿 문법과 개념을 사용해보고 싶었지만 프로젝트 특성상 사용하지 못해서 아쉬웠다.


# 클래스 다이어그램
![Untitled](https://user-images.githubusercontent.com/22064581/158502780-970375c9-3d10-4a43-a665-c9d0b0dd08d6.jpg)
# 구현화면
* **openpage**
![image](https://user-images.githubusercontent.com/22064581/158515668-e2b22656-bfcd-4ea1-b167-71117914f48b.png)

* **communicationSelectPage**
![image](https://user-images.githubusercontent.com/22064581/158515693-bb3f8a34-4273-4132-ba3f-ef7caaa46aea.png)

* **namePage**
![image](https://user-images.githubusercontent.com/22064581/158515763-080836e1-cd56-4dc5-9792-227dcf1a6ab1.png)

* **gameStartPage**
![image](https://user-images.githubusercontent.com/22064581/158515799-d7ceb917-c6da-4ff7-a716-e19e8d1c4c5b.png)
leftPlayer
![image](https://user-images.githubusercontent.com/22064581/158515811-b20e2917-cb8b-4799-ade3-50e674ec73ba.png)
rightPlayer
![image](https://user-images.githubusercontent.com/22064581/158515846-c2fb49d6-2568-465a-9784-1638e71c3917.png)
setEnd

* **gameEndPage**
![image](https://user-images.githubusercontent.com/22064581/158515856-abeb23d6-d7ec-4e63-a67d-40eea2ca6431.png)

