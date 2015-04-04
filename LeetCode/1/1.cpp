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
        int idx1, idx2;
        vector<int> ans;
        vector<element> number;

        for (unsigned i = 0 ; i < numbers.size() ; i ++)
        {
            number.push_back(element(i, numbers[i]));
        }

        MergeSort(number, 0, number.size());

        for (idx1 = 0 ; idx1 < int(number.size()) ; idx1 ++)
        {
            idx2 = BinarySearch(number, idx1 + 1, number.size(), target - number[idx1].content);
            if (idx2 > 0)
            {
                int result1 = number[idx1].originIdx;
                int result2 = number[idx2].originIdx;

                if (result1 < result2)
                {
                    ans.push_back(result1 + 1);
                    ans.push_back(result2 + 1);
                }
                else
                {
                    ans.push_back(result2 + 1);
                    ans.push_back(result1 + 1);
                }

                return ans;
            }
        }
    }

private:

    typedef struct element
    {
        unsigned originIdx;
        int content;

        element(){}
        element(unsigned idx, int data) : originIdx(idx), content(data) {}
    } element;

    void DebugPrint(vector<int> data)
    {
        for (unsigned i = 0 ; i < data.size() ; i ++)
            cout << data[i] << " ";
        cout << endl;
    }

    /* include start, but exclude end */
    int BinarySearch(vector<element> &data, unsigned start, unsigned end, int target)
    {
        int resultIdx = -1;
        unsigned mid;

        while(end != start)
        {
            if (end == start)
            {
                break;
            }
            else if (end == (start + 1))
            {
                if (target == data[start].content)
                    resultIdx = start;
                break;
            }

            mid = (start + end) >> 1;

            if (target == data[mid].content)
            {
                resultIdx = mid;
                break;
            }
            else if (target < data[mid].content)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        return resultIdx;
    }

    /* include start, but exclude end */
    void MergeSort(vector<element> &data, unsigned start, unsigned end)
    {
        if (end == (start + 1))
            return;

        element *tmp = new element [end - start];
        unsigned mid = (start + end) >> 1;
        unsigned idx1 = start;
        unsigned idx2 = mid;
        unsigned idx3 = 0;

        /* divide */
        MergeSort(data, start, mid);
        MergeSort(data, mid, end);

        /* merge */
        while (idx1 != mid && idx2 != end)
        {
            if (data[idx1].content <= data[idx2].content)
                tmp[idx3 ++] = data[idx1 ++];
            else
                tmp[idx3 ++] = data[idx2 ++];
        }

        if (idx1 != mid)
        {
            for ( ; idx1 < mid ; idx1 ++)
                tmp[idx3 ++] = data[idx1];

        }
        if (idx2 != end)
        {
            for ( ; idx2 < end ; idx2 ++)
                tmp[idx3 ++] = data[idx2];
        }

        /* copyback */
        idx3 = 0;
        for (unsigned i = start ; i < end ; i ++)
            data[i] = tmp[idx3 ++];

        delete [] tmp;
    }
};


int main(int argc, char* argv[])
{
    vector<int> testData;
    Solution sol;

    srand(time(NULL));
    for (int i = 0 ; i < 10 ; i ++)
        testData.push_back(rand() % 21 - 10);

    sol.twoSum(testData, 3);
}
