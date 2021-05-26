class SegTree {// Yoavsh orz
	public:

		long long size, n;
		vector<long long> Sums;
		
		SegTree(int _) :n(_){
			size = 1;
			while(size < n) size *=2;
		
			Sums.assign(2*size, 0ll);
		}

		
		void Build(vector<int> &a, int Node, int Lx, int Rx) {
			if(Rx - Lx == 1){//leaf node
				if(Lx < (int)a.size()) {
					Sums[Node] = a[Lx];		
				}return;
			}
			int Mid = ((Lx + Rx) >> 1);

			Build(a, 2*Node+1, Lx, Mid);
			Build(a, 2*Node +2, Mid , Rx);
		
			Sums[Node] = (Sums[2*Node+1] + Sums[2*Node+2]);
		}

		void Build(vector<int> &a) {
			//leaf nodes --> elements of the array
			Build(a, 0, 0, size);
		}

		void Set(int I, int V, int X, int Lx, int Rx) {
			
			if(Rx - Lx == 1) {
				Sums[X] = V;
				return;
			}
			int Mid = ((Lx + Rx)>>1);

			if(I < Mid) //go left
				Set(I, V, 2*X+1, Lx, Mid);
			
			else Set(I, V, 2*X+2, Mid, Rx);
		
			Sums[X] = (Sums[2*X+1] + Sums[2*X+2]);
		}

		void Set(int I, int Value) {
			Set(I, Value, 0, 0, size);//index, val, root, 0 --> size
		}

		long long Sum(int L, int R, int X, int Lx, int Rx) {//Val of that seg
			if(Lx >= R or Rx <= L) return 0;

			if(Lx >= L and Rx <= R) return Sums[X];

			int Mid = ((Lx + Rx)>>1);

			long long Lsum = Sum(L, R, 2*X+1, Lx, Mid);
			long long Rsum = Sum(L, R, 2*X+2, Mid, Rx);
			return (Lsum + Rsum);	
		}

		long long Sum(int L, int R) {
			return Sum(L, R, 0, 0, size);
		}
};
/*
05/26/2021 mm/dd/yyyy

*/
