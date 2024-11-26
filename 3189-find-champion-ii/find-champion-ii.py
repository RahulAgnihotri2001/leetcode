class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        li=[i for i in range(n)]

        for ele in edges:
            if ele[1] in li:
                li.remove(ele[1])

        if len(li)==1:
            return li[0]
        else:
            return -1