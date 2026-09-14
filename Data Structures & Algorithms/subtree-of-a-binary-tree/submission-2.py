# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        # def recur(r,sr):
            # if (r==None and sr!=None) or (r!=None and sr==None):
            #     return False
            # if r==sr==None:
            #     return True
        #     if r.val==sr.val:
        #         if (recur(r.left,sr.left) and recur(r.right, sr.right)):
        #             return True
        #     print(r.val, sr.val)
        #     print(recur(r.left,sr),recur(r.right, sr))
            # return recur(r.left,sr) or recur(r.right, sr)

        def check(r,sr):
            if (r==None and sr!=None) or (r!=None and sr==None):
                return False
            if r==sr==None:
                return True
            if r.val==sr.val:
                return check(r.left,sr.left) and check(r.right, sr.right)
            return False

        def recur(r,sr):
            if (r==None and sr!=None) or (r!=None and sr==None):
                return False
            if r==sr==None:
                return True
            if r.val==sr.val:
                if check(r,sr):
                    return True
            return recur(r.left,sr) or recur(r.right, sr)
            
        return recur(root,subRoot)