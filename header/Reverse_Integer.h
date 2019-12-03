/*
 * Reverse_Integer.h
 *
 *  Created on: 2019年9月18日
 *      Author: 其懋
 */

#ifndef HEADER_REVERSE_INTEGER_H_
#define HEADER_REVERSE_INTEGER_H_

#include <climits>

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        do {
            res = res*10 + x%10;
        } while (x /= 10);
        return res>INT_MAX ? 0 : res;  //INT_MAX = 2^31 - 1
    }
};

int main_reverse_integer()
{
    Solution s;
    std::cout << s.reverse(123) << std::endl;
    std::cout << s.reverse(-123) << std::endl;
    std::cout << s.reverse(10100) << std::endl;
    std::cout << s.reverse(1000000003) << std::endl;

    return 0;
}


#endif /* HEADER_REVERSE_INTEGER_H_ */
