#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_edges(int N, int &m, int &n)
{
	m=1;
	while(m*m<N)
		m++;
	int sqr_est = m;
	if(m*m==N){
		n=m;
		return;
	} else {
		while(m<=N){
			n = sqr_est-1;
			while(m*n>N){
				n--;
			}
			if(m*n==N) return;
			else m++;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> data(N);

	for(int i=0; i<N; i++){
		cin >> data[i];
	}

	sort(data.begin(), data.end());
	int index = N-1;

	int m, n;
	find_edges(N, m, n);

	vector<int> reshaped(N);
	int col=0, row=0;
	int n_r = n-1, m_r = m-1;
	for(int i=0; i<N; i++){
		while(col<=n_r && index!=-1){
			reshaped[row*n+col++] = data[index--];
		}
		col--; row++;
		while(row<=m_r && index!=-1){
			reshaped[(row++)*n+col] = data[index--];
		}
		col--; row--;
		while(col>=n-n_r-1 && index!=-1){
			reshaped[row*n+col--] = data[index--];
		}
		col++; row--;
		while(row>m-m_r-1 && index!=-1){
			reshaped[(row--)*n+col] = data[index--];
		}
		col++; row++;
		m_r--;
		n_r--;
	}

	for(int i=0; i<m; i++){
		for(int j=0; j<n-1; j++)
			cout << reshaped[i*n+j] << ' ';
		cout << reshaped[i*n+n-1] << endl;
	}

	return 0;
}