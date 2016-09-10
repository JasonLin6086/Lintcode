/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/word-count-map-reduce
@Language: C++
@Datetime: 16-09-10 20:13
*/

/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done(); 
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 */
class WordCountMapper: public Mapper {
public:
    void Map(Input<string>* input) {
        // Write your code here
        // Please directly use func 'output' to 
        // output the results into output buffer.
        // void output(string &key, int value);
        while (!input->done()) {
            string line = input->value();
            istringstream iss(line);
            string word;
            while ( std::getline( iss, word, ' ' ) ) {
                output(word, 1);
                //printf( "`%s'\n", word.c_str() );
            }
            input->next();
        }
    }
};


class WordCountReducer: public Reducer {
public:
    void Reduce(string &key, Input<int>* input) {
        // Write your code here
        // Please directly use func 'output' to 
        // output the results into output buffer.
        // void output(string &key, int value);
        int result = 0;
        while (!input->done()) {
            result += input->value();
            //cout<<result<<endl;
            input->next();
        }
        output(key, result);
    }
};