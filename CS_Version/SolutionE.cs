using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CS_Version
{
    public class SolutionE
    {
        /// <summary>
        /// 1. 两数之和
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="target"></param>
        /// <returns></returns>
        public int[] TwoSum(int[] nums, int target)
        {
            int[] res = new int[2];
            for (int i = 0; i < nums.Length; i++)
            {
                res[0] = i;
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (target - nums[i] == nums[j])
                    {
                        res[1] = j;
                        return res;
                    }
                }
                res[0] = 0;
            }
            return res;
        }
        /// <summary>
        /// 2. 两数相加
        /// </summary>
        /// <param name="l1"></param>
        /// <param name="l2"></param>
        /// <returns></returns>
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            ListNode head = new ListNode(0);
            ListNode p = l1, q = l2, current = head;
            int carry = 0;
            while (p != null || q != null)
            {
                int x = (p != null) ? p.val : 0;
                int y = (q != null) ? q.val : 0;
                int sum = carry + x + y;
                carry = sum / 10;
                current.next = new ListNode(sum % 10);
                current = current.next;
                if (p != null) p = p.next;
                if (q != null) q = q.next;
            }
            if (carry > 0)
            {
                current.next = new ListNode(carry);
            }
            return head.next;
        }
        /// <summary>
        /// 3. 无重复字符的最长子串
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public int LengthOfLongestSubstring(string s)
        {
            //滑动窗口 方案

            int n = s.Length;
            HashSet<char> hashset = new HashSet<char>();
            int ans = 0, i = 0, j = 0;
            while (i < n && j < n)
            {
                if (!hashset.Contains(s[j]))
                {
                    hashset.Add(s[j++]);
                    ans = Math.Max(ans, j - i);
                }
                else
                    hashset.Remove(s[i++]);
            }
            return ans;
        }
        /// <summary>
        /// 7. 整数反转
        /// </summary>
        /// <param name="x"></param>
        /// <returns></returns>
        public int Reverse(int x)
        {
            int res = 0;
            bool m = false;
            m = x < 0;
            while (x != 0)
            {
                int pop = x % 10;
                x /= 10;
                if (res > int.MaxValue / 10 || (res == int.MaxValue / 10 && pop > 7)) return 0;
                if (res < int.MinValue / 10 || (res == int.MinValue / 10 && pop < -8)) return 0;
                res = res * 10 + pop;
            }
            return res;
        }
        /// <summary>
        /// 6. Z 字形变换
        /// </summary>
        /// <param name="s"></param>
        /// <param name="numRows"></param>
        /// <returns></returns>
        public string Convert(string s, int numRows)
        {
            if (numRows == 1) return s;
            List<StringBuilder> rows = new List<StringBuilder>();
            for (int i = 0; i < Math.Min(numRows, s.Length); i++)
            {
                rows.Add(new StringBuilder());
            }
            int curRow = 0;
            bool goingDown = false;
            foreach (char c in s)
            {
                rows[curRow].Append(c);
                if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
                curRow += goingDown ? 1 : -1;
            }
            StringBuilder res = new StringBuilder();
            foreach (StringBuilder build in rows)
            {
                res.Append(build);
            }
            return res.ToString();
        }
        /// <summary>
        /// 9. 回文数
        /// </summary>
        /// <param name="x"></param>
        /// <returns></returns>
        public bool IsPalindrome(int x)
        {
            if (x < 0 || (x % 10 == 0 && x != 0)) return false;
            int Num = 0;
            while (x > Num)
            {
                Num = Num * 10 + x % 10;
                x /= 10;
            }

            return x == Num || x == Num / 10;
        }
        /// <summary>
        /// 14. 最长公共前缀
        /// </summary>
        /// <param name="strs"></param>
        /// <returns></returns>
        public string LongestCommonPrefix(string[] strs)
        {
            if (strs.Length == 0) return string.Empty;
            for (int i = 0; i < strs[0].Length; i++)
            {
                char mark = strs[0][i];
                foreach (string str in strs)
                {
                    if (i == str.Length || str[i] != mark)
                        return strs[0].Substring(0, i);
                }
            }
            return strs[0];
        }
        /// <summary>
        /// 20. 有效的括号
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public bool IsValid(string s)
        {
            if (s.Length % 2 != 0) return false;
            Stack<char> stc = new Stack<char>();
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == '(') stc.Push(')');
                else if (s[i] == '{') stc.Push('}');
                else if (s[i] == '[') stc.Push(']');
                else if (stc == null)
                {
                    return false;
                }
            }
            return true;
        }
        /// <summary>
        /// 100. 相同的树
        /// </summary>
        /// <param name="p"></param>
        /// <param name="q"></param>
        /// <returns></returns>
        public bool IsSameTree(TreeNode p, TreeNode q)
        {
            if (p == null && q == null)
                return true;
            if (p != null && q != null && p.val == q.val)
                return IsSameTree(p.left, q.left) &&
                 IsSameTree(p.right, q.right);
            else
                return false;
        }
        /// <summary>
        /// 202. 快乐数
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public bool IsHappy(int n)
        {
            int count = 0;
            while (n != 0)
            {
                count += (int)Math.Pow(n % 10, 2);
                n /= 10;
            }
            if (count == 1)
                return true;
            else if (count == 4)
                return false;
            else
                return IsHappy(count);
        }
        /// <summary>
        /// 242. 有效的字母异位词
        /// </summary>
        /// <param name="s"></param>
        /// <param name="t"></param>
        /// <returns></returns>
        public bool IsAnagram(string s, string t)
        {

            if (s.Length != t.Length) return false;
            char[] ns = s.ToArray();
            char[] ts = t.ToArray();
            Array.Sort(ns);
            Array.Sort(ts);
            for (int i = 0; i < s.Length; i++)
                if (ns[i] != ts[i]) return false;
            return true;
        }
        /// <summary>
        /// 485. 最大连续1的个数
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int FindMaxConsecutiveOnes(int[] nums)
        {
            int count = 0;
            int max = 0;
            foreach (int item in nums)
            {
                switch (item)
                {
                    case 1:
                        count++;
                        break;
                    case 0:
                        max = Math.Max(max, count);
                        count = 0;
                        break;
                }
            }
            return Math.Max(max, count);
        }
        /// <summary>
        /// 520. 检测大写字母
        /// </summary>
        /// <param name="word"></param>
        /// <returns></returns>
        public bool DetectCapitalUse(string word)
        {
            if (word.Length == 0) return false;
            int count = 0;
            foreach (char c in word)
            {
                if (char.IsUpper(c)) count++;
            }
            return count == 0 || count == word.Length || (count == 1 && char.IsUpper(word[0]));
        }
        /// <summary>
        /// 538. 把二叉搜索树转换为累加树
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public int preNum = 0;
        public TreeNode ConvertBST(TreeNode root)
        {
            traversal(root);
            return root;
        }
        public void traversal(TreeNode root)
        {
            if (root == null) return;
            traversal(root.right);
            int value = root.val;
            root.val += preNum;
            preNum += value;
            traversal(root.left);
        }

    }
    /// <summary>
    /// 303. 区域和检索 - 数组不可变
    /// </summary>
    public class NumArray
    {

        public NumArray(int[] nums)
        {
            this.nums = nums;
        }

        public int SumRange(int i, int j)
        {
            int count = 0;
            for (int l = i; l <= j; l++)
            {
                count += this.nums[l];
            }
            return count;
        }
        private int[] nums;

    }

}
