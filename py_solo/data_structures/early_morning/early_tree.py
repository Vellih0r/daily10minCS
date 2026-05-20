from collections import deque
import time

class Node:
    def __init__(self, data: str) -> None:
        self.data = data
        self.left = None
        self.right = None

class Tree:
    
    def __init__(self):
        self.root = None

    def add(self, data):
        new_node = Node(data)

        if self.root is None: 
            self.root = new_node
            return

        q = deque([self.root])

        while q:
            node = q.popleft()
            
            if node.left is None:
                node.left = new_node
                return
            else:
                q.append(node.left)

            if node.right is None:
                node.right = new_node
                return
            else:
                q.append(node.right)


def clear():
    print("\033[H\033[J", end="")

def animate_tree(root):
    q = deque([root])
    current_level = []
    level = 0

    while q:
        next_q = deque()
        current_level = []

        while q:
            node = q.popleft()
            current_level.append(node)

            if node.left:
                next_q.append(node.left)
            if node.right:
                next_q.append(node.right)

        level += 1
        clear()
        print(f"LEVEL: {level}")
        for n in current_level:
            print(n.data, end=' ')
        print()
        
        time.sleep(2 * level)
        q = next_q

def print_tree(root, level=0, prefix="Root: "):
    if root is not None:
        print(" " * (level * 4) + prefix + root.data)
        print_tree(root.left,  level + 1, "Left : ")
        print_tree(root.right, level + 1, "Right: ")

def print_tree_sideways(node, level=0):
    if node is not None:
        print_tree_sideways(node.right, level + 1)
        print("    " * level + node.data)
        print_tree_sideways(node.left,  level + 1)

tom = Tree()
tom.add('root')
tom.add('I')
tom.add('am')
tom.add('a')
tom.add('tree')
tom.add('he')
tom.add('he')
print_tree(tom.root)
time.sleep(5)
clear()


t = Tree()

with open('lyrics.txt', 'r') as f:
    for line in f:
        t.add(line)
animate_tree(t.root)
#print_tree_sideways(t.root)
