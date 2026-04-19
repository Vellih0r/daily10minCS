from collections import deque

class Tree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None
        def __repr__(self):
            return f"{self.data}"

    def __init__(self):
        self.root = None

    def add(self, data):
        new_node = self.Node(data)
        if self.root is None:
            self.root = new_node
            return self

        q = deque([self.root])
        while q:
            current = q.popleft()
            if current.left:
                q.append(current.left)
            else:
                current.left = new_node
                return self
            if current.right:
                q.append(current.right)
            else:
                current.right = new_node
                return self
        return self

    def bfs_print(self):
        if self.root is None:
            print("None")
            return
        
        q = deque([self.root])
        while q:
            current = q.popleft()
            print(f"{current.data}")
            if current.left:
                q.append(current.left)
            if current.right:
                q.append(current.right)

    def dfs_print(self, node):
        if node is None:
            return

        print(node.data)
        if node.left:
            self.dfs_print(node.left)
        if node.right:
            self.dfs_print(node.right)

if __name__ == "__main__":
    t = Tree()
    t.add(0).add(1).add(2).add(3).add(4).add(5)
    print("depth first:")
    t.dfs_print(t.root)
    print("breadth first:")
    t.bfs_print()


