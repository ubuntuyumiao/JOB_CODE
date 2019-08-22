/* || 2019.8.20  Achieve：                                                 || */


# include "./lib/io.hpp"
#define T TreeNode
T                  l1(10);
T    l2_1(8);T                l2_2(12);
T  l3_1(6);T l3_2(9);   T l3_3(11);T l3_4(14);
T l4_1(4);T l4_2(7);
int main(int argc, const char** argv) {
    
    Solution yu;
    l1.left = &l2_1 ; l1.right=&l2_2;
    l2_1.left=&l3_1;l2_1.right=&l3_2;
    l2_2.left=&l3_3;l2_2.right=&l3_4;
    l3_1.left=&l4_1;l3_2.right=&l4_2;
    vector<int> in = {5,1,9,2,3,34,56,19};
    
    yu.Print(&l1);
    std::cout << "END" << std::endl;
    return 0;
}