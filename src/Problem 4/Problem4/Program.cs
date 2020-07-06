using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;


namespace Problem4
{
    public class Solution
    {
        static int[] coins = { 1, 5, 10, 20, 25, 50 };

        public static int getNumberOfCombinations(int amount)
        {
            return getNumberOfCombinations(amount,  0);
        }

        static int getNumberOfCombinations(int amount , int checkFromIndex)
        {
            if (amount == 0)
                return 1;
            else if (amount < 0 || coins.Length == checkFromIndex)
                return 0;
            else
            {
                int withFirstCoin = Solution.getNumberOfCombinations(amount - coins[checkFromIndex],  checkFromIndex);
                int withoutFirstCoin = Solution.getNumberOfCombinations(amount,  checkFromIndex + 1);
                return withFirstCoin + withoutFirstCoin;
            }
        }
        public static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter("OUTPUT4.TXT", true);

            int n = Convert.ToInt32(Console.ReadLine().Trim());

            int result = getNumberOfCombinations(n);
            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }

}
