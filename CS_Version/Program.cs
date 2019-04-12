using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;

namespace CS_Version
{
    class Program
    {
        static int Main()
        {
            TreeNode p1 = new TreeNode(1);
            p1.left = new TreeNode(2);
            TreeNode p2 = new TreeNode(1);
            p2.left = null;
            p2.right = new TreeNode(2);
            SolutionE solution = new SolutionE();
            int[] nums = { 1, 1, 0, 1, 1, 1 };
            Console.WriteLine(
            solution.LengthOfLongestSubstring("abcabcbb"));
            Console.ReadKey();
            return 0;
        }
    }

}
