#include <bits/stdc++.h>


class Node {
protected:
public:
    virtual ~Node() {};

    virtual int evaluate() const = 0;
};

class OperandNode : public Node {
protected:
    int val;
public:
    OperandNode(string val) {
        this->val = stoi(val);
    }

    int evaluate() const {
        return val;
    }
};


class OperatorNode : public Node {
protected:
    Node *right;
    Node *left;
public:
    OperatorNode(Node *left, Node *right) {
        this->left = left;
        this->right = right;
    }
};

class AddOperatorNode : public OperatorNode {
public:
    AddOperatorNode(Node *left, Node *right): OperatorNode(left, right) {}

    int evaluate() const {
        return left->evaluate() + right->evaluate();
    }
};

class SubtractOperatorNode : public OperatorNode {
public:
    SubtractOperatorNode(Node *left, Node *right): OperatorNode(left, right) {}

    int evaluate() const {
        return left->evaluate() - right->evaluate();
    }
};


class MultiplyOperatorNode : public OperatorNode {
public:
    MultiplyOperatorNode(Node *left, Node *right): OperatorNode(left, right) {}

    int evaluate() const {
        return left->evaluate() * right->evaluate();
    }
};

class DivideOperatorNode : public OperatorNode {
public:
    DivideOperatorNode(Node *left, Node *right): OperatorNode(left, right) {}

    int evaluate() const {
        return left->evaluate() / right->evaluate();
    }
};


class TreeBuilder {
private:
    bool isNumeric(string &str) {
        return str[0] >= '0' && str[0] <= '9';
    }

    OperatorNode* getOperatorNode(char op, Node *left, Node *right) {
        if (op == '+') {
            return new AddOperatorNode(left, right);
        } else if (op == '-') {
            return new SubtractOperatorNode(left, right);
        } else if (op == '*') {
            return new MultiplyOperatorNode(left, right);
        }
        return new DivideOperatorNode(left, right);
    }


public:
    Node *buildTree(vector<string> &postfix) {
        stack<Node *> nodes;

        for (auto &str: postfix) {
            if (isNumeric(str)) {
                nodes.push(new OperandNode(str));
            } else {
                Node *right = nodes.top();
                nodes.pop();
                Node *left = nodes.top();
                nodes.pop();

                nodes.push(getOperatorNode(str[0], left, right));
            }
        }

        return nodes.top();
    }
};
