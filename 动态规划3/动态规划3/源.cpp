#include<stdio.h>
int dp[100][100];
int getAns(int k, int l){
	int i, j, t, sum = 0;
	for (i = 0; i<k; i++){
		dp[1][i] = 1;
	}
	for (i = 2; i <= l; i++){
		for (j = 0; j<k; j++){
			for (t = 0; t<k; t++){
				if (t != j - 1 && t != j + 1){
					dp[i][j] += dp[i - 1][t];
				}
			}
		}
		dp[i][j] %= 100000008;
	}
	for (j = 1; j<k; j++){
		sum = sum + dp[l][j];
		sum %= 100000008;
	}
	return sum;
}
int main(){
	int k, l;
	scanf("%d%d", &k, &l);
	printf("%d\n", getAns(k, l));
	return 0;
}
