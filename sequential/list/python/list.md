## 리스트란?

- 리스트는 가장 자유로운 선형 자료구조
  - 순서를 가짐
  - 항목들이 순서대로 나열되어 있고, 각 항목들은 위치를 가짐
  - Stack, Queue, Deque과 차이점 : 자료의 접근 위치
- 구현 방법
  - 배열 구조
    - 구현이 간단
    - 항목 접근이 O(1)
    - 삽입, 삭제시 오버헤드
    - 항목의 개수 제한
- 연결된 구조
  - 구현이 복잡
  - 항목 접근이 O(n)
  - 삽입, 삭제가 효율적
  - 크기가 제한되지 않음

- 파이썬의 리스트는 동적 배열로 구현됨
  - 필요한 양보다 넉넉한 크기의 메모리 사용

- 파이썬 리스트의 시간 복잡도
  - append(a) 연산 : 대부분의 경우 O(1)
    - 배열 구조에서 맨 앞에 새로운 항목을 삽입하려먼 먼저 모든 항목을 한 칸씩 뒤로 이동시켜야 함
  - insert(pos, a) 연산 : O(n)
    - 배열 구조에서 맨 앞에서 항목을 삭제하면 이후의 모든 항목들을 한 칸씩 앞으로 이동시켜야 함
  - pop(pos) 연산 : O(n)

- List ADT

  ```
  데이터 : 같은 유형의 요소들의 순서 있는 모임
  
  연산
  - List() : 비어 있는 새로운 리스트를 만듦
  - insert(pos, e) : pos 위치에 새로운 요소 e를 삽입
  - delete(pos) : pos 위치에 있는 요소를 꺼내고(삭제) 반환
  - isEmpty() : 리스트가 비어있는지 검사
  - getEntry(pos) : pos 위치에 있는 요소를 반환
  - size() : 리스트안의 요소의 개수를 반환
  - clear() : 리스트를 초기화
  - find(item) : 리스트에서 item이 있는지 찾아 인덱스를 반환
  - replace(pos, item) : pos에 있는 항목을 item으로 바꿈
  - sort() : 리스트의 항목들을 어떤 기준으로 정렬
  - merge(lst) : 다른 리스트 lst를 리스트에 추가
  - display : 리스트를 화면에 출력
  - append(e) : 리스트의 맨 뒤에 새로운 항목을 추가
  ```

- 함수 버전 리스트

  ```python
  items = []
  def insert(pos, e):
      items.insert(pos, e)	# 파이썬 리스트 클래스의 메서드 사용
  def delete(pos):
      return items.pop(pos)
  def getEntry(pos):
      """ pos번째 항목 반환 """
      return items[pos]
  def isEmpty():
      return len(items) == 0
  def size():
      return len(items)
  def clear():
      global items
      items = []
  def find(item):
      return items.index(item)
  def replace(pos, item):
      """ pos번째 항목 변경 """
      items[pos] = item
  def sort():
      items.sort()
  def merge(lst):
      items.extend(lst)
  def display(msg = 'ArrayList :'):
      print(msg, size(), items)
  ```

- 클래스 버전 리스트

  ```python
  class ArrayList:
      def __init__(self):
          self.items = []
      
      def isEmpty(self):
          return len(self.items) == 0
      def size(self):
      	return len(self.items)
      def clear(self):
      	self.items = []
      def getEntry(self, pos):
          return self.items[pos]
      def insert(self, pos, e):
          self.items.insert(pos, e)
      def delete(self, pos):
          return self.items.pop(pos)
      def find(self, item):
          return self.items.index(item)
      def replace(self, pos, item):
          self.items[pos] = item
      def sort(self):
          self.items.sort()
      def merge(self, lst):
          self.items.extend(lst)
      def display(self, msg = 'ArrayList :'):
          print(msg, '항목 수 =', self.size(), self.items)
  ```

---

## 리스트의 응용 : 라인 편집기

![image](https://user-images.githubusercontent.com/87686562/148979537-78d059ce-5ac9-4894-a0e4-af662c352d7f.png)

- i : 라인 삽입. 행 번호와 문자열을 입력하면 그 행에 한 라인 추가

- d : 한 라인 삭제. 행 번호를 입력하면 그 행을 삭제

- r : 한 라인 변경. 행 번호와 문자열을 입력하면 그 행의 내용을 변경

- p : 현재 내용 출력. 현재 문서의 모든 내용을 라인 번호와 함께 출력

- l : 파일 입력. 지정된 파일로부터 라인을 읽어 들임

- s : 파일 출력. 지정된 파일로 편집 내용을 저장

  ```python
  from ArrayList import ArrayList
  
  def myLineEditor():
      list = ArrayList()
      while True:
          command = input('[메뉴선택] i-입력, d-삭제, r-변경, p-출력, l-파일읽기, s-저장, q-종료 : ')
          if command == 'i':
              pos = int(input('입력행 번호 : '))
              tmp = input('입력행 내용 : ')
              lst.insert(pos, tmp)
          elif command == 'd':
              pos = int(input('삭제행 번호 : '))
              lst.delete(pos)
          elif command == 'r':
              pos = int(input('변경행 번호 : '))
              tmp = input('변경행 내용 : ')
              lst.replace(pos, tmp)
          elif command == 'p':
              print('Line Editor')
              for line in range(lst.size()):
                  print('[%2d]' % line, end = '')
                  print(lst.getEntry(line))
              print()
          elif command == 'l':
              filename = input('읽을 파일명 : ')
              try:
                  infile = open(filename, 'r')
                  lines = infile.readlines()
                  for line in lines:
                      lst.insert(lst.size(), line.rstrip('\n'))
                  infile.close()
              except FileNotFoundError as e:
                  print(e)
                  continue
          elif command == 's':
              filename = input('저장할 파일명 : ')
              outfile = open(filename, 'w')
              for i in range(lst.size()):
                  outfile.write(lst.getEntry(i) + '\n')
              outfile.close()
          elif command == 'q':
              return
          else:
              continue
  ```

