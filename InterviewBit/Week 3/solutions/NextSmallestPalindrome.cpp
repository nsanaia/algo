string mirrorLeftToRight(string& A) {
    int N = A.size();
	int leftIdx = (N - 1) / 2;
	int rightIdx = N / 2;
	string res = A;
	
	while (leftIdx >= 0) {
		res[rightIdx++] = res[leftIdx--];
	}
	
	return res;
}

void addOneInLeftMiddle(string& A) {
    int N = A.size();
	int leftIdx = (N - 1) / 2;
	
	while (leftIdx >= 0) {
		if (A[leftIdx] == '9') {
			A[leftIdx] = '0';
		} else {
			A[leftIdx] += 1;
			return;
		}
		
		leftIdx--;
	}

    A = '1' + A;
}

string Solution::solve(string A) {
	string mirrorred = mirrorLeftToRight(A);
	if (mirrorred.compare(A) > 0)
		return mirrorred;
	
	addOneInLeftMiddle(A);
	return mirrorLeftToRight(A);
}