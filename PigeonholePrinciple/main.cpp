#include <iostream>
#include <string>
int findNumber(int n)
{
    int fr[n];
    for (int i = 0; i < n; i++)
        fr[i] = 0;

    int cur_rem = 0;
    int cur_num = 0;
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        /// each loop add digit 1
        /// 1 - 11 - 111 
        cur_num = (cur_num * 10 + 1);
        cur_rem = cur_num % n;

        std::cout << cur_num << std::endl;

        if (cur_rem == 0)
        {
            std::cout << "Solution!" << std::endl;
            std::cout << cur_num << std::endl;
            std::cout << std::endl;
            result = cur_num;
            break;
        }
        if (fr[cur_rem] != 0)
        {
            int pre_num = 1;
            int mult_10 = 10;
            for (int j=1; j < fr[cur_rem]; j++)
            {
                pre_num += mult_10;
                mult_10 *= 10;
            }
            std::cout << "cur_num is " << cur_num << std::endl;
            std::cout << "pre_num is "<< pre_num << std::endl;
            std::cout << "cur_num - pre_num = " << cur_num - pre_num << std::endl;
            std::cout << "Solution!" << std::endl;
            std::cout << cur_num - pre_num << std::endl;
            std::cout << std::endl;
            result = cur_num - pre_num;
            break;
        }
        fr[cur_rem] = i;
    }
    return result;
}


int main(int argc, char** argv)
{
    int num;
    if (argc > 0)
        num = std::stoi(argv[1]);
    else
        num = 5;
    
    int result;
    result = findNumber(num);

    return 0;
}