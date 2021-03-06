/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // The number of node that current level has.
        int curLevelNodesNum = 0;
        // The number of node that next level has.
        int nextLevelNodesNum = 0;
        
        // Store the final answer
        vector<vector<int> > treeTraversal;
        
        // Queue for bfs
        queue<TreeNode *> nodeQueue;
        
        if( root == NULL )
            return treeTraversal;
        
        int nodeNum = 0;
        bool left2RightDirection = true;
        curLevelNodesNum = 1;
        nextLevelNodesNum = 0;
        vector<int> *curLevelValues = NULL;
        nodeQueue.push( root );
        while( curLevelNodesNum > 0 ){
            // construct a vector to store values of current level nodes.
            if( nodeNum == 0 ){
                // a little optimization for vector by initializing it with capacity.
                curLevelValues = new vector<int>( curLevelNodesNum );
            }
            
            // Get a node from queue, add it's value to curLevelValues, and push it's childrens to queue.
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            
            // Change direction according to left2RightDirection
            if( left2RightDirection )
                (*curLevelValues)[nodeNum] = node->val;
            else
                (*curLevelValues)[curLevelNodesNum-1 - nodeNum] = node->val;
            
            if( node->left != NULL ){
                nodeQueue.push( node->left );
                nextLevelNodesNum ++;
            }
            
            if( node->right != NULL ){
                nodeQueue.push( node->right );
                nextLevelNodesNum ++;
            }
            
            // Done with one node, check if all nodes in current level are all done.
            // If all done, switch to next level.
            // If next level is None, then the whole while() loop will stop.
            nodeNum++;
            if( nodeNum >= curLevelNodesNum ){
                // Add values of current level to answer
                treeTraversal.push_back( *curLevelValues );
                curLevelValues = NULL;
                
                // Switch to next level
                curLevelNodesNum = nextLevelNodesNum;
                nextLevelNodesNum = 0;
                nodeNum = 0;
                left2RightDirection = !left2RightDirection; // Change direciton
            }
            
        }
        
        return treeTraversal;
        
    }
};