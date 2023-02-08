class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if not nums1 or not nums2:
            return []
        nums1 = set(nums1)
        nums2 = set(nums2)
        return list(nums1 & nums2)