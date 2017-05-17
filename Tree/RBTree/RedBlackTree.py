#!/usr/bin/env python
# -*- coding:utf-8 -*-
black = 0
red = 1


class MyString(str):
    def __gt__(self, other):
        str1 = self.__str__()
        str2 = other.__str__()
        lim = min(len(str1), len(str2))
        for index in xrange(lim):
            if str1[index] != str2[index]:
                return ord(str1[index]) - ord(str2[index]) > 0
        return len(str1) - len(str2) > 0

    def __lt__(self, other):
        return not self.__gt__(other)


class RBNode(object):
    def __init__(self, value, color=red, parent=None, left=None, right=None):
        super(RBNode, self).__init__()
        self.value = value
        self.color = color
        self.parent = parent
        self.left = left
        self.right = right


class RBtree(object):
    def __init__(self, root=None):
        super(RBtree, self).__init__()
        self.root = root

    def binary_search(self, item, node=False):
        if node is False:  # first time
            node = self.root

        if node is None:
            return node

        if item < node.vaule:
            return self.binary_search(item, node.left)
        elif item > node.value:
            return self.binary_search(item, node.right)
        else:
            return node

    def binary_search_parent(self, item, node=False, parent=False):
        if node is False:  # first time
            node = self.root
            parent = None

        if node is None:
            return node, parent

        if item < node.value:
            return self.binary_search_parent(item, node.left, node)
        elif item > node.value:
            return self.binary_search_parent(item, node.right, node)
        else:
            return node, parent

    def left_rotate(self, up, down):
        if down is not up.right or not down:
            raise ValueError("down is not up.right" + repr(up.value) + " " + repr(down.value))
        middle = down.left
        if self.root is up:
            self.root = down
        elif up is up.parent.left:
            up.parent.left = down
        else:
            up.parent.right = down
        down.parent = up.parent

        if middle:
            middle.parent = up
        up.right = middle
        up.parent = down
        down.left = up

    def right_rotate(self, up, down):
        if down is not up.left or not down:
            raise ValueError("down is not up.left" + repr(up.value) + " " + repr(down.value))
        middle = down.right
        if up is self.root:
            self.root = down
        elif up is up.parent.left:
            up.parent.left = down
        else:
            up.parent.right = down
        down.parent = up.parent

        if middle:
            middle.parent = up
        up.left = middle
        up.parent = down
        down.right = up

    def check(self, node):
        """
        node must not be root, node's color must be BLACK
        """
        if node.color == black:
            return
        if node is node.parent.left:
            sibling = node.parent.right
        else:
            sibling = node.parent.left

        if sibling and sibling.color == red:  # sibling color RED
            node.color = black
            sibling.color = black
            if node.parent is self.root:
                return
            else:
                node.parent.color = red
                return self.check(node.parent.parent)
        else:  # sibling None or black, but node is red
            if node is node.parent.left and (node.left and node.left.color == red):  # LL
                node.color = black
                node.parent.color = red
                self.right_rotate(node.parent, node)
            elif node is node.parent.left and (node.right and node.right.color == red):  # LR
                # after rotate, node become the down node, node->parent is the "node->right" after rotate
                self.left_rotate(node, node.right)
                node = node.parent  # reset node
                node.color = black
                node.parent.color = red
                self.right_rotate(node.parent, node)
            elif node is node.parent.right and (node.left and node.left.color == red):  # RL
                self.right_rotate(node, node.left)
                node = node.parent
                node.color = black
                node.parent.color = red
                self.left_rotate(node.parent, node)
            elif node is node.parent.right and (node.right and node.right.color == red):  # RR
                node.color = black
                node.parent.color = red
                self.left_rotate(node.parent, node)
            else:
                raise ValueError("node.value: " + repr(node.value))

    def insert(self, item):
        if not self.root:
            self.root = RBNode(item, black)
        else:
            node, parent = self.binary_search_parent(item)
            if node:  # already exist, no need to insert
                return
            new_node = RBNode(item, parent=parent)
            if item < parent.value:
                parent.left = new_node
            else:
                parent.right = new_node
            self.check(parent)

    def middle_traversal(self, node=False):
        if node is False:
            node = self.root
        if not node:
            return
        print(node.value)
        self.middle_traversal(node.left)
        self.middle_traversal(node.right)

    def left_traversal(self, node=False):
        if node is False:
            node = self.root
        if not node:
            return
        self.left_traversal(node.left)
        print(node.value)
        self.left_traversal(node.right)

if __name__ == "__main__":
    tree = RBtree()
    tree.insert(10)
    tree.insert(-10)
    tree.insert(17)
    tree.insert(15)
    tree.insert(20)
    tree.left_traversal()
