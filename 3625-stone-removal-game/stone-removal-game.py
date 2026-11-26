class Solution:
    def canAliceWin(self, n: int) -> bool:
        turn = 10
        while n >= turn:
            n -= turn
            turn -= 1
            if n < turn:
                return True
            n -= turn
            turn -= 1
        return False 