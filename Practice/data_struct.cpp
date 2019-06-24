/* ------------------ 先序序列+中序序列 重构二叉树---------------------------- 
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
using namespace std;
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()) return NULL;
        TreeNode* root =new TreeNode(pre[0]);

        int offset=0;
        for(auto& data:vin)
        {
            if(data==root->val) break;
            offset++;
        }
        vector<int> left_vin(vin.begin(),vin.begin()+offset);
        vector<int> right_vin(vin.begin()+offset+1,vin.end());

        vector<int> left_pre(pre.begin()+1,pre.begin()+offset+1);
        vector<int> right_pre(pre.begin()+offset+1,pre.end());

         root->left = reConstructBinaryTree(left_pre,left_vin);
         root->right = reConstructBinaryTree(right_pre,right_vin);

        return root;
    }
};
int main()
{
    Solution solu;
    vector<int> pre={1,2,4,7,3,5,6,8};
    vector<int> vin={4,7,2,1,5,3,8,6};

    solu.reConstructBinaryTree(pre,vin);

    return 0;
}*/

/*----------------- 后序遍历二叉树 (递归 + 迭代)----------------

#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

using namespace std;
class Solution {
public:
    void PostOder(TreeNode* pRoot)
    {
        if(pRoot == nullptr)
        {
            return ;
        }
        else
        {
            PostOder(pRoot->left);
            PostOder(pRoot->right);
            cout << pRoot->val << " ";
        }
        
    }
    void PostOder_2(TreeNode* pRoot)
    {
        stack<TreeNode*> node;
        node.push(pRoot);
        TreeNode* pre = nullptr;
        while( !node.empty())
        {
            TreeNode* p = node.top();
            if(((p->left == nullptr) && (p->right == nullptr))
            || (pre &&( pre==p->left  || pre==p->right) )
            )
            {
                cout << p->val << " ";
                pre = p;
                node.pop();
            }
            else
            {
                if(p->right != nullptr)
                  node.push(p->right);
                if(p->left != nullptr)
                 node.push(p->left);
            }
        }
    }
};
int main(void)
{
    Solution solu;
    TreeNode p1(3),n1(5),n2(7),n3(6),n4(2),n5
    (1),n6(4),n7(11),n8(10);
    
    p1.left=&n1; p1.right=&n2;
    n1.left=&n3;n1.right=&n4;
    n3.left=&n7;

    n2.left=&n5;n2.right=&n6;
    n5.right=&n8;
    solu.PostOder(&p1);
    cout << endl;
    solu.PostOder_2(&p1);
    cout << endl;
    return 0;
} */
/* -------------------直接插入排序---------------------------- 

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> solution(vector<string> vec) {
        if(vec.empty()) return vec;
        for(int i=1;i<vec.size();i++)
        {
            string x = vec[i];
            int j=i-1;
            while((j>=0)&&(x.length()<vec[j].length()))
                {
                    vec[j+1]=vec[j];
                    j--;
                }
                vec[j+1]=x;
        }
        return vec; 
    }
};
int main(void)
{
    Solution solu;
    int n,input;
    
    while(scanf("%d",&n)!=EOF)
    {
        vector<int> array;
        vector<int> out;
        for(int i=0;i<n;i++)
            {
                scanf("%d",&input);
                array.push_back(input);
            }
       out = solu.solution(array) ;
       for(auto&data:out)   
        std::cout << data << '\n';
    }
            

    return 0;
}
*/

/* -------------------折半插入排序---------------------------- 

#include <iostream>
#include <cstdio>
#include <vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> solution(vector<string> vec) {
        if(vec.empty()) return vec;
        for(int i=1;i<vec.size();i++)
        {
            string x = vec[i];

            int left=0,right=i-1;
            int middle= 0;
            while(left<=right)
            {
                middle = (left+right)/2;
                if((vec[middle].length()<=x.length())&&(vec[middle+1].length()>=x.length()))
                {
                    break;
                }
                else
                {
                    if(vec[middle].length()>x.length())
                    {
                        right = middle-1;
                    }
                    if(vec[middle].length()<x.length())
                    {
                        left = middle +1;
                    }
                }
                
            }
            if(right==-1)   
            {
             for(int k=i;k>middle;k--)
                 vec[k]=vec[k-1];

                  vec[middle] = x ;
            }
            else
            {
              for(int k=i;k>middle+1;k--)
                 vec[k]=vec[k-1];

                  vec[middle+1] = x ;
            }
            

        }
        return vec; 
    }
};
int main(void)
{
    Solution solu;
    int n;
    string input;
    while(scanf("%d",&n)!=EOF)
    {
        vector<string> array;
        vector<string> out;
        for(int i=0;i<n;i++)
            {
                cin >> input;
                array.push_back(input);
            }
       out = solu.solution(array) ;
       for(auto&data:out)   
        std::cout << data << '\n';
    }
            

    return 0;
}
*/


/* ------------------ 希尔排序+直接插入排序 缩小增量排序---------------------------- 

#include <iostream>
#include <cstdio>
#include <vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> solution(vector<int> vec) {
        if((vec.empty())||(vec.size()==1)) return vec;
        int d=5;
        while(d>=1)
        {          
            for(int start=0;start<d;start++)
                {
                    for(int i=start+d;i<vec.size();i=i+d)
                    {
                        int x = vec[i];
                        int j=i-d;
                        while((j>=0)&&(x<vec[j]))
                            {
                                vec[j+d]=vec[j];
                                j-=d;
                            }
                            vec[j+d]=x;
                    }
                }
            if(d==1) break;
            d = (d+1)/2;
        }


        return vec; 
    }
};
int main(void)
{
    Solution solu;
    int n;
    int input;
    while(scanf("%d",&n)!=EOF)
    {
        vector<int> array;
        vector<int> out;
        for(int i=0;i<n;i++)
            {
                cin >> input;
                array.push_back(input);
            }
       out = solu.solution(array) ;
       for(auto&data:out)   
        std::cout << data << '\n';
    }
            
//14 86 22 24 82 97 65 25 6 56 12 48 64 70 33
    return 0;
}
*/
/* ------------------ 希尔排序+起泡排序 缩小增量排序----------------------------
#include <iostream>
#include <cstdio>
#include <vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> solution(vector<int> vec) {
        if((vec.empty())||(vec.size()==1)) return vec;
        int d=5;
        while(d>=1)
        {          
            for(int start=0;start<d;start++)
                {
                    int mark= vec.size()-1,m;
                    //起泡排序改进
                    while(mark)
                    {
                       m=mark;
                       mark=0;
                        for(int k=start;k<m;k++)
                        {
                            if(vec[k]>vec[k+d])
                            {
                                mark=k;
                                swap(vec[k],vec[k+1]);
                            } 
                        }
                    }

                }
            if(d==1) break;
            d = (d+1)/2;
        }


        return vec; 
    }
};
int main(void)
{
    Solution solu;
    int n;
    int input;
    while(scanf("%d",&n)!=EOF)
    {
        vector<int> array;
        vector<int> out;
        for(int i=0;i<n;i++)
            {
                cin >> input;
                array.push_back(input);
            }
       out = solu.solution(array) ;
       for(auto&data:out)   
        std::cout << data << '\n';
    }
            
//14 86 22 24 82 97 65 25 6 56 12 48 64 70 33
    return 0;
}
 */

/* ------------------ 归并排序 (递归)  基于分治----------------------------

#include <iostream>
#include <cstdio>
#include <vector>
#include<string>
using namespace std;

class Solution {
public:
//二路归并
    vector<int> solution(vector<int> list) {
        if((list.empty())||(list.size()==1))  return list;

        vector<int>::iterator center;
        center = list.begin() + list.size()/2;

        vector<int>left_part(list.begin(),center);
        vector<int>right_part(center,list.end());

        vector<int> left_sort =solution(left_part);
        vector<int> right_sort =solution(right_part);

       return  mercg(left_sort,right_sort);
    }

    //合并两个有序数组为一个数组
    vector<int> mercg(vector<int>list1,vector<int>list2)
    {
        vector<int> out;
        size_t i=0,k=0;
        while((i<list1.size())&&(k<list2.size()))
         {
            if(list1[i]<list2[k])
                out.push_back(list1[i++]);
            else 
                out.push_back(list2[k++]);
         }
         if(i<list1.size())
         {
             for(int l=i;l<list1.size();l++)  out.push_back(list1[l]);
         }
         if(k<list2.size())
         {
             for(int l=k;l<list2.size();l++)  out.push_back(list2[l]);
         }

        return out;
    }
};
int main(void)
{
    Solution solu;
    int n;
    int input;
    while(scanf("%d",&n)!=EOF)
    {
        vector<int> array;
        vector<int> out;
        for(int i=0;i<n;i++)
            {
                cin >> input;
                array.push_back(input);
            }
       out = solu.solution(array) ;
       for(auto&data:out)   
        std::cout << data << '\n';
    }
            
//14 86 22 24 82 97 65 25 6 56 12 48 64 70 33
    return 0;
}*/


/* ------------------ 归并排序 (迭代)  基于分治----------------------------

#include <iostream>
#include <cstdio>
#include <vector>
#include<string>
#include<unistd.h>
using namespace std;

class Solution {
public:
//二路归并
    vector<vector<int>> solution(vector<int> list) {
        // if((list.empty())||(list.size()==1))  return list;
        vector<int> out(list.begin(),list.end());
        for(int sub_num=1;;sub_num=sub_num*2)
        {
            int offset=0;
            int start=0;
            while(offset<out.size())
            {
                vector<int>part1;
                vector<int>part2;
                int has1=0,has2=0;
                while((has1<sub_num)&&(offset<out.size()))
                {
                    part1.push_back(out[offset]);
                    offset++;
                    has1++;
                }
                while((has2<sub_num)&&(offset<out.size()))
                {
                    part2.push_back(out[offset]);
                    offset++;
                    has2++;
                }
              
                vector<int> temp= mercg(part1,part2);
                int mul=0;
                for(auto&data:temp)
                {
                    out[start+mul]=data;
                    mul++;
                }
                start +=(has1+has2);
            }
            if(sub_num*2>=out.size()) break;
        }
// ------------  寻找三元组
        vector<vector<int>> arr;
 
        for(int left=0;(left<out.size()-2);left++)
        {
            if(left>0&&(out[left]==out[left-1]))  continue;

          int  mid=left+1;
          int  right=out.size()-1;
          int tem = 0 - out[left];
          while(mid<right)
          {
                if((out[mid]+out[right])==tem)
                {
                    vector<int> get(3);
                    get[0]= out[left];
                    get[1]= out[mid];
                    get[2]= out[right];
                    arr.push_back(get);
                    while((mid<(out.size()-1))&&(out[mid]==out[mid+1]))
                    {
                        mid++;
                    }
                    while((right>0)&&(out[right]==out[right-1]))
                    {
                        right--;
                    }

                mid++; right--;
                }
                else if((out[mid]+out[right])>tem) 
                {
                    while((right>0)&&(out[right]==out[right-1]))
                    {
                        right--;
                    }
                    right--;
                }
                else
                {
                    while((mid<(out.size()-1))&&(out[mid]==out[mid+1]))
                    {
                        mid++;
                    }
                mid++;                   
                }
            }
        }


        return arr;
    }

    //合并两个有序数组为一个数组
    vector<int> mercg(vector<int>list1,vector<int>list2)
    {
        vector<int> out;
        size_t i=0,k=0;
        while((i<list1.size())&&(k<list2.size()))
         {
            if(list1[i]<=list2[k])
                out.push_back(list1[i++]);
            else 
                out.push_back(list2[k++]);
         }
         if(i<list1.size())
         {
             for(size_t l=i;l<list1.size();l++)  out.push_back(list1[l]);
         }
         if(k<list2.size())
         {
             for(size_t l=k;l<list2.size();l++)  out.push_back(list2[l]);
         }

        return out;
    }
};
int main(void)
{
    Solution solu;
    int n;
    int input;
    while(scanf("%d",&n)!=EOF)
    {
        vector<int> array;
        vector<vector<int>> out;
        for(int i=0;i<n;i++)
            {
                cin >> input;
                array.push_back(input);
            }
       out = solu.solution(array) ;
       for(auto&vec:out)  
       {
           cout<< '\n';
           for(auto&data:vec)   
        std::cout << data <<' ';
       }
         
    }
            
//6 -1 0 1 2 -1 -4 
    return 0;
}*/

/* ------------------ 快速排序(递归)   基于分治----------------------------

#include <iostream>
#include <cstdio>
#include <vector>
#include<string>
using namespace std;

class Solution {
public:

    void solution(vector<string>& list,int left,int right) {
        int i,j;
        if(left<right)
        {
            string mid_data = *(list.begin()+left);
             i=left+1;j=right;
            for(;;)
            {
                while(((*(list.begin()+i)).length()<=mid_data.length())&&(i<=right))
                {
                    i++;
                }
                while(((*(list.begin()+j)).length()>=mid_data.length())&&(j>=(left+1)))
                {
                    j--;
                }
                if(i<=j)
                    {
                        string temp;
                        temp=*(list.begin()+i);
                        *(list.begin()+i)=*(list.begin()+j);
                        *(list.begin()+j)=temp;
                    }
                else break;
            }
            
            string temp2;
            temp2=*(list.begin()+left);
            *(list.begin()+left)=*(list.begin()+j);
            *(list.begin()+j)=temp2;

            solution(list,left,j-1);
            solution(list,j+1,right);
        }

    }


};
int main(void)
{
    Solution solu;
    int n;
    string input;
    while(scanf("%d",&n)!=EOF)
    {
        vector<string> array;
        vector<int> out;
        for(int i=0;i<n;i++)
            {
                cin >> input;
                array.push_back(input);
            }
       solu.solution(array,0,int(array.size()-1)) ;
       for(auto&data:array)   
        std::cout << data << '\n';
    }
            
//14 86 22 24 82 97 65 25 6 56 12 48 64 70 33
    return 0;
}*/

/* ------------------ 快速排序(迭代)   基于分治----------------------------

#include <iostream>
#include <cstdio>
#include <vector>
#include<string>
#include<stack>
#include <queue>
using namespace std;

class Solution {
public:

    void solution(vector<int>& list,int left,int right) {
        int i,j;
        stack<int> pl;
        stack<int> pr;
        pl.push(left),pr.push(right);
        while(!pl.empty())
        {
             left = pl.top(); pl.pop();
             
             right = pr.top(); pr.pop();
             std::cout << left<<"--"<<right<<" ";
             i=left; j=right;
            int mid_data =list[(i+j)/2];
            while(i<=j)
            {
                while(list[i]<mid_data)
                {
                    i++;
                }
                while(list[j]>mid_data)
                {
                    j--;
                }
                if(i<=j)
                    {
                        int temp;
                        temp=*(list.begin()+i);
                        *(list.begin()+i)=*(list.begin()+j);
                        *(list.begin()+j)=temp;
                        i++; j--;
                    }
            }
            for(auto&data:list)   
                std::cout << data<<' ';
                if(left<j)
                {
                    pl.push(left);pr.push(j);
                }
                if(right>i)
                {
                     pl.push(i);pr.push(right);
                }
                cout<< '\n';
        }
    }
};
int main(void)
{
    Solution solu;
    int n;
    int input;
    while(scanf("%d",&n)!=EOF)
    {
        vector<int> array;
        vector<int> out;
        for(int i=0;i<n;i++)
            {
                cin >> input;
                array.push_back(input);
            }
       solu.solution(array,0,int(array.size()-1)) ;
       for(auto&data:array)   
        std::cout << data << '\n';
    }
            
//14 86 22 24 82 97 65 25 6 56 12 48 64 70 33
    return 0;
} */


/*------------ 分治法 传染病问题 自写方法--------------

// 终端输入 row col （矩阵行、列） rand（）随机生成病毒
// 菌群输出
#include<iostream>
#include<vector>
using namespace std;

int cnt;
void dis_means(int cur_x,int cur_y,vector<vector<int>>& matrix,vector<vector<int>>&vis);
int main(void)
{
    int row,col;
    while(scanf("%d%d",&row,&col)!=EOF)
    {
        vector<vector<int>> matrix(row,vector<int>(col));
        vector<vector<int>> vis(row,vector<int>(col));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=matrix[0].size()/2;j<matrix[0].size();j++)
            {
                int pos_i = rand()%(matrix.size()-1);
                int pos_j = rand()%(matrix[0].size()-1);
                matrix[pos_i][matrix[0].size()-1-pos_j] = 1;
                vis[i][j]=0;
            }
        }
        cnt=1;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
            {
                if(vis[i][j]==1) continue;
                dis_means(i,j,matrix,vis);
                if(matrix[i][j]!=0) cnt++;
            }

        std::cout <<"共有菌群： "<< cnt-1 << '\n' << '\n';
        for(auto& vec:matrix)
        {
            for(auto& data:vec)
            {
                std::cout << data << " ";
            }
            cout<<endl;
        }
    }
    return 0;
}
void dis_means(int cur_x,int cur_y,vector<vector<int>>& matrix,vector<vector<int>>&vis)
{
    if(vis[cur_x][cur_y]==1) return ;

    vis[cur_x][cur_y]=1;

    if(matrix[cur_x][cur_y]==0)   return ;

    matrix[cur_x][cur_y]=cnt;
    
    for(int i=-1;i<2;i++)
        for(int j=-1;j<2;j++)
        {
            if((cur_x+i)>=0 && (cur_x+i)<matrix.size())
            {
                if((cur_y+j)>=0 && (cur_y+j)<matrix[0].size())
                {
                    dis_means(cur_x+i,cur_y+j,matrix,vis);
                }
            }
        }
}*/

/*------------ 分治法 递归 矩阵乘法 --------------

函数参数：pMatrix1--矩阵1
			nLeftIndex1，nTopIndex1--矩阵1左上角索引点（相对于源矩阵pMatrixl）
			pMatrix2--矩阵2
			nLeftIndex2, nTopIndex2--矩阵2左上角索引点（相对于源矩阵pMatrix2）
			nCount--方阵n
			nTotalCol--使用矩阵列大小（指针取值使用）
			pResult--相乘结果保存
函数返回：
*****************************************************************

bool MatrixMuiltiplyGeneralEx_8( int* pMatrix1, int nLeftIndex1, int nTopIndex1,
							  int* pMatrix2, int nLeftIndex2, int nTopIndex2,
							  int nCount, int nTotalCol, int** pResult )
{
 
	*pResult = new int[nCount*nCount];
 
	for( int i = 0; i < nCount; ++i )
	{
		for( int j = 0; j < nCount; ++j )
		{
			GetArrayVal( *pResult, nCount, i, j ) = 0;
			for( int k = 0; k < nCount; ++k )
			{
				GetArrayVal( *pResult, nCount, i, j ) += GetArrayVal( pMatrix1, nTotalCol, nLeftIndex1+i, nTopIndex1+k)
					* GetArrayVal( pMatrix2, nTotalCol, nLeftIndex2+k, nTopIndex2+j );
			}
		}
	}
 
	return true;
}
 
 
//矩阵加法(n*n),结果保存在第一个矩阵中
void MatrixAddOrSub(  int* pMatrix1, int* pMatrix2, int nCount, bool bAdd = true )
{
	for( int i = 0; i < nCount; ++i )
	{
		for( int j = 0; j < nCount; ++j )
		{
			if ( bAdd )
			{
				GetArrayVal( pMatrix1, nCount, i, j ) += GetArrayVal( pMatrix2, nCount, i, j );
			}
			else
			{
				GetArrayVal( pMatrix1, nCount, i, j ) -= GetArrayVal( pMatrix2, nCount, i, j );
			}
			
		}
	}
}
 
//递归求解n*n方矩阵之积(8次乘法)
void RecursiveMuiltiplyMatrix( int* pMatrix1, int nLeftIndex1, int nTopIndex1,
							  int* pMatrix2, int nLeftIndex2, int nTopIndex2, 
							  int nCount, int nTotalCol, int** pResult )
{
	if ( nCount == 2 )
	{
		MatrixMuiltiplyGeneralEx_8( pMatrix1, nLeftIndex1, nTopIndex1, 
			pMatrix2, nLeftIndex2, nTopIndex2, nCount, nTotalCol, pResult );
	}
	else
	{
		//拆分成4个大小相等的子矩阵
		int* pResult1 = NULL;
		int* pResult2 = NULL;
		int* pResult3 = NULL;
		int* pResult4 = NULL;
		int* pResult5 = NULL;
		int* pResult6 = NULL;
		int* pResult7 = NULL;
		int* pResult8 = NULL;
 
		//A[1][1]*B[1][1];
		RecursiveMuiltiplyMatrix( pMatrix1, nLeftIndex1, nTopIndex1,
			pMatrix2, nLeftIndex2, nTopIndex2, nCount / 2, nTotalCol, &pResult1 );
 
		//A[1][2]*B[2][1];
		RecursiveMuiltiplyMatrix( pMatrix1, nLeftIndex1, nTopIndex1+nCount/2,
			pMatrix2, nLeftIndex2+nCount/2, nTopIndex2, nCount / 2, nTotalCol, &pResult2 );
 
		//A[1][1]*B[1][2];
		RecursiveMuiltiplyMatrix( pMatrix1, nLeftIndex1, nTopIndex1,
			pMatrix2, nLeftIndex2, nTopIndex2+nCount/2, nCount / 2, nTotalCol, &pResult3 );
 
		//A[1][2]*B[2][2];
		RecursiveMuiltiplyMatrix( pMatrix1, nLeftIndex1, nTopIndex1+nCount/2,
			pMatrix2, nLeftIndex2+nCount/2, nTopIndex2+nCount/2, nCount / 2, nTotalCol, &pResult4 );
 
		//A[2][1]*B[1][1];
		RecursiveMuiltiplyMatrix( pMatrix1, nLeftIndex1+nCount/2, nTopIndex1,
			pMatrix2, nLeftIndex2, nTopIndex2, nCount / 2, nTotalCol, &pResult5 );
 
		//A[2][2]*B[2][1];
		RecursiveMuiltiplyMatrix( pMatrix1, nLeftIndex1+nCount/2, nTopIndex1+nCount/2,
			pMatrix2, nLeftIndex2+nCount/2, nTopIndex2, nCount / 2, nTotalCol, &pResult6 );
 
		//A[2][1]*B[1][2];
		RecursiveMuiltiplyMatrix( pMatrix1, nLeftIndex1+nCount/2, nTopIndex1,
			pMatrix2, nLeftIndex2, nTopIndex2+nCount/2, nCount / 2, nTotalCol, &pResult7 );
 
		//A[2][2]*B[2][2];
		RecursiveMuiltiplyMatrix( pMatrix1, nLeftIndex1+nCount/2, nTopIndex1+nCount/2,
			pMatrix2, nLeftIndex2+nCount/2, nTopIndex2+nCount/2, nCount / 2, nTotalCol, &pResult8 );
 
 
		//加法运算
		MatrixAddOrSub( pResult1, pResult2, nCount/2 );
		MatrixAddOrSub( pResult3, pResult4, nCount/2);
		MatrixAddOrSub( pResult5, pResult6, nCount/2 );
		MatrixAddOrSub( pResult7, pResult8, nCount/2 );
		
 
 
		//构造结果
		*pResult = new int[nCount*nCount];
		for( int i = 0; i < nCount/2; ++i )
		{
			for( int j = 0; j <nCount/2; ++j )
			{
				GetArrayVal( *pResult, nCount, i, j ) = GetArrayVal( pResult1, nCount/2, i, j );
				GetArrayVal( *pResult, nCount, i, j+nCount/2 ) = GetArrayVal( pResult3, nCount/2, i, j );
				GetArrayVal( *pResult, nCount, i+nCount/2, j ) = GetArrayVal( pResult5, nCount/2, i, j );
				GetArrayVal( *pResult, nCount, i+nCount/2, j+nCount/2 ) = GetArrayVal( pResult7, nCount/2, i, j );
 
			}
		}
 
		DeleteMatrix( &pResult1 );
		DeleteMatrix( &pResult2 );
		DeleteMatrix( &pResult3 );
		DeleteMatrix( &pResult4 );
		DeleteMatrix( &pResult5 );
		DeleteMatrix( &pResult6 );
		DeleteMatrix( &pResult7 );
		DeleteMatrix( &pResult8 );
	}
}*/


/*------------ 回溯法 八皇后问题 --------------

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
class queen_distribution
{
    public:
        queen_distribution(int num);
        void find_solution(int row_);
        bool check(int row_,int pos);
        const int has_solu() {return solu_num;}
    private:
        int col;
        int solu_num=0;
        vector<int> queen;
};
queen_distribution::queen_distribution(int num)
{
    col = num;
    queen.resize(num);
}
void queen_distribution::find_solution(int row_)
{
        for(int n=0;n<col;n++)
        {
            //  check pos is interrupted ?
            if(check(row_,n))
            {
                queen[row_]=n;
                if(row_== queen.size()-1)
                {
                   for(int i=0;i<col;i++)
                    std::cout << queen[i] << " ";
                    cout << endl;
                    solu_num++;
                }
                else
                find_solution(row_+1);
            }
        }
}
bool queen_distribution::check(int row_,int pos)
{
    // 列存在 0-row_ 皇后
    // 对脚线存在 0-row_ 皇后
    for(int i=row_-1;i>=0;i--)
    {
        if(queen[i]==pos) return false;
        if( row_-i == abs(pos-queen[i])) return false;
    }
    
    return true;
}
int main(void)
{
    queen_distribution solu(8);
    solu.find_solution(0);
    cout << "共有解决方案： " <<solu.has_solu()<<" 种" ;
    return 0;
}*/

/*------------ 回溯法 骑士周游 --------------*/
