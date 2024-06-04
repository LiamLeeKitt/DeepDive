// All necessary imports
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

void basicLoop(int a[]) {
    int sum = 0;
    // Replaced the loop with an auto loop
    //int alen = 10;
    //for(int i = 0; i < alen; i++) {
    //        sum += a[i];
    //}
    for(auto i: a) {
            sum += i;
    }
    std::cout << sum << std::endl;
    std::cout << "\n";
}

void scoreOfString(std::string &s) {
        // This is the solution to LC 3110 "Score of a String"
        int score = 0;
        for(int i = 0; i < s.size() - 1; i++) {
                score += abs(s[i] - s[i+1]);
        }
        std::cout << score << std::endl;
}

void appendCharacters(std::string s, std::string t) {
        // This is the solution to LC 2486 "Append Characters to String to Make Subsequence"
        int i = 0, j = 0;
        int len_s = s.size(), len_t = t.size();

        while(i < len_s && j < len_t) {
                if(s[i] == t[j]) {
                        j++;
                }
                i++;
        }
        std::cout << len_t - j << std::endl;
}

void longestPalindrome(std::string s) {
        // This is the solution to LC 409 "Longest Palindrome"
        //
        // Initializing a map between a letter and its frequency
        std::map<char, int> letterfreqmap;
        for(auto ch:s) { // auto for auto type deduction
               letterfreqmap[ch]++;
        }
        int resLen = 0;
        // This allows us to check if we have a single left over letter that we can put into the middle
        int oddLeft = 0;
        for(auto item:letterfreqmap) {
                if(item.second % 2 == 1) {
                        resLen += item.second - 1;
                        // Here we know it was odd number of character x so we can place one of them
                        // in the middle and just add the rest to the resLen
                        oddLeft = 1;
                }else {
                        resLen += item.second;
                }
        }
        if(oddLeft) {
                resLen++;
        }
        std::cout << resLen << std::endl;
}

int main()
{
        // Testing f1
        int a1[10] = {1,2,3,4,5,6,7,8,9,10};
        basicLoop(a1);
        // Testing f2
        std::string s1 = "hellos";
        scoreOfString(s1);
        // Testing f3
        std::string s2 = "coaching";
        std::string t2 = "coding";
        appendCharacters(s2, t2);
        // Testing f4
        std::string s3 = "abccccdd";
        longestPalindrome(s3);
        return 0;
}
