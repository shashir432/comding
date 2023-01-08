#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//using recursion
//int knapsack(int wt[],int val[],int n,int w){
    // base case
//	if(n==0 || w==0){
//		return 0;
//	}
    // choice diagram
//	if(wt[0]<=w){
//		return max(knapsack(wt+1,val+1,n-1,w-wt[0])+val[0] , knapsack(wt+1,val+1,n-1,w));
//	}
//	else{
//		return knapsack(wt+1,val+1,n-1,w);
//	}
//}

//or 
//using recursion
int knapsack(int wt[],int val[],int n,int w){
	//base case
	if(n==0 || w==0){
		return 0;
	}
	//choice diagram
	if(wt[n-1]<=w){
		return max(knapsack(wt,val,n-1,w-wt[n-1])+val[n-1] , knapsack(wt,val,n-1,w));
	}
	else{
		return knapsack(wt,val,n-1,w);
	}
}

//using dynamic programming -> bottom up approach
int knapsackdp(int wt[],int val[],int n,int w){
	int dp[n+1][w+1];
	memset(dp,0,sizeof(dp));
//	for(int i=0;i<n+1;i++)
//	dp[i][0]=0;
//	for(int j=0;j<w+1;j++)
//	dp[0][j]=0;
    for(int i=1;i<n+1;i++){  //traversing thru items
    	for(int j=1;j<w+1;j++){  //capacity of knapsack
    		if(wt[i-1]<=w){
    			dp[i][j]=max(dp[i-1][j-wt[i-1]]+val[i-1],dp[i-1][j]);
			}
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	//recursion ka 'n' idhr 'i' hai ar 'w' idhr 'j' h
	return dp[n][w];
}

//using memoization -> top down approach
int knapsackk(int wt[],int val[],int n,int w,int ans[102][1002]){
	//base case
	if(n==0 || w==0)
	return 0;
	if(ans[n][w]!=-1)
	return ans[n][w];
	//choice diagram
	if(wt[n-1]<=w){
		ans[n][w]=max(val[n-1]+knapsackk(wt,val,n-1,w-wt[n-1],ans),knapsackk(wt,val,n-1,w,ans));
	}
	else{
		ans[n][w]=knapsackk(wt,val,n-1,w,ans);
	}
	return ans[n][w];
}

//to find if there is any subset whose sum is k or not
//comparing this prblm with knapsack, we get
//capacity of knapsack is sum=k here
//waha wt ar val array tha yaha bs ek hi arr hai to ise wt[] array ki equivalent manenge
//idhr val[] jaisa kuch nhi rhega
//waha max lete the but yaha dp box me true/false fill krna h 
//ar true/false me maximum to kuch hoga nhi isliye yaha ||(OR) operator use krenge
//rest code remains same
bool subsetsum(int arr[],int n, int k){
	bool dp[n+1][k+1];
	//initialization for 1st row & col
	for(int i=0;i<n+1;i++)
	dp[i][0]=true;
	for(int j=1;j<k+1;j++)
	dp[0][j]=false;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<k+1;j++){
			if(arr[i-1]<=k){
				dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
			}
			else 
			dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][k];
}

int main(){
	int n=4;
	int wt[]={1,3,4,7};
	int val[]={3,5,7,8};
	int w=7;
	//below 2 lines are for memoization
	int ans[102][1002];
    memset(ans,-1,sizeof(ans));
    int arr[]={2,3,7,8,10};
    cout<<subsetsum(arr,5,12);
	//cout<<knapsackk(wt,val,n,w,ans);
}

