from sys import stdin
raw_input = stdin.readline
N = input()
S = {tuple(sorted(raw_input().split())) for x in xrange(N)}
print 'No two snowflakes are alike.' if len(S) == N else 'Twin snowflakes found.'
