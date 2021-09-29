import collections


def bfs(adj_list, source):
    result = []
    q = collections.deque()
    q.append(source)
    while q:
        curr = q.popleft()
        result.append(curr)
        for node in adj_list.get(curr, []):
            q.append(node)
    return result


def hasCommonAncestor(parentChildPairs1, node1, node2):
    adj_list = {}
    for node in parentChildPairs1:
        if node[1] not in adj_list:
            adj_list[node[1]] = []
        adj_list[node[1]].append(node[0])
#     print(adj_list)
    path1 = bfs(adj_list, node1)
    path2 = bfs(adj_list, node2)
#     print(path1)
#     print(path2)
    intersection = set(path1).intersection(set(path2))
    if len(intersection) == 1:
        if list(intersection)[0] in [node1, node2]:
            return False
    return True if intersection else False


if __name__ == "__main__":

	parentChildPairs1 = [
	    (1, 3), (2, 3), (3, 6), (5, 6), (5, 7), (4, 5),
	    (4, 8), (4, 9), (9, 11), (14, 4), (13, 12),
	    (12, 9),(15, 13)
	]
	
	parentChildPairs2 = [
	    (1, 3), (11, 10), (11, 12), (2, 3), (10, 2),
	    (10, 5), (3, 4), (5, 6), (5, 7), (7, 8),
	]
	
	print(hasCommonAncestor(parentChildPairs1, 3, 8))
	print(hasCommonAncestor(parentChildPairs1, 5, 8))
	print(hasCommonAncestor(parentChildPairs1, 6, 8))
	print(hasCommonAncestor(parentChildPairs1, 6, 9))
	print(hasCommonAncestor(parentChildPairs1, 1, 3))
	print(hasCommonAncestor(parentChildPairs1, 3, 1)) 
	print(hasCommonAncestor(parentChildPairs1, 7, 11))
	print(hasCommonAncestor(parentChildPairs1, 6, 5))
	print(hasCommonAncestor(parentChildPairs1, 5, 6))
	
	print(hasCommonAncestor(parentChildPairs2, 4, 12))
	print(hasCommonAncestor(parentChildPairs2, 1, 6))
	print(hasCommonAncestor(parentChildPairs2, 1, 12))

"""
O(n) -> time complexity where n is total number of nodes

O(n) -> space complexity
"""
