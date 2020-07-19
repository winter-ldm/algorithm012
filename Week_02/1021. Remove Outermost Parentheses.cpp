/**
 * 用count做判断将第一个和最后一个括号去掉
 * 当count为0时即是第一个和最后一个配套的括号
 * 第一对括号内的括号都是配对的，所以当匹配完中间的括号之后，count的值为0
 **/

class Solution {
public:
    string removeOuterParentheses(string S) {
        int count = 0;
        string str;
        
        for (char c : S) {
            if (c == '(') {
                if (count++) {
                    str += c;
                }
            }
            else {
                if (--count) {
                    str += c;
                }
            }
        }
        return str;
    }
};