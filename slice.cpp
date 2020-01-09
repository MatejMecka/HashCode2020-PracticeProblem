#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> slices;
vector<int> sortedSlices;
vector<int> pizzas;

int greedy(int maxi){
	int counter = maxi;
		for(int i=0; i < sortedSlices.size(); i++){
			//cout << sortedSlices[i] << endl;
			if(counter - sortedSlices[i] > 0 && sortedSlices[i] != -1){
				counter-=sortedSlices[i];
				pizzas.push_back(sortedSlices[i]);
				sortedSlices[i]=-1;
			}
		}
	
}

int main(){
	freopen("e_also_big.in","r",stdin);
	freopen("nesh_e.out","w",stdout);
	int maxSlices, types = 0;
	cin >> maxSlices >> types;
	for(int i=0; i < types; i++){
		int temp;
		cin >> temp;
		slices.push_back(temp);
	}
	sortedSlices = slices;

	sort(sortedSlices.begin(), sortedSlices.end());
	reverse(sortedSlices.begin(), sortedSlices.end());
	greedy(maxSlices);

	cout << pizzas.size() << endl;
	for(int i=0; i < pizzas.size(); i++){
		vector<int>::iterator it = find(slices.begin(), slices.end(), pizzas[i]);
		int index = distance(slices.begin(), it);		
		cout << index << ' ';
	}

}