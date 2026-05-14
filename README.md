# Gilded Rose

Gilded Rose 는 게임 "World of Warcraft"에 나오는 여관 이름입니다.  
아이템은 퀄리티 속성을 가지고 있으며, 예외 사항이 있는 아이템들이 있습니다.  
- 아이템은 [아이템 이름, 퀄리티, 유통기한]의 속성을 가집니다.  
- 아이템의 퀄리티는 0 이상이고 아이템의 퀄리티는 하루가 지날 때마다 1씩 줄어듭니다.  
- 유통 기한이 지난 아이템의 퀄리티는 2배의 속도로 떨어집니다.  
- 퀄리티는 최대값이 50입니다.  

### Aged Brie, Backstage Pass, Sulfuras 의 예외적 규칙  

- Aged Brie는 하루가 지날 때마다 퀄리티가 1씩 증가합니다.  
- 유통기한이 지나면 퀄리티가 2씩 증가합니다.  
- Backstage Pass 는 유통기한(콘서트일)이 다가올수록 퀄리티가 증가합니다.  
  유통기한이 11일 이상일 때는 1, 10일 이하일 때는 2, 5일 이하일 때는 3씩 증가하지만  
  콘서트 날이 지나면 퀄리티는 0이 됩니다.  
- Sulfuras의 퀄리티는 변화가 없습니다.  
  
---------------------------------------------------------  
## 실습 목적 :  테스트 코드 작성을 통한 legacy code 이해

### 프로젝트 구조 (C++)

```
cpp/
├── CMakeLists.txt          # CMake 빌드 설정 (Google Test 자동 다운로드)
├── include/
│   ├── Item.h              # Item 클래스 (수정 불가)
│   └── GildedRose.h        # GildedRose 클래스 헤더
├── src/
│   └── GildedRose.cpp      # updateQuality() 구현
└── test/
    └── GildedRoseTest.cpp  # Google Test 기반 테스트
```

### 빌드 및 테스트 실행

```bash
cd cpp
cmake -B build
cmake --build build
ctest --test-dir build
```

### GildedRoseTest.cpp : failed test 수정
- updateQuality() 의 test case를 추가 작성해 보세요.
- unit test 내용 : 문서상에 나타난 동작들 확인

### unit test VS golden-master test 비교
- updateQuality() Test Case 작성 완료
C:\DEV\GildedRose_05\cpp\build>ctest --output-on-failure
Test project C:/DEV/GildedRose_05/cpp/build
      Start  1: GildedRoseTest.NormalItemQualityLowerLimit
 1/11 Test  #1: GildedRoseTest.NormalItemQualityLowerLimit ...............   Passed    0.04 sec
      Start  2: GildedRoseTest.NormalItemSellInSpecOut
 2/11 Test  #2: GildedRoseTest.NormalItemSellInSpecOut ...................   Passed    0.04 sec
      Start  3: GildedRoseTest.SulfurasNoQualityDecrease_SellinSpecIn
 3/11 Test  #3: GildedRoseTest.SulfurasNoQualityDecrease_SellinSpecIn ....   Passed    0.04 sec
      Start  4: GildedRoseTest.SulfurasNoQualityDecrease_SellinSpecOut
 4/11 Test  #4: GildedRoseTest.SulfurasNoQualityDecrease_SellinSpecOut ...   Passed    0.04 sec
      Start  5: GildedRoseTest.AgedBrieQualityIncrease_SellinSpecOut
 5/11 Test  #5: GildedRoseTest.AgedBrieQualityIncrease_SellinSpecOut .....   Passed    0.04 sec
      Start  6: GildedRoseTest.AgedBrieQualityUpperLimit
 6/11 Test  #6: GildedRoseTest.AgedBrieQualityUpperLimit .................   Passed    0.03 sec
      Start  7: GildedRoseTest.BackStageOver10Days
 7/11 Test  #7: GildedRoseTest.BackStageOver10Days .......................   Passed    0.04 sec
      Start  8: GildedRoseTest.BackStageQualityAfterConcert
 8/11 Test  #8: GildedRoseTest.BackStageQualityAfterConcert ..............   Passed    0.03 sec
      Start  9: GildedRoseTest.BackStageOver50Quality
 9/11 Test  #9: GildedRoseTest.BackStageOver50Quality ....................   Passed    0.03 sec
      Start 10: GildedRoseTest.EmptyItems
10/11 Test #10: GildedRoseTest.EmptyItems ................................   Passed    0.03 sec
      Start 11: ApprovalTest.PrintTextFixture
11/11 Test #11: ApprovalTest.PrintTextFixture ............................   Passed    0.03 sec

100% tests passed, 0 tests failed out of 11

Total Test time (real) =   0.41 sec

- GildedRose 추상화 다형성 Test 결과 (10 TestCase 성공 + 1 Approval Test 성공)
C:\DEV\GildedRose_05\cpp\build>ctest --output-on-failure
Test project C:/DEV/GildedRose_05/cpp/build
      Start  1: GildedRoseTest.NormalItemQualityLowerLimit
 1/11 Test  #1: GildedRoseTest.NormalItemQualityLowerLimit ...............   Passed    0.04 sec
      Start  2: GildedRoseTest.NormalItemSellInSpecOut
 2/11 Test  #2: GildedRoseTest.NormalItemSellInSpecOut ...................   Passed    0.04 sec
      Start  3: GildedRoseTest.SulfurasNoQualityDecrease_SellinSpecIn
 3/11 Test  #3: GildedRoseTest.SulfurasNoQualityDecrease_SellinSpecIn ....   Passed    0.03 sec
      Start  4: GildedRoseTest.SulfurasNoQualityDecrease_SellinSpecOut
 4/11 Test  #4: GildedRoseTest.SulfurasNoQualityDecrease_SellinSpecOut ...   Passed    0.03 sec
      Start  5: GildedRoseTest.AgedBrieQualityIncrease_SellinSpecOut
 5/11 Test  #5: GildedRoseTest.AgedBrieQualityIncrease_SellinSpecOut .....   Passed    0.04 sec
      Start  6: GildedRoseTest.AgedBrieQualityUpperLimit
 6/11 Test  #6: GildedRoseTest.AgedBrieQualityUpperLimit .................   Passed    0.04 sec
      Start  7: GildedRoseTest.BackStageOver10Days
 7/11 Test  #7: GildedRoseTest.BackStageOver10Days .......................   Passed    0.04 sec
      Start  8: GildedRoseTest.BackStageQualityAfterConcert
 8/11 Test  #8: GildedRoseTest.BackStageQualityAfterConcert ..............   Passed    0.04 sec
      Start  9: GildedRoseTest.BackStageOver50Quality
 9/11 Test  #9: GildedRoseTest.BackStageOver50Quality ....................   Passed    0.04 sec
      Start 10: GildedRoseTest.EmptyItems
10/11 Test #10: GildedRoseTest.EmptyItems ................................   Passed    0.03 sec
      Start 11: ApprovalTest.PrintTextFixture
11/11 Test #11: ApprovalTest.PrintTextFixture ............................   Passed    0.03 sec

100% tests passed, 0 tests failed out of 11

Total Test time (real) =   0.41 sec
