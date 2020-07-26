学习笔记

泛型递归、树的递归
树的面试题解法一般都是 递归

节点的定义
重复（自相似）性
示例代码

def preorder(self, root):
    if root:
        self.traverse_path.append(root.val)
        self.preorder(root.left)
        self.preorder(root.right)

def inorder(self, root):
    if root:
        self.inorder(root.left)
        self.traverse_path.append(root.val)
        self.inorder(root.right)

def postorder(self, root):
    if root:
        self.postorder(root.left)
        self.postorder(root.right)
        self.traverse_path.append(root.val)
递归（Recursion）
递归 - 循环

通过函数体来进行的循环

例如：计算 n!

n!= 1 * 2 * 3 * ... * n

def Factorial(n):
    if n <= 1:
        return 1
    return n * Factorial(n — 1)
Python 代码模版

def recursion(level, param1, param2, ...):
     # recursion terminator
     if level > MAX_LEVEL:
       process_result
       return
     # process logic in current level
     process(level, data...)
     # drill down
     self.recursion(level + 1, p1, ...)
     # reverse the current level status if needed

	 
分治、回溯
模板

def divide_conquer(problem, param1, param2, ...):
  # recursion terminator
  if problem is None:
    print_result
    return
  # prepare data
  data = prepare_data(problem)
  subproblems = split_problem(problem, data)
  # conquer subproblems
  subresult1 = self.divide_conquer(subproblems[0], p1, ...)
  subresult2 = self.divide_conquer(subproblems[1], p1, ...)
  subresult3 = self.divide_conquer(subproblems[2], p1, ...)
  ...
  # process and generate the final result
  result = process_result(subresult1, subresult2, subresult3, ...)
  # revert the current level states