import collections


# DFS
def DFS(graph, start, visited=set()):  # 처음 호출할 때 visited 공집합
    if start not in visited:  # start가 방문하지 않은 정점이면
        visited.add(start)  # start를 방문한 노드 집합에 추가
        print(start, end=" ")  # start를 방문했다고 출력
        nbr = graph[start] - visited  # nbr : 차집합 연산 이용
        for v in nbr:  # v is an element {인접정점} - {방문정점}
            DFS(graph, v, visited)  # v에 대해 DFS를 순환적으로 호출


# BFS
def BFS(graph, start):
    visited = set([start])  # 맨 처음엔 start만 방문한 정점
    queue = collections.deque([start])  # 컬렉션의 덱 객체 생성(Queue로 사용)
    while queue:  # 공백이 아닐 때까지
        vertex = queue.popleft()  # Queue에서 하나의 정점 vertex를 빼냄
        print(vertex, end=" ")  # vertex는 방문했음을 출력
        nbr = graph[vertex] - visited  # nbr : 차집합 연산 이용
        for v in nbr:  # v is an element {인접정점} - {방문정점}
            visited.add(v)  # v는 방문했음
            queue.append(v)  # v를 Queue에 삽입


# 연결 성분 검사 알고리즘
def find_connected_component(graph):
    visited = set()  # 이미 방문한 정점 집합
    colorList = []  # 부분 그래프별 정점 리스트
    for vtx in graph:  # 그래프의 모든 정점들에 대해
        if vtx not in visited:  # 방문하지 않은 정점이 있다면
            color = dfs_cc(graph, [], vtx, visited)  # 새로운 컬러 리스트
            colorList.append(color)  # 새로운 리스트 추가
    print("그래프 연결성분 개수 = %d" % len(colorList))
    print(colorList)


def dfs_cc(graph, color, vertex, visited):
    if vertex not in visited:  # 아직 칠해지지 않은 정점에 대해
        visited.add(vertex)  # 방문했음
        color.append(vertex)  # 같은 색의 정점 리스트에 추가
        nbr = graph[vertex] - visited  # nbr : 차집합 연산 이용
        for v in nbr:  # v is an element {인접정점} - {방문정점}
            dfs_cc(graph, color, v, visited)  # 순환 호출
    return color  # 같은 색의 정점 리스트 반환


# 테스트
mygraph = {"A": set(["B", "C"]), "B": set(["A"]), "C": set(["A"]), "D": set(["E"]), "E": set(["D"])}
print("find_connected_component :")
find_connected_component(mygraph)
