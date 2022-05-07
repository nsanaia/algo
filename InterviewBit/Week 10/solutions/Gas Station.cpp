int canCompleteCircuitHelper(const vector<int> &stationRes, const vector<int> &travelCost) {
    int N = stationRes.size();
    int accGas = 0;
    int minStation = 0;
    int minGas = 0;

    for (int station = 0; station < N; station++) {
        if (accGas < minGas) {
            minStation = station;
            minGas = accGas;
        }

        accGas += stationRes[station];
        accGas -= travelCost[station];
    }


    return accGas < 0 ? -1 : minStation;
}

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
	return canCompleteCircuitHelper(A, B);
}
