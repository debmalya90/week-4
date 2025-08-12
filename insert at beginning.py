class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def insert_at_beginning(head, data):
    new_node = Node(data)
    new_node.next = head
    if head:
        head.prev = new_node
    return new_node  # New head

def print_dll(head):
    while head:
        print(head.data, end=" <-> ")
        head = head.next
    print("NULL")

# Example
head = None
head = insert_at_beginning(head, 30)
head = insert_at_beginning(head, 20)
head = insert_at_beginning(head, 10)

print("Doubly Linked List:")
print_dll(head)
