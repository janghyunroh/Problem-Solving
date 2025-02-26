import sys
import math
input = sys.stdin.readline

cur_time = list(map(int, input().rstrip().split(':')))
start_time = list(map(int, input().rstrip().split(':')))

cur_time = cur_time[0] * 3600 + cur_time[1] * 60 + cur_time[2]
start_time = start_time[0] * 3600 + start_time[1] * 60 + start_time[2]

time_diff = start_time - cur_time
if cur_time > start_time:
    time_diff += 86400


h = str(math.floor(time_diff / 3600))
m = str(math.floor((time_diff % 3600) / 60))
s = str(time_diff % 60)

h = h if len(h)==2 else '0'+h
m = m if len(m)==2 else '0'+m
s = s if len(s)==2 else '0'+s

print(h+':'+m+':'+s)

