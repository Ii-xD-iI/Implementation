template<typename T>
	class prefixSums { //SlavicG orz
		public:
			int n;	
			vector<T> Sums; 

			prefixSums (const vector<T> &v) {
				n = (int)v.size();
				Sums.resize(n);
				Sums[0] = v[0];

				for (int i=1; i < n; ++i) Sums[i] = v[i] + Sums[i-1]; 
			}

			T Query (int L, int R) {//assuming that you've passed 0 based range
				T Ans = Sums[R];
				if(L) 
					Ans -= Sums[L-1];

				return Ans;
			}
};
