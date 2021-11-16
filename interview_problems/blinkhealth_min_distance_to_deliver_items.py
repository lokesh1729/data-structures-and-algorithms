"""
delivery agent

warehouse ->

delivery agent pick n number of packages and deliver to n number of addresses

                n = 5,               addresses = [2, 1, 5, 6, 8]

                    inter_distance = [[0, 1, 2, 3, 4],
                                        [2, 0, 4, 5],
                                        []]
                        
                        greedy approach

                    DFS

most optimal route -> optimal distance and optimal time


"""


def dfs(index, visited, n, addresses, inter_distance, memo, total_addresses_covered):
    if total_addresses_covered == n:  # if we visited all the addresses, return
        return addresses[index]
    # if memo[index] != -1:  # if we already found solution at index, return it
    #     return memo[index]
    visited[index] = True
    result = float("inf")
    for curr_index, curr_distance in enumerate(
        inter_distance[index]
    ):  # visit all other vertices from current index
        if (
            curr_index != index
        ):  # for any address i to i, the distance would be zero
            result = min(
                result,
                curr_distance
                + dfs(
                    curr_index,
                    visited,
                    n,
                    addresses,
                    inter_distance,
                    memo,
                    total_addresses_covered + 1,
                ),
            )
    visited[index] = False
    return result
    # memo[index] = result
    # return memo[index]


def find_optimal_route(addresses, inter_distance):
    n = len(addresses)
    result = float("inf")
    memo = [-1 for _ in range(n)]
    for index in range(n):
        t = dfs(index, [False for _ in range(n)], n, addresses, inter_distance, memo, 1)
        result = min(
            result,
            addresses[index] + t,
        )
    return result


if __name__ == "__main__":
    # w -> l1,
    print(find_optimal_route([10, 15, 20], [[0, 35, 25], [35, 0, 30], [25, 30, 0]]))

# 10 + 35 + 30 + 20 = 75 + 20 = 95
# 10 + 25 + 30 + 15 = 65 + 15 = 80

# 15 + 35 + 25 = 75
# 15 + 30 + 25 = 70

# 20 + 30 + 35 = 85
# 20 + 25 + 35 = 80
