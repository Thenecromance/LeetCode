// LeetCode.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <list>
#include<set>
using namespace std;


/*
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
/*
'('，')'，'{'，'}'，'['，']'
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int reverse(int x) {

	}
	bool isPalindrome(int x) {
		/*if (x < 0)
			return false;
		int re = 0;
		int pop = 0;
		int tar = x;
		while (x != 0)
		{
			re *= 10;
			pop = x % 10;
			if (re == INT_MAX / 10 && pop > 7)return false;
			re += pop;
			x /= 10;
		}
		cout << re << endl;
		if (re == tar)return true;
		return false;*/
		if (x < 0)return false;
		string str = to_string(x);
		string  s(str.rbegin(), str.rend());
		return !str.compare(s);
	}
	int romanToInt(string s) {
		map<char, int> rom;
		rom['I'] = 1;
		rom['V'] = 5;
		rom['X'] = 10;
		rom['L'] = 50;
		rom['C'] = 100;
		rom['D'] = 500;
		rom['M'] = 1000;
		int rev = 0;
		for (int i = 0; i < s.length(); i++)
		{
			rev += rom.find(s[i])->second;
			if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))
				rev -= 2;
			if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
				rev -= 20;
			if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))
				rev -= 200;
		}
		return rev;
	}
	int uniquePaths(int m, int n) {

	}
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size())
			return "";
		int alphaloc;
		for (alphaloc = 0; alphaloc < strs[0].length(); alphaloc++)
		{
			for (int j = 0; j < strs.size(); j++)
			{
				if (strs[0][alphaloc] != strs[j][alphaloc])
					return strs[0].substr(0, alphaloc);
			}
		}
		return strs[0].substr(0, alphaloc);
	}
	bool isValid(string s) {
		if (s.length() == 0)return true;
		if (s.length() % 2 != 0)return false;//初步检查
		stack<char> st;
		for (int i = 0; i < s.length(); i++)
		{
			switch (s[i])
			{
			case '(':
			case '{':
			case '[':
				st.push(s[i]);
				break;
			case ']':if (st.empty())return false;
				if (st.top() == '[')
					st.pop();
				else
					return false;
				break;
			case '}':if (st.empty())return false;
				if (st.top() == '{')
					st.pop();
				else return false;
				break;
			case ')':
				if (st.empty())return false;
				if (st.top() == '(')
					st.pop();
				else return false;
				break;
			default:
				break;
			}
		}
		if (!st.empty())return false;
		//((()))
		//(){[]}
		return true;
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *next = new ListNode(0);


		if (NULL == l1) {
			return l2;
		}

		if (NULL == l2) {
			return l1;
		}

		ListNode *result = next;

		while (NULL != l1 || NULL != l2) {

			if (NULL == l1) {
				next->next = l2;
				break;
			}
			if (NULL == l2) {
				next->next = l1;
				break;
			}
			if (l1->val > l2->val) {
				next->next = l2;
				l2 = l2->next;
			}
			else {
				next->next = l1;
				l1 = l1->next;
			}
			next = next->next;
		}

		return result->next;


	}
	int removeDuplicates(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()), nums.end());
		return nums.size();
	}
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty())return 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == val)
			{
				nums.erase(nums.begin() + i);
				i--;
			}

		}
		return nums.size();
	}
	int strStr(string haystack, string needle) {
		int nNum = 0;
		for (int i = 0; i < haystack.length(); i++)
		{
			for (nNum = 0; nNum < needle.length(); nNum++)
			{

				if (haystack[i + nNum] != needle[nNum])
				{
					nNum = 0;
					break;
				}
			}
			if (nNum == needle.length())
				return i;
		}
		if (haystack.length() == 0 && needle.length() == 0)return 0;
		return -1;
	}
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty())return 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[nums.size() - 1] < target)return nums.size();
			if (nums[i] > target)return i;
			if (nums[i] == target)return i;
		}
		return 0;
	}
	int maxSubArray(vector<int>& nums) {

	}//Need to do
	int lengthOfLastWord(string s) {
		if (s.empty())return 0;
		if (s.find_last_of(' ') == string::npos)return s.length();
		if (s.find_last_of(' ') != s.length() - 1)
			return s.length() - s.find_last_of(' ') - 1;
		if (s.find_last_of(' ') == s.length() - 1)
		{
			s.erase(s.begin() + s.find_last_of(' '));
			return lengthOfLastWord(s);
		}
	}
	vector<int> plusOne(vector<int>& digits) {
		digits[digits.size() - 1]++;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if (digits[i] > 9)
			{
				digits[i] %= 10;
				if (i == 0)
				{
					digits.insert(digits.begin(), 1);
				}
				else
				{
					digits[i - 1] += 1;
				}

			}

		}
		return digits;
	}
	string addBinary(string a, string b) {
		string res = "";
		int m = a.size() - 1, n = b.size() - 1, carry = 0;
		while (m >= 0 || n >= 0) {
			int p = m >= 0 ? a[m--] - '0' : 0;
			int q = n >= 0 ? b[n--] - '0' : 0;
			int sum = p + q + carry;
			res = to_string(sum % 2) + res;
			carry = sum / 2;
		}
		return carry == 1 ? "1" + res : res;
	}
	int mySqrt(int x) {
		return (int)sqrt(x);
	}
	int climbStairs(int n) {
		int count = 0;
		int a[10001] = { 0 };
		int i;
		a[0] = 0;
		a[1] = 1;
		a[2] = 2;
		if (n > 10000)
			return 0;
		for (i = 3; i <= n; ++i)
		{
			a[i] = a[i - 1] + a[i - 2];
		}
		return a[n];

	}
	ListNode* deleteDuplicates(ListNode* head) {
		while ((head == NULL) || (head->next == NULL))
		{
			return head;
		}
		ListNode *p = head->next, *q = head;
		while (p != NULL)
		{
			if (p->val == q->val)//相等 删除
			{
				q->next = p->next;
			}
			else//不等 后移
			{
				q = q->next;
			}
			p = p->next;
		}

		return head;

	}
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (m == 0)
		{
			nums1 = nums2;
			return;
		}

		for (int i = 0; i < n; i++)
		{
			nums1.pop_back();
		}
		for (int i = 0; i < n; i++)
		{
			if (nums2[i] < nums1[0])//最小值
			{
				nums1.insert(nums1.begin(), nums2[i]);
				m++;
			}
			else if (nums2[i] >= nums1[m - 1])
			{
				nums1.insert(nums1.end(), nums2[i]);
				m++;

			}
			else
			{
				for (int j = 0; j < m; j++)
				{

					if (nums2[i] > nums1[j] && nums2[i] <= nums1[j + 1])
					{
						nums1.insert(nums1.begin() + j + 1, nums2[i]);
						m++;
						break;
					}

				}
			}

		}
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode l3(0);
		ListNode *preNode = &l3;
		int addNumber = 0;
		ListNode *b1 = l1, *b2 = l2;
		while (b1 != NULL || b2 != NULL || addNumber > 0)//当l1和l2不为空或者addNumber>0任意一个条件成立
		{
			ListNode *node = new ListNode(0);//临时的结构体指针
			int val1 = b1 ? b1->val : 0;//如果b1不为空，val1=b1->val,否则为空
			int val2 = b2 ? b2->val : 0;//如果b2不为空，val2=b2->val,否则为空
			b1 = b1 ? b1->next : NULL;//如果b1不为空，b1指向下一个链表节点,否则为空
			b2 = b2 ? b2->next : NULL;//如果b1不为空，b1指向下一个链表节点,否则为空
			node->val = (val1 + val2 + addNumber) % 10;
			addNumber = (val1 + val2 + addNumber) / 10;
			preNode->next = node;
			preNode = node;
		}
		return l3.next;

		return preNode;

	}
	int getSum(int a, int b) {
		if (b == 0)

			return a;

		else

			return getSum(a^b, (a&b) << 1);
	}
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
		{
			return true;
		}
		if (
			(p == NULL && q != NULL) || (NULL != p && NULL == q)
			)
			return false;
		if (p->val != q->val)
		{
			return false;
		}
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
#pragma region isSymmetric
	bool Judge(TreeNode* left, TreeNode* right)
	{
		if (left == NULL && right == NULL)return true;
		if (left == NULL || right == NULL)return false;
		if (left->val != right->val)return false;
		TreeNode* pLleft = left->left;
		TreeNode* pRleft = left->right;

		TreeNode* pLright = right->left;
		TreeNode* pRright = right->right;

		return Judge(pLleft, pRright) && Judge(pLright, pRleft);
	}
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)return true;
		TreeNode* pLeft = root->left;
		TreeNode* pRight = root->right;
		if (pLeft == NULL && pRight == NULL)return true;
		if (pLeft == NULL || pRight == NULL)return false;
		return Judge(pLeft, pRight);

	}
#pragma endregion
	int maxDepth(TreeNode* root) {
		int max = 0;
		if (root != NULL)
		{
			max++;
			int max_left = maxDepth(root->left);
			int max_right = maxDepth(root->right);
			max += max_left > max_right ? max_left : max_right;
		}
		return max;
	}


	vector<vector<int>> generate(int numRows) {
		vector <vector<int>> res(numRows, vector<int>());
		for (int i = 0; i < numRows; i++) {
			res[i].resize(i + 1);
			res[i][0] = 1;
			res[i][i] = 1;
		}
		for (int i = 1; i < numRows; i++) {
			for (int j = 1; j < i; j++) {
				res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
			}

		}
		return res;
	}
	vector<int> getRow(int rowIndex) {
		vector<int> out;
		if (rowIndex < 0) return out;

		out.assign(rowIndex + 1, 0);
		for (int i = 0; i <= rowIndex; ++i) {
			if (i == 0) {
				out[0] = 1;
				continue;
			}
			for (int j = rowIndex; j >= 1; --j) {
				out[j] = out[j] + out[j - 1];
			}
		}
		return out;
	}
	int maxProfit(vector<int>& prices) {
		if (prices.empty())return 0;
		int max = 0;
		int tar = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			tar = prices[i];
			for (int j = i + 1; j < prices.size(); j++)
			{
				int cmp = prices[j] - tar;
				max = max > cmp ? max : cmp;
			}
		}
		return max;
	}
	int maxProfit2(vector<int>& prices) {
		if (prices.empty())return 0;
		int max = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] - prices[i - 1] > 0) {
				max += (prices[i] - prices[i - 1]);
			}
		}
		return max;
	}
	bool isPalindrome(string s) {
		int i = 0;
		while (s[i] != '\0')
		{
			if (!isalnum(s[i]))
			{
				s.erase(s.begin() + i);
				continue;
			}
			s[i] = tolower(s[i]);
			i++;
		}
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != s[s.length() - 1 - i])
			{
				return false;
			}
		}
		return true;
	}
	int singleNumber(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			bool sec = false;
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] == nums[j])
				{
					sec = !sec;
					nums.erase(nums.begin() + j);
				}

			}
			if (!sec)
				return nums[i];
		}
		return 0;
		/*+
		int tmp = 0, i;
		for (i = 0; i < numsSize; ++i)
		tmp ^= *(nums + i);
		return tmp;
		*/
	}
	bool hasCycle(ListNode *head) {
		ListNode *ptr1 = head;
		ListNode *ptr2 = head->next->next;
		while (ptr1 != ptr2)
		{
			if (ptr2->next == NULL || ptr2 == NULL)
				return false;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next->next;
		}
		return true;
	}
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

	}
	string convertToTitle(int n) {
		string res;
		while (n) {
			res += --n % 26 + 'A';
			n /= 26;
		}
		return string(res.rbegin(), res.rend());
	}
	int titleToNumber(string s) {
		int res = 0;
		int tmp = 1;
		for (int i = s.length(); i > 0; --i)
		{
			res += (s[i - 1] - 'A' + 1) * tmp;
			tmp *= 26;
		}
		return res;
	}
	vector<int> twoSum(vector<int>& numbers, int target) {
		int num = numbers.size();
		for (int i = 0; i < numbers.size(); i++)
		{
			if (target < numbers[i])
			{
				num = i;
				break;
			}
		}
		for (int firstIndex = 0; firstIndex < num; firstIndex++)
		{
			for (int sec = firstIndex + 1; sec < num; sec++)
			{
				if (numbers[firstIndex] + numbers[sec] == target)
				{
					return { firstIndex + 1,sec + 1 };
				}
			}
		}
	}
	int majorityElement(vector<int>& nums) {
		int res = 0, counts = 0;
		for (int x : nums) {
			if (counts == 0) {
				res = x;
				counts = 1;
			}
			else if (res == x) ++counts;
			else --counts;
		}
		return res;
	}
	int trailingZeroes(int n) {
		int count = 0;
		int ten = 0;
		for (int i = 5; i <= n; i += 5)
		{
			int tmp = i;
			while (tmp >= 5)
			{
				if (tmp % 10 == 0)
				{
					ten++;
					tmp /= 10;
				}
				else if (tmp % 5 == 0)
				{
					count++;
					tmp /= 5;
				}
				else
				{
					break;
				}
			}
		}
		return count + ten;

	}
	void reverse(vector<int>&arr, int numbegin, int end)
	{
		while (numbegin < end)
		{
			int temp =arr[numbegin];
			arr[numbegin] = arr[end];
			arr[end] = temp;
			numbegin++;
			end--;
		}
	}
	void rotate(vector<int>& nums, int k) {
		int n = nums.size() - k;
		if (nums.empty() || nums.size() == 0 || k % nums.size() == 0)
			          return;
		reverse(nums, 0, n-1);
		reverse(nums, n, nums.size()-1);
		reverse(nums, 0, nums.size()-1);

	}
	int lengthOfLongestSubstring(string s) {
		int m[256] = { 0 }, res = 0, left = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (m[s[i]] == 0 || m[s[i]] < left) {
				res = max(res, i - left + 1);
			}
			else {
				left = m[s[i]];
			}
			m[s[i]] = i + 1;
		}
		return res;
	}
	string longestPalindrome(string s)
	{
		string manaStr = "$#";
		for (int i = 0; i < s.size(); i++) //首先构造出新的字符串
		{
			manaStr += s[i];
			manaStr += '#';
		}
		vector<int> rd(manaStr.size(), 0);//用一个辅助数组来记录最大的回文串长度，注意这里记录的是新串的长度，原串的长度要减去1
		int pos = 0, mx = 0;
		int start = 0, maxLen = 0;
		for (int i = 1; i < manaStr.size(); i++)
		{
			rd[i] = i < mx ? min(rd[2 * pos - i], mx - i) : 1;
			while (i + rd[i] < manaStr.size() && i - rd[i]>0 && manaStr[i + rd[i]] == manaStr[i - rd[i]])//这里要注意数组越界的判断，源代码没有注意，release下没有报错
				rd[i]++;
			if (i + rd[i] > mx) //如果新计算的最右侧端点大于mx,则更新pos和mx
			{
				pos = i;
				mx = i + rd[i];
			}
			if (rd[i] - 1 > maxLen)
			{
				start = (i - rd[i]) / 2;
				maxLen = rd[i] - 1;
			}
		}
		return s.substr(start, maxLen);
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

	}
	string convert(string s, int numRows) {
		if (numRows <= 1) return s;
		string res = "";
		int size = 2 * numRows - 2;
		for (int i = 0; i < numRows; ++i) {
			for (int j = i; j < s.size(); j += size) {
				res += s[j];
				int tmp = j + size - 2 * i;
				if (i != 0 && i != numRows - 1 && tmp < s.size()) res += s[tmp];
			}
		}
		return res;
	}
	int myAtoi(string str) {
		int i = 0;
		bool b = false;
		while (str.find(' ') != string::npos)
		{
			str.erase(str.begin() + str.find(' '));
		}
		while (str.find('+') != string::npos)
		{
			str.erase(str.begin() + str.find('+'));
		}
		if (!(str[0] == '-' || str[i] > '0' || str[i] < '9'))
			return 0;
		int res = 0;
		if (str[0] == '-')
		{
			i++;
			b = !b;
		}
		for (i; i < str.length(); i++)
		{
			if (str[i]<'0' || str[i]>'9')
				break;
			res *= 10;
			res += (b ? -1 : 1)*(str[i] - '0');
			if (res <= INT_MIN / 10)
				return INT_MIN;
			if (res > INT_MAX / 10)
				return INT_MAX;
		}

		return res;
	}

};
/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
1 7 21 35 35 21 7 1
1 8 28 56 70 56 28 8 1
1 9 36 84 126 126 84 36 9 1
*/

ListNode* Reversed(ListNode *node)
{
	if (node == NULL) return NULL;
	if (node->next == NULL) return node;
	ListNode * n = Reversed(node->next);
	if (n != NULL) {
		n->next = node;
		node->next = NULL;
	}
	return node;
}
int main()
{
#pragma region List Node
	ListNode *ln1_1 = new ListNode(1);
	ListNode *ln1_2 = new ListNode(2);
	ListNode *ln1_3 = new ListNode(3);
	ListNode *ln1_4 = new ListNode(4);
	ListNode *ln1_5 = new ListNode(5);
	ln1_1->next = ln1_2;
	ln1_2->next = ln1_3;
	ln1_3->next = ln1_4;
	ln1_4->next = ln1_5;
	ListNode *ln2_1 = new ListNode(1);
	ListNode *ln2_2 = new ListNode(3);
	ListNode *ln2_3 = new ListNode(4);
	ListNode *ln2_4 = new ListNode(8);
	ListNode *ln2_5 = new ListNode(10);
	ln2_1->next = ln2_2;
	ln2_2->next = ln2_3;
	//ln2_3->next = ln2_4;
	//ln2_4->next = ln2_5;
#pragma endregion
#pragma region TreeNode
	TreeNode *tNode;
#pragma endregion




	Solution s;
	/*Treeno* ret = s.isSymmetric(tNode);
	while (ret->next != NULL)
	{
		cout << ret->val << endl;
		ret = ret->next;
	}*/
	//vector<int> Rows = s.getRow(3);
	//vector<int> n = { 3,2,3
	//};
	//cout << s.majorityElement(n) << endl;
	
	//for (int i = 11; i <= 14; i++)
	//{
	//	int num = 1 << i;
	//	cout << i<<" "<<num << endl;
	//}
	Reversed(ln1_1);
	cout << ln1_2->next->val;
	system("pause");

	return 0;
}

