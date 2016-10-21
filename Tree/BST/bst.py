class Tnode(object):
    def __init__(self, left = None, right = None, value = None):
        super().__init__()
        self.left = left
        self.right = right
        self.value = value


class BST(object):
    def __init__(self):
        super().__init__()
        self.root = None

    def insert(self, val):
        new_node = Tnode(value=val)
        if (self.root == None):
            self.root = new_node
        else:
            curr = self.root
            while curr != None:
                if val == curr.value:
                    raise ValueError
                elif val < curr.value:
                    if curr.left == None:
                        curr.left = new_node
                        break
                    curr = curr.left
                else:
                    if curr.right == None:
                        curr.right = new_node
                        break
                    curr = curr.right

    def search(self, val):
        if self.root == None:
            return None
        parent = None
        curr = self.root
        while curr != None:
            if val == curr.value:
                return curr, parent
            elif val < curr.value:
                parent = curr
                curr = curr.left
            else:
                parent = curr
                curr = curr.right
        return None

    def successor(self, node):
        """ node pass to successor must have right child"""
        grandparent = node
        parent = node
        node = node.right
        assert node != None
        while node != None:
            parent = node
            node = node.left
            if node != None:
                grandparent = parent
        return parent, grandparent


    def delete(self, val):
        result = self.search(val)
        if result == None:
            return None
        delnode, parent = result[0], result[1]
        ret_val = delnode.value
        if delnode.left == None and delnode.right == None:
            if delnode == parent.left:
                parent.left = None
            else:
                parent.right = None
        elif not (delnode.left != None and delnode.right != None): # one child
            if delnode.left != None:
                if delnode == parent.left:
                    parent.left = delnode.left
                else:
                    parent.right = delnode.left
            elif delnode == parent.left:  ## delnode.right == None
                parent.left = delnode.left
            else: ## delnode.right == None and delnode == parent.right
                parent.right = delnode.right
        else: ## two child
            succ, par_succ = self.successor(delnode) ## susccessor must not have left child
            delnode.value = succ.value
            if succ.right == None: ## successor have no child
                if succ == par_succ.left:
                    par_succ.left = None
                else:
                    par_succ.right = None
            else: ## successor have one right child
                if succ == par_succ.left:
                    par_succ.left = succ.right
                else:
                    par_succ.right = succ.right
        return ret_val

    def preorder_traversal(self, outnode=None):
        def helper(node):
            if node != None:
                print("%d\t" % (node.value, ), end="")
                helper(node.left)
                helper(node.right)
        print("preorder_traversal:\t", end="")
        if outnode == None:
            helper(self.root)
        else:
            helper(outnode)
        print("")

    def postorder_traversal(self, outnode=None):
        def helper(node):
            if node != None:
                helper(node.left)
                helper(node.right)
                print("%d\t" % (node.value, ), end="")
        print("postorder_traversal:\t", end="")
        if outnode == None:
            helper(self.root)
        else:
            helper(outnode)
        print("")

    def inorder_traversal(self, outnode=None):
        def helper(node):
            if node != None:
                helper(node.left)
                print("%d\t" % (node.value,), end="")
                helper(node.right)
        print("inorder_traversal:\t", end="")
        if outnode == None:
            helper(self.root)
        else:
            helper(outnode)
        print("")

    def levelorder_traversal(self, outnode=None):
        if outnode == None:
            queue = [self.root]
        else:
            queue = [outnode]
        print("levelorder_traversal:\t", end="")
        while (len(queue) != 0):
            node = queue.pop(0)
            print("%d\t" % (node.value,), end="")
            if (node.left != None):
                queue.append(node.left)
            if (node.right != None):
                queue.append(node.right)
        print("")

    def good(self):
        print(self)

    def height(self, outnode=None):
        def helper(node):
            if node == None:
                return -1
            return max(helper(node.left), helper(node.right)) + 1
        if outnode == None:
            outnode = self.root
        return helper(outnode)

    def depth(self, value):
        node = self.root
        dep = 0
        while node != None:
            if value == node.value:
                return dep
            elif value < node.value:
                node = node.left
                dep += 1
            elif value > node.value:
                node = node.right
                dep += 1
        return None

    def node_count(self, outnode=None):
        return self.height(outnode) - 1

    def isbinarytree(self, outnode=None):
        def check_node(node):
            nonlocal pre
            if node == None:
                return True
            elif pre < node.value:
                pre = node.value
                #print(pre)
                return True
            else:
                return False
        def helper(node):
            if node != None:
                if helper(node.left):
                    if check_node(node):
                        if helper(node.right):
                            return True
                return False
            return True

        pre = float("-inf")
        node = self.root if outnode == None else outnode
        return helper(node)




if __name__ == "__main__":
    BSTtree = BST()
    BSTtree.insert(5)
    BSTtree.insert(10)
    BSTtree.insert(15)
    BSTtree.insert(3)
    BSTtree.insert(2)
    BSTtree.insert(1)
    BSTtree.delete(1)
    BSTtree.delete(15)
    BSTtree.insert(1)
    BSTtree.insert(15)
    BSTtree.preorder_traversal()
    BSTtree.postorder_traversal()
    BSTtree.inorder_traversal()
    BSTtree.levelorder_traversal()
    print("BST.height(): %d\t BST.node_count(): %d\t BST.depth(15): %d BST.isbinarytree(): %d" % (BSTtree.height(), BSTtree.node_count(),BSTtree.depth(15), BSTtree.isbinarytree()))
