/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/gas-station
@Language: Java
@Datetime: 15-08-17 06:27
*/

public class Solution {
    /**
     * @param gas: an array of integers
     * @param cost: an array of integers
     * @return: an integer
     */
public int canCompleteCircuit(int[] gas, int[] cost) {
	int sumRemaining = 0; // track current remaining
	int total = 0; // track total remaining
	int start = 0; 
 
	for (int i = 0; i < gas.length; i++) {
		int remaining = gas[i] - cost[i];
 
		//if sum remaining of (i-1) >= 0, continue 
		if (sumRemaining >= 0) { 
			sumRemaining += remaining;
		//otherwise, reset start index to be current
		} else {
			sumRemaining = remaining;
			start = i;
		}
		total += remaining;
	}
 
	if (total >= 0){
		return start;
	}else{
		return -1;
	}
}
}
