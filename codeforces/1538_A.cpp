#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

void file_io()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
int find_min_steps(vector<int>& arr, map<pair<int, int>, int>& memo, int start, int end, int curr_achievements) {
	int n = arr.size();
	if (curr_achievements == 2 || (start >= n && end < 0)) {
		return 0;
	}
	pair<int, int> curr_pair = make_pair(start, end);
	if (memo.find(curr_pair) != memo.end()) {
		return memo.find(curr_pair)->second;
	}
	int min_ele = *min_element(arr.begin(), arr.end());
	int max_ele = *max_element(arr.begin(), arr.end());
	memo[curr_pair] = 1 + min(find_min_steps(arr, memo, start+1, end, arr[start] == min_ele || arr[start] == max_ele ? curr_achievements + 1 : curr_achievements), find_min_steps(arr, memo, start, end-1, arr[end] == min_ele || arr[end] == max_ele ? curr_achievements + 1 : curr_achievements));
	return memo[curr_pair];
}

int main()
{
    file_io();
    int t;
    cin >> t;
    while (t > 0) {
    	int n;
    	cin >> n;
    	vector<int> arr(n, 0);
    	for (int i=0;i<n;i++) {
    		int temp;
    		cin >> temp;
    		arr[i] = temp;
    	}
    	map<pair<int, int>, int> memo;
    	cout << find_min_steps(arr, memo, 0, n-1, 0) << endl;
    	t--;
    }
	return 0;
}