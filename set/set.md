## 집합

- Set ADT

  ```
  데이터 : 같은 유형의 유일한 요소들의 모임. 원소들은 순서는 없지만 서로 비교할 수는 있어야 함
  
  연산
  - Set() : 비어 잇는 새로운 집합 만듦
  - size() : 집합의 원소 개수를 반환
  - contains(e) : 집합이 원소 e를 포함하는지 검사하고 반환
  - insert(e) : 새로운 원소 e를 삽입, 이미 e가 있다면 삽입하지 않음
  - delete(e) : 원소 e를 집합에서 꺼내고(삭제) 반환
  - equals(setB) : setB와 같은 집합인지 검사
  - union(setB) : setB와 합집합
  - intersect(setB) : setB와 교집합
  - difference(setB) : setB와 차집합
  - display() : 집합을 화면에 출력
  ```

- 특징

  - 원소의 중복을 허용하지 않음

  - 원소들 사이에 순서가 없음(선형 자료구조가 아님)

  - 다양한 방법으로 구현할 수 있음

    - 리스트, 비트 벡터, 트리, 해싱 구조 등

  - 리스트를 이용한 구현

    ```python
    class Set:
        def __init__(self):
            self.items = []
    
        def size(self):
            return len(self.items)
        def display(self, msg):
            print(msg, self.items)
        def contains(self, item):
            for i in range(len(self.items)):
                if self.items[i] == item:
                    return True
            return False
        def insert(self, item):
            if item not in self.items:
                self.items.append(item)
        def delete(self, item):
            if item in self.items:
                self.items.remove(item)
        def union(self, setB):
            setC = Set()
            setC.items = list(self.items)
            for item in setB.items:
                if item not in self.items:
                    setC.items.append(item)
            return setC
        def intersect(self, setB):
            setC = Set()
            for item in setB.items:
                if item in self.itmes:
                    setC.items.append(item)
            return setC
        def difference(self, setB):
            setC = Set()
            for item in self.items:
                if item not in setB.items:
                    setC.items.append(item)
            return setC
    ```

    
