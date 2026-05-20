def hashfunc(s: str):
    hash = 0
    for c in s:
        hash += ord(c) * 31
    return hash

class Hashmap:
    class Node:
        def __init__(self, key: str, data):
            self.key = key
            self.data = data
            self.next = None
        def __repr__(self):
            return f"{self.key}:{self.data}"

    def __init__(self, size):
        if size < 1:
            raise Exception("Size must be positive")
        self.size = size
        self.buckets = []
        for _ in range(size):
            self.buckets.append(None)

    def add(self, key: str, data):
        new_node = self.Node(key, data)
        hash = hashfunc(key)
        index = hash % self.size
        
        current = self.buckets[index]
        if current is None:
            self.buckets[index] = new_node
            return

        while current.next is not None:
            current = current.next
        current.next = new_node

    def __repr__(self):
        out = ""
        out+=("Hashmap:\n")
        for i, l in enumerate(self.buckets):
            out += f"bucket[{i}]\n  "
            current = l
            while current is not None:
                out += f"{current}->"
                current = current.next
            out += "\n"
        return out

    def get(self, key):
        hash = hashfunc(key)
        index = hash % self.size

        current = self.buckets[index]
        if current is None:
            return None
        while current.next and current.key != key:
            current = current.next
        if current.key == key:
            return current

    def clear(self):
        for i in range(len(self.buckets)):
            self.buckets[i] = None

    def update(self, key: str, data):
        node = self.get(key)
        if node is not None:
            node.data = data
            return
        


if __name__ == "__main__":
    h = Hashmap(3)
    h.add("hello", 1)
    h.add("kek", 2)
    h.add("yo", 3)
    h.add("jopa", 10)
    
    print("Printing nodes")
    node = h.get("o")
    print(node)
    node = h.get("yo")
    print(node)
    h.update("yo", 9)
    node = h.get("yo")
    print(node)

    print()
    print(h)
