
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}

/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var findLeaves = function (root) {
    const leaves = [];
    collectLeaves(root, leaves);
    return leaves;
};

/**
 * @param {TreeNode} node
 * @param {number[][]} leaves
 * @return {number}
 */
function collectLeaves(node, leaves) {
    if (node === null) {
        return -1;
    }

    let level = 1 + Math.max(collectLeaves(node.left, leaves), collectLeaves(node.right, leaves));

    if (level === leaves.length) {
        leaves.push([]);
    }
    leaves[level].push(node.val);

    return level;
}
