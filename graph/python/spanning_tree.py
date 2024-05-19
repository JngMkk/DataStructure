from collections import deque


# 신장트리 알고리즘
def bfsST(graph, start):
    visited = set([start])  # 맨 처음 start만 방문한 정점
    queue = deque([start])  # 컬렉션의 덱 생성(큐로 사용)
    while queue:  # 공백이 아닐 때까지
        v = queue.popleft()  # 큐에서 하나의 정점 v를 빼냄
        nbr = graph[v] - visited  # nbr = {v의 인접정점} - {방문정점}
        for u in nbr:  # 갈 수 잇는 모든 인접 정점에 대해
            print("(", v, ",", u, ")", end="")  # (v, u) 간선 추가
            visited.add(u)  # u는 방문했음.
            queue.append(u)  # u를 큐에 삽입
