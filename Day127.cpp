// LeetCode

// 1962. Remove Stones to Minimize the Total
class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq;
        for (int i = 0; i < piles.size(); i++)
        {
            pq.push(piles[i]);
        }
        while (k != 0)
        {
            int element = pq.top();
            pq.pop();
            int subs = element / 2;
            int ans = element - subs;
            if (ans == element)
            {
                pq.push(ans);
                break;
            }
            else
            {
                pq.push(ans);
            }
            k--;
        }
        int sum = 0;
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};

// 767. Reorganize String
class Solution
{
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> freqMap;
        for (char ch : s)
        {
            freqMap[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto &entry : freqMap)
        {
            pq.push({entry.second, entry.first});
        }

        string result;
        while (!pq.empty())
        {
            pair<int, char> first = pq.top();
            pq.pop();
            if (result.empty() || result.back() != first.second)
            {
                result.push_back(first.second);
                if (--first.first > 0)
                {
                    pq.push(first);
                }
            }
            else
            {
                if (pq.empty())
                {
                    return "";
                }
                pair<int, char> second = pq.top();
                pq.pop();
                result.push_back(second.second);
                if (--second.first > 0)
                {
                    pq.push(second);
                }
                pq.push(first);
            }
        }

        return result;
    }
};

// 1405. Longest Happy String
class Info
{
public:
    char val;
    int count;
    Info(char ch, int count)
    {
        this->val = ch;
        this->count = count;
    }
};
class compare
{
public:
    bool operator()(Info a, Info b)
    {
        return a.count < b.count;
    }
};
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<Info, vector<Info>, compare> pq;
        if (a > 0)
        {
            Info temp('a', a);
            pq.push(temp);
        }
        if (b > 0)
        {
            Info temp('b', b);
            pq.push(temp);
        }
        if (c > 0)
        {
            Info temp('c', c);
            pq.push(temp);
        }
        string ans = "";
        while (pq.size() > 1)
        {
            Info first = pq.top();
            pq.pop();
            Info second = pq.top();
            pq.pop();
            if (first.count >= 2)
            {
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count -= 2;
            }
            else
            {
                ans.push_back(first.val);
                first.count--;
            }
            if (second.count >= 2 && second.count >= first.count)
            {
                ans.push_back(second.val);
                ans.push_back(second.val);
                second.count -= 2;
            }
            else
            {
                ans.push_back(second.val);
                second.count--;
            }
            if (first.count > 0)
            {
                pq.push(first);
            }
            if (second.count > 0)
            {
                pq.push(second);
            }
        }
        if (pq.size() == 1)
        {
            Info first = pq.top();
            pq.pop();
            if (first.count >= 2)
            {
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count -= 2;
            }
            else
            {
                ans.push_back(first.val);
                first.count--;
            }
        }
        return ans;
    }
};

// 2325. Decode the Message
class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        vector<char> v(26, '0');
        int i = 0;
        for (auto ch : key)
        {
            if (i == 26)
            {
                break;
            }
            if (ch == ' ')
            {
                continue;
            }
            if (v[ch - 'a'] == '0')
            {
                v[ch - 'a'] = 'a' + i;
                i++;
            }
        }
        string str = "";
        for (auto ch : message)
        {
            if (ch == ' ')
            {
                str.push_back(' ');
            }
            else
            {
                str.push_back(v[ch - 'a']);
            }
        }
        return str;
    }
};

// 295. Find Median from Data Stream
class MedianFinder
{
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median = 0;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.size() == minHeap.size())
        {
            if (num > median)
            {
                minHeap.push(num);
                median = minHeap.top();
            }
            else
            {
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
        else if (maxHeap.size() == minHeap.size() + 1)
        {
            if (num < median)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
            else
            {
                minHeap.push(num);
            }
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else if (minHeap.size() == maxHeap.size() + 1)
        {
            if (num > median)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else
            {
                maxHeap.push(num);
            }
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }

    double findMedian()
    {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// 871. Minimum Number of Refueling Stops
class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int stops = 0;
        int distance = 0;
        int i = 0;
        int fuel = startFuel;
        priority_queue<pair<int, int>> pq;
        while (true)
        {
            while (i < stations.size())
            {
                if (stations[i][0] <= distance + fuel)
                {
                    pq.push({stations[i][1], stations[i][0]});
                }
                else
                {
                    break;
                }
                i++;
            }
            distance += fuel;
            fuel = 0;
            if (distance >= target)
            {
                break;
            }
            if (pq.empty())
            {
                stops = -1;
                break;
            }
            auto &top = pq.top();
            fuel = (distance - top.second) + top.first;
            distance = top.second;
            pq.pop();
            stops++;
        }
        return stops;
    }
};