class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        l, r = 0, len(height)-1
        leftMax = rightMax = 0
        water = 0

        while l < r:
            if(height[l] < height[r]):
                if(height[l] >= leftMax):
                    leftMax = height[l]
                else:
                    water += leftMax - height[l]
            
                l += 1
            else:
                if(height[r] >= rightMax):
                    rightMax = height[r]
                else:
                    water += rightMax - height[r]
                
                r -= 1
        
        return water