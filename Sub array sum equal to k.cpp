#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    int k;  // Target value K
    cin>>k;
    int cunt = 0;
    int prefixSum = 0; // Here I will store the prefixSum and I will match it with target => k

    unordered_map<int, int>previousSum;  //Here I will put all the prefixSum as key and I will count the frequency as value.

    for(int i=0; i<n; i++)
    {
        prefixSum+=a[i];  // Here I store first value of array => a[i]

        if(prefixSum==k)  // Here I am checking that my prefixSum is equal to the target k or not. If equal then increment the frequency.
        {
            cunt++;  // Here I incrementing the cunt frequency
        }

        if(previousSum.find(prefixSum-k)!= previousSum.end()) // here I try to find every time that in my previousSum array new value(prefixSum - k) is available or not
        {
            cunt+=previousSum[prefixSum-k];  // Here I add the value of previousSum[prefixSum-k] with cunt.
        }

        previousSum[prefixSum]++;  // Here store the prefixSum and count the frequency in previousSum array.
    }

    cout<<cunt;

    return 0;
}
