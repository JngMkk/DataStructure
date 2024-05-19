"""
이진 트리란?

- 모든 노드가 2개의 서브 트리를 갖는 트리
    > 서브트리는 공집할일 수 있음
    > 이진트리는 순환적으로 정의됨
    > 이진트리의 서브 트리들은 모두 이진트리여야 함
    > 노드의 개수가 n개이면 간선의 개수는 (n - 1)개
    > 높이가 h이면 h<최소> ~ (2^h - 1)개<최대>의 노드를 가짐
    > n개 노드의 이진 트리 높이 : log_2(n+1) ~ n
        . n개의 노드를 일렬로 늘어놓으면 트리의 높이가 최대인 n이 됨


- 포화 이진 트리(full binary tree)
    > 트리의 각 레벨에 노드가 꽉 차있는 이진트리
                    A

                B       C

            E      E F      G

- 완전 이진 트리(complete binary tree)
    > 높이가 h일 때 레벨 1부터 h-1까지는 노드가 모두 채워짐
    > 마지막 레벨 h에서는 노드가 순서대로 채워짐
                    A

                B       C

            E      E  F     G

         H    I  J


이진 트리의 연산
    순회
        - 트리에 속하는 모든 노드를 한 번씩 방문하는 것
        - 선형 자료구조는 순회가 단순
        - 트리는 다양한 방법이 있음
        - 전위 순회, 중위 순회, 후위 순회
"""


class TreeNode:
    """링크 표현법"""

    def __init__(self, data, left, right):
        self.data = data
        self.left = left
        self.right = right


MAX_QSIZE = 10


class CircularQueue:
    def __init__(self):
        self.front = 0
        self.rear = 0
        self.items = [None] * MAX_QSIZE

    def isEmpty(self):
        return self.front == self.rear

    def isFull(self):
        return self.front == (self.rear + 1) % MAX_QSIZE

    def clear(self):
        self.front = self.rear

    def enqueue(self, item):
        if not self.isFull():
            self.rear = (self.rear + 1) % MAX_QSIZE
            self.items[self.rear] = item

    def dequeue(self):
        if not self.isEmpty():
            self.front = (self.front + 1) % MAX_QSIZE
            return self.items[self.front]

    def peek(self):
        if not self.isEmpty():
            return self.items[(self.front + 1) % MAX_QSIZE]

    def size(self):
        return (self.rear - self.front + MAX_QSIZE) % MAX_QSIZE

    def display(self):
        out = []
        if self.front < self.rear:
            out = self.items[self.front + 1 : self.rear + 1]  # noqa
        else:
            out = self.items[self.front + 1 : MAX_QSIZE] + self.items[0 : self.rear + 1]  # noqa
        print("[f=%s,r=%d] ==> " % (self.front, self.rear), out)


class TreeAlgorithm:
    @classmethod
    def preorder(cls, node: TreeNode):
        """
        전위 순회(preorder traversal) : VLR (루트 -> 왼쪽 서브트리 -> 오른쪽 서브트리)

        ex) 노드의 레벨 계산, 구조화된 문서 출력
        """

        if node is not None:
            print(node.data, end=" ")
            cls.preorder(node.left)  # 왼쪽 서브트리
            cls.preorder(node.right)  # 오른쪽 서브트리

    @classmethod
    def inorder(cls, node: TreeNode):
        """
        중위 순회(inorder traversal) : LVR (왼쪽 서브트리 -> 루트 -> 오른쪽 서브트리)

        ex) 정렬
        """

        if node is not None:
            cls.inorder(node.left)
            print(node.data, end=" ")
            cls.inorder(node.right)

    @classmethod
    def postorder(cls, node: TreeNode):
        """
        후위 순회(postorder traversal) : LRV (왼쪽 서브트리 -> 오른쪽 서브트리 -> 루트)

        ex) 폴더 용량 계산
        """

        if node is not None:
            cls.postorder(node.left)
            cls.postorder(node.right)
            print(node.data, end=" ")

    @staticmethod
    def levelorder(node: TreeNode):
        """
        레벨 순회(levelorder traversal) : 루트부터 레벨 순으로 노드를 방문

        큐를 사용해 구현. 순환을 사용하지 않음.
        """

        queue = CircularQueue()  # 큐 객체 초기화
        queue.enqueue(node)  # 최초에 큐에는 루트 노드만 들어있음
        while not queue.isEmpty():  # 큐가 공백상태가 아닌 동안
            _node = queue.dequeue()  # 큐에서 맨 앞의 노드 n을 꺼냄
            if _node is not None:
                print(_node.data, end=" ")  # 먼저 노드 정보를 출력
                queue.enqueue(_node.left)  # n의 왼쪽 자식 노드를 큐에 삽입
                queue.enqueue(_node.right)  # n의 오른쪽 자식 노드를 큐에 삽입

    @classmethod
    def count_node(cls, node: TreeNode):
        """
        노드 개수
        """

        if node is None:  # n이 None이면 공백 트리 -> 0 반환
            return 0
        else:
            return (
                1 + cls.count_node(node.left) + cls.count_node(node.right)
            )  # 순환 이용. 좌우 서브트리의 노드수의 합+1을 반환 (루트까지)

    @classmethod
    def count_leaf(cls, node: TreeNode):
        if node is None:
            return 0
        elif node.left is None and node.right is None:  # 단말노드 -> 1 반환
            return 1
        else:  # 비단말 노드 : 좌우 서브트리의 결과 합을 반환
            return cls.count_leaf(node.left) + cls.count_leaf(node.right)

    @classmethod
    def calc_height(cls, node: TreeNode):
        if node is None:
            return 0
        hLeft = cls.calc_height(node.left)  # 왼쪽 트리의 높이
        hRight = cls.calc_height(node.right)  # 오른쪽 트리의 높이
        if hLeft > hRight:  # 더 높은 높이에 1을 더해 반환 (루트까지)
            return hLeft + 1
        else:
            return hRight + 1


# 테스트
d = TreeNode("D", None, None)
e = TreeNode("E", None, None)
b = TreeNode("B", d, e)
f = TreeNode("F", None, None)
c = TreeNode("C", f, None)
root = TreeNode("A", b, c)

print("In-order : ", end="")
TreeAlgorithm.inorder(root)
print("\n Pre-order : ", end="")
TreeAlgorithm.preorder(root)
print("\n Post-order : ", end="")
TreeAlgorithm.postorder(root)
print("\n Level-order : ", end="")
TreeAlgorithm.levelorder(root)
print()
print(" 노드의 개수 : %d개" % TreeAlgorithm.count_node(root))
print(" 단말의 개수 : %d개" % TreeAlgorithm.count_leaf(root))
print(" 트리의 높이 : %d" % TreeAlgorithm.calc_height(root))
