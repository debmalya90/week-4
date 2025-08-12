class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def delete_node(head, key):
    temp = head

    while temp and temp.data != key:
        temp = temp.next

    if not temp:
        return head  # Key not found
    if temp.prev is None:
        head = temp.next
        if head:
            head.prev = None
    else:
        temp.prev.next = temp.next

    if temp.next:
        temp.next.prev = temp.prev

    return head

def print_dll(head):
    while head:
        print(head.data, end=" <-> ")
        head = head.next
    print("NULL")


print("Original DLL:")
print_dll(head)

head = delete_node(head, 20)
print("After deleting 20:")
print_dll(head)
