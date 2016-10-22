class TrieNode(object):
    def __init__(self, end=False):
        super().__init__()
        self.children = {}
        self.end = end
        self.textfile = ""
    
    def set(self, val, node):
        self.children[val] = node

    def getnext(self, val):
        try:
            return self.children[val]
        except KeyError:
            return False

    def isin(self, val):
        return val in self.children

    def __len__(self):
        return len(self.children)

class Trie(object):
    def __init__(self):
        super().__init__()
        self.root = TrieNode()

    def insert(self, string):
        node = self.root
        for s in string:
            if node.isin(s):
                node = node.getnext(s)
            else:
                end = True if s == string[-1] else False
                new_node = TrieNode(end)
                node.set(s, new_node)
                node = new_node
        if node.end == False:
            node.end = True
        node.textfile = string

    def search(self, string):
        node = self.root
        for s in string:
            node = node.getnext(s)
            if node == False:
                return False
        return node.end

    def delete(self, string):
        "return False if string not inside Trie, True if success in deleting"
        def delete_helper(parent, depth):
            nonlocal string
            s = string[depth]
            node = parent.getnext(s)

            if depth+1 < len(string):
                delete_helper(node, depth+1)

            if len(node) == 0:
                del parent.children[s]
            elif s == string[-1]:
                node.end = False
                node.textfile = ""

        if self.search(string) == False:
            return False
        delete_helper(self.root, 0)
        return True

    def traversal(self, node=None):
        def travsesal_helper(node):
            for s in node.children:
                travsesal_helper(node.getnext(s))
            if node.end:
                print("%s\t" % (node.textfile, ), end="")
        print("traversal:\t", end="")
        if node == None:
            node = self.root
        travsesal_helper(node)
        print("")


if __name__ == "__main__":
    trie = Trie()
    trie.insert("abc")
    trie.insert("abgl")
    trie.insert("abcd")
    trie.insert("hijk")
    trie.insert("hijjk")
    trie.traversal()
    print("After delete abc, hijjk:")
    trie.delete("abc")
    trie.delete("hijjk")
    trie.traversal()
