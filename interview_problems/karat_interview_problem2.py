def findNodesWithZeroAndOneParents(parentChildPairs):
    adj_list = {}
    zero_parents = []
    one_parent = []
    all_nodes = set()
    for node in parentChildPairs:
        if node[1] not in adj_list:
            adj_list[node[1]] = []
        adj_list[node[1]].append(node[0])
        all_nodes.add(node[0])
        all_nodes.add(node[1])
    for child, parent in adj_list.items():
        if len(parent) == 1:
            one_parent.append(child)
    return [list(all_nodes - set(list(adj_list.keys()))), one_parent]


if __name__ == "__main__":
	parent_child_pairs_1 = [
	    (1, 3), (2, 3), (3, 6), (5, 6), (5, 7), (4, 5),
	    (4, 8), (4, 9), (9, 11), (14, 4), (13, 12), (12, 9),
	    (15, 13)
	]
	
	parent_child_pairs_2 = [
	    (1, 3), (11, 10), (11, 12), (2, 3), (10, 2), 
	    (10, 5), (3, 4), (5, 6), (5, 7), (7, 8)
	]
	print(findNodesWithZeroAndOneParents(parent_child_pairs_1))
	print(findNodesWithZeroAndOneParents(parent_child_pairs_2))
