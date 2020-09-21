#include <bits/stdc++.h>


#include <stdio.h>
#include <string.h>
#define D 2

int main( void )
{
	char s[(int) 1e5];
	char t[(int) 1e5];
	int i=0;
	int tmp;

	char resp[50] = "Yes";

	while( scanf("%s %s",s,t) != EOF )
	{

		strcpy( resp, "Yes");
		tmp = 0;

		t[ strlen(t) ] = '\0';

		for( i=0; i < strlen(s); i++ ){
			//if( D>0 ) printf("To Resolve %c - SUBSTRING = %s\n",s[i],&t[tmp]);
			if( strchr( &t[tmp],s[i] ) != NULL ){
				tmp = (strchr( &t[tmp],s[i] ) - t)+1;
			}
			else{
				strcpy( resp, "No");
				break;
			}

		}

		printf("%s\n",resp);
	}





	return 0;
}
