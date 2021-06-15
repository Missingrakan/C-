#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    inline void delspace(string& s, int& n)
    {
        while(n < s.size() && s[n] == ' ')
            n++;
    }

    inline bool delnumber(string& s, int& n)
    {
        int n_start = n;
        while(n < s.size() && isdigit(s[n]))
            n++;
        if(n_start == n)
            return false;
        return true;
    }

    bool isnumber(string& s, int& n)
    {
        if(s[n] == '+' || s[n] == '-')
            n++;
        
        if(s[n] == '.')//小数点前半部分为空
        {
            ++n;
            if(!delnumber(s, n))
                return false;
        }
        else//完整的小数形式
        {
            if(!delnumber(s, n))
                return false;
            
            if(s[n] == '.')
            {
                ++n;
                delnumber(s, n);//"3."为true
            }
        }

        return true;
    }

    bool isNumber(string s) {
        int index = 0;
        delspace(s, index);
        if(index == s.size() || !isnumber(s, index))
            return false;
        
        if(index != s.size())
        {
            if(s[index] == 'e' || s[index] == 'E')
            {
                ++index;
                if(s[index] == '+' || s[index] == '-')
                    ++index;
                if(!delnumber(s, index))
                    return false;
            }
        }
        delspace(s, index);
        if(index == s.size())
            return true;
        else
            return false;
    }
};



/*
class Solution {
public:
    int integer(string& s, int n)
    {
        while(s[n] != '\0')
        {
            if(!isdigit(s[n]))
                break;
            
            n++;
        }

        return n;
    }

    int integerorDecimal(string& s, int n)
    {
        int n_start = n;
        n = integer(s, n);
        int n_end  = n;

        if(s[n] != '.')
        {
            return n_start == n_end ? -1 : n_end;
        }

        //跳过小数点
        n++;

        int n_start2 = n;
        n = integer(s, n);
        int n_end2 = n;

        //有小数点但小数点左右边都为空 ，左边空右边右值是正确的
        if(n_start == n_end && n_start2 == n_end2)
            return -1;
        return n_end2;
    }

    bool isNumber(string s) {
        int index = 0;

        //跳过开头空格
        while(s[index] == ' ')
            index++;
        
        //判断 + - 号
        if(s[index] == '+' || s[index] == '-')
            index++;
        
        //有效数值部分
        index = integerorDecimal(s, index);
        if(index == -1)
            return false;
        
        if(index < s.size())
        {
            if(s[index] == 'e' || s[index] == 'E')
            {
                index++;
                if(s[index] == '+' || s[index] == '-')
                    index++;
                int index_start = index;
                index = integer(s, index);
                if(index_start == index)
                    return false;
            }
        }

        //结尾空格
        while(index < s.size())
        {
            if(s[index] != ' ')
                return false;
            
            ++index;
        }

        return true;
    }
};
*/