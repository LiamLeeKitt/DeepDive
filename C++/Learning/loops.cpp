// All necessary imports
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void basicLoop(int a[]) {
    int sum = 0;
    int alen = 10;
    for(int i = 0; i < alen; i++) {
            sum += a[i];
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
        return 0;
}
