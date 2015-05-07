__author__ = 'Craig'

def isPartitionable(nums):
    ret = False
    for i in range(len(nums)):
        part1 = nums[i:]
        part2 = nums[:i]
        if(sum(part1) == sum(part2)):
            for j in range(len(part1)):
                if(sum(part1[j:]) == sum(part1[:j])):
                    for k in range(len(part2)):
                         if(sum(part2[k:]) == sum(part2[:k])):
                             ret = True
    return ret



print(isPartitionable([1,2,3,3,2,1,1,2,3,3,1,2]))
print(isPartitionable([10,1,2,3,4,5,5,9,1]))
print(isPartitionable([1,1,1,1,4,3,1,1,3]))
print(isPartitionable([3,3,3,1,2,1]))
print(isPartitionable([1,1,1]))
print(isPartitionable([1,4,5,4,1,5,5]))
