/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/cosine-similarity
@Language: C++
@Datetime: 15-09-29 07:53
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        int sizeA = A.size(), sizeB = B.size();
        if (sizeA==0 || sizeB==0) return 2.0000;
        if (sizeA != sizeB) return 2.0000;
        double dot = 0.0, denom_a = 0.0, denom_b = 0.0 ;
        for(unsigned int i = 0u; i < sizeA; ++i) {
            dot += A[i] * B[i] ;
            denom_a += A[i] * A[i] ;
            denom_b += B[i] * B[i] ;
        }
        if (denom_a==0&&denom_b==0) return 2.0000;
        return dot / (sqrt(denom_a) * sqrt(denom_b)) ;
    }
};