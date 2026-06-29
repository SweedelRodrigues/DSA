class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        // Total gas available in all stations
        int totGas = 0;

        // Total cost required to travel all stations
        int totCost = 0;

        // Possible starting station
        int start = 0;

        // Current gas in tank while traversing
        int currGas = 0;

        for (int i = 0; i < gas.size(); i++) {

            // Calculate total gas
            totGas += gas[i];

            // Calculate total cost
            totCost += cost[i];

            // Update current gas
            currGas += (gas[i] - cost[i]);

            // If current gas becomes negative,
            // we cannot start from 'start'
            if (currGas < 0) {

                // Next station becomes new starting point
                start = i + 1;

                // Reset current gas
                currGas = 0;
            }
        }

        // If total gas is less than total cost,
        // completing the circuit is impossible
        if (totGas < totCost)
            return -1;

        return start;
    }
};