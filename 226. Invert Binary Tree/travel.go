/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func Travel(root *TreeNode) *TreeNode {

	if root == nil {
        return nil
	}
	Travel(root.Left)
	Travel(root.Right)
	root.Left, root.Right = root.Right, root.Left
	return root
}

func invertTree(root *TreeNode) *TreeNode {
    Travel(root)
	return root
}
