    // A Dynamic Programming based solution for 0-1 Knapsack problem
    #include <iostream>
    using namespace std;
    #include <cstdlib>
	#include <ctime>
	#include <cmath>
     
    // A utility function that returns maximum of two integers
	int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
     
    // Returns the maximum value that can be put in a knapsack of capacity W
    int knapSack(int W, int wt[], int val[], int n, int l)
    {	
        int i, w;
        int K[n + 1][W + 1];
        // Build table K[][] in bottom up manner
    for (int k=0; k<=l; k++){
        for (i = 0; i <= n; i++)
        {
            for (w = 0; w <= W; w++)
            {
                if (i == 0 || w == 0)
                    K[i][w] = 0;
                else if (wt[i - 1] <= w)
                    K[i][w]= max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                else
                    K[i][w] = K[i - 1][w];
            }
        }
	}
        return K[n][W];
    }
    
    int random(int r){
	
	int num = rand() % r ;
	return num;
	}

    int main()
    {
        cout << "Input how many thing in the bag : ";
        int n, W, l, c, knaptemp, sum;
        cin >> n;
        int val[n], wt[n];
        for (int i = 0; i < n; i++)
        {
        cout<<"Input the value and the weight-" << i << "\n";
        cout<< "Value  : "; cin >> val[i]; 
        cout<< "Weight    : "; cin >> wt[i]; cout<< "\n";
        }
        
        for(int z = 0; z < n ; z++){
        	sum += val[z];
		}

        cout << "Input Maximum Weight ";
        cin >> W;
        cout << "How Much Iteration ";
        cin >> l;    
        
        knaptemp = knapSack(W, wt, val, n,l);
        cout<<knaptemp<<endl;
        for (c=0; c<l; c++){
        int knapsack = knapSack(W, wt, val, n,l);
        if(knapsack > sum ) {
        	knapsack = knapsack-random(W);
		} else {
        if (c%2 == 0){
        	knapsack = knapsack-random(W);
		}
		else {
			knapsack = knapsack+random(W);
		}
		if(knapsack > knaptemp){
			knaptemp = knapsack;
		}
		}
		cout <<abs(knapsack)<<"     "<<abs(knaptemp)<<endl;
	
		}
  return 0;
    }
