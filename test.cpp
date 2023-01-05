#include<bits/stdc++.h>
using namespace std;

int maxevents(int start[], int end[], int N){
	priority_queue<int,vector<int>, greater<int>>pq;
	vector<pair<int,int>>temp(N);
	for(int i=0;i<N;i++){
		temp[i].first=start[i];
		temp[i].second=end[i];

	}
	sort(temp.begin(),temp.end());
	int idx=0;
	int res=0;
	int d=0;
	while(pq.size()>0 || idx<N){
		if(pq.size()==0){
			d=temp[idx].first;
		}
		while(idx<N && temp[idx].first <=d){
			pq.push(temp[idx++].second);
		}
		pq.pop();
		++res;
		++d;
		while(pq.size()>0&&pq.top()<d){
			pq.pop();
		}
	}
	return res;
}

int main(){
	int N;
	cin>>N;
	int start[N];
	for(int i=0;i<N;i++){
		cin>>start[i];
	}
	int end[N];
	for(int i=0;i<N;i++){
		cin>>end[i];
	}
	int result;
	result = maxevents(start, end, N);
	cout<<result;
}