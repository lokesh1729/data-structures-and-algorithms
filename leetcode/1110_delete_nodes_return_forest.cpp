

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        to_delete_set = set()
        for node in to_delete:
            to_delete_set.add(node)
        result = []
        self.pre_order(result, to_delete_set, root, True)
        return result

    def pre_order(self, result, to_delete_set, node, is_root):
        if node == None:
            return None
        is_deleted = node.val in to_delete_set
        if (is_root and not is_deleted):
            result.append(node)
        node.left = self.pre_order(result, to_delete_set, node.left, is_deleted)
        node.right = self.pre_order(result, to_delete_set, node.right, is_deleted)
        return None if is_deleted else node
