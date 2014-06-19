LeetCode
========

Progress
--------
> 122/151

Other Solutions
---------------

[自定义搜索LeetCode](https://www.google.com/cse/publicurl?cx=011300011874908098858:-gv4qvyceza)  
- [水中的鱼](http://fisherlei.blogspot.com/) *C++*,有详细思路解释  
- [kitt's blog](http://chaoren.is-programmer.com/categories/9841/posts) *python*,部分有解释   
- [Code_Ganker](http://blog.csdn.net/linhuanmars?viewmode=contents) *Java*,部分有解释  
- [iphkwan](https://github.com/iphkwan/leetcode)  
- [fanfank](https://github.com/fanfank/leetcode)  

Associated Documents and Resources
----------------------------------
Peter norvig神牛Python代码写的很飘逸,果然是有LISP内功的人!  
[Udacity CS212](https://www.udacity.com/course/viewer#!/c-cs212)  
[Solving Every Sudoku Puzzle](http://norvig.com/sudoku.html)  

[Binary Search Tree In-Order Traversal Iterative Solution][inOrder]
[Binary Tree Post-Order Traversal Iterative Solution][postOrder]

[进军硅谷: 程序员面试揭秘](http://book.douban.com/subject/25844586/) 本书涉嫌抄袭leetcode,特此注明  

题目分类
--------
from http://blog.csdn.net/fightforyourdream/article/details/12705509
###Dynamic Programming
>   Edit Distance  
>   Maximum Subarray  
>   Minimum Path Sum  
>   Unique Paths  
>   Unique Paths II  
>   Longest Palindromic Substring  
>   Interleaving String  
>   Triangle  
>   Distinct Subsequences  
>   Decode Ways  
>   Palindrome Partitioning II  
>   Maximal Rectangle  
  

###Recursion  
>   N-Queens  
>   N-Queens II  
>   Balanced Binary Tree  
>   Binary Tree Inorder Traversal  
>   Binary Tree Maximum Path Sum  
>   Convert Sorted Array to Binary Search Tree  
>   Convert Sorted List to Binary Search Tree  
>   Flatten Binary Tree to Linked List  
>   Maximum Depth of Binary Tree  
>   Minimum Depth of Binary Tree  
>   Path Sum  
>   Permutations  
>   Permutations II  
>   Populating Next Right Pointers in Each Node  
>   Pow(x, n)  
>   Same Tree  
>   Subsets  
>   Sum Root to Leaf Numbers  
>   Swap Nodes in Pairs  
>   Symmetric Tree  
>   Valid Palindrome  
>   Validate Binary Search Tree  
>   Restore IP Addresses
>   Combinations  
>   Interleaving String (dp is the best)  
>   Combination Sum II  
>   Letter Combinations of a Phone Numbers  
>   Word Search  
>   Construct Binary Tree from Inorder and Postorder Traversal  
>   Construct Binary Tree from Preorder and Inorder Traversal  
>   Generate Parentheses  
>   Surrounded Regions (runtime error)  
>   Palindrome Partitioning  
>   Combination Sum  
>   Sudoku Solver  
>   Unique Binary Search Trees II  
  

###Binary Search    
>   Search Insert Position  
>   Search a 2D Matrix  
>   Search for a Range  
>   Search in Rotated Sorted Array
>   Sqrt(x)  
  

###Sequence  
>   Container With Most Water  
>   Count and Say  
>   First Missing Positive  
>   Implement strStr()  
>   Jump Game  
>   Jump Game II  
>   Length of Last Word  
>   Longest Common Prefix  
>   Longest Substring Without Repeating Characters  
>   Merge Sorted Array  
>   Palindrome Number  
>   Plus One  
>   Remove Duplicates from Sorted Array  
>   Remove Duplicates from Sorted Array II  
>   Remove Element  
>   Reverse Integer  
>   Search in Rotated Sorted Array II  
>   Sort Colors  
>   Two Sum  
>   3Sum  
>   3Sum Closest  
>   4Sum  
>   Add Binary  
>   Longest Palindromic Substring  
>   Next Permutation  
>   Longest Valid Parentheses  
>   Climbing Stairs  
>   Permutation Sequence  
>   Simplify Path  
>   String to Integer (atoi)  
>   Minimum Window Substring  
>   Longest Consecutive Sequence  
>   Trapping Rain Water  
>   Valid Number  
  

###Linked List  
>   Add Two Numbers  
>   Convert Sorted List to Binary Search Tree  
>   Merge Two Sorted Lists  
>   Partition List  
>   Remove Duplicates from Sorted List  
>   Remove Duplicates from Sorted List II  
>   Remove Nth Node From End of List  
>   Reverse Linked List II  
>   Reverse Nodes in k-Group  
>   Rotate List  
>   Swap Nodes in Pairs  
  

###Stack  
>   Binary Tree Inorder Traversal  
>   Binary Tree Level Order Traversal II  
>   Valid Parentheses  
  

###Queue  
>   Binary Tree Level Order Traversal  
>   Binary Tree Level Order Traversal II  
>   Populating Next Right Pointers in Each Node II  
>   Symmetric Tree  
>   Surrounded Regions  
>   Word Ladder  
  

###Tree  
>   Balanced Binary Tree  
>   Binary Tree Inorder Traversal  
>   Binary Tree Level Order Traversal  
>   Binary Tree Level Order Traversal II  
>   Binary Tree Maximum Path Sum  
>   Convert Sorted Array to Binary Search Tree  
>   Convert Sorted List to Binary Search Tree  
>   Flatten Binary Tree to Linked List  
>   Maximum Depth of Binary Tree  
>   Minimum Depth of Binary Tree  
>   Path Sum  
>   Same Tree  
>   Sum Root to Leaf Numbers  
>   Symmetric Tree  
>   Validate Binary Search Tree  

TODO
----

- [ ] `Longest_Common_Prefix.cpp`
    - [ ] Dynamic Programming solution
    - [ ] blog
- [x] `Substring_with_Concatenation_of_All_Words_bruteForce.py` non-trival solution (brute force: `O(len(S)*Len(L[0]))` 832ms) (not found)  
- [ ] `Divide_Two_Integers.cpp` abc() 结果是负数...
- [ ] [`Single_Number_II.cpp`](https://oj.leetcode.com/discuss/857/constant-space-solution)
- [x] `Permutation II` none trival solution (not set, constant memory, no next_permutation, just recurrsion with extra-branching rules dealing with duplicates)  
- [ ] `Permutation II` amortize solution like `Combinations.py`
- [ ] write summation about Permutation
    - $[e| e <- lst]*Permutation(lst-e)$ branch: take every element as head element 
    - insert e everywhere
    - next_permutation
- [ ] list reverse 类总结，写blog, 介绍我的reverseFrom函数   
- [ ] `First_Missing_Positive.cpp` review  
- [ ] `Best_Time_to_Buy_and_Sell_Stock.cpp`   
    - [ ] 看可以推广到K的思路[local Opt VS global Opt](http://blog.csdn.net/linhuanmars/article/details/23236995)  
        - [ ] 用这个思路重写[`Maximum_Subarray_DP.cpp`](http://blog.csdn.net/linhuanmars/article/details/21314059)  
    - [ ] 总结从1～∞的情况blog之  
- [ ] `Word_Search.py` 和 `Word_Search_copyPath.py` 以及 cpp 版本整理写一篇blog. DFS状态，复制/共享<=>面向过程/函数式<=>效率/简洁   
- [ ] `Generate_Parentheses_bruteForce.py` why insert `()` every where make all valid parentheses?  
- [ ] `Combination_Sum_II.cpp` condition not understand  
- [ ] `Combination_Sum_tailcall_opt.cpp` too slow  
- [ ] `Two_Sum.py` better solution?  
- [ ] `Unique_Binary_Search_Trees_II_DP.cpp`  
- [ ] `Sort_Colors_1pass.cpp `  
- [ ] `Sort_List.cpp` 
    - [ ] revise quickSort version; 
    - [x] write merge sort version;
    - [ ] iterative ?
- [ ] `Linked_List_Cycle_II.cpp` review,discuss  
- [ ] `Simplify_Path.py` cpp version  
- [ ] binary tree traversal
[PreOrder](http://blog.csdn.net/linhuanmars/article/details/21428647),
[InOrder](http://blog.csdn.net/linhuanmars/article/details/20187257),
[PostOrder](http://blog.csdn.net/linhuanmars/article/details/22009351),
[wiki](http://en.wikipedia.org/wiki/Threaded_binary_tree)  
    - [x] recursive traversal
    - [ ] iterative traversal with stack
    - [ ] Threaded binary tree (morris ...)
- [ ] iterative tree-like struct traverse  
    - [x] write code  
    - [ ] read [Binary Search Tree In-Order Traversal Iterative Solution][inOrder],[Binary Tree Post-Order Traversal Iterative Solution][postOrder]  
    - [ ] *dsalgo* rec to iter  
    - [ ] [BST iterator](http://oj.leetcode.com/discuss/281/how-solve-this-problem-validate-binary-search-tree-iterative)  
    - [ ] [morris traversal](http://oj.leetcode.com/discuss/2103/how-can-the-space-complextity-be-better-than-log-n-with-stack)  
- [ ] 整理word break和word break II的资料，写一篇blog  
    - *Top down* **memoization** VS *Bottom up* **Dynamic Programming**: check DP implemetation  
    * [Earley parser](http://en.wikipedia.org/wiki/Earley_parser)  
        + 分词[1](http://www.matrix67.com/blog/archives/4212),[2](http://www.matrix67.com/blog/archives/4870),[3](http://www.matrix67.com/blog/archives/5044)  
        + parsing  
    + review Udacity *CS212* and Udacity *Programming Languages*  
        + Gramma from *CS212*  
        + Earley parser implementaion from *Programming Languages*;  [another python implemetation](https://github.com/tomerfiliba/tau/blob/master/earley3.py)  
- [x] 刷过的题目整理丢github  
- [x] `Populating_Next_Right_Pointers_in_Each_Node.cpp` too slow and looks bad for myself, check other's [implemetation](http://leetcode.com/2010/03/first-on-site-technical-interview.html)  
- [ ] `Longest_Substring_Without_Repeating_Characters.cpp` 用[数组当索引](http://fisherlei.blogspot.com/2012/12/leetcode-longest-substring-without.html)重新实现一次  

[inOrder]:http://leetcode.com/2010/04/binary-search-tree-in-order-traversal.html
[postOrder]:http://leetcode.com/2010/10/binary-tree-post-order-traversal.html
