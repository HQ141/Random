#include <stdio.h>
#include<string.h>
int subsequence( char*n , char*m, int length, int length2,int i,int j){
	if (length2 == j)
		return 1;
	if (i >= length) {
		return 0;
	}
	if (n[i] == m[j]) {
		return subsequence(n, m, length, length2, ++i, ++j);
	}
	return subsequence(n, m, length, length2, ++i,0);
}
int main()
{
	char word[50], word2[100];
	int n, m; 
	printf("Enter any word: ");
	scanf(" %s", &word);
	
	printf("Enter any other word to check subsequence of your first word: ");
	scanf(" %s", &word2);
	
	n= strlen(word);
	m= strlen(word2);
	
	if(subsequence(word, word2, n, m,0,0))
	{
		printf("Your first word is subsequent of the other word!!");
	}
	else
	{
		printf("Your first word is not subsequent of the other word!!");
	}
	getchar();
}

