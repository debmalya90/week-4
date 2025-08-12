class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def reverse_dll(head):
    temp = None
    current = head
    while current:
        temp = current.prev
        current.prev = current.next
        current.next = temp
        current = current.prev  # move to "next" in reversed list

    if temp:
        head = temp.prev
    return head

def print_dll(head):
    while head:
        print(head.data, end=" <-> ")
        head = head.next
    print("NULL")



print("Original DLL:")
print_dll(head)

head = reverse_dll(head)
print("Reversed DLL:")
print_dll(head)
