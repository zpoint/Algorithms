class Node(object):
    def __init__(self, value):
        super().__init__()
        self.left = None
        self.right = None
        self.parent = None
        self.value = value
        self.left_height = -1
        self.right_height = -1

class AVL(object):

    def __init__(self):
        super().__init__()
        self.root = None

    def height(self, node):
        if node == None:
            return -1
        else:
            return max(node.left_height, node.right_height) + 1

    def search_node(self, value):
        node = self.root
        while node != None:
            if value == node.value:
                return node
            elif value < node.value:
                node = node.left
            else:
                node = node.right
        return node

    def left_rotate(self, up, down):
        if down != up.right:
            return False
        elif up.parent == None:
            self.root = down
        elif up == up.parent.left:
            up.parent.left = down
        else:
            up.parent.right = down
        down.parent = up.parent
        if down.left == None:
            up.right = down.left
        else:
            up.right = down.left
            down.left.parent = up
        up.parent = down
        down.left = up
        up.left_height = self.height(up.left)
        up.right_height = self.height(up.right)
        down.left_height = self.height(down.left)
        down.right_height = self.height(down.right)

    def right_rotate(self, up, down):
        if down != up.left:
            return False
        elif up.parent == None:
            self.root = down
        elif up == up.parent.left:
            up.parent.left = down
        else:
            up.parent.right = down
        down.parent = up.parent

        if down.right == None:
            up.left = down.right
        else:
            up.left = down.right
            down.right.parent = up
        up.parent = down
        down.right = up
        up.left_height = self.height(up.left)
        up.right_height = self.height(up.right)
        down.left_height = self.height(down.left)
        down.right_height = self.height(down.right)


    def fix_upward(self, node):
        def fix_helper(node):
            if node.left_height - node.right_height > 1: # LL or LR
                if node.left.left != None: #LL
                    self.right_rotate(node, node.left)
                else: #LR
                    self.left_rotate(node.left, node.left.right)
                    self.right_rotate(node, node.left)
            elif node.right_height - node.left_height > 1: # RL or RR
                if node.right.right != None: #RR
                    self.left_rotate(node, node.right)
                else: #RL
                    self.right_rotate(node.right, node.right.left)
                    self.left_rotate(node, node.right)
            else:
                return None
            return node.parent # after rotation, node become a child
        while node != None:
            node.left_height = self.height(node.left)
            node.right_height = self.height(node.right)
            result = fix_helper(node)
            node = node.parent if result == None else result

    def insert(self, value):
        new_node = Node(value)
        parent = self.root
        node = self.root
        while node != None:
            if value == node.value:
                return(False)
            elif value < node.value:
                parent = node
                node = node.left
            else:
                parent = node
                node = node.right
        if parent == None:
            self.root = new_node
        elif value < parent.value:
            parent.left = new_node
        else:
            parent.right = new_node
        new_node.parent = parent
        self.fix_upward(parent)

    def successor(self, node):
        node = node.right
        if node == None:
            return None
        while node.left != None:
            node = node.left
        return node

    def delete(self, value):
        curr = self.search_node(value)
        if curr == None:
            return None
        if curr.parent == None:
            self.root = None
        elif curr.left == None and curr.right == None:
            if curr == curr.parent.left:
                curr.parent.left = None
            else:
                curr.parent.right = None
        elif not (curr.left != None and curr.right != None):
            if curr.left != None:
                if curr == curr.parent.left:
                    curr.parent.left = curr.left
                    curr.left.parent = curr.parent
                else:
                    curr.parent.right = curr.left
                    curr.left.parent = curr.parent
            else: ## curr.right != None
                if curr == curr.parent.left:
                    curr.parent.left = curr.right
                    curr.right.parent = curr.parent
                else:
                    curr.parent.right = curr.right
                    curr.right.parent = curr.parent
        else: # two children
            succ = self.successor(curr)
            curr.value = succ.value
            if succ.right != None:
                if succ == succ.parent.right:
                    succ.parent.right = succ.right
                else:
                    succ.parent.left = succ.right
            else:
                if succ == succ.parent.right:
                    succ.parent.right = None
                else:
                    succ.parent.left = None
            curr = succ
        self.fix_upward(curr.parent)

    def preorder_traversal(self):
        def helper(node):
            if node != None:
                helper(node.left)
                print("node_value: %d, left_height: %d, right_height: %d, height: %d" % (node.value, node.left_height, node.right_height, self.height(node)))
                helper(node.right)
        print("preorder_traversal:")
        if self.root == None:
            print("Empty Tree")
        else:
            helper(self.root)

if __name__ == "__main__":
    tree = AVL()
    tree.insert(5)
    tree.insert(10)
    tree.insert(8)
    tree.insert(13)
    tree.insert(9)
    tree.delete(10)
    tree.preorder_traversal()
