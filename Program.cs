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

class Result
{

    /*
     * Complete the 'encryption' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static string encryption(string s)
    {
        s = s.Replace(" ", "");
        int L = s.Length;

        int rows = (int)Math.Floor(Math.Sqrt(L));
        int columns = (int)Math.Ceiling(Math.Sqrt(L));
        if (rows * columns < L) rows++;

        var symb = new System.Text.StringBuilder();

        for (int col = 0; col < columns; col++)
        {
            for (int row = 0; row < rows; row++)
            {
                int index = row * columns + col;
                if (index < L)
                {
                    symb.Append(s[index]);
                }

            }
            if (col != columns - 1) symb.Append(' ');
        }
        return symb.ToString();
    }

}

class Solution
{
    public static void Main(string[] args)
    {

        Console.Write("enter your text: ");
        string s = Console.ReadLine();

        string result = Result.encryption(s);

        Console.WriteLine("encrypted text:");
        Console.WriteLine(result);

    }
}
