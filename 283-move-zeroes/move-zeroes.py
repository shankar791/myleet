class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
         x1,x2=0,1
         while x2<len(nums):
            if nums[x1]==0 and (nums[x2]!= 0):
                temp=nums[x1]
                nums[x1]=nums[x2]
                nums[x2]=temp
                x1+=1
                x2+=1
            elif (nums[x1] != 0 )and nums[x2]==0:
                x1+=1
                x2+=1
            elif nums[x1]==0 and nums[x2]==0:
                x2+=1
            elif nums[x1]!=0 and nums[x2]!=0:
                x1+=2
                x2+=2           