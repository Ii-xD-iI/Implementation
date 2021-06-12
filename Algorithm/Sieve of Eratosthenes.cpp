vector<int> SieveOfEratosthenes(int N) {// 1 not a prime
    const int Size= 1e4+7;
    int prime[Size] = {};
    for(long long i = 2; i <= N; ++i) 
        if(not prime[i] and i*i <= N) 
            for(long long j = i*i; j <= N; j += i) 
                prime[j] = 1;    
    vector<int> Primes;
    for(int i = 2; i <= N; ++i) 
        if(! prime[i]) Primes.push_back(i);
    return Primes;
}
