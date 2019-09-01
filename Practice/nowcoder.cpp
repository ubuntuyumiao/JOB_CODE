
// // /* ------------------ STL-- map  ----------------------------
// // #include <iostream>
// // #include <algorithm>
// // #include <list>
// // #include <map>

// // using namespace std;

// // int main(void)
// // {
// //         vector<int> array;
// //         list<int> arr;
// //         map<string, string> namemap;
 
// //         namemap["岳不群"]="华山派掌门人，人称君子剑";
// //         namemap["张三丰"]="武当掌门人，太极拳创始人";
// //         namemap["东方不败"]="第一高手，葵花宝典";

// //         for(int i=0;i<100;i++)
// //         {
// //             arr.push_back(i);
// //         }
// //         if(namemap.find("岳不群") != namemap.end()){
// //             std::cout << namemap["岳不群"] << '\n';
// //            } 
// //         printf("%d",*arr.begin());

// //     return 0;
// // }*/

// // /* ------------------ STL-- map  ----------------------------
// // #include <iostream>
// // #include <algorithm>
// // #include <list>
// // #include <map>

// // using namespace std;

// // int main(void)
// // {
// //         vector<int> array;
// //         list<int> arr;
// //         map<string, string> namemap;
 
// //         namemap["岳不群"]="华山派掌门人，人称君子剑";
// //         namemap["张三丰"]="武当掌门人，太极拳创始人";
// //         namemap["东方不败"]="第一高手，葵花宝典";

// //         for(int i=0;i<100;i++)
// //         {
// //             arr.push_back(i);
// //         }
// //         if(namemap.find("岳不群") != namemap.end()){
// //             std::cout << namemap["岳不群"] << '\n';
// //            } 
// //         printf("%d",*arr.begin());

// //     return 0;
// // }*/

// // /* ------------------  2间隔删除元素 直到只剩一个 输出  ----------------------------
// // #include <iostream>
// // #include <cstdio>
// // #include <vector>
// // #include<string>
// // #include<unistd.h>
// // #include<queue>
// // using namespace std;

// // class Solution {
// // public:

// //     void solution(queue<int> array) {
// //                int count;
// //        while(array.size()>1)
// //        {
// //             if(count!=2)
// //             {
// //                 int temp=array.front();
// //                 array.pop();
// //                 array.push(temp);
// //                 count++;
// //             }
// //             else
// //             {
// //                 count=0;

// //                 array.pop();
// //             }
            
// //        }
// //        std::cout << array.front() << '\n';
// //     }


// // };
// // int main(void)
// // {
// //     Solution solu;
// //     int n;
// //     int input;
// //     while(scanf("%d",&n)!=EOF)
// //     {
// //         queue<int> array;
// //         vector<int> out;
// //         for(int i=0;i<n;i++)
// //             {
// //                 // cin >> input;
// //                 array.push(i);
// //             }

// //         solu.solution(array);
// //     }
            
// // //6 -1 0 1 2 -1 -4 
// //     return 0;
// // } */


// // /* ------------------  Dijkstra(贪心) 算法  ----------------------------
// // #include <iostream>
// // #include <cstdio>
// // #include <vector>
// // #include <string>
// // #include <unistd.h>
// // #include <queue>
// // #include<math.h>
// // #include<stack>
// // using namespace std;
// // #define V 7 
// // #define INF 0x3f3f3f3f  

// // struct graph
// // {
// //     int cost[V][V];
// //     char sig[V]={'A','B','C','D','E','F','G'};
// //     void init()
// //     {
// //         for(int i=0;i<V;i++)
// //             for(int j=0;j<V;j++)
// //                  cost[i][j]=INF;

// //     cost[0][1] = cost[1][0] = 4;
// //     cost[0][2] = cost[2][0] = 5; 
// //     cost[0][3] = cost[3][0] = 2;
// //     cost[1][3] = cost[3][1] = 1;
// //     cost[1][4] = cost[4][1] = 2;
// //     cost[2][3] = cost[3][2] = 8;
// //     cost[2][6] = cost[6][2] = 1;
// //     cost[3][4] = cost[4][3] = 3;
// //     cost[3][5] = cost[5][3] = 7;
// //     cost[3][6] = cost[6][3] = 4;
// //     cost[4][5] = cost[5][4] = 10;
// //     cost[5][6] = cost[6][5] = 2;
// //     }
// //     int findminvtx(int* dist,int* visited)
// //     {
// //         int minvtx=0,min=INF;
// //         for(int i=0;i<V;i++)
// //         {
// //             if(visited[i]==0  && dist[i]<min)
// //             {
// //                 minvtx=i;
// //                 min = dist[i];
// //             }
// //         }

// //         return minvtx;
// //     }
// //     int first_adj(int v)
// //     {
// //         for(int i=0;i<V;i++)
// //         {
// //             if(v==i) continue;
// //             if(cost[v][i]!=INF) return i;
// //         }
// //         return -1;
// //     }
// //     int next_adj(int v,int first_adj)
// //     {
// //         for(int i=first_adj+1;i<V;i++)
// //         {
// //             if(v==i) continue;
// //             if(cost[v][i]!=INF) return i;
// //         }
// //         return -1;
// //     }
// //     void dijkstra(int start)
// //     {
// //         int* dist=new int[V];
// //         int* visited=new int[V];
// //         int* path=new int[V];
 
// //         for(int i=0;i<V;i++)
// //         {
// //             visited[i]=0;
// //             dist[i]=cost[start][i];
// //             if(cost[start][i]!=INF) path[i]=start;
// //                 else path[i]=-1;
// //         }

// //         visited[start]=1;

// //        for(int i=0;i<V;i++)
// //         {
// //             int w=findminvtx(dist,visited);
  
// //             visited[w]=1;
 
// //             for(int j=0;j<V;j++)
// //             {
// //                 if((visited[j]==0)&&(dist[j]>(dist[w]+cost[w][j])))
// //                 {
// //                     path[j]= w;
// //                     dist[j]= dist[w]+cost[w][j];
// //                 }
                
// //             }
// //             for(int k=0;k<V;k++)
// //                 std::cout << dist[k] << ' ';
// //                 cout<< '\n';
// //         }


// //         cout<<'\n';cout<<'\n';
// //         for(int i=0;i<V;i++)
// //         {
// //             cout<<"Vertex "<< sig[start] << " ->"<<"Vertex "<< sig[i]
// //                     <<": "<< dist[i] <<" ";
// //             cout<<'\n';
// //         } 
            
// //             stack<int> s;
// //             //这个循环以由叶子结点到根结点的顺序将其入栈
// //             for(int i=0;i<V;i++)
// //             {
// //                 int to=i;
// //                 while(path[to] != -1){
// //                 s.push(to);
// //                 // cout << sig[path[to]] <<' ';   
// //                 to = path[to];
// //             } 
// //             s.push(to);

// //             while(!s.empty()){
// //                 cout << sig[s.top()] <<' ';
// //                 s.pop();
// //             }
// //             std::cout << '\n';
// //             }

// //     }
// // };

// // int main(void)
// // {
// //     graph dijk_g;
// //     dijk_g.init();
// //     // for(int j=0;j<V;j++)
// //     // {
// //         dijk_g.dijkstra(0);
// //         std::cout << "-  -  -  -  -" << '\n';
// //     // }
// // //6 -1 0 1 2 -1 -4 
// //     return 0;
// // } */

// // /* ------------------  反转链表 （单向链表）  ----------------------------
// // #include <iostream>
// // #include <cstdio>
// // #include <vector>
// // #include<string>
// // #include<unistd.h>
// // #include<queue>
// // using namespace std;
// // struct ListNode {
// // 	int val;
// // 	struct ListNode *next;
// // 	ListNode(int x) :
// // 			val(x), next(NULL) {
// // 	}
// // };
// // class Solution {
// // public:
// //     ListNode* ReverseList(ListNode* pHead) {
        
// //         ListNode* node = pHead;
// //         ListNode* pre = nullptr;
// //         while(node!=nullptr)
// //         {
// //              ListNode* next= node->next;
             
// //              node->next = pre;
// //              if(next == nullptr) break;
// //              pre= node ;
// //              node = next;
// //         }
// //         return node;
// //     }
// // };
// // int main(void)
// // {
// //     Solution solu;

// //     ListNode head(3);
// //     ListNode node1(7);
// //     ListNode node2(4);
// //     ListNode node3(10);
// //     ListNode rear(9);

// //     head.next = & node1;
// //     node1.next = & node2;
// //     node2.next = & node3;
// //     node3.next = & rear;
// //     ListNode* result;
// //     result = solu.ReverseList(&head);
    
// //     while(result!=nullptr)
// //     {
// //         std::cout <<result->val << '\n';
// //         result = result->next ;
// //     }
// // //6 -1 0 1 2 -1 -4 
// //     return 0;
// // }  */


// // /* ------------------（迭代）  合成两个有序链表为一个有序链表 ----------------------------
// // #include <iostream>
// // #include <cstdio>
// // #include <vector>
// // #include<string>
// // #include<unistd.h>
// // #include<queue>
// // using namespace std;
// // struct ListNode {
// // 	int val;
// // 	struct ListNode *next;
// // 	ListNode(int x) :
// // 			val(x), next(NULL) {
// // 	}
// // };
// // class Solution {
// // public:
// //     ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
// //         if(pHead1==nullptr)  return pHead2;
// //         else if(pHead2==nullptr)  return pHead1;
        
// //         ListNode* out_head=nullptr;
// //         ListNode* out_pre=nullptr;
        
// //         ListNode* node1 = pHead1;
// //         ListNode* node2 = pHead2;

// //         while(node1!=nullptr && node2!=nullptr)
// //         {
// //             if(node2->val>node1->val)
// //             {
// //                 if(out_pre!=nullptr)
// //                 {
// //                     out_pre->next = node1;
// //                     out_pre = out_pre->next;
// //                 }
// //                 else
// //                 {
// //                     out_pre= node1;
// //                     out_head= out_pre;
// //                 }
// //                 node1 = node1->next;
// //             }
// //             else
// //             {
// //                 if(out_pre!=nullptr)
// //                 {
// //                     out_pre->next = node2;
// //                     out_pre = out_pre->next;
// //                 }
// //                 else
// //                 {
// //                     out_pre= node2;
// //                     out_head= out_pre;
// //                 }
// //                 node2 =node2->next;
// //             }
// //         }
// //         if(node1 == nullptr)
// //         {
// //             while(node2!=nullptr)
// //             {
// //                 out_pre->next = node2;
// //                 out_pre = out_pre->next;
// //                 node2= node2->next;
// //             }
// //         }
// //         if(node2 == nullptr)
// //         {
// //             while(node1!=nullptr)
// //             {
// //                 out_pre->next = node1;
// //                 out_pre = out_pre->next;
// //                 node1= node1->next;
// //             }
// //         }
// //         return out_head;
// //     }
// // };
// // int main(void)
// // {
// //     Solution solu;

// //     ListNode head(6);
// //     ListNode node1(7);
// //     ListNode node2(8);
// //     ListNode node3(9);
// //     ListNode rear(10);

// //     ListNode head1(5);
// //     ListNode node11(8);
// //     ListNode node21(9);
// //     ListNode node210(10);
// //     ListNode node211(12);
// //     ListNode node31(13);
// //     ListNode rear1(16);

// //     head.next = & node1;
// //     node1.next = & node2;
// //     node2.next = & node3;
// //     node3.next = & rear;

// //     head1.next = & node11;
// //     node11.next = & node21;
// //     node21.next = & node210;
// //     node210.next = & node211;
// //     node211.next = & node31;
// //     node31.next = & rear1;

// //     ListNode* result;
// //     result = solu.Merge(&head,&head1);
    
// //     while(result!=nullptr)
// //     {
// //         std::cout <<result->val << '\n';
// //         result = result->next ;
// //     }
// // //6 -1 0 1 2 -1 -4 
// //     return 0;
// // } */


// // /* ------------------（递归）  合成两个有序链表为一个有序链表 ----------------------------
// // #include <iostream>
// // #include <cstdio>
// // #include <vector>
// // #include<string>
// // #include<unistd.h>
// // #include<queue>
// // using namespace std;
// // struct TreeNode {
// // 	int val;
// // 	struct TreeNode *left;
// // 	struct TreeNode *right;
// // 	TreeNode(int x) :
// // 			val(x), left(NULL), right(NULL) {
// // 	}
// // };
// // class Solution {
// // public:
// //     TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
// //         if(pre.empty()) return NULL;
// //         TreeNode* root =new TreeNode(pre[0]);

// //         int offset=0;
// //         for(auto& data:vin)
// //         {
// //             if(data==root->val) break;
// //             offset++;
// //         }
// //         vector<int> left_vin(vin.begin(),vin.begin()+offset);
// //         vector<int> right_vin(vin.begin()+offset+1,vin.end());

// //         vector<int> left_pre(pre.begin()+1,pre.begin()+offset+1);
// //         vector<int> right_pre(pre.begin()+offset+1,pre.end());

// //          root->left = reConstructBinaryTree(left_pre,left_vin);
// //          root->right = reConstructBinaryTree(right_pre,right_vin);

// //         return root;
// //     }


// //     bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
// //     {
// //         if(pRoot2==nullptr) return false;
// //         return true;
// //     }
// // };

// // int main(void)
// // {
// //     Solution solu;
// //     vector<int> pre={1,2,4,7,3,5,6,8};
// //     vector<int> vin={4,7,2,1,5,3,8,6};

// //     vector<int> pre2={1,2,4,7,3,5,6,8};
// //     vector<int> vin2={4,7,2,1,5,3,8,6};

// //     TreeNode* tree1 = solu.reConstructBinaryTree(pre,vin);
// //     TreeNode* tree2 = solu.reConstructBinaryTree(pre2,vin2);
// //     cout << solu.HasSubtree(tree1,tree2) << '\n';
// // //6 -1 0 1 2 -1 -4 
// //     return 0;
// // } */


// // /* ------------------ 输入两个二叉树链表A、B 判断子树  ----------------------------
// // #include<iostream>
// // #include<cstdio>
// // #include<queue>
// // struct TreeNode {
// // 	int val;
// // 	struct TreeNode *left;
// // 	struct TreeNode *right;
// // 	TreeNode(int x) :
// // 			val(x), left(NULL), right(NULL) {
// // 	}
// // };

// // using namespace std;
// // class Solution {
// // public:
// //     bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
// //     {
// //         if(pRoot2==nullptr) return false;
// //         if(pRoot1==nullptr) return false;

// //         TreeNode* p1 = pRoot1;
// //         TreeNode* p2 = pRoot2;
// //         queue<TreeNode*> ver;
// //         ver.push(p1);
// //         while(!ver.empty())
// //         {
// //             TreeNode* cur = ver.front();
// //             cout<< cur->val << ' ';
// //             if(cur->val==p2->val)
// //             {
// //                //左子树 右子树也重合  则输出true
// //                 if (((p2->left==nullptr) || HasSubtree(cur->left,p2->left))
// //                        && ((p2->right==nullptr) || HasSubtree(cur->right,p2->right)))
// //                     return true;
// //             }
// //             if(cur->left!=nullptr) ver.push(cur->left);
// //             if(cur->right!=nullptr) ver.push(cur->right);
// //             ver.pop();
// //         }

// //         return false;
// //     }
// // };
// // int main(void)
// // {
// //     Solution solu;
// //     TreeNode p1(3),n1(5),n2(7),n3(6),n4(2),n5(1),n6(4),n7(11),n8(10);
    
// //     p1.left=&n1; p1.right=&n2;
// //     n1.left=&n3;n1.right=&n4;
// //     n3.left=&n7;

// //     n2.left=&n5;n2.right=&n6;
// //     n5.right=&n8;


// //     TreeNode p2(5),n_1(2);
// //     p2.right=&n_1;
// //     std::cout << '\n' << solu.HasSubtree(&p1,&p2) << '\n';

// //     return 0;
// // } */

// // /* ------------------  将二叉树链表镜像输出  ----------------------------

// // #include<iostream>
// // #include<cstdio>
// // #include<queue>
// // struct TreeNode {
// // 	int val;
// // 	struct TreeNode *left;
// // 	struct TreeNode *right;
// // 	TreeNode(int x) :
// // 			val(x), left(NULL), right(NULL) {
// // 	}
// // };

// // using namespace std;
// // class Solution {
// // public:
// // public:
// //     void Mirror(TreeNode *pRoot) {
// //         if((pRoot == nullptr) ) return;

// //         swap(pRoot->left,pRoot->right);
        
// //         Mirror(pRoot->left);
// //         Mirror(pRoot->right);
// //     }
// // };
// // int main(void)
// // {
// //     Solution solu;
// //     TreeNode p1(3),n1(5),n2(7),n3(6),n4(2),n5(1),n6(4),n7(11),n8(10);
    
// //     p1.left=&n1; p1.right=&n2;
// //     n1.left=&n3;n1.right=&n4;
// //     n3.left=&n7;

// //     n2.left=&n5;n2.right=&n6;
// //     n5.right=&n8;


// //     TreeNode p2(5),n_1(2);
// //     p2.right=&n_1;
// //     solu.Mirror(&p1) ;
// //     std::cout << n2.right->val << '\n';
// //     return 0;
// // }  */


// // /* ------------------  顺时针打印矩阵  好tm无聊的题目 ----------------------------

// // #include<iostream>
// // #include<cstdio>
// // #include<queue>

// // using namespace std;
// // class Solution {
// // public:
// //     vector<int> printMatrix(vector<vector<int>>& matrix) {
// //        vector<int> out ;

// //        if(matrix.empty()) return out;

// //         int row = matrix.size();
// //         int col = matrix[0].size();
// //         int left_i=0,left_j=0;
// //         int right_i=row-1,right_j=col-1;
       
// //     while((left_i<=right_i)&&(left_j<=right_j))
// //     {
// //        for( int k=left_j;k<=right_j;k++)
// //         out.push_back(matrix[left_i][k]);
        
// //         if(left_i==right_i) return out;
        
// //        for( int k=left_i+1;k<=right_i;k++)
// //         out.push_back(matrix[k][right_j]);

// //        if(left_j==right_j) return out;

// //        for( int k=right_j-1;k>=left_j;k--)
// //         out.push_back(matrix[right_i][k]);

// //        for( int k=right_i-1;k>left_i;k--)
// //         out.push_back(matrix[k][left_j]);
            
// //        left_i ++; left_j ++;
// //        right_i--; right_j--;
// //     }
// //     return out;
// //     }
// // };
// // int main(void)
// // {
// //     Solution solu;
// //     int dim;
// //    while(~scanf("%d",&dim)!=EOF)
// //    {
// //           int num=0;
// //        vector<vector<int>> mat;
// //        vector<int> res;
// //        for(int i=0;i<dim;i++)
// //        {
// //         vector<int> row;
// //          for(int k=0;k<dim;k++)
// //             {
// //                 num++;
// //                 row.push_back(num);
// //             }
// //             mat.push_back(row);
// //        }

// //      res =  solu.printMatrix(mat);
// //      for(auto&data:res)
// //         std::cout << data << '\n';
// //    }
    
// //     return 0;
// // }*/

// // /* ------------------  包含min功能的栈 有点简单 ----------------------------

// // #include<iostream>
// // #include <stdio.h>
// // #include<stack>
// // class Solution {
// // public:
// //     std::stack<int> min_st;
// //     std::stack<int> st2;
// //     void push(int value) {
// //         st2.push(value);
// //         if(min_st.empty())
// //         {
// //             min_st.push(value);
// //         }
// //         else
// //         {
// //             if(value<=min_st.top())
// //                 {
// //                     min_st.push(value);
// //                 }
// //         }
// //     }
// //     void pop() {
// //         //若弹出最小数据
// //         if(!min_st.empty()) 
// //             if(st2.top()==min_st.top())
// //                  min_st.pop();
// //         st2.pop();
// //     }
// //     int top() {
// //         return st2.top();
// //     }
// //     int min() {
// //         return min_st.top();
// //     }
// // };  
// // int main(int argc, char* argv[])  
// // {  
// //     Solution solu;



// //     return 0;  
// // }  */

// // /* ------------------  判断 栈的压入、弹出序列 自己的写法好蠢，没考虑逆向思维----------------------------

// // #include<iostream>
// // #include <stdio.h>
// // #include<stack>
// // #include<vector>
// // using namespace std;
// // class Solution {
// // public:
// //     bool IsPopOrder(vector<int> pushV,vector<int> popV) {
// //         if(popV.empty()) return false;
// //         if(popV.size()!=pushV.size()) return false;
// //         vector<int> vis;
// //         int i,pos_pre=-1;
// //         for( i=0;i<pushV.size();i++)
// //         {
// //             vis.push_back(0);
// //             if(popV[0]==pushV[i]) 
// //             {
// //                 pos_pre=i;
// //                 vis[i]=1;
// //             }
// //         }
// //         if(pos_pre==-1) return false;

// //         for(int k=1;k<popV.size();k++)
// //         {
// //             int i;
// //             bool left_find=false;
// //             for(i=pos_pre-1;i>=0;i--)
// //             {
// //               if(vis[i]==0)
// //               {
// //                   if(popV[k]==pushV[i])
// //                   {
// //                       vis[i]=1;
// //                       pos_pre = i;
// //                       left_find=true;
// //                       break;
// //                   }
// //                   break;
// //               }
// //             }
// //             if(left_find) continue;
            
// //             for(i=pos_pre+1;i<pushV.size();i++)
// //             {
// //                 if(popV[k]==pushV[i])
// //                 {
// //                     pos_pre = i;
// //                     vis[i]=1;
// //                     break;
// //                 }
// //             }
// //             if(i!=pushV.size()) continue;
// //             else 
// //                 return false;
// //         }
// //         return true;
// //     }
// // }; 
// // int main(int argc, char* argv[])  
// // {  
// //     Solution solu;
// //     cout << solu.IsPopOrder({1,2,3,4,5},{3,5,4,2,1});


// //     return 0;  
// // } */

// // /* ------------------  层序遍历 （迭代方法）----------------------------

// // #include<iostream>
// // #include<cstdio>
// // #include<queue>
// // struct TreeNode {
// // 	int val;
// // 	struct TreeNode *left;
// // 	struct TreeNode *right;
// // 	TreeNode(int x) :
// // 			val(x), left(NULL), right(NULL) {
// // 	}
// // };

// // using namespace std;
// // class Solution {
// // public:
// //     vector<int> PrintFromTopToBottom(TreeNode* root) {
// //         vector<int> out;
// //         queue<TreeNode*> ver;
// //         ver.push(root);
// //         while(!ver.empty())
// //         {
// //             out.push_back(ver.front()->val) ;
// //             if(ver.front()->left!=nullptr) ver.push(ver.front()->left);
// //             if(ver.front()->right!=nullptr) ver.push(ver.front()->right);
// //             ver.pop();
// //         }

// //         return out;
// //     }
// // };
// // int main(void)
// // {
// //     Solution solu;
// //     TreeNode p1(3),n1(5),n2(7),n3(6),n4(2),n5(1),n6(4),n7(11),n8(10);
    
// //     p1.left=&n1; p1.right=&n2;
// //     n1.left=&n3;n1.right=&n4;
// //     n3.left=&n7;

// //     n2.left=&n5;n2.right=&n6;
// //     n5.right=&n8;


// //     TreeNode p2(5),n_1(2);
// //     p2.right=&n_1;
// //     vector<int> res;
// //     res=solu.PrintFromTopToBottom(&p1);
// //     for(auto&da:res)
// //         std::cout << da << '\n';
// //     return 0;
// // }*/

// // /* ------------------ 判断序列是否是BST的后序输出  走了弯路  重做！  ----------------------------
// // #include<iostream>
// // #include<cstdio>
// // #include<queue>
// // #include<algorithm>
// // struct TreeNode {
// // 	int val;
// // 	struct TreeNode *left;
// // 	struct TreeNode *right;
// // 	TreeNode(int x) :
// // 			val(x), left(NULL), right(NULL) {
// // 	}
// // };

// // using namespace std;
// // class Solution {
// // public:
// //     bool find(vector<int>list,int data)
// //     {
// //         vector<int>::iterator it=list.begin();
// //         while(it != list.end())
// // 	 {   
// // 	      if(*it==data) break;
// // 	      it++;
// // 	 }
// //      if(it==list.end()) return false;
// //      return true;
// //     }
// //     bool VerifySquenceOfBST(vector<int> sequence) {
// //         if(sequence.empty()) 
// //         {
// //             std::cout << "empty" << '\n';
// //             return false;
// //         }
// //         if(sequence.size()==1) return true;

// //         vector<int> mid_seq(sequence);
// //         sort(mid_seq.begin(),mid_seq.end());
// //         vector<int>left_tree,right_tree;
// //         for(int i=0;i<mid_seq.size();i++)
// //         {
// //             if(mid_seq[i]<sequence.back())
// //             {
// //                 left_tree.push_back(mid_seq[i]);
// //             }
// //             else if(mid_seq[i]>sequence.back())
// //             {
// //                 right_tree.push_back(mid_seq[i]);
// //             }
// //         }
// //         int root=sequence.back();
// //         sequence.pop_back();
// //         vector<int>left_tree_be,right_tree_be;
// //         for(int i=0;i<right_tree.size();i++)
// //         {
// //             if(!find(right_tree, sequence.back()))
// //                  return false;
// //             if(sequence.back()<root) return false;
// //             right_tree_be.insert(right_tree_be.begin(),sequence.back());
// //             sequence.pop_back();
// //         }
// //         for(int i=0;i<left_tree.size();i++)
// //         {
// //             if(!find(left_tree, sequence.back()))
// //                  return false;
// //             if(sequence.back()>root) return false;
// //             left_tree_be.insert(left_tree_be.begin(),sequence.back());
// //             sequence.pop_back();
// //         }
// //         for(auto&da:left_tree_be) std::cout << da << " ";
// //         std::cout << " || " ;
// //         for(auto&da:right_tree_be) std::cout << da << "  ";


// //         if(left_tree.empty())
// //             {if(!VerifySquenceOfBST(right_tree_be)) return false;}
// //         if(right_tree.empty())    
// //             {if(!VerifySquenceOfBST(left_tree_be)) return false;}

// //         if(!right_tree.empty()&&!left_tree.empty())
// //         {if(!(VerifySquenceOfBST(left_tree_be)&&VerifySquenceOfBST(right_tree_be))) return false;}

// //         return true;
        
// //     }
// // };

// // int main(void)
// // {
// //     Solution solu;
// //     TreeNode p1(3),n1(5),n2(7),n3(6),n4(2),n5(1),n6(4),n7(11),n8(10);
    
// //     p1.left=&n1; p1.right=&n2;
// //     n1.left=&n3;n1.right=&n4;
// //     n3.left=&n7;

// //     n2.left=&n5;n2.right=&n6;
// //     n5.right=&n8;


// //     TreeNode p2(5),n_1(2);
// //     p2.right=&n_1;
// //     vector<int> res;

// //     std::cout << solu.VerifySquenceOfBST({4,6,7,5}) << '\n';
// //     // for(auto&da:res)
// //     //     std::cout << da << '\n';
// //     return 0;
// // }*/

// // /* ------------------ 特殊链表的复制 特殊链表的复制  ----------------------------

// // #include<iostream>
// // #include<cstdio>
// // #include<queue>
// // #include<algorithm>
// // #include<stack>
// // struct RandomListNode {
// //     int label;
// //     struct RandomListNode *next, *random;
// //     RandomListNode(int x) :
// //             label(x), next(NULL), random(NULL) {
// //     }
// // };

// // using namespace std;
// // class Solution {
// // public:
// //     RandomListNode* Clone(RandomListNode* pHead)
// //     {
// //         if(pHead==nullptr) return nullptr;
// //         RandomListNode *node=pHead;
// //         while(node!=nullptr)
// //         {
// //             RandomListNode *currNode = new RandomListNode(node->label);
// //             currNode->next = node->next;
// //             node->next = currNode;
// //             node = currNode->next;
// //         }
// //         node =pHead;
// //         while(node!=nullptr)
// //         {
// //             if(node->random!=nullptr)
// //                 node->next->random = node->random->next;
            
// //             node = node->next->next;
// //         }
// //         RandomListNode *pre = pHead->next;
// //         RandomListNode *tmp ;
// //         node=pHead;
// //         while(node->next!=nullptr)
// //         {
// //             tmp = node->next;
// //             node->next = tmp->next;
// //             node = tmp;
// //         }
// //         return pre;
// //     }
// // };

// // int main(void)
// // {
// //     Solution solu;

// //     return 0;
// // }*/

// // /*---------------------- 空瓶换可乐----------------------

// // #include <iostream>
// // #include <cstdio>
// // using namespace std;


// // int coke(int bottle)
// // {
// //     if(bottle<3)
// //     {
// //         if(bottle<2) return 0;
// //         else return 1;
// //     }

// //     return (bottle/3 + coke(bottle%3+bottle/3));
// // }
// // int main(void)
// // {

// //     int bottle;
// //     while(scanf("%d",&bottle)!=EOF)
// //     {
// //         cout << coke(bottle) <<'\n';
// //     }

// //     return 0;
// // } */

// // /*---------------  将输入去重与排序  -----------
// // #include <iostream>
// // #include <cstdio>
// // #include<vector>
// // #include <algorithm>
// // using namespace std;

// // int main(void)
// // {

// //     int n;
// //     while(scanf("%d",&n)!=EOF)
// //     {
// //      vector<int> array;
// //      int data;
// //      for(int i=0;i<n;i++)
// //         {
// //             scanf("%d",&data);
// //             if(array.empty()) array.push_back(data);
// //             else
// //             {
// //                 int k=0;
// //                 for(k=0;k<array.size();k++)
// //                 {
// //                     if(array[k]==data) break;
// //                     if(array[k]>data)
// //                     {
// //                         array.insert(array.begin()+k,data);
// //                         break;
// //                     }
// //                     if(k==array.size()-1)
// //                     {
// //                         array.insert(array.end(),data);
// //                         break;
// //                     }
// //                 }
              
// //             }
// //         }   
// //         for(auto& da:array) std::cout << da << "\n";
// //     }

// //     return 0;
// // }*/

// // /*---------- 将输入十六进制(字符串)转换成十进制输出 -------------
// // #include <iostream>
// // #include <cstdio>
// // #include<vector>
// // #include <string>
// // using namespace std;
// // int po(int pow_)
// // {
// //     int res=1;
// //     for(int i=0;i<pow_;i++)
// //     {
// //         res *= 16;
// //     }
// //     return res;
// // }
// // int hex2int(string hex)
// // {
// //     int res=0;
// //     int pow_=1,num=0;
// //     for(int k=hex.size()-1;k>=0;k--)
// //     {
// //         char hex_ = hex[k];
// //         if((hex_=='x')||(hex_=='X')) return res;
// //         int trans;
// //         if((((int)hex_)>=48)&&(((int)hex_)<=57))
// //         {
// //             trans = ((int)hex_) - 48;
// //         }
// //         else  if((((int)hex_)>=97)&&(((int)hex_)<=102))
// //         {
// //             trans = ((int)hex_) - 87;
// //         }
// //         else  if((((int)hex_)>=65)&&(((int)hex_)<=70))
// //         {
// //             trans = ((int)hex_) - 55;
// //         }

// //         res += trans * pow_;
// //         num++;
// //         pow_ = po(num);
// //     }
// //     return res;
// // }
// // int main(void)
// // {

// //     string str;
// //     while(getline(cin,str))
// //     {
// //         std::cout << hex2int(str) << '\n';
// //     }
// //     return 0;
// // }*/

// // /*--------- sort 自定义排序 （函数 + lamda）----------

// // #include <iostream>
// // #include <cstdio>
// // #include <vector>
// // #include <algorithm>
// // using namespace std;
// // bool compare(string s1,string s2)
// // {
// //     return s1.length()>s2.length();
// // }
// // int main(void)
// // {

// //     int n;
// //     while(scanf("%d",&n)!=EOF)
// //     {
// //         string str;
// //         vector<string> str_vec;
// //         for(int k=0;k<n;k++)
// //             {
// //                 cin >> str;
// //                 str_vec.push_back(str);
// //             }
// //             sort(str_vec.begin(),str_vec.end(),[](string s1,string s2){return s1.length()>s2.length();});
// //             for(auto&da:str_vec) std::cout << da << '\n';
// //     }

// //     return 0;
// // }*/


// // /*---------------------- 输出字符串包含的字符集合 ------------------------
// // #include <iostream>
// // #include <cstdio>
// // #include <vector>
// // #include <algorithm>
// // #include <queue>
// // using namespace std;
// // bool find(vector<char> vec,char ch)
// // {
// //     vector<char>::iterator it=vec.begin();
// //     while(it!=vec.end())
// //     {
// //         if(*it==ch) return true;
// //         it++;
// //     }
// //     return false;
// // }
// // vector<char> gather(string str)
// // {
// //     vector<char> res;
// //     for(int k=0;k<str.size();k++)
// //     {
// //         char ch = str[k];
// //         if(find(res,ch)) continue;
// //         res.push_back(ch);
// //     }
// //     return res;
// // }
// // int main(void)
// // {

// //     int n;
// //     string str;
// //     while(getline(cin,str))
// //     {
// //         vector<char> res;
// //         res = gather(str);
// //         for(auto&ch:res) cout<< ch;
// //         std::cout  << '\n';
// //     }
// //     return 0;
// // } */
// // /*
// // 0 0 8 0 0 0 2 0 0
// // 0 3 0 8 0 2 0 6 0
// // 7 0 0 0 9 0 0 0 5
// // 0 5 0 0 0 0 0 1 0
// // 0 0 4 0 0 0 6 0 0
// // 0 2 0 0 0 0 0 7 0
// // 4 0 0 0 8 0 0 0 6
// // 0 7 0 1 0 3 0 9 0
// // 0 0 1 0 0 0 8 0 0
// // */

// // //scanf 如果是 %d、%f 读入数值类型，会自动跳过多余的空格和换行，
// // //如果是  %s  遇到空格和换行会停止，如果是  %c  就可以读入空格和换行。

// // /*--------------- 修改和查询学生成绩---------------

// // #include <iostream>
// // #include <cstdio>
// // #include <vector>
// // #include <algorithm>
// // #include <queue>
// // using namespace std;

// // int main(void)
// // {

// //     int n,op;
// //     while(scanf("%d%d",&n,&op)!=EOF)
// //     {
// //         vector<int> grades;
// //         scanf("\n");
// //         for(int i =0;i<n;i++)
// //         {
// //             int data;
// //             scanf("%d",&data);
// //             grades.push_back(data);
 
// //         }
// //         for(int i=0;i<op;i++)
// //         {
// //             char cmd;int arg1,arg2;
// //             scanf("\n");
// //             scanf("%c%d%d",&cmd,&arg1,&arg2);
// //             if(cmd=='Q')
// //             {
// //                 int max=-1;
// //                 if(arg1>arg2) swap(arg1,arg2);
// //                 for(int k=arg1-1;k<arg2;k++)
// //                 {
// //                     if(grades[k]>max) max=grades[k];
// //                 }
// //                 std::cout <<max << '\n';
// //             }
// //             else if(cmd=='U')
// //             {
// //                 grades[arg1-1]=arg2;
// //             }
// //         }

// //     }
// //     return 0;
// // }*/

// // /*------------- 错误记录 读不确定行字符串 ---------------
// // #include <map>
// // #include<iostream>
// // #include<cstdio>
// // #include<vector>
// // #include<string>
// // #include <algorithm>
// // using namespace std;


// // vector<pair<string,int>> pair_vec;

// // void deal_input(string input)
// // {
// //     int k,depa=-1;
// //     for(k=input.size()-1;k>=0;k--)
// //     {
// //         if(input[k]=='\\') break;
// //         if(input[k]==' ')
// //             if(depa==-1)
// //             {
// //                 depa=k;
// //             }
// //     }
// //     string name = input.substr(k+1);

// //     pair_vec.push_back(make_pair(name,1));

// //     for (int i = 0; i<(pair_vec.size() - 1); i++){
// //         if (pair_vec[i].first == name){
// //             pair_vec[i].second++;
// //             pair_vec.pop_back(); break;
// //         }
// //     }
// // }
// // bool cmp(pair<string,int>x,pair<string,int>y)
// // {
// //     return x.second>y.second;
// // }

// // int str2int(string input)
// // {
// //     int num=0,i=0;
// //      for(int k=input.size()-1;k>=0;k--)
// //      {
// //          num += ((input[k]-48) *pow(10,i));
// //          i++;
// //      }
// //      return num;
// // }
// // void deal(string input)
// // {
// //         int k,depa=-1;
// //     for(k=input.size()-1;k>=0;k--)
// //     {
// //         if(input[k]=='\\') break;
// //         if(input[k]==' ')
// //             if(depa==-1)
// //             {
// //                 depa=k;
// //             }
// //     }
// //     string name;
// //     string out;
// //     name = input.substr(k+1,depa-k-1);
// //     if(name.size()>16)
// //         {
// //             out = name.substr(name.size()-16);
// //             cout<< out<<" ";
// //         }
// //     else
// //     cout<< name<<" ";
// //     string num;
// //     num = input.substr(depa+1);
// //     cout<< str2int(num);
// // }
// // int main(void)
// // {
// //     string str;
// //     vector<string> arr_str;
// //     while (getline(cin, str))
// //     {
// //         if (str.size() == 0)
// //             break;
// //         deal_input(str);
// //     }
// //     sort(pair_vec.begin(),pair_vec.end(),cmp);
// //     int i=0;
// //     for(auto&da:pair_vec)
// //     {
// //         i++;
// //         deal(da.first);
// //         cout<<" "<<da.second << endl;
// //         if(i==8) break;
// //     }
    
// //     return 0;
// // }*/

// // /*------------  卡牌游戏  方法太笨--------------
// // #include<iostream>
// // #include<cstdio>
// // #include<string>
// // #include<sstream>
// // #include<vector>
// // #include<math.h>
// // #include<algorithm>
// // using namespace std;
// // typedef enum _type
// // {
// //     joke_boom,
// //     com_4,
// //     seq,
// //     com_3,
// //     com_2,
// //     com_1,
// //     non_type
// // }car_type;
// // typedef struct group
// // {
// //     car_type type=non_type;
// //     string card_str;
// //     vector<int>card_id;
// // }group;
// // int str2int(string input)
// // {
// //     int num=0,i=0;

// //     if(input.compare("J")==0) return 11;
// //     if(input.compare("Q")==0) return 12;
// //     if(input.compare("K")==0) return 13;
// //     if(input.compare("A")==0) return 14;
// //     if(input.compare("2")==0) return 16;
// //     else
// //     {
// //     for(int k=input.size()-1;k>=0;k--)
// //      {
// //          num += ((input[k]-48) *pow(10,i));
// //          i++;
// //      }
// //     }
// //      return num;
// // }

// // void check_type(group& card)
// // {   
// //     string card_st = card.card_str,word;
// //     vector<int>s_card;
// //     std::stringstream ss(card_st);
// //     while(ss >> word)
// //         {
// //          if((word.compare("joker")==0)||(word.compare("JOKER")==0))
// //           {
// //             s_card.push_back(-1);
// //           }
// //         else
// //             s_card.push_back(str2int(word));
// //         }
// //             sort(s_card.begin(),s_card.end());
// //             card.card_id = s_card;

// //     if(s_card.size()==1)
// //     {
// //         card.type=com_1;
// //     }
// //     else if(s_card.size()==2)
// //     {
// //         if((s_card[0]==-1)&&(s_card[1]==-1))
// //         {
// //             card.type=joke_boom;
// //         }
// //         else if(s_card[0]==s_card[1])
// //         {
// //             card.type=com_2;
// //         }
// //     }
// //     else if(s_card.size()==3)
// //     {
// //         if(s_card[0]==s_card[1])
// //         {
// //             if(s_card[0]==s_card[2])
// //                 card.type=com_3;
// //         }
// //     }
// //     else if(s_card.size()==4)
// //     {
// //         if(s_card[0]==s_card[1])
// //         {
// //             if(s_card[0]==s_card[2])
// //                 if(s_card[0]==s_card[3])
// //                 card.type=com_4;
// //         }
// //     }
// //     else if(s_card.size()==5)
// //     {
// //         if((s_card[4]-s_card[0])==4)
// //             if((s_card[3]-s_card[0])==3)
// //                 if((s_card[2]-s_card[0])==2)
// //                     if((s_card[1]-s_card[0])==1)
// //                         card.type=seq;
// //     }
    
// // }
// // bool depart_inpur(string input,group& a,group& b)
// // {   
// //     size_t found;
// //     found = input.rfind("-");
// //     if(found!=string::npos)
// //     {
// //         a.card_str = input.substr(0,found);
// //         b.card_str = input.substr(found+1); 
// //         check_type(a);
// //         if(a.type==non_type) return true;
// //         check_type(b);
// //         return true;
// //     }
// //     return false;
// // }
// // int main(void)
// // {
// //     string input;
// //     while(getline(cin,input))
// //     {
// //         group group_a,group_b;
// //         if(depart_inpur(input,(group_a),(group_b))) 
// //         {
// //             if((group_a.type==non_type)||(group_b.type==non_type))
// //             {
// //                 cout<< "ERROR"<<endl;
// //             }
// //             else
// //             {
// //                 if(group_a.type==joke_boom)
// //                 {
// //                     cout<< group_a.card_str <<endl;
// //                 }
// //                 else if(group_b.type==joke_boom)
// //                 {
// //                     cout<< group_b.card_str <<endl;
// //                 }            
// //                 else 
// //                 {
// //                     //都不是对王
// //                     if(group_b.type==com_4)
// //                     {
// //                         if(group_a.type==com_4)
// //                         {
// //                             if((group_b.card_id[0]>group_a.card_id[0]))
// //                                 cout<< group_b.card_str <<endl;
// //                             else cout<< group_a.card_str <<endl;
// //                         }
// //                         else  cout<< group_b.card_str <<endl;
// //                     }
// //                     else if(group_a.type==com_4)
// //                     {
// //                         cout<< group_a.card_str <<endl;
// //                     }
// //                     else if(group_b.type==com_3)
// //                     {
// //                             if(group_a.type==com_3)
// //                         {
// //                             if((group_b.card_id[0]>group_a.card_id[0]))
// //                                 cout<< group_b.card_str <<endl;
// //                             else cout<< group_a.card_str <<endl; 
// //                         }
// //                         else  cout<< "ERROR" <<endl;
// //                     }
// //                     else if(group_b.type==com_2)
// //                     {
// //                         if(group_a.type==com_2)
// //                         {
// //                             if((group_b.card_id[0]>group_a.card_id[0]))
// //                                 cout<< group_b.card_str <<endl;
// //                             else cout<< group_a.card_str <<endl;
// //                         }
// //                         else  cout<< "ERROR" <<endl;      
// //                     }
// //                     else if(group_b.type==com_1)
// //                     {
// //                         if(group_a.type==com_1)
// //                         {
// //                             if((group_b.card_id[0]>group_a.card_id[0]))
// //                                 cout<< group_b.card_str <<endl;
// //                             else cout<< group_a.card_str <<endl;
// //                         }
// //                         else  cout<< "ERROR" <<endl;                        
// //                     }
// //                     else if(group_b.type==seq)
// //                     {
// //                         if(group_a.type==seq)
// //                         {
// //                             if((group_b.card_id[0]>group_a.card_id[0]))
// //                                 cout<< group_b.card_str <<endl;
// //                             else cout<< group_a.card_str <<endl;
// //                         }
// //                         else  cout<< "ERROR" <<endl;
// //                     }
// //                 }
// //             }
            
// //         }
// //     }

// //     return 0;
// // }*/


// // /*-------------  括号匹配 ------------
// // #include<iostream>
// // #include<cstdio>
// // #include<string>
// // #include<sstream>
// // #include<vector>
// // #include<math.h>
// // #include<algorithm>
// // #include<stack>
// // using namespace std;
// // int main(void)
// // {

// //     string input;
// //     while(getline(cin,input))
// //     {
// //             stack<char> sig;
// //         for(int i=input.size()-1;i>=0;i--)
// //         {
// //             char ch = input[i];
// //             if(ch=='}') sig.push('}');
// //             else if(ch==']')  sig.push(']');
// //             else if(ch==')') sig.push(')');

// //             else if(ch=='{')
// //             {
// //                 if(sig.top()=='}')
// //                 {
// //                     sig.pop();
// //                 }
// //                 else 
// //                 {
// //                     std::cout << "False" << '\n';
// //                     return 0;
// //                 }
// //             }
// //             else if(ch=='[')
// //             {
// //                 if(sig.top()==']')
// //                 {
// //                     sig.pop();
// //                 }
// //                 else 
// //                 {
// //                     std::cout << "False" << '\n';
// //                     return 0;
// //                 }
// //             }
// //             else if(ch=='(')
// //             {
// //                 if(sig.top()==')')
// //                 {
// //                     sig.pop();
// //                 }
// //                 else 
// //                 {
// //                     std::cout << "False" << '\n';
// //                     return 0;
// //                 }
// //             }
// //         }
// //         if(sig.empty()) std::cout << "True" << '\n';
// //             else std::cout << "False" << '\n';
// //     }

// //     return 0;
// // } */

// // /*-------------桶排序问题----------------
// // #include <iostream>
// // #include<cstdio>
// // #include<queue>
// // using namespace std;
// // void printOrder(const int input[], int len)
// // {
// //     queue<int> barrel[10];
// //     for(int i=0;i<len;i++)
// //     {
// //         barrel[input[i]].push(i);
// //     }
// //     for(int i=9;i>0;i--)
// //     {
// //         if(!barrel[i].empty())
// //         {
// //             while(!barrel[i].empty())
// //             {
// //                 std::cout << barrel[i].front() << " ";
// //                 barrel[i].pop();
// //             }
// //         }
// //     }
// //     cout<<'\n';
// // }
// // int main(void)
// // {
// //     int input[9]={9,3,5};
// //     printOrder(input,9);

// //     return 0;
// // }*/


// // /* ---------- 删除重复出现数字 ------------
// // #include<iostream>
// // #include<cstdio>
// // #include<sstream>
// // #include<vector>
// // #include<math.h>
// // #include<algorithm>
// // #include<map>
// // using namespace std;
// // int str_int(string input)
// // {
// //     int num=0,i=0;
// //     if(input.compare("0")==0) return 0;
// //      for(int k=input.size()-1;k>=0;k--)
// //      {
// //          num += ((input[k]-48) *pow(10,i));
// //          i++;
// //      }
// //      return num;
// // }
// // bool cmp_1(const pair<unsigned int,unsigned int>a,const pair<unsigned int,unsigned int>b)
// // {
// //     return a.first<b.first;

// //     // if(a.first!=b.first) return a.first<b.first;
// //     // else return a.second<b.second;
// // }
// // bool cmp_2(const pair<unsigned int,unsigned int>a,const pair<unsigned int,unsigned int>b)
// // {
// //      return a.second<b.second;
// // }
// // int main(void)
// // {

// //     string input;

// //     while(getline(cin,input))
// //     {
// //         string word;
// //         vector<pair<unsigned int,unsigned int>>ch_vec;
// //         std::stringstream ss(input);
// //         int i=0;
// //         if(input.empty()) continue;
// //         while(ss >> word)
// //         {
// //             ch_vec.push_back(make_pair(str_int(word),i));
// //             i++;
// //         }
// //         cout << '\n';
// //         for(auto&da:ch_vec)
// //           {
// //               std::cout <<da.first<<"  下标： "<< da.second;
// //             cout << '\n';
// //           }  
// // cout << '\n';
// //         sort(ch_vec.begin(),ch_vec.end(),cmp_1);

// //         for(auto&da:ch_vec)
// //           {
// //               std::cout <<da.first<<"  下标： "<< da.second;
// //             cout << '\n';
// //           }  

// //         int base=ch_vec[0].first;
// //         for(int i=1;i<ch_vec.size();i++)
// //         {
// //             if(ch_vec[i].first==base)
// //             {
// //                 ch_vec.erase(ch_vec.begin()+i);
// //                 i--;
// //             }
// //             else
// //             {
// //                 base = ch_vec[i].first;
// //                 // 1 1 2 3 3 2 4 5 1 8 4 2 7 3 6 4 5 1 
// //             }
            
// //         }
// //         sort(ch_vec.begin(),ch_vec.end(),cmp_2);
// //         cout <<endl;
// //         for(auto &num:ch_vec)
// //             std::cout << num.first << " ";
// //     }



// //     return 0;
// // }*/

// // /* --------剑指offer 回溯法 字符串的全排列 （递归） ------------
// // // tips:字符串的 字典序 要逐个字符比对 不相等处停止！！

// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <string.h>
// // #include<algorithm>
// // #include<iostream>
// // #include<vector>
// // using namespace std;
// // class Solution {
// // public:
// //     vector<string> res;
// //     vector<char> has_ex;
// //     vector<string> Permutation(string str) { 
// //        Permutation_helper(str,0,str.size());  
// //        sort(res.begin(),res.end());
// //        return res;   
// //     }
// //     void Permutation_helper(string str,int begin,int end)
// //     {
// //         if(begin == end-1)
// //         {
// //             //实现n个字符的全排列 只需排好后面的n-1个字符
// //             // 再将排好的n-1个字符与其做交换（不相等的情况下）
// //             res.push_back(str);
// //         }
// //         else
// //         {
// //             for(int k=begin;k<end;k++)
// //             {
// //                 swap(str[k],str[begin]);

// //                 if((k!=begin)&&(str[k]==str[begin])) ;
// //                 else
// //                     Permutation_helper(str,begin+1,end);
// //                 swap(str[k],str[begin]);
// //             }           
// //         }

// //     }
// // };

// // int main()
// // {

// //     Solution solu;
// //     string input;

// //     while (getline(cin,input)) {

// //         vector<string> res = solu.Permutation(input);

// //         for(auto &str:res)
// //             std::cout << str << '\n';
// //     }       
 
// //     return 0;
// // }*/


// // /*-----------  剑指offer 数组中出现次数超过一半的数字 --------------
// // //如果用了排序直接 取中间就可以！！！！
// // // 复杂度主要在用了排序算法 非最优
// // //最优复杂度： n
// // #include<iostream>
// // #include<cstdio>
// // #include<vector>
// // #include<algorithm>
// // using namespace std;
// // class Solution {
// // public:
// //     int MoreThanHalfNum_Solution(vector<int> numbers) {
// //         if(numbers.size()==1) return numbers[0];

// //         int half_min=numbers.size()/2;
// //         int left=0,right=numbers.size()-1;

// //         sort(numbers.begin(),numbers.end());

// //         while(left<=right-half_min)
// //         {
// //             if(numbers[left]!=numbers[left+half_min])
// //             {
// //                 ++left;
// //             }
// //             else return numbers[left]; 
// //             if(numbers[right]!=numbers[right-half_min])
// //             {
// //                 --right;
// //             }
// //             else return numbers[left]; 
// //         }
// //         return 0;
// //     }
// // };
// // int main(void)
// // {

// //     Solution solu;

// //     cout <<solu.MoreThanHalfNum_Solution({1,2,3,2,4,2,5,2,3});

// //     return 0;
// // }*/



// // /*-----------  剑指offer 最小的k个数 -------------- 
// // //复杂度： lgn
// // //这个办法不行
// // #include<iostream>
// // #include<cstdio>
// // #include<vector>
// // #include<algorithm>
// // using namespace std;
// // class Solution {
// // public:
// //    // 我的方法 最坏nlogn
// //     vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
// //         vector<int> res;
// //         if(input.size()<k) return res; 
// //         res=input;
// //         while(res.size()>k)
// //         {
// //             for(int i=0;i<res.size();i++)
// //             {
// //                 if(i+1>=res.size()) continue;
// //                 if(res[i]>res[i+1])
// //                 {
// //                     res.erase(res.begin()+i);
// //                     i--;
// //                 }
// //                 else
// //                 {
// //                     res.erase(res.begin()+i+1);
// //                 }
// //             }
// //         }
 
// //         sort(res.begin(),res.end());
// //         return res;
// //     }
// //     // 别人的方法 nlgk
// //     vector<int> GetLeastNumbers_Solution_2(vector<int> input, int k) {
        
// //         if(input.size()<k) return vector<int>(); 
// //         vector<int> res(input.begin(),input.begin()+k);
// //         // 建堆 将最大元素上浮
// //         make_heap(res.begin(),res.end());
        
// //         //留出前k个位置
// //         for(int i=k;i<input.size();i++)
// //         {
// //             if(input[i]<res[0])
// //             {
// //                 //删除堆顶 （最大值）
// //                 res.erase(res.begin());

// //                 res.push_back(input[i]);
// //                 // 将最大值上浮
// //                 push_heap(res.begin(),res.end());
// //             }
// //         }
// //         // sort_heap(res.begin(),res.end());
// //         return res;
// //     }
// // };
// // int main(void)
// // {

// //     Solution solu;
// //     vector<int> test =  solu.GetLeastNumbers_Solution_2({4,5,1,6,2,7,3,8},3);

// //     for(auto&data:test)
// //         std::cout << data << '\n';

// //     return 0;
// // }*/

// // /*----------- 剑指offer 连续子数组的最大和 ---------------

// // // MAX[i] = max{MAX[i-1] + A[i],MAX[i-1]}；

// // // F（i）：以array[i]为末尾元素的子数组的和的最大值，子数组的元素的相对位置不变
// // // F（i）=max（F（i-1）+array[i] ， array[i]）
// // // res：所有子数组的和的最大值
// // // res=max（res，F（i））

// // #include<iostream>
// // #include<cstdio>
// // #include<vector>
// // using namespace std;
// // class Solution {
// // public:
// // //暴力 求解效率极低
// //     int FindGreatestSumOfSubArray(vector<int> array) {
// //         int max=-100;

// //         for(int left=0;left<array.size();left++)
// //         {
// //             int sum=0;
// //             for(int right=left;right<array.size();right++)
// //             {
// //                 sum += array[right];
// //                 if(sum > max) max=sum;
// //             }
// //         }

// //         return max;
// //     }
// // //dp动态规划 并输出了 区间
// //     int FindGreatestSumOfSubArray_2(vector<int> array) {
// //         int max=-100;
// //         int sum=0;
// //         int left=0,right=0;
// //         bool clear=false;
// //         for(int i=0;i<array.size();i++)
// //         {
// //             sum += array[i];
// //             if(sum>max) 
// //             {
// //                 max=sum;
// //                 if(clear)
// //                 {
// //                     left = right =i;
// //                 }
// //                 else
// //                 {
// //                     right=i;
// //                 }
// //                 clear = false;
// //             }
// //             if(sum<0) 
// //             {
// //                 sum=0;
// //                 clear = true;
// //             }
// //         }
// //         cout<< left <<" "<< right <<endl;
// //         return max;
// //     }
// // };
// // int main(void)
// // {


// //     Solution solu;
// //     cout << solu.FindGreatestSumOfSubArray_2({-4,6,-3,-1,-1,-2,7,-15,1,2,2})<<endl;

// //     return 0;
// // } */




// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include <math.h>
// #include <algorithm>
// #include <set>
// #include <stack>
// #include <queue>
// #include <string.h>
// using namespace std;
// class Solution {
// public:
// /* ----------- 剑指offer 0～n十进制 1出现的次数 ----------------*/
//     int NumberOf1Between1AndN_Solution(int n)
//     {
//         int cnt=0;

//         // 硬算
//         // 
//         // for(int i=1;i<=n;i++)
//         // {
//         //     int num=i;
//         //     while(num!=0)
//         //     {
//         //         if(num%10==1) cnt++ ;
//         //         num = num / 10;
//         //     }
//         // }


        

//         return cnt;
//     }

// /* ----------- 剑指offer 把数组排成最小的数 ----------------*/
// // 本质是个排序问题 又走了弯路。。。
//     static bool cmp(string a1,string b1)  //true： 替换a1
//     {
//        int len = ((a1.size() > b1.size())?: b1.size(),a1.size());
//        int i;

//        for(i=0;i<len;i++)
//        {
//            if(a1[i] > b1[i]) 
//            { 
//                return false;
//            }
//        }
//        while(i<b1.size())  
//        {
//            if(b1[i]<b1[0]) return false;
//            i++;
//        }     
           
//        return true;
//     }

//     string PrintMinNumber(vector<int> numbers) {
//         if(numbers.empty()) return "";
//         vector<string> str_array;

//         for(int i=0;i<numbers.size();i++)
//         {
//             str_array.push_back(to_string(numbers[i]));
//         }


//         if(str_array.size()==1) return str_array[0];
//         string res;
//         sort(str_array.begin(),str_array.end(),cmp);

//         for(auto&data:str_array)
//             res +=data;


//          // 牛客网解法 

//     //  static bool cmp(int a,int b){
//     //      string A="";
//     //      string B="";
//     //      A+=to_string(a);
//     //      A+=to_string(b);
//     //      B+=to_string(b);
//     //      B+=to_string(a);
          
//     //      return A<B;
//     //  }
//     //  string PrintMinNumber(vector<int> numbers) {
//     //      string  answer="";
//     //      sort(numbers.begin(),numbers.end(),cmp);
//     //      for(int i=0;i<numbers.size();i++){
//     //          answer+=to_string(numbers[i]);
//     //      }
//     //      return answer;
//     //  }

//         //第一次写出的程序：
//         // while(str_array.size()!=1)
//         // {
//         //     string suit = str_array[0];
//         //     int del=0;
//         //     for(int i=1;i<str_array.size();i++)
//         //     {
//         //      if(cmp(suit,str_array[i]))
//         //      {
//         //          del = i ;
//         //          suit = str_array[i];
//         //      } 
//         //     }
//         //     res += suit;
//         //     str_array.erase(str_array.begin()+del);
//         // }
//         // res += str_array[0];
//         return res;
//     }

// /* ----------- 剑指offer 丑数 ----------------*/
// //暴力求解 自己的方法空间造成浪费 复杂度也非最优
//      int GetUglyNumber_Solution(int index) {
//         if(index==0) return 0;
//         set<int> seq;
//         seq.insert(1);
//         int ugly[3]={2,3,5};
//         int k=0;
//         set<int>::iterator it = seq.begin();
//         while(it!=seq.end())
//         {
//             k++;
//             for(int i=0;i<3;i++)
//             {
//                 if(seq.count((*it)*ugly[i])==0)
//                     {
//                         seq.insert((*it)*ugly[i]);  
//                     }
//             }
//             if(k==index) 
//             {
//                 for(auto &da:seq )
//                     std::cout << da << std::endl;
//                 return *it;
//             }
//             it++;
//         }

//         return 1;
//     }
//     /* ----------- 剑指offer 字符串找到第一个只出现一次的字符 ----------------*/
//     int FirstNotRepeatingChar(string str) {
//         //用map是不是会更快 ？ ？ ？
//         for(int i=0;i<str.size();i++)
//         {
//             if(str.find(str[i])==str.rfind(str[i]))
//                 return i;
//         }
//         return -1;
//     }
//     /* ----------- 剑指offer 数组中的逆序对 对1000000007取模的结果输出----------------*/
//     int InversePairs(vector<int> data) {
//         int cnt=0;
//             for(int j=data.size()-2;j>=0;j--)
//             {
//                 if(data[j]>data[j+1])
//                 {
//                     if(cnt==0)
//                     {
//                         for(int i=j+1;i<data.size();i++)
//                         {
//                             if(data[j]>=data[i])
//                             {
//                                 break;
//                             }
//                             else
//                             {
//                                 cnt++;
//                                 // if(cnt==1000000007) cnt=0;
//                             }
                            
//                         }  
//                     }
//                     else
//                     {
//                         for(int i=j+1;i<data.size();i++)
//                         {
//                             if(data[j]>data[i])
//                             {
//                                 cnt++;
//                                 // if(cnt==1000000007) cnt=0;
//                             }
//                         }
//                     }
                    
//                 }
//                 else if(data[j]==data[j+1])
//                 {
//                     int temp = cnt;
//                     cnt ++;
//                     // if(cnt==1000000007) cnt=0;
//                 }
//                 else
//                 {
//                     for(int i=j+2;i<data.size();i++)
//                     {
//                         if(data[j]>data[i])
//                         {
//                             cnt++;
//                             // if(cnt==1000000007) cnt=0;
//                         }
//                     }
//                 }
//             }
//         return (cnt%1000000007);
//     }

//     /* ----------- 剑指offer 两个链表的第一个公共节点 ----------------*/
//     struct ListNode {
// 	int val;
// 	struct ListNode *next;
// 	ListNode(int x) :
// 			val(x), next(NULL) {
// 	}
//     };
//     ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
//     // 自己写的 非最优查找

//     // 长度相同有公共结点，第一次就遍历到；没有公共结点，走到尾部NULL相遇，返回NULL
//     // 长度不同有公共结点，第一遍差值就出来了，第二遍一起到公共结点；没有公共，一起到结尾NULL。

//         ListNode* p1 = pHead1;

//         while(p1!=nullptr)
//         {
//             ListNode* p2 = pHead2;
//             while(p2!=nullptr)
//             {
//                 if(p1->val == p2->val) return p2;

//                 p2 = p2->next ;
//             }
//             p1 = p1->next;
//         }
//         return nullptr;
//     }

//     /* ----------- 剑指offer 统计一个数字在排序数组中出现的次数----------------*/
//     int GetNumberOfK(vector<int> data ,int k) {
//         int left= 0;
//         int right = data.size()-1;
        
//         while(left<=right)
//         {
//             int mid=(left+right)/2;
            
//             if(data[mid]==k){
//                left = right = mid;
//                for(int i=1;;i++)
//                 {
//                     if((mid+i)<data.size())
//                     {
//                         if(data[mid+i]==k) 
//                             right ++;
//                     }
//                     if(mid - i>=0)
//                     {
//                         if(data[mid-i]==k) 
//                             left --;
//                     }
//                 if(((mid+i)>=data.size())&&(mid-i<0))   break;
//                 }

//                break;
//             }   
//             else if(data[mid]>k)  right = mid - 1; 
//             else if(data[mid]<k)  left = mid + 1;
//         }

//         if(left>right) return 0;
//         return (right-left+1); 
//     }

//     /* ----------- 剑指offer 输入一棵二叉树，求该树的深度 （最长路径的长度）----------------*/
//     struct TreeNode {
//         int val;
//         struct TreeNode *left;
//         struct TreeNode *right;
//         TreeNode(int x) :
//                 val(x), left(NULL), right(NULL) {
//         }
//     };
    
//     int TreeDepth(TreeNode* pRoot)
//     {

//         if(pRoot == nullptr) return 0;
        
//         queue<TreeNode*> seq;
//         seq.push(pRoot);
//         int depth=0,layer_count=1,count=0;
//         while(!seq.empty())
//         {
//             count++;
//             if(seq.front()->left!=nullptr) 
//                 seq.push(seq.front()->left);

//             if(seq.front()->right!=nullptr) 
//                 seq.push(seq.front()->right);

//             seq.pop();
//             if(count==layer_count)
//             {
//                 count =0;
//                 depth ++;
//                 layer_count = seq.size();
//             }
//         }

//         return depth;
//     }
//     /* ----------- 剑指offer 数组中有两个数字只出现一次，其他数字则出现了两次，找出这两个数----------------*/
//     bool FindNumsAppearOnce(vector<int> data) {
//         int res=data[0];
//         for(int i=1;i<data.size();i++){   
//             res = res ^ data[i];
//         }
//         int k=0;
//         while(res!=0){
//             k++;
//             res = res/2 ;
//         }
//         int check = 1<<(k-1);

//         int num1=0,num2=0;
//         for(int i=0;i<data.size();i++){
//             if((data[i]&check)==check) 
//                 num1 ^= data[i];
//             else
//                 num2 ^= data[i];
//         }
//         cout << num1 <<" " <<num2 <<endl;
//         return true;
//     }

//     /* ----------- 剑指offer 判断一颗二叉树是否是平衡二叉树----------------*/
//     // 自己的思路： 所有叶节点高度差 不超过2
//     // 最优思路： 后序遍历
//     bool check_leaf(TreeNode* node)
//     {
//         if((node->left==nullptr)&&(node->right==nullptr)) return true;
//         return false;
//     }
//     bool IsBalanced_Solution(TreeNode* pRoot) {

//         if(pRoot==nullptr) return true;
//         vector<int> layers;
//         queue<TreeNode*> node;
//         node.push(pRoot);
//         int depth=0,layer_count=1,count=0;
//         while(!node.empty())
//         {
//             count++;
//             if(node.front()->left!=nullptr) 
//                 node.push(node.front()->left);

//             if(node.front()->right!=nullptr) 
//                 node.push(node.front()->right);

//             if(check_leaf(node.front()))
//                 layers.push_back(depth);

//             node.pop();
//             if(count==layer_count)
//             {
//                 count =0;
//                 depth ++;
//                 layer_count = node.size();
//             }
//         }
//         sort(layers.begin(),layers.end());
//         if(layers.size()==1)
//         {
//             if(depth==2) return true;
//             else return false;
//         }
//         if(abs(*layers.end() - layers[0])>=2) return false;    
//         return true;
//     }
//     /*----------- 剑指offer 和为S 的正数序列 -----------*/
//     //写的有点累赘  用双指针思想最好
//     vector<vector<int> > FindContinuousSequence(int sum) {
//         const int start=(sum-1)/2;
//         volatile int s1=1;
//         vector<vector<int>> res;

//         volatile int i=2;
//         while(s1<=start)
//         {
//             int add_sum = ((2*s1+i-1)*i/2) ;
//             if(add_sum==sum)
//             {
//                  vector<int>temp;
//                 for(int p=0;p<i;p++)
//                     temp.push_back(s1+p);
//                 res.push_back(temp);
//                 if((++s1)>start) break;
//                 else 
//                 {   
//                     i=2;
//                     continue;
//                 }
//             }
//             else if(add_sum>sum) 
//             {
//                 if((++s1)>start) break;
//                 else 
//                 {
//                     i=2;
//                     continue;
//                 }
//             }
//             else i++;
//         }
//     return res;
//     }
//     /*----------- 剑指offer 和为S 的两个数字 -----------*/
//     // 证明 相隔越远 乘积越小！！！！
//     vector<int> FindNumbersWithSum(vector<int> array,int sum) {
//         if(array.size()<=1) return vector<int>();

//         vector<int>res;
//         int left =0 ,right = array.size()-1,min=10000;
//         while(left<right)
//         {
//             int add = array[left]+array[right] ;
//             if(add==sum)
//             {
//                 // if((array[left] * array[right])<min)
//                 {
//                     // min = array[left] * array[right];
//                     res.resize(2);
//                     res[0]= array[left] ;
//                     res[1] = array[right];
//                 }
//                 break;
//                 // --left;--right;
//             }
//             else if(add>sum) --right;
//             else ++left;
//         }
//         return res;
//     }
//     /*----------- 剑指offer 左旋转字符串 -----------*/
//     string LeftRotateString(string str, int n) {
//         string res;
//         int spe = n%str.size();
//         for(int i=spe;i<str.size();i++)
//             res+=str[i];
//         for(int i=0;i<spe;i++)
//             res+=str[i];
//         return res;
//     }
//     /*----------- 剑指offer 翻转单词顺序列 ----------- */
//     string ReverseSentence(string str) {
//         if(str.empty()) return str;
//         string ori_str=str;
//         int ori_size=str.size();
//         int right=str.size();
//         for(int i=ori_size-1;i>=0;i--)
//         {
//             if(ori_str[i]==' ')
//                 {
//                     //
//                     str+= (ori_str.substr(i+1,right-i-1));
//                     str+=' ';
//                     right = i;  
//                 }
//         }
//         str+= ori_str.substr(0,right);   
//         str+='\n';
//      return    str.substr(ori_size,ori_size);
//     }
//     /*----------- 剑指offer 判断是否是顺子 ----------- */
//     // 不用开辟一个桶！！！！！ 可以用移位实现存储
//     bool IsContinuous( vector<int> numbers ) {
//         if(numbers.size()!=5) return false;
//         vector<int> tong(14);
//         int min=20,max=-20;
//         for(int i=0;i<numbers.size();i++)
//         {
//             if(numbers[i]!=0)
//             {
//                 if(tong[numbers[i]]==1 ) return false;
                
//                 if(numbers[i]<min) min=numbers[i];
//                 else if(numbers[i]>max) max=numbers[i];
//             }
//             tong[numbers[i]]++;
//         }
//         if(max-min <=4) return true;
//         return false;
//     }
//     /*----------- 剑指offer 围圈数数 最后剩下的那个 ----------- */
//     // 
//     int LastRemaining_Solution(int n, int m)
//     {
        
//     }
//     /*----------- 剑指offer 最简 求阶乘  ----------- */
    
//     int Sum_Solution(int n) {

//         //最简：
//         int ans=n;
//         ans && (ans+=Sum_Solution(ans-1));
//         return ans;

//         // static int res=0;
//         // res+=n;
//         // int ans = (n>1 && Sum_Solution(n-1));
//         // return res;
//     }
//     /*----------- 剑指offer 不用加减乘除做加法 ----------- */
//     int Add(int num1, int num2)
//     {   
//         //递归 最简洁
//         // return num2 ? Add(num1^num2, (num1&num2)<<1) : num1;

//         //迭代 逻辑性最好

//         // while (num2!=0) {
//         //     int temp = num1^num2;
//         //     num2 = (num1&num2)<<1;
//         //     num1 = temp;
//         // }
//         // return num1;

//         int temp = 1,res=0;
//         bool add_flag=false;
//         while(true)
//         {
//                 if( (num1&temp)==temp && (num2&temp) ==temp)  // 1 1
//                     (add_flag)?res|=temp:(res|=0,add_flag=!add_flag) ;
//                 else if (((num1&temp)|(num2&temp))==temp)       // 0 1
//                     (add_flag)?res|=0:res|=temp  ;
//                 else                                           //0 0
//                     (add_flag)?(res|=temp,add_flag=!add_flag):res|=0 ;
//             if(temp&(1<<31)) break;
//             temp = (temp <<1); 
//         }
//         return res;
//     }
//     /*----------- 剑指offer 转字符串为数字 ----------- */
//     int StrToInt(string str) {
//         long long res=0; //long long 为64位
//         for(int i=str.size()-1;i>=0;i--)
//         {
//             if(str[i]<=57 && str[i]>=48)
//             {
//                 res += ((str[i]-48)* pow(10,str.size()-i-1));
//             }
//             else if(str[i]=='+'||str[i]=='-')
//             {
//                 if(i!=0) return 0;
//                 if(str[i]=='-') return (0-res);
//                 return res;
//             }
//             else return 0;
//         }
//         return res;
//     }
//     /*----------- 剑指offer 数组中重复的数字 ----------- */
//     // 桶排序
//     bool duplicate(int numbers[], int length, int* duplication) {

//         for(int i=0;i<length;i++)
//         {
//             if(i!=numbers[i]) 
//             {
//                 if(numbers[numbers[i]]==numbers[i])
//                 {
//                     (*duplication) = numbers[i];
//                     return true;
//                 }
//                 swap(numbers[numbers[i]],numbers[i]) ;
//             }
//         }
//         return false;
//     }
//     /*----------- 剑指offer 构建乘积数组 ----------- */

//     int beh(vector<vector<int>>&st,int k)
//     {
//         if(st[k][2]==-1)
//             st[k][2] = st[k+1][1]*beh(st,k+1);
        
//         return st[k][2];
//     }
//     int fro(vector<vector<int>>&st,int k)
//     {
//         if(st[k][0]==-1)
//             st[k][0] = st[k-1][1]*fro(st,k-1);

//         return st[k][0];
//     }
//     vector<int> multiply(const vector<int>& A) {
//     if(A.empty()) return A;
//     vector<vector<int>>store(A.size(),vector<int>(3));
    
//     for(int i=0;i<A.size();i++){
//         store[i][0]=store[i][2]=-1;
//         store[i][1] = A[i];
//     }
//     store[0][0]=store[A.size()-1][2]=1;
    
//     beh(store,0);
//     fro(store,(A.size()-1));
//     vector<int> res(A.size());

//     for(int i=0;i<store.size();i++)
//         res[i]=store[i][0]*store[i][2];
//     return res;
//     }
//     /*----------- 剑指offer 匹配正则表达式 ----------- */
//     /* 逻辑设计 与 递归 ！ */
//     bool match(char* str, char* pattern)
//     {
//         if( *str=='\0' && *pattern=='\0')     return true;
//         if(*str!='\0' && *pattern=='\0')      return false;

//         if((*pattern=='.'&& *str!='\0')|| *str == *pattern){
//             if( *(pattern+1)=='*') 
//                 return (match(str,pattern+2) || match(str+1,pattern));
//             else 
//                 return match(str+1,pattern+1);
//         }
//         else{
//             if( *(pattern+1)=='*') 
//                 return match(str,pattern+2) ;
//             else 
//                 return false;
//         }
//     }
//     /*----------- 剑指offer 用来判断字符串是否表示数值（包括整数和小数） ----------- */
    
//     bool isNumeric(char* string)
//     {

//     }
//     /*----------- 剑指offer 找出字符流中第一个只出现一次的字符 ----------- */
//   //Insert one char from stringstream
//     int cnt[256];
//     queue<char> buffer;
//     void Insert(char ch)
//     {
//         cnt[ch]++;
//         buffer.push(ch);
//         while (!buffer.empty() && cnt[buffer.front()]>1)
//         {
//             buffer.pop();
//         }
        
//     }
//   //return the first appearence once char in current stringstream
//     char FirstAppearingOnce()
//     {
//         if(!buffer.empty())
//             return buffer.front();
//         else return '#';
//     }
// };

// int main(void)
// {
    
//     // Solution solu;
//     char *str="e16";
//     char *pattern="asfahfia";
//     // std::cout << Numeric(str) << std::endl;
    
//     return 0;
// }




// 从字符串string开始完整匹配子串sub，返回匹配到的字符个数。

// sub中如果出现'?'表示可以匹配一到三个除'\0'以外的任意字符。
// 如果sub还有找不到匹配的字符，则说明不能完整匹配。

// 如果能完整匹配，返回匹配到的字符个数，如果有多种匹配方式，返回匹配字符数最少的那个，如果不能完整匹配，返回-1
/*
#include<iostream>
#include<cstdio>
using namespace std;
int match_num;
int sign_use=0;
bool match(string input,string sub,int in_index,int sub_index)
{
    if(sub_index==0&&sub[sub_index]=='?') return false;
    if(sub_index==sub.size()) return true;
    else if(in_index==input.size()) return false;

    if(sub[sub_index]!='?'&&sub[sub_index]==input[in_index])    
        {
            sign_use=0;
            match_num++;
            return match(input,sub,in_index+1,sub_index+1);
        }
    else if(sub[sub_index]=='?'){
        match_num++;
        sign_use++;
        if(sign_use>3) return false;
        return match(input,sub,in_index+1,sub_index+1)||match(input,sub,in_index+1,sub_index);
    }
    else return false;
}

int main(int argc, char const *argv[])
{
    string input;
    string sub;   
    while(getline(cin,input)){
        getline(cin,sub);
        match_num=0;
        if(match(input,sub,0,0))
            cout << match_num << endl;
        else
            cout << -1 << endl;
        
    }
    return 0;
}
*/


// 有K种颜色的小球(K<=10)，每种小球有若干个，总数小于100个。
// 现在有一个小盒子，能放N个小球(N<=8)，现在要从这些小球里挑出N个小球，放满盒子。
// 想知道有哪些挑选方式。注：每种颜色的小球之间没有差别。

// 请按数字递增顺序输出挑选小球的所有方式。

// 如有3种颜色，每种颜色小球的个数分别为a:1,b:2,c:3，挑出3个小球的挑法有：
// 003,012,021,102,111,120

/* #include<iostream>
#include<cstdio>
#include <map>
#include <vector>
using namespace std;

vector<int>give;

void  group(map<int,int>ball,int ball_cls,int sum,int cur,int need){

    
    for(int ball_give=0;ball_give<=ball[cur-1];ball_give++)
    {
        if(cur==ball_cls){
            give.push_back(ball_give);
            int index=0;
            int has=0;

            for(index=0;index<ball_cls;index++){
                if(ball[index]>=give[index]) { has +=give[index]; continue;}
                else break;
            }

            if(index==ball_cls&&has==need){
                for(auto ball_:give){
                    cout << ball_ << " ";
                }
            cout << endl;
            }
        }
        else{
            give.push_back(ball_give);
            group(ball,ball_cls,sum-ball_give,cur+1,need);
        }
        give.pop_back(); 
    }
}
int main(int argc, char const *argv[])
{
    int K,N;
    map<int,int>ball;
    while(scanf("%d %d",&K,&N)!=EOF){
        for(int i=0;i<K;i++){
            int num;
            scanf("%d",&num);
            ball.insert(pair<int,int>(i,num));
        }

        group(ball,K ,N,1,N);

    }
    

    return 0;
}
 */

// 一个长方体，长宽高分别为x,y,z，都为自然数。
// 现在要把若干个相同的长方体摆成高为N的一根柱形体。
// 每层摆1个，如果两种摆法的高度是一样的，则认为这两种摆法等价，所以每层只有三种摆法。
// 求一共有多少种摆法。
/* #include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int opre_kinds=0;
vector<int> size;
int sum;
void comb(int cur){

    if(cur==sum){
        opre_kinds++;
        return ;
    }
    else if(cur>sum){
        return ;
    }
    for(int i=0;i<size.size();i++){
            comb(cur+size[i]);
    }
}
int main(int argc, char const *argv[])
{
    int N;
    int x,y,z;

    while (scanf("%d",&N)!=EOF)
    {
        opre_kinds=0;
        size.clear();
        scanf("%d %d %d",&x,&y,&z);
        size.push_back(x);
        if(y!=x) 
            size.push_back(y);
        if(z!=x && z!=y) 
            size.push_back(z);

        std::sort(size.begin(),size.end());
 
        sum = N;
        comb(0);
        cout << opre_kinds <<endl;
    }
    return 0;
}
 */

// 一个数字段由首尾两个数字标识，表示一个自然数集合，
// 比如数字段[beg, end)表示从beg到end之间的所有自然数，
// 包含beg，但不包含end。

// 有若干个数字段，这些数字段之间可能有重叠，
// 怎么把这些数字段合并去重，用最少个数的数字段来表示。

// 合并前后，整个集合包含的数字不发生变化。
// 合并去重后形成的数字段集合，按升序排列。
// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include <algorithm>
// using namespace std;

// bool cmp(vector<int>p1,vector<int>p2){
//     return p1[0]<p2[0];
// }

// void store(vector<int>p1,vector<vector<int>>&all){
//     if(all.empty()) all.push_back(p1);
//     else{
//         int i;
//         for(i=0;i<all.size();i++){
//             //看区间段里是否有段相交 或包括
//             // 有则只需更新该段
//             if(all[i][0]<=p1[0]&&all[i][1]>=p1[0]){
//                 all[i][1]= (all[i][1]>p1[1]?all[i][1]:p1[1]);
//                 break;
//             }
//             else if (all[i][0]<=p1[1]&&all[i][1]>=p1[1])
//             {
//                 all[i][0]= (all[i][0]<p1[0]?all[i][0]:p1[0]);
//                 break;
//             }
//             if((all[i][0]>=p1[0]&&all[i][1]<=p1[1]) || all[i][0]<=p1[1]&&all[i][1]>=p1[1]){
//                 // 并包
//                 all[i][0]= (all[i][0]<p1[0]?all[i][0]:p1[0]);
//                 all[i][1]= (all[i][1]>p1[1]?all[i][1]:p1[1]);
//                 break;
//             }
//         }
//         if(i==all.size()){
//             all.push_back(p1);
//         }
//         else{
//             vector<int> tmp = all[i];
//             all.erase(all.begin()+i);
//             store(tmp,all);
//         }
//     }
// }
// int main(int argc, char const *argv[])
// {
//     int N;
//     while(scanf("%d",&N)!=EOF){
//         vector<vector<int>> input;
//         for(int i=0;i<N;i++){
//             int begin,end;
//             vector<int>part;
//             scanf("%d %d",&begin,&end);
            
//             part.push_back(begin);part.push_back(end);
//             input.push_back(part);
//         }
//         vector<vector<int>> all;
//         for(int i=0;i<input.size();i++){
//             store(input[i],all);
//         }
//         sort(all.begin(),all.end(),cmp);
//         for(int i=0;i<all.size();i++){
//             cout << all[i][0]<<" "<<all[i][1]<<endl;
//         }
//     }
    
//     return 0;
// }


// 输入一个正整数，表示小电视君需要的N个扭蛋。

// 输出一个字符串，每个字符表示扭蛋机，字符只能包含"2"和"3"。

// 题目精髓： 逆向思维 ！ ！
// #include <iostream>
// #include <cstdio>
// #include <vector>
// using namespace std;
// vector<int>num;
// vector<vector<int>>all;
// int push_time=0;
// void get(int sum){

//     if(sum==0){
//         all.push_back(num);
//         return ;
//     }
//     else if(sum<0){
//         return ;
//     }
//     else{
//         if(sum%2==0){
//             num.push_back(3);
//             get(sum/2-1);
//             num.pop_back();
//         }
//         else{
//             num.push_back(2);
//             get((sum-1)/2);
//             num.pop_back();
//         }
//     }
// }

// int main(int argc, char const *argv[])
// {
    
//     int n;
//     while(scanf("%d",&n)!=EOF){
//         all.clear();
//         num.clear();
//         get(n);
//         for(int i=all[0].size()-1;i>=0;i--) cout << all[0][i] ;
//         cout << endl;
//     }
//     return 0;
// }


// 输入有多行，每行是一个表达式，输入以END作为结束
/* #include<iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int str2int(string str){
    if(str.empty()) {
        cout << "NO STR" << endl;
        return 0;
    }
    int out=0;
    int add=0;
    
    for(int i=str.size()-1;i>=0;i--){
        out += ((str[i]-'0')*pow(10,add));
        add++;
    }

    return out;
}
int solution(string express){

    if(express.find('+')!=string::npos){       // 有+ 可以分割
        int pos=express.find('+');
        int left = solution(express.substr(0,pos)) ;
        int right = solution(express.substr(pos+1,express.size()-pos-1)) ;
        // cout << left <<"+"<<right<<" "<<(left+right)<<endl;
        return (left+right);
    }
    else if(express.find('-')!=string::npos){  // 有- 可以分割
        int pos=express.find('-');
        int left = solution(express.substr(0,pos));
        for(int i=pos;i<express.size();i++){
            if(express[i]=='+') express[i]='-';
            if(express[i]=='-') express[i]='+';
        }
        int right = solution(express.substr(pos+1,express.size()-pos-1));
        // cout << left <<"-"<<right<<" "<<(left-right)<<endl;
        return (left-right);
    }
    else if(express.find('*')!=string::npos){  // 只有乘法符号
        int pos=express.find('*');
        int left = solution(express.substr(0,pos));
        int right = solution(express.substr(pos+1,express.size()-pos-1));
        // cout << left <<"*"<<right<<" "<<(left*right)<<endl;
        return (left*right);
    }
    else{// 无 + - × 返回数字
    
        return str2int(express);
    }
}
int main(int argc, char const *argv[])
{
    string express;
    vector<int> dis;
    while(getline(cin,express)){
        if(express=="END"){
            for(auto data:dis) cout << data << endl;
            dis.clear();
            continue;
        }
       int out = solution(express);
       dis.push_back(out);
       
    }

    return 0;
}
 */

// 并查集 经典 ！！ 

/* #include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,ix,m;
vector<int>parent;
int find(int x){
    return x==parent[x]?x:parent[x]=find(parent[x]);
}
int main(void){
    cin>>n>>ix>>m;
    parent=vector<int>(n);
    for(int i=0;i<n;i++)
        parent[i]=i;

    int ans=0,b=0;

    while(m--){
        int one,two;
        scanf("%d,%d",&one,&two);
        if(one==ix||two==ix) b++;

        int fx=find(one),fy=find(two);

        if(fx!=fy) parent[fx]=fy;
    }
    for(int i=0;i<n;i++){
        if(find(ix)==find(i)) ans++;
    }
    cout<<ans-b-1<<endl;
    return 0;
 
} */

/* #include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int call(vector<int>has,vector<vector<int>>dur){
    if(has.size()<3) return 0;
        int res=0;
        for(int i=0;i<dur.size();i++){
            vector<int>temp(has.begin()+dur[i][0]-1,has.begin()+dur[i][1]);

            if(temp.size()<3) continue;

            sort(temp.begin(),temp.end());

            for(int i=2;i<temp.size();i++){
                if(temp[i]<(temp[i-1]+temp[i-2])){

                    res++;
                    break;
                }
            }
            

        }

    return res;
}
int main(int argc, char const *argv[])
{
    int n;
    vector<int> has;
    vector<vector<int>> dur;
    vector<int> tmp(2);
    while(scanf("%d",&n)!=EOF){
        has.clear();
        dur.clear();
        int len,per,l,r;
        int ex=0;
        for(int i=0;i<n;i++){
            scanf("%d",&len);
            has.push_back(len);
        }
        scanf("%d",&per);
        for(int i=0;i<per;i++){
            scanf("%d %d",&l,&r);
            if((r-l)>=2){
                tmp[0]=l;tmp[1]=r;
                dur.push_back(tmp);
            }
            else if(l-r+1 > 47){
                ex++;
        
            }
        }

        int res = call(has,dur);
        cout << res+ex << endl;
    }

    return 0;
} */


/* #include <iostream>
#include <math.h>
using namespace std;
int str2int(string str){
    if(str.empty()) {
        cout << "NO STR" << endl;
        return 0;
    }
    int out=0;
    int add=0;
    
    for(int i=str.size()-1;i>=0;i--){
        out += ((str[i]-'0')*pow(10,add));
        add++;
    }

    return out;
}
int cmp(string v1,string v2){

    if(v1.empty()&&!v2.empty()) return -1;
    if(v2.empty()&&!v1.empty()) return 1;  
    int r_v1=str2int(v1);
    int r_v2=str2int(v2);
    if(r_v1>r_v2) return 1;
    else if(r_v1<r_v2) return -1;
    return 0;
}
int main(int argc, char const *argv[])
{
    
    string input;
    while(getline(cin,input)){

        int space = input.find(' ');
        string ver1=input.substr(0,space),
                ver2 = input.substr(space+1,input.size()-space-1);
        
        int start=0;

        while(start<ver1.size()&&start<ver2.size()){
            string ver1_sub = ver1.substr(start,ver1.size()-start);
            string ver2_sub = ver2.substr(start,ver2.size()-start);
            
            int pos1=ver1_sub.find('.');
            int pos2=ver2_sub.find('.');
     
            if(pos1!=string::npos&&pos2!=string::npos){
                // 字段1 大于 字段2   输出 1 break
                int res=cmp(ver1_sub.substr(0,pos1),ver2_sub.substr(0,pos2));
                if(res!=0) {
                    cout <<  res << endl;
                    break;
                }
                // 相等 start 移动 continue;
                start += pos1+1;
                
            }
            else{
                    if(pos1==string::npos && pos2==string::npos){
                        int res=cmp(ver1_sub,ver2_sub);
                        
                        cout <<  res << endl;
                        break;
                    }
                    else if(pos1==string::npos){
                        int res=cmp(ver1_sub,ver2_sub.substr(0,pos2));
                        if(res==0) res=-1;
                        cout <<  res << endl;
                        break;
                    }
                    else{
                        int res=cmp(ver1_sub.substr(0,pos1),ver2_sub);
                        if(res==0) res=1;
                        cout <<  res << endl;
                        break;
                    }
            }
        }
   
    }

    return 0;
} */


//  迷宫问题 最小权值路径
//  回溯法超内存 应该使用动态规划 DP
/* #include <iostream>
#include <vector>
using namespace std;
int min_slow=-1;
vector<vector<int>> vis;
int size_;
void find(vector<vector<int>> vis,int cur_i,int cur_j,int slow){

    if(vis[cur_i][cur_j]==-1) return;
    slow += vis[cur_i][cur_j];
    if(min_slow!=-1 && slow>min_slow) return;
    vis[cur_i][cur_j]=-1;
    if(cur_i==vis.size()-1 && cur_j==vis.size()-1){
        if(min_slow==-1) min_slow=slow;
        else{
            if(slow<min_slow) min_slow=slow;
        }
        return;
    }
    // 上
    if(cur_i-1>=0&&cur_i-1<vis.size())
        find(vis,cur_i-1,cur_j,slow) ;
    // 下
    if(cur_i+1>=0&&cur_i+1<vis.size())
        find(vis,cur_i+1,cur_j,slow) ;
    // 左
    if(cur_j-1>=0&&cur_j-1<vis.size())
        find(vis,cur_i,cur_j-1,slow) ;
    // 右
    if(cur_j+1>=0&&cur_j+1<vis.size())
        find(vis,cur_i,cur_j+1,slow) ;

}
int main(int argc, char const *argv[])
{
    int n;
    while(scanf("%d",&n)!=EOF){
        vis.clear();
        // vector<vector<int>> vis;
        min_slow=-1;
        int block;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(j!=n-1) scanf("%d,",&block);
                else scanf("%d",&block);
                temp.push_back(block);
            }
            size_=n;
            vis.push_back(temp);
            // vis.push_back(vector<int>(n,0));
        }
        find(vis,0,0,0); 
        cout << min_slow << endl;
    }
    
    return 0;
} */



// 对每一个样例，输出所有可能的搭配方案，如果有多种方案，请按每个方案的第一杯 B 型血剂量的大小升序排列。
// 如果无法找到任何一种满足大小姐的方案，输出"NO"(不包括引号)并换行。
/* #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool get_another(vector<int>dose,int l,int r,int find){

    while(l<=r){
        int mid=(l+r)/2;
        if(dose[mid]==find) return true;
        if(dose[mid]>find) {r=mid-1;}
        else if(dose[mid]<find){l=mid+1;}
    }
    return false;
}
int main(int argc, char const *argv[])
{
    
    int has;
    while (scanf("%d",&has)!=EOF)
    {
        vector<int> dose;
        int dose_;
        for(int i=0;i<has;i++){
            scanf("%d",&dose_);

            dose.push_back(dose_);
            // 插入排序

            for(int i=dose.size()-2;i>=0;i--){
                if(dose[i+1]<dose[i]) swap(dose[i+1],dose[i]);
                else break;
            }
            
        }

        int need;
        scanf("%d",&need);
        // sort(dose.begin(),dose.end());
        bool find=false;
        
        // 暴力求解  O(n*n)
        // for(int i=0;i<dose.size();i++)
        //     for(int j=i+1;j<dose.size();j++){
        //         if(dose[i]+dose[j]==need){
        //             find=true;
        //             cout << dose[i]<<" "<<dose[j] <<endl;
        //         }
        //     }

        

        // 二分查找  need-dose[i] O(n*lgn)
        // for(int i=dose.size()-1;i>=0;i--){
        //     if(dose[i]>need) continue;
        //     if(get_another(dose,0,i-1,need-dose[i])){
        //         find=true;
        //         cout <<need- dose[i]<<" "<<dose[i] <<endl;
        //     }
        // }

        // start end 双指针求和查找

        int start=0,end=dose.size()-1;
        while(start<end){

            if(dose[start]+dose[end]==need) {
                 cout << dose[start] <<" "<< dose[end] <<endl;find=true;
                 start++;
                 }
            else if(dose[start]+dose[end]>need) end--;
            else start++;
        }

        if(!find) cout << "NO" << endl;

    }

    return 0;
} */



// #include<iostream>
// #include <vector>
// #include <math.h>
// using namespace std;
// struct node{
//     int val;
//     struct node *next;
// };
// int str2int(string str){
//     if(str.empty()) {
//         cout << "NO STR" << endl;
//         return 0;
//     }
//     int out=0;
//     int add=0;
    
//     for(int i=str.size()-1;i>=0;i--){
//         out += ((str[i]-'0')*pow(10,add));
//         add++;
//     }

//     return out;
// }
// int main(int argc, char const *argv[])
// {
//     string seq;
//     while (getline(cin,seq))
//     {
//         string sub = seq;
//         vector<int> numic;
//         node* p;
//         node* header=nullptr;
//         int num;
//         /* 将输入创建成链表 */
//         while(sub.find(',')!=string::npos){
//             num =str2int(sub.substr(0,sub.find(',')));
//             sub = sub.substr(sub.find(',')+1,sub.size()-sub.find(',')-1);
            
//             if(!header){
//                 header = (node*) malloc(sizeof(node));
//                 p = header;
//                 header->val = num;
//                 header->next = nullptr;
//             }
//             else{
//                 p->next = (node*) malloc(sizeof(node));
//                 p = p->next;
//                 p->val = num;
//                 p->next = nullptr;
//             }
//         }
//         num =str2int(sub);
//         if(!header){
//             header = (node*) malloc(sizeof(node));
//             p = header;
//             header->val = num;
//             header->next = nullptr;
//         }
//         else{
//             p->next = (node*) malloc(sizeof(node));
//             p = p->next;
//             p->val = num;
//             p->next = nullptr;
//         }
        
//         /* header 为输入链表头指针  */

//         node* last_sec;
        
//         node* new_p = header;
//         while (new_p!=nullptr)
//         {
//             // 找倒数第二个节点
//             node* tmp = new_p->next;
//             node* tmp_ =tmp;
//             while (tmp!=nullptr)
//             {
//                 if( tmp->next!=nullptr && tmp->next->next==nullptr) {
//                     // 找到倒数第二个节点 将其后也就是最后一个节点插入到当前节点后 
//                     tmp->next->next= new_p->next;
//                     new_p->next = tmp->next;

//                     //这个倒数第二个节点变为尾节点
//                     tmp->next=nullptr;

//                     break;
//                 }
//                 tmp = tmp->next;
                
//             }

//             new_p = tmp_;
//             // 只剩下 一个节点 翻转完成 不退出的话 ->next->next 出错
//             if(new_p->next==nullptr) break;
//         }
        
//         // 输出
//         while(header!=nullptr){
//             if(header->next==nullptr) cout << header->val<<endl ;
//             else cout << header->val <<",";
//             header=header->next;
//         }
   
//     }
    
    

//     return 0;
// }


// 三数之和是否存在  两数之和 的升级版

/* #include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int str2int(string str){
    if(str.empty()) {
        cout << "NO STR" << endl;
        return 0;
    }
    int out=0;
    int add=0;
    
    for(int i=str.size()-1;i>=0;i--){
        out += ((str[i]-'0')*pow(10,add));
        add++;
    }

    return out;
}
bool find(int need,vector<int>ele,int l_l,int l_r,int r_l,int r_r){
       
        int start=l_l,end=r_r;
        while(start<=l_r&&end>=r_l){

            if(ele[start]+ele[end]==need) {
                 return true;
                 }
            else if(ele[start]+ele[end]>need) end--;
            else start++;
        }
        return false;
}
bool exist(vector<int>ele,int need){

    for(int i=1;i<ele.size();i++){
        // 找二元组 和为need-ele[i]  左边元素 [0,i-1] 右边元素[i+1,ele.size()-1]
     if(ele[i]>=need) break;
     if(find(need-ele[i],ele,0,i-1,i+1,ele.size()-1)) return true;   
    }
    return false;
}

int main(int argc, char const *argv[])
{
    string seq;
    while (getline(cin,seq))
    {
        int num;
        string sub = seq;
        vector<int> ele;
         while(sub.find(' ')!=string::npos){
            num =str2int(sub.substr(0,sub.find(' ')));
            sub = sub.substr(sub.find(' ')+1,sub.size()-sub.find(' ')-1);
            ele.push_back(num);
            if(sub.find(' ')==string::npos&&sub.find(',')!=string::npos){
                num = str2int(sub.substr(0,sub.find(',')));
                sub = sub.substr(sub.find(',')+1,sub.size()-sub.find(',')-1);
                ele.push_back(num);
                break;
            }
            
         }
        int need = str2int(sub);
        if(ele.size()<3) {cout << "False"<<endl;continue;}
        sort(ele.begin(),ele.end());
        if(exist(ele,need)==false) cout << "False" << endl;
            else cout << "True" << endl;
    }
    
    return 0;
} */


#include <iostream>
#include<math.h>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int num;
 
    while (scanf("%d",&num)!=EOF)
    {
        int left = -90;
        int right=90;
           vector<int>out;
        while(out.size()<6){

            int mid=(left+right)/2;
            if(num<mid){
                out.push_back(0);
                
                right = mid;
            }
            
            else{
                out.push_back(1);
                left = mid;
            }
        }
        for(auto da:out) cout<<da;
        cout << endl;
    }

    return 0;
}

