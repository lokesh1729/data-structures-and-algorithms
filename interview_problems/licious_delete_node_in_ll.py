# // singly linked list

# // X -> 2 -> 2 -> 2 -> 2

# 1 -> 2 -> 3 -> 4
      

# // unique ? -> not unique

# // we need to delete all the nodes equal to a value

# // O(n) and O(1) 

# // O(n)
# // O(1)

class Node:
    def __init__(self, value, next=None) -> None:
        self.next = next
        self.value = value

def delete_node_in_ll(head, value):
    prev = None
    new_head = head
    result = head
    while new_head:
        if new_head.value == value:
            if prev is None:
                result = new_head.next
            else:
                prev.next = new_head.next
        else:
            prev = new_head
        new_head = new_head.next
    return result

def print_ll(head):
    while head:
        print(head.value)
        head = head.next

if __name__ == "__main__":
    obj = Node(1, Node(1, Node(2, Node(3, Node(1, Node(4, Node(1)))))))
    new_obj = delete_node_in_ll(obj, 4)
    print_ll(new_obj)
