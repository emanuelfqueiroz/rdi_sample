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

namespace Problem3
{
    public class Program
    {
        public static string isPalindromePermutation(string s)
        {
			int len = s.Length;
			if (len <= 1) return "YES";

			Dictionary<char, int> dc = new Dictionary<char, int>();
			bool oddCharFound = false;

			foreach (char c in s)
			{
				if (!dc.ContainsKey(c))
				{
					dc.Add(c, 1);
				}
				else
				{
					dc[c]++;
				}
			}

			foreach (var keyvalue in dc)
			{
				if (keyvalue.Value % 2 == 1)
				{
					if (!oddCharFound)
						oddCharFound = true;
					else
						return "NO";
				}
			}

			return "YES";
		}

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter("OUTPUT3.TXT", true);

            string s = Console.ReadLine();

            textWriter.WriteLine(isPalindromePermutation(s));

            textWriter.Flush();
            textWriter.Close();
        }

    }
}
