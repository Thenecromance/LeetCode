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
#include <queue>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <Windows.h>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
	int val;
	vector<Node*> children;

	Node() :val(0) {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

struct StringNode
{
	string str;
	int times;
};
class Solution_E {
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
		ListNode* next = new ListNode(0);


		if (NULL == l1) {
			return l2;
		}

		if (NULL == l2) {
			return l1;
		}

		ListNode* result = next;

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
		int max = INT_MIN;
		int cal = 0;
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			cal = nums[i];
			if (max < cal)
				max = cal;
			for (int j = i + 1; j < nums.size(); j++)
			{
				cal += nums[j];
				if (max < cal)
					max = cal;
			}
		}
		return max;


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
		vector<int>a(10001, 0);
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
		ListNode* p = head->next, * q = head;
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
		ListNode* preNode = &l3;
		int addNumber = 0;
		ListNode* b1 = l1, * b2 = l2;
		while (b1 != NULL || b2 != NULL || addNumber > 0)//当l1和l2不为空或者addNumber>0任意一个条件成立
		{
			ListNode* node = new ListNode(0);//临时的结构体指针
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

			return getSum(a ^ b, (a & b) << 1);
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
	bool hasCycle(ListNode* head) {
		ListNode* ptr1 = head;
		ListNode* ptr2 = head->next->next;
		while (ptr1 != ptr2)
		{
			if (ptr2->next == NULL || ptr2 == NULL)
				return false;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next->next;
		}
		return true;
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
#pragma region 189. 旋转数组

	void rotate(vector<int> & nums, int k) {
		if (0 == k || nums.size() <= 0 || 0 == k % nums.size())
			return;
		k = nums.size() - k % nums.size();
		for (int i = 0; i < k / 2; ++i)
			swap(nums[i], nums[k - i - 1]);
		for (int i = 0; i < (nums.size() - k) / 2; ++i)
			swap(nums[i + k], nums[(nums.size() - i - 1)]);
		for (int i = 0; i < nums.size() / 2; ++i)
			swap(nums[i], nums[nums.size() - i - 1]);
	}
#pragma endregion
#pragma region 1025. 除数博弈
	bool divisorGame(int N) {
		return N & 1 ? false : true;
	}
#pragma endregion
#pragma region 766. 托普利茨矩阵
	bool isToeplitzMatrix(vector<vector<int>> & matrix) {
		int line = matrix.size();
		int row = matrix[0].size();
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < row; j++)
			{
				if (i + 1 == line || j + 1 == row)continue;
				if (matrix[i][j] != matrix[i + 1][j + 1])
					return false;
			}
		}
		return true;
	}
	//空间占用O(matrix[0])
	bool compare(vector<int>& nums1, vector<int> nums2)
	{
		for (int i = 0; i < nums1.size() - 1; i++)
		{
			if (nums1[i] != nums2[i + 1])
				return false;
		}
		nums1.insert(nums1.begin(), nums2[0]);
		nums1.pop_back();
		return true;
	}
	bool isToeplitzMatrix_2(vector<vector<int>>& matrix) {
		vector<int> marker = matrix[0];
		int length = marker.size();
		for (int i = 1; i < matrix.size(); i++)//得到每一行
		{
			if (!compare(marker, matrix[i]))
			{
				return false;
			}
		}
		return true;
	}
#pragma endregion

#pragma region 1030. 距离顺序排列矩阵单元格
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		map<int, vector<vector<int>>>m;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				vector<int> tmp(2);
				tmp[0] = i;
				tmp[1] = j;
				m[(abs(i - r0) + abs(j - c0))].push_back(tmp);
			}
		}
		vector<vector<int>> res;
		for (pair<int, vector<vector<int>>> x : m)
		{
			for (int i = 0; i < x.second.size(); i++)
			{
				res.push_back(x.second[i]);
			}
		}
		return res;
	}
	vector<vector<int>> allCellsDistOrder_Best(int r, int c, int r0, int c0) {
		vector<int> vi(r + c, 0);

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				int d = abs(i - r0) + abs(j - c0);
				vi[d + 1]++; // 这里有点妙，不用d来存放。
			}
		}
		for (int i = 1; i < r + c; i++) {
			vi[i] += vi[i - 1]; // 这里 0 1 2 3   0 1 3 5 前缀和数组
		}
		vector<vector<int>> re(r * c); // 一共r*c个点
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				int d = abs(i - r0) + abs(j - c0);
				re[vi[d]] = { i, j };
				vi[d]++;
			}
		}
		return re;

	}
#pragma endregion

#pragma region 748. 最短完整词
	string shortestCompletingWord(string licensePlate, vector<string> & words) {
		transform(licensePlate.begin(), licensePlate.end(), licensePlate.begin(), ::tolower);
		vector<int> licenseChVec(26, 0);
		for (auto ch : licensePlate) {
			if (isalpha(ch))
				licenseChVec[ch - 'a']	++;
		}
		string shortest = "aaaaaaaaaaaaaaa";
		for (string& str : words)
		{

			vector<int> wordVec(26, 0);
			for (char c : str)
			{
				if (isalpha(c))
					wordVec[c - 'a']	++;
			}
			for (int i = 0; i < 26; i++)
			{
				if (licenseChVec[i] > wordVec[i])break;
				if (25 == i && str.size() < shortest.size())
				{
					shortest = str;
				}
			}
		}
		return shortest;

	}
#pragma endregion

#pragma region 892. 三维形体的表面积
	int surfaceArea(vector<vector<int>> & grid) {
		//每个表面积为6
		int size = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid.size(); j++)
			{
				if (grid[i][j] != 0)
				{
					size += grid[i][j] * 6 - 2 * (grid[i][j] - 1);

					if (i != 0 && grid[i - 1][j] != 0)
						size -= min(grid[i - 1][j], grid[i][j]);

					if (i < grid.size() - 1 && grid[i + 1][j] != 0)
						size -= min(grid[i + 1][j], grid[i][j]);

					if (j != 0 && grid[i][j - 1] != 0)
						size -= min(grid[i][j - 1], grid[i][j]);

					if (j < grid.size() - 1 && grid[i][j + 1] != 0)
						size -= min(grid[i][j + 1], grid[i][j]);
				}
			}
		}
		return size;
	}
#pragma endregion

#pragma region 606. 根据二叉树创建字符串
	stack<TreeNode> stc;
	string tree2str(TreeNode* t) {
		if (!t)return "";
		string l = "(" + tree2str(t->left) + ")";
		string r = "(" + tree2str(t->right) + ")";
		if (!(t->left) && !(t->right))
			l = r = "";
		if (t->left && !(t->right))
			r = "";
		return to_string(t->val) + l + r;
	}
#pragma endregion

#pragma region 437. 路径总和 III
	void helpSum(TreeNode * root, int& res, vector<int> & nums, int sum)
	{
		nums.push_back(0);
		int nodeCount = nums.size();
		for (int i = 0; i < nodeCount; i++)
		{
			nums[i] += root->val;
			res += (nums[i] == sum);
		}
		if (root->left)helpSum(root->left, res, nums, sum);
		if (root->right)helpSum(root->right, res, nums, sum);
		for (int i = 0; i < nodeCount; i++)
		{
			nums[i] -= root->val;
		}
		nums.pop_back();
	}
	int pathSum(TreeNode* root, int sum) {
		if (!root)return 0;
		int res = 0;
		vector<int>sums;
		helpSum(root, res, sums, sum);
		return res;

	}
#pragma endregion


#pragma region 506. 相对名次
	vector<string> findRelativeRanks(vector<int> & nums) {
		vector<int> nums1 = nums;
		vector<string>res;
		sort(nums1.begin(), nums1.end(), greater<int>());
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < nums1.size(); j++)
			{
				if (nums[i] == nums1[j])
				{
					if (j == 0)
						res.push_back("Gold Medal");
					else if (j == 1)
						res.push_back("Silver Medal");
					else if (j == 2)res.push_back("Bronze Medal");
					else res.push_back(to_string(j + 1));
					break;
				}
			}
		}
		return res;
	}
#pragma endregion
#pragma region 704. 二分查找
	int search(vector<int> & nums, int target) {
		int res = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == target)
			{
				res = i;
				return res;
			}
		}
		return res;
	}
#pragma endregion

#pragma region 598. 范围求和 II
	int maxCount(int m, int n, vector<vector<int>> & ops) {
		if (ops.size() < 1)return m * n;
		int minLine = INT_MAX; int minRow = INT_MAX;
		for (int i = 0; i < ops.size(); i++)
		{
			if (ops[i][0] < minLine)
				minLine = ops[i][0];
			if (ops[i][1] < minRow)
				minRow = ops[i][1];
		}
		return minLine * minRow;
	}
#pragma endregion
#pragma region 78. 子集
	vector<vector<int>> subsets(vector<int> & nums) {
		vector<vector<int>> res;
		res.push_back({});//肯定有空集
		int size = nums.size();
		int powsize = pow(2, size);
		int hash = 1;
		while (hash < powsize)
		{
			vector<int>map;
			for (int k = 0; k < size; k++)
			{
				int a = 1 << k;
				if (a & hash)
					map.push_back(nums[k]);
			}
			res.push_back(map);
			hash++;
		}
		return res;

	}
#pragma endregion




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
		if (str.empty()) return 0;
		int sign = 1, base = 0, i = 0, n = str.size();
		while (i < n && str[i] == ' ') ++i;
		if (str[i] == '+' || str[i] == '-') {
			sign = (str[i++] == '+') ? 1 : -1;
		}
		while (i < n && str[i] >= '0' && str[i] <= '9') {
			if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
				return (sign == 1) ? INT_MAX : INT_MIN;
			}
			base = 10 * base + (str[i++] - '0');
		}
		return base * sign;
	}
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* cursorA = headA;
		ListNode* cursorB = headB;
		if (!cursorA || !cursorB)
			return NULL;
		while (cursorA != cursorB)
		{
			if (!cursorA)
				cursorA = headB;
			else
				cursorA = cursorA->next;
			if (!cursorB)
				cursorB = headA;
			else
				cursorB = cursorB->next;
		}
		return cursorA;
	}
	bool isPowerOfThree(int n) {
		if (n <= 0)
			return false;
		while (n > 1)
		{
			if (n % 3 != 0) return false;
			n /= 3;
		}
		return true;
	}
	bool isPowerOfTwo(int n) {
		if (n <= 0)
			return false;
		while (n > 1)
		{
			if (n % 2 != 0) return false;
			n /= 2;
		}
		return true;
	}
	bool isPowerOfFour(int num) {
		if (num <= 0)
			return false;
		if (num == 1)
			return true;
		while (num > 1)
		{
			if (num % 4 != 0) return false;
			num /= 4;
		}
		return true;
	}
	int rob(vector<int>& nums) {
		if (nums.size() == 0)return 0;
		if (nums.size() == 1)return nums[0];
		vector<int> dp(nums.size(), 0);

		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);

		for (int i = 2; i < nums.size(); ++i)
		{
			dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
		}

		return dp[nums.size() - 1];

	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL) return res;
		queue<TreeNode*> p;
		p.push(root);
		while (!p.empty())
		{
			vector<int> level;
			int size = p.size();
			for (int i = 0; i < size; ++i)
			{
				TreeNode* node = p.front();
				p.pop();
				level.push_back(node->val);
				if (node->left)p.push(node->left);
				if (node->right)p.push(node->right);
			}
			res.insert(res.begin(), level);
		}
		return res;
	}
	int romanToInt(string s) {
		int roman_sum = 0;//累加后返回的结果
		int i = 0;//循环
		int n = s.length();//字符串的长度
		for (i; i < n; i++) {

			switch (s.at(i))//获取一个字符
			{
			case 'I':roman_sum += 1; break;
			case 'V':roman_sum += 5; break;
			case 'X':roman_sum += 10; break;
			case 'L':roman_sum += 50; break;
			case 'C':roman_sum += 100; break;
			case 'D':roman_sum += 500; break;
			case 'M':roman_sum += 1000; break;

			}

			if (i != 0) {//第一个字符不循环
				if (s.at(i - 1) == 'I' && (s.at(i) == 'V' || s.at(i) == 'X')) {//判断IV IX
					roman_sum = roman_sum - 1 * 2;
				}
				if (s.at(i - 1) == 'X' && (s.at(i) == 'L' || s.at(i) == 'C')) {//判断XL XC
					roman_sum = roman_sum - 10 * 2;
				}
				if (s.at(i - 1) == 'C' && (s.at(i) == 'D' || s.at(i) == 'M')) {//判断CD CM
					roman_sum = roman_sum - 100 * 2;
				}
			}
		}
		return roman_sum;
	}
	int minDepth(TreeNode* root) {
		if (root == NULL)return 0;
		if (root->left == NULL && root->right == NULL)
		{
			return 1;
		}
		int left, right;
		if (root->left != NULL)left = minDepth(root->left);
		else left = INT_MAX;
		if (root->right != NULL)right = minDepth(root->right);
		else right = INT_MAX;
		return left < right ? left : right + 1;
	}
	int hammingWeight(uint32_t n) {
		if (n == 0)return 0;
		int count = 0;
		while (n != 0)
		{
			n % 2 ? count++ : NULL;
			n = n >> 1;
		}
		return count;
	}
	bool isHappy(int n) {
		set<int> recordN;
		int sum = 0;
		while (n != 1) {
			recordN.insert(n);
			sum = 0;
			while (n != 0) {
				sum += ((n % 10) * (n % 10));
				n = n / 10;
			}
			if (recordN.find(sum) != recordN.end())
				return false;
			n = sum;
		}
		return true;
	}
	bool canJump(vector<int>& nums) {
		int N = nums.size();
		int maxreach = 0;
		for (int i = 0; i < N; i++)
		{
			if (i > maxreach)return false;
			maxreach = max(maxreach, i + nums[i]);
			if (maxreach >= N - 1)
				return true;

		}
	}
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		if (intervals.empty())
			return res;
		sort(intervals.begin(), intervals.end(), [](Interval const& i1, Interval const& i2) {return i1.start < i2.start; });

		res.push_back(intervals[0]);
		int cur = 0;
		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[i].start > res[cur].end) {
				res.push_back(intervals[i]);
				cur++;
			}
			else {
				res[cur].end = max(res[cur].end, intervals[i].end);
			}
		}
		return res;

	}
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		intervals.insert(intervals.begin(), newInterval);
		if (intervals.empty())
			return res;
		sort(intervals.begin(), intervals.end(), [](Interval const& i1, Interval const& i2) {return i1.start < i2.start; });

		res.push_back(intervals[0]);
		int cur = 0;
		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[i].start > res[cur].end) {
				res.push_back(intervals[i]);
				cur++;
			}
			else {
				res[cur].end = max(res[cur].end, intervals[i].end);
			}
		}
		return res;

	}
	ListNode* reverseList(ListNode* head) {
		if (head == NULL)return NULL;
		ListNode* prev = nullptr, * curr = head, * next = head->next;
		while (curr->next)
		{
			curr->next = prev;
			prev = curr;
			curr = next;
			next = next->next;
		}
		curr->next = prev;
		return curr;


	}
	int maxArea(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int size = 0;
		int s = 0;
		while (left < right)
		{
			s = height[left] > height[right] ? height[right] : height[left];
			size = max(size, s * (right - left));
		}
		return size;
	}
	void moveZeroes(vector<int>& nums) {
		int flag = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				nums.erase(nums.begin() + i);
				i--;
				flag++;
			}
		}
		while (flag)
		{
			nums.push_back(0);
			flag--;
		}


	}
	int largestPerimeter(vector<int>& A) {
		sort(A.begin(), A.end());
		for (int i = A.size() - 3; i >= 0; i--)
		{
			if ((A[i] + A[i + 1]) > A[i + 2])
				return A[i] + A[i + 1] + A[i + 2];
		}
		return 0;
	}
	int repeatedNTimes(vector<int>& A) {
		sort(A.begin(), A.end());
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] == A[i + A.size() / 2 - 1])
				return A[i];
		}
	}
	bool isAlienSorted(vector<string>& words, string order)
	{
		int hash[26];
		for (int i = 0; i < order.length(); i++)
		{
			int temp = order[i] - 'a';
			hash[temp] = i;
		}
		for (int i = 0; i < words.size() - 1; i++)
		{
			int a = words[i].length();
			int b = words[i + 1].length();
			int len = (a > b ? b : a);
			int j = 0;
			for (; j < len;)
			{
				if (hash[words[i][j] - 'a'] > hash[words[i + 1][j] - 'a'])
					return 0;
				else if (hash[words[i][j] - 'a'] < hash[words[i + 1][j] - 'a'])
					break;
				else
					j++;
			}
			if (j == len && a > b)
				return 0;
		}
		return 1;
	}
	string largestTimeFromDigits(vector<int>& A) {
		for (int i = 0; i < A.size(); i++)
		{

		}

	}
	int uniqueMorseRepresentations(vector<string>& words) {
		vector<string> Morse = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
		string output;
		set<string> set;
		for (int i = 0; i < words.size(); i++)
		{
			output = "";
			for (int j = 0; j < words[i].size(); j++)
			{
				output += Morse[words[i][j] - 'a'];
			}
			set.insert(output);
		}
		return set.size();
	}
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		map<string, int>maps;
		map<string, int>::iterator iter;
		int currenttimes;
		string timesstr;
		string domain;
		vector<string> ret;
		for (int i = 0; i < cpdomains.size(); i++)
		{
			while (cpdomains[i].find(".") != string::npos)
			{
				if (cpdomains[i].find(" ") != string::npos)
				{
					currenttimes = atoi(cpdomains[i].substr(0, cpdomains[i].find(" ")).c_str());
					domain = cpdomains[i].substr(cpdomains[i].find(" ") + 1);
					if (maps.find(domain) == maps.end())					maps.insert(pair<string, int>(domain, currenttimes));
					else					maps[domain] += currenttimes;
				}
				if (cpdomains[i].find(".") != string::npos)
				{
					cpdomains[i] = cpdomains[i].substr(cpdomains[i].find(".") + 1);
					if (maps.find(cpdomains[i]) == maps.end())					maps.insert(pair<string, int>(cpdomains[i], currenttimes));
					else					maps[cpdomains[i]] += currenttimes;
				}

			}
		}
		for (iter = maps.begin(); iter != maps.end(); iter++)
		{
			string build = to_string(iter->second) + " " + iter->first;
			ret.push_back(build);
		}
		return ret;
	}
	double largestTriangleArea(vector<vector<int>>& points) {
		if (points.size() <= 2)
			return 0;
		double s = 0.0;
		double curr = 0.0;
		for (int i = 0; i < points.size(); i++)
			for (int j = i + 1; j < points.size(); j++)
				for (int l = j + 1; l < points.size(); l++)
				{
					curr = (
						points[i][0] * points[j][1] +
						points[j][0] * points[l][1] +
						points[l][0] * points[i][1] -
						points[i][0] * points[l][1] -
						points[j][0] * points[i][1] -
						points[l][0] * points[j][1]
						) / 2.0;
					s = s >= abs(curr) ? s : abs(curr);
				}
		return s;
	}
	string mostCommonWord(string paragraph, vector<string>& banned) {
		unordered_set<string> s;
		for (auto b : banned) {
			s.insert(b);
		}
		unordered_map<string, int> m;
		paragraph.append(1, ' ');
		for (int left = 0, right = 0; right < paragraph.length(); right++) {
			if (!isalpha(paragraph[right])) {
				string str;
				while (left < right) {
					str += tolower(paragraph[left++]);
				}
				if (s.find(str) == s.end())
					m[str] ++;
				while (right < paragraph.length() && !isalpha(paragraph[right])) {
					right++;
				}
				left = right;
			}
		}
		string res;
		int max_cnt = 0;
		for (auto it = m.begin(); it != m.end(); it++) {
			if (it->second > max_cnt) {
				res = it->first;
				max_cnt = it->second;
			}
		}
		return res;
	}
	vector<int> shortestToChar(string S, char C) {
		vector<int> loc;
		vector<int> ret(S.length(), INT_MAX);
		for (int i = 0; i < S.length(); i++)
			if (S[i] == C)loc.push_back(i);
		for (int i = 0; i < S.length(); i++)
		{
			for (int j = 0; j < loc.size(); j++)
			{
				if (ret[i] >= abs(i - loc[j]))
					ret[i] = abs(i - loc[j]);
			}
		}
		return ret;
	}
	string toGoatLatin(string S) {
		string ret;
		int count = 1;
		string str;
		S.append(" ");
		while (S.find(" ") != string::npos)
		{
			str = S.substr(0, S.find(" "));
			if (str[0] == 'a' ||
				str[0] == 'e' ||
				str[0] == 'i' ||
				str[0] == 'o' ||
				str[0] == 'u' ||
				str[0] == 'A' ||
				str[0] == 'E' ||
				str[0] == 'I' ||
				str[0] == 'O' ||
				str[0] == 'U'
				)
			{
				ret += str;
			}
			else
			{
				ret.append(str, 1, str.length());
				ret += str[0];
			}
			ret += "ma";
			for (int i = 0; i < count; i++)
			{
				ret += "a";
			}
			ret += " ";
			count++;
			S = S.substr(S.find(" ") + 1);
		}

		return ret.substr(0, ret.length() - 1);
	}
	//OT
	vector<vector<int>> largeGroupPositions(string S) {
		vector<vector<int>> ret;
		if (S.size() <= 0)
			return ret;
		int left = 0;
		int right = 1;
		while (right < S.size())
		{
			if (S[left] != S[right])
			{
				if (right - left > 2)
				{
					ret.push_back({ left,right - 1 });
					left = right;
				}

			}
			else
				right++;
		}
		if (right == S.size())
		{
			if (right - left > 2)
			{
				ret.push_back({ left,right - 1 });
				left = right;
			}
		}
		return ret;
	}
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		for (int i = 0; i < A.size(); i++)
			std::reverse(A[i].begin(), A[i].end());
		for (int i = 0; i < A.size(); i++)
			for (int j = 0; j < A[i].size(); j++)
				A[i][j] = A[i][j] == 1 ? 0 : 1;
		return A;
	}
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		if (rec2[0] >= rec1[2] ||//左下角
			rec2[1] >= rec1[3]
			)return false;
		if (rec2[2] <= rec1[0] ||
			rec2[3] <= rec1[1]
			)return false;

		return true;

	}
	bool hasAlternatingBits(int n) {
		int temp = n ^ (n >> 1);
		return (temp & (temp + 1)) == 0;
	}
	vector<int> numberOfLines(vector<int>& widths, string S) {
		int line = 0;
		int w = 0;
		for (int i = 0; i < S.length(); i++)
		{
			w += widths[S[i] - 'a'];
			if (w == 100)
			{
				w = 0;
				line++;
			}
			else if (w > 100)
			{
				w = 0;
				w += widths[S[i] - 'a'];
				line++;
			}
		}
		return { line + 1,w };
	}
	int smallestRangeI(vector<int>& A, int K) {
		int max = A[0], min = A[0];
		for (int i : A)
		{
			max = max >= i ? i : max;
			min = min <= i ? i : min;
		}
		int dif = abs(max - min);
		cout << max << ":" << min << endl;
		return K * 2 >= dif ? 0 : dif - abs(K * 2);
	}
	int addDigits(int num) {
		if (num == 0)return 0;
		int ret = num % 9;
		if (ret == 0)return 9;
		return ret;
	}
	string reverseWords(string s) {
		stack<string> stack;
		string tmp;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			if (i == 0)
			{
				tmp += s[0];
				stack.push(tmp);
			}
			if (s[i] == ' ')
			{
				stack.push(tmp);
				tmp = "";
			}
			else
			{
				tmp += s[i];
			}
		}
		tmp = "";
		while (!stack.empty())
		{
			tmp += stack.top() += " ";
			stack.pop();
		}
		return tmp.substr(0, tmp.length() - 1);
	}
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0; i < nums.size(); i += 2)
		{
			res += nums[i];
		}
		return res;
	}
	int fib(int N) {
		//if (N <= 2)
		//{
		//	return 1;
		//}
		//else
		//{
		//	return fib(N - 1) + fib(N - 2);
		//}
		double z = sqrt(5.0);
		double x = (1 + z) / 2;
		double y = (1 - z) / 2;
		return (int)(pow(x, N) - pow(y, N)) / z + 0.5;
	}
	vector<string> findWords(vector<string>& words) {
		string l1 = "qwertyuiop";
		string l2 = "asdfghkjl";
		string l3 = "zxcvbnm";
		vector<string>res;
		map<char, int>map;
		for (char c : l1)
			map.insert(pair<char, int>(c, 1));
		for (char c : l2)
			map.insert(pair<char, int>(c, 2));
		for (char c : l3)
			map.insert(pair<char, int>(c, 3));
		int head = 0;
		bool can_put = true;
		string orig;
		for (string word : words)
		{
			orig = word;
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			can_put = true;
			head = map[word[0]];
			for (int i = 0; i < word.size(); i++)
				if (head != map[word[i]])
				{
					can_put = false;
					break;
				}
			if (can_put)res.push_back(orig);
		}
		return res;
	}
	bool isUnivalTree(TreeNode* root) {
		if (root == NULL)return true;
		if (!root->left && !root->right)return true;
		if (!root->left)
			return root->val == root->left->val && isUnivalTree(root->left);
		if (!root->right)
			return root->val == root->right->val && isUnivalTree(root->right);
		return root->val == root->left->val && root->val == root->right->val && isUnivalTree(root->left) && isUnivalTree(root->right);
	}

	void Create(TreeNode* root, vector<int>& nums, int min, int max)
	{
		if (min > max)return;
		int index = (min + max) / 2;
		TreeNode* temproot = root;
		TreeNode* temp = new TreeNode(nums[index]);
		if (temp->val <= temproot->val)
		{
			temproot->left = temp;
			temproot = temp;
		}
		else
		{
			temproot->right = temp;
			temproot = temp;
		}
		Create(temproot, nums, min, index - 1);
		Create(temproot, nums, index + 1, max);
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)return NULL;
		if (nums.size() == 1)return new TreeNode(nums[0]);
		TreeNode* root = NULL;
		int index = (nums.size() - 1) / 2;
		root = new	TreeNode(nums[index]);
		Create(root, nums, 0, index - 1);
		Create(root, nums, index + 1, nums.size() - 1);
		return root;
	}

	int TreeDeep(TreeNode* root)
	{
		if (!root)return 0;
		return 1 + max(TreeDeep(root->left), TreeDeep(root->right));
	}
	bool isBalanced(TreeNode* root) {
		if (!root)return true;
		if (abs(TreeDeep(root->left) - TreeDeep(root->right)) > 1)return false;
		if (isBalanced(root->left) && isBalanced(root->right))return true;
		else return false;
	}

	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)return false;
		if (!root->left && !root->right && sum == root->val)return true;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);

	}

	int islandPerimeter(vector<vector<int>>& grid) {
		int length = 0;
		for (int i = 0; i < grid.size(); i++)//列
		{
			for (int j = 0; j < grid[0].size(); j++)//行
			{
				if (grid[i][j] == 1)
				{
					length += 4;
					if (i - 1 >= 0 && grid[i - 1][j] == 1)length -= 1;
					if (i + 1 < grid.size() && grid[i + 1][j] == 1)length -= 1;
					if (j - 1 >= 0 && grid[i][j - 1] == 1)length -= 1;
					if (j + 1 < grid[0].size() && grid[i][j + 1] == 1)length -= 1;
				}
			}
		}
		return length;
	}

	int distributeCandies(vector<int>& candies) {
		int totalnums = candies.size() / 2;//妹妹最多可以获得糖果数
		sort(candies.begin(), candies.end());//去重
		candies.erase(unique(candies.begin(), candies.end()), candies.end());
		return (candies.size() >= totalnums) ? totalnums : candies.size();

	}

	vector<string> fizzBuzz(int n) {
		vector<string> res;
		string str;
		for (int i = 1; i <= n; i++)
		{
			str = "";
			if (i % 3 != 0 && i % 5 != 0) res.push_back(to_string(i));
			else
			{
				if (i % 3 == 0)str += "Fizz";
				if (i % 5 == 0)str += "Buzz";
				res.push_back(str);
			}
		}
		return res;
	}
	int countPrimeSetBits(int L, int R) {
		vector<int> prime = { 2 ,3 ,5 ,7 ,11 ,13 ,17 ,19 };
		int res = 0;
		while (L <= R)
		{
			int num = 0, temp = L;
			while (temp > 0)
			{
				num += temp % 2;
				temp = temp >> 1;
			}
			for (int i = 0; i < prime.size(); i++)
			{
				if (num == prime[i])res++;
			}
			L++;
		}
		return res;
	}

	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

		int m = nums.size();
		int n = nums[0].size();
		if (m * n != r * c)return nums;
		vector<vector<int>> resmatrix(r, vector<int>(c, 0));
		for (int i = 0; i < m * n; ++i)
		{
			resmatrix[i / c][i % c] = nums[i / n][i % n];
		}
		return resmatrix;
	}

	ListNode* middleNode(ListNode* head) {
		/*vector<ListNode*> vec;
		while (head->next!=NULL)
		{
			vec.push_back(head);
			head = head->next;
		}
		int num = vec.size() / 2;
		if (vec.size()% 2 == 0)return vec[num+1];
		else return vec[num];*/
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		return fast->next == NULL ? slow : slow->next;
	}

	vector<string> commonChars(vector<string>& A) {
		if (A.empty())return A;
	}

	int projectionArea(vector<vector<int>>& grid) {
		int N = grid.size();
		int ans = 0;

		for (int i = 0; i < N; ++i) {
			int bestRow = 0;  // largest of grid[i][j]
			int bestCol = 0;  // largest of grid[j][i]
			for (int j = 0; j < N; ++j) {
				if (grid[i][j] > 0) ans++;  // top shadow
				bestRow = max(bestRow, grid[i][j]);
				bestCol = max(bestCol, grid[j][i]);
			}
			ans += bestRow + bestCol;
		}

		return ans;

	}

	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int>res(findNums.size(), -1);
		for (int i = 0; i < findNums.size(); i++)
		{
			int maxnum = -1;
			for (int j = 0; j < nums.size(); j++)
			{
				if (findNums[i] == nums[j])
				{
					for (int l = j + 1; l < nums.size(); l++)
					{
						if (findNums[i] < nums[l])
							if (maxnum == -1)
								maxnum = nums[l];
							else break;
					}
				}
			}
			res[i] = maxnum;
		}
		return res;
	}

	vector<string> uncommonFromSentences(string A, string B) {
		unordered_map<string, int>map;
		vector<string> res;
		string tempstr;
		for (char a : A)
		{
			if (a != ' ')
			{
				tempstr += a;
			}
			else
			{
				map[tempstr] += 1;
				tempstr = "";
			}
		}
		map[tempstr] += 1;
		tempstr = "";
		for (char a : B)
		{
			if (a != ' ')
			{
				tempstr += a;
			}
			else
			{
				map[tempstr] += 1;
				tempstr = "";
			}
		}
		map[tempstr] += 1;
		for (unordered_map<string, int>::iterator it = map.begin(); it != map.end(); it++)
		{
			if (it->second == 1)res.push_back(it->first);
		}
		return res;
	}

	int binaryGap(int N) {
		if (N == 0)	return 0;
		int maxdis = 0;
		int pos = 32;
		for (int i = 0; i < 32; i++)
		{
			if (((N >> i) % 2) == 1)
			{
				maxdis = max(maxdis, i - pos);
				pos = i;
			}
		}
		return maxdis;
	}

	char findTheDifference(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != t[i])return t[i];
		}
		return t[t.size() - 1];
	}

	TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
		if (!root)return tail;
		TreeNode* res = increasingBST(root->left, root);
		root->left = NULL;
		root->right = increasingBST(root->right, tail);
		return res;
	}
	int rotatedDigits(int N) {
		int rescount = 0;
		string numstr;
		bool isdifferent = false;
		bool hashwrongnum = false;
		for (int i = 1; i <= N; ++i)
		{
			numstr = to_string(i);
			isdifferent = false;
			hashwrongnum = false;
			for (char c : numstr)
			{
				if (hashwrongnum)break;
				if (
					c - '0' == 1 ||
					c - '0' == 0 ||
					c - '0' == 8
					)continue;
				else if (
					c - '0' == 2 ||
					c - '0' == 5 ||
					c - '0' == 6 ||
					c - '0' == 9
					)
					isdifferent = true;
				else
				{
					hashwrongnum = true;
				}
			}

			if (!hashwrongnum && isdifferent)
				rescount++;
		}
		return rescount;
	}

	bool detectCapitalUse(string word) {
		if (word.length() == 1)	return true;
		int count = 0;
		for (char c : word)
			if (c <= 'Z')
				count++;
		return count == 0 || count == word.size() || (count == 1 && word[0] <= 'Z');
	}
	void getAllValue(TreeNode* node, vector<int>& value_vec)
	{
		if (!node)return;
		value_vec.push_back(node->val);
		getAllValue(node->left, value_vec);
		getAllValue(node->right, value_vec);
	}
	int getMinimumDifference(TreeNode* root) {
		if (!root->left && !root->right)return root->val;
		vector<int> val_v;
		getAllValue(root, val_v);
		sort(val_v.begin(), val_v.end());
		int min = 0;
		for (int i = val_v.size(); i > 0; i--)
		{
			min = min < (val_v[i] - val_v[i - 1]) ? min : val_v[i] - val_v[i - 1];
		}
		return min;
	}
	bool isAnagram(string s, string t) {
		if (s.length() != t.length())return false;
		vector<int>record(26, 0);
		for (int i = 0; i < s.length(); i++)
		{
			record[s[i] - 'a'] += 1;
			record[t[i] - 'a'] -= 1;
		}
		for (int i = 0; i < 25; i++)
		{
			if (record[i] != 0)return false;
		}
		return true;
		//sort(s.begin(), s.end());
		//sort(t.begin(), t.end());
		//return s == t;
	}
	int bitwiseComplement(int N) {
		int n = 1;
		if (N == 0)return 1;
		while (n <= N)
		{
			n <<= 1;
		}
		return (n - 1 - N);
	}
	void save_value(TreeNode* root, vector<int>& values)
	{
		if (root)
		{
			save_value(root->right, values);
			values.push_back(root->val);
			save_value(root->left, values);
		}
	}
	bool findTarget(TreeNode* root, int k) {
		vector<int>values;
		save_value(root, values);
		for (int i = 0; i < values.size(); i++)
		{
			for (int j = i + 1; j < values.size(); j++)
			{
				if (k == values[i] + values[j])return true;
			}
		}
		return false;
	}
	int minMoves(vector<int>& nums) {
		int times = 0;
		int minEle = *min_element(nums.begin(), nums.end());
		for (int num : nums)
			times += (num - minEle);
		return times;
	}
	int GetLeftNode(TreeNode* root, bool isleft)
	{
		if (!root)return 0;
		else if (!root->left && !root->right)return isleft ? root->val : 0;
		return GetLeftNode(root->left, true) + GetLeftNode(root->right, false);
	}
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root)return 0;
		return GetLeftNode(root, false);
	}

	bool lemonadeChange(vector<int>& bills) {
		if (bills[0] != 5)return false;
		int countf = 0, countt = 0;
		for (int i = 0; i < bills.size(); i++)
		{
			if (bills[i] == 5)countf++;
			else if (bills[i] == 10)
			{
				countf--;
				countt++;
				if (countf < 0)return false;
			}
			else
			{
				if (countt > 0)
				{
					countt--;
					countf--;
				}
				else
				{
					countf -= 3;
				}
				if (countf < 0)
					return false;
			}
		}
		return true;

	}

	int missingNumber(vector<int>& nums) {
		//int sum = nums.size();
		//for (int i = 0; i < nums.size(); i++)
		//{
		//	sum ^= nums[i];
		//	sum ^= i;
		//}
		//return sum;
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			res += i;
			res -= nums[i];

		}
		return res + nums.size();
	}

	int numJewelsInStones(string J, string S) {
		if (J.empty() || S.empty())return 0;
		vector<int> record = vector<int>(128, 0);
		int count = 0;
		for (char c : J)
		{
			record[c]++;
		}
		for (char c : S)
		{
			if (record[c])count++;
		}
		return count;
	}
	string toLowerCase(string str) {
		if (str.length() == 0)return str;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] = str[i] - 'A' + 'a';
			}
		}
		return str;
	}
	vector<int> sortedSquares(vector<int>& A) {
		if (A.size() == 0)return A;
		vector<int>res;
		for (int num : A)
		{
			res.push_back(num * num);
		}
		sort(res.begin(), res.end());
		return res;
	}
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
	vector<int> diStringMatch(string S) {
		vector<int>res;
		int numi = 0, numd = S.length();
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] == 'I')res.push_back(numi++);
			else res.push_back(numd--);
		}
		res.push_back(numd);
		return res;
	}
	bool judgeCircle(string moves) {
		int row = 0, line = 0;
		for (char c : moves)
		{
			if (c == 'U')row++;
			else if (c == 'D')row--;
			else if (c == 'L')line--;
			else if (c == 'R')line++;
		}
		return row == 0 && line == 0;
	}
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL)return t2;
		if (t2 == NULL)return t1;
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;

	}
	int hammingDistance(int x, int y) {
		int n = x ^ y;
		int res = 0;
		while (n)
		{
			if (n % 2 == 1)res++;
			n >>= 1;
		}
		return res;
	}
	int numUniqueEmails(vector<string>& emails) {
		set<string>res;
		string tempstr;
		string str2;
		for (string email : emails)
		{
			tempstr = email.substr(0, email.find('@'));
			for (char c : tempstr)
			{
				if (c == '.')continue;
				if (c == '+')break;
				str2.push_back(c);
			}
			email = str2 + email.substr(email.find('@'));
			tempstr = "";
			str2 = "";
			res.insert(email);
		}
		return res.size();
	}
	bool canWinNim(int n) {
		return n % 4 != 0;
	}
	int findComplement(int num) {
		int temp = num, num2 = 0;
		while (temp > 0)
		{
			temp >>= 1;
			num2 = (num2 << 1) + 1;
		}
		return num ^ num2;
	}
	int peakIndexInMountainArray(vector<int>& A) {
		int max = 0;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] > A[max])max = i;
		}
		return max;
	}
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> res;
		bool isAdd = true;
		int nums2 = 0;
		for (int i = left; i <= right; i++)
		{
			int temp = i;
			if (temp < 10)
			{
				res.push_back(i);
				continue;
			}

			while (temp > 0)
			{
				nums2 = temp % 10;
				if (nums2 == 0)
				{
					isAdd = false;
					break;
				}
				if (i % nums2 != 0)
				{
					isAdd = false;
					break;
				}
				temp /= 10;
			}

			if (isAdd)res.push_back(i);
			else isAdd = true;
		}
		return res;
	}
	vector<int> sortArrayByParity(vector<int>& A) {
		vector<int>vec1;
		vector<int>vec2;
		for (int n : A)
		{
			if (n % 2 == 0)vec2.push_back(n);
			else vec1.push_back(n);
		}
		for (int n : vec1)
		{
			vec2.push_back(n);
		}
		return vec2;
	}
	void reverseString(vector<char>& s) {
		int i = 0;
		int end = s.size() - 1;
		char c;
		while (i < end)
		{
			c = s[end];
			s[end] = s[i];
			s[i] = c;
			i++;
			end--;
		}
	}
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<vector<int>>ans(A[0].size(), vector<int>(A.size(), 0));
		for (int i = 0; i < A[0].size(); i++)
		{
			for (int j = 0; j < A.size(); j++)
			{
				ans[j][i] = A[i][j];
			}
		}
		return ans;
	}
	int numRookCaptures(vector<vector<char>>& board) {//size 8*8
		int count = 0;
		int posX, posY;
		vector<bool>mark(4, true);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'R')
				{
					posX = i;
					posY = j;
					break;
				}
			}
		}
		for (int step = 1; step < 8; step++)
		{
			if (posX + step < 8 && mark[0])
			{
				if (board[posX + step][posY] == 'p')
				{
					count++;
					mark[0] = false;
				}
				else if (board[posX + step][posY] == 'B')mark[0] = false;
			}
			if (posX - step >= 0 && mark[1])
			{
				if (board[posX - step][posY] == 'p') {
					count++; mark[1] = false;
				}
				else if (board[posX - step][posY] == 'B')mark[1] = false;
			}

			if (posY + step < 8 && mark[2])
			{
				if (board[posX][posY + step] == 'p')
				{
					count++;
					mark[2] = false;
				}
				else if (board[posX][posY + step] == 'B')mark[2] = false;
			}
			if (posY - step >= 0 && mark[3])
			{
				if (board[posX][posY - step] == 'p') {
					count++; mark[3] = false;
				}
				else if (board[posX][posY - step] == 'B')mark[3] = false;
			}
		}
		return count;
	}
	int calPoints(vector<string>& ops) {
		stack<int> stk;
		for (string str : ops)
		{
			if (str == "+") {
				int top = stk.top();
				stk.pop();
				int newtop = top + stk.top();
				stk.push(top);
				stk.push(newtop);
			}
			else if (str == "C")stk.pop();
			else if (str == "D")stk.push(2 * stk.top());
			else stk.push(atoi(str.c_str()));
		}
		int ans = 0;
		while (!stk.empty())
		{
			ans += stk.top();
			stk.pop();
		}
		return ans;
	}
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
		int S = 0;
		for (int x : A)if (x % 2 == 0)	S += x;
		vector<int >ans;
		for (int i = 0; i < queries.size(); i++)
		{
			int val = queries[i][0], index = queries[i][1];
			if (A[index] % 2 == 0)S -= A[index];
			A[index] += val;
			if (A[index] % 2 == 0)S += A[index];
			ans.push_back(S);
		}
		return ans;
	}
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> ans;
		if (!root)return ans;
		queue<TreeNode*>nodeque;
		nodeque.push(root);
		while (!nodeque.empty())
		{
			int count = nodeque.size();
			int cnt = count;
			double sum = 0;
			while (count > 0)
			{
				root = nodeque.front();
				nodeque.pop();
				sum += root->val;
				if (root->left)nodeque.push(root->left);
				if (root->right)nodeque.push(root->right);
				count--;
			}
			ans.push_back(sum / cnt);
		}
		return ans;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val >= q->val)
		{
			TreeNode* node = q;
			q = p;
			p = node;
		}
		while (true)
		{
			if (root->val >= p->val && root->val <= q->val)return root;
			else if (root->val > q->val)root = root->left;
			else if (root->val < q->val)root = root->right;
		}
		return NULL;
	}
	vector<string> path;
	vector<string> binaryTreePaths(TreeNode* root) {
		if (!root) return path;
		treereverse("", root);
		return path;
	}
	void treereverse(string str, TreeNode* root) {
		if (!root) return;
		if (!root->left && !root->right) {
			str += to_string(root->val);
			path.push_back(str);
			return;
		}
		str += to_string(root->val) + "->";
		if (root->left) treereverse(str, root->left);
		if (root->right) treereverse(str, root->right);
	}
	int firstUniqChar(string s) {
		int alpha[26] = { 0 };
		for (char c : s)
			alpha[c - 'a']++;
		for (int i = 0; i < s.length(); i++)
		{
			if (alpha[s[i] - 'a'] == 1)
			{
				return i;
			}
		}
		return -1;
	}
	int guess(int num);
	int guessNumber(int n) {
		int low = 1;
		int high = n;
		int num;
		while (low < high)
		{
			num = low + (high - low) / 2;
			if (guess(num) == 0)return num;
			else if (guess(num) == 1)low = num + 1;
			else high = num - 1;
		}
		return low;
	}
	int Title = 0;
	int findTilt(TreeNode* root) {
		traverse(root);
		return Title;
	}
	int traverse(TreeNode* root)
	{
		if (!root)return 0;
		int left = traverse(root->left);
		int right = traverse(root->right);
		Title = abs(left + right);
		return left + right + root->val;
	}
	TreeNode* invertTree(TreeNode* root) {
		if (!root)return root;
		if (root->left == NULL && root->right == NULL)return root;
		TreeNode* node = invertTree(root->left);
		root->left = invertTree(root->right);
		root->right = node;
		return root;
	}
	vector<int> preorder(Node* root) {
		if (!root)return {};
		stack<Node*> st;
		vector<int> res;
		st.push(root);
		while (!st.empty())
		{
			Node* temp = st.top();
			st.pop();
			res.push_back(temp->val);
			auto riter = temp->children.crbegin();
			while (riter != temp->children.crend())
			{
				if (*riter)
					st.push(*riter++);
			}
		}
		return res;
	}
	vector<int> sortArrayByParityII(vector<int>& A) {
		stack<int>num1, num2;
		vector<int>  ans;
		for (int i : A)
		{
			if (i % 2 == 0)num2.push(i);
			if (i % 2 == 1)num1.push(i);
		}
		for (int i = 0; i < A.size(); i += 2)
		{
			ans.push_back(num2.top());
			ans.push_back(num1.top());
			num2.pop();
			num1.pop();
		}
		return ans;
	}
	int maxDepth(Node* root) {
		if (!root)return 0;
		int maxDep = 1;
		for (Node* child : root->children)
		{
			maxDep = max(maxDep, 1 + maxDepth(child));
		}
		return maxDep;
	}
	int imp = 0;
	int getImportance(vector<Employee*> employees, int id) {
		for (Employee* e : employees)
		{
			if (e->id == id)
			{
				imp += e->importance;
				if (e->subordinates.empty())return imp;
				else
				{
					for (int i : e->subordinates)
						getImportance(employees, i);
				}
			}
		}
		return imp;
	}

	vector<string> letterCasePermutation(string S) {
		vector<string>res;
		if (S.length() == 0)return{};
		string s2 = S;
		for (int i = 0; i < S.length(); i++)
			if (isupper(s2[i]))s2[i] = tolower(s2[i]);

		int len = 0;
		allsort(res, s2, len);
		return res;

	}
	void allsort(vector<string>& letters, string& s, int& len) {
		// 遍历结束
		if (len == s.length()) {
			letters.push_back(s);
			return;
		}

		// 对走过的每一步，选择要不要改变大小写
		// 这里就相当于全排列里的全循环
		len++;
		allsort(letters, s, len);
		len--;  // 第一轮结束，没有改变数字，所以不用回退

		// 如果不是数字，进入下一轮
		if (s[len] > '9' || s[len] < '0') {
			len++;
			s[len - 1] = s[len - 1] - 'a' + 'A';
			allsort(letters, s, len);

			s[len - 1] = s[len - 1] - 'A' + 'a';
			len--;
		}
	}

	int findMaxConsecutiveOnes(vector<int>& nums) {
		int count = 0;
		vector<int> numCounter;
		for (int i : nums)
		{
			if (i == 0)
			{
				numCounter.push_back(count);
				count = 0;
			}
			if (i == 1)	count++;
		}
		numCounter.push_back(count);
		sort(numCounter.begin(), numCounter.end());
		return numCounter[numCounter.size() - 1];
	}

	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int child = 0;
		int cookie = 0;
		while (child < g.size() && cookie < s.size()) {
			if (g[child] <= s[cookie])child++;
			cookie++;
		}
		return child;
	}
#pragma region 1089. 复写零
	void duplicateZeros(vector<int> & arr) {
		int size = arr.size();
		int i = 0;
		while (i < size)
		{
			if (!arr[i])
			{
				arr.insert(arr.begin() + i, 0);
				i += 2;
				arr.pop_back();
			}
			else
			{
				i++;
			}
		}
	}
#pragma endregion
#pragma region 1078. Bigram 分词
	vector<string> findOcurrences(string text, string first, string second) {

		vector<string>res;
		string tarStr = first + " " + second;
		int pos = text.find(tarStr);
		while (pos != string::npos)
		{
			if (pos + tarStr.length() == text.length())
				return res;
			text = text.substr(pos + tarStr.length() + 1);
			string temp = "";
			for (int i = 0; i < text.length(); i++)
			{

				if (text[i] == ' ')
					break;
				temp += text[i];
			}
			res.push_back(temp);
			pos = text.find(tarStr);
		}
		return res;


	}
#pragma endregion
#pragma region IP 地址无效化
	string defangIPaddr(string address) {
		string res;
		for (int i = 0; i < address.length(); i++)
		{
			if (address[i] == '.')
				res += "[.]";
			else
				res += address[i];
		}
		return res;
	}
#pragma endregion
#pragma region 1103. 分糖果 II
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int>res = vector<int>(num_people, 0);
		int Num = 0;
		while (candies > 0)
		{
			for (int i = 0; i < num_people; i++)
			{
				int deltaNum = num_people * Num + i + 1;
				if (candies <= deltaNum)
				{
					deltaNum = candies;
				}
				res[i] += deltaNum;
				candies -= deltaNum;
				if (candies <= 0)
					break;
			}
			Num++;
		}
		return res;
	}
#pragma endregion

#pragma region 1047. 删除字符串中的所有相邻重复项
	string removeDuplicates(string S) {
		stack<char> stc;
		string Str;
		for (int i = 0; i < S.length(); i++)
		{
			if (stc.empty())
			{
				stc.push(S[i]);
			}
			else if (stc.top() == S[i])
			{
				stc.pop();
			}
			else
			{
				stc.push(S[i]);
			}
		}
		while (!stc.empty())
		{
			Str += stc.top();
			stc.pop();
		}
		std::reverse(Str.begin(), Str.end());
		return Str;
	}
#pragma endregion
#pragma region 1046. 最后一块石头的重量
	int lastStoneWeight(vector<int> & stones) {
		if (stones.size() == 1)
			return stones[0];
		sort(stones.rbegin(), stones.rend());
		while (stones[1] != 0)
		{
			if (stones[0] == stones[1])
			{
				stones[0] = 0;
				stones[1] = 0;
			}
			else
			{
				stones[0] -= stones[1];
				stones[1] = 0;
			}
			sort(stones.rbegin(), stones.rend());
		}
		return stones[0];

	}
#pragma endregion
#pragma region 1041. 困于环中的机器人
	bool isRobotBounded(string instructions) {
		int x = 0, y = 0;
		int i = 0;
		int dir[][2] = { {0,1},{1,0},{0,-1},{-1,0} };
		do
		{
			for (char ch : instructions)
			{
				if (ch == 'G')
				{
					x += dir[i][0];
					y += dir[i][1];
				}
				else if (ch == 'R')
				{
					i++;
					i %= 4;
				}
				else
					i = (i + 3) % 4;
			}
		} while (i != 0);
		return (x == 0 && y == 0);
	}
#pragma endregion
#pragma region 1029. 两地调度
	static bool cmp(vector<int> & a, vector<int> & b)
	{
		return a[2] < b[2];
	}
	int twoCitySchedCost(vector<vector<int>>& costs) {
		int size = costs.size() / 2;
		int res = 0;
		for (int i = 0; i < costs.size(); i++)
			costs[i].push_back(costs[i][0] - costs[i][1]);
		sort(costs.begin(), costs.end(), cmp);
		for (int i = 0; i < size; i++)
		{
			res += costs[i][0];
		}
		for (int i = size; i < costs.size(); i++)
		{
			res += costs[i][1];
		}
		return res;

	}
#pragma endregion
#pragma region 1018. 可被 5 整除的二进制前缀
	vector<bool> prefixesDivBy5(vector<int> & A) {
		vector<bool> res;
		int mod = 0;
		for (int i = 0; i < A.size(); i++)
		{
			mod = (mod << 1) % 5 + (A[i] == 1 ? 1 : 0);
			res.push_back(mod % 5 == 0);
		}
		return res;
	}
#pragma endregion
#pragma region 1128. 等价多米诺骨牌对的数量
	int numEquivDominoPairs(vector<vector<int>> & dominoes) {
		if (dominoes.size() < 2)	return 0;
		map<vector<int>, int> Map;
		for (vector<int> a : dominoes)
		{
			sort(a.begin(), a.end());
			Map[a]++;
		}
		int num = 0;
		for (auto a : Map)
		{
			if (a.second > 1)
				num += a.second * (a.second - 1) / 2;
		}
		return num;
	}
#pragma endregion
#pragma region 1122. 数组的相对排序
	vector<int> relativeSortArray(vector<int> & arr1, vector<int> & arr2) {
		int size = arr1.size();
		if (size <= 1)
			return arr1;
		vector<int> res;
		map<int, int> Map;
		for (int i : arr1)
			Map[i]++;
		for (int i = 0; i < arr2.size(); i++)
		{
			for (int j = 0; j < Map[arr2[i]]; j++)
			{
				res.push_back(arr2[i]);
				if (res.size() == size)
					return res;
			}
			Map[arr2[i]] = 0;

		}
		for (auto m : Map)
			for (int i = 0; i < m.second; i++)
				res.push_back(m.first);
		if (res.size() > size)
			res.erase(res.begin() + size, res.end());
		return res;
	}
#pragma endregion
#pragma region 1033. 移动石子直到连续
	vector<int> numMovesStones(int a, int b, int c) {
		vector<int> n, res;
		n = { a,b,c };
		sort(n.begin(), n.end());
		if (n[2] - n[0] == 2)res = { 0,0 };
		else if (n[2] - n[1] == 1 || n[1] - n[0] == 1)res = { 1,n[2] - n[0] - 2 };
		else if (n[2] - n[1] == 2 || n[1] - n[0] == 2)res = { 1,n[2] - n[0] - 2 };
		else res = { 2,n[2] - n[0] - 2 };
		return res;
	}
#pragma endregion
#pragma region 1022. 从根到叶的二进制数之和
	int ans = 0;
	void sum(TreeNode* node, int num)
	{
		if (node == NULL)return;
		num += node->val;
		if (node->left == NULL && node->right == NULL)
			ans += num;
		sum(node->left, num<<1);
		sum(node->right, num<<1);
	}
	int sumRootToLeaf(TreeNode* root) {
		if (root == NULL)return 0;
		sum(root, 0);
		return ans;
	}
#pragma endregion
#pragma region 1021. 删除最外层的括号
	string removeOuterParentheses(string S) {
		int left = 1;
		int right = 0;
		string res;
		for (int i = 1; i < S.size(); i++)
		{
			if (S[i] == '(')left++;
			else right++;
			if (right != left)	res.push_back(S[i]);
			else
			{
				i++;
				left = 1;
				right = 0;
			}
		}
		return res;
	}
#pragma endregion

#pragma region 203. 移除链表元素
	ListNode* removeElements(ListNode* head, int val) {
		while (head && head->val == val)
			head = head->next;
		if (head == NULL)
			return NULL;
		ListNode* Cur = head;
		while (Cur && Cur->next)
		{
			if (Cur->next->val == val)
				Cur->next = Cur->next->next;
			else
				Cur = Cur->next;
		}
		if (Cur->val == val)
			Cur = NULL;
		return head;
	}
#pragma endregion






	//	float media = 0.0;
	//	int pos = nums3.size();
	//	if (pos % 2 == 0) {
	//		media = static_cast<float>((nums3[pos / 2] + nums3[(pos / 2) - 1])) / 2;//如果长度为偶数取两数平均值
	//	}
	//	else {
	//		media = nums3[pos / 2];//奇数则取中间的数
	//	}
	//	return media;
	//}
#pragma region 跳动字节
	bool isinvaild(string t)
	{
		int temp = stoi(t);
		if (temp >= 0 && temp <= 255
			&& (t.size() == 1 || t[0] != '0'))
			return true;
		return false;
	}
	void dfs(vector<string>& ans, string s, string t, int tar)
	{
		if (tar == 3)
		{
			if (isinvaild(t))
				ans.push_back(s + t);
			return;
		}

		for (int i = 1; i < 4 && i < t.size(); i++)
		{
			string curr = t.substr(0, i);
			if (isinvaild(curr))
			{
				cout << t << endl;
				dfs(ans, s + curr + '.', t.substr(i), tar + 1);
			}

		}
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		string t;
		dfs(ans, t, s, 0);
		return ans;
	}
#pragma endregion


};

class Solution_M
{
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)return head;
		ListNode* p = head, * q = head->next, * res = head;
		while (true)
		{
			p->next = q->next;
			q->next = p;
			if (q->next == head)head = q;
			p = p->next;
			if (!p || !p->next)return head;
			q = p->next;
			res->next = q;
			res = p;
		}
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int>ans;
		stack<TreeNode*>nodeStack;
		nodeStack.push(root);
		while (!nodeStack.empty())
		{
			TreeNode* node = nodeStack.top();
			nodeStack.pop();
			if (node)ans.push_back(node->val);
			else continue;
			if (node->left)nodeStack.push(node->left);
			if (node->right)nodeStack.push(node->right);
		}
		return ans;
	}
	int findDuplicate(vector<int>& nums) {
		int fast = 0, slow = 0;
		while (true)
		{
			fast = nums[nums[fast]];
			slow = nums[slow];
			if (slow == fast) {
				fast = 0;
				while (nums[slow] != nums[fast])
				{
					fast = nums[fast];
					slow = nums[slow];
				}
				return nums[slow];
			}
		}
	}
	int minimumTotal(vector<vector<int>>& triangle) {
		for (int i = triangle.size() - 2; i >= 0; i--)
		{
			for (int j = 0; j < triangle[0].size(); j++)
			{
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);

			}

		}
		return triangle[0][0];
	}
	void setZeroes(vector<vector<int>>& matrix) {
		set<int>row;
		set<int>col;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (0 == matrix[i][j])
				{
					row.insert(i);
					col.insert(j);
				}
			}
		}
		for (int i : row)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				matrix[i][j] = 0;
			}
		}
		for (int i : col)
		{
			for (int j = 0; j < matrix.size(); j++)
			{
				matrix[j][i] = 0;
			}
		}
	}
	vector<int> constructArray(int n, int k) {
		vector<int>res;
		int i = 1;
		while (i <= (n - k))
		{
			res.push_back(i);
			i++;
		}
		int j = 0;
		while ((i + j) <= (n - j))
		{
			if ((i + j) == (n - j))
			{
				res.push_back(n - j);
				break;
			}
			res.push_back(n - j);
			res.push_back(i + j);
			j++;
		}
		return res;
	}
};

class MyHashSet {
public:
	/** Initialize your data structure here. */
	MyHashSet() {

	}

	void add(int key) {
		HashSet.insert(key);
	}

	void remove(int key) {
		HashSet.erase(key);
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		if (HashSet.find(key) != HashSet.end())return true;
		else return false;
	}
private:
	set<int> HashSet;
};
class MyQueue {
public:
	stack<int> s1, s2;
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
		s2.push(x);
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int a = s2.top();
		s2.pop();
		return a;
	}

	/** Get the front element. */
	int peek() {
		return s2.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s2.empty();
	}

};

class MinStack {
public:

	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		if (Stack.empty() && minStack.empty())
		{
			minStack.push(x);
		}
		else
		{
			minStack.push((x < minStack.top()) ? x : minStack.top());
		}
		Stack.push(x);
	}

	void pop() {
		Stack.pop();
		minStack.pop();
	}

	int top() {
		return Stack.top();
	}

	int getMin() {
		return minStack.top();
	}
private:
	stack<int> Stack;
	stack<int> minStack;
};

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		data.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		count = data.size() - 1;
		for (int i = 0; i < count; i++)
		{
			data.push(data.front());
			data.pop();
		}
		int res = data.front();
		data.pop();
		return res;
	}

	/** Get the top element. */
	int top() {
		return data.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return data.empty();
	}
private:
	queue<int> data;
	int count = 0;
};

class NumArray {
public:
	NumArray(vector<int> nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			numsCache.push_back(nums[i]);
		}
	}

	int sumRange(int i, int j) {
		int res = 0;
		for (int a = i; a <= j; a++)
		{
			res += numsCache[a];
		}
		return res;
	}
private:
	vector<int>numsCache;
};


class MyHashMap {
public:
	/** Initialize your data structure here. */
	MyHashMap() {
		for (int i = 0; i < 1000000; i++)
		{
			Data[i] = -1;
		}
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		Data[key] = value;
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		return Data[key];
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		Data[key] = -1;
	}
private:
	int Data[1000000];
};


static const auto _ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
class Solution_Best
{
public:
	int maxSubArray(vector<int>& nums) {
		int maxsum = INT_MIN, sum = 0;
		if (nums.size() == 1)return nums[0];
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (sum > maxsum) {
				maxsum = sum;
			}
			if (sum < 0) {
				sum = 0;
			}
		}
		return maxsum;
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

//ListNode* Reversed(ListNode *node)
//{
//	if (node == NULL) return NULL;
//	if (node->next == NULL) return node;
//	ListNode * n = Reversed(node->next);
//	if (n != NULL) {
//		n->next = node;
//		node->next = NULL;
//	}
//	return node;
//}
ListNode* Head = nullptr;
void Reversed2(ListNode* node, ListNode* PreNode = NULL)
{
	if (node->next != NULL)
	{
		Head = node->next;//Mark List node Header
		Reversed2(node->next, node);
	}
	node->next = PreNode;
}

class RecentCounter {
public:
	RecentCounter() {

	}

	int ping(int t) {
		time.push_back(t);
		for (int i = 0; i < time.size(); i++)
		{
			if (time[i] >= t - 3000)return time.size() - i;
		}
		return time.size();
	}
	int ping2(int t)
	{
		time2.push(t);
		while (t - time2.front() > 3000 && !time2.empty())
		{
			time2.pop();
		}
		return time2.size();
	}
private:
	vector<int> time;
	queue<int>time2;
};

int main()
{
	/*
	[2 42 38 0 43 21 5 7 12 12 13 23 24 24 27 29 30 31 33 48]
	[2,42,38,0,43,21,5,7,12,12,13,23,24,24,27,29,30,31,33,48]
	*/
	Solution_E s;
	vector<vector<int>> domin{
		{1,2},
		{2,1},
		{3,4},
		{5,6},
		{7,8},
		{1,2},
	};
	vector<int>arr1 = { 2, 21, 43, 38, 0, 42, 33, 7, 24, 13, 12, 27, 12, 24, 5, 23, 29, 48, 30, 31 };
	vector<int>arr2 = { 2, 42, 38, 0, 43, 21 };
	ListNode* head=	new ListNode(1,new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7, new ListNode(6))))))));
	ListNode* res = s.removeElements(head,6);
	while (res!=NULL)
	{
		cout << res->val<<" ";
	}
	cout << endl;
	cin.get();
	return 0;
}