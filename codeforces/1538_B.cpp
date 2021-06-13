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
typedef unsigned long long int uint64;

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

int lower_bound(vector<int>& arr, int find, int start, int end) {
	int low = start;
	int high = end;
	while (low < high) {
		int mid = low + (high-low+1)/2;
		if (find >= arr[mid]) {
			low = mid;
		} else {
			high = mid-1;
		}
	}
	return low;
}

int upper_bound(vector<int>& arr, int find, int start, int end) {
	int low = start;
	int high = end;
	while (low < high) {
		int mid = low + (high-low)/2;
		if (find <= arr[mid]) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

int main()
{
    file_io();
    int t;
    cin >> t;
    while (t > 0) {
    	int64 n, l, r;
    	cin >> n;
    	cin >> l;
    	cin >> r;
    	vector<int> arr(n);
    	for(int i=0;i<n;i++) {
    		int temp;
    		cin >> temp;
    		arr[i] = temp;
    	}
    	sort(arr.begin(), arr.end());
    	int64 result=0;
    	for(int i=0;i<n-1;i++) {
    		int64 start = upper_bound(arr, l-arr[i], i+1, n-1);
    		int64 end = lower_bound(arr, r-arr[i], i+1, n-1);
    		// cout << "start value for i " << i << " is " << start << endl;
    		// cout << "end value for i " << i << " is " << end << endl;
    		if (arr[i] + arr[start] >= l && arr[i] + arr[end] <= r) {
    			// cout << "incrementing result for i " << i << endl;
    			result += (end-start+1);
    		}
    	}
    	cout<<result<<endl;
    	t--;
    }
	return 0;
}