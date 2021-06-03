class Solution:
    #Function to find the maximum number of meetings that can
    #be performed in a meeting room.
    def maximumMeetings(self,n,start,end):
        # code here
        meets = [(i, j) for (i, j) in zip(start, end)]
        meets.sort(key = lambda x: x[1])
        
        max_meets = 0
        
        prev_meet = (0,0)
        
        for meet in meets:
            if meet[0] > prev_meet[1]:
                max_meets += 1
                prev_meet = meet
        
        return max_meets
        
#{ 
#  Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n = int(input())
        start = list(map(int,input().strip().split()))
        end = list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.maximumMeetings(n,start,end))
# } Driver Code Ends
