class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insert_end(head, data):
    new_node = Node(data)

    if not head:  # Empty list
        new_node.next = new_node
        return new_node

    temp = head
    while temp.next != head:
        temp = temp.next

    temp.next = new_node
    new_node.next = head
    return head

def print_cll(head):
    if not head:
        return
    temp = head
    while True:
        print(temp.data, end=" -> ")
        temp = temp.next
        if temp == head:
            break
    print("(back to head)")

# Example
head = None
head = insert_end(head, 10)
head = insert_end(head, 20)
head = insert_end(head, 30)

print("Circular Linked List:")
print_cll(head)
