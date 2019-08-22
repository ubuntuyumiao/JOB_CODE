#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

// 二叉树结构体
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


class Solution
{
    public:

// 输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
// (注意: 在返回值的list中，数组长度大的数组靠前)

// version_1.0 by yu
    /*vector<int> path;
    vector<vector<int>> out;
    void pre_order(TreeNode* root,int expectNumbe){
        if(root==nullptr) return ;
        path.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            int sum=0;
            for(auto node:path){
                sum += node;
            }
            if(sum==expectNumbe) out.push_back(path);
            std::cout << std::endl;
            // path.pop_back();
        }
        pre_order(root->left,expectNumbe);
        pre_order(root->right,expectNumbe);
        path.pop_back();
    }
    vector<vector<int>> FindPath_(TreeNode* root,int expectNumber) {
        pre_order(root,expectNumber);
        return out;
    }*/
// version_2.0 
    vector<int> path;
    vector<vector<int>> out;
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        if(root==nullptr) return out;
        expectNumber -= root->val;
        path.push_back(root->val);
        if(expectNumber==0 && (root->left==nullptr && root->right==nullptr)){
            out.push_back(path);
        }
        FindPath(root->left,expectNumber);
        FindPath(root->right,expectNumber);
        path.pop_back();
        return out;    // 在内层递归 他的作用只是 返回 ！！
    }

// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。
    TreeNode* mid_order(TreeNode* root){
        //非递归 中序遍历
        // 数据结构 ： 栈
        if(root==nullptr) return nullptr;
        stack<TreeNode*> opre;
    
        TreeNode* node = root;
        TreeNode* pre = root;
        TreeNode* newroot = nullptr;
        bool isfirst=false;
        while (node !=nullptr || !opre.empty())
        {
            while (node!=nullptr)
            {
                opre.push(node);
                node = node->left;
            }
            TreeNode* vis = opre.top();
            opre.pop();
            if(!isfirst){
                isfirst = true ;
                newroot = vis;
            }
            else{
                pre->right =vis;
                vis->left = pre;
            }
            pre = vis;
            node = vis->right;
        }
        return newroot ;
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==nullptr) return nullptr;
        stack<TreeNode*> opre;
    
        TreeNode* node = pRootOfTree;
        TreeNode* pre = pRootOfTree;
        TreeNode* newroot = nullptr;
        bool isfirst=false;
        while (node !=nullptr || !opre.empty())
        {
            while (node!=nullptr)
            {
                opre.push(node);
                node = node->left;
            }
            TreeNode* vis = opre.top();
            opre.pop();
            if(!isfirst){
                isfirst = true ;
                newroot = vis;
            }
            else{
                pre->right =vis;
                vis->left = pre;
            }
            pre = vis;
            node = vis->right;
        }
        return newroot ;
    }

// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
// 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。
// 即输出P%1000000007
// 1000000007  || 1000000007 是最小的十位质数。模1000000007，可以保证值永远在int的范围内不溢出
    int InversePairs(vector<int>& data) {
        int inverse_num=0;
        merge_sort(data,0,(data.size()-1),&inverse_num);

        return inverse_num;
    }
    
    void merge_sort(vector<int>& data,int l,int r,int* inverse_num){
        
        if(l>=r) return;

        vector<int> left_part;
        vector<int> right_part;
        int mid = (l+r)/2;

        merge_sort(data,l,mid,inverse_num);
        merge_sort(data,mid+1,r,inverse_num);


// version 1.0 建立左右部分存放向量 加大空间复杂度和时间复杂度了～～

        for(int i=l;i<=mid;i++) left_part.push_back(data[i]);
        for(int i=mid+1;i<=r;i++) right_part.push_back(data[i]);

        // for(int i=0;i<left_part.size();i++)
        //    cout << left_part[i] << " ";
        // std::cout << "| " ;
        // for(int i=0;i<right_part.size();i++)
        //    cout << right_part[i] << " ";
        // std::cout << "  -- " ;
        
        vector<int> res = mercg(left_part,right_part,inverse_num);
        // // for(int i=0;i<res.size();i++)
        // //    cout << res[i] << " ";
        // // std::cout  << std::endl;

        int index=0;
        for(int i=l;i<=r;i++){
            data[i] = res[index];
            index++;
        }


// version 2.0 不需要建立左右部分存放向量
        //    mercg_2(data,l,mid,r,inverse_num);
        
    }
    
    void mercg_2(vector<int>&data,int l,int mid,int r,int* inverse_num){
        
        int has=r-l+1;
        if(has==0) return;
        vector<int> out(has);
        int i=mid,k=r;
        
        while (i>=l && k>mid)
        {
            if(data[i]<=data[k]){
                out[--has] = data[k];
                k--;
            }
            else{
                (*inverse_num) += (k-mid) ;
                (*inverse_num) = (*inverse_num)%1000000007;
                out[--has] = data[i];
                i--;
            }
        }
         if(i>=l)
         {
            
             for(int t=i;t>=l;t--){
                 out[--has] = data[t];
             }
         }
         else if(k>mid)
         {
             
             for(int t=k;t>mid;t--){
                 out[--has] = data[t];
             }
         }
         int index=0;
         for(int t=l;t<=r;t++){
             data[t] = out[index];
             std::cout <<out[index] <<" ";
             index ++ ;
         }
         std::cout  << std::endl;
    }
    vector<int> mercg(vector<int>list1,vector<int>list2,int* inverse_num)
    {

        int has = list1.size()+list2.size();
        
        vector<int> out(has);
        int i=list1.size()-1,k=list2.size()-1;
        
        while(i>=0 && k>=0){
            if(list1[i]<=list2[k]){
                out[--has] = list2[k];
                k--;
            }
            else{
                (*inverse_num) += (k+1) ;
                out[--has] = list1[i];
                i--;
            }
        }
         if(i>=0)
         {
             for(int l=i;l>=0;l--){
                 out[--has] = list1[l];
             }
         }
         else if(k>=0)
         {
             
             for(int l=k;l>=0;l--){
                 out[--has] = list2[l];
             }
         }

        
        // vector<int> out;
        // size_t i=0,k=0;
        // while((i<list1.size())&&(k<list2.size()))
        //  {
        //     if(list1[i]<=list2[k])
        //         out.push_back(list1[i++]);
        //     else {
        //         (*inverse_num) ++ ;
        //         out.push_back(list2[k++]);
        //     }
        //  }
        //  if(i<list1.size())
        //  {
        //      for(size_t l=i;l<list1.size();l++)  out.push_back(list1[l]);
        //  }
        //  if(k<list2.size())
        //  {
        //      for(size_t l=k;l<list2.size();l++)  out.push_back(list2[l]);
        //  }

        return out;
    }
    

// 每年六一儿童节,牛客都会准备一些小礼物去看 1望孤儿院的小朋友,今年亦是如此。
// HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:
// 首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
// 每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
// 从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,
// 并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
// 请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
    int LastRemaining_Solution(int n, int m)
    {
        
    }

// 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
// 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
    
    vector<vector<int> > Print(TreeNode* pRoot) {
        bool ex_dir=true;
        vector<vector<int> > res;
        if(pRoot==nullptr) return res;
        // queue<TreeNode*> vis;
        stack<TreeNode*> next_layer;
        deque<TreeNode*> vis;

        next_layer.push(pRoot);

        while (!next_layer.empty() || !vis.empty())
        {
            // 
            if(ex_dir){
                vector<int>tmp;
                while(!next_layer.empty())
                {
                TreeNode* node = next_layer.top();
                // std::cout << node->val << " ";
                tmp.push_back( node->val );
                next_layer.pop();
                if(node->left!=nullptr) vis.push_back(node->left);
                if(node->right!=nullptr) vis.push_back(node->right);
                }
                // std::cout  << std::endl;
                res.push_back(tmp);
                while(!vis.empty())
                {
                TreeNode* node = vis.front();
                vis.pop_front();
                next_layer.push(node);
                }
                ex_dir = !ex_dir;
            }
            else{
                vector<int>tmp;
                while(!next_layer.empty())
                {
                TreeNode* node = next_layer.top();
                // std::cout << node->val << " ";
                tmp.push_back( node->val );
                next_layer.pop();
                if(node->right!=nullptr) vis.push_back(node->right);
                if(node->left!=nullptr) vis.push_back(node->left);
                }
                // std::cout  << std::endl;
                res.push_back(tmp);
                while(!vis.empty())
                {
                TreeNode* node = vis.front();
                vis.pop_front();
                next_layer.push(node);
                }
                ex_dir = !ex_dir;
            }

        }
        
        
        return res;
    }

// 请实现两个函数，分别用来序列化和反序列化二叉树
// 二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，
// 从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，
// 序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。
// 二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树
    char* Serialize(TreeNode *root) {    
        
    }
    TreeNode* Deserialize(char *str) {
    
    }

// 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，
// 每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入
// 该格子。 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bccced"的路径，但是矩阵中不包含"abcb"路径，
// 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
    
    }

// 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
// 但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），
// 因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
    int movingCount(int threshold, int rows, int cols)
    {
        
    }
};