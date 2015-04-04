#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class Solution
{
public:

    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int inputSize = numbers.size();

        int HASH_SIZE = 2011;
        
        element *hashTable[HASH_SIZE];
        int hashIdx;
        element *curr, *next;
        int idx2;
        int val;
        
        vector <int> result;

        for (unsigned i = 0 ; i < HASH_SIZE; i++)
            hashTable[i] = NULL;

        for (unsigned i = 0 ; i < numbers.size() ; i ++)
        {
            hashIdx = numbers[i] % HASH_SIZE;
            if (hashIdx < 0) hashIdx *= -1;
            
            curr = hashTable[hashIdx];

            if (curr == NULL)
            {
                hashTable[hashIdx] = new element(i, numbers[i]);
            }
            else
            {
                while (curr -> next)
                    curr = curr -> next;
            
                curr->next = new element(i, numbers[i]);
            }
        }
    
        for (unsigned i = 0 ; i < numbers.size() ; i ++)
        {
            val = target - numbers[i];
            hashIdx = val % HASH_SIZE;
            if (hashIdx < 0) hashIdx *= -1;
            
            curr = hashTable[hashIdx];
            idx2 = -1;

            while (curr)
            {
                if (curr->value == val && curr->orgIdx > i)
                {
                    idx2 = curr->orgIdx;
                    break;
                }

                curr = curr->next;
            }

            if (idx2 != -1)
            {
                result.push_back(i + 1);
                result.push_back(idx2 + 1);
                break;
            }
        }

        for (unsigned i = 0 ; i < HASH_SIZE ; i ++)
        {
            curr = hashTable[i];

            while (curr)
            {
                next = curr->next;
                delete curr;
                curr = next;
            }
        }

        return result;
    }

private:

    typedef struct  element
    {
        unsigned orgIdx;
        int value;
        element *next;

        element(unsigned idx, int val) : orgIdx(idx), value(val), next(NULL) {}
    } element ;

};


int main(int argc, char* argv[])
{
    vector<int> testData;
    Solution sol;
/*
    srand(time(NULL));
    for (int i = 0 ; i < 10 ; i ++)
        testData.push_back(rand() % 21 - 10);
*/

    testData.push_back(0);
    testData.push_back(4);
    testData.push_back(3);
    testData.push_back(0);

    sol.twoSum(testData, 0);
}
