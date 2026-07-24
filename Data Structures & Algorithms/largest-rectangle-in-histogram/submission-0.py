class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area = 0
        stack = []                                  # (start_index, height)

        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h:
                idx, height = stack.pop()
                max_area = max(max_area, height * (i - idx))   # i is the right boundary
                start = idx                                     # inherit the left boundary
            stack.append((start, h))

        n = len(heights)
        for idx, height in stack:                   # never blocked → reach the right edge
            max_area = max(max_area, height * (n - idx))
        return max_area