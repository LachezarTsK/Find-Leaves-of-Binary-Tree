
import java.util.ArrayList;
import java.util.List;

public class Solution {

    public List<List<Integer>> findLeaves(TreeNode root) {
        List<List<Integer>> leaves = new ArrayList<>();
        collectLeaves(root, leaves);
        return leaves;
    }

    public int collectLeaves(TreeNode node, List<List<Integer>> leaves) {
        if (node == null) {
            return -1;
        }

        int level = 1 + Math.max(collectLeaves(node.left, leaves), collectLeaves(node.right, leaves));

        if (level == leaves.size()) {
            leaves.add(new ArrayList<>());
        }
        leaves.get(level).add(node.val);

        return level;
    }

}

class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
