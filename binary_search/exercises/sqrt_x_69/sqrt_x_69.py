class Solution:
    def mySqrt(self, x: int) -> int:
        guess = 1

        while (guess * guess) <= x:
            guess *= 2

        while (guess * guess) > x:
            guess -= 1

        return guess

if __name__ == "__main__":
    sol = Solution()
    test_values = [4, 16, 25, 37]

    for x in test_values:
        result = sol.mySqrt(x)
        print(f"The integer square root of {x} is {result}")
