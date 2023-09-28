class Solution {
public:
	int search(const vector<int>& a, int target, function<bool(int, int)>  Operator = less_equal<int>()) {

		int left = -1;
		int right = (int)a.size();
	
		//for (int mid = left + (right - left) / 2; 2 != right - left + 1;  mid = left + (right - left) / 2) { // good!
			
			while(2 != right - left + 1){
			int mid = left + (right - left) / 2;
			//  a[mid] <= target <--> Operator( a[mid],target )
			(Operator( a[mid],target )) ?  left = mid : right = mid;

		}

		if(left == -1){return -1;} // обработка случая, когда left ни разу не сдвинулся, например: [5] -5
		return (a[left] != target) ? -1 : left; // делаем вывод, что для a[right] записывается инвариант из правдивой ветки условного оператора 
	}
};
