vector<int> Solution::stepnum(int A, int B) {
	vector<int> res;
	queue<int> numbers;
	
	for (int i = 0; i < 10; i++) 
		numbers.push(i);
	
	
	while (!numbers.empty()) {
		int curr = numbers.front();
		numbers.pop();
		
		if (curr > B)
			continue;
		if (curr >= A && curr <= B)
			res.push_back(curr);
		
		if (curr == 0)
			continue;
		
		int lastDigit = curr % 10;
		
		if (lastDigit != 0)
			numbers.push(curr * 10 + lastDigit - 1);
		
		if (lastDigit != 9)
			numbers.push(curr * 10 + lastDigit + 1);
	}
	
	
		
	return res;
}