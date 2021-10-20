"""
You have N houses and three colors (blue , red , green)
Find min cost of painting all houses so that no two adjacent houses are of same color.
Cost = [{11 , 2 , 5}, {10, 7, 8}, { 12, 9 , 11}]

Ans- 2 + 8 + 9= 19

Cost = [{10, 4 , 5},{ 12, 11 , 14,}{7, 9, 11}{5, 7 , 9 }]

Ans = 5+ 11+7+7=  30


at any house i, i only two colors

            /

T(i) = min(T(j) + weight of j, T(k) + weight of k) where j, k are two different colors

T -> function to compute the result

memoization

top down approach

bottom up approach

dp[i][0] = current weight + min() 

the cost of painiting ith building with previous different colors

"""

def min_cost_to_paint_houses(arr):
    n = len(arr)
    dp = [[0 for _ in range(3)] for _ in range(n)]
    dp[0][0] = arr[0][0]
    dp[0][1] = arr[0][1]
    dp[0][2] = arr[0][2]
    for i in range(1, n):
        dp[i][0] = arr[i][0] + min(dp[i-1][1], dp[i-1][2])
        dp[i][1] = arr[i][1] + min(dp[i-1][0], dp[i-1][2])
        dp[i][2] = arr[i][2] + min(dp[i-1][0], dp[i-1][1])
    return min(dp[n-1])

if __name__ == "__main__":
    print(min_cost_to_paint_houses(
        [(11 , 2 , 5), (10, 7, 8), (12, 9 , 11)]
    ))
    print(min_cost_to_paint_houses(
        [(10, 4 , 5),(12, 11 , 14),(7, 9, 11),(5, 7 , 9 )]
    ))
    