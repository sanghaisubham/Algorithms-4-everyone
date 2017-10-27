/*Author:SUBHAM SANGHAI
LCS Problem Statement: Given two sequences, find the length of longest subsequence
present in both of them. A subsequence is a sequence that appears in the same relative order,
but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”*/
	#include<bits/stdc++.h>
	using namespace std;
    	string lcsString (string str1, string str2, int lcsMatrix[100][100])
	{
		int i = str1.length(),j = str2.length();
		string lcs="";
		while(i > 0  && j > 0)
		{
			if(str1[i-1] == str2[j-1])
			{
				lcs=lcs+str1[i-1];
				i--;
				j--;
			}
			else if(lcsMatrix[i-1][j] > lcsMatrix[i][j-1])
			{
				i--;
			}
			else
			{
				j--;
			}
		}
		reverse(lcs.begin(),lcs.end());
		return lcs;
	}
	string getLCS(string str1, string str2)
 	{

		//At least one string is null
		if(str1 == "" || str2 =="")
			return "";

		//At least one string is empty
		if(str1.length() == 0 || str2.length() == 0)
			return "";

		string arr1 = str1;
		string arr2 = str2;

		//lcsMatrix[i][j]  = LCS of first i elements of arr1 and first j characters of arr2
		int lcsMatrix[100][100];

		for(int i = 0; i < arr1.length() + 1; i++)
			lcsMatrix[i][0] = 0;
		for(int j = 1; j < arr2.length() + 1; j++)
			lcsMatrix[0][j] = 0;
		for(int i = 1; i < arr1.length() + 1; i++)
		 {
			for(int j = 1; j < arr2.length() + 1; j++)
			{
				if(arr1[i-1]==arr2[j-1])
				{
					lcsMatrix[i][j] = lcsMatrix[i-1][j-1] + 1;
				}
				else
				{
					lcsMatrix[i][j] = lcsMatrix[i-1][j] > lcsMatrix[i][j-1] ? lcsMatrix[i-1][j] : lcsMatrix[i][j-1];
				}
			}
		}
		return lcsString(str1, str2, lcsMatrix);
	}
	int main()
	{
		string str1 = "DSGSHSRGSRHTRD";
		string str2 = "DATRGAGTSHS";
		string lcs = getLCS(str1, str2);

		//Print LCS
		if(lcs != "")
		{
			cout<<"String 1: "<<str1<<"\n";
			cout<<"String 2: "<<str2<<"\n";
			cout<<"LCS: "<<lcs<<"\n";
			cout<<"LCS length: "<<lcs.length()<<"\n";
		}
	}

