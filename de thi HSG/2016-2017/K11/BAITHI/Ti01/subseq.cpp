#include <fstream>
using namespace std;
int main()
{
    long a[10001];
    long n, k, dem, dem_max;
    ifstream fi ("subseq.inp");
    ofstream fo ("subseq.out");
    
    fi>>n>>k;
    if (k==1) dem_max = n;
    else
    {
    	for (long i = 0; i<n; i++) fi>>a[i];
    	a[n] = k+1;
    
    	dem_max = 0;
    	dem = 0;
    	for (long i = 0; i<=n; i++)
    	if ((a[i] % k ) == 0) dem++;
   		else
    	{
    	if (dem > dem_max)
    	{
    		dem_max = dem;
    		dem = 0;
    	}
    	}
    }
    
    fo<<dem_max;
    
    fi.close();
    fo.close();
}
