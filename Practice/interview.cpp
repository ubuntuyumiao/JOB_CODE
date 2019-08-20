/*---------------华为 顺时针旋转m次矩阵 -----------------
#include <iostream>
#include<vector>
using namespace std;

int main(void)
{

    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int m;
        vector<vector<int>> matrix;
        for(int row=0;row<n;row++)
        {
            int data;
            vector<int>row_;
            for(int col=0;col<n;col++)
                {
                    scanf("%d",&data);
                    row_.push_back(data);
                }
            matrix.push_back(row_);
        }
        scanf("%d",&m);
        m = m%4;
        vector<vector<int>> temp(n,vector<int>(n));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(m==0)  temp[i][j]=matrix[i][j];
                    else if(m==1) temp[j][n-i-1]=matrix[i][j];
                    else if(m==2) temp[i][j]=matrix[n-i-1][n-j-1];
                    else if(m==3) temp[i][j]=matrix[j][n-i-1];
                }
            }

        for(auto& row_:temp)
            {
                for(auto&data:row_)
                {
                    std::cout << data << " ";
                }
                cout<<endl;
            }
    }

    return 0;
}*/

/*---------------华为 回溯法 n件无差别礼物分给k个小朋友 -----------------
#include<iostream>
using namespace std;
//i为第i个盒子,0<=i<=m-1
//j:剩余礼物
//x:每个人所得数
//num：放置的方法数目
void Select(int i,int j,const int m,int *x,int &num)
{
	if (i > m) return;
	if (j == 0) //没有礼物了
    {
		num++;
		for (int i = 0; i < m; i++)
        {
			for(int k=0;k<x[i];k++)
                cout<<"*";
			if (i != m - 1) cout << "|";
			else cout  << endl;
		}
		return;
	}

    for (int k = 0; k <= j; k++)
    {
		if (i == m) return;
		x[i] = j-k;
		Select(i + 1, k, m, x,num);
	}
}
int main(){

    int n,k;
    // n件礼物 k个小朋友
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int num = 0;
	    int x[100] = { 0 };
        Select(0, n, k, x,num);
        cout << "共 " << num << " 种" << endl;
    }

	return 0;
}*/



/*---------------BIGO 十进制能否被9整除 -----------------
#include<iostream>

using namespace std;

int main(void)
{

    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int input=n;
        if(input==0) 
        {
            std::cout << "该数能被9整除" << '\n';
            continue;
        }
        int part=0,wei_sum=0;
        while(input>=10)
        {
            part = input%10;
            wei_sum += part;
            input = input/10;
            if(input<10)
            {
                input += wei_sum;
                wei_sum = 0; 
            }
        }
        if(input==9) std::cout << "该数能被9整除" << '\n';
            else std::cout << "该数不能被9整除" << '\n';
    }

    return 0;
}*/


/*---------------BIGO 求矩形交叉面积 -----------------

#include<iostream>

using namespace std;

int computeArea(int A,int B,int C,int D ,int E,int F,int G,int H)
{
    if((C<E)||(D<F)||(G<A)||(H<B)) return 0;
    else
    {
        int len,width;

        int min=C,max=A;
        if (min>G) min=G;
        if(max<E) max=E;
                
        len = min - max;

        min=D,max=B;
        if (min>H) min=H;
        if(max<F) max=F;
                
        width = min - max;

        return len*width;
    }
    
}
int k;
double compute(double x)
{
    static int num=0;
    num++;
    if(k==0) return 1.0;
    if(num==k) return 1.0;
    return (x/(x+compute(x)));
}
int main(void)
{

    int n;
    while(scanf("%d",&n)!=EOF)
    {
        k=n;
       std::cout << compute(1.0) << '\n';
    }

    return 0;
}*/

/*---------------BIGO 求两个整数的Hamming距离 ----------------- */

/*
平安果
简要描述：
给定一个M行N列的矩阵（M*N个格子），每个格子中放着一定数量的平安果。
你从左上角的各自开始，只能向下或者向右走，目的地是右下角的格子``。
每走过一个格子，就把格子上的平安果都收集起来。求你最多能收集到多少平安果。
注意：当经过一个格子时，需要一次性把格子里的平安果都拿走。
限制条件：1<N,M<=50；每个格子里的平安果数量是0到1000（包含0和1000）.
输入描述：
输入包含两部分：
第一行M, N
接下来M行，包含N个平安果数量
输出描述：
一个整数
最多拿走的平安果的数量
*/


// #include<iostream>
// #include<stdio.h>
// #include<vector>
// #include<algorithm>
// using namespace std;
// void opera(vector<char>&res,int n){

//     if(n!=0){
//         if(n%2==0)
//             {
//                 n = (n-2)/2;
//                 res.push_back('2');
//             }
//         else
//             {
//                 n = (n-1)/2;
//                 res.push_back('1');
//             }
//     opera(res,n);
//     }
//     else return ;
    
// }
// int main(void)
// {
//     int n;
//     while(scanf("%d",&n)!=EOF){
//     vector<char> res;
//     opera(res,n);  
//     reverse(res.begin(),res.end());
//     string out_;
//     for(auto ch:res)
//         out_+=ch;
//     cout<< out_ ;
//     }
//     exit(0);
// }

// #include<iostream>
// #include<stdio.h>
// #include<vector>
// #include<algorithm>
// #include<stack>
// using namespace std;
// int opera(int n){
//      int jie=0;
//      stack<int> num;
//      while(n!=0)
//         {
//             int k = n%10;
//             num.push(k);
//             n=n/10;
//         }
//     int new_n=0;
//     while(!num.empty())
//     {
//         new_n += num.top()*pow(10,jie);
//         num.pop();
//         jie++;
//     }
//     return new_n;
// }
// int main(void)
// {
//     int n;
//     while(scanf("%d",&n)!=EOF){
//     cout<< (n+opera(n)) ;
//     }
//     exit(0);
// }


// #include<iostream>
// #include<stdio.h>
// #include<vector>
// #include<algorithm>
// #include<stack>
// using namespace std;

// int main(void)
// {
//     string input;
//     while(getline(cin,input)){
//         if(input.empty()) {
//             cout<<0; continue;
//         }
//         // 26个小写字母
//         int k=0;
//         float sep_num=0.0,sep=0.0;
//         for(int i=k;i<input.size();){
//             do
//             {
//                 ++k;
//             }while(k<input.size() && input[k]==input[i]);
//             sep += float(k-i);
//             sep_num++;
//             i=k;
//         }
//      printf("%.2f",(sep/sep_num));
//     }
//     exit(0);
// }

/* #include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int max_trip(int* par,int* vis,int n){

    



}
int main(void)
{
    int city_num,t;
    while(scanf("%d%d",&city_num,&t)!=EOF){
        int *parent = new int[city_num];
        int *vis = new int[city_num];
        for(int i=1;i<city_num;i++) vis[i]=0;
        vis[0]=1;
        for(int i=0;i<(city_num-1);i++){
            int parent_;
            scanf("%d",&parent_);
            parent[i+1] = parent_ ;
        }
        parent[0]=0;

        cout << max_trip(parent,vis,city_num);
    }
    exit(0);
} */



/* */

/* 
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, const char** argv) {


    int n;
    while(scanf("%d",&n)!=EOF){
        int num=1;
        for(int i=2;i<=n;i++)
        {
            num = num*2;
            for(int j=i-1;j>=2;j--)
            {
                if(i%j==0) num-=2;
            }
        }
        cout << num << endl;
    }
    return 0;
} */


 









