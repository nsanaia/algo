#include <bits/stdc++.h>
#define ll long long

ll getSumTFromOneToN(ll N) {
	return (N * (N + 1)) / 2;
}
 
ll getSquaredSumFromOneToN(ll N) {
	ll res = 0;
	for (ll i = 1; i <= N; i++) {
		res += (i * i);
	}
	return res;
}

pair<ll, ll> getActualSums(const vector<int> &A) {
	ll res = 0;
	ll squaredRes = 0;
	
	for (int n : A) {
        ll num = (ll)n;
		res += num;
		squaredRes += (num * num);
	}
	
	return make_pair(res, squaredRes);
}
 
vector<int> Solution::repeatedNumber(const vector<int> &A) {
	ll N = A.size();
	ll sum = getSumTFromOneToN(N);
	ll squaredSum = getSquaredSumFromOneToN(N);
	auto sums = getActualSums(A);
	
	ll sumsDiff = sum - sums.first;
	ll squaredDiff = squaredSum - sums.second;
	
	ll b = (squaredDiff - (sumsDiff * sumsDiff)) / (2 * sumsDiff);
	ll a = b + sumsDiff;
	
	return {(int)b, (int)a};
}